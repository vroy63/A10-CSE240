#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {4, 2, 5, 1, 3};

    sort(nums.begin(), nums.end());

    for(int n : nums){
        cout << n << " ";
    }
    return 0;

}