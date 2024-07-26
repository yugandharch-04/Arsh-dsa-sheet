class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string> ans;
        vector<string> temp;
        for(int i=0;i<n;i++){
            temp.clear();
            temp.push_back(words[i]);
            int rem=maxWidth-words[i].size();
            int j;
            for(j=i+1;j<n;j++){
                if(words[j].size()+1<=rem){
                    temp.push_back(words[j]);
                    rem-=1+words[j].size();
                }
                else break;
            }
            i=j-1;
            string s;
            int total_lenght=0;
            for(auto a: temp){
                total_lenght+=a.size();
            }
            int spaces_req=maxWidth-total_lenght;
            s+=temp[0];
            if(temp.size()==1){
                ans.push_back(s);
                while(ans.back().size()<maxWidth){
                    ans.back().push_back(' ');
                }
                continue;
            }
            int space_per_word=spaces_req/(temp.size()-1);
            int extraspace=spaces_req%(temp.size()-1);
            for(int g=1;g<temp.size();g++){
                string a=temp[g];
                for(int h=0;h<space_per_word;h++){
                    s.push_back(' ');
                }
                if(extraspace>0){
                    s.push_back(' ');
                    extraspace--;
                }
                s+=a;
            }
            ans.push_back(s);
            
        }
        ans.pop_back();
        string s;
        s+=temp[0];
        for(int g=1;g<temp.size();g++){
            string a=temp[g];
            s.push_back(' ');
            s+=a;
        }
        ans.push_back(s);
        while(ans.back().size()<maxWidth){
            ans.back().push_back(' ');
        }
        return ans;
    }
};