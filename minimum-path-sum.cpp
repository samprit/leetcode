class Solution {
public:
	map< pair<int, int> , int> memoize;
    int minPathSum(vector<vector<int> > &grid) {
        return algo(grid,0,0);
    }

    int algo(vector<vector<int> > &arr,int x, int y){

        int N = arr.size();
        int M = arr[0].size();
    	if( memoize.find(make_pair(x,y)) != memoize.end()){
    		return memoize[make_pair(x,y)];
    	}else{
    		int ret = arr[x][y];
    		if(x ==N-1 && y==M-1){
    
    		}else if(x==N-1){
    			ret += algo(arr,x,y+1);
    		}else if(y==M-1){
    			ret += algo(arr,x+1,y);
    		}else{
    			ret += min (algo(arr,x,y+1), algo(arr,x+1,y) );
    		}
    		memoize[make_pair(x,y)] = ret;
    		return ret;
    	}
    }
};
