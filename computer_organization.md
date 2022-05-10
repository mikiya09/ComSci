
# Basic 
    >> how to convert base 10 number into binary or other base number?

      usually, first convert to binary, then to other base
      [ex.] 
      3(10) to base 4
      to binary: 0011
      base 4 is at most 3 ={0, 1, 2, 3}
      "0011" is in the range 3
      
      [ex.]
      4(10) to base 4
      to binary: 0100
      to base 4: 10
      [?]
      for example binary for 0100 is: 0*2^3 + 1*2^2 + 0*2^1 + 0*2^0  
      then when you are working with base 4: 1*4^1 + 0 *4^0

      - least significant bit: The rightmost bit (has the most weighted)
      - most significant bit:  The leftmost bit 
      [!] of a word 32 bits, what the is leftmost bit numbered? 
        + it's 31, because it starts at zero(0)



# Unsinged numbers
    >> what is the largest base ten number representable in 4 bits
    : 4 bits (0000)
    : largest (1111)
    : convert to base 10 --> 15

    >> what is the largest base 10 number representable in 8 bits?
    : 2^8 - 1 = 255
    : 11111111
    : 2^(numbers of bits) - 1



# IMPORTANT FACT!
    >> unsigned 
      + largest:  2^n - 1
      + smallest: 0
      [ex.] 
      1111 = 8+4+2+1 = 15
      [reason.]
      the reason why you need the minus one is because the calculation start at 2^0, 
      so when you 4 digits, n = 4, then you are calculating only up to 2^3


    >> signed 
      + largest:  2^(n-1) - 1
      + smallest: -2^(n-1) 
      [ex.] 
      1000 -(two's complement)-> 1000 --> -8
      [reason]
      the reason minus one inside n is because sign number seperate + and -, one group into two


    >> normal process of calcualting two's complement
      step 1. reverse all 0->1 or 1->0
      step 2. plus 1 on binary scale
      reminder. when you use shortcut, 
      you will find sometime there's not 1 for you to flip or when you come across 1 is already the end, so use the normal process



# Two's complement
    >> occur when number need to be separated by positive and negative (signed number)
    >> signed number representation where a leading 0 indicates positive number, a leading 1 indicates a negative number.
    : how to calcualte?
      + The complement of a value is obtained by complementing each bit(0 -> 1 or i -> 0), 
        and then adding one to the result 

    [!]
    >> All computers use two's complement. sign and magnitude representation was tried in early computers, 
       but was difficult to implement efficiently in hardware
    >> and the existing of both positive and negative 0 is problematic


    [!] 
    Knowing the 2^31 is 2,147,483,648 and so what is the base 10 value of the following two's complement number?
    1000 0000 0000 0000 0000 0000 0000 0000 = -2,147,483,648

    [explanation]
    The leftmost bit is multiplied by -2^31, 
    then added with the remaining bits that are multiplied by those bits' usual positive base values. 
    Because those remaining bits are all 0's, the base ten value is just -2,147,483,648 + 0 = -2,147,483,648.

    [!]
    In the two's complement representation, 
    the magnitude of the largest negative value is one greater than the magnitude of the largest positive number

    [ex.]
    for an 8-bit two's complement representation
    >> the most negative value is -128(10000000)    --> all number after leftmost one, follows the normal converation, 
       if (signed number 10000001), then result is -127
    >> the most positive value is 127(01111111)
    >> leftmost is used for representing positive and negative, as well as magnitude 


    [!] compute two's complement

    [positive]
    step 1. 0000 -(reverse)-> 1111
    step 2. 1111 + 1 = 10000
    step 3. keep it inside range, therefore 0000

    [negative]
    step 1. 1111 -(reverse)-> 0000
    step 2. 0000 + 1 = 0001
    step 3. within the ragne, therefore 0001

    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

      [ex.]
        7       5
      - 5     + 7
      ----    ----
        2      12
      
    <in hardware perspective, it's overflow, only number within limitation is taken, meaning i is ignore, so same result>

    [!] in base 10, what is the complement of 33? --> 100-33=67

  



# Overflow
    >> when the result of a proper operation are larger than can be represented in a register
      

      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
     
        1000 1111 0000 0000 0000 0000 0000 0000     (-1,895,825,408) +
      + 1000 0000 1111 1111 1111 1111 0000 0000     (-2,130,706,688)
      -----------------------------------------     ≠
     [1]0000 1111 1111 1111 1111 1111 0000 0000     (268,435,200)

        [!]: overflow occurs when the numbers' sign bits match, but yield a sum with a different sign bit
        here we have two negative binary addition, so an negative result is expected, but the numbers are represented 
        as 32-bit value the carry bit is lost and the result appears positive 



      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        
        0000 1111 0000 0000 0000 0000 0000 0000
      + 0111 0000 0000 0000 0000 0000 0000 0000
      -----------------------------------------
        0111 1111 0000 0000 0000 0000 0000 0000

        [!]: not overflow, positive numbers addition yield positive number



      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        0111 0000 0000 0000 0000 0000 0000 0000
      + 1111 0000 0000 0000 0000 0000 0000 0000
      -----------------------------------------
        0110 0000 0000 0000 0000 0000 0000 0000

        [!]: not overflow, A positive number is being added to a negative number of a smaller magnitude, 
             therefore overflow does not occur 
        [!]: It seems to have a theroemoe, that as long as positive number add negative number, not overflow will occur



    >> Shortcut to negate a two's complement binary number
       - starting from the rightmost number, looping from it until you see the first 1: the first 1 stays the same,
         and flip the numbers after first 1 to their complement

      [!]: 3(10) = 00000011(2) 
      [!]: two's complement = 11111101
      
      [?]: how to get the negative number if given a positive number in binary bits
           > get binary representaion of the positive
           > get its two's complement



# Extending Bits

    >> Given -5 in 8-bit two's complement: 11111011
      - extending to 16 bits yields
      : 11111111 11111011


# tricks

    [Signed Number]
    
    >> adding two positive number has a chance to create overflow                 0111 + 0001 = 1000 (-8)
    >> adding two negative number has a chance to create overflow as well         1000 + 1111 = [1]0111 (7)
    >> adding one positive and one negative will cannot overflow

    [practice]
    1011 + 1110 overflow? 
    no, because [1]1001, leftmost 1 will automactically removed, and left with 1001,
    which is negative. 1000 is -8, +1 at the rightmost, so -7 correct



# Fractions in Binary
    >> decimal representation: 0.111 = 1/10^1 + 1/10^2 + 1/10^3
    >> binary representation:  1.1101 = 1 + 1/2 + 1/4 + 0 + 1/16
      [ex.] it will convert to decimal: 1 + 0.5 + 0.25 + 0 + 0.0625
      [ex.] binary 10.101 to deciaml:   2 + 0 + 1/2 + 0 + 1/8 = 2.625
      [ex.] decimal 0.75 to binary:     0 + 1/2 + 1/4 = 0 + .1 + .01 = 0.11
      [ex.] decimal 16.75 to binary:    10000.11


    >> loss of precision
      : using a fix number of bits means that some numbers cannot be precisely represented in a computer
        - A fraction that requires more bits than the allocated space allows. Ex: 1/8 = 0.125 when only one fraction bit is available. This one needs three 3 fraction bits
        - A rational number with an infinitely-repeating fraction portion.    Ex: 2/3 = 0.6666..
        - An irrational number.                                               Ex: √2  = 1.41421
      [ex.]
      1/10 = 0.1 cannot be represented exactly in binary using three fraction bits.



    >> fixed point binary to decimal
      > 1101011001 = 11010 | 11001 



# Binary Floating point Arithmetic

    >> Binary floating-point representation
      + Sign: 1 bit --> 0 or 1
      + Exponent 8 bits, which is biased in this case 127
        [why]: the largest signed positive number is selected (I don't know why yet) --> in this case largest positive is 2^(n-1) -1 = 2^7 -1 = 127
      + Fraction: 23(I don't know why)

    >> Addition 
      
      [decimal] 
        2 x 10^2      0.02 x 10^4 
      + 3 x 10^4      3    x 10^4
      ----------      -----------
      ??????????      3.02 x 10^4
      


# Logic Gates

    >> general representation: 
      1. AND: •
      2. OR:  +
      3. NOT: ¬
  
    >> De Morgen Law: 
      : ¬(A • B)  = ¬A + ¬B
      : ¬(A + B)  = ¬A • ¬B


    >> NAND gates

      > as NOT gate
        [!]: AND between two identical inputs, is just that input, and negate it.
        [.]: combine two inputs --> ¬(A • B) --> ¬(A • A) --> ¬ A


      > as AND gate
        [!]: NAND(NOT AND) + NOT = AND
        [.]: ¬(A • B) --> ¬ (¬ (A • B)) --> A • B 
        [x]: NOT operator is represented by NAND

      > as OR gate
        [!]: NOT every element in the NAND, and NOT NAND by De Morgen Law
        [.]: ¬(A • B) --> ¬(¬A • ¬B) --> A • B
        [x]: NOT operator is represented by NAND

      > as NOR gate
        [!]: OR + NOT
        [.]: NAND as OR gate, and negate it 
      
  
    >> NOR gates
      
      > as NOT gate
        [!]: NOR between two identical inputs, is just that input, and negate it.
        [.]: ¬(A + B) --> ¬(A + A) --> ¬ A 
      
      > as OR gate
        [!]: NOT the NOT+OR, two negation cancel each other, and left with OR
        [.]: ¬(A + B) --> ¬ ¬(A + B) --> A + B

      > as AND gate
        [!]: NOT every element in the NOR, and NOT the NOR by De Morgen Law
        [.]: ¬(A + B) --> ¬ (¬A + ¬B) --> (A • B)

      > as NAND gate
        [!]: AND + NOT
        [.]: NOR as AND gate, and NOR as NOT gate



    >> Special Gates: XOR




# Half Adder & Full Adder

    >> how many gates are used to make Half Adder?
      - 4 gates
      - XOR
        : 2 AND gates + 1 OR gates
      - AND


    >> how many gates are used to make Full Adder?
      - 9 gates
        : 2 half adder
        : 1 OR gate

    >> how many gates are required to add two 10-bit numbers?
      [ex.]
        00000 11000
      + 01010 01000
      -------------
      
    >> [ every full adder take three inputs(two bits and one carrier) every half adder takes two inputs. ]
    >> when you calculate in head, you do horizontal adding, and in computer that require one two bits addition, which is one half adder
    >> and the rest needs a full adder, therefore for two 10-bit numbers, we need 9 fuller adders, and 1 half adder
    >> which is 9*9 + 4 = 85 




# ================================================



# Computer Architecture
        
    >> concepts.
        
        + logical description of its components and basic operations

        + in pure assembly language, one assembly 'instruction' corresponds to 
          one basic operation of the processor

        + the architecture is visiable in every instruction of the program


    >> Processor Architecture
    
        [ 1 ]: describe basic components and basic operations

        [ 2 ]: each processor 
                + has its own architecture
                + has its own assembly language


        [ ex ]:
                + Intel i5
                + AMD Ryzen
                + Apple M1




# MIPS

    >> MIPS comparation to C
            C: mostly independent of the processor, runs on the compiler that builds code specific to a processor
    [ ! ]   A: is written to control a specific processor
                + human readable
                + generates binary codes for processor and its architecture


    >> MIPS

    [ 1 ]: MIPS processor
            + Reduced Instruction Set Computer(RISC), so firstly, it's a computer
                • microprocessor designed to perform a smaller number computer instructions 
                  so it can operate at a higher speed
                • Simpler, Less Circuitry, Less expensive
            
            + older computer is the opposite
                • more complex, more instruction, more cost


            + the concept of MIPS assembly are transferable to other processors


            [ex]: PS4, Tesla Model 4



    [ 2 ]: MIPS Machine Instruction

        + basic machine circle
            1. fetch the next instruction from memory
            2. increment the program counter (next instruction) = refer to register name
            3. execute the instruction


        + machine code                                  :     assembly code
            0011 0100 0000 0001 0000 0000 0000 1001             ori  $1, $0, 9
            0000 0000 0100 0001 0000 0000 0001 1000             mult $2, $1
            0000 0000 0000 0000 0100 0000 0001 0010             mflo $8 
            0011 0100 0000 0001 0000 0000 0000 0101             ori  $1, $0, 5
            0000 0001 0000 0001 0000 0000 0001 1010             div  $8, $1


        + understand as some machine runs your machine code instruction, and tell the actual machine to do stuff


    
    [ 3 ]: MIPS basic structure

        + Von Neumann Architecture

            <1>. Memory holds data AND instructions
            <2>. instructions execute one at a time
            <3>. Main components: Input, CPU, Memory, Output
            for figure: p22-8

            <4>. Von Neumann bottleneck
                - the idea that computer system throughput is limited,
                  due to the relative ability of processors compared to top rates of data transfer.  
                  According to this description of computer architecture, 
                  a processor is idle(闲) for a certain amount of time while memory is accessed.




        + MIPS basics 
                                    ------------------------------------------------------
                                    |                                                    |
                                    |    --------------------------------------------    |
                                    |    |                                          |    |
                                    |    |                  CPU                     |    |
                                    |    |  (control unit + arithmetic/logic unit)  |    |
                                    |    |                                          |    |
                Input Device --->   |    |       ^                       |          |    |   ---> Output device
                                    |    --------|-----------------------|-----------    |
                                    |    |       |                       V          |    |
                                    |    |               Memory Unit                |    |
                                    |    |                                          |    |
                                    |    |                                          |    |
                                    |    |------------------------------------------|    |           
                                    |                                                    |
                                    |----------------------------------------------------|    
                                    
                                        (reigstar is in CPU, RAM is in memory unit) 


        + Memory Model
            
            Data:
                - MIPS memory is an array of 2^32 bytes, each bytes has a 32-bits address(8 hex = 32 bits(binary)          
            
            Operation
            
                * Load: copy from address in memory to register inside the processor

                * Store: copy from register to memory at a designated address
    


        + MIPS & Standard Computer Architecture 

            
                > hardware connected on a PCI bus to transmit data
                ===================================================================

                Hard Disk      Main Memory       Processor     Monitor     Keyboard 


                                                                           <-- slow
                ----------------------------- Bus ----------------------------------




# MARS: The MIPS Simulator


    >> MARS (MIPS Assembler and Runtime Simulator)

        + allow us to run machine code on laptop

        + component
            
            <1> register - fost storage in CPU chips

                .. list of $v0 command ..


            <2> MIPS Memory Segments (2 main part)
    
                .data   # is comment
                        # .data is where variables are stored, variable declaration
                        # they are store in RAM, not registar (outside of CPU)

                .text   # where your code resides
                        # unlike C/C++, the first line is the first to execute



            <3>
            =================================== example =====================================

                    -----------------------------------------------------------------
                    |                                                               |
                    |   int:            it takes 4 bytes to hold a 32 bit integer   |
                    |   char/string:    8 bits = 1 byte = 1 ASCII charater          |   
                    |                                                               |       
                    |   - each charater has a unique address -                      |           
                    |                                                               |
                    -----------------------------------------------------------------    
                    |
                    --> refer to Memory model: MIPS memory is an array of 2^32 bytes (p45-8)
                        1001008 | 1001009 | 100100a | 100100b ... | 100100f
                            H        e          l        l    ...      d

            ============================================

            .data   # declare your variables in RAM here

                    num1: .word 7   # int num1 = 7
                    num2: .word 10  

                    num3: .word 0x1a2b3c4d  # valid, number in hex
                    num4: .word 012         # valid, number in Octal(starts with 0)

                    myString: .asciiz "Hello World\n" 
                    


            .text 
                    lw $t0, num1    # load from RAM to registar(CPU)
                    lw $t1, num1
                    add $t2, $t0, $t1   # add two registers

                    li $v0, 1       # 1 is for int
                    syscall         # execute command




            <4> RAT: Register Allocation Table
                
                • shows where you put your variables:

                                RAT
                                ---
                int a;          $s1 = a
                int b;          $s2 = b
                int c;          $s3 = c






# registers name
        
    >> $v0 and $v1: for Return values from a function, 
       - not an execute command, only store instruction


    >> syscall: a command that does whatever $v0 indicates


    >> $a0 to $a3: for Argument (Parameters)
       - whatever you want to print, you need to finally store in some $a0..3


    >> $t0 to $t7: temporary variables (inside function)


    >> $s0 to $s7: saved variables (across functions)


    >> $sp: Stack pointer


    >> $pc: Program Counter - shows location in program







# MARS operation
            
    [ 1 ] add / addi

          + add
                • add = Verilog R[rd] = R[rs] + R[rt]
                    - R[] as an array of register values
                    - rd, rs, rt as index value
                • add two registers and store stores in a register
                    add $t3, $t1, $t2   # t3 = t2 + t1 
          + addi
                • addi = Verilog R[rt] = R[rs] + SignImm
                    - Immediate means a constant number
                    - addi $t1, $t2, 5  # t1 = t2 + 5
        

    [ 2 ] Labels (show later in the example)

        + you can any self-defined label


    [ 3 ] Branch (if and while)


        + fastest (takes 1 instruction cycle)
            
            • beq (branch equal to)
            • bne (branch not equal to)

            • j (jump to)

        + Pseudo-Instruction (takes 2 instruction)

            • bge (branch greater and equal than)
            • bgt (branch greater than)

            • bls (branch less and equal to)
            • blt (branch less than)



        + ex
        =========== while ==========
        C++

        int a=1;                        addi $s1, $zero, 1
        int b=5;                        addi $s2, $zero, 5
        int c=0;                        addi $s3, $zero, 0
        while (a<b)
        {                   whileloop:  beq $s1, $s2, endwhile      # check if $s1 and $s2 is equal, if yes, go to endwhile label
            c++;                        addi $s3, $s3, 1            # if no, execute line by line, that's assembly works
            b++;                        addi $s1, $s1, 1
        }                               j whileloop                 # reach here, jump to whileloop label section
                            
        cout << c;          endwhile:
                                        .....


        ============= if ===========
        int a=1;                    addi $s1, $zero, 1
        int b=5;                    addi $s2, $zero, 5
        int c=0;                    addi $s3, $zero, 0
        if (a < b)
        {                           bge $s1, $s2, else1
            c = 12;                 addi $s3, $zero, 12
        }                           j printArea
        else                 
            c = 42;          else1: addi $s3, $zero, 42
                         printArea: 
        cout << c;



        ============= print ==============
        .data
                myNum: .word 9

        .text
                li $v0, 1       # printing setup, 1 for print int
                la $a0, myNum   # load myNum to a0
                syscall         # execute


        ============= exit politely ============
        li $v0, 10
        syscall




# MARS operation 2

    <1> subtract (two ways)
        
        + sub $a0, $s0, $s1
        
        + sub $t0, $s0, $s1
          move $a0, $t0         # move means only different registar is design for different stuff
                                # check what's the meaning of $a0

        
    <2> multiply <3 ways> 

        + mul (3 arguments)
            
            =====================================
            addi $s0, $zero, 15     # s0 = 0 + 15
            addi $s1, $zero, 4      # s1 = 0 + 4
            mul $t0, $s0, $s1       # t0 = s0 * s1

            li $v0, 1
            add $a0, $zero, $t0
            syscall


        + mult: (2 arguments) - rarely use

            =====================================
            addi $t0, $zero, 2000       # t0 = 2000
            addi $t1, $zero, 10         # t1 = 10
            mult $t0, $t1               # t0 * t1

            # result goes into h1 and lo, similar to division
            mflo $s0
            add $a0, $zero, $s0

            li $v0, 1       # setting to 1 for printing integer
            syscall


        + sll: (shift left logical)
    
            =====================================
            addi $s0, $zero, 12
            sll $t0, $s0, 2        # s0*2 *2 (explanation below, shift left one position make it 2 times greater, 
                                              shift two position therefore 4 times greater, because of sll twice)
            add $a0, $zero, $t0

            li $v0, 1
            syscall


            < understanding shift left logical >
            -----------------------------------------------------------------------------------------------
            | before: 0110 0001 = 97(base 10)                                                             |
            |               <- move a bit left by one,                                                    |
            |                 low-order bit is replaced by a zero bit and the high-order bit is discarded |
            |                                                                                             |
            | after:  1100 0010 = 194(base 10)                                                            |
            |                                                                                             |
            | 97 * 2 = 194                                                                                |
            -----------------------------------------------------------------------------------------------

        

    <3> Division
        # only take two arguments after the operator
        < 3 arguments >
        >> div $s0, $t0, $t1                            # s0 = t0/t1
        >> div $s0, $t1, 10                             # s0 = t1/10

        < 2 arguments >
        # and quotient goes to lo
        # while remaindar goes to hi in the registar
        >> div $t0, $t1                                 # t0 = t0/t1
        >> mflo $s0     # quotient
        >> mfhi $s1     # remaindar


    <4> divide power




# MARS operation 3

    <1> Float & Double
        + same idea as in C++, double type could hold more bits

        PI: .float 3.141593                 # only 6 digits
        PIDouble: .double 3.1415926535      # more digits

        li $v0, 2           # 2 is for float
        lwc1 $f12, PI       # load WORD into coprocessor 1 (location for float & double)

        ldc1 $f2, PIDouble # load DOUBLE into coprocessor 1, at reg f2
        ldc1 $f4, PIDouble # another copy       # double take up the space of 2 registers (because 64 bits)

        add.d $f12, $f2, $f4
        li $v0, 3               # 3 is for double 
        syscall 



    <2> Load & Store word


    <3!> Array (special attention)

        -- basic --
        # Allocate space for the array --> int myArray[3];
        >> myArray:    .space 12 # bytes (reserve for 3 ints: 4 bytes each)
        
    
        # Initialized array --> int intArray[] = {10, 20, 30, 40, 50};
        >> intArray:   .word    10, 20, 30, 40, 50


        # Preload with the same value int SameValArray[5] = {[0...4] = 1}; 
        >> SameValArray:    .word   1:5


        #  second method is the most straightforward way
        >> list:    .word   3, 0, 1, 2, 6, -2, 4, 7, 3, 7


        # accessing Array Elements in RAM
        -- converting A[i] to Assembly --
        ex).
        >> sw $s0, myArray($t0)    # store s0 into myArray + offset stored in $t0(number/index)
        [IMPORTANT!]: for sw, left assigns to right side = (whatever value in $s0 goes into myArray at $t0)

        >> lw $t6, myArray($t1)    # Load content of (myArray + offset $t1) into $t6
        [!]: right to left



        # Loop Array
        =============================================================
        .data                           # declare storage to RAM
                size: .word 10
                list: .word 3, 0, 1, 2, 6, -2, 4, 7, 3, 7

        .text
                li $t0, 0               # load immediate (specific for loading int, that represent certain behavior)
                                        # 16 bits sign-extended
                                        # unsigned 16 bits 
                                        # 32 bits 
                lw $t1, size            # load word
                la $t2, list            # load address
                                        # they are all loading stuff from memory(RAM) to register table
        
        forlopp:
                bge $t0, $t1, exit      # for (int i=0; i<size; i++)
                lw $t3, 0($t2)          # get value from address, t2 is an address, 
                                        # first element's address in the array,
                                        # load it to register so that get corresponding int value

                li $v0, 1               # {
                add $a0, $t3, $zero     #     cout << list[i]
                syscall                 # }

                addi $t2, $t2, 4        # go the next position in address
                addi $t0, $t0, 1        # increment counter variable for comparaison requirement
                j foorloop

        exit:
                li $v0, 10              # polite exit
                syscall

        =============================================================




    <4> Procedure Call (to be continue)
        
        >> jal proceduralName # jump and link

        proceduralName(ex. display):
        ..........


        >> ja $ra   # jump return address (back to the calling method)

        when meet jal, store the address or the work here, and jump to where the proceduralName at
        and excecute the code inside the proceduralName, 
        then jump back to where jal at



    <5> *leaf Procedure (function)
        
        pointer

        >> stack pointer ($sp)


    <6> non-leaf procedure (function calling function, recursively)











# Decoding Instructions


    >> general steps

        <1> Pull first 6 bits (on left) out

        <2> Decode to find instruction

        <3> Read the format (R, I, J)

        <4> Read the instruction format and Verilog to get the answer syntax (find function first, last 6 bits)

        <5> Decode the rest of the instruction to get rs, rt, etc




    >> R format (for detail refer Green Sheet)

          op    |    rs   |    rt   |    rd   |    shamt  |  funct
        6 bits    5 bits    5 bits     5 bits    5 bits      6 bits

        op: operation code (opcode)            ------> used to determine which format is using, always do this first
        rs: first source register number
        rt: sceond source register number
        rd: destination register number
        shamt: shift amount (00000 for now)
        funct: function code


    >> Verilog
        
        + Used to model hardware

        + Can specify registers, wires, gates, clock, etc

        + Can test the logic before you "build"


    >> ex.

        hex code (instruction): 02324020 <base 16>

                    0    2    3    2    4    0    2    0
        binary:     0000 0010 0011 0010 0100 0000 0010 0000
                    -------++++++-------++++++------+++++++ 
        decimal:    opcode   17    18      8     0      32      ==> use them to refer the register in the green sheet

                             rs    rt      rd    0      (look it up code instruction set, 
                                                         use hex code for function reference, here is 20 <base 16>)
                                                         rs, rt, rd are referenced by decimal number

                    R format: add $t0, $s1, $s2




    >> I format (refer to green sheet & PPT)
        


    >> Questions


       • how to determine which format it is based on opcode
            >> R format: 000000
            >> I format: 001000?
            >> J


    >> more examples

        [ 1 ]: 0x00085880
                - R[rd] = R[rt] << shamt (with shamt equal to 00010, which is 2)

                - the meaning of x = y << 2 (C++)
                    > y * 2 * 2 and then assign the value in y to x




# Datapath


    >> PC (Program Counter)

        + it goes through instruction location/address one by one sequentially

        + that's why it has a operation of adding 4 at the begining (adding 4 move to next address in memory)

        + such each time adding 4 is a convention for next move

        + after loading the next address, find the commands in there


    >> Instruction Memory

        + read the instruction address, and decode it

        + give the instruction out

        + determine what to do for the next register


    >> register table

        + arithmetic operation usually goes to read register first
            • the contents at the address in RAM is sent out as Read Data

        + load word
            • loading value to memory from register table
            • go to Write register
            • finally pass to Data memory
            • output of Data memory is switched back to the write data(input) of the register set by the write register

    
    >> Sign-extend
    


    >> Mux

        + output of Data memory is switched back to the write data(input) of the register set



    >> Branch Instruction?



    >> ALU (actually many operation will go through ALU)
       -p64-10
        
        + Load/Store: F = add
        + Branch:     F = subtract
        + R-type:     F depends on funct field

        --------------------------------
        ALU control     :       Function
        0000                    AND
        0001                    OR
        0010                    add
        0110                    subtract
        0111                    set-on-less-than
        1100                    NOR




# Clock (keep the pace)

    >> Frequency = 1/TimePeriod
        + 1 cycle per second = Hertz

    >> to run computer faster
        + reduce the TimePeriod = Increase the Freq


    >> There is a lot more than just CPU speed(frequency) that affects performance

        + clock design
            •
            •
            •

        + why having clock?
            • want predictable values




# Performance

    >> Von Neumann Bottleneck
        + A machine will run only as fast as the slowest operation 

    
    >> Issue
        + Longest delay determines clock period 
            • critical path: load instruction
            • instruction memory -> register file -> ALU -> data memory -> register file

        + no feasible to vary period for different instructions

        + violates design principle 

    >> pipeline(ing)

        + improve performance

        + pipelined laundry: overloapping execution - parallelism
            (refer to p75-9 on the PPT)


        + MIPS pipeline

    >> Hazard

        + Structure hazards
            • a required resource is busy

        + Data hazard
            • need to wait for previous instruction to complete its data read/write

        + Control hazard
            • deciding on control action depends on previous instruction



    >> summary
        
        + Pipelining improves performance by increasing instruction throughput(吞吐量)
            • executing multiple instructions in parallel
            • each instruction has the same latency

        + Subject to hazards
            • Structure
            • data
            • control

        + Instruction set design affects complexity of pipeline implementation
            



# Still want to go faster (Components Affecting Performance)

    >> Limits of single Processor
        + more CPUs (x)
        + many reason for not working out, for example, no way to use all the CPUs

    >> Largest Reason for Multi-processor design failure
        
        + Applications
            • application were traditionally written for serial computation

        + Compiler to split code automatically, which is still not available
            • Software engineers still specify separable 'threads'

        + Operating System control
            • having a Ferrari...without a steering wheel


    >> cache memory 
        
        + inter-station that keep the history of virtual -> physical address look-up record, 
          so that next time looking for same address mapping is faster



    
    >> virtual memory (!)

        <1> When program is running, they reside in memory and occupy certain amount of memory
        <2> programm itself(as if they could think), think it is the only one running on memory 
            --> have a tendency to use up certain amount of memory
        <3> Every program CANNOT have all memory, which itself may be limited
        <4> how can program 'share' without knowing it is sharing


    >> Memory Management Unit (MMU)

        < 1 >. metaphor: at first, program look its spot in the physical memory address itself, 
               it doesn't how to effectively manage its spot, so does other program
        

        < 2 >. MMU is the door keeper, it arranges all programs to make use of all physical memory address


        < 3 >. they can't communicate like human, program doesn't aware the existence of MMU or the remaining space left, 
               they just find continguous spots and sit in

               + when program suit themselves in the memory address, order exist.
               + some finsih runing faster, some slower
               + when one is finish, it leaves, and empty out the space for another program
               + but other program might have size little smaller, but necessary fill in the whole empty, 
                 then there will be a gap left out
               + this gap is small that no new program has this size could fit in, 
                 but current running program is no using it as well

               ------> memory fragmentation <-------


        < 4 >. virtual address is created, here the word "virtual" holds its meaning just in terms of programs. To programs, 
               those address is virtual, but they don't know

        
        < 5 >. program find the assume they find the continguous spots and suit in, 
               but in reality those space might map separately to physical address by MMU


        < 6 >. there are different ways of managing space or slice the space, that is up to MMU


        < 7 >. when many programs is running together, there is a page table 

                + 4k for each page size
                + think of that each page contains list of mapping
                + and right now you have a book of page

                [!]: if some mapping is in the middle of the page, 
                     a way of mapping is to map the first 4k of program to the actual physical address, 
                     and let the rest map to the middle of the page


        + converts (mapping) requested address to a real, physical address
        |
        V
        + so that every program 'thinks' it starts at address zero, and owns all the memory
        |
        V
        + The MMU keeps a table to keep track of the proper locations

        [ ! ]: 
        1. therefore not contiguous blocks is required
        2. can handle spitting program #1s memory over several areas
        3. like a sandwiches style


  





        





