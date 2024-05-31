# RowClubManager ![C++](https://img.shields.io/badge/-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)

`RowClubManager` is a set of C++ structures and functions designed to manage boats and excursions at a rowing club. The club has a number of boats and a number of members who join the club to participate in excursions. Each excursion must be recorded, so that the system can keep track of which boats are in use at any given time. The system also keeps track of the number of excursions and the total number of kilometers traveled by each member of the club. 


## Project Purpose 🎯
This software was developed as part of the Systems Programming course at Università della Svizzera italiana (USI), Lugano, taught by Professor Dr. [Antonio Carzaniga](https://search.usi.ch/it/persone/cdc278cad8619ae5f51219135ee1599d/carzaniga-antonio).

## Requirements 📋
- C/C++ compiler

## Project Structure 🏗️
- `create_club()`: Initializes a new, empty club. Returns a pointer or `nullptr` on failure.
- `destroy_club(c)`: Destroys the specified club, freeing all resources.
- `add_boat(c, name, max_crew)`: Adds a boat to the club. Returns `1` on success; `0` on failure or if the boat name already exists.
- `add_person(c, name)`: Adds a person to the club. Returns `1` on success; `0` if the name already exists.
- `create_excursion(c)`: Prepares a new excursion. Returns a pointer or `nullptr` on failure.
- `use_boat(e, name)`: Assigns a boat to an excursion. Returns `1` on success; `0` otherwise.
- `add_crew(e, name)`: Adds a crew member to an excursion. Returns `1` on success; `0` if conditions fail.
- `close_excursion(e, k)`: Ends an excursion, recording the distance traveled. Returns `1` on success; `0` if setup is incomplete.
- `cancel_excursion(e)`: Cancels an excursion and frees resources.
- `get_crew_excursions(c, name)`: Returns the number of excursions by a member. Returns `-1` on error.
- `get_crew_kilometers(c, name)`: Returns the total kilometers traveled by a member. Returns `-1` on error.
- `boat_available(c, name)`: Checks boat availability. Returns `1` if available; `0` or `-1` on error.
- `get_boat_excursions(c, name)`: Returns the number of excursions using a specific boat. Returns `-1` on error.
- `get_boat_kilometers(c, name)`: Returns the distance traveled by a specific boat. Returns `-1` on error.

## Usage 🛠️


## License 📄
[MIT License](LICENSE)

## Credits 💳
Special thanks to Professor [Antonio Carzaniga](https://search.usi.ch/it/persone/cdc278cad8619ae5f51219135ee1599d/carzaniga-antonio) for his guidance in Systems Programming and for devising this engaging project.




