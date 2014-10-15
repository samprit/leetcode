class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> unique;
        int left=0, right=0, maxLeft = 0, maxRight = -1;

        while(right<s.size()){
            if(unique.find(s[right]) != unique.end()){
                while(unique[s[right]] != 0){
                    unique[s[left]]--;
                    left++;
                }
            }
            unique[s[right]] = 1;
            if(maxRight - maxLeft < right - left){
                maxRight = right;
                maxLeft = left;
            }
            right++;
        }
        return (maxRight - maxLeft + 1);
    }
};