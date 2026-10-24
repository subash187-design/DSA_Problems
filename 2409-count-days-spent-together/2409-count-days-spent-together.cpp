class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int res = 0;
        int aliceStr = 0, bobStr = 0;
        int aliceEnd = 0, bobEnd = 0;
        int alice = 0, bob = 0;
        int alice1 = 0, bob1 = 0;
        int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i = 0; i < 5; i++){
            if(i < 2){
                aliceStr = (aliceStr * 10) + (arriveAlice[i]  - '0');
                bobStr = (bobStr * 10) + (arriveBob[i] - '0');
                alice = (alice * 10) + (leaveAlice[i] - '0');
                bob = (bob * 10) + (leaveBob[i] - '0');
            }
            else if(i > 2){
                aliceEnd = (aliceEnd * 10) + (arriveAlice[i] - '0');
                bobEnd = (bobEnd * 10) + (arriveBob[i] - '0');
                alice1 = (alice1 * 10) + (leaveAlice[i] - '0');
                bob1 = (bob1 * 10) + (leaveBob[i] - '0');
            }
        }
        if(alice < bobStr)
        return 0;
        vector<int>year(366,0);
        vector<int>year1(366,0);
        int k = 0;
        for(int i = 1 ; i <= 12 ; i++){
            int x = arr[i - 1];
            for(int j = 1; j <= x ; j++){
                if(aliceStr == alice){
                    if(i == alice && j >= aliceEnd && j <= alice1){
                        year[k] = 1;
                    }
                }
                else if(i == aliceStr && j >= aliceEnd){
                    year[k] = 1;
                }
                else if(i == alice && j <= alice1){
                    year[k] = 1;
                }
                else if(i > aliceStr && i < alice){
                    year[k] = 1;
                }
                k++;
            }
        }
        k = 0;
        for(int i = 1 ; i <= 12 ; i++){
            int x = arr[i - 1];
            for(int j = 1; j <= x ; j++){
                if(bobStr == bob){
                    if(i == bob && j >= bobEnd && j <= bob1){
                        year1[k] = 1;
                    }
                }
                else if(i == bobStr && j >= bobEnd){
                    year1[k] = 1;
                }
                else if(i == bob && j <= bob1){
                    year1[k] = 1;
                }
                else if(i > bobStr && i < bob){
                    year1[k] = 1;
                }
                k++;
            }
        }
        for(int i = 0; i < 365; i++){
            if(year[i] && year1[i])
            res++;
        }
        return res;
    }
};