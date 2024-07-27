class Solution {
public:

    string addBinary(string a, string b) {
        if(a=="0") return b;
        if(b=="0") return a;

        int l=min(a.length(),b.length());
        int as=a.length();
        int bs=b.length();
        int carry=0;
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<l;i++){
            if(carry){
                if((a[i]=='1')&&(b[i]=='1')) ans.push_back('1');
                else if((a[i]=='0')&&(b[i]=='1')) ans.push_back('0');
                else if((a[i]=='1')&&(b[i]=='0')) ans.push_back('0');
                else if((a[i]=='0')&&(b[i]=='0')){
                    ans.push_back('1');
                    carry=0;
                }
            }
            else{
                if((a[i]=='1')&&(b[i]=='1')){ 
                    ans.push_back('0');
                    carry=1;
                }
                else if((a[i]=='0')&&(b[i]=='1')){ 
                    ans.push_back('1');
                }
                else if((a[i]=='1')&&(b[i]=='0')) {
                    ans.push_back('1');
                }
                else if((a[i]=='0')&&(b[i]=='0')){
                    ans.push_back('0');
                }
            }
        }
        if(l==bs){
            for(int i=l;i<as;i++){
                if(carry){
                    if(a[i]=='1') ans.push_back('0');
                    else{
                        ans.push_back('1');
                        carry=0;
                    }
                }
                else{
                    ans.push_back(a[i]);
                }
            }
        }
        else{
            for(int i=l;i<bs;i++){
                if(carry){
                    if(b[i]=='1') ans.push_back('0');
                    else{
                        ans.push_back('1');
                        carry=0;
                    }
                }
                else{
                    ans.push_back(b[i]);
                }
            }
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};