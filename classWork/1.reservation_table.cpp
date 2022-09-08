#include<bits/stdc++.h>
#define MAX 10
using namespace std;

set<int> find_forbidden_latency(vector<string> &reserve, int n){

    //cout<<n<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<reserve[i]<<endl;
    // }

    vector<vector<int>>matrix;

    set<int> forbid;
    for(int i=0;i<n;i++){
        vector<int>dis;
        for(int j=0;j<reserve[i].size();j++){
            for(int k=j+1;k<reserve[i].size();k++){
                if(reserve[i][j]==reserve[i][k] and reserve[i][j]=='1'){
                    dis.push_back(k-j);
                    forbid.insert(k-j);
                }
            }
        }
        matrix.push_back(dis);

    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            printf("%d ",matrix[i][j]);
        }
        cout<<endl;
    }
    return forbid;

}

set<int>find_permissible_latency(set<int>&st, int n){
    map<int,int>has;

    for(auto it: st){
        has[it]++;
    }

    set<int>ans;
    for(int i=1;i<=n;i++){
        if(has.count(i)==0) ans.insert(i);
    }
    return ans;
}



int main(){
    freopen("input.txt","r",stdin);

    int n = 3;
    vector<string>vec(MAX);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    //Task-: 1
    set<int>forbiden_latency = find_forbidden_latency(vec,n);
    printf("Forbiden latency: \n");
    for(auto it: forbiden_latency){
        printf("%d ",it);
    }
    printf("\n\n");

    //Task-:2
    int time = 8;
    set<int> permissible_latency = find_permissible_latency(forbiden_latency,time);
    printf("Permissible Latency:\n");
    for(auto it: permissible_latency){
        printf("%d ",it);
    }
    printf("\n\n");

    
    printf("Collision Vector:\n");
    vector<int>temp(time,0);
    for(auto it: permissible_latency){
        temp[it]=1;
        //cout<<it<<endl;
    }
    for(int i=1;i<=time;i++){
        printf("%d ",temp[i]);
    }
    printf("\n\n");


    //Task-4: Any New initiation and find collision point
    map<pair<int,int>,bool>already_occupy;
    queue<pair<int,int>>consecutive;

    for(int i=0;i<time;i++){
        for(int j=0;j<n;j++){
            if(vec[j][i]=='1'){
                consecutive.push({j,i});
                already_occupy[{j,i}]=true;
            }
        }
    }

    int point_x = 1, point_y=2;

    for(int k=1;k<=time;k++){
        point_x=1;
        point_y=k;

        //cin>>point_x>>point_y;

        point_y--;
        point_x--;

        bool get = true;

        queue<pair<int,int>>qq=consecutive;
        vector<pair<int,int>>store;

        for(int i=0;i<time;i++){
            auto point = consecutive.front(); consecutive.pop();
            int get_x=-1,get_y=-1;
            if(point.first+point_x<n and point.second+point_y<time){
                get_x=point.first+point_x;
                get_y=point.second+point_y;
                store.push_back({get_x,get_y});
            }
            if(get_x>-1 and get_y>-1){
                if(already_occupy.count({get_x,get_y})>0){
                    printf("Collision Found for initiation point (1,%d). Collison point: %d %d\n",point_y+1,get_x+1,get_y+1);
                    get=false;
                    i=INT_MAX;
                    break;
                }
            }
        }
        
        if(get){
            printf("No Collision Found for point(1,%d)\n",point_y+1);
            for (auto it: store){
                already_occupy[it]=true;
                qq.push(it);
            }
        }
        //break;
        consecutive=qq;
        //break;
    }
    
    


    return 0;
}