class Solution {
public:
    int fib(int n) {
        int mod=1e9+7;
        if(n<=1)
        return n;
        vector<int> arr(n+1);
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;++i)
        {
            arr[i]=arr[i-1]+arr[i-2];
            arr[i]%=mod;
        }
        return arr[n];
    }
};
