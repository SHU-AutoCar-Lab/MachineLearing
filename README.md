# MachineLearing


#if we use opencv in linux 
#the follow may be convenient
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

% : %.cpp
       g++ $(CFLAGS) -o $@ $< $(LIBS)
