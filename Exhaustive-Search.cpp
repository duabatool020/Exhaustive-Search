#include<iostream>
using namespace std;
class node
{
public:
char assignment;
int value;
int time;
node* next;
};
class Linkedlist {
public:
node* head;
int time;
int points;
Linkedlist() {
head = NULL;
time = 0;
points = 0;
}
void Insert_end(char asmnt, int v, int t) {
node* temp1;
node* p;
if (head == NULL) {
temp1 = new node;
temp1->assignment = asmnt;
temp1->value = v;
temp1->time = t;
temp1->next = NULL;
head = temp1;
}
else {
temp1 = head;
while (temp1->next != NULL) {
temp1 = temp1->next;
}
p = new node;
p->assignment = asmnt;
p->value = v;
p->time = t;
p->next = NULL;
temp1->next = p;
}
}
int sumOFTime()//calculate sum of time of all assignments in a
set
{
node* temp1;
temp1 = head;
while (temp1 != NULL)
{
time = time + temp1->time;
temp1 = temp1->next;
}
return time;
}
int sumOFPoints()//calculate sum of points of all assignmets in a
set
{
node* temp1;
temp1 = head;
while (temp1 != NULL)
{
points = points + temp1->value;
temp1 = temp1->next;
}
return points;
}
void Display()
{
node* temp1 = head;
while (temp1 != NULL) {
cout << temp1->assignment;
temp1 = temp1->next;
}
}
};
class Array //array of linkedlist
{
private:
int N;
Linkedlist* array;
public:
Array()
{
N = 2;
array = new Linkedlist[2];
}
Array(Linkedlist* arr, int size)
{
N = size;
array = new Linkedlist[size];
}
void setValue(Linkedlist* arr, int size)
{
N = size;
array = arr;
}
void DisplayArray() //display all sets of assignments
{
cout << "***********************All possible pairs
are:******************" << endl;
cout << "SUSBETS OF ASSIGNMENTS: " << "\t\t\t\t\t" << "TIME
CONSUMED " << "\t\t\t" << "POINTS" << endl;
cout <<
"_____________________________________________________________________
________________________________________" << endl;
for (int i = 0;i < N;i++)
{
cout << "{ ";
array[i].Display();
cout << " }" << "\t\t\t\t\t\t\t\t\t" <<
array[i].sumOFTime() << "\t\t\t" << array[i].sumOFPoints() << endl;
cout <<
"_____________________________________________________________________
________________________________________" << endl;
}
}
int best = 0; //global variable for storing max points from a
best assignment set
int indexOfBest = 0; //global variable for storing best
assignment set index
void DisplayTime()//display only those assignment sets which can
be done in max 15 hours
{
cout << "********************Sets of Assignment done within
15 hours**********************" << endl;
cout << "SUSBETS OF ASSIGNMENTS: " << "\t\t\t\t\t" << "TIME
CONSUMED " << "\t\t\t" << "POINTS" << endl;
cout <<
"_____________________________________________________________________
________________________________________" << endl;
for (int i = 0;i < N;i++)
{
int sum = array[i].sumOFTime();
if (sum <= 15)
{
cout << "{ ";
array[i].Display();
cout << " }" << "\t\t\t\t\t\t\t\t\t" <<
array[i].time << "\t\t\t" << array[i].sumOFPoints() << endl;
cout <<
"_____________________________________________________________________
________________________________________" << endl;
}
Best(i);//calculate the assignment set with maximum
points and stores its index
}
char input;
cout << "Enter Y/y" << endl;
cin >> input;
if (input == 'Y' || input == 'y')
{
system("cls");
}
cout << "Best assignment set to be done within 15 hours is:
"<<endl;
cout << "{ ";
array[indexOfBest].Display();
cout << " }" << "\t\t\t\t\t\t\t\t\t" <<
array[indexOfBest].time<<" hours" << "\t\t\t" <<
array[indexOfBest].points<<" points" << endl;
cout <<
"_____________________________________________________________________
________________________________________" << endl;
}
void Best(int index)//giving best points and best index
{
if (best < array[index].points)
{
best = array[index].points;
indexOfBest = index;
}
}
};
void CreateSubsets()
{
char assignment[] = { 'A','B' ,'C' ,'D','E' ,'F' ,'G' };
int value[] = { 7,9,5,12,14,6,12 };
int time[] = { 3,4,2,6,7,3,15 };
Array a;
int count = pow(2, 7);
Linkedlist* arr;
arr = new Linkedlist[count];
for (int i = 0;i < count;i++)
{
Linkedlist list;
list.head = NULL;
for (int j = 0;j < 7;j++)
{
if ((i & (1 << j)) > 0)
{
list.Insert_end(assignment[j], value[j],
time[j]);
}
}
arr[i] = list;
}
a.setValue(arr, count);//setting an array of linkedlist
/*a.DisplayArray()*/;//display all posible subsets
a.DisplayTime();//display subsets done within 15 hours
}
int main()
{
CreateSubsets();
return 0;
}