#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()&&left<nums.size())
        {
            while (right < nums.size() && nums[right] == 0)
                right++;

            while (left < nums.size() && right < nums.size() && nums[left] == 0)
            {

                if (nums[right] != 0)
                {
                    std::swap(nums[left++], nums[right++]);
                }
                else
                    break;
            }

            while (left < nums.size() && nums[left] != 0)
                left++;
        }



    }
};


int main()
{
    vector<int> v1 = {1};
    Solution().moveZeroes(v1);




	return 0;
}