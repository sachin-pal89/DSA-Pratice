#include <bits/stdc++.h>
using namespace std;

char crossword[10][10];

// To print the resultant crossword
void print()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << crossword[i][j] << " ";
        }
        cout << endl;
    }
}

// To set Default status to false
void setStatus(bool status[], int length)
{
    for (int i = 0; i < length; i++)
    {
        status[i] = false;
    }
}

// To check if we can set it vertically
bool isVertical(int row, int column, string word, bool status[])
{
    for (int i = 0, j = row; i < word.length(); i++, j++)
    {
        if (crossword[j][column] != '-')
        {
            if (crossword[j][column] != word[i])
            {
                return false;
            }
        }
    }

    return true;
}

// To check if we can set it Horizontally
bool isHorizontal(int row, int column, string word, bool status[])
{
    for (int i = 0, j = column; i < word.length(); i++, j++)
    {
        if (crossword[row][j] != '-')
        {
            if (crossword[row][j] != word[i])
            {
                return false;
            }
        }
    }

    return true;
}

// To set the word vertically in crossword
void setVertical(int row, int column, string word, bool status[])
{
    for (int i = 0, j = row; i < word.length(); i++, j++)
    {
        if (crossword[j][column] != '+')
        {
            if (crossword[j][column] == word[i])
            {
                status[i] = false;
            }
            else
            {
                crossword[j][column] = word[i];
                status[i] = true;
            }
        }
    }
}

// To set the word vertically in crossword
void setHorizontal(int row, int column, string word, bool status[])
{
    for (int i = 0, j = column; i < word.length(); i++, j++)
    {
        if (crossword[row][j] != '+')
        {
            if (crossword[row][j] == word[i])
            {
                status[i] = false;
            }
            else
            {
                crossword[row][j] = word[i];
                status[i] = true;
            }
        }
    }
}

// To reset the the crossword to its previous state
void resetVertical(int row, int column, bool status[], int length)
{
    for (int i = 0, j = row; i < length; i++, j++)
    {
        if (status[i])
        {
            crossword[j][column] = '-';
        }
    }
}

// To reset the the crossword to its previous state
void resetHorizontal(int row, int column, bool status[], int length)
{
    for (int i = 0, j = column; i < length; i++, j++)
    {
        if (status[i])
        {
            crossword[row][j] = '-';
        }
    }
}

// To get the correct crossword
bool Crosshelper(string word[], int size, int index)
{
    // If we got the result
    if (index == size)
    {
        print();
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // If we have an empty space or a common char in crossword
            if (crossword[i][j] == '-' || crossword[i][j] == word[index][0])
            {
                int length = word[index].length();
                bool status[length];

                // To intiate status to false
                setStatus(status, length);

                // To check if we can put it vertical in this position and if yes then setting it and moving on
                if (isVertical(i, j, word[index], status))
                {
                    // To set this word vertically
                    setVertical(i, j, word[index], status);

                    // To move to next string word if successfull then return true
                    if (Crosshelper(word, size, index + 1))
                    {
                        return true;
                    }

                    // If not then set the position to its previous state
                    resetVertical(i, j, status, length);
                }

                // To check if we can put it Horizontal in this position and if yes then setting it and moving on
                if (isHorizontal(i, j, word[index], status))
                {
                    // To set this word Horizontally
                    setHorizontal(i, j, word[index], status);

                    // To move to next string word if successfull then return true
                    if (Crosshelper(word, size, index + 1))
                    {
                        return true;
                    }

                    // If not then set the position to its previous state
                    resetHorizontal(i, j, status, length);
                }
            }
        }
    }

    return false;
}

void getCrossWord(string word[], int size)
{
    bool result = Crosshelper(word, size, 0);
    return;
}

int main()
{
    // To store every line of crossword
    string symbols;

    for (int i = 0; i < 10; i++)
    {
        cin >> symbols;
        // To store this line of crossword character by character in our crossword
        for (int j = 0; j < 10; j++)
        {
            crossword[i][j] = symbols[j];
        }
    }

    // Taking the words that is to be inserted in the crossword
    string wordString;
    cin >> wordString;

    // A String array to store each word separately
    string word[6];
    string test = "";
    int a = 0;

    // To now actually keeping those words separately in word array
    for (int i = 0; wordString[i] != '\0'; i++)
    {
        if (wordString[i] == ';')
        {
            word[a++] = test;
            test = "";
        }
        else
        {
            test += wordString[i];
        }
    }
    word[a++] = test;

    // Call function to get the resulted crossword
    getCrossWord(word, a);

    return 0;
}