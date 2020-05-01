#include "query.h"
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