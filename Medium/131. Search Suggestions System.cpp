class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto start=products.begin();
        sort(start,products.end());
        vector<vector<string>>ans;
        vector<string>temp;
        string curr="";
        for(auto c:searchWord)
        {
            curr+=c;
            temp.clear();
            start=lower_bound(start,products.end(),curr);      // providing first occurance
            
            //question asked 3 times so i<3 and 
            //start+i!=products.end() -> checks if we are out of index or not
            for(int i=0;i<3 && start+i!=products.end();i++)
            {
                //(start+i) gives the pointer and *(start+i) gives 
                //the value at the pointer->here string
                string s=*(start+i);        
                
                //if we dont find the curr then we are sure that we are not going to 
                //find it in the upcoming words as they are in sorted manner
                if(s.find(curr))break;         
                
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};