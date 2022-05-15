

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

            >> why study this? (because limitation of Algorithmic Solvability)
    
                + Useful! because then can realize that 
                  searching for an algorithmic solution is a waste of time (perhaps the problem can be simplified)

                + Gain a perspective on computability and its limits




        [ Decidable ]:

            >> if a string is in the language, 
               Turing machine will accept it, and if not in the language, it must reject! 

            >> will eventually halt,
               but it's not sufficient to just say it halt on all inputs, you have to include above explanation
        
             


        [ Turing recognizable ]:

            >> we don't know whether L(language) is Turing Recognizable in the first place, and we put L into TM

                + If L is in the language: a TM accpets all strings in L
                    
                    • Language L is Turing Recognizable
                
                + If L is not in the language: a TM might not reject it and just loop forever
                    
                    • not every Turing-recogniable language is decidable




# Decidable Language


    [ GOAL ]:

        >> we give algorithm for testing whether a finite automata accepts a string,
           or whether the language of a finite automata is empty, whether two FA are equivalent

        
    [ method ]:

        >> we represent the problems by languages (not FAs)

            + Let A(DFA) = { (B, w) | B is a DFA that accepts string w }

            + The problem of testing whether a DFA B accepts a specific input w is the same as testing wehther
              (B, w) is a member of the language A(DFA)

            + showing that the language is edcidable is the same thing as showing that the computational 
              problem is decidable


    [ Encoding ]:


        >> Logic

            + Church Turing Thesis says TMs are basically equivalent to algorithm 
                                              
                                              |
                                              |
                                              V

            + If we can build a TM to do something, we can say our computer could do the same

                                              |
                                              |
                                              V

            + if we can encode Machines(DFA, TM, etc) into string, we can then test what they can do through TM

                                              |
                                              |
                                              V

            + and then we can put the string onto the tape from some TM, and let it run for result


        >> Terms

            • <> angle brackets means encoding
            • D means for DFA
            • <D, w> they are both string right now



        >> Example for a DFA D1
                                              -----
                      -----                   |   | 1
                      |   | 0                 |   V
                      |   V              ---------------
                    ----------           | ----------- |            ----------
                    |        |     1     | |         | |     0      |        |
            ------> |   q1   | --------> | |    q2   | | ---------> |   q3   |
                    |        |           | |         | |            |        |
                    ----------           | ----------- |            ----------
                                         ---------------                |
                                                ^                       |
                                                |           0,1         |
                                                -------------------------


                                                delta
            D1 = (Q, sigma, delta, q0, F)       ---------------------------------
                                                |       |     0     |     1     |
                  Q = { q1, q2, q3 }            |-------|-----------|-----------|
              sigma = { 0, 1 }                  |   q1  |     q1    |     q2    |
              delta = ex. q1 on 0 goto q1       |       |           |           |
                 q1 = the start state           |   q2  |     q3    |     q2    |
                  F = { q2 }                    |       |           |           |
                                                |   q3  |     q2    |     q2    |
                                                ---------------------------------



            + string w

            + w = #Q#sigma#delta#q0#F#

            + # q1,q2,q3 # 0,1 # $q1 0 q1$q2 1 q2$q3 0 q2$...$ # q1 # q2 #
                --------   ---   -----------------------------   --   --
                  all     sigma        delta(transition)        start  final
                 states                                         state  state


            + finally for a encoding "if DFA take some string w"we can write

                 -----------------------------------------------------
                 |                                                   |
                 |   <D, w> = # Q # sigma # delta # q0 # F # w #     |
                 |                                                   |
                 -----------------------------------------------------
                



    ----------------------------------------------- Example -------------------------------------------------------


    [ A(DFA) ]: deciable 

        >> A: acceptance / whether a DFA accept a langauge 

        >> Theorem: A(DFA) is a decidable language
        >> Proof Idea: Present a TM M that decides A(DFA)

            + M = On input (B, w), where B is a DFA and w is a string:

                1. Simulate B on input w
                2. If the simulation ends in an accept state, then accpet; else reject


    
    [ A(NFA) ]: deciable
        
        >> convert NFA to DFA

            + N = On input (B, w) where B is an NFA and w is a string
                
                1. Convert NFA B to an equivalent DFA C

                2. Run TM M on input(C, w) using the theorem above

                3. If M accepts, then accept; else reject

            + Running TM M in step 2 means incorporating Min to the design of N as a subroutine (make NFA a string)
                                                                                                (generate a DFA)

            + use table to convert NFA to DFA (midterm last question)


        

    [ E(DFA) ]:  deciable

        >> E: emptiness / whether there has string is in the DFA

        >> E(DFA) = {<A> | A is a DFA and L(A) = ø} is a decidable langauge

        >> A DFA accepts some string iff it is possible to reach the accept state from the start state


                                                reachable
                                start state ------------------> accepted state 

            + T = On input(A) where A is a DFA:

                1. Mark the start state of A

                2. Repeat until no new starts got marked:

                    3. Mark any state that has a transition coming into it from any state already marked

                4. if no accept state is marked, accept(indicate empty); otherwise reject

                (question) : for step 2, what if we have a path that does not reach the accept state,
                             how do we go back? Once we go back, do we need to unmarked start state first?



        

    [ EQ(DFA) ]: deciable

        >> EQ: equivalence for DFAs

        >> EQ(DFA) = { (A, B) | A and B are DFAs and L(A)=L(B) }

        >> construct a DFA C from A and B, where C accepts only those strings accepted by either A or B but not both
                                                                                            ( symmetric difference )
            + if A and B accept the same language,
            + then C will accept nothing and we can use the proof for E(DFA)

            + F = On input(A, B) where A and B are DFAs:

                1. Construct DFA C that is the symmetric difference of A and B


                                L(C) = L(A) & L(B)' U (L(A)' & L(B))

                                                
                                            --------  --------
                                           / /  /  /\/  /  /  \        
                                          / /  /  // \ /  /  / \
                               L(A) ---> / /  /  //   \  /  /  /\ <--- L(B)
                                         \/  /  / \   / /  /  / /
                                          \ /  /  /\ / /  /  / / 
                                           \  /  /  /\   /  / /
                                            \/  /  /  \ /  / /         
                                             ------    ------

                              [ the shadow part are the symmetric difference ]


                2. Run TM T from the proof of E(DFA) on input (C)

                3. If T accepts(sym.diff = ø) then accept. If T rejects then reject




    [ Regular Language under Intersection ]:


        >> for adding suppliment proof for above (DFA after intersection still DFA)


        >> If L and M are regular languages, then so is L & M (intersect)           

            + Let A and B be DFAs whose regular languages are L and M, respectively

                1. construct C, the "product automation" of A and B

                    (C tracks the states in A and B, just like the proof of union without using NFAs)
                    (question) : how to proof union without NFA
                
                2. Make the final states of C be the pairs consisting of final states both A and B

                3. chapter 4 - p13



    [ A(CFG) ]: deciable


        >> A: acceptance 

        >> but since CFG generate string, the thought is about why it could generate a string w is in the langauge

            - wrong method

              : For CFG G and string w want to determine whether G generates w. One idea is to use G to go 
                through all derivations. This will not work, why?

              => because this method at best will yield a TM that is a recognizer, not a decider.
                 it can generate infinite strings and if w is not in the language, will neve know it
                 ( because won't halt )


    > smart way
    ------------------------------------------------------------------------------------------------------------- 
    |                                                                                                           |
    |   >> For CFG G and string w want to determine whether G generates w, not told whether w is in L(G)        |
    |                                                                                                           |
    |       + A string w of length n will have a derivation that uses 2n-1 steps                                |
    |           if the CFG is in Chomsky-Normal Form                                                            |
    |                                                                                                           |
    |           1. convert to Chomsky-Normal Form                                                               |
    |                                                                                                           |
    |           2. list all derivation of length 2n-1 steps. If any generates w, then accept, else reject       |
    |                                                                                                           |
    |           3. This is a variant of breadth first search, but instead of extended the depth 1 at a time     |
    |              we allow it to go from 1 to 2n-1 at a time. As long as finite depth extension, we are good   |
    |                                                                                                           |
    -------------------------------------------------------------------------------------------------------------


        >> keep in mind that the PDA we talk about is non-deterministic, which has more than deterministic PDA





    [ E(CFG) ]: decidable

        >> E: emptiness 

            + same idea with A(CFG), the goal is to check if there are strings in the language

            + in DFA we can if input reach accept state 

            + here we check if start variable generate variables, and those variables will eventually all reach terminals


        >> working backward (X -> YZ): 

            + from YZ to X

                1. start by marking all terminal symbols

                2. determine for each variable if it can generate any string of terminals and if so, mark it

                3. keep working backwards so that if the right hand side(YZ) of of any rule has only marked items,
                   then go to mark the LHS (backward)

                   • for example, if X -> YZ and Y and Z are marked, then mark X
                   
                   • if you mark S (start variable), then done; if nothing else to mark and S not marked, reject 

            


    [ EQ(CFG) ]:

        >> not decidable

        >> can use EQ(DFA) proof because CFGs are not closed under complement and intersection



    [ Every Context-Free Language ]:

        >> decidable

        >> we want to know if A, which is CFL, is deciable

            + A will have some CFG G that generates it

                1. when we proved that A(CFG) is deciable, we constructed a TM S that would tell us if any CFG 
                   accept a particular input w

                2. Now we use this TM and run it on input <G, w> and if it accepts, we accept; otherwise reject



# Hierarchy of Classes of Language



                                                                                
                            ----------------------------------------------------------
                            |                                                        | 
                            |                                                        |
                            |     ----------------------------------------------     |
                            |     |                                            |     |
                            |     |                                            |     |
                            |     |     ---------------------------------      |     |
                            |     |     |                               |      |     |
                            |     |     |                               |      |     |
                            |     |     |    -----------------------    |      |     |
                            |     |     |    |                     |    |      |     |
                            |     |     |    |                     |    |      |     |
                            |     |     |    |       regular       |    |      |     |
                            |     |     |    |                     |    |      |     |
                            |     |     |    |                     |    |      |     |
                            |     |     |    -----------------------    |      |     |
                            |     |     |                               |      |     |
                            |     |     |         context-free          |      |     |
                            |     |     |                               |      |     |
                            |     |     ---------------------------------      |     |
                            |     |                                            |     |
                            |     |                 decidable                  |     |
                            |     |                                            |     |
                            |     ----------------------------------------------     |
                            |                                                        |
                            |                  Turing-recognizable                   |
                            |                                                        |
                            ----------------------------------------------------------







# Halting Porblem

    >> prove not every turing-recognizable language is decidable


    [ definition ]:
        
        >> check whether a program will halt or not

        >> the problem to halting problem is that: it is algorithmically unsolvable
        


    [ ex ]:

        >> A(TM) = {(M, w) | M is a TM and M accepts w}

            + A(TM) is undeciable

                1. It can only be undeciable because of a loop of M on w
    
                2. IF we could determine if it will loop forever, then could reject, Hence A(TM) is often call the 
                                                                                                   halting problem
                3. this is Turing-recognizable



    [ Diagonalization Method ]:

        >> measuring the sizes of infinite sets

            + two finite/infinite sets have the same size if each element in one set can be paired with the 
              element in the other set

                => n = 2n


            + Rational Numbers
                
                • let Q = {m/n: m, n belongs to N}, the set of positive Rational Numbers, N = natural num (自然数)

                • Q seems larger, but they are the same according to our definition

                • we should be able to find a 1:1 correspondence between Q and N

                      
                                    -------------------------------
                                    | 1/1 | 1/2 | 1/3 | 1/4 | 1/5 |
                                    -------------------------------
                                    | 2/1 | 2/2 | 2/3 | 2/4 | 2/5 |
                                    -------------------------------
                                    | 3/1 | 3/2 | 3/3 | 3/4 | 3/5 |
                                    -------------------------------
                                    | 4/1 | 4/2 | 4/3 | 4/4 | 4/5 |
                                    -------------------------------
                                    | 5/1 | 5/2 | 5/3 | 5/4 | 5/5 |
                                    -------------------------------


                • bad way: going row-to-row, since first row is infinite, would never get to second row
            
                • good way: go diagonals order => 1/1, 2/1, 1/2, 3/1, ... 

                • that is, N=1 corresponds to 1/1; N=2 conrresponds to 2/1; N=3 corresponds 1/2 etc.
                        


    [ Pairing Set Items ]:


            + Theorem: R(real number) is Uncountable

                • real number is one that has a decimal representation and R is set of Real Number

                • includes those that cannot be represented with a finite number of digits (Pi or √2)

                • find some X that is always not in the pairings and thus proof by contradiction



                          < generate a number X, the following the the method for generating >
                        -------------------------------------------------------------------------
                        | n     | f(n)                                                          |
                        |-----------------------------------------------------------------------|
                        | 1     | 3.14159... ->(pick 1 at the first position after decimal)     |
                        |-----------------------------------------------------------------------|
                        | 2     | 55.5555... ->(pick 5 at second position ...)                  |
                        |-----------------------------------------------------------------------|
                        | 3     | 0.12345... ->(pick 3 at third ...)                            |
                        |-----------------------------------------------------------------------|
                        | 4     | 0.50000... ->(pick 0 at forth ...)                            |
                        -------------------------------------------------------------------------

                                                        x ≠ f(1)
                                                        x ≠ f(2)
                                                        x ≠ f(3)
                                                           .
                                                           .
                                                           .
                                                        x ≠ f(n)

                        keep choosing the "right-downward diagonal" of digits, we are guarantee
                        to have a value x not already in the list since it different at least
                        one position with every other number in the list



            + implication

                • R is uncountable -> some languages are not deciable or even Turing-recognizable
                                      (find x above is an algorithm and thus a language)
                                      because there are uncountably many languages yet only countably
                                      many Turing Machine

                • each Turing Machine can recognize a single language and there are more languages than 
                  Turing Machines, some language are not recognized by any Turing Machine



                • Common Sense Explanation

                    - comparing languages: a potentially infinite set of strings v.s. number of strings(1, 2, 3..)

                    - each language is represented by a sequence of infinite length whereas each individual string
                      is of finite (but unbounded) length

                    - string is to Language as Natural number is to Real number
                        
                    < no way to find one-to-one conrrespondence between natrual and real numbers (proof above) >



    [ diagonalization proof of A(TM) ]: p35-41


            + back to ex. of proving A(TM)

            + Let A(TM) = {<M, w> | M is a TM and accepts w}

            + proof Technique:

                • assume A(TM) is deciable and obtain a contradiction
                • A diagonalization proof

            + takes time to understand p36

            + Slightly More Concrete Version (with C++)


            ---------------------------------------------------------------------------------------------
            |                                                                                           |
            |   it's ok if you don't understand, just remember we cannot write a program to determine   | 
            |   if any arbitrary program will halt or loop                                              |
            |                                                                                           |
            ---------------------------------------------------------------------------------------------

            therefore A(TM) cannot be decided, so undecidable



    [ Co-Turing Recognizable ]: p40-43 




# Reducibility


    [ definition ]:

        >> converting one problem to another such that the solution to the scond can be used to solve the first

            
            + ex:

                • finding your way around NYC is reducible to the problem of finding and reading a map of NYC

            + If A reduce to B

                1. A can be no harder than B since the solution to B solves A

                2. A could be easier ( the reduction is "inefficient" in a sense )

                3. in the above ex, A is easier than B since B can solve any routing problem

                    - the one on the left is inefficient
                    - the one on the right is more powerful


            + Practice on Reducibility

                - which way is it ? 

                    1. reduce DFAs to NFAs

                    2. reduce NFAs to DFAs

                        a). NFA can be reduced (converted) to a DFA via a set of simple steps
                        b). NFA can not be any more powerful than a DFA, NFA could be less powerful
                        c). wrong!
                            because we know they have same expressive power
                            (question) : so cannot reduce in either way?


    [ prove languages undecidable ]:


        + if A is reduciable to B and B is decidable

            1. A is deciable (since A can only be "easier")

            2. B, which is decidable, can be used to solve A


        + if A is reducible to B and A is deciable

            - can say nothing


        + A is undeciable and reduciable to B

            1. B must be undecidable (B can only be harder than A)

            2. to show something undeciable, show an undecidable problem can be reduced to it.


    
    [ HALT(TM) is undeciable ]:


        >> proof by contradiction, the key idea is to show that A(TM) is reduciable to HALT(TM)

            1. you have a TM R that decides HALT(TM), use R to construct a TM S that deicdes A(TM)

                - but we know there is no such S could decide A(TM) because possible looping

                - so bad


            2. assume that you have a TM R that decies HALT(TM), you test whether M halts on w <M, w>
               instead of buliding a machine for testing <M, w>, testing <M, w> directly  

                - we are assuming there's a decider for HALT(TM), and use it to solve A(TM)

                - but as we know, not such machine, so R does not exist


        >> Formal Proof


            + let's assume for the purposes of obtaining a "contradiction" that TM R decides HALT(TM),
              we construct TM S to decide A(TM), with S operating as follows:

                S = "On input <M, w>, an enconding of a TM M and a string w:

                    1. Run TM R on input <M, w>
                    2. If R rejects, reject
                    3. If R acccepts, simluate M on w until it halts
                    4. If M has accepted, accept; if M has rejected, reject."


                clearly, if R decides HALT(TM), then S decides A(TM). indication of reducing A(TM) to HALT(TM)


            + the concept of A(TM) is if TM accept some input

                1. so here we set operation to be "Run TM R on input <M, w>"

                2. no matter what operation we set, A(TM) is proved by diagonally undeciable

                3. so it will be undeciable eventually, and therefore get contradition

                   HALT(TM) could not be deciable
                


    


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
