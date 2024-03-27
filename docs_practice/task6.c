// 6. https://leetcode.com/problems/binary-search/description/

int binarysearch(int* nums, int numsSize, int target) {
   int mid = 0;
   int start = 0;
   int end = numsSize -1;

   while (start <= end) {
       mid = (start + end) / 2;

       if (nums[mid] == target) return mid;

       if (target > nums[mid]) start = mid + 1;
       else end = mid -1;
   }

   return -1;
}