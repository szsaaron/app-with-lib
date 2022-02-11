CC = g++
CFLAGS = -g -std=c++11
SOURCES = $(wildcard *.cpp)
INCLUDE_DIR = -I ./include/
LIB_DIR = -L .
ifeq ($(LANG),)
LIBS = -lord_sdk -lpthread -lwsock32 -lws2_32
else
LIBS = -lord_sdk -lpthread
endif

TARGET = sdk_demo
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

$(TARGET):$(OBJECTS)
	$(CC) -o $@ $^ $(LIB_DIR) $(LIBS) $(LDFLAGS)
$(OBJECTS):%.o:%.cpp
	$(CC) -c $^ -o $@ $(INCLUDE_DIR) $(CFLAGS)

.PHONY:clean
clean:
ifeq ($(LANG),)
	del $(TARGET).exe $(OBJECTS)
else
	rm -rf $(TARGET) $(OBJECTS)
endif
