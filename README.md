# Initial
ENGG1340-Group 55 
1. Jeong Seungheon (3035980106)
2. Kim Dowon (3035986928)
3. Kim Minchan (3035986617)
4. Kim Yunjin (3036029545)
5. Noh Seungwoo (3035986930)

Game Name: Haunted Memories

Game description: 
In this game, the player must escape the school by finding keys in various rooms on the school map. The player will be able to explore various rooms in the school and travel around to find keys that are scattered on the floors. As time passes, the player’s view field decreases, hence they should escape as soon as possible before the player cannot look around. 

Game rules:
1. The player will have to find the two keys to escape from the school, and the key is presented as “ * ”
2. Press “F” to pick up the key
3. Press “W”, “A”, “S”, or “D” on your keyboard to move the character to your desired direction (W = up, S = down, A = left, D = right)
4. Press “I” to open or close your inventory and “M” to open/close the menu
5. During the game, the player is holding a flashlight hence, it can only look at limited boundaries instead of seeing the whole map
6. The flashlight will lose battery as time passes and the size of the visible boundary will also decrease accordingly
7. To pass a door on the map, please press forward in front of the door
8. Press “Enter” to skip pop-up messages

Features Implemented:
1. Generation of random game sets or events: The rooms of the key being spawned and the location of each key in the rooms being spawned is random. We have generated random rooms and random coordinates to choose from suitable data sets for every game set.

2. Data structures for storing game status: We have used various structures to store the game status. For example, vectors. Vector supports dynamic data structure, giving us more freedom in adding elements like character name, remaining time, etc.

3. Dynamic memory management: We have dynamically declared an int object that is used throughout the main function. Then, after the termination of the program, the memory allocated to the int variable is deleted. In such a fashion we were able to dynamically manage the memories, leading to greater memory efficiency of the game.

4. File input/output (e.g., for loading/saving game status): We have a lot of graphical text files as the game involves various visual elements. Therefore, we had to load input text files to display those visual contents. Also, our game allows users to save time playing during and after the game so that they can always see their records. During the process, the data will be saved in the output text files, which also means that it saves the game status.

5. Program codes in multiple files: MainEngine.cpp - [ Updating timer and flashlight boundary, Chatbox mechanism, Inventory mechanism, Displaying windows of maps, Character moving mechanisms, Menu page ] | MAIN.cpp - [ Displaying start page and functions such as starting the game and instructions page, Randomly spawning keys in random rooms ]

List of non-standard C/C++ libraries:
ncurses.h: programming library for creating text-based user interfaces in a terminal window
Used to create and display and delete windows of our map files

Compilation and execution instructions:
In the terminal, write the following in order:
1. make clean
2. make MAIN
3. ./MAIN
