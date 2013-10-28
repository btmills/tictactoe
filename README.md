# Tic-tac-toe

Console-based Tic-tac-toe game using the [Minimax algorithm](http://en.wikipedia.org/wiki/Minimax)

The AI player is unbeatable. It works by considering possible moves to maximize its minimum outcome. For example, if it has a choice of two moves, one that has a high chance of winning but a slight chance of losing, and another that has a low chance of winning but can guarantee at least a tie, it prefers the latter. For those interested in the algorithm, its implementation is in [ComputerPlayer.cpp](ComputerPlayer.cpp).

## Usage

Build with `make`. The name of the output file is `ttt`, so run with `./ttt`.

For the human player, squares are numbered from 1 in the top left corner to 9 in the bottom right corner:

	1|2|3
	-----
	4|5|6
	-----
	7|8|9

## License

Licensed under the BSD 3-Clause license, the full text of which can be read in [LICENSE](LICENSE).
