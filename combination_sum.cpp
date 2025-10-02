#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) { result.push_back(current); return; }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for (auto &v : res) {
        for (int num : v) cout << num << " ";
        cout << endl;
    }
    return 0;
}
