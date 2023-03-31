# level-editor
In the stage editor you can create a new stage which will be playable with small adjustments by the implementation of the game. New stages can be built but only one stage will be saved to the given file. If the user wants to open an existing stage and edit it, this option also exists.
High School :
The editor is made up of three departments:
board class:
Contains the board data, including the toolbar and stage data. In addition, she is responsible for opening the file to read the step/save it.
Editor's department:
Responsible for the editing itself - inherits from the board department the board for management and takes care of printing the board. Adds the window to the user on the board.
Printing department:
Responsible for loading the required images and printing the board.
Location department:
For more convenient use in the required locations.
File list:
Images of: Delete, Save, New Page, Exit, Player, Enemy, Ladder, Coin, Wall/Floor, Rod and frame for blank parts of the board.
Noteworthy algorithms: None
Main data structures: a vector holding the board showing the current stage of editing, a vector of images and a two-dimensional vector (of a "sprite") that converts the board to images on the window.
Additional comments - none.
