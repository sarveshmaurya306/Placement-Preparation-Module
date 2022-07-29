class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanVal;
        romanVal['I']=1;
        romanVal['V']=5;
        romanVal['X']=10;
        romanVal['L']=50;
        romanVal['C']=100;
        romanVal['D']=500;
        romanVal['M']=1000;
        
        int ans=romanVal[s[s.size()-1]];
        
        for(int i=s.size()-2; i>=0; i--){
            int cur= romanVal[s[i]], next= romanVal[s[i+1]];
            if(cur<next) ans-=cur;
            else ans+=cur;
        }
        
        return ans;        
    }
};