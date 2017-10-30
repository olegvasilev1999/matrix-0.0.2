# matrix-0.0.2


#include <iostream>
#include <sstream>

using namespace std;


auto input(std::istream & stream,
	float ** & result_elements,
	unsigned int & result_rows,
	unsigned int & result_columns)->std::istream &
{
	unsigned int rows = 0;
	unsigned int columns = 0;
	char symbol;
	float ** elements = nullptr;

	bool success = true;

	if (stream >> rows && stream >> symbol && symbol == ',' && stream >> columns) {
		elements = new float *[rows];
		for (unsigned int i = 0; i < rows && success; i++) {
			elements[i] = new float[columns];
			string line;
			if (getline(stream, line)) {
				istringstream sstream(line);
				for (unsigned j = 0; j < columns; j++) {
					sstream >> elements[i][j];
					if (!sstream) {
						success = false;
						break;
					}
				}
			}
			else {
				success = false;
			}
		}
	}
	else {
		success = false;
	}

	if (success) {
		result_elements = elements ;
		result_rows = rows;
		result_columns = columns;
	}
	else {
		stream.setstate(ios_base::failbit);
	}

	return stream;
}

int main()
{
	float **matrix1;
	unsigned int rows1, columns1;

	if (input(cin, matrix1, rows1, columns1)) {
		char oper;
		cin >> oper;

		float **matrix2;
		unsigned int rows2, columns2;
		if (input(cin, matrix2, rows2, columns2)) {
			cout << matrix1[2][2];
			/*switch (oper) {
			case '+':
				if (add) {

				}
			}*/
		}

	}
	cin.get();
	cin.get();
	return 0;
}
