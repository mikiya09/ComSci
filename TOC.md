

# Regular Language



# DFA/NFA

    [ properties ]:

        >> model for device with little memory



# Pumping Lemma



# CFL




# PDA


    [ properties ]:

        >> Models for device with unlimited memory that is accessiable only in Last-in-First-Out order




# Turing Machine

    [ what's for ]:

        >> we want the model that is equivalent to what a real computer can do,
           so that we can analyze problem theoretically (on paper)

            + if a problem that is not solvable with that model, so does the real computer

            + (assume we have enough calculation capcity and memory)

            + only model thus far that can model general purpose of a computer


    [ elements ]:


                + tape head = could move either left and right

                     -----------
                     | control |
                     -----------
                          |
                          |
                          V

                        -------------------------
                + tape  | a | b | a | b | - | - | ...
                        -------------------------

                    - Tape initially contains the input string and blanks everywhere else
                    - contains an infinite tape


                + # (blank cell)

                    < rightmost >: if we move to the end of right (end of the input), 
                                   a blank sysmbol will be added to rightmost
                    
                    < leftmost >: either stop or moving


    [ properties ]:

        >> extend/generalize what a PDA can do

        >> as a TN computes, changes occur in:

            <1>. the state
            <2>. the content of the current tape location
            <3>. the current head location


        >> decider

            + A Turing Machine halts on all inputs is a decider. A decider that recognizes a language decides it
                                                                   -------

            + A language is Turing-decidable or simply decidable if some Turing Machine decides it(halt)


    [ formal definition ]:

    
                    -------------------------------------------------------------
                    |                                                           |
                    |       < 7 tuple >                                         |
                    |                                                           |
                    |       • Q = finite set of state                           |
                    |       • ∑ = finite set of symbols (input alphabet)        |
                    |       • gamma = tape alphabet (all symbol on the tape)    |
                    |       • delta = transition function                       |
                    |       • q0 = start state                                  |
                    |       • q(accpet) = acccpeting state                      |
                    |       • q(reject) = rejecting state                       |
                    |                                                           |
                    -------------------------------------------------------------

                    (question) : what is accept and reject state looks like?


    [ compparison ]:

        >> DFA/NFA or PDA take input consecutively and and only move right

            !. will eventually go to some end of the state, either accept or reject
            !. because we will have last input goes into the machine, 
               and base on the last one's position to decide whether accept or reject
        

        >> Turing Machine have all the inputs fill in the tape first
            
            + tape head could move either right or left
            + could mark the inputs on the tape
            + since the inputs are on the tape already, the way we analyze it is by moving the head, 
              and so we need some specific q(accept) and q(reject) state

    [ Question ]:

            A finite automata will run until its input is completely processed and then it will stop. 
            This is not true for a Turing Machine

            : because The input is placed on the tape of the Turing machine. 
              The Turing machine runs until either accept or reject state is entered
              it's not like a finite finite automata which processes the input and then accpets 
              if in an accept state or else it rejects.
              Thus TM does not have a notion of processing the input



    [ example ]:

        + B = { w#w | w belongs to {0,1}*}

            >> 011000#011000


        + A = {0^(2^n) |n >= 0} 

            <1>. Sweep left to right across the tape, crossing off every other 0
            <2>. If in step 1:
                 - the tape contains exactly one 0, then accept
                 - the tape contains an odd number of 0's, reject immediately
                 - Only alternative is even 0's. In this case return head to start and loop back to step 1

            0 0 0 0 --      Number is 4, which is 2^2
            x 0 0 0 --
            x 0 x 0 --      Now we have 2, or 2^1
            x 0 x 0 --
            x x x 0 --
            x x x 0 --      Now we have 1, or 2^0
            x x x 0 --      Seek back to start
            •           
            x x x 0 --      Scan right; one 0, so accept
                  •

            (question) : by dividing the input string into two parts, 
                         it's that similar to say non-deterministic find the middle of the string?


        + PPT chapter-3-p16 to p16

            a a b b b c c c c c c
            -   • • • • • • 

            [ restore all b's ]
            
            a a b b b c c c c c c 
            - + * * * • • • * * *

            -------------------------------------------------------------------------------------------------
            |                                                                                               |
            |   Transducers                                                                                 |
            |                                                                                               |
            |   • Turing Machine can also generate/transduce language                                       |
            |                                                                                               |
            |       - given a^ib^i and ixj=k                                                                |
            |       - similar manner. For every a,                                                          |
            |         you scan through the b's and for each you go to the end of the string and add c       |
            |       - zig-zagging(之字形) a times, you can generate the appropriate number of c's           |
            |                                                                                               |
            -------------------------------------------------------------------------------------------------


        + PPT chapter-3-p20

            >> given a list of strings over {0, 1} each separated by a #, accpet if all strings are different.

               E = {#x1#x2# ... # xn | each xi belongs to {0, 1}* and xi ≠ xj for each i ≠ j}

            <1>. pick a mark on top of the left-most symbol. If it is a blank, accept. 
                                                             If it was a # comtinue; else reject

            <2>. Scan right to next # and place a mark on it. If no # is encountered, we only had x1 so accept

            <3>. mark两个#，比较两个#右边的string

            <4>. 检测步骤：先将两个已经marked的最右边那个往下一个# symbol移动（右移）；
                 假设没有在遇到blank之前，没有遇到任何#
                 
                 操作步骤：再将左边那个marked往右边移动，移动到下一个#（这里就是之前右边的marked #），
                 同时将右边的marked也往后移动一格
                 
                 判断：如果右边没有#了，那全部的string已经比较完毕，accept

            <5>. go to step 3


# Variants of Turing Machine


    [ concept ]:

        >> to show that two models are equivalent, we only need to show that one can simulate another

            + simulate (variant model does the same thing as the original)

            + refer to --> deterministic = non-determinstic
    


    [ Variant I ]:

        >> stay put(留在原地)

        >> add two transitions
            
            <1>. move right

            <2>. then move left


    [ Variant II ]:

        + multi-tape

        + Multitape is convenient (think of extra tapes as scratch paper) but does not add power

        >> PROOF

        ex. 
                     ------------------                         |
                                      |                         |
                                      V                         |
                            -------------------------           |
                            | a | a | b | a | b | - | ...       |
                            -------------------------           |
                                                                |
                -----------------------                         |
                                      |                         |
                                      V                         |
                            -------------------------           | --> k=3 tapes, each has its own TAPE HEAD
                            | 1 | 0 | 1 | 1 | - | - | ...       |
                            -------------------------           |
                                                                |
                -------------------                             |
                                  |                             |
                                  V                             |
                            -------------------------           |
                            | x | y | x | x | - | - | ...       |
                            -------------------------           |
                                                                |


                        ---------                       ---------
                        |       |   b1y -> a0x, LLR     |       |
                        |   Q   | --------------------> |   R   |
                        |       |                       |       |
                        ---------                       ---------

            <1>. the first tape HEAD pointing to b, and base on the transition it will be replaced by a, and move LEFT
            <2>. the second tape HEAD pointing to 1, and replaced by 0, and move LEFT
            <3>. the third tape HEAD pointing to y, replaced by x, and move RIGHT



            total (k + 1) #
            ------------------------------------------------------------------------------
            | # | a | a | b | a | b | # | 1 | 0 | 1 | 1 | # | x | y | x | x | # | - | ...
            ------------------------------------------------------------------------------
                          •                           •           • <- virtual head (marked mechanism)
                 ===================     ===============     ===============
                        tape 1                tape 2              tape 3



            <1>. Add "dots" to show whee Head "K" is
            <2>. To simulate a transition from state Q, 
                 we must scan out Tape to see which symbols are under the K Tape Heads
            <3>. Once we determin this and are ready to MAKE the transition, 
                 we must scan across the tape again to update the cells and move the dots(virtual head)
            <4>. Whenever one head moves off the right end, we must shift our tape so we can insert a - (blank symbol)
            


    [ Variant III ]:

        >> non-deterministic TM
        
            + use a breadth-first search

                • depth-first search is a bad idea, it will fully explore one branch before going to the next. 
                  If that one loops forever, will never even try most branches

                • breadth-first guarantees that all branches will be explored to any finite depth 
                  and hence will accept if any branch accepts

                • The DTM will accept if the NTM does

            + like NFA, always guess the right input (assume)

            + could be done using 3 tapes

                1. one tape for input
                2. one tape for handling current branch
                3. one tape for tracking position in computation tree
            


    [ Enumerators ]:        (question): it's this something we could expected on the exam?

        >> enumerator E is a TM with a printer attached 
            
            <1>. the TM can send strings to be output to the printer
            <2>. the language enumerated by E is the collection of strings printed out
            <3>. E may not halt and print put infinite numbers of strings
            
            • Theorem: A language is Turing-recognizable if and only if some enumerator enumerates it

        >> PROOF

            + forward direction
                
                (if an enumerator E enumerates a language A then a TM M recognizes it)
                
                & M = "On input w"
                    • Run E. Every time E outputs a string compare it to w.
                    • If w ever appears in the output of E, accept.
                & Clearly M accepts any string enumerated by E



    [ other model ]:        (question)



# Defintion of Algorithm


    [ Definition ]:

        >> algorithm is a collection of simple instructions for carrying out some task (a procedure or recipe)


    [ Hilbert's Problem ]:       (question) : should I review this ?


    
    [ Church-Turing Thesis ]:

        >> provide in 1936

        >> Connection between the information notion of an algorithm and the precise one is the Church-Turing thesis

            + the intuitive notion of algorithm equals Turing machine

        >> fun fact

            + In 1970 it was shown that no algorithm exists for testing whether a polynomial has integral roots


    [ Turing Machine Terminology ]:
        
        >> The input to a TM is always a string

            + other objects (graphs, lists, etc) must be encoded as a string
        
            + the encoding of object O as a string is <O>


        ex.
        ----------------------------------------------------------------------------------------------------------
        < Let A be the language of all strings representing graphs that are connected >
        A = { <G> | G is a connceted undirected graph }

        M = "On input <G> the encoding of a graph G":
            
            1. Select and mark the first node in G
            2. Repeat the following until no new nodes are marked 
                
                - for each node in G, mark it if it is attached by an edge to a node that is already marked

            3. Scan all nodes of G to determine whether they are all marked. If they are, then accept; else reject






# Decidable 


        [ unsolvability ]:

            >> why study this?
    
                + Useful! because then can realize that searching for an algorithmic solution is a waste of time (perhaps the problem can be simplified)

                + Gain a perspective on computability and its limits



        [ Decidable ]:

            + if it is in the language, Turing machine will accept it, and if not in the language, it must reject! 

                • will eventually halt, (but it's not sufficient to just say it halt on all inputs, you have to include above line) 
        
             

        [ Turing recognizable ]:

            < ? > we don't know whether L is Turing Recognizable in the first place, and we put L into TM

                + If L is in the language: a TM accpets all strings in L
                    
                    • Language L is Turing Recognizable
                
                + If L is not in the language: a TM might not reject it and just loop forever
                    
                    • not every Turing-recogniable language is decidable




# Decidable Language


    [ A(DFA) ]:

        >> A: acceptance / whether a DFA accept a langauge



    [ A(NFA) ]:

        

    [ E(DFA) ]:

        >> E: emptiness / whether there has string is in the DFA



    [ EQ(DFA) ]:

        >> EQ: equivalence for DFAs



    [ Regular Language under Union ]:



    [ A(CFG) ]:


        >> A: acceptance 

            + but since CFG generate string, the thought is about why it could generate a string w is in the langauge


    [ E(CFG) ]:

        >> E: emptiness 

            + same idea with A(CFG), the goal is to check if there are strings in the language

            + in DFA we can if input reach accept state 

            + here we check if start variable generate variables, and those variables will eventually all reach terminals


        >> working backward


            ?


    [ EQ(CFG) ]:

        >> not decidable



    [ Every Context-Free Language ]:

        >> decidable

        >> proof ?



# Hierarchy of Classes of Language




# Halting Porblem

    >> prove not every turing-recognizable language is decidable


    [ concept ]:



    [ A(TM) ]:


    [ Diagonalization Method ]:


    [ Pairing Set Items ]:


    [ diagonalization proof of A(TM) ]: ? p35-41


# Reducibility

    [ Prove Halting Problem ]: ? p48-50



    


# Time Complexity


    [ relationship between model and complexity ]: 

        >> proof?

            <1>. single tape turing machine and multi-tape turing machine

            <2>. non-deterministic turing machine runtime proof


# CLass P

    [ ploynomial difference ]:

        >> single tape TM and multi tape TM is at most a square, or ploynominal difference

        >> moving to a non-deterministic TM yields an exponential difference (not a real-world model)


    [ Ploynomial Time ]:


        >> in terms of time complexity

            + polynomial differences are consider small

            + exponential ones are large


    [ Background ]:

        >> p41
        >> Exponential time algorithm arise when we solve problem by exhaustively searching a space of possible solutions using brute force search

        >> Polynomial time require something other than brute force

        >> All reasonable computational models are polynomial-time equivalent 


    [ Definition ]:

        >> p42


    [ proof ]:

        >> steps to prove an algorithm is in class P


    [ encoding ]:

        >> encode the problem in polynomial time to the internal representation


        <1>. Path Problem (standard encoding: graph)

            + brute force won't work

            + details


        <2>. RELPRIME (relative prime) 

            + why simple method won't work

            + more efficient algorithm


# CLass NP


    [ background ]:


    [ Hamiltonian Path ]:

        >> why is n! for brute force

    [ Polynomial Verifiability ]:

        >> even though we don't know of a fast way to determine if a Hamiltonian path exists 

        >> but if we discover such a path (by brute force), we can verify it easily (in poly time)

        >> easilier

        <1>. composite number problem


    [ Verifier ]:

            
        there is a solution presented to you, can you verify this is indeed a true solution?


    [ definition ]:


        
    [ example of NP ]:

        Clique


        


# NP-Complete