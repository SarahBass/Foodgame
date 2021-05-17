# Foodgame
------------------------------------------------------------------------
A C++ Text Art Game 
------------------------------------------------------------------------
Originally designed with flashing colors on ⌭windows and use of sleep
for animations. On the  Mac version it uses Usleep and a different 
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
function that turns the string into a lowercase version, 
removes numbers  and symbols, removes plural and e endings, 
removes common phrases, removes spaces,
and then finally outputs a clean input string copy.

2. Main calls a function to open text files of arrays to 
check for the clean input copy. Each .txt has hundreds of 
food entries in an organized list.

3. Each food has an ascii art text file.
The program will give a generic food image for most 
entries, but for the most unique foods, it will
open a special ascii art using if statements to help it
determine whether to use generic or special.

4. When an input is not found, it is added to an array, and stored
in a not-found txt database, to better improve the model. Upon
next play, it will exist in this array and open a picture of a 
generic blob that can be interpeted as a food item. 

5. Each food has a calorie amount and points for food group.

6. At the end, the program gives you the diagnostic on
what foods you entered, your score, and a total calorie
count. It asks user for a scorename, and will add it to a high 
score array txt file, which will then print 5 previous players 
and their score. 

__________________________________________________________________

⌫ Future improvements: I have animations in txt files of each food
Being eaten and ascii art graphics. Because python already 
Supports most unicode symbols, I may make a python version as well
using dictionaries. This program could be made more efficient with the
use of mapping (the c++ equivalent to python dictonary- which will use
constant time instead of operators to save computing time).

