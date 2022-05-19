#include <iostream>
#include <fstream>
#include <vector>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

int main()
{
    string filename("graph1.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    for (const auto &i : lines){
        char origin = i[0];
        for (const auto &j : i){
            cout << j << endl;
        }
    }

    input_file.close();
    return EXIT_SUCCESS;
}