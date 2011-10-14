all:
	g++ -o server lib/application.cpp server.cpp -levent -I/opt/local/include -L/opt/local/lib