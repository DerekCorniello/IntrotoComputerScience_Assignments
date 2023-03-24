#include <string>
#include <iostream>

/*
 * is_vowel
 *
 * checks to see if the character is a vowel
 *
 * input: a character that is tested
 * output: a boolean of if it is a vowel or not
 */

bool is_vowel(char letter)
{
	char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < 5; i++)
	{
		if (letter == vowels[i])
		{
			return true;
		}
	}
	return false;
}

/*
 * is_consonant
 *
 * checks to see if the character is a consonant
 *
 * input: a character that is tested
 * output: a boolean of if it is a consonant or not
 */

bool is_consonant(char letter)
{
	return !is_vowel(letter);
}

/*
 * ends_with
 *
 * checks to see if the inputted string has ends with the inputted suffix
 *
 * input: two strings, the candidate, or tested value, and the suffix
 * output: a boolean of if the candidate variable endes in the suffix var
 */

bool ends_with(std::string candidate, std::string suffix)
{
	if (candidate.empty() && suffix.empty())
	{
		return true;
	}

	if (candidate.empty() && !suffix.empty())
	{
		return false;
	}

	if (suffix.length() >= candidate.length())
	{
		return false;
	}

	std::string substr_from_candidate = candidate.substr(candidate.length() - suffix.length(), suffix.length());

	if (substr_from_candidate == suffix)
	{
		return true;
	}

	return false;
}

/*
 * ends_with_double_consonant
 *
 * checks to see if the last two characters in the string are consonants
 *
 * input: a string of the word being tested
 * output: a boolean value for if the string ends in two consonants
 */

bool ends_with_double_consonant(std::string word)
{
	if (word.length() < 2)
	{
		return false;
	}
	else if (is_consonant(word.at(word.length() - 1)) && is_consonant(word.at(word.length() - 2)) && word.at(word.length() - 1)== word.at(word.length() - 2))
	{
		return true;
	}
	return false;
}

/*
 * ends_with_cvc
 *
 * checks to see if the string ends in the 'consonant', 'vowel', 'consonant' pattern
 *
 * input: a string to test if it ends in the sequence above
 * output:a boolean for if it ends in the sequence above
 */

bool ends_with_cvc(std::string word)
{
	if (word.length() < 3)
	{
		return false;
	}
	else if (is_consonant(word.at(word.length() - 1)) && is_vowel(word.at(word.length() - 2)) && is_consonant(word.at(word.length() - 3)))
	{
		return true;
	}
	return false;
}

/*
 * count_consonants_at_front
 *
 * counts the number of consonants in a row at the beginning of the word
 *
 * input: a string being tested
 * output: the number of consonants in a row before the first vowel
 */

int count_consonants_at_front(std::string word)
{
	if (word.empty()) 
	{
		return 0;
	}

	int sum = 0;

	for (int i = 0; i < word.length(); i++)
	{
		if (is_consonant(word.at(i)))
		{
			sum++;
		}
		else
		{
			return sum;
		}
	}
	return sum;
}

/*
 * count_vowels_at_back
 *
 * counts the number of vowels in a row at the end of the word
 *
 * input: a string being tested
 * output: the number of vowels in a row before the first consonant at the end
 */

int count_vowels_at_back(std::string word)
{
	if (word.empty())
	{
		return 0;
	}

	int sum = 0;

	for (int i = word.length() - 1; i >= 0; i--)
	{
		if (is_vowel(word.at(i)))
		{
			sum++;
		}
		else
		{
			return sum;
		}
	}

	return sum;
}

/*
 * contains_vowel
 *
 * checks to see if the string has a vowel in it or not
 *
 * input: a string being tested
 * output: a boolean of if it has a vowel in the string or not
 */

bool contains_vowel(std::string word)
{
	if (word.empty())
	{
		return false;
	}

	for (int i = 0; i < word.length(); i++)
	{
		if (is_vowel(word.at(i)))
		{
			return true;
		}
	}
	return false;
}

/*
 * new_ending
 *
 * takes off the ending of a string and replaces it with another string
 *
 * input: a string to be changed, the length of the suffix in the original word, and the replacement suffix
 * output: the adjusted string
 */

std::string new_ending(std::string candidate, int suffixlength, std::string replacement)
{
	std::string base = candidate;
	base = base.substr(0, base.length() - suffixlength) + replacement;
	return base;
}