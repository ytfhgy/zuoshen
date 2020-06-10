#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::map;
using std::sort;

struct Job
{
    int hard;
    int money;
};

bool comp(Job a,Job b)
{
    if(a.hard<b.hard)
        return true;
    if(a.hard==b.hard&&a.money>=b.money)
        return true;

    return false;
}

class Solution
{
public:
    int search(vector<int> &arr,int target)
    {
        int left=0;
        int right=arr.size()-1;
        int index=-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]>target)
            {
                right=mid-1;
            }else if(arr[mid]<=target)
            {
                index=mid;
                left=mid+1;
            }
        }

        return index;
    }

    vector<int> chooseWord(Job *job,vector<int> &ability,int N)
    {
        //对job进行排序:hard 从小--->大
        //如果hard相等,money 从大到小
        sort(job,job+N,comp);
        map<int,int> myMap;

        Job pre=job[0];
        myMap[pre.hard]=pre.money;
        vector<int> res(ability.size(),0);
        vector<int> arr;
        arr.push_back(pre.hard);
        
        //这个循环是用来进行hars相等，我只要钱数大的
        //hard不相等，我也只要钱数最大的
        for(int i=1;i<N;++i)
        {
            if(job[i].hard!=pre.hard&&job[i].money>pre.money)
            {
                pre=job[i];
                myMap[pre.hard]=pre.money;
                arr.push_back(pre.hard);
            }
        }

        for(int i=0;i<ability.size();++i)
        {
            int ret=search(arr,ability[i]);//这个函数用来进行查找我的最大钱数对应的hard坐标
            res[i]=ret!=-1?myMap[arr[ret]]:0;
        }

        return res;
    }
};

int main()
{
    Solution solut;

    vector<int> ability(9,0);
    int abilityArr[9]={1,2,3,4,5,6,7,8,9};
    int arr[14][2]={{5,10},{1,7},{2,5},{1,3},{4,5},{4,12},
        {5,9},{2,5},{4,7},{2,7},{5,10},{3,4},{1,9},
        {3,10}};

    Job *job=new Job[14];

    for(int i=0;i<14;++i)
    {
        job[i].hard=arr[i][0];
        job[i].money=arr[i][1];
    }

    for(int i=0;i<9;++i)
    {
        ability[i]=abilityArr[i];
    }

    vector<int> res=solut.chooseWord(job,ability,14);
    for(auto it:res)
        cout<<it<<" ";
    cout<<endl;

    delete [] job;

    return 0;
}
