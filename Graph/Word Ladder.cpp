class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> se(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord) return level;
            for(int i=0;i<word.size();i++){
                string original=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(se.find(word)!=se.end()){
                        se.erase(word);
                        q.push({word,level+1});
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};