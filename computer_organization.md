
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
      the reason why you need the minus one is because the calculation start at 2^0, so when you 4 digits, n = 4, then you are calculating only up to 2^3


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
      reminder. when you use shortcut, you will find sometime there's not 1 for you to flip or when you come across 1 is already the end, so use the normal process



# Two's complement
    >> occur when number need to be separated by positive and negative (signed number)
    >> A signed number representation where a leading 0 indicates positive number and a leading 1 indicates a negative number.
    : how to calcualte?
      + The complement of a value is obtained by complementing each bit(0 -> 1 or i -> 0), and then adding one to the result 

    [!]
    >> All computers use two's complement. sign and magnitude representation was tried in early computers, but was difficult to implement efficiently in hardware
    >> and the existing of both positive and negative 0 is problematic


    [!] 
    Knowing the 2^31 is 2,147,483,648 and so what is the base 10 value of the following two's complement number?
    1000 0000 0000 0000 0000 0000 0000 0000 = -2,147,483,648

    [explanation]
    The leftmost bit is multiplied by -2^31, then added with the remaining bits that are multiplied by those bits' usual positive base values. 
    Because those remaining bits are all 0's, the base ten value is just -2,147,483,648 + 0 = -2,147,483,648.

    [!]
    In the two's complement representation, the magnitude of the largest negative value is one greater than the magnitude of the largest positive number
    [ex.]
    for an 8-bit two's complement representation
    >> the most negative value is -128(10000000)    --> all number after leftmost one, follows the normal converation, if (signed number 10000001), then result is -127
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
        here we have two negative binary addition, so an negative result is expected, but the numbers are represented as 32-bit value the carry bit is lost and the result appears positive 



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

        [!]: not overflow, A positive number is being added to a negative number of a smaller magnitude, therefore overflow does not occur 
        [!]: It seems to have a theroemoe, that as long as positive number add negative number, not overflow will occur



    >> Shortcut to negate a two's complement binary number
       - starting from the rightmost number, looping from it until you see the first 1: the first 1 stays the same, and flip the numbers after first 1 to their complement

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
    no, because [1]1001, leftmost 1 will automactically removed, and left with 1001, which is negative. 1000 is -8, +1 at the rightmost, so -7 correct



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







# assembly language


    why is that the registar has different prefix letter, such as $t0, $s0, etc
    explanation on April 5 pptx, and it's also on the green sheet



    <4> float data type (32bit)
        
        PI: float

    <5> double: data type take more digits than float (64bit)
        - always take out two register space, because that's 32 bit base
        - might cause overflow be doesn't matter a lot


    <6> Division
        - only take two arguments after the operator
        >> div $t0, $t1
        - and quotient goes to lo, while remaindar goes to hi in the registar
        >> mflo $s0     # quotient
        >> mfhi $s1     # remaindar

    <7> Load Word (32bits)
        >> get something from RAM into CPU(registar is inside CPU)


    <8> Store word (32bits)
        >> get variable from CPU into RAM


    <9> Array

        -- basic --
        # Allocate space for the array --> int myArray[3];
        >> myArray:    .space 12 # bytes (reserve for 3 ints: 4 bytes each)
        
    
        # Initialized array --> int intArray[] = {10, 20, 30, 40, 50};
        >> intArray:   .word    10, 20, 30, 40, 50


        # Preload with the same value int SameValArray[5] = {[0...4] = 1}; 
        >> SameValArray:    .word   1:5


        # most straightforward way
        >> list:    .word   3, 0, 1, 2, 6, -2, 4, 7, 3, 7


        -- converting A[i] to Assembly --
        ex).
        >> sw $s0, myArray($t0)    # store s0 into myArray + offset stored in $t0(number/index)
        [IMPORTANT!]: for sw, left assigns to right side = (whatever value in $s0 goes into myArray at $t0)

        >> lw $t6, myArray($t1)    # Load content of (myArray + offset $t1) into $t6
        [!]: right to left


        ??????????????????
        -- loop --
        should figure what's going on for the first looping example(while version)
        ! la command(it's was used for storing the address of a array once in the example, what is it really mean)
        la $t3, list, is this a special character only used for uploading address? or it has other usage
        li $t2, 6

        sll $t2, $t2, 2 
        
        for loop version


        
    <10> Procedure Call
        
        >> jal proceduralName # jump and link

        proceduralName(ex. display):
        ..........


        >> ja $ra   # jump return address (back to the calling method)

        when meet jal, store the address or the work here, and jump to where the proceduralName at
        and excecute the code inside the proceduralName, 
        then jump back to where jal at



    <11> leaf Procedure (function)
        
        pointer

        >> stack pointer ($sp)


    <12> non-leaf procedure (function calling function, recursively)






# Decoding Instructions


    <1> how to determine which format it is based on opcode
        >> R format: 000000
        >> I format: 001000?



shift left logical: https://www.eecis.udel.edu/~davis/cpeg222/AssemblyTutorial/Chapter-12/ass12_2.html

2N

