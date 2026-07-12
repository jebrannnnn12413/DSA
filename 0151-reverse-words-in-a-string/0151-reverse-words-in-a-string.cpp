class Solution {
public:
    string reverseWords(string s) {
        vector<string>str;
        string temp="";

        for(auto it:s){
            if(it!=' '){
                temp+=it;
            }
            else{
                if(temp != ""){
                    str.push_back(temp);
                    temp="";
                }
            }
        }

        if(temp!=""){
            str.push_back(temp); 
        }

        string ans="";

        for(int i=str.size()-1;i>=0;i--){
            ans+=str[i];

            if(i != 0){
                ans+=" ";
            }
        }
        return ans;
        
    }
};