class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
         int count = 1;
        string temp = "1";
        string ans ="";
        for (int i = 0 ; i < S.size() ; i++ )
        {
            if( S[i] == 'D')
            {
                count++;
                temp = to_string(count)+temp;
            }
            else 
            {
                ans+=temp;
                count++;
                temp = to_string(count);
            }
        }
           ans+=temp;
        return ans;
    }
};
