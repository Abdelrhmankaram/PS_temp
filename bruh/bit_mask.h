#include <bits/stdc++.h>
#define ll long long

#ifdef _MSC_VER
#define __builtin_popcount __popcnt
#define __builtin_clz __lzcnt
#endif

int const mod=1e9+7;

ll low_bit(ll n) {
    return (n & (-n));
}

int msb(int n){
    return (31-__builtin_clz(n));
}


/*
tricks on bitmask :-
{
    Set union : A | B

    Set intersection : A & B

    Set subtraction : A & ~B

    Set negation : ALL_ONES_BITS ^ A

    Set bit : A |= 1 << bit

    Clear bit : A &= ~(1 << bit)

    Flib bit : A ^= (1 << bit)

    Test bit : (A & 1 << bit) != 0

    int lo = s & ~(s - 1); // lowest one bit

    int lz = (s + lo) & ~s; // lowest zero bit above lo

    s |= lz; // add lz to the set

    s &= ~(lz - 1); // reset bits below lz

    s |= (lz / lo / 2) - 1; // put back right number of bits at end
}
*/