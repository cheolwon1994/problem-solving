class Solution {
public:
    int addDigits(int num) {
        while(true){
            string str = to_string(num);
            int len = str.size();
            if(len == 1) return num;

            num = 0;
            for(int i=0;i<len;i++){
                num += (str[i]-'0');
            } 
        }
        return 0;
    }
};
