Maze Generator and Solver
Overview
This program generates a random maze using a recursive backtracking algorithm and solves it using a depth-first search (DFS) approach with recursion. The maze is represented as a grid of walls and paths, and the program outputs the generated maze along with the solution path.

Maze Generation
The maze is generated using the recursive backtracking algorithm. Here's how it works:

We start with a grid where all cells are walls (#).

We pick a random starting cell and mark it as a path ( ).

Then, we recursively carve out paths by choosing random directions (up, down, left, right) and ensuring that we don't carve paths that result in cycles.

We stop the recursive process once all reachable cells have been visited.

The maze generation algorithm guarantees that there is always a path from the start point to the exit point.

Key Steps:
Initialize the grid: A 2D grid is created with all cells marked as walls.

Randomly shuffle directions: The possible directions are shuffled to ensure randomness.

Carve paths recursively: Starting from the initial position, paths are carved recursively by checking all possible directions.

Ensure solvability: The maze is always solvable because the backtracking algorithm ensures that the starting and exit points are connected.

Pathfinding Algorithm
The program uses a recursive depth-first search (DFS) to find the path from the start point to the exit. Here's how the pathfinding works:

The algorithm starts at the entrance of the maze (top-left corner).

It recursively explores each possible direction (up, down, left, right) from the current cell.

If a direction leads to an open path ( ), the algorithm moves to that cell.

If it encounters a dead-end or a wall (#), it backtracks and tries another direction.

The algorithm continues until the exit point is reached, marking the visited path with a special symbol (.).

If no path exists, the algorithm returns a message indicating that no solution was found.

Key Steps:
Start at the entrance: The algorithm begins at the starting point.

Recursive exploration: It explores adjacent cells in all four possible directions.

Backtracking: If a dead end is reached, the algorithm backtracks and tries another direction.

End when the exit is found: If the exit is reached, the algorithm marks the path.


Sample output 
generated maze:
#####################
#     #       # #   #
##### ### ### # # # #
#   #     # # #   # #
# # ####### # ##### #
# #   #       #     #
# ### # ####### #####
# #   # #     #     #
# ##### # # # # ### #
#     # # # # #   # #
##### # # # # ##### #
#     # # # #       #
# ### # # # ####### #
#   # # # # #     # #
# # ### # # # # ### #
# #   # # # # # #   #
# ### # # # ### # ###
#   # # # #   # # # #
### # # ##### # # # #
#   #         #     #
#####################



Solved maze:
#####################
#.....#  .....# #   #
#####.###.###.# # # #
#   #.....# #.#   # #
# # ####### #.##### #
# #   #.......#     #
# ### #.####### #####
# #   #.#  ...#     #
# #####.# #.#.# ### #
#     #.# #.#.#   # #
##### #.# #.#.##### #
#     #.# #.#.......#
# ### #.# #.#######.#
#   # #.# #.#     #.#
# # ###.# #.# # ###.#
# #   #.# #.# # #...#
# ### #.# #.### #.###
#   # #.# #...# #.# #
### # #.#####.# #.# #
#   #  .......#  ...#
#####################
