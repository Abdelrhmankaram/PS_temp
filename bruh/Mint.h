#include<bits/stdc++.h>
using namespace std;
#define ll long long
template < int mod = 1000000007 > struct modInt {

    int val;

    modInt(int V = 0) : val(V) { val %= mod; }

    modInt& operator += (const modInt& rhs) {
        if ((val += rhs.val) >= mod) val -= mod;
        return *this;
    }
    modInt& operator += (const int rhs) {
        if ((val += rhs) >= mod) val -= mod;
        return *this;
    }

    modInt& operator -= (const modInt& rhs) {
        if ((val += mod - rhs.val) >= mod) val -= mod;
        return *this;
    }
    modInt& operator -= (const int rhs) {
        if ((val += mod - rhs) >= mod) val -= mod;
        return *this;
    }

    modInt& operator *= (const modInt& rhs) { val = (1ll * val * rhs.val) % mod; return *this; }
    modInt& operator *= (const int rhs) { val = (1ll * val * rhs) % mod; return *this; }

    modInt& operator /= (const modInt& rhs) { return *this *= rhs.inverse(); }
    modInt& operator /= (const int rhs) { return *this *= modInt(rhs).inverse(); }

    modInt& operator %= (const modInt& rhs) { val %= rhs.val; return *this; }
    modInt& operator %= (const int rhs) { val %= rhs; return *this; }

    modInt& operator ++() { return *this += 1; }
    modInt& operator --() { return *this -= 1; }

    modInt operator ++(int unused) { modInt res(*this); ++*this; return res; }
    modInt operator --(int unused) { modInt res(*this); --*this; return res; }

    modInt operator + (const modInt& rhs) const { modInt res(*this); return res += rhs; }
    modInt operator + (const int rhs) const { modInt res(*this); return res += rhs; }

    modInt operator % (const modInt& rhs) const { modInt res(*this); return res %= rhs; }
    modInt operator % (const int rhs) const { modInt res(*this); return res %= rhs; }

    modInt operator - (const modInt& rhs) const { modInt res(*this); return res -= rhs; }
    modInt operator - (const int rhs) const { modInt res(*this); return res -= rhs; }

    modInt operator * (const modInt& rhs) const { modInt res(*this); return res *= rhs; }
    modInt operator * (const int rhs) const { modInt res(*this); return res *= rhs; }

    modInt operator / (const modInt& rhs) const { modInt res(*this); return res /= rhs; }
    modInt operator / (const int rhs) const { modInt res(*this); return res /= rhs; }

    modInt& operator = (const modInt& rhs) { val = rhs.val; return *this; }
    modInt& operator = (const int rhs) { val = rhs; return *this; }

    bool operator == (const modInt& rhs) const { return val == rhs.val; }
    bool operator == (const int rhs) const { return val == rhs; }

    bool operator != (const modInt& rhs) const { return val != rhs.val; }
    bool operator != (const int rhs) const { return val != rhs; }

    bool operator < (const modInt& rhs) const { return val < rhs.val; }
    bool operator < (const int rhs) const { return val < rhs; }

    bool operator <= (const modInt& rhs) const { return val <= rhs.val; }
    bool operator <= (const int rhs) const { return val <= rhs; }

    bool operator > (const modInt& rhs) const { return val > rhs.val; }
    bool operator > (const int rhs) const { return val > rhs; }

    bool operator >= (const modInt& rhs) const { return val >= rhs.val; }
    bool operator >= (const int rhs) const { return val >= rhs; }

    int operator () () const { return val; }

    modInt inverse() const { return power(mod - 2); }

    modInt power(ll n) const {
        modInt a = *this, res = 1;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a, n >>= 1;
        }
        return res;
    }

    modInt power(modInt n) const {
        modInt a = *this, res = 1;
        int e = n();
        while (e > 0) {
            if (e & 1) res *= a;
            a *= a, e >>= 1;
        }
        return res;
    }

    friend modInt operator ^ (modInt rhs, ll n) { return rhs.power(n); }
    friend modInt operator ^ (modInt rhs, modInt n) { return rhs.power(n); }

    friend std::istream& operator>>(std::istream& is, modInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const modInt& x) noexcept { return os << x.val; }

};
using Mint = modInt < >;