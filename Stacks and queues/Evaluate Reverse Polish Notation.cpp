class Solution {
public:
    int checkSign(string ch){
        if(ch=="+") return 1;
        if(ch=="-") return 2;
        if(ch=="*") return 3;
        if(ch=="/") return 4;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            int sign=checkSign(it);
            if(sign==-1){
                st.push(stoi(it));
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(sign==1) st.push(b+a);
                if(sign==2) st.push(b-a);
                if(sign==3) st.push(b*a);
                if(sign==4) st.push(b/a);
            }
        }
        return st.top();
    }
};