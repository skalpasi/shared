# CO Tutorial 5

## Question 1a

C Code

    int main() {
      int r0 = 10;
      int r1 = 5;
      int r2;
      if (r0 == r1) {
        r2 = 1;
        return 0;
      }
      r2 = 0;
      return 0;
    }

Assembly

    mov r0, #10
    mov r1, #5
    sub r0, r0, r1
    bz r0, .L1
    mov, r2, #0
    bnz r0, .EXIT
    .L1:
      mov, r2, #1
    .EXIT:

## Question 1b

C Code 

    int main() {
      int r0 = 10;
      int r1 = 5;
      int r3 = 0;
      if (r0 == 0 || r1 == 0) return 0;
      for (int i=0; i<r1; i++) {
          r3 = r3 + r0;
      }
      return 0;
    }

Assembly

    mov r0, #10 
    mov r1, #5
    mov r4, #1
    sub r1, r1, r4
    mov r3, #0
    bz r0, .EXIT
    bz r1, .EXIT
    bz r3, .LOOP
    .LOOP:
      bz r1, .EXIT
      add r3, r3, r0
      sub r1, r1, r4
      bnz r1, .LOOP
    .EXIT:

## Question 1c

C Code

    int main() {
      int r0, 10;
      int sum = 0;
      for (; r0 >= 0; r0--) {
        sum = sum + r0;
      }
      return 0;
    }

Assembly

    mov r1, #0
    mov r0, #10
    mov r3, #1
    bz r1, .LOOP
    bnz r1, .EXIT
    .LOOP:
      add r1, r1, r0
      sub r0, r0, r3
      bnz r0, .LOOP
    .EXIT:

## Question 2a

| Cycle | PC | r0 | r1 | r2 | r3 |
|-------|----|----|----|----|----|
| 0     | 0  | 2  |NULL|NULL|NULL|
| 1     | 1  | 2  | 0  |NULL|NULL|
| 2     | 2  | 2  | 0  | 1  |NULL|
| 3     | 3  | 2  | 0  | 1  | 1  |
| 4     | 4  | 2  | 0  | 1  | 1  |
| 5     | 5  | 2  | 1  | 1  | 1  |
| 6     | 6  | 2  | 1  | 2  | 1  |
| 7     | 7  | 1  | 1  | 2  | 1  |
| 8     | 8  | 1  | 1  | 2  | 1  |
| 9     | 5  | 1  | 3  | 2  | 1  |
| 10    | 6  | 1  | 3  | 3  | 1  |
| 11    | 7  | 0  | 3  | 3  | 1  |
| 12    | 8  | 0  | 3  | 3  | 1  |
| 13    |END |END |END |END |END |

## Question 2b

Execution time = (# of instructions * CPI) / clock frequency
CPI = average cycle/instruction

Let n = no. of cycles in which that instruction is executed
CPI = inst1% * n1 + inst2% * n2 + .....

In given question, total instructions are 13. How?

    mov
    mov
    mov
    mov
    bz
    loop (2 times) {
      add
      add
      sub
      bnz
    }

Therefore, total instructions =  5 + 4*2 = 13 instructions

* % of mov instructions = 4/13 
* % of add instructions = (2/13)*2
* % of bz instructions = 1/13
* % of sub and bnz instructions = (1/13)*2 each

Given, n=1 for all instructions and clock speed = 1GHz

CPI = %mov*1 + %add*1 + %bz*1 + %sub*1 + %bnz*1

=> (4/13)*1 + (4/13)*1 + (1/13)*1 + (2/13)*1 + (2/13)*1 = 1

=> Execution time = (13 * 1) / 1 * 1000 * 1000 * 1000

=> T = 13ns

## Question 2c

* add, sub - 1 cycle
* bz, bnz - 2 cycles
* mov - 3 cycles

Total instructions and % is same as 2b.

Clock speed = 2GHz

New CPI = %mov*3 + %add*1 + %bz*2 + %sub*1 + %bnz*2

=> (4/13)*3 + (4/13)*1 + (1/13)*2 + (2/13)*1 + (2/13)*2 = 24/13

=> Execution time = (13 * (24/13)) / (2 * 1000 * 1000 * 1000)

=> T = 12ns