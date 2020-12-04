class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& A, int K) 
    {
        sort(A.begin(), A.end(), cmp);
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] < 0 && K > 0)
            {
                A[i] *= -1;
                K--;
            }
        }

        if(K % 2 != 0) A[A.size() - 1] *= -1;

        int res = 0;
        for(int i : A) res += i;

        return res;
    }
};