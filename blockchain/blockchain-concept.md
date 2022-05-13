


# Decentralized Currency 
    
    [History]:
    >> whitepaper posted online 2008 "Bitcoin: A Peer-to-Peer Electronic Cash System" -- Satoshi Nakamoto
    >> live on January 2009


    [Ctyptocurrencies]:
    >> use of cryptographic primitives and distributed consensus protocols to secure virtual money creation and flow between various parties


    [Hash Function]:
    <1> mathematical functions that take input of any size and produces a fixed size output
        + one-way function where computing the hash of some string is easy but reversing the hash to reover the input is hard (lots of computation is needed)
        - computing the image of some input is efficient (done in polynomial time of O(n)), 
          but computing the preimage is inefficient (non-polynomial or computationally hard)

    <2> security properties
        + First-preimage resistance: given y where y=h(x), it's computationally hard to find x
        + second-preimage resistance: given x it is computationall hard to find x' such that h(x) = h(x')
        + collision resistance: it is computationally hard to find any x, x' such that h(x) = h(x')

        => Application
            • Commitment schemes 
            • Merkle trees
   
    <3> 
        >> (Theory) Hash Function are keyed functions 
            + meaning that hash functions are parameteried by a key(public/private)
            + changing the key changes the mapping (for function output)

        >> (Practical)
            + all used hash functions are fixed-length, unkeyed
            + for the same input, they always produce the same output

            [ex]: SHA1, SHA2, SHA3, etc
            + most cryptocurrencies use SHA256 (SHA2 with output size of 256 bit)

            [!] Bitcoin also used RIPEMD-160 with output size of 160 bits 
            [!] Ethereum replace SHA256 with more secure one SHA3 or Keccak with the same output size



    [Merkle Tree] (p12-1)
    >> An efficient solution for data correctness verification
        + used in distributed systems and file storage
        + it's a binary tree, Each internal node in the tree is the hash of its two children
        + the root digest represent the hash of all leaf nodes
       <!> verifying the correctness of an input is done by providing a membership path of size log n digest



    [Digital Signatures]
    >> used to provide message integrity and non-repudiation
        + Integrity: prevent message tampering(minacious modifying data)
        + Non-repudiation: bind the sender to the message
    >> work in the public-key setting
        + each party creates a key pair, public and private key
        + use the private key to sign the message, while anyone can verify the signature using the public key
        + The public key usually serves as an ID
    >> Consists of three algorithms
        + Gen: generate a key pair
        + Sign: sign a message using the private key (usually randomized)
        + Verify: verify the correctness of the signature over the signed message (just for verifying, not decoding i think)
       <!> a secure digital signature scheme means that an attacker cannot generate a valid signature over a message without knowing the secret key even if it obtains signatures on other messages
            - cannot to forge a signature
       <!> Usually the hash-sign paradigm is used, where the message is hashed first and then the digest is signed
     




# Bitcoin
    >> A distributed currency exchange medium open to anyone to join (powered by P2P network)
    >> utilized basic cryptographic primitives to control the money flow in the system
    [components]
        + Players: miners and clients
        + Transactions: messages exchanged
        + Blockchain: an append only log
        + Mining: extending the blockchain
        + Consensus: agreeing on the current state of the Blockchain

    
    >> No real identities are required, just key pair
        - Usually the hash of the public key is the participant's address

    <1> Owning the private key of the "destination address" of currency transfer means you own the currency value of that address
    <2> Losing the private key of a specific address means losing the coins associated to this address forever!
    <3> Digital signatures are used to prove your "ownership" of the private key associated to the coins you want to spend
    <!> everything is logged on a public ledger called a blockchain (ledger: 分类账)
        - using linked list and hash pointers


    [Tyes of Nodes]
    <1> lightweight nodes or clients:
        - vast majority of Bitcoin nodes are lightweight ones
        - they do not store the whole blockchain, only sepcific parts to verify the transactions they care about
        - they trust the miners in generating trusted and true blocks
    
    <2> Fully validating nodes or miners:
        - Must stay permanently connected to the system
        - Have a good network connectivity to be able to hear all transactions 
        - Store a full copy of the blockchain



    [Decentralization in Bitcoin]
    < Peer-to-Peer > = P2P network: 
        + anybody can join and leave anytime

    < mining >
        + Updates on the used software: done by community developer
        + Maintaining the public ledger: maintained by all miners within the network
        + Transactions: announced publicly to everyone


    [Bitcoin Addresses]
    >> define a user
        + 160-bit hash of the public portion of an ECDSA key-pair
        + ECDSA is used for digital signature in Bitcoin with key size of 512 bit
       <+> The Address is the public key hashed twice: using SHA256 followed by RIPEMD-160
       <!> Additional byte is needed since all Bitcoin addresses should start with either 1 or 3
            - 1 for individual addresses as output destination
            - 3 for scripts addresses as output destination (script hash)

        + QR code (quick response code) for easy way to exchange addresses and perform transaction through the wallets


    [Bitcoin TRansactions]
    >> transactions represent the digital token
        + in bitcoin, a coin can be spent by providing a signature using the private key associated with the destination address of the transaction
        + a new transaction is issued by any node as follows:
        [fill the following]
            => input section
            => output section
        [sign the whole transaction using the private keys associated with the inputs]
        + the sender then broadcasts the transaction over the network

    >> no notion of accounts, track chains of transactions
        + wallets do that transparently for users
        + cannot spend a portion of an input, 8 ether means 8 ether, whenever you use that coin
        + solution is to return the extra value in a new coin
        + transactions are irreversible


    =====================================================
    >> Bitcoin Block Overview (p28-1)
        + check the figure of that on the PPT


    >> The Public Ledger or Blockchain
        + append only log containa full record of all transactions
        + miners extend the blockchain by mining new blocks
            - Solve a proof-of-work puzzle
            - Collect monetary incetives
        + header includes meta data, while the body includes the list of transactions recorded in a block


    >> genesis block (the very first block in the chain)



    >> mining
        + miner extend the blockchain with new blocks
            => done through proof-of-work
            => needed to prevent Sybil attacks
            => miner solve a hash puzzle
                - SHA256(SHA256(new block header)) < Difficulty Target

        + verfication is very easy, other miners check the validity of the included transactions and then verify the solution of the has puzzle

        + difficulty is adjusted periodically, roughly, every two weeks
            - keeps the block generation rate constant, 1 block every 10 mimutes

            - accommodates the increasing computation power of miners

            - strong miners could be able to rewrite the blockchain and change its view

            - Miners get
                • mining rewards
                • transaction fees


        + Miners Hardware (p37-1)

        + detail on spending bitcoin (p9-2)






# Consensus and Blockchain Forking
       
       [ Consensus ]
       <1> miners hold consistent copies of the blockchain
       <2> A miner votes for a block implicityly
            + accept it by including it in the chain and start working on top of it
            + reject it by ignoring the new block and continue working on the older blockchain or another announced block
            - propagation delays: not all nodes hear all announced transactions
            - nodes may crash at any point of time
              causing the blockchain have multiple branches, i.e. forks



        [ blockchain forking ]
        >> forking the blockchain means the miners work on different branches
            + causing by network propagation delays, adversarial actions
            + resolved by adopting the longest branch

    
        [ Forking Type ]
            < Soft Fork >
            : temporary fork in the blockchain due to updating the consensus protocol to include additional rules on validating the blocks
                - blocks considered valid by an old version of the protocol are all valid by the new version, but the block validated by new versions are all valid based on old version
                - If the majority of the nodes switch evertually as their branch is no longer the longest one

            < Hard Fork >
            : permanent fork in the blockchain due to updating the consensus protocol
                + old version considers all blocks that are valid according to the new version invalid
                    • thus, two branches will not have any blocks in common.
                    • results in two different blockchains from this hard fork
                + so a miner can be on one branch only as a block is valid based on single version of the protocol not both
                    • requiring all developers to upgrade to the latest version of the protocol software




        [ Bitcoin Scripting Language ]
        >> Validating Transactions
            + validating a transaction in Bitcoin is not static
            + no fixed logic that applies to all transactions

        >> to validating that inputs can be spent to the outputs is done in a programmable way  
            + each transaction has an unlocking script for each input that is processed alongside a locking script for the output of the referenced input transaction.
                • recall a previous output is an input for new transaction
                • the concatednated unlocking and locking script has to evaluate to TRUE in order to consider the transaction as valid

        >> Non Turing-complete, does not support loops
            + limited complexity and it has a predictable execution times
            + stack based

        >> kept simple for security reasons
            + more complex scripting languages, or better saying Turing-complete, provider great flexibility for the programmer to build complicated functionalities
            + but it's hard to get it right!
            + attackers are motivated to dig into these programs and find security bugs





        [ Transaction Validation through Script: scriptPubKey & scriptSig ]
        >> Validation requires two types of scripts: 
            + scriptPubKey: locking script
                • A locking script placed on the output of a transaction that requires certain conditions to be met in order for a recipient to spend their bitcoins
            + scriptSig:    unlocking script
                • The unlocking script that satisfies the conditions placed on the output by the scriptPubKey and is what allows it to be spent

        >> visit detail on (p21-2)


        [ Bitcoin Standard Transactions ]
        >> pay to public key hash
            • vast majority of Bitcoin transactions are of this type
            • X pays Y a Z bitcoin

        >> public key
            • same as above but instead of using addresses (hashed public keys), use the public key itself
            • hashed public keys are more efficient as they are shorter

        >> Pay to script hash (P2SH).
        >> Multi-signature
        >> Data output

        [ Multi-signature ]
            >> one of the very useful and widely implemented scripts in P2SH
            >> the script requires signatures of a set of users to ublock the currency instead of one user signature
            >> can be built also in a threshold-based way, like 2 out of 3 signatures are enough to spend the currency
            >> mostly used to create escrows while trading using Bitcoin

        [ Pay to Script Hash(P2SH) ] - (p24-2)
            >> provides ways to implement advanced operations in Bitcoin beyond the standard currency transfer transactions
            >> ...
            >> ...
            >> ...
            >> The scripts that you can code are limited by the primitives supported in Bitcoin Scripting Language (p24-2)





        ===================================
        [ Security ]
        >> def (no specific security notion for a cryptocurrency system)
            + informal definition: refer to stability of the system

            + consensus protocol
                • defined rigorous security notions in terms of security properties that if satisfied, the consensus protocol is considered secure
                • proved formally the security of Nakamoto's consensus protocol

        [ security properties ]
        >> informally, the blockchain is considered secure if it achieves the following properties
            <1> consistency: 
                - at any point in time, honest miners hold copies of the blockchain that have a common prefix and may differ only in the last y blocks,
                  where y is a block confirmation parameter. A block then is confirmed once it is buried under y blocks on the blockchain
            <2> future-self consistency:
                - at any two points in time, t1 and t2, the blockchain maintained by an honest party may differ only in the last y blocks. 
                  Consistency and future-self consistency properties achieve blockchain persistence or immutability
            <3> ..
            <4> ..
            <5> ..
            (p29-2)



        [ security issues ]

            <i> double spending 
                + spend the same currency more than once (only cost new signature)
                    • handled by logging all transactions on the blockchain (miner can check whether a transaction has been already spent or not)
                + Network propagation delay may allow race condition between transaction
                    • also can manipulating the transaction fee
                + TO address this issue, usually it is advised not to act until the transaction is confirmed

                + When
                    • in bitcoin, when buried under 6 blocks, which is around 60 min
                    • usually wait one hour to make sure that payments are confirmed before handing the customer the purchased items
                    - what if you are just buying a coffee???
                    • miner usually give higher priority to transactions with larger fees to be included in the next block
                      so it may take your transaction longer than 1 hour to be confirmed

            <ii> Sybil Attack
                + An attack usually takes place when an attacker creates a large number of fake identities to control the majority of the network (水军)
                + usually the has the target of destroying reputation-based systems (Amazon, yelp review)
                + bitcoin thwarts(阻挠) this threat through the proof-of-work(PoW)
                    - so creating new identities is expensive as computation power is needed to mine a new block, and hence, vote in the system on the previous block


            <iii> 51% attack 
                + usually see as very difficult to achieve by one person

            <iv> Tendency Toward Centralization
                + other cryptocurrencies as well
                + reason:
                    - even through mining is open to anyone, it is not the case now. you need to purchase expensive mining hardware, which not everyone could do
                    - mining algorithm is reachable, you can ask someone else do the work for you
                
                >> this encourage the concept of mining pools in the mining networks (bad)
                    • where a set of miners get together under the control of a single party called the pool manager

                [ mining pool ]
                    + mostly centralized, each pool is under the control of one manager
                    + what manager does
                        <1-4>. (p36-2)

            <v> Eclipse Attack
                








# Smart contact
    >> a program written in Ethereum scripting language (solidity), deployed to the network by the miners 

    >> composition
    [1]. state
         - represented by the values of the variables defined inside the smart contract

    [2]. functions
         - type one. Read-only, functions that do not change the contract state (called for free)

         - type two. transactional functions that change the state of the contract and result in transactions logged on the blockchain
           miners do not perform the function without getting paid with gas fee

    [3]. smart contract code and its current state 
         - are public and can be retrieved by any party in the system, but can it cannot be changed(chained with hashing code) once deployed
         - can be destrcuted if contains that destruct function

    [4]. need gas fee for deploying


# Compare to Traditional coding

    [!] traditional coding
        [steps]: write code --> test it locally on your machine --> write test the covers the whole code --> then deploy

    [!] smart contract
        [steps]: local testing with (fake) blockchain --> test it on the testnet blockchain --> then deploy


# State Machine 

    [Ethereum Yellow Book]: cryptographically secure transactional singleton machine with shared-state
      - secured by the secure crytographic primitives 
      - operates as a single machine responsible of tracking all transactions 
      - the system state blockchain content, is shared across several machines


    -[STATE MACHINE]-
      
      [1]: a state machine is a machine that reads an input and changes to a new state based on the output
      [2]: starts with genesis state - move to a new state based on processed transactions
      [3]: account can contain balances, reputation, contract code associated with account, or any digital information about the system

      - transactions are grouped into blocks, and these blocks are also chained using their hash like Bitcoin
      [!]: a block contain an identifier for the new system state that was produced after processing the transactions included in the block
      [*]: this is ID is simply the root of the Merkle tree over all mappings in the state


# Ethereum Tokens 

    [motivation]

      [+]: a flexible way of creating new coins or digital assets on top of Ethereum ecosystem 

      [+]: very similar to loyalty cards concept, you collect points and then you can use them to buy additional items instead of using your money

      [advantage]
      - utilize the underlying infrastructure of Ethereum such as the miners, etc
      - no need to bootstrap a new crytocurrency system, just issue token
      - Allow the use of a token across multiple projects or platforms, which enhance liquidity


# Token ≠ Ether

    [+]. Any crytocurrency is a token
    [+]. however, a token created on top of another crytocurrency has several differences
         [.]. Ether is controlled by the ethereum protocol, a token is controlled by its smart level
         [!]. Ether balance is handled at the protocol level, a token balance is handled at the smart contract level
         [!]. Sending ether is an instrictic action in Ethereum, but sending a token is not



    [+]. Standards
         {=}: goal is to outline minimum specifications and encourage interoperability
          + : ERC20 (popular and widely used)
          + : ICOs



# Smart Contract Security Issues

    [!]. cannot patch a buggy smart contract code

    [!]. extensive testing is needed for smart contract

    [!]. attackers are financially motivated 



# Transaction Ordering Dependence (TOD)

    

























