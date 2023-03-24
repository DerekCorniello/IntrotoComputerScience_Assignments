#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = 
  { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};

  return alphabet[number];
}

int main() 
{
    std::ifstream inputFile{};
    inputFile.open("input.txt");
    char shiftChar;
    int shiftNum{};
        if (!(inputFile.is_open()))
        {
            std::cout << "The file cannot be opened." << std::endl;
            return 0;
        }
        if (!(inputFile >> shiftChar))
        {
            std::cout << "Oops: Could not read the direction from the input file." << std::endl;
            return 0;
        }
        if (!(shiftChar == 'l' || shiftChar == 'r'))
        {
            std::cout << "Oops: Invalid direction in the input file." << std::endl;
            return 0;
        }
        if (!(inputFile >> shiftNum))
        {
            std::cout << "Oops: Could not read the shift number from the input file." << std::endl;
            return 0;
        }
    while (!(std::iscntrl(inputFile.peek()) || inputFile.eof()))
    {
        char inputChar{};
        inputFile >> inputChar;
        int inputNum{ number_from_letter(inputChar) };

        if (shiftChar == 'l')
        {
            inputNum -= shiftNum;
        }
        else
        {
            inputNum += shiftNum;
        }

        if (inputNum < 0 || inputNum > ALPHABET_LENGTH - 1)
        {
            inputNum %= ALPHABET_LENGTH;
        }

        while (inputNum < 0)
        {
            inputNum += ALPHABET_LENGTH;
        }

        std::cout << letter_from_number(inputNum);
    }
    std::cout << std::endl;
}