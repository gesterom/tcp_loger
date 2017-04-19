start:
	g++ debuger_server.cpp -lsfml-system -lsfml-network -o debuger.out
	g++ test_program.cpp -lsfml-system -lsfml-network  -o test.out
