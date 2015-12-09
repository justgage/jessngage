###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS165
# Author:
#     Brennan Harris
# Summary:
#     this is a game where the player can launch and shoot
#     clay pigeons as in real life trap shooting. this program
#     handles the behavior of the rifle, the birds launched,
#     and the bullets fired and the interactions among bird
#     and bullets. there are three different bird types, each
#     with a different behavior and "shot" value
# Above and Beyond
#     - birds are "pulled" by pressing the up arrow key
#     - the rifle must be cocked every 7 rounds by pressing the
#       down arrow. rounds left are displayed with points
#     - instructions are displayed and disappear when the user
#       launches a bird or fires a bullet
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingObject.o bullet.o bird.o
	g++ game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingObject.o bullet.o bird.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h
    g++ -c velocity.cpp

rifle.o: rifle.cpp rifle.h velocity.h point.h
    g++ -c rifle.cpp

flyingObject.o: flyingObject.cpp flyingObject.h velocity.h point.h
    g++ -c flyingObject.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h
    g++ -c bullet.cpp

bullet.o: bird.cpp bird.h flyingObject.h
g++ -c bird.cpp


#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################



###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
