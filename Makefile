CC = g++
CFLAGS = -g -std=c++11
SOURCES = $(wildcard *.cpp)
INCLUDE_DIRS = -I ./include/
LIB_DIRS = -L .
ifeq ($(LANG),)
CLIBS = -lord_sdk -lpthread -lwsock32 -lws2_32
else
CLIBS = -lord_sdk -lpthread
endif

TARGET = sdk_demo
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

$(TARGET):$(OBJECTS)
	$(CC)$(LDFLAGS) -o $@ $^ $(LIB_DIRS) $(CLIBS)
$(OBJECTS):%.o:%.cpp
	$(CC) -c $(CFLAGS) $^ -o $@ $(INCLUDE_DIRS) 

.PHONY:clean
clean:
ifeq ($(LANG),)
	del $(TARGET).exe $(OBJECTS)
else
	rm -rf $(TARGET) $(OBJECTS)
endif
