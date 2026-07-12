class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need, window;
        for(auto c : t){
            need[c]++;
        }
        int l = 0, r = 0, n = s.size(), valid = 0, start = 0;
        int ln = INT_MAX;
        while(r < n){
            if(need.count(s[r])){
                window[s[r]]++;
                if(need[s[r]] == window[s[r]]){
                    valid++;
                }
            }
            while(need.size() == valid){
                if(r - l + 1 < ln){
                    ln = r - l + 1;
                    start = l;
                }
                if(need.count(s[l])){
                    if(need[s[l]] == window[s[l]]){
                        valid--;
                    }
                    window[s[l]]--;
                }
                l++;
            }
            r++;
        }

        return ln == INT_MAX ? "" : s.substr(start, ln);
    }
};
