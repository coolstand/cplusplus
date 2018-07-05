#include <string>
#include <iostream>
#include "util/lexical_cast.h"
#include "ext/hash_map"

using namespace std;
using namespace platform::util;
using namespace __gnu_cxx;

vector<int> TwoNumSum(std::vector<int>& vecNums, int nTarget)
{
    vector<int> vecOut;
    hash_map<int,int> mapTemp;
    for (unsigned int i = 0; i < vecNums.size(); i++)
    {   
        mapTemp[i] = vecNums[i];
        int value = nTarget - vecNums[i];
        hash_map<int,int>::const_iterator it = mapTemp.begin();
        for (; it != mapTemp.end(); it++)
        {   
            if (it->second == value)
            {   
                vecOut.push_back(it->first);
                vecOut.push_back(i);
            }   
        }   
    }   

    return vecOut;
}


int main(int argc, char** argv)
{
    vector<int> vecIn;
    vector<int> vecOut;
    vecIn.push_back(2);
    vecIn.push_back(7);
    vecIn.push_back(11);
    vecIn.push_back(15);
    if (argc < 2)
    {
        return -1;
    }

    vecOut = TwoNumSum(vecIn, lexical_cast<int>(argv[1]));

    printf("getout size:%d\n", (int)vecOut.size());
    for (unsigned int i = 0; i < vecOut.size(); i++)
    {
        printf("value:%d\n",vecOut[i]);
    }

    return 0;
}
