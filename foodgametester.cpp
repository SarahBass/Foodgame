/* ___               __                 _                              
  / __\ _     _     / _| ___   ___   __| |   __ _  __ _ _ __ ___   ___ 
 / /  _| |_ _| |_  | |_ / _ \ / _ \ / _` |  / _` |/ _` | '_ ` _ \ / _ \
/ /__|_   _|_   _| |  _| (_) | (_) | (_| | | (_| | (_| | | | | | |  __/
\____/ |_|   |_|   |_|  \___/ \___/ \__,_|  \__, |\__,_|_| |_| |_|\___|
                                            |___/                      */

/**********************************
Sarah Bass
Personal Project: Food Word Game
Language: C++ with NCURSES
-----------------------------------
---------Contents------------------
Part 1: user input as array of char
Part 2: clean up input     
        a.lowercase   
        b.remove spaces
        c.remove plural
        d.convert to string
Part 3:find input type                   
        a.check array for found 
        b.assign type string  
Part 4:sort input type                 
        a.assign filename
        b.give points
        c.update score
Part 5: open files
        a.use filename to open
        b.animate
        c.show score        
-----------------------------------
-----------------------------------                
---------LIST OF FUNCTIONS------------                      
#1)userinputcleaner: cleans userinput |                               
#2):filereaderfunctionvchecks arrays  |             
#3)asciiartopener: opens txt files    |
#4)flashinglights: changes colors     | 
#5)spacedown: sleep and /n looped     |
#6)deletepicture: sleep and /         |
---------------------------------------
---------------------------------------*/

#include <stdio.h>
#include <iostream> 
#include <string> 
#include <stdlib.h> 
#include <fstream> 
#include <unistd.h>
//#include <windows.h> 
#include <chrono> 
//#include <mmsystem.h> 
#include <iomanip> 
#include <algorithm>
#include <cctype>
#include <array>

//#include <curses.h>
using namespace std; 
struct notfoundlog {string notfoundwords;};
//----------------FUNCTIONS AND TEMPLATES---------------
//#1 clean up string input
string userinputcleaner (string userinputraw);
//#2 open and check file for input
bool filereaderfunction(string userinput,string nameoffile);
//#3: Opens a .txt 
void asciiartopener (string filename);
//#4: Flashes console colors
void flashinglights();
//#5: Move downs
void spacedown(); 
//#6 
void deletepicture();
/*               _       
 _ __ ___   __ _(_)_ __  
| '_ ` _ \ / _` | | '_ \ 
| | | | | | (_| | | | | |
|_| |_| |_|\__,_|_|_| |_| */                        

int main(){
//****ARRAY FOR NOT FOUND STORAGE****
  notfoundlog words[20]; 
  string notfoundwords; 
  int userCount = 0; 
//*********HIGH SCORE**************

//*********************************
bool inarray = false;    
string userinput;
string userinputraw;
string usertype = "unknown";
string nameoffile; //array file
string filename;//art file
int score = 0;
//*********************************
  int caloriecount = 0;
  int dessertcount = 0;
  int drinkcount = 0;
  int egganddairycount = 0;
  int fruitcount = 0;
  int graincount = 0;
  int meatcount = 0;
  int nutcount = 0;
  int vegetablecount = 0; 
//*********************************
//----START SCREEN ANIMATION-------
    
    cout << "\nWelcome to C++ Picnic" << endl;
    usleep (1000000);
    cout << "***Enter Ctrl - Z to quit***" << endl;
    usleep (1000000);
cout << "Enter food item: " << endl;
for (int s = 0; s < 15; s++)
    {
      getline(cin, userinputraw);
    
userinput = userinputcleaner(userinputraw);

nameoffile = "fruitinarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "fruit";
    fruitcount++;
    caloriecount += 100;
    score++;
    if((userinput == "grap")||(userinput == "grape")
    ||(userinput == "grapes")){
    filename = "grape.txt";
    }else if((userinput == "appl")|| (userinput == "apple")
    || (userinput == "apples")){
    filename = "tinyapple.txt";
    }else if((userinput == "banana")||(userinput == "bananas")){
    filename = "bananaopen.txt";  
    }else if(userinput == "fruitsalad"){
    filename = "bowlofblob.txt";  
    }
    else if ((userinput == "pineappl")||(userinput == "pineapple")){
    filename = "pineapple.txt";  
    }else if ((userinput == "watermelon")||(userinput == "melon")||
    (userinput == "hornedmelon")|| (userinput == "muskmelon")||
    (userinput == "xiguamelon")|| (userinput == "honeydew")||
     (userinput == "cantaloup") || (userinput == "cantalop")){
    filename = "watermelon.txt";  
    }
    else if ((userinput == "tomato") || (userinput == "orang")|| 
    (userinput == "tomatoes") || (userinput == "oranges")){
    filename = "tomato.txt";  
    }
    else if ((userinput == "cherry")||(userinput == "cherries")){ 
    filename = "bettercherry.txt";  
    }else if ((userinput == "strawberry") || (userinput == "blackberry") ||
    (userinput == "boysenberry") || (userinput == "mulberry") ||
    (userinput == "pricklypear") || (userinput == "raspberry") ||
    (userinput == "bilberry") || (userinput == "cherimoya") ||
    (userinput == "breadfruit") || (userinput == "durian") ||
    (userinput == "itapalm") || (userinput == "hornedmelon")){
    filename = "strawberry.txt";  
    }else if ((userinput == "acai") || (userinput == "ackee") ||
    (userinput == "kumquat") || (userinput == "blueberry") ||
    (userinput == "oliv") || (userinput == "lingonberry") ||
    (userinput == "cranberry") || (userinput == "wildstrawberry") ||
    (userinput == "coffeebean") || (userinput == "cloudberry") ||
    (userinput == "berry") || (userinput == "bilberry") ||
    (userinput == "currant") || (userinput == "gojiberry")){
    filename = "berriesonplant.txt";  
    }
    else{
    filename = "cherry.txt";
    }
}
nameoffile = "vegetableinarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "vegetable";
    vegetablecount++;
    score++;
    score = score + vegetablecount;
    if ((userinput == "pumpkin")||(userinput == "squash")||
    (userinput == "butternut")|| (userinput == "butternutsquash")||
    (userinput == "acornsquash")|| (userinput == "pumpkin")||
    (userinput == "kabocha")|| (userinput == "spaghettisquash")){
    filename = "pumpkin.txt";}  
    else if ((userinput == "chili") || (userinput == "chilipepper")||
     (userinput == "bellpepper") || (userinput == "cucumber") ||
     (userinput == "zuchinni") || (userinput == "pepper") ||
     (userinput == "bean") || (userinput == "limabean")||
     (userinput == "kidneybean") || (userinput == "pea") ||
     (userinput == "sugarpea") || (userinput == "sugarsnappea")){
    filename = "peppers.txt";}
    else if((userinput == "potato")||(userinput == "potatoes")){
    filename = "potato.txt";  
    }else if(userinput == "corn"){
    filename = "corn.txt";  
    }else if((userinput == "pickl") || (userinput == "pickles")){
    filename = "picklejar.txt";  
    }else if((userinput == "mixedvegetabl")|| (userinput == "vegetables")|| 
    (userinput == "potatosalad")|| (userinput == "salad")||
    (userinput == "mixedveggy")){
    filename = "bowlofblob.txt";  
    }else if((userinput == "fry")||(userinput == "tattertot")|| 
    (userinput == "cheesefry")||    (userinput == "fries")||
    (userinput == "hashbrown")||(userinput == "chip")|| 
    (userinput == "chips")){
       filename = "burgerandfries.txt";
    }else{  
    filename = "carrotsmall.txt";}
    caloriecount += 50;
}
nameoffile = "cheesearraylong.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "cheese";
    egganddairycount++;
    filename = "cheese.txt";
    caloriecount += 230;
    score++;
}
nameoffile = "alcoholarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "alcohol";
    drinkcount++;
    filename = "alcohol.txt";
    caloriecount += 130;
    score++;
}
nameoffile = "milkarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "milk";
    egganddairycount++;
    filename = "milk.txt";
    caloriecount += 130;
    score++;
}
nameoffile = "spicesarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){

    usertype = "spice";
    filename = "berriesonplant.txt";
    caloriecount += 0;
    score++;
}
nameoffile = "chickenarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "chicken";
    meatcount++;
    score++;
    if ((userinput == "chickenburger") ||
    (userinput =="turkeyburger") ||
     (userinput =="chickensandwich")){
filename = "burgerandfries.txt";
    }else{
    filename = "meat.txt";}
    caloriecount += 370;
}
nameoffile = "beefarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "beef";
    meatcount++;
    score++;
    if ((userinput == "burger")|| (userinput =="hamburger") 
    || (userinput =="cheeseburger")||
    (userinput =="steakburger")|| (userinput =="cheesehamburger")
    || (userinput =="beefburger")||
   (userinput =="buffaloburger") || (userinput =="sloppyjo")){
    filename = "burgerandfries.txt";}
    else if ((userinput == "hotdog") || (userinput == "weiner") 
    || (userinput == "dog")||
    (userinput == "bageldog") || (userinput == "wenniedog") || 
    (userinput == "frank") ){
      filename = "hotdog.txt";
    }else if ((userinput == "meatball") || (userinput == "groundbeef")
     || (userinput == "groundmeat")||
    (userinput == "groundpork") || (userinput == "groundlamb") || 
    (userinput == "meatloaf")){
      filename = "blob.txt";
    }else if ((userinput == "bacon") || (userinput == "sausag")){
      filename = "breakfastplate.txt";
    }
    else {
      filename = "hunkofmeat.txt";
    }
    caloriecount += 450;
}

nameoffile = "dougharray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "bread";
    graincount++;
    score++;
    caloriecount += 150;
    if (userinput == "pretzel"){
    filename = "pretzel.txt";
    }else if ((userinput == "pizza") ||
    (userinput == "brushetta") ||
    (userinput == "calzon") ||
    (userinput == "quesadilla") ||
    (userinput == "pizzapocket") ||
    (userinput == "stromboli")||
    (userinput == "apizza"))
    {
      filename = "pizza.txt";
}else if ((userinput == "bagel") ||
(userinput == "onionbagel" ) ||
(userinput == "cheesebagel") ||
(userinput == "cinnamonraisinbagel") ||
(userinput == "plainbagel") ||
(userinput == "sesamebagel") ||
(userinput == "eggbagel") ||
(userinput == "wheatbagel") ||
(userinput == "blueberrybagel") || 
(userinput == "poppyseedbagel")){
      filename = "bagel.txt";
    }else if (userinput == "matzah")
    {
      filename = "matzah.txt";
    }
      else{
    filename = "bread.txt";
    } 
    }

nameoffile = "sandwichtoastarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "sandwich";
    graincount++;
    score++;
    filename = "toastorsandwich.txt";
    caloriecount += 550;
}
nameoffile = "bowlarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "bowl";
    graincount++;
    score++;
    filename = "bowlofblob.txt";
    caloriecount += 390;
}
nameoffile = "nutarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "nut";
    nutcount++;
    score++;
    filename = "nuts.txt";
    caloriecount += 230;
}
nameoffile = "hotdrinkarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "drink";
    drinkcount++;
    score++;
    filename = "teapot.txt";
    if((userinput == "tea") || (userinput == "coffee") ||
     (userinput == "coffe")){
   caloriecount += 0; 
}else{
  caloriecount += 100;
}
}
nameoffile = "colddrinkarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "drink";
    drinkcount++;
    score++;
    filename = "beer.txt";
    if((userinput == "dietcok") || (userinput == "mineralwater") 
    || (userinput == "water")){
   caloriecount += 0; 
}else{
  caloriecount += 100;
}
}
nameoffile = "dessertarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "dessert";
    dessertcount++;
    score++;
    if (userinput == "chocolat"){
      filename = "chocolate.txt";
    }else
    filename = "dessertpic.txt";
    caloriecount += 330;
}
nameoffile = "bakedgoodarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "dessert";
    dessertcount++;
    score++;
    if (userinput == "gingerbread"){
      filename = "cookie.txt";
    } else if ((userinput == "cookie") || (userinput == "cooki") 
    || (userinput == "cooky") ||
    (userinput == "muffin") || (userinput == "browni")||
    (userinput == "cookies") || (userinput == "oreos")
    || (userinput == "donut")|| (userinput == "doughnut")) {
      filename = "bagel.txt";
    }else
    {filename = "hotdog.txt";}
    caloriecount += 330;
}
nameoffile = "fisharray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "fish";
    meatcount++;
    score++;
    filename = "shrimpsushi.txt";
    caloriecount += 300;
}
nameoffile = "eggarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "egg";
    egganddairycount++;
    score++;
    filename = "breakfastplate.txt";
    caloriecount += 230;
}
nameoffile = "nicewordarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "happy";
    score++;
    filename = "niceheart.txt";
}
nameoffile = "cusswordarray.txt";
inarray = filereaderfunction(userinput, nameoffile); 
if (inarray == true){
    usertype = "sad";
    filename = "blankscreencreatedonmac.txt";
}
if (usertype == "unknown")
    {
        notfoundlog user;
        user.notfoundwords = userinputraw;
        words[userCount] = user;
        userCount++;
        filename = "nothere.txt";
    }


//print art
asciiartopener(filename);
cout << "\nScore: " << score <<endl;

//must reset values for loop 
inarray = false;
usertype = "unknown";
//repeat loop or end program ----------
cout << "Enter food item: " << endl;
} 


//------------------END OF LOOP--------
string line;
  ifstream myfile ("finalscore.txt");
  if (myfile.is_open())
  { while ( getline (myfile,line) )
    {cout << line << '\n';
    usleep(10000);}
    myfile.close();
  }else{ cout << "Unable to open file";}
          
cout << "--------------------" << endl; 
cout << "Your score : " << score << endl;  
cout << "You ate " << caloriecount << " calories!" <<endl;
cout << "--------------------" << endl;  
flashinglights();
spacedown();
cout << "----------------------------------" << endl;   
cout << "VEGETABLE and BEAN BONUS: " << vegetablecount << endl;
cout << "----------------------------------" << endl;    
cout << "---ANIMAL PERFORMANCE STATISTICS---" << endl;
cout << "\tFRUITS LISTED: " << fruitcount << endl;
cout << "\tGRAINS LISTED: " << graincount << endl;
cout << "\tMEAT LISTED: " << meatcount << endl;
cout << "\tDESSERTS AND DRINKS LISTED: " << (drinkcount + dessertcount) << endl;
cout << "\tEGGS AND DAIRY LISTED: " << egganddairycount << endl;
cout << "\tNUTS LISTED: " << (nutcount) << endl;
cout << "----------------------------------" << endl;  
flashinglights();
spacedown(); 
cout << "--------------------" << endl;   
cout << "NOT FOUND IN DATABASE" << endl;   
cout << "--------------------" << endl;   
for (int i = 0; i < userCount; i++)
{
    cout << "Not Found: " << words[i].notfoundwords << endl;
}
cout << "--------------------" << endl;  
flashinglights();
spacedown();
cout << "\aThank you for using C++ Picnic" << endl;
usleep (1000000);
for (int i = 0; i<30; i++) {
    printf(">");
    usleep(10000);    
cout << "\nEND OF PROGRAM" <<  endl;
spacedown();
//system("color 07");   
return 0;
}

}
 /*__                  _   _                 
  / _|_   _ _ __   ___| |_(_) ___  _ __  ___ 
 | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 |  _| |_| | | | | (__| |_| | (_) | | | \__ \
 |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/*/
                                          
/*-----------------------------------                
---------LIST OF FUNCTIONS------------                      
#1)userinputcleaner: cleans userinput |                               
#2):filereaderfunctionvchecks arrays  |             
#4)asciiartopener: opens txt files    |
#5)flashinglights: changes colors     | 
#6)spacedown: sleep and /n looped     |
---------------------------------------
---------------------------------------*/

//function #1 clean up user input
string userinputcleaner (string userinputraw){
string userinput;
char ch1;
char ch2;
char ch3;
int n;

string worddelete;
//turn to lowercase
   transform(userinputraw.begin(), userinputraw.end(), userinputraw.begin(), ::tolower);
//removepunctuation
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), ',' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '.' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '?' ),
            userinputraw.end());            
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '!' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '&' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '1' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '2' ),
            userinputraw.end());            
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '3' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '4' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '5' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '6' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '7' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '8' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '9' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '0' ),
            userinputraw.end());
userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), '#' ),
            userinputraw.end());                                                                                                                                                                                                             
//remove plural
n = userinputraw.length();
		ch1=userinputraw[n-1]; //s
		ch2=userinputraw[n-2]; //e
        ch3 = userinputraw[n-3]; //i
        if ((ch1=='s') && (ch2 == 'e') && (ch3 == 'i')){
			userinputraw = userinputraw.substr(0,n-3)+"y   ";
        }else if ((ch1=='s') && (ch2 == 'e')){
			userinputraw = userinputraw.substr(0,n-2)+"  ";
        }else if (ch1=='s'){
			userinputraw = userinputraw.substr(0,n-1)+" ";
        }else if (ch1=='e'){
			userinputraw = userinputraw.substr(0,n-1)+" ";
        }
//remove spaces
std::string::iterator end_pos = std::remove(userinputraw.begin(), 
userinputraw.end(), ' ');
userinputraw.erase(end_pos, userinputraw.end());
//order: all request phrases first
//please last
//adjectives before adverbs and prepositional phrases
//an before a
//long and uncommon phrases first, most common last
// withtomatoandonion must come before withtomato 
string worddeleted[550] = {
"organic", "glutenfree", "gmo", "green", "purple", "sweet", "i'dlikea",
"sour", "bitter", "spicy", "yellow", "vanilla", "unripe", "ripened", "abagof", 
"abasketof", "large", "californian", "five", "dairyfree", "aplateof",
"iwanttoorderan","iwanttoordera", "iwanttoordersome",
"iwouldliketoeatan","iwouldliketoeata", "iwouldliketoeatsome","iwouldliketoeat",
"iwanttoeatan","iwanttoeata", "iwanttoeatsome","iwanttoeat",
 "iwouldliketoorderan","iwouldliketoordera","iwouldliketoordersome",
"i'llhavethe", "iwillhavean","iwillhavea", "Iwillhavesome", 
"canipleasehavean", "canipleasehavea","canipleasehave",
"canihavean" "canihavea", "canihavesome","canihave", 
"iwouldliketohavea", "iwouldliketohavean", "iwouldliketohavesome",
"iwouldliketodrinkan","iwouldliketodrinka","iwouldliketodrink",
"canyoushowmean", "canyoushowmea", "canyoushowme",
"canyougivemesome", "canyougivemean", "canyougivemea",
"givemesome", "givemean", "givemea",
"caniseean","caniseea", "canisee",
"canieatan","canieata", "canieat",
"doyouwantan","doyouwanta", "hereisan","hereisa",
"iwanttodrink",  "canidrinka","canidrinkan","canidrink"
"iwantsome","iwantan", "iwanta", "iwant",
"i'llhavesome",
"i'llhavean", "i'llhavea", "i'llhave","illhave",
"Iwouldlikean","Iwouldlikea", "Iwouldlikesome","iwouldlike", 
"freerange", "soy", "vegan", "vegetarian", 
"small", "medium", "paleo", "keto", "english", "american", "southern", 
"powdered", "crushed", "adozen", "acoupleof", "acouple",  "ahundred", 
"mcdonalds", "burgerking", "newyork", "chicago", "indian" ,"chinese", "mexican", 
"inandout", "fiveguys", "homebrew", "local", "homemade", "sprinkled", "alittle", 
"asmallamountof", "bringsome", "amillion", "two", "three", "four", 
"seven", "eight", "nine", "six", "twelve", "twenty", "fifty", "atonof", "onehundred",
"onethousand", "onemillion", "andabunchof","abunchof", "bunchof", "loadsof", "amountianof", "ascoopof",
"adollopof","burnt","traditional", "sugarfree", "fatfree", "lowfat", "lowsugar", "tasty", 
"lactosefree", "fresh", "dried", "cooked", "fried", "baked", "freeze",
"ahandful", "grilled", "poached", "boiled", "harboiled", 
"softboiled", "grated",  "freerange", "locallygrown", 
"sunnysideup", "scrambled", "overeasy", "german", "french", "italian", "frozen", "paste", 
"atablespoonof","ateaspoonof","tablespoonof","teaspoonof","aspoonfulof", "aspoonof","spoonsof", "spoonof",
"acupof", "cupsof", "cupof",  
"abowlof", "bowlsof",  "bowlof", 
"glassesof","aglassof","glassof",
"slicesof", "asliceof", "sliceof", "sliced",
"ajarof", "jarsof", "jarof",
"withalfredo",
"ahalfofan","ahalfofa","halfofa","ahalfa","halfa","half",
"vietnamese", "african", "lightroast", "darkroast", "mediumroast", "broiled", "diced", 
"chilled", "japanese", "korean", 
"chopped", "minced", "whipped", "jam", "jelly", "melted", "peeled" "handsqueezed", 
"buttered" ,"microwaved", "steamed", "juic", "juice",  
"blended", "grande", "venti", "wheat", "wholewheat", "cagefree", 
"persian", "greek", "italian", "sweedish", "danish", "iced", "withoutmilk", "withoutdairy", 
"localgrown", "farmersmarket", 
"crunchy", "gourmet", "natural", "pickled", "golden", "goldenbrown", "brown", "white", 
"blood", "bloody", "browned", "opal", "roma", "hard", "withoutmayo"
"withnosugar","mashed", "light",
"kosher", "grannysmith", "fuji", "pinklady", "juicy", "honeycrisp", "envy", "gala", "jazz",
"andacherryontop","withoutsugar", "creamed", "acanof", "bottleof",
"reddelicious", "goldendelicious", "mcintosh", "libery", "freedom", "pacific", "atlantic", 
"yukon", "yukongold", "russet", "withmarshmellow", "abowlof", "withpepperoni",
"fingerling", "halal", "smoked", "stinky", "pasteurized", "processed", "fresh", "soft", "withcreamcheese",
"black", "anwhole","awhole","whole", "withsugar", "withoutsugar", "withcreamchees",
 "extra", "fresh", "hot", "cold", "aspoofof", "withsplenda", 
 "withpickl", "withfry", "withchip", "withvinegarandchip", "withpotatosalad", "withfruit", 
 "withonion", "andshak", "andsugar", "withsalt",  "withoutchees",
 "withredpepper", "withmaplesyrup", "withranch", "withcarrot", "withmarinara", "withponzu",
 "withcoleslaw", "withveggy", "withvegetabl", "withpotato", "withfrosting", "withsourcreamandchives",
 "withhoney", "withmilk", "withhotsauce", "mediumrare", "withbutterscotch", "withoutonion",
"withsauerkraut", "withcabbag", "withpeasandcarrot", "withsaltandpepper", "withketchup",
 "withcelery", "andmilk", "notspicy", "butnotspicy", "withpickle", "andpickle",
 "withspinach", "withdressing", "withoutbutter", "withlettuc",  "withsalad", "withpreserv", 
 "withbutter", "withsourcream", "withbanana", "withgarlic", "withtzatziki", "withlettucetomatoandonion",
 "withbacon", "withcottagechees", "butnosugar", "butnomilk", "andonionring", "withlettuceandtomato", 
 "withmarmalad", "withgrape", "withgrap", "withstrawberry", "withcherry", "withblackberry",
  "withraspberry", "withappl", "withapple", "withegg", "lotsof", "withmustard", "withbalsamic",
  "withsweetpotatofry", "withswisschees", "withpepperjack", "withprovolon", "withcheddar",
  "withmozzarella", "withgoatchees", "withtomatosoup", "withclamchowder", "andlettuce", "andlettuc"
 "withchili", "withbean", "withbakedbean", "withfruitsalad", "withmacandchees", 
  "withcornbread", "onthecob", "withcorn", "withnut", "withraisin","andpotato", "withmolass","withpepper", 
 "withacherryontop", "withchocolatesyrup", "withchocolat", "withcaper", "withtartar",
  "withcucumber", "withpesto", "withmayonnaise", "withsyrup", "andcooky", "andcookies", "andcooki",
 "withcaramel", "withorange", "withorang", "withfish", "withpeanut", "withsriracha", "withhummu", 
  "withyogurt", "withicecream", "withbiscuit", "withcranberry", "andchocolat", "cliced",
 "withvinagrete", "withhollandaise", "withhollandais", "withaujus", "withchutney", 
  "withguacamole", "withavocado", "andchips", "andfries", "andsalad", "andfry", "withtomato",
 "withsalsa", "andsalsa", "andguacamol", "withmol", "withhorseradish", "andtartar", "withlingonberry", 
  "withdip", "anddip", "withsausage", "andbacon", 
 "withsprinkl", "andnut", "withschmaltz", "withtahini", "withwhipcream", "withwhip",  "withicing", "secret",
  "withthousandisland", "withlox", "andlox", "andcreamchees", "withgreenpepper", "witholives", "witholiv",
 "withbarbecu", "withbluechees" ,"withchees", "withmushrooms", "andchiv", "withlettuce", "withlettuc",
  "withmayo", "withcrisp",  "withcoffe", "withtea", "andhoney", "andchees", "andolives"
 "withcinnamon", "withcardamom", "withnutmeg", "withdill", "withginger", "withhorseradish", "andoliv", 
 "withszechwansauc", "withoregano", "withsaffron", "withpaprika", "witheverythingonit", "andcream", "afew", 
 "withrosewater", "withrosepetals", "withcayennepepper", "sauc", "slic", "withspicypepper", "withcream", "please", "pleas"};
for (int k = 0; k<550; k++){
std::string::size_type i = userinputraw.find(worddeleted[k]);
if (i != std::string::npos)
   userinputraw.erase(i,  worddeleted[k].length());   
}                                               

//assign new string with clean input
userinput = userinputraw;
return userinput;
}

//function 2: read and print array in file to check
bool filereaderfunction(string userinput,string nameoffile){
bool inarray = false;      
int filecount;
ifstream fileopener(nameoffile);
fileopener >> filecount;
string filearray[filecount];
for (int i = 0; i<filecount; i++){
     fileopener >> filearray[i];}
    for (int j = 0; j < filecount; j++)
    {
        if (userinput == filearray[j])
        {inarray =true;
        }
    }
   return inarray;  
}

//Function #3 
void asciiartopener (string filename)
{string line;
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    
      cout << line << '\n';
    }
    myfile.close();
  }
}
//Function #4 
  void flashinglights(){
for (int i = 0; i<7; i++){
//system("color 0A");
usleep(200000);
//system("color 0B"); 
usleep(200000);
//system("color 0E");
usleep(200000);
//system("color 06");
usleep(200000);
//system("color 0A");
usleep(200000);
//system("color 02");
}
  }

//function #5 
void spacedown(){
for (int i = 0; i<12; i++) {
    printf("\n");
    usleep(10000);
}
}
/*---------------GAME RUN EXAMPLE---
Enter food item: apple              | 
  ,--./,-.                          |
 / #      \                         |
|          |                        |
 \        /                         |
  `._,._,'                          |
 Score: 1  
-----------------------------------*/
//CHECK IF ARRAY IS READING PROPERLY------------     
//cout << "--------------------------" << endl;
//cout << "Print Array: [ ";
//for (int m = 0; m<filecount; m++){ 
//    cout << filearray[m];
//    cout << " , ";
//}
//cout << "\b\b ]";
//cout << endl;
//-------------------------------------------------