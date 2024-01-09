class Solution {
public:
    //TC=O(POW(3,N)*N)
    //SC=O(N+N)+O(M) M=STACK SPACE
    int find(int index,string& f,string& se,string& s,int n){
        if(index==n){
            bool one=true,two=true;
            int i=0,j=f.size()-1;
            while(i<=j){
                if(f[i]==f[j]){
                    i++;j--;
                }else{
                    one=false;
                    break;
                }
            }
            i=0,j=se.size()-1;
            while(i<=j){
                if(se[i]==se[j]){
                    i++;j--;
                }else{
                    two=false;
                    break;
                }
            }
          
            if(one && two){
                return f.size()*se.size();
            }
            return 1;
        }
        int first=0,second=0,not_take=0;
        f+=s[index];
        first=find(index+1,f,se,s,n);
        f.pop_back();
        se+=s[index];
        second=find(index+1,f,se,s,n);
        se.pop_back();
        not_take=find(index+1,f,se,s,n);
        return max(first,max(second,not_take));
    }
    int maxProduct(string s) {
        int n=s.size();
        string f="",se="";
        return find(0,f,se,s,n);
    }
};
