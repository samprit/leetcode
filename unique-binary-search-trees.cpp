class Solution {
public:
    int numTrees(int n) {
        int arr[n+1];
        for(int i=0;i<=n;i++) arr[i]=0;
        arr[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                arr[i] += arr[j]*arr[i-1-j];
            }
        }
        return arr[n];
    }
};