
#include "HumanPlayer.h" //has logic for how the human player strategises his moves

#include "BoardException.h" //lets say the exception class is defined here in this file

#define BOARD_SIZE 3

//game itself;
class TicTacToeGame
{
private:
	char board[BOARD_SIZE][BOARD_SIZE];
	int turn;
	bool finished;
	
	bool checkPlayer(char x)
	{
		if (x != 'X' && x != 'O') return false;
		
		if ((board[0][0] == x && board[0][1] == x && board[0][2] == x) ||
		(board[1][0] == x && board[1][1] == x && board[1][2] == x)	||
		(board[2][0] == x && board[2][1] == x && board[2][2] == x) ||
		(board[0][0] == x && board[1][0] == x && board[2][0] == x) ||
		(board[0][1] == x && board[1][1] == x && board[2][1] == x)  ||
		(board[0][2] == x && board[1][2] == x && board[2][2] == x)  ||
		(board[0][0] == x && board[1][1] == x && board[2][2] == x)  ||
		(board[0][2] == x && board[1][1] == x && board[2][0] == x)  )
		{
			return true;
		}
		return false;
	}
public:
	TicTacToeGame() : turn(1), finished(false)
	{
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			for (int j = 0; j < BOARD_SIZE; ++j)
			{
				board[i][j] = ' '; //initialize
			}
		}
	}
	
	void updateBoard(int row, int col, char val)
	{
		if (row >= 0 && row < BOARD_SIZE && col >=0 && col < BOARD_SIZE)
		{
			//odd turned player can only mark X and even turn player can mark only O
			if (((turn % 2 == 0 && val == 'O') || (turn % 2 != 1 && val == 'X')) && board[i][j] == ' ')
			{
				board[i][j] = val;
				++turn;
			}
			else
			{
				throw BoardException;
			}
		}
		else
		{
			throw BoardException;
		}
	}
	
	void getBoard(char copyboard[][BOARD_SIZE]) const
	{
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			for (int j = 0; j < BOARD_SIZE; ++j)
			{
				copyboard[i][j] = board[i][j];
			}
		}
	}
	
	bool checkWin(int & winner)
	{
		bool ret = false;
		if (checkPlayer('X')) ret = true;
		else if (checkPlayer('O')) ret = true;
		
		winner = turn;
		if (!ret && turn == 10) finished = true;
			
		return ret;
	}
	
	bool isFinished()
	{
		return finished;
	}
	
};

// computer player
class ComputerPlayer
{
private:
	char mark;
	char oponent;
	char board[BOARD_SIZE][BOARD_SIZE]
public:
	ComputerPlayer()
	{
		for (int i = 0; i < BOARD_SIZE; ++i)
		{
			for (int j = 0; j < BOARD_SIZE; ++j)
			{
				board[i][j] = ' '; //initialize
			}
		}
	}
	
	void setMarker(char x) { marker = x; oponent = (marker == 'O') ? 'X' : 'O';}
	
	void updateBoard(const TicTacToeGame & game)
	{
		game.getBoard(board);
		
		//rule 0 and 1 - try to win if possible or block oponent
		if (((board[0][0] == marker  && board[0][1] == marker) || (board[0][0] == oponent  && board[0][1] == oponent))
		&& board[0][2] == ' ')
		{
			game.updateBoard(0, 2, marker);
			return;
		}
		else if....
		//all other cases
		
		//rule2 - see if center is available
		if (board[1][1] == ' ')
		{
			game.updateBoard(1, 1, marker);
			return;
		}
	
		//rule3 - see if corner available
		if (board[0][0] == ' ')
		{
			game.updateBoard(0, 0, marker);
			return;
		}
		else if...
		//all other cases
		
		//rule 4 - pick any other slot
			for (int i = 0; i < BOARD_SIZE; ++i)
			{
				for (int j = 0; j < BOARD_SIZE; ++j)
				{
					if (board[i][j] == ' ')
					{
						game.updateBoard(i, j, marker);	
						return;
					}
				}
			}
	}
};

int main()
{
	HumanPlayer human;
	ComputerPlayer comp;
	
	TicTacToeGame game;
	int winner = 0;
	
	//toss
	time_t seconds = time();
	bool humanWins = false;
	if (seconds % 2 == 0)
	{
		human.setMarker('X');
		comp.setMarker('O');
		humanwins = true;
	}
	else
	{
		human.setMarker('O');
		comp.setMarker('X');
	}
	
	while (!game.checkWin(winner) && !game.isFinished())
	{
		if (humanWins)
		{
			human.updateBoard(game);
			if (game.checkWin(winner) || game.isFinished())
			{
				break;
			}
			comp.updateBoard(game);
		}
		else
		{
			comp.updateBoard(game);
			if (game.checkWin(winner) || game.isFinished())
			{
				break;
			}
			human.updateBoard(game);
		}	
	}
	
	if (game.isFinished())
	{
		std::cout << "Tie\n";
		return 0;
	}
	
	if (winner % 2 == 0 && humanWins)
	{
		std::cout << "Winner is Human\n";
	}
	else
	{
		std::cout << "Winner is Comp\n";
	}
	
	return 0;
}