class Solution {
private:
    string reference[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string s;
public:
    void backtrack(string& digits, int index)
    {
        if(index == digits.size())
        {
            res.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string tmp = reference[digit];
        for(int i = 0; i < tmp.size(); i++)
        {
            s.push_back(tmp[i]);
            backtrack(digits, index+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0) return res;
        backtrack(digits, 0);
        return res;
    }
};