class StockSpanner {
public:
    stack<pair<int, int>> s;
    int i=0;
 
    int next(int price) {
       if(s.empty()){
           s.push({price, i++});
          
       }
        else{
            
            
            while(!s.empty() && s.top().first <= price ){
                s.pop();
            }
            int ans;
            
            if(s.empty()) ans = i+1;
            else{
                ans = i- s.top().second;
            }
            s.push({price, i++});
            return ans;
        }
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */