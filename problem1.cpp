// Time Complexity :    O(n*m*m)                     wordList.length = n, beginword.length = m
// Space Complexity : O(n*m*m)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach

// 1. we do a bfs by search for a string neighbor in wordList.
// 2 . string neighbors should be generated by replacing a character with a to z
// 3. when we find a string equal to endword,return level else zero
// 4. for efficient lookup we use a set of wordlist


class Solution {
public:
    unordered_set<string>set;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set = unordered_set<string>(wordList.begin(),wordList.end());
        queue<string>q;
        set.erase(beginWord);
        q.push(beginWord);
        int lvl = 1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto p = q.front();q.pop();
                if(p == endWord) return lvl;
                vector<string>neigh = neighbor(p);
                for(auto &e:neigh){
                    if(set.count(e)>0){
                        q.push(e);
                        set.erase(e);
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
    vector<string> neighbor(string &s)
    {
        int m = s.size();
        vector<string>res;
        for(int i = 0;i<m;i++)
        {
            string p = s;
            for(char ch = 'a';ch<='z';ch++)
            {
                p[i] = ch;
                if(set.count(p)>0) res.push_back(p);
            }
        }
        return res;
    }
};
