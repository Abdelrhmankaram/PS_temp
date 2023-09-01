#include <bits/stdc++.h>
#define ll long long
int const mod=1e9+7;
int const N=100000+5;

ll gcd(ll a, ll int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

ll fast_power(ll num, ll p) {
    if (!p)return 1;
    ll a = fast_power(num, p / 2);
    a *= a;
    if (p & 1)a *= num;
    return a;
}

ll _ceil(ll a, ll b){
    return (a + b - 1) / b;
}

ll modular_fast_power(ll num, ll p) { //Modular Exponentiation log n
    if (!p)return 1;
    ll a = modular_fast_power(num, p >> 1);
    a = ((a % mod) * (a % mod)) % mod;
    if (p & 1)a = ((a % mod) * (num % mod)) % mod;
    return a % mod;
}

ll sum(ll n){
    return n*(n+1)/2;
}
bool prime1(ll n){
    if(n<2)return 0;
    for(ll i=2;i<n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
bool prime2(ll n){
    if(n<2)return 0;
    for(ll i=2;i<=n/i;i++){
        if(n%i==0)return 0;
    }
    return 1;
}

/*bitset<N>is_prime;
void sieve(){
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(ll i=2;i<=N/i;i++){
        if(is_prime[i]){
            for(ll j=i*i;j<N;j+=i){
                is_prime[j]=0;
            }
        }
    }
}
bool is_prime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}*/