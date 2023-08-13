#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;

bool validCoords(int n, int m, int x, int y)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool findWordRec(char matrix[MAX_SIZE][MAX_SIZE], int n, int m, int x, int y, char *word, int idx, int wordSize)
{
    if (!validCoords(n, m, x, y) or matrix[x][y] == '#')
    {
        return false;
    }
    char letter = matrix[x][y];
    if (letter != word[idx])
    {
        return false;
    }
    matrix[x][y] = '#';
    if (wordSize - 1 == idx)
    {
        return true;
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (findWordRec(matrix, n, m, x + dx[i], y + dy[i], word, idx + 1, wordSize))
        {
            return true;
        }
    }
    matrix[x][y] = letter;
    return false;
}

bool findWord(char matrix[MAX_SIZE][MAX_SIZE], int n, int m, char *word)
{
    int size = strlen(word);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (matrix[i][j] == word[0])
            {
                if (findWordRec(matrix, n, m, i, j, word, 0, size))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool findAll(char matrix[MAX_SIZE][MAX_SIZE], int n, int m, char *words[MAX_SIZE / 2], int wordNumber)
{
    for (size_t i = 0; i < wordNumber; i++)
    {
        if (!findWord(matrix, n, m, words[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char matrix[MAX_SIZE][MAX_SIZE];
    int n, m;
    std::cin >> n >> m;

    if (!validCoords(MAX_SIZE, MAX_SIZE, n, m))
    {
        throw std::exception();
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    char word[MAX_SIZE];
    std::cin.ignore();
    // 1.2
    // std::cin.getline(word, MAX_SIZE);

    // if (findWord(matrix, n, m, word))
    // {
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         for (size_t j = 0; j < m; j++)
    //         {
    //             std::cout << matrix[i][j] << ' ';
    //         }
    //         std::cout << '\n';
    //     }
    // }

    // 1.3
    char *words[MAX_SIZE / 2];
    int wordCount = 0;
    while (std::cin.getline(word, MAX_SIZE))
    {
        words[wordCount] = new char[strlen(word) + 1];
        strcpy(words[wordCount++], word);
    }
    std::cout << std::boolalpha << findAll(matrix, n, m, words, wordCount) << '\n';
}
