Bit Manipulation
-----------------

#### Bitwise operator in c++
- `&` AND operator
- `||` OR operator
- `^` XOR operator, returns true if both the bits are diff
- left shift operator `<<`, shift the bits to the left side
    ex. 3 << 1 (shift to the left i.e. add zero at the end and ignores the first bit
                in the binary representation)
        here, I'm using 32 bit representation

    ```
    000000....110
    00000....1100 (after left shift by 1)
    ```
- right shift `>>`, shifts the bits to the right side i.e. `x >> y` means right shifting y bits 
    i.e. adding zero in the start and ignoring the last bit in the binary representatio

    ```
    000000....110
    00000....0011 (after left shift by 1)
    ```
    - `x << y` is equivalent to `x * 2^y` if x has trailing zeros in the binary represenation
    - `x >> y` is equivalent to `[x / 2^y]` ( floor division )
- `~` bitwise not operator - take binary representation and inverts all the bits
    it is a uniary operator unlike previous ones.
    ```
    0000....0001111 (x)
    1111....1110000 (~x)
    ```
- negative numbers are represented using 2's complement method, where all bits are inverted
and 1 is added in the last 
ex. for 3 using 4 bit representation
    ```
    0011 (3)
    1101 (-3)
    ```
- `n & (n-1)` -> set the last set bit as zero 
    ```
      0011 - (3)
    & 0010 - (2)
      ----------
      0010 - last set bit of 3, became zero
    ```

#### Problems:
- [Check if k_th bit is set or not](./check_if_kth_bit_set_or_not.cpp)
- [count set bit](./count_set_bits.cpp)
- [find one odd occuring element](./one_odd_occuring.cpp)
- [find two odd occuring elements](./two_odd_occuring_nums.cpp)
- [check if a number if power of two or not](./power_of_two.cpp)
- [print power set for a given string](./power_set.cpp)


[main menu](../../README.md)
