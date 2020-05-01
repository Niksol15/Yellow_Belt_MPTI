
#ifndef LIPPMAN_BUS_MANAGER_H
#define LIPPMAN_BUS_MANAGER_H
#include "responses.h"
#include "query.h"

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);
    BusesForStopResponse GetBusesForStop(const string& stop) const;
    StopsForBusResponse GetStopsForBus(const string& bus) const;
    AllBusesResponse GetAllBuses() const ;
private:
    map<string, vector<string>> _busesForStop;
    map<string, vector<string>> _stopsForBus;
};

#endif //LIPPMAN_BUS_MANAGER_H
