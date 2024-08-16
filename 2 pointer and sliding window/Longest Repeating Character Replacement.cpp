class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int hash[26]={0};
        int max_f=0;
        int ans=0;
        // unoptimized
        while(r<n){
            hash[s[r]-'A']++;
            max_f=max(max_f,hash[s[r]-'A']);
            while((r-l+1)-max_f>k){
                hash[s[l]-'A']--;
                max_f=0;
                for(int i=0;i<26;i++) max_f=max(max_f,hash[i]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }

        //optimized
        while(r<n){
            hash[s[r]-'A']++;
            max_f=max(max_f,hash[s[r]-'A']);
            // while((r-l+1)-max_f>k){
            if((r-l+1)-max_f>k){
                hash[s[l]-'A']--;
                max_f=0;
                // for(int i=0;i<26;i++) max_f=max(max_f,hash[i]);
                l++;
            }
            // ans=max(ans,r-l+1);
             if((r-l+1)-max_f<=k) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};