###############################################################
# Program:
#     Project 10, Skeet
#     Brother Burton, CS241
# Author:
#     Allen Foster
# Summary:
#     Create a game that involves a rifle that shoots at three
#     types of birds that are scored differently. I struggled
#     to get this project working. I had a hard time trying to
#     get it all to work together, and found myself getting super
#     confused with passing by reference, and using things between
#     the files. I had some people try and help me, and talked to
#     a tutor, but overall, this became a bigger and more complicated
#     mess for me. 
#     
# Above and Beyond
#     I initially thought about creating different types of bullets,
#     that travelled at different speeds. But I wasnt even able to
#     get the basics working first.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o flyingobject.o
	g++ game.o uiInteract.o uiDraw.o point.o flyingobject.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h bullet.h rifle.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h bullet.h rifle.h
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
rifle.o: rifle.cpp rifle.h point.h bullet.h uiDraw.h
	g++ -c rifle.cpp

flyingobject.o: flyingobject.cpp flyingobject.h point.h
	g++ -c flyingobject.cpp
  
bird.o: bird.h bird.cpp flyingobject.h point.h uiDraw.h velocity.h
	g++ -c bird.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
