#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    void process(vector<int> &pre,vector<int> &in,vector<int> &pos,int prei,int prej,int ini,int inj,int posi,int posj)
    {
        if(prei>prej)//base case
            return;

        if(prei==prej)//只剩下一个数了，直接填
        {
            pos[posi]=pre[prej];
            return;
        }

        pos[posj]=pre[prei];

        int find=ini;//这个find是一定会找到的
        while(in[find]!=pre[prei])
        {
            ++find;
        }
        
        //分别对左半部分和右半部分进行递归
        process(pre,in,pos,prei+1,prei+find-ini,ini,find-1,posi,posi+find-ini-1);
        process(pre,in,pos,prei+find-ini+1,prej,find+1,inj,posi+find-ini,posj-1);
    }

    vector<int> getPosArray(vector<int> &pre,vector<int> &in)
    {
        vector<int> pos(pre.size(),-1);
        if(pre.empty())
            return pos;

        process(pre,in,pos,0,pre.size()-1,0,in.size()-1,0,pos.size()-1);
        return pos;
    }

    void printVector(vector<int> &vec)
    {
        for(auto it:vec)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    int arrPre[7]={1,2,4,5,3,6,7};
    int arrIn[7]={4,2,5,1,6,3,7};
    vector<int> pre(7,0);
    vector<int> in(7,0);

    for(int i=0;i<7;++i)
    {
        pre[i]=arrPre[i];
        in[i]=arrIn[i];
    }

    Solution solut;

    vector<int> pos=solut.getPosArray(pre,in);

    cout<<"先序:";
    solut.printVector(pre);
    cout<<"中序:";
    solut.printVector(in);
    cout<<"后序:";
    solut.printVector(pos);

    return 0;
}

