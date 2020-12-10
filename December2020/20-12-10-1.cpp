class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(int bill : bills){
            if(bill!=5){
                if(bill==10){
                    if(five>0){
                        five--;
                        ten++;
                    }else{
                        return false;
                    }
                } else{
                    if(ten>0&&five>0){
                        ten--;
                        five--;
                        twenty++;
                    }else if(five>2){
                        five-=3;
                        twenty++;
                    }else{
                        return false;
                    }
                }
            }else{
                five++;
            }
            cout<<five<<" "<<ten<<" "<<twenty<<endl;
        }
        return true;
    }
};