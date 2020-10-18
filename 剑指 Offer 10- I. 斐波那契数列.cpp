class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;

        int first = 1;
        int second = 1;
        int third = 1;
        while(n > 2)
        {
            third = (first + second)%1000000007;
            first = second;
            second = third;
            n--;
        }
        return third;
    }
};