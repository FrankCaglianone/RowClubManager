# RowClubManager ![C++](https://img.shields.io/badge/-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white) 

A set of structures and functions intended to be used to manage boats and excursions in a rowing club. The club has a number of boats and a number of members who join the club to participate in excursions. Each excursion must be recorded, so that the system can keep track of which boats are in use at any given time. The system also keeps track of the number of excursions and the total number of kilometers traveled by each member of the club. 


## Project Purpose 🎯 
This project is made to manage boats and excursions in a rowing club. It was part of the Systems Programming exam at USI: Università della Svizzera italiana - Lugano, teached by professor Dr. Antonio Carzaniga.


## Requirements 📋
Make sure to have a C/C++ compiler installed.


## Project Structure 🏗️  
* create_club() creates a club. Return a valid pointer to a new, empty club. Return the null pointer if memory is exhausted and therefore the creation of a new club object fails.
* destroy_club(c) destroys the given club object and releases all its allocated resources.
* add_boat(c,name,max_crew) adds a boat with the given name and maximum crew size to club c. Within a club, boats are uniquely identified by name. A boat with a maximum crew of four can take between one and four persons on an excursion. Return 1 on success. Return 0 on error or if resources are exhausted. It is an error to add two boats with the same name in the same club. It is also an error to have a maximum crew size less than 1.
* add_person(c,name) adds a person to club c. Persons are also identified uniquely by name within a club. It is therefore an error to add two persons with the same name in the same club. Return 1 on success or 0 on error.
* create_excursion(c) create an excursion object to prepare an excursion within club c. Return a valid pointer to a new excursion object. Return the null pointer if memory is exhausted and therefore the creation of a new excursion object fails.
* use_boat(e,name) assigns the named boat to the excursion e. Return 1 on success. In this case, the boat remains assigned to the excursion until the excursion is closed or canceled. Return 0 if the boat does not exist or is not available because it is currently assigned to another excursion.
* add_crew(e,name) assigns the named person as a crew member for the excursion e. Return 1 on success. In this case, the person is assigned and remains assigned to the given excursion until that excursion is canceled or closed. Return 0 if the excursion does not yet have an assigned boat, or if the maximum crew capacity of the boat has already been reached, or if the named person does not belong to the club, or if the named person has already been added to the crew of another excursion.
* close_excursion(e,k) confirms that the given excursion has ended successfully with the given distance k traveled (in kilometers). The excursion object e is also destroyed and all its allocated resources are properly released. Return 1 on success. Return 0 when the given excursion has not been set up properly, with a valid boat and a crew of at least one person. In this case, the excursion object remains valid.
* cancel_excursion(e) the given excursion is canceled. The excursion object e is properly de- stroyed; all its allocated resources are released.
* get_crew_excursions(c,name) return the number of excursions made by the given member of the club. Return −1 in case of error, for example if the given person does not belong to the club.
* get_crew_kilometers(c,name) return the total number of kilometers traveled in completed ex- cursions made by the given member of club c. Return −1 in case of error, for example if the given person does not belong to the club.
* boat_available(c,name) return 1 if the boat is available, or 0 if it is not available. Return −1 in case of error, if the given named boat does not exist in club c.
* get_boat_excursions(c,name) return the number of excursions made with the given boat of club c. Return −1 in case of error, if club c does not have the given boat.
* get_boat_kilometers(c,name) return the number of kilometers traveled with the given boat of club c. Return −1 in case of error, if club c does not have the given boat.




## Usage 🛠️ 






## License 📄
[MIT License](LICENSE)

## Credits 💳


