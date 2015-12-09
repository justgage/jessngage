###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     David Mead Hansen
# Summary:
#    Properties for Skeet... Get rifle to shoot and birds to appear.
# Above and Beyond
#     I wasn't able to get this program to work the way I wanted
#     it to(Tough birds, multiple bullets on the screen, ect.) However,
#     I was able to get the birds to move randomly on the screen.
#     I feel like I understood and implemented Polymorphism and
#     inheritancce with this project. Number in top right is the number
#     of birds spawned.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o rifle.o bird.o bullet.o velocity.o
	g++ game.o uiInteract.o uiDraw.o point.o rifle.o bird.o bullet.o velocity.o $(LFLAGS)

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

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################

rifle.o: rifle.cpp uiDraw.h uiInteract.h point.h
	g++ -c rifle.cpp

bird.o: bird.cpp bird.h point.h
	g++ -c bird.cpp

bullet.o: bullet.cpp bullet.h point.h
	g++ -c bullet.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
