all:
	g++ -o server_cpp lib/application.cpp server.cpp -levent -I/opt/local/include -L/opt/local/lib