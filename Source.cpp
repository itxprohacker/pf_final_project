#include<iostream>
#include<fstream>
using namespace std;
void displayData(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	for (int i = 0; i<size; i++)
	{
		cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;

	}
}
float calculate_WP(int midtermMarks, int finaltermMarks)
{
	float weightPercentage = 0.0;
	weightPercentage = (midtermMarks*0.8) + (finaltermMarks*0.6);
	return weightPercentage;
}
char calculate_grade(float weight_percentage)
{
	char grade = '0';
	if (weight_percentage<50)
	{
		grade = 'F';
		return grade;
	}
	else if (weight_percentage >= 50 && weight_percentage<60)
	{
		grade = 'D';
		return grade;
	}
	else if (weight_percentage >= 60 && weight_percentage<72)
	{
		grade = 'C';
		return grade;
	}
	else if (weight_percentage >= 72 && weight_percentage<85)
	{
		grade = 'B';
		return grade;
	}
	else
	{
		grade = 'A';
		return grade;
	}


}
void copy_arrays_char(char *old_array, char *new_array, int size)
{
	for (int i = 0; i<size; i++)
	{
		new_array[i] = old_array[i];
	}
}
char *grow_char(char *old_array, int size, char value)
{
	char *new_array = new char(size + 1);
	copy_arrays_char(old_array, new_array, size);
	delete[]old_array;
	new_array[size] = value;
	return new_array;
}
void copy_arrays_float(float *old_array, float *new_array, int size)
{
	for (int i = 0; i<size; i++)
	{
		new_array[i] = old_array[i];
	}
}
float *grow_float(float *old_array, int size, float value)
{
	float *new_array = new float(size + 1);
	copy_arrays_float(old_array, new_array, size);
	delete[]old_array;
	new_array[size] = value;
	return new_array;
}
void copy_arrays(int *old_array, int *new_array, int size)
{
	for (int i = 0; i<size; i++)
	{
		new_array[i] = old_array[i];
	}
}
int *grow(int *old_array, int size, int value)
{
	int *new_array = new int(size + 1);
	copy_arrays(old_array, new_array, size);
	delete[]old_array;
	new_array[size] = value;
	return new_array;
}
bool add_student_data(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	int roll_number = 0;
	float midterm_marks = 0.0;
	float finaltermMarks = 0.0;
	float weight_percentage = 0.0;
	char grade_obtained;
	cout << "Add student Student Roll Number:";
	cin >> roll_number;
	bool check = true;
	for (int i = 0; i<size; i++)
	{
		if (rollNumber[i] == roll_number)
		{
			check = false;
			break;
		}
	}
	if (check == false)
	{
		cout << "Student Roll Number already exists\n";
		return false;
	}
	else
	{
		cout << "Enter the Midterm marks(out of 50):";
		cin >> midterm_marks;
		cout << "Enter the Finalterm Marks(out of 100):";
		cin >> finaltermMarks;
		weight_percentage = calculate_WP(midterm_marks, finaltermMarks);
		grade_obtained = calculate_grade(weight_percentage);
		if (size >= 20)
		{
			rollNumber = grow(rollNumber, size, roll_number);
			midtermMarks = grow_float(midtermMarks, size, midterm_marks);
			finalMarks = grow_float(finalMarks, size, finaltermMarks);
			weightPercentage = grow_float(weightPercentage, size, weight_percentage);
			grades = grow_char(grades, size, grade_obtained);
			size++;
			cout << "Student data added successfully\n";
		}
		else
		{
			rollNumber[size] = roll_number;
			midtermMarks[size] = midterm_marks;
			finalMarks[size] = finaltermMarks;
			grades[size] = grade_obtained;
			weightPercentage[size] = weight_percentage;
			size++;
			cout << "Student data added successfully\n";
		}

		for (int i = 0; i<size; i++)
		{
			cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;

		}
		return true;
	}
}
void sort_ascend_grades(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (grades[z]<grades[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_decend_grades(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (grades[z]>grades[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_ascend_weightpercent(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (weightPercentage[z]>weightPercentage[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_decend_weightpercent(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (weightPercentage[z]<weightPercentage[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_decend_finalterm(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (finalMarks[z]<finalMarks[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_ascend_finalterm(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (finalMarks[z]>finalMarks[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_ascend_midterm(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (midtermMarks[z]>midtermMarks[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_decend_midterm(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (midtermMarks[z]<midtermMarks[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_decend_rollID(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (rollNumber[z]<rollNumber[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void sort_ascend_rollID(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	if (size == 0)
	{
		cout << "No data is found....Enter students Data to sort\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int z = 0; z<size - 1; z++)
			{
				int temp = 0;
				float temp1 = 0;
				char temp2;
				if (rollNumber[z]>rollNumber[z + 1])
				{
					temp = rollNumber[z];
					rollNumber[z] = rollNumber[z + 1];
					rollNumber[z + 1] = temp;
					temp1 = midtermMarks[z];
					midtermMarks[z] = midtermMarks[z + 1];
					midtermMarks[z + 1] = temp1;
					temp1 = finalMarks[z];
					finalMarks[z] = finalMarks[z + 1];
					finalMarks[z + 1] = temp1;
					temp1 = weightPercentage[z];
					weightPercentage[z] = weightPercentage[z + 1];
					weightPercentage[z + 1] = temp1;
					temp2 = grades[z];
					grades[z] = grades[z + 1];
					grades[z + 1] = temp2;
				}
			}
		}
	}
}
void greater_X_decend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	float wp_X = 0.0;
	cout << "Enter the any X weight percentage:";
	cin >> wp_X;
	sort_decend_weightpercent(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
	for (int i = 0; i<size; i++)
	{
		if (weightPercentage[i]>wp_X)
		{
			cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;
		}
	}
}
void greater_X_ascend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	float wp_X = 0.0;
	cout << "Enter the any X weight percentage:";
	cin >> wp_X;
	sort_ascend_weightpercent(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
	for (int i = 0; i<size; i++)
	{
		if (weightPercentage[i]>wp_X)
		{
			cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;
		}
	}
}
void less_wpX_decend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	int wpX = 0;
	cout << "Enter the any X weight percentage:";
	cin >> wpX;
	sort_decend_weightpercent(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
	for (int i = 0; i<size; i++)
	{
		if (weightPercentage[i] <= wpX)
		{
			cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;

		}
	}

}
void less_wpX_ascend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	int wpX = 0;
	cout << "Enter the any X weight percentage:";
	cin >> wpX;
	sort_ascend_weightpercent(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
	for (int i = 0; i<size; i++)
	{
		if (weightPercentage[i] <= wpX)
		{
			cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;

		}
	}

}


void greater_GradeX_decend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	char grade_X = '@';
	cout << "Enter the any X grade(Capital Letter):";
	cin >> grade_X;
	if (grade_X != 'A' && grade_X != 'B' && grade_X != 'C' && grade_X != 'D' && grade_X != 'F')
	{
		cout << "The grade you entered is valid\n";
	}
	else if (grade_X == 'A')
	{
		cout << "No grade is greater than A, Try entering any other grade..!\n";
	}
	else
	{
		sort_decend_grades(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		for (int i = 0; i<size; i++)
		{
			if (grades[i]<grade_X)
			{
				cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;
			}
		}
	}
}
void greater_GradeX_ascend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	char grade_X = '@';
	cout << "Enter the any X grade(Capital Letter):";
	cin >> grade_X;
	if (grade_X != 'A' && grade_X != 'B' && grade_X != 'C' && grade_X != 'D' && grade_X != 'F')
	{
		cout << "The grade you entered is invalid\n";
	}
	else if (grade_X == 'A')
	{
		cout << "No grade is greater than A, Try entering any other grade..!\n";
	}
	else
	{
		sort_ascend_grades(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		for (int i = 0; i<size; i++)
		{
			if (grades[i]<grade_X)
			{
				cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;
			}
		}
	}
}


void less_GradeX_decend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	char grade_X = '@';
	cout << "Enter the any X grade(Capital Letter):";
	cin >> grade_X;
	if (grade_X != 'A' && grade_X != 'B' && grade_X != 'C' && grade_X != 'D' && grade_X != 'F')
	{
		cout << "The grade you entered is invalid\n";
	}
	else if (grade_X == 'A')
	{
		cout << "No grade is greater than A, Try entering any other grade..!\n";
	}
	else
	{
		sort_decend_grades(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		for (int i = 0; i<size; i++)
		{
			if (grades[i]>grade_X)
			{
				cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;
			}
		}
	}
}
void less_GradeX_ascend(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	char grade_X = '@';
	cout << "Enter the any X grade(Capital Letter):";
	cin >> grade_X;
	if (grade_X != 'A' && grade_X != 'B' && grade_X != 'C' && grade_X != 'D' && grade_X != 'F')
	{
		cout << "The grade you entered is invalid\n";
	}
	else if (grade_X == 'A')
	{
		cout << "No grade is greater than A, Try entering any other grade..!\n";
	}
	else
	{
		sort_ascend_grades(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		for (int i = 0; i<size; i++)
		{
			if (grades[i]>grade_X)
			{
				cout << "Roll No: " << rollNumber[i] << "   Midterm Marks: " << midtermMarks[i] << "   Final Marks: " << finalMarks[i] << "   WP: " << weightPercentage[i] << "   Grade: " << grades[i] << endl;
			}
		}
	}
}
void count_less_WP(float *weightPercentage, int size)
{
	float wp_X = 0.0;
	int count = 0;
	cout << "Enter X weight percentage to count students:";
	cin >> wp_X;
	for (int i = 0; i<size; i++)
	{
		if (weightPercentage[i]<wp_X)
		{
			count++;
		}
	}
	cout << "The number of students less than " << wp_X << " weight percentage:" << count << endl;
}
void count_greater_WP(float *weightPercentage, int size)
{
	float wp_X = 0.0;
	int count = 0;
	cout << "Enter X weight percentage to count students:";
	cin >> wp_X;
	for (int i = 0; i<size; i++)
	{
		if (weightPercentage[i]>wp_X)
		{
			count++;
		}
	}
	cout << "The number of students greater than " << wp_X << " weight percentage:" << count << endl;
}
bool backup_Data(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	int size1 = 0;
	cout << "Enter the size of the file you want to store data into:";
	cin >> size1;
	char *filename = new char[size1];
	cout << "Enter the filename you want to store data (Max " << size1 << " characters):";
	cin >> filename;
	ofstream write;
	write.open(filename);
	if (!write.is_open())
	{
		cout << "Error...creating file\n";
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			write << rollNumber[i] << "           " << midtermMarks[i] << "           " << finalMarks[i] << "           " << weightPercentage[i] << "           " << grades[i] << endl;
		}
		cout << "Data backup successful....!\n";
		write.close();
	}
	delete[] filename;
	return true;
}
void restore_Data(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size, int &count)
{
	for (int i = 0; i<size; i++)
	{
		rollNumber[i] = { 0 };
		midtermMarks[i] = { 0.0 };
		finalMarks[i] = { 0.0 };
		weightPercentage[i] = { 0.0 };
		grades[i] = { '\0' };
	}

	int size1 = 0;
	cout << "Enter the size of file you want to restore from:";
	cin >> size1;
	char *filename = new char[size1]{'\0'};
	cout << "Enter the name of the file you want to restore data from:";
	cin >> filename;
	ifstream read;
	read.open(filename);
	if (!read.is_open())
	{
		cout << "Error reading file...Enter the name of the file in which backed up your data\n";
	}
	else
	{
		while (read >> rollNumber[count])
		{
			read >> midtermMarks[count];
			read >> finalMarks[count];
			read >> weightPercentage[count];
			read >> grades[count];
			count++;
		}
		read.close();
	}
	cout << "The data is restored successfully...!\n";
	delete[] filename;
}
bool delete_student(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	int roll_number = 0;
	cout << "Add student Student Roll Number to delete:";
	cin >> roll_number;
	int check = 0;
	for (int i = 0; i<size; i++)
	{
		if (rollNumber[i] == roll_number)
		{
			check = 1;
		}
	}
	if (check != 1)
	{
		cout << "Students roll number is invalid...try again!\n";
		return false;
	}
	else
	{
		int i = 0;
		for (; i<size; i++)
		{
			if (rollNumber[i] == roll_number)
			{
				break;
			}
		}
		for (int z = i; z<size; z++)
		{
			rollNumber[z] = rollNumber[z + 1];
			midtermMarks[z] = midtermMarks[z + 1];
			finalMarks[z] = finalMarks[z + 1];
			weightPercentage[z] = weightPercentage[z + 1];
			grades[z] = grades[z + 1];
		}
		cout << "Student deleted successfully!\n";
	}
	return true;
}
void mainMenuFunctions(int *rollNumber, float *midtermMarks, float *finalMarks, float *weightPercentage, char *grades, int size)
{
	char letter_termination = '0';
	int count = 0;
	bool flag = false;
	while (letter_termination = 'E' && letter_termination != 'e')
	{
		int key = 0;
		cout << "Select the option:";
		cin >> key;
		if (key == 1)
		{
			sort_ascend_rollID(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);

		}
		else if (key == 2)
		{
			sort_decend_rollID(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 3)
		{
			sort_ascend_midterm(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 4)
		{
			sort_decend_midterm(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 5)
		{
			sort_ascend_finalterm(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 6)
		{
			sort_decend_finalterm(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 7)
		{
			sort_ascend_weightpercent(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 8)
		{
			sort_decend_weightpercent(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 9)
		{
			sort_ascend_grades(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 10)
		{
			sort_decend_grades(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			displayData(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 11)
		{
			bool check_added = add_student_data(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			if (check_added == true)
			{
				size++;
			}

		}
		else if (key == 12)
		{
			bool check_added = delete_student(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
			if (check_added == true)
			{
				size--;
			}
		}
		else if (key == 13)
		{
			greater_X_decend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 14)
		{
			greater_X_ascend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 15)
		{
			less_wpX_decend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 16)
		{
			less_wpX_ascend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 17)
		{
			greater_GradeX_decend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 18)
		{
			greater_GradeX_ascend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 19)
		{
			less_GradeX_decend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 20)
		{
			less_GradeX_ascend(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 21)
		{
			count_less_WP(weightPercentage, size);
		}
		else if (key == 22)
		{
			count_greater_WP(weightPercentage, size);
		}
		else if (key == 23)
		{
			flag = backup_Data(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
		}
		else if (key == 24)
		{
			if (flag == false)
			{
				cout << "You didn't backup data...You must backup data to restore it!\n";
			}
			else
			{
				restore_Data(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size, count);
				size = count;
			}
		}
		else
		{
			cout << "ERROR.....invalid entry\n";
		}
		cout << "Do you want to continue:";
		cin >> letter_termination;

	}
}
void displayMenu()
{
	cout << "1. Sort and display all the records roll number wise in ascending order.\n";
	cout << "2. Sort and display all the records roll number wise in descending order.\n";
	cout << "3. Sort and display all records in ascending order based on marks in Midterm\n";
	cout << "4. Sort and display all records in descending order based on marks in Midterm\n";
	cout << "5. Sort and display all records in ascending order based on marks in Finalterm \n";
	cout << "6. Sort and display all records in descending order based on marks in Finalterm\n";
	cout << "7. Sort and display all records in ascending order based on weighted percentage\n";
	cout << "8. Sort and display all records in descending order based on weighted percentage\n";
	cout << "9. Sort and display all records in ascending order based on Grade\n";
	cout << "10.Sort and display all records in descending order based on Grade\n";
	cout << "11.Add a new entry of a student\n";
	cout << "12.Delete a student record based on roll number\n";
	cout << "13.Display record of all the students greater than X weighted percentage (in descending order with respect to WP). The value of X will be entered by the user\n";
	cout << "14.Display record of all the students greater than X weighted percentage (in ascending order with respect to WP). The value of X will be entered by the user\n";
	cout << "15.Display record of all the students less than or equal to X weighted percentage (in descending order with respect to WP). The value of X will be entered by the user\n";
	cout << "16.Display record of all the students less than or equal to X weighted percentage (in ascending order with respect to WP). The value of X will be entered by the user\n";
	cout << "17.Display record of all the students greater than X grade (in descending order with respect to grade). The value of X (character) will be entered by the user\n";
	cout << "18.Display record of all the students greater than X grade (in ascending order with respect to grade). The value of X (character) will be entered by the user\n";
	cout << "19.Display record of all the students less than or equal to X grade (in descending order with respect to grade). The value of X (character) will be entered by the user\n";
	cout << "20.Display record of all the students less than or equal to X grade (in ascending order with respect to grade). The value of X (character) will be entered by the user\n";
	cout << "21.Display total count of students out of 100 with WP less than equal to X. The value of X will be entered by the user\n";
	cout << "22.Display total count of students out of 100 with WP greater than equal to X. The value of X will be entered by the user\n";
	cout << "23.Backup the data: When this option is selected, all the data is written to a txt file in a 2d format\n";
}

int main()
{
	int *rollNumber = new int[20];
	float *midtermMarks = new float[20];
	float *finalMarks = new float[20];
	float *weightPercentage = new float[20];
	char *grades = new char[20];
	int size = 0;
	ifstream read;
	read.open("Project.txt");
	if (!read.is_open())
	{
		cout << "Error opening file";
	}
	else
	{
		while (read >> rollNumber[size])
		{
			read >> midtermMarks[size];
			read >> finalMarks[size];
			read >> weightPercentage[size];
			read >> grades[size];
			cout << rollNumber[size] << " 		   " << midtermMarks[size] << " 		   " << finalMarks[size] << " 		   " << weightPercentage[size] << " 		   " << grades[size] << endl;
			size++;
		}cout << endl;

		read.close();
	}
	displayMenu();
	mainMenuFunctions(rollNumber, midtermMarks, finalMarks, weightPercentage, grades, size);
	return 0;
}