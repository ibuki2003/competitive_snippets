map<int, int> prime_factors(int n) {
    map<int, int> res;
    if(n == 1) {
        return res;
    }
    for(int i = 2, _n = n; i*i <= _n; ++i) {
        while(n % i == 0) {
            ++res[i]; // 素数i^{res[i]}
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}
