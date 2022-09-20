class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content_to_filePath_map;
        vector<vector<string>> result;
        
        for(auto dir : paths)
        {
            stringstream ss(dir);
            string root, temp;
            getline(ss, root, ' ');
            
            while(getline(ss, temp, ' '))
            {
                string file_path = root + '/' + temp.substr(0, temp.find('('));
                string file_content = temp.substr(temp.find('(')+1, temp.find(')') - temp.find('(') - 1);
                content_to_filePath_map[file_content].push_back(file_path);
            }
        }
        
        for(auto it : content_to_filePath_map)
        {
            if(it.second.size() > 1)
                result.push_back(it.second);
        }
        return result;
    }
};