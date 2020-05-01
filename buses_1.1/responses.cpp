#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if(r.buses.empty()){
        os << "No stop";
    } else {
        for(const auto& bus: r.buses)
            os << bus << " ";
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    size_t count = 0;
    if (r.stopsForBuses.empty()){
        os << "No bus";
    } else {
        for(const auto& stop: r.stopsForBuses){
            os << "Stop " << stop.first << ": ";
            if(stop.second.empty()){
                os << "no interchange";
            } else {
                for(const auto& bs: stop.second){
                    os << bs << " ";
                }
            }
            ++count;
            if(count != r.stopsForBuses.size())
                os << endl;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    size_t count = 0;
    if(r.allBuses.empty()){
        os << "No buses";
    } else {
        for(const auto& bus: r.allBuses){
            os << "Bus " << bus.first << ": ";
            for(const auto& stop: bus.second){
                os << stop << " ";
            }
            ++count;
            if(count != r.allBuses.size())
                os << endl;
        }
    }
    return os;
}