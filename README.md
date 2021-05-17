# Foodgame
------------------------------------------------------------------------
A C++ Text Art Game 
------------------------------------------------------------------------
Originally designed with flashing colors on ⌭windows and use of sleep
For animations. On the  Mac version it uses Usleep and a different 
terminal color changing code. See commented sections for both versions.

This game takes input, cleans it, and opens a txt ascii art file. 
-------------------------------------------------------------------------

Example input:

*apple

*A p P l

*Apples 

*Can I have apples?

*I want 3 apples, please!!! 

*I will have apple slices with milk. 

Output:
apple (with image, calories, and food group)

---------------------------------------------------
1.  Main takes in your terminal input, runs it through a 
function that turns the string into a lowercase version, removes numbers 
and symbols, removes plural and e endings, removes common 
Phrases, and then finally outputs a clean input string copy.

2. Then it opens text files of arrays to check for 
The clean input copy. Each .txt has hundreds of 
food entries.

3. Each food has an ascii art text file that roughly portrays 
It. The program will give a generic food image for most 
entries, but for the most common or unique foods it will
Open a special ascii art using if statements to help it
determine whether to use generic or special.

4. When a food is not found, it is added to an array, and stored
In a txt database, so that someone can better improve the model.

5. Each food has a calorie amount and points for food group.
6. At the end, the program gives you the diagnostic on
What foods you entered, your score, and a total calorie
Count. 

__________________________________________________________________

☆ The main gem about this program, are the text file databases
Of arrays of food, and the many txt files all 10 lines long max
That show a little image of food when printed in terminal. It is a
great library of information for anyone. 

⌫ Future improvements: I have animations in txt files of each food
Being eaten and ascii art graphics. Because python already 
Supports most unicode symbols, I may make a python version as well
using dictionaries. This program could be made more efficient with the
use of mapping (the c++ equivalent to python dictonary- which will use
constant time instead of operators to save computing time)

*/
