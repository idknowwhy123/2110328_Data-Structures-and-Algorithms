#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::vector<std::vector<std::queue<int>>> b;

    while(!a.empty()){

        std::vector<std::queue<int>> v;

        auto tmp = a.top();a.pop();

        for(auto &x : tmp){

            std::queue<int> q;

            while(!x.empty()){

                auto tmpq = x.front();x.pop();

                if(tmpq == from)q.push(to);

                else q.push(tmpq);

            }

            v.push_back(q);

        }

        b.push_back(v);

    }

    for(auto it = b.end()-1; it >= b.begin() ; it--){

        a.push(*it);

    }
    
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    std::map<string, std::pair<std::priority_queue<int>, int>> mp;

    for(auto &x : a){

        std::priority_queue<int> pq;

        while(!x.second.first.empty()){

            int tmp = x.second.first.top();x.second.first.pop();

            if(tmp == from)pq.push(to);

            else pq.push(tmp);

        }

        int tmp = x.second.second;

        if(tmp == from)tmp = to;

        mp[x.first] = {pq, tmp};

    }

    a = mp;
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> s;

    for(auto &x : a){

        std::list<int> lst;

        for(auto &y : x.first){

            int tmp = y;

            if(tmp == from)tmp = to;

            lst.push_back(tmp);

        }

        std::map<int,std::pair<int,string>> mp;

        for(auto &z : x.second){

            int tmp1 = z.first,tmp2 = z.second.first;

            if(tmp1 == from)tmp1 = to;

            if(tmp2 == from)tmp2 = to;

            mp[tmp1] = {tmp2 , z.second.second};

        }

        s.insert({lst, mp});

    }

    a = s;

}

#endif
