template<ll M=MOD>
class mint{
  constexpr static bool is_prime(ll n) {
    if (n == MOD) return true;
    for (ll i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
  }
  static_assert(M>0, "modulo should be positive");
  static_assert(is_prime(M), "modulo should be a prime number");
private:
  ll a;
  inline constexpr static ll _nl(const ll&a){return (a%M+M)%M;}
public:
  mint():a(0){}
  mint(const ll&a):a(_nl(a)){}
  mint(const mint&o):a((ll)o){}

  inline mint&operator=(const ll&o){a=_nl(o);return*this;};
  inline operator ll()const{return a;}
  inline operator bool()const{return (bool)a;}

  inline mint&operator+=(ll o){a = _nl(a + _nl(o));return *this;};
  inline mint&operator-=(ll o){a = _nl(a - _nl(o));return *this;};
  inline mint&operator*=(ll o){a = _nl(a * _nl(o));return *this;};
  inline mint&operator/=(const mint<M>&o){return *this *= o.inv();}

  mint&operator^=(ll o) {
    o %= MOD - 1;
    if (o == 0) {a = 1; return *this;}
    if (o == 1) return *this;
    ll aa = a;
    *this ^= (o/2);
    a = _nl(a * a);
    if (o % 2) *this *= aa;
    return *this;
  }

  const mint inv() const {return *this ^ (M - 2);}

  const mint operator+(ll o) const {mint b(a);return b+=o;}
  const mint operator-(ll o) const {mint b(a);return b-=o;}
  const mint operator*(ll o) const {mint b(a);return b*=o;}
  const mint operator/(const mint<M>&o)const{mint b(a);return b/=o;}
  const mint operator^(ll o) const {mint b(a);return b^=o;}

  inline const mint operator+() const {return *this;}
  inline const mint operator-() const {return mint(-a);}
};

template<ll M>ostream&operator<<(ostream&o,const mint<M>&v){return o<<(ll)v;}
template<ll M>istream&operator>>(istream&i,mint<M>&v){ll b;i>>b;v=b;return i;}
