#include"iostream"
#include"string"
#include"vector"
#include"fstream"

using namespace std;

#define P_MAX 1009
int dfs_ans;

int cnt=1;

void dfs(int cur_time,vector<int>p_num){



    int v_max=0;
    for(int i=0;i<p_num.size();i++){
        //printf("p_num[%d]=%d\n",i,p_num[i]);
        if(p_num[i]>0)v_max=i;
    }
    //printf("cur time %d,v max%d,p_num.size=%d\n",cur_time,v_max,p_num.size());

    if(cur_time+v_max<dfs_ans){
        dfs_ans=cur_time+v_max;
    }
    if(v_max<=1){
        return ;
    }
    vector<int>pv1(p_num.begin(),p_num.end());
    vector<int>pv2;
    int half_val=v_max/2+(v_max&1);
    pv1[half_val]+=p_num[v_max]*2;
    pv1[v_max]=0;
    dfs(cur_time+p_num[v_max],pv1);

    for(int i=0;i<p_num.size()-1;i++){
        if(i==0){
            pv2.push_back(p_num[0]+p_num[1]);
        }else {
            pv2.push_back(p_num[i+1]);
        }
    }
    pv2.push_back(0);

    dfs(cur_time+1,pv2);

}
int main(){


    //freopen("d:B.txt","r",stdin);
    //freopen("d:B_out.txt","w",stdout);



    int T;
    cin>>T;
    int casenum=0;

    int P[P_MAX];
    int p_num[P_MAX];//there are p_num[i] people have i pancake(s).

    while(casenum++<T){

        int D;
        int Pi;
        cin>>D;
        //init:
        memset(p_num,0,sizeof(int)*P_MAX);




        int p_max=0;
        int ans_min=0;

        for(int i=0;i<D;i++){
            cin>>P[i];
            p_num[P[i]]++;

            if(P[i]>p_max){
                p_max=P[i];
            }
        }
        ans_min=p_max;
        dfs_ans=p_max;

        vector<int> pvec(p_num,p_num+p_max+1);
        //dfs(0,pvec);


        int cur_max=p_max;

        int cur_time=0;

        while(1){
            int half_val=cur_max/2+(cur_max&1);
            if(half_val+p_num[cur_max]>=cur_max){break;}

            cur_time+=p_num[cur_max];
            p_num[half_val]+=2*p_num[cur_max];

            while(p_num[--cur_max]<=0&&cur_max>=0);

            if(cur_max+cur_time<ans_min){
                    //printf("cur time %d, cur max =%d\n",cur_time,cur_max);
                    ans_min=cur_max+cur_time;}
        }

        printf("Case #%d: %d,%d,%d\n",casenum,ans_min,dfs_ans,dfs_ans==ans_min);
    }

return 0;}
