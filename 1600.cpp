#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;


class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        m_kingname = kingName;
    }
    
    void birth(string parentName, string childName) {
        auto m_it = m_mapParentToChild.find(parentName);
        if(m_it == m_mapParentToChild.end())
        {
            vector<string> m_vecTemp;
            m_vecTemp.push_back(childName);
            m_mapParentToChild.insert(make_pair(parentName,m_vecTemp));
        }else
        {
            m_it->second.push_back(childName);
        }
    }
    
    void death(string name) {
        m_setDeath.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        return getInheritanceOrder(m_kingname);
    }

    vector<string> getInheritanceOrder(string name)
    {
        vector<string> m_Vname;
        if(m_setDeath.find(name) == m_setDeath.end())
            m_Vname.push_back(name);

        auto m_it = m_mapParentToChild.find(name);
        if(m_it == m_mapParentToChild.end())
        {
            return m_Vname;
        }else
        {
            vector<string> m_vecTemp = m_it->second;
            for(auto it : m_vecTemp)
            {
                vector<string> Temp = getInheritanceOrder(it);
                for(auto it : Temp)
                {
                    if(m_setDeath.find(it) == m_setDeath.end())
                        m_Vname.push_back(it);
                }
            }
        }
        return m_Vname;
    }

    unordered_map<string,vector<string>> m_mapParentToChild;
    unordered_set<string> m_setDeath;
    string m_kingname;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */