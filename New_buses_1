#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    //q.stops.clear();
    string query;
    is >> query;
    if (query == "NEW_BUS"){
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for(auto& currStop: q.stops){
            is >> currStop;
        }
    }
    else if(query == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if( query == "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    BusesForStopResponse() = default;
    BusesForStopResponse(vector<string> bs): buses(bs){}
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if(r.buses.empty()){
        os << "No stop";
    } else {
        for(const auto& bus: r.buses)
            os << bus << " ";
    }
    return os;
}

struct StopsForBusResponse {
    StopsForBusResponse() = default;
    StopsForBusResponse(vector<pair<string, vector<string>>> sB): stopsForBuses(sB){}
    vector<pair<string, vector<string>>> stopsForBuses;
};

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

struct AllBusesResponse {
    AllBusesResponse() = default;
    AllBusesResponse( map<string, vector<string>> aB): allBuses(aB){}
    map<string, vector<string>> allBuses;
};

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

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        _stopsForBus[bus] = stops;
        for(const auto& stop: stops){
            _busesForStop[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        if(!_busesForStop.count(stop)){
            return BusesForStopResponse();
        } else {
            return BusesForStopResponse(_busesForStop.at(stop));
        }
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
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

    AllBusesResponse GetAllBuses() const {
        return AllBusesResponse(_stopsForBus);
    }
private:
    map<string, vector<string>> _busesForStop;
    map<string, vector<string>> _stopsForBus;
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}
