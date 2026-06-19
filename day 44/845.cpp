class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        //time complexity: O(n)
        //space complexity: O(1)

        int ans=0;
        int n=arr.size();

        //to track length of 'increasing' part
        int up=0;
        //to track length of 'decreasing' part
        int low=0;

        //pointer variable to start from 2nd variable
        int i=1;
        while(i < n)
        {
            //resetting 'increasing' counter for each segment
            up=0;
            //resetting 'decreasing' counter for each segment
            low=0;

            //skipping equal adjacent elements(moving 'i' ahead)
            while((i < n) && (arr[i-1] == arr[i]))
                i++;

            //while strictly 'increasing'
            while((i < n) && (arr[i-1] < arr[i]))
            {
                //moving forward
                i++;
                //increasing 'uphill' count
                up++;
            }

            //while strictly 'decreasing'
            while((i < n) && (arr[i-1] > arr[i]))
            {
                //moving forward
                i++;
                //increasing downhill count
                low++;
            }

            //valid mountain only if both sides exist: updating maximum length of longest mountain
            if(up && low)
                ans=max(ans,up+low+1);
        }
        //reeturning final answer
        return ans;
    }
};
