template<typename T>
T gcd(T a,T b){ // log N
    if(!b)return a;
    while(b&&(a%=b)&&(b%=a));
    return a|b;
}
template<typename T>
T lcm(T a,T b){
    if(!a&&!b)return 0;
    return a/gcd(a,b)*b;
}
