

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

    

























