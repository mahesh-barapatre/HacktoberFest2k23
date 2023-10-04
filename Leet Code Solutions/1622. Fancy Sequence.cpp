long long modInverse(long long A, long long M)
{
    long long m0 = M;
    long long y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        long long q = A / M;
        long long t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
 
    return x;
}


class Fancy {
public:
vector<vector<long long>> arr;
long long sum;
long long mod;
long long mul = 1;
    Fancy() {
        sum = 0;
        mod = 1e9+7;
    }
    
    void append(int val) {
        arr.push_back({val, mul, sum});
    }
    
    void addAll(int inc) {
        sum = (inc+sum)%mod;
    }
    
    void multAll(int m) {
        sum = (m*sum)%mod;
        mul = (mul*(long long)m)%mod;
    }
    
    int getIndex(int i) {
        if(i>=arr.size()) return -1;
        long long val = arr[i][0], m = arr[i][1], bal = arr[i][2];
        long long div = modInverse(m, mod);
        long long add = sum;
        long long bm = (mul * div)%mod;
        bal = (bal*bm)%mod;
        add = (add + mod - bal)%mod;
        val = (val*bm)%mod;
        return (val + add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
