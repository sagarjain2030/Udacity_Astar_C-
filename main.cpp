#include <algorithm>  
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed, kPath};


vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Write function to compare the f-value of two nodes here
bool Compare(vector<int> node1, vector<int> node2)
{
  return node1[2] + node1[3] > node2[2] + node2[3]? true : false;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

// TODO: Write the Heuristic function here.
int Heuristic(int x1, int y1, int x2, int y2)
{
  return abs(x2 -x1) + abs(y2 - y1);
}

// TODO: Write CheckValidCell here. Check that the 
// cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
  bool bool_x = (x > 0 && grid.size() > x? true:false);
  bool bool_y = (y > 0 && grid[x].size() > y? true:false);
  if(bool_x && bool_y)
  {
    if(grid[x][y] == State::kEmpty)
      return true;
    return false;
  }
  
  return false;
}

void AddToOpen(int x, int y, int g, int h, std::vector<vector<int>>& openNodes, std::vector<vector<State>>& grid)
{
  vector<int> node = {x, y, g, h};
  openNodes.push_back(node);
  grid[x][y] = State::kClosed;
}


/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
// TODO: ExpandNeighbors(arguments) {

  // TODO: Get current node's data.

  // TODO: Loop through current node's potential neighbors.

    // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.

      // TODO: Increment g value, compute h value, and add neighbor to open list.

// } TODO: End the function

void ExpandNeighbors(const vector<int>& current, int goal[2], vector<vector<int>>& open, vector<vector<State>>& grid)
{
  for(int i = 0; i < 4; i++)
  {
    int neighbour_x = current[0] + delta[i][0];
    int neighbour_y = current[1] + delta[i][1];
    if(CheckValidCell(neighbour_x, neighbour_y, grid))
    {
      int g2 = current[2] + 1;
      int h2 = Heuristic(neighbour_x, neighbour_y, goal[0], goal[1]);
      AddToOpen(neighbour_x, neighbour_y, g2, h2, open, grid);
    }
  }
}


/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};
  
  // TODO: Initialize the starting node. 
  vector<int> firstNode = 
  {init[0], init[1], 0, Heuristic(init[0],init[1], goal[0], goal[1])};
  
  // TODO: Use AddToOpen to add the starting node to the open vector.
  AddToOpen(init[0],init[1], 0, Heuristic(init[0],init[1], goal[0], goal[1]), open, grid);

    while(open.size())
  {
    CellSort(&open);
    auto currentnode = open[0];
    grid[currentnode[0]][currentnode[1]] = State::kPath;
    if(currentnode[0] == goal[0] && currentnode[1] == goal[1])
      return grid;
  

  // TODO: while open vector is non empty {
    // TODO: Sort the open list using CellSort, and get the current node.

    // TODO: Get the x and y values from the current node,
    // and set grid[x][y] to kPath.

    // TODO: Check if you've reached the goal. If so, return grid.

    
    // If we're not done, expand search to current node's neighbors. 
	// This step will be completed in a later quiz.
     ExpandNeighbors(current, goal, open, grid);
  
  } // TODO: End while loop
  
  // We've run out of new nodes to explore and haven't found a path.

  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    default: return "0   "; 
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}


#include "test.cpp"

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
  TestAddToOpen();
  TestCompare();
  TestSearch();
  TestCheckValidCell();
  TestExpandNeighbors();
}