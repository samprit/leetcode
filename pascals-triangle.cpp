class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        int i,j;
        vector< vector<int> > ans;
        vector<int> temp;
        for(i=0;i<numRows;i++){
            temp.clear();
            if(i==0){
                temp.push_back(1);
            }else{
                for(j=0;j<=i;j++){
                    temp.push_back(combi(i,j));
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    int combi(int n, int k){
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        int result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
};