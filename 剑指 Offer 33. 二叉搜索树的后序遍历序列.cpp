class Solution {
public:
    bool verifyPostorderCore(vector<int>& postorder, int start, int end) 
    {
        if(start >= end)
        {
            return true;
        }

        int root = postorder[end];
        int i = start;
        for(; i < end; i++)
        {
            if(postorder[i] > root)
            {
                break;
            }
        }

        for(int j = i; j < end; j++)
        {
            if(postorder[j] < root)
            {
                return false;
            }
        }

        return verifyPostorderCore(postorder, start, i-1) && verifyPostorderCore(postorder, i, end-1);
    }
    
    bool verifyPostorder(vector<int>& postorder)
    {
        if(postorder.empty())
        {
            return true;
        }

        return verifyPostorderCore(postorder, 0, postorder.size()-1);
    }
};