#ifndef LIPPMAN_RESPONSES_H
#define LIPPMAN_RESPONSES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct BusesForStopResponse {
    BusesForStopResponse() = default;
    BusesForStopResponse(vector<string> bs): buses(bs){}
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    StopsForBusResponse() = default;
    StopsForBusResponse(vector<pair<string, vector<string>>> sB): stopsForBuses(sB){}
    vector<pair<string, vector<string>>> stopsForBuses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    AllBusesResponse() = default;
    AllBusesResponse( map<string, vector<string>> aB): allBuses(aB){}
    map<string, vector<string>> allBuses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

#endif //LIPPMAN_RESPONSES_H
