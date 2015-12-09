###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Taylor Groom
# Summary:
#     The game of skeet.  The game will randomly generate one 
#     of three types of bird on the left hand side of the 
#     screen.  The user will determine if they should shoot 
#     this type of bird, and will the fire a bullet from the
#     rifle (located at the bottom right hand side of the 
#     screen) and try to destroy the bird.  Points are alloted
#     based on the number of birds destroyed.
# Above and Beyond
#     I used the moon lander as a fourth type of bird.  It 
#     moves faster than the others and so it is worth 10 points
#     and I have the phrase "Shoot the alien ship" appear on
#     the screen when the moon lander is on the screen.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o bird.o bullet.o flyingobject.o
	g++ game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o bird.o bullet.o flyingobject.o $(LFLAGS)

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

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h velocity.h bird.h bullet.h flyingobject.h
	g++ -c game.cpp


#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
rifle.o: rifle.cpp rifle.h point.h
	g++ -c rifle.cpp
velocity.o: velocity.cpp velocity.h  point.h
	g++ -c velocity.cpp
bird.o: bird.cpp bird.h point.h velocity.h flyingobject.h uiDraw.h
	g++ -c bird.cpp
bullet.o: bullet.cpp bullet.h uiDraw.h point.h velocity.h flyingobject.h
	g++ -c bullet.cpp
flyingobject.o: flyingobject.cpp flyingobject.h point.h velocity.h
	g++ -c flyingobject.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
