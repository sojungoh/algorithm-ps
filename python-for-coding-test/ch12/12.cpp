#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, int>> column, girder;

bool checkColumnInstall(int x, int y) {
    bool ret_val = false;
    
    if(y == 0) {
        ret_val = true;
    }
    else if(column.find({x, y - 1}) != column.end()) {
        ret_val = true;
    }       
    else if(girder.find({x, y}) != girder.end() 
            || girder.find({x - 1, y}) != girder.end()) {
        ret_val = true;
    }
    
    return ret_val;
}

bool checkGirderInstall(int x, int y) {
    bool ret_val = false;
    
    if(column.find({x, y - 1}) != column.end() 
       || column.find({x + 1, y - 1}) != column.end()) {
        ret_val = true;    
    }
    else if(girder.find({x - 1, y}) != girder.end() 
            && girder.find({x + 1, y}) != girder.end()) {
        ret_val = true;
    }
    
    return ret_val;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame){
    vector<vector<int>> answer;
    
    for(vector<int> v : build_frame) {
        int x = v[0];
        int y = v[1];
        int isGirder = v[2];
        int isInstall = v[3];
        
        if(isInstall) {
            if(isGirder) {
                if(checkGirderInstall(x, y))
                    girder.insert({x, y});
            }
            else {
                if(checkColumnInstall(x, y))
                    column.insert({x, y});
            }
        }
        else {
            set<pair<int, int>>::iterator iter;
            
            if(isGirder) {                
                iter = girder.find({x, y});
                girder.erase(iter);
                
                if(girder.find({x - 1, y}) != girder.end()) {
                    if(!checkGirderInstall(x - 1, y)) {
                        girder.insert({x, y});
                        continue;
                    }
                }
                
                if(girder.find({x + 1, y}) != girder.end()) {
                    if(!checkGirderInstall(x + 1, y)) {
                        girder.insert({x, y});
                        continue;
                    }
                }
                
                if(column.find({x , y}) != column.end()) {
                    if(!checkColumnInstall(x, y)) {
                        girder.insert({x, y});
                        continue;
                    }
                }
                
                if(column.find({x + 1, y}) != column.end()) {
                    if(!checkColumnInstall(x + 1, y)) {
                        girder.insert({x, y});
                    }
                }
            }
            else {   
                iter = column.find({x, y});
                column.erase(iter);
                
                if(column.find({x, y - 1}) != column.end()) {
                    if(!checkColumnInstall(x, y - 1)) {
                        column.insert({x, y});
                        continue;
                    }
                }
                
                if(column.find({x, y + 1}) != column.end()) {
                    if(!checkColumnInstall(x, y + 1)) {
                        column.insert({x, y});
                        continue;
                    }
                }
                
                if(girder.find({x, y}) != girder.end()) {
                    if(!checkGirderInstall(x, y)) {
                        column.insert({x, y});
                        continue;
                    }
                }
                
                if(girder.find({x - 1, y}) != girder.end()) {
                    if(!checkGirderInstall(x - 1, y)) {
                        column.insert({x, y});
                        continue;
                    }
                }
                
                if(girder.find({x, y + 1}) != girder.end()) {
                    if(!checkGirderInstall(x, y + 1)) {
                        column.insert({x, y});
                        continue;
                    }
                }
                
                if(girder.find({x - 1, y + 1}) != girder.end()) {
                    if(!checkGirderInstall(x - 1, y + 1)) {
                        column.insert({x, y});
                    }
                }
            }
        }
    }
    
    for(pair<int, int> p : column) {
        vector<int> v;
        v.push_back(p.first);
        v.push_back(p.second);
        v.push_back(0);
        answer.push_back(v);
    }
    
    for(pair<int, int> p : girder) {
        vector<int> v;
        v.push_back(p.first);
        v.push_back(p.second);
        v.push_back(1);
        answer.push_back(v);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
