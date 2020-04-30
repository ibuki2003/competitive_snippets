template<ll MODULO=MOD> // modulo should be prime
class mint{
    static_assert(MODULO>0, "modulo should be positive");
private:
    ll a;
    constexpr static ll _nl(const ll&a){return a>=0?a%MODULO:MODULO-(-a-1)%MODULO-1;}
public:
    constexpr static ll phi() {
        ll ans=MODULO;
        ll nn=MODULO;
        for (ll x = 2; x*x <= nn; ++x) {
            if (nn % x == 0) {
                ans -= ans / x;
                while (nn % x == 0) nn /= x;
            }
        }
        if (nn > 1) ans -= ans / nn;
        return ans;
    }
    mint():a(0){}
    mint(const ll&a):a(_nl(a)){}
    mint(const mint&o):a((ll)o){}

    inline mint&operator=(const ll&o){a=_nl(o);return*this;};
    inline operator ll()const{return a;}
    inline operator bool()const{return (bool)a;}

    inline mint&operator+=(const ll&o){a=_nl(a+_nl(o));return*this;};
    inline mint&operator-=(const ll&o){a=_nl(a+_nl(-o));return*this;};
    inline mint&operator*=(const ll&o){a=_nl(a*_nl(o));return*this;};
    inline mint&operator/=(const ll&o){a=_nl(a*_nl(phi()-_nl(o)));}
    inline mint&operator%=(const ll&o){a=_nl(a%_nl(o));return*this;};
    inline mint&operator^=(const mint<phi()>&o){
        if(o==0)a=1;
        if(o<=1)return*this;
        ll aa=a;
        *this^=(o/2);
        if(o%2)*this*=aa;
        return*this;
    }

    const mint operator+(const ll&o)const{mint b(a);return b+=o;}
    const mint operator-(const ll&o)const{mint b(a);return b-=o;}
    const mint operator*(const ll&o)const{mint b(a);return b*=o;}
    const mint operator/(const ll&o)const{mint b(a);return b/=o;}
    const mint operator%(const ll&o)const{mint b(a);return b%=o;}
    const mint operator^(const ll&o)const{mint b(a);return b^=o;}

    inline const mint operator+()const{return *this;}
    inline const mint operator-()const{return mint(-a);}
};

template<ll M>ostream&operator<<(ostream&o,const mint<M>&v){return o<<(ll)v;}
template<ll M>istream&operator>>(istream&i,mint<M>&v){ll b;i>>b;v=b;return i;}
