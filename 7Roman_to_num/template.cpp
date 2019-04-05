#include <iostream>
#include<vector>
#include <string>
#include <map>
using namespace std;
/*class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        map<char,int>::iterator mapit;
        int sum = 0;
        int mapitvalue;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        for(string::iterator it=s.begin();it!=s.end();it++)
        {
            if(!((it+1)!=s.end()))
            {
                sum += mp[*it];
                break;
            }
            if(mp[*it]>=mp[*(it+1)])
            {
                sum += mp[*it];
            }
            else
            {
                mapit=mp.find(*it);
                mapitvalue = mapit->second;
                mapit=mp.find(*(it+1));
                if(mapit->second/mapitvalue == 5 || mapit->second/mapitvalue == 10)
                {
                    sum +=(mp[*(it+1)] - mp[*it]);
                    it++;
                }
                else
                {
                    sum += mp[*it];
                }
            }
        }
        return sum;
    }
};*/
class Solution {
public:
    int romanToInt(string s) {
        int end=0;
        int leng=s.size();
        int temp=0;
        int lastchar=9999;
        
        for(int i=0;i<leng;i++)
        {
            switch(s[i])
            {
                    case'M': temp =1000;break;
                    case'D': temp =500;break;
                    case'C': temp =100;break;
                    case'L': temp =50;break;
                    case'X': temp =10;break;
                    case'V': temp =5;break;
                    case'I': temp =1;break;
            }
            end+=temp;
            
            if(lastchar<temp)
            {
                end-=2*lastchar;
            }
            lastchar = temp;
    
        }
        
        return end;
    }
};

int main()
{
	Solution s;
	int a = s.romanToInt("IL");
	cout<<"ans:"<<a<<endl;
	return 0;
}