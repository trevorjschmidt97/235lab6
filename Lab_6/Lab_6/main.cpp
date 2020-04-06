#include <fstream>
#include <iostream>
#include "Deque.h"
#include "Vector.h"
#include "Station.h"
#include <sstream>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

using namespace std;

int main(int argc, char * argv[])
{
	VS_MEM_CHECK

		if (argc < 3)
		{
			cerr << "Please provide name of input and output files";
			return 1;
		}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	Station<int> station;
	string input;

	while (in >> input)
	{
		out << input;
		if (input == "Add:station")
		{
			int intInput;
			in >> intInput;
			out << " " << intInput << " ";
			out << station.addCar(intInput) << endl;
		}

		else if (input == "Add:queue")
		{
			out << " " << station.addQueue() << endl;
		}

		else if (input == "Add:stack")
		{
			out << " " << station.addStack() << endl;
		}

		else if (input == "Remove:station")
		{
			out << " " << station.removeCar() << endl;
		}

		else if (input == "Remove:queue")
		{
			out << " " << station.removeQueue() << endl;
		}

		else if (input == "Remove:stack")
		{
			out << " " << station.removeStack() << endl;
		}

		else if (input == "Top:station")
		{
			out << " " << station.topCar() << endl;
		}

		else if (input == "Top:queue")
		{
			out << " " << station.topQueue() << endl;
		}

		else if (input == "Top:stack")
		{
			out << " " << station.topStack() << endl;
		}

		else if (input == "Size:queue")
		{
			out << " " << station.sizeQueue() << endl;
		}

		else if (input == "Size:stack")
		{
			out << " " << station.sizeStack() << endl;
		}

		else if (input.substr(0,5) == "Find:")
		{
			stringstream s;

			s << input.substr(5);
			int int1;
			s >> int1;

			out << " " << station.find(int1) << endl;
		}

		else if (input == "Train:")
		{
			out << "  " << station.toString() << endl;
		}


	}

	system("pause");
	return 0;
}