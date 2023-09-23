class Solution {
public:
int help(vector<vector <int> > & tic, int ck){
    int maxi = -1;
        int n = tic.size();
        // bool flag = false;
        //digonal1
            int cnt = 0;
            if(tic[1][1] == ck){
                cnt = 0;
                for(int i = 0; i < tic.size(); ++i){
                    if(tic[i][i] == ck){
                        cnt++;
                    }else{
                        break;
                    }
                }

                maxi = max(maxi, cnt);

                if(cnt == 3) return 3;
            }
        //digonal2
            if(tic[1][1] == ck){
                cnt = 0;
                for(int i = n-1; i >= 0; i--){
                    if(tic[i][n-1-i] == ck){
                        cnt++;
                    }else{
                        break;
                    }
                }
                maxi = max(maxi, cnt);
                if(cnt == 3)
                    return 3;
            }
        //01
            if(tic[0][1] == ck){
                //hori
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[0][i] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;
                    

                    
                //verti
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[i][1] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;
            }

                    maxi = max(maxi, cnt);
        //10
            if(tic[1][0] == ck){
                //hori
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[1][i] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;
                // verti
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[i][0] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;

            }
        //21
         
                //hori
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[2][i] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;

                // verti
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[i][1] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;
        //12
                cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(tic[i][2] == ck){
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    maxi = max(maxi, cnt);
                    if(cnt == 3)
                        return 3;
            
        return maxi;
    }
    string tictactoe(vector<vector<int>>& moves) {
        if(moves.size() < 5) return "Pending";
        vector<vector <int> > tic(3, vector<int>(3, -1));
        // 1 for x || 2 for y
        for(int i = 0; i < moves.size(); ++i){
            int r = moves[i][0];
            int c = moves[i][1];
            if(i%2 == 0){
                tic[r][c] = 1;
            }else{
                tic[r][c] = 2;
            }
        }

       int flag1 = help(tic, 1);
       int flag2 = help(tic, 2);

       if(flag1 == 3){
           return "A";
       }
       
        if(flag2 == 3){
           return "B";
       }
        int cnt = 0;
        for(auto it : tic){
            for(auto itr:it){
                if(itr == -1){
                    cnt++;
                } 
            }
        }

        if(cnt >= 1){
            return "Pending";
        }
        // if(flag1 + flag2 < 4) return "Pending"; 
        


        return "Draw";
       

       
    }
};