class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        stringstream st(s);
        string word;
        string res="";
        while(st>>word){
            reverse(word.begin(), word.end());
            res=res+word+" ";
        }
        res.pop_back();
        s=res;
        return s;
    }
};