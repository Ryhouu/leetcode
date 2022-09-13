// Median of Two Sorted Arrays

#include<bits/stdc++.h>
using namespace std;

int num_lt(vector<int>& arr, double x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int j = (l + r) >> 1;
        if (arr[j] < x) l = j + 1;
        else r = j - 1;
    }
    return max(0, r + 1);
}

int num_le(vector<int>& arr, double x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int j = (l + r) >> 1;
        if (arr[j] <= x) l = j + 1;
        else r = j - 1;
    }
    return max(0, r + 1);
}

int num_gt(vector<int>& arr, double x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int j = (l + r) >> 1;
        if (arr[j] > x) r = j - 1;
        else l = j + 1;
    }
    return (l < arr.size()) ? arr.size() - l : 0;
}


bool bin_search(vector<int>& nums1, vector<int>& nums2, set<int>& medians) {
    int l = 0, r = nums1.size() - 1;
    while (l <= r) {
        int i = (l + r) >> 1;
        double x = nums1[i];

        int lt = num_lt(nums1, x) + num_lt(nums2, x);
        int eq = max(0, num_le(nums1, x) + num_le(nums2, x) - lt - 1);
        int gt = num_gt(nums1, x) + num_gt(nums2, x);

        int res = eq - abs(gt - lt);
        if (res >= 0 && res % 2 == 0) { 
            medians.clear();
            medians.insert(x);
            return true; 
        }
        else if (res + 1 >= 0) { medians.insert(x); }
        
        if (lt < gt) l = i + 1;
        else r = i - 1;
    }
    return false;
}
    
double solve(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    set<int> medians;
    bool res;

    res = bin_search(nums1, nums2, medians);
    if (res) { return *medians.begin(); }
    res = bin_search(nums2, nums1, medians);
    if (res) { return *medians.begin(); }

    double md;
    for (auto x : medians) { md += x; }
    return md / medians.size();
}

int main(){
    vector<int> nums1_1{1, 3};
    vector<int> nums2_1{2};
    cout << "expected: " << 2 << ", got: " << solve(nums1_1, nums2_1) << endl;
    
    vector<int> nums1_2{1, 2};
    vector<int> nums2_2{3, 4};
    cout << "expected: " << 2.5 << ", got: " << solve(nums1_2, nums2_2) << endl;
    
    vector<int> nums1_3{1};
    vector<int> nums2_3{};
    cout << "expected: " << 1 << ", got: " << solve(nums1_3, nums2_3) << endl;
    
    vector<int> nums1_4{};
    vector<int> nums2_4{3, 4};
    cout << "expected: " << 3.5 << ", got: " << solve(nums1_4, nums2_4) << endl;
    
    vector<int> nums1_5{2, 2, 4, 4};
    vector<int> nums2_5{2, 2, 4, 4};
    cout << "expected: " << 3 << ", got: " << solve(nums1_5, nums2_5) << endl;
    
    vector<int> nums1_6{2, 4, 4};
    vector<int> nums2_6{2, 2, 4, 4};
    cout << "expected: " << 4 << ", got: " << solve(nums1_6, nums2_6) << endl;
    
    vector<int> nums1_7{2, 2, 2, 2, 2};
    vector<int> nums2_7{4, 4};
    cout << "expected: " << 2 << ", got: " << solve(nums1_7, nums2_7) << endl;
    
    vector<int> nums1_8{3};
    vector<int> nums2_8{-2, -1};
    cout << "expected: " << -1 << ", got: " << solve(nums1_8, nums2_8) << endl;
    
    vector<int> nums1_9{2, 2, 2, 3};
    vector<int> nums2_9{4, 4};
    cout << "expected: " << 2.5 << ", got: " << solve(nums1_9, nums2_9) << endl;
    
    
    return 0;
}