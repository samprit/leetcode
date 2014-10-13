class Solution {
public:
    string minWindow(string S, string T) {
        int left=0, right=0,i;
		int ansleft=0, ansright=S.size()+10;
		map<char, int> solution, tempSol;

		for(i=0;i<T.size();i++){
			solution[T[i]] = 0;
			tempSol[T[i]] = 0;
		}
		for(i=0;i<T.size();i++){
			solution[T[i]]++;
		}
		int count = 0;

		i=0;
		while(i<S.size() && (tempSol.find(S[i])==tempSol.end())){
			i++;
		}
		left = ansleft = i;
		for(;i<S.size();i++){
			if(tempSol.find(S[i])!=tempSol.end()){
				tempSol[S[i]]++;
				if(tempSol[S[i]] <= solution[S[i]]){
					count++;
				}
			}
			if(count==T.size()){
				break;
			}
		}
		if(i==S.size()){
			return "";
		}
		right = ansright= i;
		if(T.size()==1){
			return S.substr(ansleft,ansright-ansleft+1);
		}

		right++;

		while(left<right){
			if(tempSol.find(S[left])!=tempSol.end()){
				if(tempSol[S[left]]-1>=solution[S[left]]){
					tempSol[S[left]]--;
					left++;
				}else{
					break;
				}
			}else{
				left++;	
			}
		}
		ansleft=left;
		while(right<S.size()){
			
			if(solution.find(S[right])!=solution.end()){
				tempSol[S[right]]++;
				
				while(left<right){
					if(tempSol.find(S[left])!=tempSol.end()){
						if(tempSol[S[left]]-1>=solution[S[left]]){
							tempSol[S[left]]--;
							left++;
						}else{
							break;
						}
					}else{
						left++;	
					}
				}
				if(right-left < ansright-ansleft){
					ansleft = left;
					ansright = right;
				}
				right++;
			}else{	
				right++;
			}

		}
		bool flag = true;
		for(map<char, int>::iterator it = solution.begin();it!=solution.end();it++){
			if(it->second == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			return S.substr(ansleft,ansright-ansleft+1);
		}else{
			return "";
		}
    }
};
