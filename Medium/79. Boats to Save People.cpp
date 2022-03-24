class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int start = 0, end = people.size()-1, count = 0;
        
        while(start <= end)
        {
            if(people[start] + people[end] <= limit)
                start++;
            
            end--;
            count++;
        }
        return count;
    }
};

/*
############### Initial approch ##################
class Solution {
public:
    bool static comparator(int a, int b)
    {
        return a>b;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end(), comparator);
        
        int start = 0, end = people.size()-1, count = 0;
        
        while(start < end)
        {
            if(people[start] + people[end] <= limit)
            {
                count++;
                start++;
                end--;
            }
            else
            {
                count++;
                start++;
            }
        }
        if(start == end)
            count++;
        
        return count;
    }
};
*/