//! on gfg


class Solution {
    public:
    bool static comp(Job& a, Job &b){
        return a.profit> b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n){ 
        sort(arr, arr+n, comp);
        int lastDeadLine=0;
        for(int i=0;i<n;i++) 
            lastDeadLine= max(lastDeadLine, arr[i].dead);
        
        vector<int> fill(lastDeadLine+1, -1);
        int cnt=0;
        int profit=0;
        
        for(int i=0;i<n;i++){
            int asLast= arr[i].dead;
            for(int j=asLast;j>=1;j--){
                if(fill[j]==-1){ //empty fill it
                    cnt++;
                    profit+= arr[i].profit;
                    fill[j]=arr[i].id;
                    break;
                }
            }
        }
        return {cnt, profit};
    } 
};
