class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 0) return 0;

        int left = 0;
        int right = numbers.size() - 1;
        int mid = 0;

        while(numbers[left] >= numbers[right])
        {
            if(right - left == 1)
            {
                mid = right;
                break;
            }

            mid = (left + right) >> 1;

            if(numbers[left] == numbers[right] && numbers[left] == numbers[mid])
            {
                int ans = numbers[left];
                for(int i = 0; i < right; i++)
                {
                    if(ans > numbers[i])
                    {
                        ans = numbers[i];
                    }
                }

                return ans;
            }

            if(numbers[mid] >= numbers[left])
            {
                left = mid;
            }

            else
            {
                right = mid;
            }
        }

        return numbers[mid];
    }
};