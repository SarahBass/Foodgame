# Foodgame
/*
A c++ game I made when I learned how to read arrays, open files, 
And clean input. No classes are used, only functions.
Originally designed with flashing colors on windows and use of sleep
For animations. On the Mac version it uses Usleep and a different 
Terminal color changing code. See commented out sections
Which include options for both.

First it takes in your terminal input, turns it lowercase, removes numbers 
And symbols, removes plural and e endings, removes common 
Phrases, and then finally outputs a clean input.

If you put in:
*apple
*A p P l
*Apples 
*Can I have apples?
*I want 3 apples, please!!! 
*I will have apple slices with milk. 

One function will clean all of this input to "appl"

Then it opens text files of arrays to check for 
The word apple. Each .txt has hundreds of 
food entries. (Yes, I could have used mapping/ dictionary 
To make it more efficient, but it was much easier for me 
To store the data this way, and keeps the program looking
Cleaner as you don't have to scroll past thousands of 
Entries of food. All in all,, it was more time effective for
Myself to copy and paste alphabetical lists of food in 
Txt files, but in the future I may improve the model.)

..............
....APPLE.....
..,--./,-.....
./-#------\...
|----------|..
.\---------/..
..`._,._,'....
..............

Each food has an ascii art text file that roughly portrays 
It. The program will give a generic food image for most 
entries, but for the most common or unique foods it will
Open a special ascii art.

When a food is not found, it is added to an array, and stored
In a txt, So that I can better improve the model.

Each food has a calorie amount and points for food group.

At the end, the program gives you the diagnostic on
What foods you entered, your score, and a total calorie
Count. 

The main gem about this program, are the text file databases
Of arrays of food, and the many txt files all 10 lines long max
That show a little image of food. 

Future improvements: I have animations in txt files of each food
Being eaten and ascii art graphics. Because python already 
Supports most Japanese characters and special symbols like stars
And hearts, I may make a python version as well using dictionaries.

*/
