CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = contact
SRCS = main.cpp contact_manager.cpp contact.cpp sneaky_contact.cpp sneaky_contact_manager.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
