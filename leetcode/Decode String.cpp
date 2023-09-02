class Solution {
public:
    string decodeString(string str) {
        while(true){
            stack<string> s;
            string number = "";
            int startIdx = -1, closeIdx;
            vector<string> numbers;

            for(int i=0;i<str.size();i++){
                char c = str[i];
                if(c=='['){
                    startIdx = i;
                    numbers.push_back(number);
                    number = "";
                }
                else if(c==']'){
                    closeIdx = i;
                    break;
                }
                else if('0'<=c && c<='9'){
                    number+=c;
                }
            }
            if(startIdx!=-1){
                string temp = str.substr(startIdx+1,closeIdx-startIdx-1);
                int num = stoi(numbers.back());
                string front = str.substr(0,startIdx-numbers.back().size());
                string back = str.substr(closeIdx+1);
                
                str = front;
                for(int k=0;k<num;k++)
                    str+=temp;
                str += back;
            }
            else break;
        }
        return str;
    }
};
