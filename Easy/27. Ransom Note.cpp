class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(magazine.length() < ransomNote.length()) {return false;}
        
        int arr[26] = {0};
        
        for(int i=0; i<ransomNote.length(); i++)
        {
            arr[ransomNote[i] -'a']++;
        }
        for(int i=0; i<magazine.length(); i++)
        {
            arr[magazine[i] -'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(arr[i] > 0)
                return false;
        }
        return true;
    }
};