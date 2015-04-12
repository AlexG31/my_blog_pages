#include"iostream"
#include"string"
#include"vector"
#include"fstream"



using namespace std;

int product(char a,int sa,char b,int sb,char &res,int &sr){
    if(a=='i'){
        if(b=='1'){res=a;sr=sa*sb;return 1;}
        if(b=='i'){res='1';sr=-sa*sb;return 1;}
        if(b=='j'){res='k';sr=sa*sb;return 1;}
        if(b=='k'){res='j';sr=-sa*sb;return 1;}
    }
    if(a=='1'){
        res=b;
        sr=sa*sb;
        return 1;
    }
    if(a=='j'){
        if(b=='1'){res=a;sr=sa*sb;return 1;}
        if(b=='i'){res='k';sr=-sa*sb;return 1;}
        if(b=='j'){res='1';sr=-sa*sb;return 1;}
        if(b=='k'){res='i';sr=sa*sb;return 1;}
    }
    if(a=='k'){
        if(b=='1'){res=a;sr=sa*sb;return 1;}
        if(b=='i'){res='j';sr=sa*sb;return 1;}
        if(b=='j'){res='i';sr=-sa*sb;return 1;}
        if(b=='k'){res='1';sr=-sa*sb;return 1;}
    }
    return -1;

}
int divide_ijk(char a,int sa,char b,int sb,char &res,int &sr){
    // a/b
    char prd_char=0;
    int prd_sign=1;

    res='1';
    sr=1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}
    res='1';
    sr=-1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}


    res='i';
    sr=1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}
    res='i';
    sr=-1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}



    res='j';
    sr=1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}
    res='j';
    sr=-1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}



    res='k';
    sr=1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}
    res='k';
    sr=-1;
    product(b,sb,res,sr,prd_char,prd_sign);
    if(a==prd_char&&sa==prd_sign){return 1;}

    return 0;
}
int main(){

    //freopen("e:C-large.in","r",stdin);
    //freopen("d:outputC_15.txt","w",stdout);

    fstream finput("e:C-large.in",fstream::in);

    int T;
    finput>>T;

    int casenum=0;
    while(casenum++<T){

        int L;
        long long X;
        finput>>L>>X;
        //scanf("%d%lld",&L,&X);

//
//        if(X>15LL){
//            X=15LL+(X-15LL)%4LL;
//        }

        cout<<"X="<<X<<endl;

        string Lstr("");
        string str_temp;
        finput>>str_temp;

        printf("case %d  str.size()=%d\n",casenum,str_temp.size());

        //cout<<"str_temp="<<str_temp<<endl;

        //for(int i=0;i<(int)X;i++){Lstr+=str_temp;}
        //L*=(int)X;
        cout<<"L="<<L<<endl;
        //cout<<Lstr.size()/L<<endl;

        continue;
        if(L!=Lstr.size())return -1;

        string head,tail;
        vector<int> head_sign,tail_sign;


        head.push_back(Lstr[0]);
        head_sign.push_back(1);
        for(int i=1;i<Lstr.size();i++){
            char res=0;
            int ts=1;
            product(head[i-1],head_sign[i-1],Lstr[i],1,res,ts);
            head.push_back(res);
            head_sign.push_back(ts);
        }


        tail.push_back(head[L-1]);
        tail_sign.push_back(head_sign[L-1]);

        for(int i=1;i<L;i++){
            char res=0;
            int ts=1;
            divide_ijk(tail[i-1],tail_sign[i-1],Lstr[i-1],1,res,ts);
            tail.push_back(res);
            tail_sign.push_back(ts);
        }

        bool ok=false;

        for(int i=0;i<L-2;i++){
            //choose i
            if(head[i]=='i'&&head_sign[i]==1){
                //choose j:
                //printf("i=%d\n",i);

                char cur_res='1';
                int cur_sign=1;

                for(int j=i+1;j<L-1;j++){

                    product(cur_res,cur_sign,Lstr[j],1,cur_res,cur_sign);

                    if(cur_res=='j'&&cur_sign==1){
                        //find k
                        //cout<<"K"<<endl;
                        //printf("j=%d\n",j);

                        if(tail[j+1]=='k'&&tail_sign[j+1]==1){
                            ok=true;
                            break;
                        }
                    }
                }

            }
            //printf("i=%d\n",i);
            if(ok==true)break;
        }


        printf("Case #%d: %s\n",casenum,ok?"YES":"NO");
    }

finput.close();

return 0;}
