gcc `pkg-config --cflags gtk+-3.0` -o $1 $1.c `pkg-config --libs gtk+-3.0`
