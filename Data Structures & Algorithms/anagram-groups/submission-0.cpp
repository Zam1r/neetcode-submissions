class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets; 
        for (const string& s : strs){
            string key = s; 
            sort(key.begin(), key.end());
            buckets[key].push_back(s);
        }
        vector<vector<string>> result; 
        for (auto& pair: buckets){
            result.push_back(move(pair.second));
        }
        return result; 
    }
};