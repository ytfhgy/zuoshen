#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unordered_map;

class LRUcache
{
public:
    LRUcache(int capacity)
    :_capacity(capacity)
    {}

    void put(string &key,int value)
    {
        auto it=_hashList.find(key);
        if(it==_hashList.end())//链表中没有该结点，则进行插入该结点
        {
            //先查看容量是否达到最大值
            if(_node.size()==_capacity)//list已经满了，则先进入删除再插入
            {
                string k=_node.back()._key;
                _node.pop_back();
                _hashList.erase(k);
            }

            //在链表头部加入
            _node.push_front(Cache(key,value));
            _hashList[key]=_node.begin();
        }else//链表中已经有该结点，则进行更新该结点
        {
            it->second->_value=value;//更新下key对应的value
            _node.splice(_node.begin(),_node,it->second);
            _hashList[key]=_node.begin();
        }
    }

    int get(string &key)
    {
        auto it=_hashList.find(key);
        if(it!=_hashList.end())//存在着key
        {
            int value=it->second->_value;
            _node.splice(_node.begin(),_node,it->second);
            _hashList[key]=_node.begin();
            return value;
        }else//不存在
        {
            return -1;
        }
    }

private:
    struct Cache{
        Cache(string key,int value)
        {
            _key=key;
            _value=value;
        }

        string _key;
        int _value;
    };
private:
    int _capacity;
    list<Cache> _node;//双向链表
    unordered_map<string,list<Cache>::iterator> _hashList;//哈希表
};

int main()
{
    LRUcache cache(3);
    string s1="A";
    string s2="B";
    string s3="C";

    cache.put(s1,1);
    cache.put(s2,2);
    cache.put(s3,3);

    cout<<cache.get(s2)<<endl;
    cout<<cache.get(s1)<<endl;

    string s4="D";
    cache.put(s4,4);

    cout<<cache.get(s4)<<endl;
    cout<<cache.get(s3)<<endl;

    return 0;
}

