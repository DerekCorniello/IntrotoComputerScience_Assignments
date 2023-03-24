#include <fstream>
#include <iostream>
#include <vector>

/*
 * more_to_read
 *
 * checks to see if a file instream has anything else to 
 *
 * input: the filestream reading from
 * output: a boolean for if another value can be read from the file stream
 * 
 */

bool more_to_read(std::ifstream &file) {
  file >> std::noskipws;
  while (file.peek() == ' ') {
    char discard;
    file >> discard;
  }
  return !(file.eof() || std::iscntrl(file.peek()));
}

/*
 * <fix typos
 *
 * changes typos in from the vectors to their respective correct word
 *
 * input: vector of words to be fixed, the typos in the original sentence, and the vector of values to change them with
 * 
 *                 /////NOTE: these must be parallel\\\\\
 * 
 * output: an integer of the amount of values replaced
 */

int fixTypos(auto &fixmeVector, auto &typoVector, auto &fixoVector)
{
    int replacedWords{ 0 };

    for (int i = 0; i < fixmeVector.size(); i++)
    {
        for (int j = 0; j < typoVector.size(); j++) {

            if (fixmeVector[i] == typoVector[j])
            {
                fixmeVector[i] = fixoVector[j];
                replacedWords++;
            }
        }
    }

    return replacedWords;
}

/*
 * write Sentence
 *
 * Takes the vector with the changed values and creates the sentence
 *
 * input: string for the sentence, the vector of fixed values
 * output: null (void)
 * 
 */

void writeSentence(std::string &sentence, auto &fixmeVector)
{
    for (int i = 0; i < fixmeVector.size(); i++)
    {
        sentence += fixmeVector[i];

        if (i == fixmeVector.size() - 1)
        {
            sentence += ".";
        }
        else
        {
            sentence += " ";
        }
    }
}

/*
 * fcc
 *
 * corrects typos in files
 *
 * input: 3 filename strings, and the string for the fixed sentence
 * output: int of how many words were changed
 * 
 */

int fcc(const std::string &fixme_filename, const std::string &typo_filename,
        const std::string &fixo_filename, std::string &fixed_sentence)
{
    std::ifstream fixme{}, typo{}, fixo{};
    std::vector<std::string> fixmeVector{}, typoVector{}, fixoVector{};

    fixme.open(fixme_filename);
    typo.open(typo_filename);
    fixo.open(fixo_filename);

    while (more_to_read(typo) && more_to_read(fixo))
    {
        std::string typostr{}, fixostr{};
        typo >> typostr;
        typoVector.push_back(typostr);
        fixo >> fixostr;
        fixoVector.push_back(fixostr);
    }
    
    if (more_to_read(typo) || more_to_read(fixo))
    {
        return -1;
    }

    while (more_to_read(fixme))
    {
        std::string fixmestr{};
        fixme >> fixmestr;
        fixmeVector.push_back(fixmestr);
    }

    int replacedWords = fixTypos(fixmeVector, typoVector, fixoVector);

    writeSentence(fixed_sentence, fixmeVector);

    return replacedWords;
}