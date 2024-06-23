#include<iostream>
#include<string>
using namespace std;
//https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int len = 0;
        int nums[129];
        for (int i = 0; i < 129; i++) nums[i] = 0;
        while (right < s.size())
        {
            nums[s[right]]++;//每次有数据进入窗口时，对nums进行更新
            while (nums[s[right]] == 2)
            {
                nums[s[left]]--;//更新nums
                left++;//出窗口
            }
            len = (right - left + 1) > len ? (right - left + 1) : len;//更新len
            //新数据进窗口
            right++;
        }
        return len;
    }
};