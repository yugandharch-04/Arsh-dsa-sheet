class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
       vector<int>v;
       int sum=0;
       int sum2=0;
       int ans=0;
       for(int i=0; i<n; i++){
           
          sum+=(p[i].petrol-p[i].distance);
          sum2+=(p[i].petrol-p[i].distance);
          
          if(sum<0){
              sum=0;
              ans=i+1;
          }
       }
       
       if(sum2<0)
       return -1;
       
       return ans;
    }
};