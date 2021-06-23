# Udacity_Astar_CPP


My study and coding of A star algorithm in C++ with the help of Udacity C++ nanodegree
Pseudo code for A\*  Search is 
"""
Search( grid, initial_point, goal_point ) :
	Initialize an empty list of open nodes.
	
	Initialize a starting node with the following:
		x and y values given by initial_point.
		g = 0, where g is the cost for each move.
		h given by the heuristic function (a function of the current coordinates and the goal).
	
	Add the new node to the list of open nodes.
	
	while the list of open nodes is nonempty:
		Sort the open list by f-value
		Pop the optimal cell (called the current cell).
		Mark the cell's coordinates in the grid as part of the path.
		if the current cell is the goal cell:
			return the grid.
		else, expand the search to the current node's neighbors. This includes the following steps:
			Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
			If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
			Mark the cell as closed.
	
	If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.

#### Commit 6:
Addition of compare function to compare nodes. The function combines goal and heuristic values to compare nodes in open list. This comparison is used to decide which node should be expanded next.

#### Commit 5:
Addition of first node (start state) to AddToOpen list for beginning the operation of A\* search.

#### Commit 4:
Addition of function AddToOpen. This function will add new nodes to open list for traversing. A node has x, y co ordinates, a goal value g and heuristic function value h. 

#### Commit 3:    
Updation in README file for previous commit.


#### Commit 2:    
Addition of heuristic functionality for calculation of h value between node and Goal. A simple  Manhattan distance calculation is used.  
If (x1, y1) are current node coordinates and (x2, y2) are Goal node coordinates then,  
	<p align="center">|x2 - x1| + |y2 - y1|</p>


#### Commit 1:  
Addition of Search method with proper input and output parameters.
