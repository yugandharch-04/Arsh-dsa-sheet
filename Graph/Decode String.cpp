class Solution {
public:
    
    string decodeString(string s) {
       string ans = "";
        stack<char> st;
        stack<int> m;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                string t = "";
                t.push_back(s[i]);
                for(int j = i+1 ; j < s.size();j++){
                    if(s[j] >= '0' && s[j] <= '9'){
                        t.push_back(s[j]);
                    }
                    else{
                        i = j - 1;
                        break;
                    }
                }
                int num = stoi(t);
                m.push(num);
            }
            else if(s[i] == ']'){
                int rep = m.top();
                m.pop();
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                string str = temp;
                for(int j = 1; j < rep; j++){
                    str += temp;
                }

                if(!st.empty()){
                    for(int k = 0; k < str.size(); k++){
                        st.push(str[k]);
                    }
                }
                else{
                    ans += str;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string te = "";
        while(!st.empty()){
            te += st.top();
            st.pop();
        }
        reverse(te.begin(),te.end());
        ans += te;
        return ans;
    }
};