class Solution {
public:
    
    int getVal(char c){
       switch(c)
       {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;  
       }
    }
        
    
    int romanToInt(string s) {
        
        int sum = 0;
        for(int i=0; i<s.length()-1; i++)
        {
            int first = getVal(s[i]);
            int second = getVal(s[i+1]);
            
            if(first<second)
                sum-=first;
            else
                sum+=first;
        }
       sum+=getVal(s.back());
      return sum;  
    }
};