# game-of-life
gcc -o game_of_life main.c game.c renderer_csfml.c -lcsfml-graphics -lcsfml-window -lcsfml-system

./game_of_life csfml

gcc -o game_of_life main.c game.c renderer_console.c

./game_of_life
