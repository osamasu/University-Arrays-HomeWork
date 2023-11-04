#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string StudentFileName = "StudentsInfo.txt";

enum enHomeWorkList { HomeWork_1 = 1, HomeWork_2, HomwWork_3, HomwWork_4, HomeWork_5, HomeWork_6, HomeWork_7 };

enum enCalculationOperator { Addition = 1, Subtract, Multiply, Divine };

void StudentMenu(void);

string Tabs(short NumberOfTabs) {

	string OrderedTabs = "";

	for (short i = 1; i <= NumberOfTabs; i++)
		OrderedTabs += "\t";

	return OrderedTabs;
}

void FillArrayWithOrderedNumbers(short arr1[10], short arrLength) {

	short Counter = 0;

	for (short i = 0; i < arrLength; i++) {

		arr1[i] = ++Counter;
	}
}

void Multi2ArrToAnotherArray(short arr1[10], short arr2[10], short MultiSum[10], short arrLength) {


	for (short i = 0; i < arrLength; i++) {

		MultiSum[i] = arr1[i] * arr2[i];
	}

}

int GetRandomNumber(int From, int To)
{
	return  rand() % (To - From + 1) + From;
}

int ReadNumber(string Message) {

	int Number = 0;
	cout << Message;

	cin >> Number;


	while (cin.fail()) {

		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << " \n|Be Sure To Enter A Number ~" + Message;
		cin >> Number;

	}

	return Number;
}

void ResetScreen() {

	system("color 0F");
	system("cls");
}

char DoUserNeed_ToPlayAgain() {
	char PlayAgain;
	cout << "Press [Y] To Play Again! | Or Press Any Key To Finish |~";
	cin >> PlayAgain;

	return PlayAgain;
}

short ReadNumber_InRange_short_Ver(string Message, short From, short To) {

	short Number = 0;
	cout << Message;

	cin >> Number;


	while (cin.fail() || (Number<From || Number>To)) {

		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		printf("\n|Be Sure To Enter A Number Between [ %d and %d ] ~", From, To);
		cout << Message;
		cin >> Number;

	}

	return Number;
}

void FillArray_WithRandomNumbers(short Array[100], short& arrLength)
{
	arrLength =ReadNumber_InRange_short_Ver("How Many Elements Do You Want ,From [ 1 to 100 ] ?    |~ ", 1, 100);

	for (int i = 0; i < arrLength; i++)
	{
		Array[i] = GetRandomNumber(1, 100);
	}
}

void FillArray_WithRandomNumbers_WithoutRead(short Array[100], short arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{
		Array[i] = GetRandomNumber(1, 100);
	}
}

void PrintArray(short Arr[], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

void Sum2Arrays(short SourceArray[100], short Source2Array[100], short SumArray[100], short& arrLength) {

	for (short i = 0; i < arrLength; i++) {
		SumArray[i] = (SourceArray[i] + Source2Array[i]);
	}
}

short Get_MaxiumumNumber_InArray(short arr[100], short& arrLength) {

	short Number = arr[0];
	for (short i = 0; i < arrLength; i++) {

		if (Number < arr[i])
			Number = arr[i];
	}

	return Number;
}

short Get_LowestNumber_InArray(short arr[100], short& arrLength) {

	short Number = arr[0];
	for (short i = 0; i < arrLength; i++) {

		if (Number > arr[i])
			Number = arr[i];

	}

	return Number;
}

void Swap(short& FirstNumber, short& SecondNumber)
{
	int Temp = FirstNumber;
	FirstNumber = SecondNumber;
	SecondNumber = Temp;
}

void Run_HomeWork1() {

	short SumedArray[100]; short arr2[100]; short arr[100]; short arrLength;

	FillArray_WithRandomNumbers(arr, arrLength);
	cout << "\nArray 1  =  "; PrintArray(arr, arrLength); cout << endl;

	FillArray_WithRandomNumbers_WithoutRead(arr2, arrLength);
	cout << "Array 2  =  "; PrintArray(arr2, arrLength);  cout << endl;

	Sum2Arrays(arr, arr2, SumedArray, arrLength);


	cout << "Sum Array  =  "; PrintArray(SumedArray, arrLength);

}

void Run_HomeWork2() {

	short arr[100]; short arrLength;

	FillArray_WithRandomNumbers(arr, arrLength);
	cout << "\nArray Elements : "; PrintArray(arr, arrLength);


	cout << "\nBiggest Number Is : " << Get_MaxiumumNumber_InArray(arr, arrLength); cout << endl;

	cout << "\nLowest Number is : " << Get_LowestNumber_InArray(arr, arrLength) << endl;

}

void Run_HomeWork3() {

	short arr[100]; short arrLength;

	FillArray_WithRandomNumbers(arr, arrLength);

	cout << "\nBefore Swaping : "; PrintArray(arr, arrLength); cout << endl;

	Swap(arr[0], arr[arrLength - 1]);

	cout << "After Swaping : "; PrintArray(arr, arrLength);
}

void Run_HomeWork6() {

	short arr[10]; short arr2[10];

	FillArray_WithRandomNumbers_WithoutRead(arr, 10);
	FillArray_WithRandomNumbers_WithoutRead(arr2, 10);

	short arrMulti[10];
	Multi2ArrToAnotherArray(arr, arr2, arrMulti, 10);

	cout << "Array 1 :"; PrintArray(arr, 10); cout << endl;
	cout << "Array 2 :"; PrintArray(arr2, 10); cout << endl;


	cout << "Array Sum :"; PrintArray(arrMulti, 10);

}

void OperatorsListMenu() {
	cout << "___________________________________________" << endl;
	cout << "|                                         |" << endl;
	cout << "|   O p e r a t o r s    M e n u          |" << endl;
	cout << "|_________________________________________|" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "  [ 1 ] :| A D D I T I O N A L  { + }    |" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "  [ 2 ] :| S U B T R A C T      { - }    |" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "  [ 3 ] :| M U L T I P L Y      { * }    |" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "  [ 4 ] :| D I V I N E          { / }    |" << endl;
	cout << "|_________________________________________|" << endl;
}

float Calculater(enCalculationOperator CalculationOp) {

	float FirstNumber = ReadNumber("Please , Enter The First Number   | "); cout << endl;
	float SecondNumber = ReadNumber("Please , Enter The Second Number   | "); cout << endl;

	switch (CalculationOp)
	{
	case Addition:
		return (FirstNumber + SecondNumber);

	case Subtract:
		return (FirstNumber - SecondNumber);

	case Multiply:
		return (FirstNumber * SecondNumber);

	case Divine:
		return (FirstNumber / SecondNumber);
	}
}

void Run_HomeWork4() {

	OperatorsListMenu();

	enCalculationOperator CalculationOperator = (enCalculationOperator)ReadNumber_InRange_short_Ver("\n\tEnter The Operator Type :  ", 1, 4);
	ResetScreen();

	
	cout << "Sir , Your Calculation Result Are = " << Calculater(CalculationOperator);
}

void HomeWorksList() {

	cout <<Tabs(11) << "    Developed By [Thabit Osama]";
	cout << "\n\n_____________" << "__________________________________________________________________________\n";
	cout << "|            " << "|       HW Number      |                 HomeWork Subject                |\n";
	cout << "|            " << "|----------------------|-------------------------------------------------|\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 1); cout << right << setw(5); cout << '|' << setw(49) << "Sum Two Arrays To Third One" << '|' << endl;
	cout << "|   Arrays   " << "|----------------------|-------------------------------------------------|\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 2); cout << right << setw(5); cout << '|' << setw(49) << "Find Biggest & Lowest Number In Array" << '|' << endl;
	cout << "|            " << "|----------------------|-------------------------------------------------|\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 3); cout << right << setw(5); cout << '|' << setw(49) << "Swaping Upper & Lower Index Number In Array" << '|' << endl;
	cout << "|____________" << "|______________________|_________________________________________________|\n";
	cout << "|            " << "|                      |                                                 |\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 4); cout << right << setw(5); cout << '|' << setw(49) << "Calculater" << '|' << endl;
	cout << "|  Functions " << "|----------------------|-------------------------------------------------|\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 5); cout << right << setw(5); cout << '|' << setw(49) << "Students Info" << '|' << endl;
	cout << "|____________" << "|______________________|_________________________________________________|\n";
	cout << "|            " << "|                      |                                                 |\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 6); cout <<right<< setw(5); cout << '|' << setw(49) << "Multi 2 Arrays To Third One" << '|' << endl;
	cout << "|   OTHERS   " << "|----------------------|-------------------------------------------------|\n";
	cout << "|            " << '|' << setw(5); printf("   HomeWork  [ %d ]", 7); cout << right << setw(5); cout << '|' << setw(49) << "Convert Number To Text" << '|' << endl;
	cout << "|____________" << "|______________________|_________________________________________________|\n\n";

}

vector <string> SplitString(string,string);

string NumberToText(int Number) {


	if (Number < 0) {

		return "Mainus " + NumberToText(Number * -1);
	}

	if (Number == 0) {
		return "";
	}

	if (Number >= 1 && Number <= 19) {

		string arr[] = { "" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" , "Ten" ,
			             "Eleven" , "Twelve" , "Thireteen" , "Fourteen" , "Fivteen" , "Sixteen" , "Seventeen" , "Eighteen" , "Nineteen" };

		return arr[Number] += " ";
	}

	if (Number >= 20 && Number <= 99) {

		string arr[] = { "" ,"", "Twenty" , "Thiry" , "Fourty" , "Fivety" , "Sixty" , "Seventy" , "Eighty" , "Ninety"};

		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number > 100 && Number < 200) {

		return "One Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999) {

		return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 1999) {

		return "One Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999) {

		return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999) {

		return "One Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 99999999) {

		return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999) {

		return "One Billion" + NumberToText(Number % 1000000000);
	}

	else {
		return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
	}
}

void Run_HomeWork7() {

	system("cls");

	cout << " ------------------------------------\n";
	cout << "             Number To Text          \n";
	cout << " ------------------------------------\n\n";


	int Number = ReadNumber("Please , Enter A Number ?  | ");

	cout << "\n\n";

	printf("The Number (%d) After Convert To Text =  ", Number);
	cout << "{   " << NumberToText(Number) << "   }\n\n";

}

void Run_SelectiveHomeWork(enHomeWorkList SelectiveHomeWork) {

	ResetScreen();

	switch (SelectiveHomeWork)
	{
	case enHomeWorkList::HomeWork_1:
		Run_HomeWork1();
		break;

	case enHomeWorkList::HomeWork_2:
		Run_HomeWork2();
		break;

	case enHomeWorkList::HomwWork_3:
		Run_HomeWork3();
		break;

	case enHomeWorkList::HomwWork_4:
		Run_HomeWork4();
		break;

	case enHomeWorkList::HomeWork_5:
		StudentMenu();
		break;

	case enHomeWorkList::HomeWork_6:
		Run_HomeWork6();
		break;

	case enHomeWorkList::HomeWork_7:
		Run_HomeWork7();
		break;

	}
}

void Run_SimpleHW_Project() {

	srand((unsigned)time(NULL));

	char PlayAgain;
	do {
		ResetScreen();
		HomeWorksList();

		Run_SelectiveHomeWork((enHomeWorkList)ReadNumber_InRange_short_Ver("Please, Enter Number Of HomeWork |~", 1, 7));
		cout << "\n\n";
		PlayAgain = DoUserNeed_ToPlayAgain();

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
	
}

float ReadNumber_InRange_float_Ver(string Message, float From, float To) {

	float Number = 0;
	cout << Message;

	cin >> Number;


	while (cin.fail() || (Number<From || Number>To)) {

		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		printf("\n|Be Sure To Enter A Number Between [ %.3f and %.3f ] ~", From, To);
		cout << Message;
		cin >> Number;

	}

	return Number;
}

string ReadString(string Message)
{
	string Word = "";

	cout << Message;
	getline(cin, Word);

	return Word;
}

char ReadChar(string Message) {

	char Character;
	cout << Message;

	cin >> Character;
	return Character;
}

struct Str_StudentGrades {

	string Student_PrimaryNumber;
	string StudentName;

	float Math;
	float Quran;
	float Physics;
	float Islamic;
	float History;

	float SumGrades;
	float Average;

	bool MarkToDelete = false;
};

float CalcGradesSum(Str_StudentGrades StudentGrades) {

	return ((StudentGrades.History + StudentGrades.Islamic + StudentGrades.Physics + StudentGrades.Math + StudentGrades.Quran));
}

float CalcAverage(Str_StudentGrades StudentGrade) {

	return (CalcGradesSum(StudentGrade) / 5);

}

Str_StudentGrades ConvertLineToRecord(string LineOfRecord) {

	vector <string> vStudents = SplitString(LineOfRecord,"#//#");
	Str_StudentGrades StudentData;

	StudentData.Student_PrimaryNumber = vStudents[0];
	StudentData.StudentName = vStudents[1];

	StudentData.Math = stof(vStudents[2]);
	StudentData.Quran = stof(vStudents[3]);
	StudentData.Physics = stof(vStudents[4]);
	StudentData.Islamic = stof(vStudents[5]);
	StudentData.History = stof(vStudents[6]);

	StudentData.SumGrades = stof(vStudents[7]);
	StudentData.Average = stof(vStudents[8]);

	return StudentData;
}

vector <Str_StudentGrades> LoadStudentsFromFile(string FileName) {

	vector <Str_StudentGrades> vStudents;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		string Line;

		while (getline(MyFile, Line)) {

			vStudents.push_back(ConvertLineToRecord(Line));
		}

		MyFile.close();
	}
	return vStudents;
}


bool IsThisAccountNumberExist(string AccountNumber) {

	vector <Str_StudentGrades> vStudents = LoadStudentsFromFile(StudentFileName);

	for (Str_StudentGrades &Student : vStudents) {

		if (Student.Student_PrimaryNumber == AccountNumber)
			return true;
	}
	return false;
}

Str_StudentGrades ReadStudentInfo(string Primary_StudentNumber) {

	Str_StudentGrades StudentGrades;


	StudentGrades.Student_PrimaryNumber = Primary_StudentNumber;

	while (IsThisAccountNumberExist(StudentGrades.Student_PrimaryNumber)) {

		cout << "This Number Are Already Exist , Enter Another Student Primary Serial ?  ";
		getline(cin >> ws, StudentGrades.Student_PrimaryNumber); cout << endl;
	}

	cout << "Please , Enter Your Name ?  | ";
	getline( cin >> ws,StudentGrades.StudentName); cout << endl;

	StudentGrades.History = ReadNumber_InRange_float_Ver("Please , Enter Your History Mark ?  |", 0, 100);  cout << endl;

	StudentGrades.Islamic = ReadNumber_InRange_float_Ver("Please , Enter Your Islamic Mark ?  |", 0, 100); cout << endl;

	StudentGrades.Math = ReadNumber_InRange_float_Ver("Please , Enter Your Math Mark ?  |", 0, 100); cout << endl;

	StudentGrades.Physics = ReadNumber_InRange_float_Ver("Please , Enter Your Physics Mark ?  |", 0, 100); cout << endl;

	StudentGrades.Quran = ReadNumber_InRange_float_Ver("Please , Enter Your Quran Mark ?  |", 0, 100);

	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	StudentGrades.SumGrades = CalcGradesSum(StudentGrades);

	StudentGrades.Average = CalcAverage(StudentGrades);


	return StudentGrades;
}

bool IsSuccess(Str_StudentGrades StudentData) {

	return (StudentData.History >= 50 && StudentData.Islamic >= 50 && StudentData.Math >= 50 && StudentData.Physics >= 50 && StudentData.Quran);
}

void PrintStudentData(Str_StudentGrades StudentData) {

	cout << "| " << left << setw(15) <<StudentData.Student_PrimaryNumber;
	cout << "| " << left << setw(30) << StudentData.StudentName;
	cout << "| " << left << setw(8) << StudentData.Math;
	cout << "| " << left << setw(8) << StudentData.Quran;
	cout << "| " << left << setw(10) << StudentData.Physics;
	cout << "| " << left << setw(10) << StudentData.Islamic;
	cout << "| " << left << setw(10) << StudentData.History;
	cout << "| " << left << setw(15) << StudentData.SumGrades;

	cout << "| " << left << setw(15);
	IsSuccess(StudentData) ? cout << StudentData.Average : cout << "Fail";

}

void Show_AllStudents(vector <Str_StudentGrades>& vSudentsData) {
	
	system("cls");

	cout << "\n\t\t\t\t\t\t\tStudents List (" << vSudentsData.size() << ") Student(s).";
	cout << "\n_______________________________________________________";
	cout << "________________________________________________________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Student Number";
	cout << "| " << left << setw(30) << "Student Name";
	cout << "| " << left << setw(8) << "Math";
	cout << "| " << left << setw(8) << "Quran";
	cout << "| " << left << setw(10) << "Physics";
	cout << "| " << left << setw(10) << "Islamic";
	cout << "| " << left << setw(10) << "History";
	cout << "| " << left << setw(15) << "Total Grades";
	cout << "| " << left << setw(15) << "Average { % }";
	cout << "\n_______________________________________________________";
	cout << "________________________________________________________________________________________\n" << endl;

	if (vSudentsData.empty()) {

		cout << "\t\t\t  S T U D E N T S   D A T A  I S   N O T   F O U N D !";
	}

	else {

		for (Str_StudentGrades& Student : vSudentsData) {

			PrintStudentData(Student); cout << endl;
		}
	}
	cout << "\n_______________________________________________________";
	cout << "________________________________________________________________________________________\n" << endl;
}

string ConvertDataToLine(Str_StudentGrades & Student , string Seperator = "#//#") {

	string DataLine;

	DataLine = Student.Student_PrimaryNumber + Seperator;
	DataLine += Student.StudentName + Seperator;

	DataLine += to_string(Student.Math) + Seperator;
	DataLine += to_string(Student.Quran) + Seperator;
	DataLine += to_string(Student.Physics) + Seperator;
	DataLine += to_string(Student.Islamic) + Seperator;
	DataLine += to_string(Student.History) + Seperator;

	DataLine += to_string(Student.SumGrades) + Seperator;
	DataLine += to_string(Student.Average);

	return DataLine;
}

void AddDataLineToFile(string FileName,string DataLine) {

	fstream MyFile;

	MyFile.open(FileName, ios::out || ios::app);

	if (MyFile.is_open()) {

		MyFile << DataLine << endl;
		MyFile.close();
	}
}

void SaveStudentToFile(string FileName, vector <Str_StudentGrades> &vStudents) {

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		string DataLine;

		for (Str_StudentGrades& Student : vStudents) {

			if (!Student.MarkToDelete) {

				DataLine = ConvertDataToLine(Student);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}
}

void ReadStudentsInfo(vector <Str_StudentGrades>& vStudent) {

	Str_StudentGrades Student;

	string PrimaryStudent;


	cout << "Please , Enter Student Primary Serial ?  ";
	getline(cin >> ws, Student.Student_PrimaryNumber); cout << endl;

	Student = ReadStudentInfo(Student.Student_PrimaryNumber);
	vStudent.push_back(Student);

	SaveStudentToFile(StudentFileName, vStudent);
}

void AddStudents(vector <Str_StudentGrades>& vStudent) {

	ReadStudentsInfo(vStudent);
	
}

vector <string> SplitString(string S1 , string Seperator = "#//#") {

	short Pos;
	string sWord;
	vector <string> vWord;

	while ((Pos = S1.find(Seperator)) != std::string::npos) {

		sWord = S1.substr(0, Pos);

		if (sWord != "") {
			vWord.push_back(sWord);
		}
		S1.erase(0, Pos + Seperator.length());
	}
	if (S1 != "") {
		vWord.push_back(S1);
	}

	return vWord;
}

enum enPerformStudentMenu { enShow_AllStudents = 1 , enAddStudent , enDeleteStudent , enBack_FromStudentMenu};

void BackToStudentMenu() {

	cout << "Press Any Key To Back To Previous Menu..."; system("pause>0");
	StudentMenu();
}

void AddStudent(vector <Str_StudentGrades>& vStudents) {

	system("cls");

	cout << " ------------------------------------\n";
	cout << "           Add Student Screen        \n";
	cout << " ------------------------------------\n\n";

	ReadStudentsInfo(vStudents);
}

bool FindStudent(vector <Str_StudentGrades>& vStudents,string StudentPrimaryNumber, Str_StudentGrades &Student) {

	for (Str_StudentGrades& Stu : vStudents) {

		if (Stu.Student_PrimaryNumber == StudentPrimaryNumber) {

			Student = Stu;
			return true;
		}
	}
	return false;
}

void PrintStudentCard(Str_StudentGrades& Student) {

	cout << "\nStudent Info :- \n";

	cout << " _____________________________________________\n";
	cout << "|                                             |\n";
	cout << "|  Student Number : " << setw(26) << left << Student.Student_PrimaryNumber   << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Student Name   : " << setw(26) << Student.StudentName   << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Math : " << setw(36) << Student.Math   << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Quran : " << setw(35) << Student.Quran   << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Physics : " << setw(33) << Student.Physics << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Islamic : " << setw(33) << Student.Islamic << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  History : " << setw(33) << Student.History  << '|' << endl;
	cout << "|________________________" << setw(22) << right << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Total Marks : " << setw(29) << left << Student.SumGrades  << '|' << endl;
	cout << "|                                             |\n";
	cout << "|  Average : " << setw(33) << Student.Average  << '|' << endl;
	cout << "|_____________________________________________|\n\n\n";

}

void MarkStudentToDelete(string StudentPrimaryNumber,vector <Str_StudentGrades>& vStudents) {

	for (Str_StudentGrades& Str : vStudents) {

		if (Str.Student_PrimaryNumber == StudentPrimaryNumber) {
			
			Str.MarkToDelete = true;
			break;
		}
	}
}

bool DeleteStudent(vector <Str_StudentGrades>& vStudents) {

	string Student_PrimaryNumber; Str_StudentGrades Student;

	cout << "Please , Enter Student Primary Serial ?  ";
	getline(cin >> ws, Student_PrimaryNumber); cout << endl;

	if (!FindStudent(vStudents, Student_PrimaryNumber, Student)) {

		cout << "\n\t T H E   S T U D E N T   IS   N O T   F O U N D ! \n\n\t";
		return false;
	}

	PrintStudentCard(Student);
	char SureToPerform = ReadChar("Are You Sure To Keep Performing This Process { Y / N } ?  | ");

	if (toupper(SureToPerform) == 'Y') {

		MarkStudentToDelete(Student_PrimaryNumber, vStudents);
		SaveStudentToFile(StudentFileName, vStudents);

		//Update - Refresh Data 
		vStudents = LoadStudentsFromFile(StudentFileName);
		printf("\n\n\tStudent Was Deleted Successfully...\n\n");
	}
}

void Feature_DeleteStudent(vector <Str_StudentGrades>& vStudents) {

	system("cls");

	cout << " ------------------------------------\n";
	cout << "           Add Student Screen        \n";
	cout << " ------------------------------------\n\n";

	DeleteStudent(vStudents);
}

void BackToMainMenu_ProjectsMenu() {

	Run_SimpleHW_Project();
}

void PerformStudentMenu(enPerformStudentMenu StudentMenuOption) {

	vector <Str_StudentGrades> vStudents = LoadStudentsFromFile(StudentFileName);

	switch (StudentMenuOption)
	{
	case enShow_AllStudents:
		Show_AllStudents(vStudents);
		BackToStudentMenu();
		break;

	case enAddStudent:
		AddStudent(vStudents);
		BackToStudentMenu();
		break;
	
	case enDeleteStudent:
		Feature_DeleteStudent(vStudents);
		BackToStudentMenu();
		break;

	case enBack_FromStudentMenu:
		BackToMainMenu_ProjectsMenu();
	}
}

enPerformStudentMenu ReadStudentMenuOption() {

	return (enPerformStudentMenu)ReadNumber_InRange_short_Ver("\nPlease, Enter Your Choice From [1] To [4] |  ",1,4);
}

void CreateFile(string FileName) {

	fstream MyFile;

	MyFile.open(FileName,  ios::app);

	if (MyFile.is_open()) {

		MyFile.close();
	}
}

void StudentMenu()
{
	system("cls");

	cout << Tabs(11) << "    Developed By [Thabit Osama]";

	cout << "\n\n___________________________________________" << endl;
	cout << "|                                         |" << endl;
	cout << "|       S t u d e n t    M e n u          |" << endl;
	cout << "|_________________________________________|" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "     [ 1 ] :| Show All Students          |" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "     [ 2 ] :| Add Student                |" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "     [ 3 ] :| Delete Student             |" << endl;
	cout << "|                                         |" << endl;
	cout << '|' << "     [ 4 ] :| B A C K                    |" << endl;
	cout << "|_________________________________________|" << endl;

	PerformStudentMenu(ReadStudentMenuOption());
}

void main(void) {
	
   Run_SimpleHW_Project();
}