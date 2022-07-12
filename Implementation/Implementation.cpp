#include <bits/stdc++.h>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

typedef struct
{
    
    long long int id;
    double latitude;
    double lon;
} Nodedata1;

typedef struct
{
    string name;
    long long int id;
    double latitude;
    double longitude
}Nodedata;

typedef struct
{
    vector<long long int> waynodes;
} way;
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
typedef struct
    xml_document<> doc;
    xml_node<> *root_node = NULL;

long double dist(Nodedata1 n1, Nodedata1 n2)
{
   
    double k;
    k = (n1.latitude - n2.latitude) * (n1.latitude - n2.latitude);
   
    return k;
}

long long int mindistance(unordered_map<long long int, double> distFromid, unordered_map<long long int, bool> sptset)
{
    double min_dist = INT_MAX;
    long long int min_id;
    for (auto it : distFromid)
    {
        if (sptset[it.first] == false && it.second <= min_dist)
        {
            min_dist = it.second;
            min_id = it.first;
        }
    }
    return min_id;
}
void printpath(long long int id_start, long long int id_end, unordered_map<long long int, double> distFromid ,unordered_map<long long int, long long int> Parentsrc )
{
   if( Parentsrc[id_end] == -1 )
   {
       cout<<"id_end ";
       return ;
   } 
   else 
   {
       printpath( id_start , Parentsrc[id_end] , distFromid , Parentsrc);
       cout << " -> id_end ";
   }
}
