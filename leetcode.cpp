33. Search in Rotated Sorted Array
Medium
1700
257


Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while(first != last){
           const int mid = first + (last- first)/2;
            if(nums[mid] == target) 
                return mid;
            if(nums[first] <= nums[mid]){
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            }else{
                if(nums[mid] < target && target <= nums[last-1])
                    first = mid +1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};

81. Search in Rotated Sorted Array II
Medium
458
225


Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while(first != last){
            const int mid = first + (last - first)/2;
            if(nums[mid] == target) 
                return true;
            
            if(nums[first] < nums[mid]){
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            }else if(nums[first] > nums[mid]){
                if(nums[mid] < target && target <= nums[last-1]) //注意边界的最大下标
                    first = mid +1;
                else 
                    last = mid;
            }else{
                ++first;
            }
        }
        return false;
    }
};

4. Median of Two Sorted Arrays
Hard

3324

416

Favorite

Share
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        if (total & 0x1)
            return find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
        else
            return (find_kth(nums1.begin(), m, nums2.begin(), n, total / 2) 
                    + find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
    }
private:
        static int find_kth(std::vector<int>::const_iterator A, int m,
                            std::vector<int>::const_iterator B, int n, int k) 
        {
            //always assume that m <= n
            if (m > n) return find_kth(B, n, A, m, k);
            if (m == 0) return *(B + k - 1);
            if (k == 1) return min(*A, *B);
            //divide k into two parts
            int ia = min(k / 2, m);
            int ib = k - ia;
            if (*(A + ia - 1) < *(B + ib - 1))
                return find_kth(A + ia, m - ia, B, n, k - ia);
            else if (*(A + ia - 1) > *(B + ib - 1))
                return find_kth(A, m, B + ib, n - ib, k - ib);
            else
                return A[ia - 1];
        }
};