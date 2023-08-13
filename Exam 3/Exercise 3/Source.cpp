#include <iostream>
#include <cstring>

const int MAX_LENGTH = 1024;

int toLength(int n)
{
    int l = 0;
    while (n)
    {
        l++;
        n /= 10;
    }
    return l;
}

bool convertToStrNumber(char *str)
{
    const int NUMBER_OF_LETTERS_IN_THE_ALPHABET = 26;

    int histogram[NUMBER_OF_LETTERS_IN_THE_ALPHABET]{0};
    char *iter = str;

    while (*iter)
    {
        histogram[*iter - 'a']++;
        iter++;
    }
    int length = 0;
    for (int i = 0; i < NUMBER_OF_LETTERS_IN_THE_ALPHABET; i++)
    {
        length += histogram[i] * toLength(histogram[i]);
    }

    // +1 for \0
    if (length + 1 >= MAX_LENGTH)
    {
        return false;
    }

    // start backwords
    // indexes from 0 to length
    int letterIndex = strlen(str) - 1;
    int writingIndex = length - 1;
    while (writingIndex >= 0)
    {
        char letter = str[letterIndex--];
        int occurances = histogram[letter - 'a'];
        while (occurances)
        {
            str[writingIndex--] = occurances % 10 + '0';
            occurances /= 10;
        }
    }

    return true;
}

int main()
{
    char str[MAX_LENGTH]{0};
    std::cin.getline(str, MAX_LENGTH);
    if (convertToStrNumber(str))
    {
        std::cout << str << '\n';
    }
}
