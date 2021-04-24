inline ll square(ll a) {a %= MOD;return (a * a) % MOD;}
ll lpow(ll a,ll b){
  a %= MOD;
  b %= MOD - 1;
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2) {
    return (square(lpow(a, b / 2) % MOD) * a) % MOD;
  } else {
    return square(lpow(a, b / 2) % MOD);
  }
}
//*
ll fact(ll n) {
  ll ans=1;
  while(n) {
    ans=(ans * n--) % MOD;
  }
  return ans;
}

inline ll rfact(ll n) {
  return lpow(fact(n), MOD - 2);
}
/*/
vl _fact;
vl _rfact;
void init(ll max) {
  _fact.resize(max + 1);
  _rfact.resize(max + 1);
  
  _fact[0] = 1;
  REP(i, 1, max+1) _fact[i] = _fact[i-1] * i % MOD;

  _rfact[max] = lpow(_fact[max], MOD - 2);
  REPR(i,max) _rfact[i] = _rfact[i + 1] * (i + 1) % MOD;
}

inline ll fact(ll n) {
  return _fact[n];
}

inline ll rfact(ll n) {
  return _rfact[n];
}
//*/

ll perm(ll n,ll r) { // nPr
  return fact(n) * rfact(n - r) % MOD;
}

ll comb(ll n, ll r) { // nCr
  return perm(n, r) * rfact(r) % MOD;
}

ll homo(ll n, ll r) { // nHr
  return comb(n + r - 1, r);
}
