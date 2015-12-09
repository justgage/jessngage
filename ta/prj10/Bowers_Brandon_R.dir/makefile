###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Brandon Bowers
# Summary:
#     Supposed to play a functioning skeet game.  All items have been
#     drawn to the screen.  I did run into issues getting certain objects   
#     to display in the correct location and function correctly.
#     
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o Rifle.o Bullet.o flyingObject.o bird.o 
	g++ game.o uiInteract.o uiDraw.o point.o Rifle.o Bullet.o flyingObject.o bird.o $(LFLAGS)

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

game.o: game.cpp uiDraw.h uiInteract.h point.h Bullet.h Rifle.h
	g++ -c game.cpp

Rifle.o: Rifle.cpp Rifle.h uiDraw.h Velocity.h point.h
	g++ -c Rifle.cpp

Bullet.o: Bullet.cpp Bullet.h uiDraw.h Velocity.h point.h Rifle.h
	g++ -c Bullet.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h
	g++ -c flyingObject.cpp

bird.o: bird.cpp bird.h flyingObject.h uiDraw.h
	g++ -c bird.cpp

Velocity.o: Velocity.cpp Velocity.h
	g++ -c Velocity.cpp

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
