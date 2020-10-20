#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int last = nums.size();
        if (last == 0) return 1;
        nums.push_back(nums[0]);
        nums[0] = 0;
        for (int i = 1; i <= last; i++) {
            if (nums[i] == i) continue;
            if (nums[i] <= 0 ||nums[i]>last || nums[i]==nums[nums[i]]) {
                nums[i--] = nums[last--];
                nums.pop_back();
            }
            else {
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
                i--;
            }
        }
        for (int i = 1; i <= last; i++) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};

int main() {
    Solution x;
    vector<int> nums = {3,4,-1,1};
    x.firstMissingPositive(nums);
}