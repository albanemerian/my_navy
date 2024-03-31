# my_navy
Create a battle-ship game using signals

Welcome to the Battleship game implemented in the terminal using signals. In this game, two players communicate exclusively using the signals SIGUSER1 and SIGUSER2. The map size is 8x8, and each player must strategically place their ships and attempt to sink the opponent's fleet.
##Gameplay

    The game proceeds with each player taking turns to fire shots at their opponent's grid.
    Players must rely on signals to communicate their moves.
    Signals can be lost, so players must be cautious when relying on their communication protocol.
    At the beginning of each turn, players must display their positions and then their opponent's positions.
    The game ends when all the ships of a player have been hit.
    Upon the game's conclusion, the player who has successfully sunk all of their opponent's ships declares victory.

Usage<br>

To play the game, use the following command-line arguments:<br>

```bash

./my_navy [first_player_pid] navy_positions
```
Options:

    first_player_pid: PID of the first player. This is only required for the second player.<br>
    navy_positions: File representing the positions of the ships.<br>

File Format:<br>

The file representing the positions of the ships must adhere to the following format:<br>

```bash
LENGTH : FIRST_SQUARE : LAST_SQUARE

    LENGTH: Length of the ship.
    FIRST_SQUARE and LAST_SQUARE: First and last positions of the ship.
```
Ensure that the file contains 4 ships, with lengths 2, 3, 4, and 5 respectively. If the navy file is invalid, the program will terminate with an error.<br>

## Test


| Category                         | Percentage | Tests | Crash |
|----------------------------------|------------|-------|-------|
| Cheater                          | 100%       | 1/1   | x     |
| Basic signal                     | 100%       | 2/2   | x     |
| Rigor                            | 100%       | 8/8   | x     |
| Rigor eval                       | 100%       | 8/8   | x     |
| Protocol                         | 100%       | 4/4   | x     |
| Protocol eval                    | 100%       | 4/4   | x     |
| Game                             | 87.5%      | 7/8   | x     |
| Game eval                        | 62.5%      | 5/8   | x     |
| End score                        | 90.7%      | 39/43 | x     |

Beware of -42 Epitech students !!!
