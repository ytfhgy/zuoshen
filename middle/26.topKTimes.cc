#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;

class Solution
{
public:
    struct Node
    {
        string str;
        int times;
    };

    struct comp
    {
        bool operator()(const Node &n1,const Node &n2)
        {
            return n1.times>n2.times;//小根堆
        }
    };

    void topKTimes(vector<string> &vec,int topK)
    {
        if(vec.empty()||topK<1)
            return;

        unordered_map<string,int> strWordCount;

        //先统计词频
        for(auto it:vec)
        {
            strWordCount[it]++;
        }

        //自己定义优先级队列的结构和比较器
        //构建小根堆
        priority_queue<Node,vector<Node>,comp> myQueue;
        for(auto it:strWordCount)
        {
            Node node;
            node.str=it.first;
            node.times=it.second;;

            //如果当前队列没达到topK，则直接回到队列
            if(myQueue.size()<topK)
            {
                myQueue.push(node);
            }else 
            {
                //堆已经满了，如果当前堆顶元素词频比当前元素词频小
                //则进行弹出堆顶，当前元素进堆
                if(myQueue.top().times<node.times)
                {
                    myQueue.pop();
                    myQueue.push(node);
                }
            }
        }
        
        //再弹出堆中的topK个元素
        while(!myQueue.empty())
        {
            cout<<myQueue.top().str<<endl;
            myQueue.pop();
        }

    }
};

int main()
{
    Solution solut;
    vector<string> vec;

    vec.push_back("hello");
    vec.push_back("word");
    vec.push_back("tencent");
    vec.push_back("hello");
    vec.push_back("baidu");
    vec.push_back("baidu");
    vec.push_back("word");
    vec.push_back("tencent");
    vec.push_back("baidu");
    vec.push_back("hello");
    vec.push_back("word");
    vec.push_back("tencent");
    vec.push_back("tencent");
    vec.push_back("word");
    vec.push_back("tencent");
    vec.push_back("baidu");

    solut.topKTimes(vec,3);

    return 0;
}

