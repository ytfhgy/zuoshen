#include <iostream>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

struct Node
{
    Node(string str)
    :info(str)
    {}
    
    Node *pNext;
    string info;
};

class Solution
{
public:
    Solution()
    :_waitPoint(1)
    {}

    void recive(int num,string &str)
    {
        if(num<1)
            return;

        Node *curNode=new Node(str);

        _headMap[num]=curNode;
        _tailMap[num]=curNode;

        if(_tailMap.find(num-1)!=_tailMap.end())
        {
            _tailMap[num-1]->pNext=curNode;
            _tailMap.erase(num-1);
            _headMap.erase(num);
        }

        if(_headMap.find(num+1)!=_headMap.end())
        {
            curNode->pNext=_headMap[num+1];
            _tailMap.erase(num);
            _headMap.erase(num+1);
        }

        if(_waitPoint==num)
            print();
    }

    void print()
    {
        Node *pCur=_headMap[_waitPoint];
        _headMap.erase(_waitPoint);

        while(pCur)
        {
            cout<<pCur->info<<" ";
            pCur=pCur->pNext;
            ++_waitPoint;
        }

        _tailMap.erase(_waitPoint-1);
        cout<<endl;
    }
public:
    unordered_map<int,Node*> _headMap;
    unordered_map<int,Node*> _tailMap;
    int _waitPoint;
};

int main()
{
    Solution solut;

    string s1="B";
    solut.recive(2,s1);

    string s2="A";
    solut.recive(1,s2);

    string s3="D";
    solut.recive(4,s3);

    string s4="E";
    solut.recive(5,s4);

    string s5="G";
    solut.recive(7,s5);

    string s6="H";
    solut.recive(8,s6);

    string s7="F";
    solut.recive(6,s7);

    string s8="C";
    solut.recive(3,s8);

    return 0;
}

