class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        int no=0; //res
        bool neg= false;
        
        while(i<str.size() && str[i]==' '){
            i++;
        }
        if(i<str.size() && str[i]=='-'){
            neg=true;
            i++;
        } else if(i<str.size() && str[i]=='+'){
            i++;
        }
        
        while(i<str.size() && isdigit(str[i])){
            int c= str[i]-'0';
            //overflow check
            if((INT_MAX-c)/10 < no){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            no =no*10+ c;
            i++;
        }
        if(no==0) return 0;
        else{
            if(neg) return -1* no;
            else return no;
        }
    }
};