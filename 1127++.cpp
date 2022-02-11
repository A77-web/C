#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isLetteOrDig(char ch)
    {
        return((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 0 && ch <= 9));
    }
    void transform(string& s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    bool isPalindrome(string s)
    {
        if (s.size() <= 1)
            return true;
        transform(s);
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isLetteOrDig(s[left]))
                left++;
            while (right > left && !isLetteOrDig(s[right]))
                right--;
            while (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
void main()
{
    Solution a;
   cout<< a.isPalindrome("A man, a plan, a canal: Panama");
    
}