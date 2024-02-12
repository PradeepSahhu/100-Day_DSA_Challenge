#include <iostream>
using namespace std;
#include <vector>
#include <set>

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    int n = nums1.size();
    int m = nums2.size();

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j])
            {
                s.insert(nums1[i]);
            }
        }
    }
    vector<int> ans(s.begin(), s.end());
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> num2 = {2, 3};

    vector<int> ans = intersection(nums1, num2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}