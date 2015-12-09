###############################################################
# Program:
#     Skeet
#     Brother Burton, CS241
# Author:
#     Austin Garbrick
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     I added a gravity function to the birds. 
#     
#
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o bulletHandler.o
	g++ game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o bulletHandler.o $(LFLAGS)

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

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bulletHandler.h
	g++ -c game.cpp

rifle.o: rifle.cpp rifle.h velocity.h bullet.h uiDraw.h
	g++ -c rifle.cpp

bullet.o: bullet.cpp bullet.h velocity.h uiDraw.h
	g++ -c bullet.cpp

bird.o: bird.cpp bullet.h uiDraw.h
	g++ -c bird.cpp

#birdhandler.o: birdhandler.cpp bullet.h velocity.h point.h bird.h
#	g++ -c birdhandler.cpp

bulletHandler.o: bulletHandler.cpp bulletHandler.h bullet.h velocity.h point.h
	g++ -c bulletHandler.cpp


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
