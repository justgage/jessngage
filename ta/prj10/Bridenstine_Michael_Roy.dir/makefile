###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Michael Bridenstine
# Summary:
#     Play Skeet, a game where a rilfe hits disks called birds.
#     Press arrow keys to aim and space to fire. Don't hit the 
#     red stars, they represent bald eagles, which are of course
#     illigal to shoot.
# Above and Beyond
#     Keep track of accuracy, only adjusting it once a bullet
#     actually hits or misses. After scoring 35 points, hard
#     mode is activating, increasing speeds of birds by 25%.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o bird.o
	g++ game.o uiInteract.o uiDraw.o point.o bird.o $(LFLAGS)

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

game.o: game.cpp uiDraw.h uiInteract.h point.h flyingObject.h rifle.h shot.h velocity.h
	g++ -c game.cpp


#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
bird.o: bird.cpp bird.h flyingObject.h velocity.h point.h
	g++ -c bird.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
