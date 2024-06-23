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
            nums[s[right]]++;//ÿ�������ݽ��봰��ʱ����nums���и���
            while (nums[s[right]] == 2)
            {
                nums[s[left]]--;//����nums
                left++;//������
            }
            len = (right - left + 1) > len ? (right - left + 1) : len;//����len
            //�����ݽ�����
            right++;
        }
        return len;
    }
};