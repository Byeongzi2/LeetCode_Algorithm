class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        for(auto& now : strs) {
            string sortedStr = now;
            sort(sortedStr.begin(),sortedStr.end());
            m[sortedStr].emplace_back(now);
        }
        
        for(auto& inputVec : m) {
            ans.emplace_back(inputVec.second);
        }

        return ans;
    }
};