#include <iostream>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const char* input, int lineNum){
    int i=0;
    while(input[i] != '\0'){
        if(input[i]<'0' || input[i]>'9'){
            cout<<"FAILURE => WRONG INPUT (LINE "<<lineNum<<")"<<endl;
            return false;
        }
        i++;
    }
    return true;
}
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string buffer;
    if(getline (std::cin, buffer)){
        //check if input is valid
        if(!isValid(buffer.c_str(), 1)){
            return 1;
        }
        int lineNum = atoi(buffer.c_str());
        int count = 1;
        while(getline (std::cin, buffer)){
            //first check line number
            if(count > lineNum){
                cout<<"FAILURE => WRONG INPUT (LINE "<<count+1<<")"<<endl;
                count++;
                continue;
            }
            //check input
            vector<int> result;
            string token = "";
            bool needToSkip = false;
            for(int i=0; i<buffer.size(); i++){
                if(buffer[i] != ' '){
                    token.push_back(buffer[i]);
                    if(i==buffer.size()-1){
                        if(isValid(token.c_str(), count+1)){
                            int id = atoi(token.c_str());
                            if(id >= 1){
                                result.push_back(id);
                                token = "";
                            }else{
                                cout<<"FAILURE => WRONG INPUT (LINE "<<lineNum<<")"<<endl;
                                needToSkip = true;
                                break;
                            }
                        }else{
                            needToSkip = true;
                            break;
                        }
                    }
                }else{
                    if(isValid(token.c_str(), count+1)){
                        int id = atoi(token.c_str());
                        if(id >= 1){
                            result.push_back(id);
                            token = "";
                        }else{
                            cout<<"FAILURE => WRONG INPUT (LINE "<<lineNum<<")"<<endl;
                            needToSkip = true;
                            break;
                        }
                    }else{
                        needToSkip = true;
                        break;
                    }
                }
            }
            if(needToSkip){
                count++;
                continue;
            }
            //valid result
            sort(result.begin(), result.end());
            if(result[result.size()-1] == result.size()){
                cout<<"SUCCESS => RECEIVED: "<<result.size()<<endl;
            }else{
                cout<<"FAILURE => RECEIVED: "<<result.size()<<", expected: "<<result[result.size()-1]<<endl;
            }
            count++;
        }
    }
    
return 0;
}