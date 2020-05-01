#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    _stopsForBus[bus] = stops;
    for(const auto& stop: stops){
        _busesForStop[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    if(!_busesForStop.count(stop)){
        return BusesForStopResponse();
    } else {
        return BusesForStopResponse(_busesForStop.at(stop));
    }
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    if(!_stopsForBus.count(bus)){
        return StopsForBusResponse();
    } else {
        vector<pair<string, vector<string>>> res;
        for(const auto& stop: _stopsForBus.at(bus)){
            vector<string> temp;
            for(const auto& buses: _busesForStop.at(stop)){
                if(buses != bus)
                    temp.push_back(buses);
            }
            res.push_back(make_pair(stop, temp));
        }
        return StopsForBusResponse(res);
    }
}

AllBusesResponse BusManager::GetAllBuses() const {
    return AllBusesResponse(_stopsForBus);
}