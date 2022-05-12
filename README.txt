Authored by 	: Deepanshu Agrawal
Dated 		: 24/04/2022

***********HOW TO RUN THE CODE***********
1. Download the files main.cpp and your code file whose data flow graph is to be 
   drawn in txt format.
2. Rename the txt file as "input.txt". Keep this file in same folder as main.cpp.
3. Run the main.cpp file with g++ compiler. To run it on Visual Studio Code terminal, commands are -
	g++ main.cpp
	./a.exe


***********SHORT CODE EXPLANATION***********
Line 31 to 39 : Taking input from txt file and storing it as a string in file_contents.
		Map named freq to help us in storing frequency of each variable.
		2-D vector named arr to store our DFG.

Line 41 to 50 : Removing spaces from file_contents and storing the result in string st.

While loop :
while loop starting from line 53 is to iterate through the string st.
if loop on line 56 finds if there is equation present on that location.
var1 then stores the variables one by one in the equation and stores it in temp vector.

Line 72 to 78 : Creates freq map to store frequency of variables, This map will help us in
		identifying the variable appearing in more than 1 equation.

for loop :
for loop staring from line 115 is to traverse through the freq map and then locate variable in
arr which appear in more than 1 equation. If any such variable appears, then it is modified as 
explained in https://www.sciencedirect.com/topics/engineering/data-flow-graph

Line 141 to 151 : Finally, DFG stored in arr 2-D vector is printed.

