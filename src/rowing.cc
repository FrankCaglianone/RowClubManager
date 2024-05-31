//
//  main.cpp
//  rowing
//
//  Created by Francesco Caglianone on 13/09/23.
//

#include <iostream>
#include "rowing.h"
#include <vector>
#include <map>

using namespace std;



struct boat {
    unsigned int max_crew_members;
    int actual_members;
    bool is_available;
    int n_excursions;
    int n_kilometers;
};


struct member {
    int n_excursions;
    bool is_available;
    int n_kilometers;
};




struct club {
    int n_boats;
    int n_members;
    map<string, boat> Boats;
    map<string, member> Members;
};


struct excursion {
    struct club * club;
    bool has_boat;
    string boat;
    vector<string> Crew_members;
};


struct club * create_club () {
    struct club * ptr = new club();
    map<string, boat> Boats;
    map<string, member> Members;
    ptr->Boats = Boats;
    ptr->Members = Members;
    ptr->n_boats = 0;
    ptr->n_members = 0;
    return ptr;
}


void destroy_club (struct club * c) {
    delete c;
}




int add_boat (struct club * c, const char * name, unsigned int max_crew) {
    if( (max_crew < 1) || c->Boats.find(name) != c->Boats.end() || (c->Boats.size() == c->Boats.max_size()) )  {
        return 0;
    }
    struct boat tmp;
    tmp.actual_members = 0;
    tmp.is_available = true;
    tmp.n_excursions = 0;
    tmp.n_kilometers = 0;
    tmp.max_crew_members = max_crew;
    
    c->Boats.insert(make_pair(name, tmp));
    c->n_boats++;
    return 1;
}

int add_person (struct club * c, const char * name) {
    if( (c->Members.size() == c->Members.max_size()) || c->Members.find(name) != c->Members.end()) {
        return 0;
    }
    struct member tmp;
    tmp.is_available = true;
    tmp.n_excursions = 0;
    tmp.n_kilometers = 0;
    
    c->Members.insert(make_pair(name, tmp));
    c->n_members++;
    return 1;
}










struct excursion * create_excursion (struct club * c) {
    struct excursion * ptr = new excursion();
    vector<string> Crew_members;
    ptr->club = c;
    ptr->has_boat = false;
    ptr->Crew_members = Crew_members;
    return ptr;
}


int use_boat (struct excursion * ex, const char * name) {
    if(ex->club->Boats.find(name) == ex->club->Boats.end() || (ex->club->Boats[name].is_available == false) || (ex->has_boat == true)) {
        return 0;
    }
    ex->club->Boats[name].is_available = false;
    ex->boat = name;
    ex->has_boat = true;
    return 1;
}


int add_crew (struct excursion * ex, const char * name){
    string str = ex->boat;
    int max_crew = ex->club->Boats[str].max_crew_members;
    int actual_crew = ex->club->Boats[str].actual_members;

    if( (ex->has_boat == false) || (actual_crew >= max_crew) || (ex->club->Members.find(name) == ex->club->Members.end()) || ex->club->Members[name].is_available == false) {
        return 0;
    }
    ex->club->Members[name].is_available = false;
    ex->club->Boats[str].actual_members++;
    ex->Crew_members.push_back(name);
    return 1;
}



int close_excursion (struct excursion * ex, unsigned int kilometers) {
    if( (ex->Crew_members.empty()) ||  (ex->has_boat == false) ) {
        return 0;
    }
    
    ex->club->Boats[ex->boat].actual_members = 0;
    ex->club->Boats[ex->boat].is_available = true;
    ex->club->Boats[ex->boat].n_excursions++;
    ex->club->Boats[ex->boat].n_kilometers += kilometers;
    
    for(auto & x : ex->Crew_members) {
        ex->club->Members[x].is_available = true;
        ex->club->Members[x].n_excursions++;
        ex->club->Members[x].n_kilometers += kilometers;
    }
    
    delete ex;
    return 1;
}


void cancel_excursion (struct excursion * ex) {
    ex->club->Boats[ex->boat].actual_members = 0;
    ex->club->Boats[ex->boat].is_available = true;
    
    for(auto & x : ex->Crew_members) {
        ex->club->Members[x].is_available = true;
    }
    delete ex;
}



int get_crew_excursions (struct club * c, const char * name) {
    string str = name;
    if(c->Members.find(name) == c->Members.end() || str.empty()) {
        return -1;
    }
    return c->Members[name].n_excursions;
}

int get_crew_kilometers (struct club * c, const char * name) {
    if(c->Members.find(name) == c->Members.end()) {
        return -1;
    }
    return c->Members[name].n_kilometers;
}


int boat_available (struct club * c, const char * name) {
    if(c->Boats.find(name) == c->Boats.end()) {
        return -1;
    }
    if(c->Boats[name].is_available == true) {
        return 1;
    }
    return 0;
}


int get_boat_excursions (struct club * c, const char * name) {
    if(c->Boats.find(name) == c->Boats.end()) {
        return -1;
    }
    return c->Boats[name].n_excursions;
}


int get_boat_kilometers (struct club * c, const char * name) {
    if(c->Boats.find(name) == c->Boats.end()) {
        return -1;
    }
    return c->Boats[name].n_kilometers;
}





//int main() {
//    club * c = create_club();
//
//    excursion * e = create_excursion(c);
//
//    use_boat (e, "titanic");
//    get_boat_excursions (c, "titanic");
//    get_boat_kilometers (c, "titanic");
//    boat_available (c, "titanic");
//    cancel_excursion(e);
//    destroy_club(c);
//
//
//}
