#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPriority(const string& s){
    return (s.front() == '*' ||  s.front() == '/');
    //|| !count(s.begin(), s.end(), ' ')
}
int main() {
    int counter, num;
    string operation;
    cin >> num >> counter;
    vector<string> res{"", to_string(num)};
    for(;counter > 0; --counter){
        cin >> operation;
        if(isPriority(operation) && !isPriority(res.back()) && res.size() != 2){
            res.back() += ")";
            res.front() += "(";
        }
        res.push_back(operation);
        cin >> num;
        res.back() += " " + to_string(num);
    }
    cout << res.front();
    for(int i = 1; i < res.size(); ++i){
        cout << res[i] + " ";
    }
    return 0;
}
