#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> dados;
    int entrada;
    int quadros = 0;

    quadros = atoi(argv[1]);
    while ((!feof(stdin)))
    {
        scanf("%d\n", &entrada);
        dados.push_back(entrada);
    }
    cout << quadros << endl
         << endl;

    for (int j = 0; j < dados.size(); j++)
    {
        cout << dados[j] << endl;
    }

    return 0;
}
