class Solution {
public:
    int strStr(string h, string n) {
        
    size_t found = h.find(n);
	if (found != string::npos){
		return found;
    }
    return -1;
    }
};