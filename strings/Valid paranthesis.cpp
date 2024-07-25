class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s){
            if((c=='}')||(c==')')||(c==']')){
                if(stack.empty()) return false;
                switch (c){
                    case '}':
                        if(stack.top()=='{') stack.pop();
                        else return false;
                        break;
                    case ')':
                        if(stack.top()=='(') stack.pop();
                        else return false;
                        break;
                    case ']':
                        if(stack.top()=='[') stack.pop();
                        else return false;
                        break;
                }
            }
            else stack.push(c);
        }
        if(stack.empty()) return true;
        return false;
    }
};