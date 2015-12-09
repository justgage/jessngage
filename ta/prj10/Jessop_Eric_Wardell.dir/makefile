###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Eric Jessop
# Summary:
#     Rifle shoots bullets on screen by adding and removing 
#     elements. Random birds, randomly fly across a screen. 
#     Score is displayed. Collisions work to delete bullets 
#     and birds and adjusts the score. Both bullets and birds
#     are deleted when it leaves the screen.
#     Reload rifle by the left arrow key.
#     
# Above and Beyond
#     I added a shinking into the distance and gravity function 
#     for the birds. There are extra kinds of birds to shoot.
#     The rifle needs down arrow to reload and up arrow give a 
#     laser sight. 
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingobject.o bullet.o bird.o
	g++ game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingobject.o bullet.o bird.o $(LFLAGS)
	tar -cf skeet.tar makefile *.cpp *.h


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

game.o: game.cpp uiDraw.h uiInteract.h point.h flyingobject.h rifle.h bullet.h bird.h
	g++ -c game.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

rifle.o: rifle.cpp rifle.h point.h uiDraw.h flyingobject.h bullet.h
	g++ -c rifle.cpp

flyingobject.o: flyingobject.cpp flyingobject.h velocity.h point.h uiDraw.h
	g++ -c flyingobject.cpp

bullet.o: bullet.cpp bullet.h point.h velocity.h flyingobject.h uiDraw.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h point.h velocity.h flyingobject.h uiDraw.h
	g++ -c bird.cpp



###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
