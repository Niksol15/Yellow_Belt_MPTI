#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
/*
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if(range_end - range_begin < 2)
        return;
    auto range_middle = range_begin + (range_end - range_begin)/2;
    vector<typename RandomIt::value_type> part1(range_begin, range_middle);
    vector<typename RandomIt::value_type> part2(range_middle, range_end);
    MergeSort(part1.begin(), part1.end());
    MergeSort(part2.begin(), part2.end());
    auto part1_it = part1.begin();
    auto part2_it = part2.begin();
    while(range_begin != range_end){
        if (part1_it == part1.end()){
            copy(part2_it, part2.end(), range_begin);
            range_begin = range_end;
        } else if (part2_it == part2.end()){
            copy(part1_it, part1.end(), range_begin);
            range_begin = range_end;
        } else {
            if(*part1_it < *part2_it){
                *range_begin = *part1_it;
                ++part1_it;
                ++range_begin;
            } else {
                *range_begin = *part2_it;
                ++part2_it;
                ++range_begin;
            }
        }
    }
}
*/
/*
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto range_middle = elements.begin() + elements.size() / 2;
    MergeSort(elements.begin(), range_middle);
    MergeSort(range_middle, elements.end());
    std::merge(elements.begin(), range_middle, range_middle, elements.end(), range_begin);
}*/
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it_one_third = begin(elements) + elements.size() / 3;
    auto it_two_third = it_one_third +elements.size() / 3;
    MergeSort(begin(elements), it_one_third);
    MergeSort(it_one_third, it_two_third);
    MergeSort(it_two_third, end(elements));
    std::vector<typename RandomIt::value_type> temp;
    std::merge(elements.begin(), it_one_third, it_one_third, it_two_third, back_inserter(temp));
    std::merge(temp.begin(), temp.end(), it_two_third, elements.end(), range_begin);
}
int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
