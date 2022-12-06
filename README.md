# A Walk in the Park
Final Project for Computer Science 151
 
 ## Game Description  
 Take a gentle stroll in the park as you walk through this game.
 ![Screenshot (1)](https://user-images.githubusercontent.com/102100720/206043498-d668cb4a-c0d7-457a-8f8b-b70bea4492de.png)
 
 This is meant to be a treasure hunt game with an Indiana Jones character. Pressing the arrow keys will move 
the character. When you land on a special square, you will receive a textbox which will tell you what 
happens next. That basically sums it up.


 
 ## How to play 
  Use the arrow keys to move along the grid, but watch out for the trap. 
  
  Press enter to click the button when it appears
  
  ## Other Notes:
  
  Tile system is used to get the positions of charcters along a gridsize. Map size is set at the start of the game using a default constructor. Pop up is its own class.

# CS151
Final Project for Computer Science 151

SetUp on Linux (Ubuntu) system
<!-- % open the terminal -->
<!-- % update the Ubuntu package lists -->
$sudo apt update && sudo apt dist-upgrade
% <!-- install the GNU compiler tools (gcc/g++) and the GDB debugger -->
$ sudo apt install build-essential gdb
<!-- % now install git -->
$ sudo apt install git
% <!-- install SFML libraries -->
$ sudo install libsfml-dev
<!-- % clone the repository -->
$ git clone https://github.com/Electrical-Fire/CS151 final
% <!-- got to the final directory -->
$ cd final
<!-- % compile the project -->
$ g++ -std=C++11 *.cpp -o final -lsfml-graphics -lsfml-window -lsfml-system
% run the game
$ ./final

<!-- SetUp on MacOS:
<!-- open the terminal -->
<!-- update the Ubuntu package lists -->
<!-- % install the GNU compiler tools (gcc/g++) and the GDB debugger -->
<!-- now install git -->
<!-- % install SFML libraries -->
$ sudo install homebrew
% <!-- clone the repository -->
$ git clone https://github.com/Electrical-Fire/CS151 final
<!-- % got to the final directory -->
$ cd final
% <!-- compile the project: -->
$ g++ *.cpp -o final -lsfml-graphics -lsfml-window -lsfml-system
<!-- % run the game -->
$ ./final

