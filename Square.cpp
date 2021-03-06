#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

template<typename T> vector<T> Sqr(const vector<T>& collection);
template<typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& Map);
template<typename First, typename Second> pair<First, Second> Sqr(pair<First, Second> x);
template<typename T> T Sqr(T x);

template<typename T>
T Sqr(T x){
    return x*x;
}

template<typename T>
vector<T> Sqr(const vector<T>& collection){
    vector<T> res;
    for(auto& el: collection)
        res.push_back(Sqr(el));
    return res;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& Map){
    map<Key, Value> res;
    for(auto& el: Map)
        res[el.first] = Sqr(el.second);
    return res;
}
template<typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> x){
    return make_pair(Sqr(x.first), Sqr(x.second));
}

int main(){
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
