class Solution {
public:

    int solve(vector<int> arr,int k)
    {
      int n = arr.size();
      int sum = 0,i = 0,j = 0;
      int ans = 0;

      while(j<n)
      {
         sum+=arr[j];

         while(sum>k)
         {
            sum-=arr[i];
            i++;
         }

         ans+=(j-i+1);
         j++;
      }

      return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        for(int i = 0;i<n;i++)
        arr[i] = (arr[i]%2) ? 1 : 0;

        return solve(arr,k)-solve(arr,k-1);
    }
};
