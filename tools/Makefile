EXECUTABLE :=app_name
LIBS :=-lssl -lrt
CFLAGS :=
CXXFLAGS :=-I../lua -I../tinyxml -DLUA_USE_LINUX -DTIXML_USE_STL
OBJ_DIR :=../lpgatetcp/output

C_SOURCE := $(wildcard *.c)
C_OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(C_SOURCE))

SOURCE := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SOURCE))
DEPS := $(patsubst $(OBJ_DIR)/%.o,%.d,$(OBJS))

DEPS := $(patsubst $(OBJ_DIR)/%.o,%.d,$(OBJS))


.PHONY : everything objs clean veryclean rebuild

everything : $(EXECUTABLE)


objs : $(OBJS)

clean :
	rm -f $(EXECUTABLE) $(OBJ_DIR)/*

test:
	echo $(COMMON_OBJS)

rebuild: clean everything

$(OBJS):$(OBJ_DIR)/%.o:%.cpp
	g++ -c $(CXXFLAGS) -o $@ $<

$(C_OBJS):$(OBJ_DIR)/%.o:%.c
	cc -c $(CXXFLAGS) -o $@ $<

$(EXECUTABLE) : $(LUA_OBJS) $(OBJS) $(C_OBJS)
	g++ -o $(EXECUTABLE) $(CXXFLAGS) $(OBJS) $(C_OBJS) $(LIBS)
