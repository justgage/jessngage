###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Craig McEwen
# Summary:
#     This is the full game of skeet according to what we were 
#     told to do
# Above and Beyond
#     There is a moonlander that flys fast across the screen and
#     if hit, +10 points, also flames come out the rifle when
#     shot
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o rifle.o bird.o bullet.o flyingobject.o
	g++ game.o uiInteract.o uiDraw.o point.o rifle.o bird.o bullet.o flyingobject.o $(LFLAGS)

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

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h velocity.h flyingobject.h bird.h
	g++ -c game.cpp


#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
rifle.o: rifle.cpp rifle.h point.h
	g++ -c rifle.cpp

bird.o: bird.cpp bird.h point.h uiDraw.h flyingobject.h velocity.h
	g++ -c bird.cpp

bullet.o: bullet.cpp bullet.h point.h uiDraw.h velocity.h rifle.h flyingobject.h
	g++ -c bullet.cpp

flyingobject.o: flyingobject.cpp flyingobject.h point.h velocity.h 
	g++ -c flyingobject.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
