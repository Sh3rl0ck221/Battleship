#!/usr/bin/env python3

# user takes turns against existing board.
# for simplicity, this only models one move.
# also for now the board being guessed about is fixed.
# 10 x 10 board, ships with the Hasboro naming scheme

def make_board():
    size = 10
    # initialize board with all 0s
    board = [[0 for _ in range(size)] for _ in range(size)]
    
    # add ships
    board[1][1] = 1
    board[2][1] = 1  # patrol boat
    
    board[9][1] = 1
    board[9][2] = 1  # submarine (note: there was a duplicate line in C version)
    
    board[1][4] = 1
    board[1][5] = 1
    board[1][6] = 1  # destroyer
    
    board[6][6] = 1
    board[6][7] = 1
    board[6][8] = 1
    board[6][9] = 1  # battleship
    
    board[3][2] = 1
    board[4][2] = 1
    board[5][2] = 1
    board[6][2] = 1
    board[7][2] = 1  # carrier
    
    return board

def check_hit(x, y, board):
    # treat off-board shots as misses
    if x < 0 or x > 9 or y < 0 or y > 9:
        return 0
    return board[x][y]

def main():
    board = make_board()
    
    # Get user input for coordinates
    try:
        x_guess = int(input("Enter X coordinate (0-9): "))
        y_guess = int(input("Enter Y coordinate (0-9): "))
        
        hit = check_hit(x_guess, y_guess, board)
        print("Hit!" if hit else "Miss!")
    except ValueError:
        print("Please enter valid numbers")

if __name__ == "__main__":
    main() 