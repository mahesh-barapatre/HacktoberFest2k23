class Solution {
public:
    double myPow(double x, int n) {
      if (n==0) return 1.0;
      int n_mod2=n%2;
      double a=1.0;
      switch(n_mod2)
      {
          case 0:a=1;
            break;
          case 1: a=x;
            break;
          case -1: a=1.0/x;
            break;
      }
      return myPow( x*x, n/2)*a;
    }
};
