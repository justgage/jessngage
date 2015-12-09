###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Jared Thurman
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o bullet.o rifle.o FlyingObj.o bird.o
	g++ game.o uiInteract.o uiDraw.o point.o bullet.o rifle.o flyingObj.o bird.o $(LFLAGS)

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

game.o: game.cpp uiDraw.h uiInteract.h point.h bullet.h rifle.h bird.h
	g++ -c game.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
bullet.o: bullet.cpp bullet.h point.h uiDraw.h
	g++ -c bullet.cpp

rifle.o: rifle.cpp point.h uiDraw.h
	g++ -c rifle.cpp

FlyingObj.o: flyingObj.cpp FlyingObj.h
	g++ -c flyingObj.cpp

bird.o: bird.cpp bird.h uiDraw.h
	g++ -c bird.cpp 


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
