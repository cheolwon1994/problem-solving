class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char c: str){
            if(c=='(' || c=='{' || c=='[') s.push(c);
            else {
                if(s.empty()) return false;
                if(c==')' && s.top()!='(') return false;
                else if(c=='}' && s.top()!='{') return false;
                else if(c==']' && s.top()!='[') return false;
                s.pop();
            }
        }
        return s.empty();
    }
};
