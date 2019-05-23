#include <string>

using std::string;

namespace bullpgia{
    /**
	 * returns how much bull and how much pgia there are in the current round.
	 * @param choise the string that the chooser have been choosed.
	 * @param guess the strinthe guesser have been choosed. 
	 * @return a string whice represent how much bull and how much pgia accordingly.
	 */
const string calculateBullAndPgia(const string& choice, const string& guess);
}