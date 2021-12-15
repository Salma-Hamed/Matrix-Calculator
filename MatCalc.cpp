#include<iostream>
#include<string>
#include<sstream>
#include <cstdlib>
#include<complex>
using namespace std;
int main()
{
	string s1;
	string stringcomp;
	string character;
	float arr1[100][100] = { 0 };
	float arr2[100][100] = { 0 };
	complex<float> arr_complex_1[100][100];

	complex<float> multiply[100][100];
	cout << "Enter The First Matrix:\n";
	getline(cin, s1);

	cout << "Enter The operation (+, -, or *):\n";
	getline(cin, character);

	string s2;
	string stringcomp2;
	float arr3[100][100] = { 0 };
	float arr4[100][100] = { 0 };
	complex<float> arr_complex_2[100][100];

	cout << "Enter The Second Matrix:\n";
	getline(cin, s2);

	cout << "\n";
	if (character.length() > 1)
	{
		cout << "Error";
	}
	else
	{
		int rows1 = 0, cols1 = 0;
		// determining the number of rows in the first matrix
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == ';')
				rows1++;
		}
		rows1++;
		// determining the number of columns in the first matrix
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == ' ')
			{
				cols1++;
			}
			if (s1[i] == ';')
				break;
		}
		cols1++;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{
				if (s1[0] == '[')
				{
					int pos_space = s1.find(" ");
					stringcomp = s1.substr(1, pos_space - 1);
					if (s1.find(" ") < s1.find("+") && s1.find(" ") < s1.find("-"))
					{
						float a;
						a = atof(stringcomp.c_str());
						if (s1.find("i") < s1.find(" "))
						{
							arr1[i][j] = 0;
							arr2[i][j] = a;
						}
						else
						{
							arr1[i][j] = a;
							arr2[i][j] = 0;
						}
					}
					else if (s1.find("+") < s1.find(" "))
					{
						float a;
						a = atof(s1.substr(1, s1.find("+") - 1).c_str());
						arr1[i][j] = a;
						arr2[i][j] = atof(s1.substr(s1.find("+") + 1, s1.find("i") - s1.find("+") - 1).c_str());
						if (s1.find("i") - s1.find("+") - 1 == 0)
						{
							arr2[i][j] = 1;
						}
					}
					else if (s1.find("-") < s1.find(" "))
					{
						arr1[i][j] = atof(s1.substr(1, s1.find("-") - 1).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("-"), s1.find("i") - s1.find("-")).c_str());
						if (s1.find("i") - s1.find("-") == 1)
						{
							arr2[i][j] = -1;
						}
					}
					s1 = s1.substr(pos_space + 1);
				}
				// last column in each row :
				else if (j == cols1 - 1 && i != rows1 - 1)
				{
					int pos_semicolon = s1.find(";");
					stringcomp = s1.substr(0, pos_semicolon);
					if (s1.find(" ") < s1.find("+") && s1.find(" ") < s1.find("-"))
					{
						if (s1.find("i") < s1.find(" "))
						{
							arr1[i][j] = 0;
							arr2[i][j] = atof(stringcomp.c_str());
						}
						else
						{
							arr1[i][j] = atof(stringcomp.c_str());
							arr2[i][j] = 0;
						}
					}
					else if (s1.find("+") < s1.find(" "))
					{
						arr1[i][j] = atof(s1.substr(0, s1.find("+")).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("+") + 1, s1.find("i") - s1.find("+") - 1).c_str());
						if (s1.find("i") - s1.find("+") - 1 == 0)
						{
							arr2[i][j] = 1;
						}
					}
					else if (s1.find("-") < s1.find(" "))
					{
						arr1[i][j] = atof(s1.substr(0, s1.find("-")).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("-"), s1.find("i") - s1.find("-")).c_str());
						if (s1.find("i") - s1.find("-") == 1)
						{
							arr2[i][j] = -1;
						}
					}
					s1 = s1.substr(pos_semicolon + 1);
				}
				// last element in the matrix :  
				else if (j == cols1 - 1 && i == rows1 - 1)
				{
					int pos_Last_bracket = s1.find("]");
					stringcomp = s1.substr(0, pos_Last_bracket);
					if (s1.find("]") < s1.find("+") && s1.find("]") < s1.find("-"))
					{
						if (s1.find("i") < s1.find("]"))
						{
							arr1[i][j] = 0;
							arr2[i][j] = atof(stringcomp.c_str());
						}
						else
						{
							arr1[i][j] = atof(stringcomp.c_str());
							arr2[i][j] = 0;
						}
					}
					else if (s1.find("+") < s1.find("]"))
					{
						arr1[i][j] = atof(s1.substr(0, s1.find("+")).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("+") + 1, s1.find("i") - s1.find("+") - 1).c_str());
						if (s1.find("i") - s1.find("+") - 1 == 0)
						{
							arr2[i][j] = 1;
						}
					}
					else if (s1.find("-") < s1.find("]"))
					{
						arr1[i][j] = atof(s1.substr(0, s1.find("-")).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("-"), s1.find("i") - s1.find("-")).c_str());
						if (s1.find("i") - s1.find("-") == 1)
						{
							arr2[i][j] = -1;
						}
					}
				}
				else
				{
					int pos_space = s1.find(" ");
					stringcomp = s1.substr(0, pos_space);
					if (s1.find(" ") < s1.find("+") && s1.find(" ") < s1.find("-"))
					{
						if (s1.find("i") < s1.find(" "))
						{
							arr1[i][j] = 0;
							arr2[i][j] = atof(stringcomp.c_str());
						}
						else
						{
							arr1[i][j] = atof(stringcomp.c_str());
							arr2[i][j] = 0;
						}

					}
					else if (s1.find("+") < s1.find(" "))
					{
						arr1[i][j] = atof(s1.substr(0, s1.find("+")).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("+") + 1, s1.find("i") - s1.find("+") - 1).c_str());
						if (s1.find("i") - s1.find("+") - 1 == 0)
						{
							arr2[i][j] = 1;
						}
					}
					else if (s1.find("-") < s1.find(" "))
					{
						arr1[i][j] = atof(s1.substr(0, s1.find("-")).c_str());
						arr2[i][j] = atof(s1.substr(s1.find("-"), s1.find("i") - s1.find("-")).c_str());
						if (s1.find("i") - s1.find("-") == 1)
						{
							arr2[i][j] = -1;
						}
					}
					s1 = s1.substr(pos_space + 1);

				}
			}
		}
		// conversion of string array into float array:

		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{

				complex<float> complex_1(arr1[i][j], arr2[i][j]);
				arr_complex_1[i][j] = complex_1;

			}
		}


		int rows2 = 0, cols2 = 0;
		// determining the number of rows in the first matrix
		for (int i = 0; i < s2.length(); i++)
		{
			if (s2[i] == ';')
				rows2++;
		}
		rows2++;
		// determining the number of columns in the first matrix
		for (int i = 0; i < s2.length(); i++)
		{
			if (s2[i] == ' ')
			{
				cols2++;
			}
			if (s2[i] == ';')
				break;
		}
		cols2++;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				if (s2[0] == '[')
				{
					int pos_space2 = s2.find(" ");
					stringcomp2 = s2.substr(1, pos_space2 - 1);
					if (s2.find(" ") < s2.find("+") && s2.find(" ") < s2.find("-"))
					{
						if (s1.find("i") < s1.find(" "))
						{
							arr3[i][j] = 0;
							arr4[i][j] = atof(stringcomp2.c_str());
						}
						else
						{
							arr3[i][j] = atof(stringcomp2.c_str());
							arr4[i][j] = 0;
						}
					}
					else if (s2.find("+") < s2.find(" "))
					{
						arr3[i][j] = atof(s2.substr(1, s2.find("+") - 1).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("+") + 1, s2.find("i") - s2.find("+") - 1).c_str());
						if (s2.find("i") - s2.find("+") - 1 == 0)
						{
							arr4[i][j] = 1;
						}
					}
					else if (s2.find("-") < s2.find(" "))
					{
						arr3[i][j] = atof(s2.substr(1, s2.find("-") - 1).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("-"), s2.find("i") - s2.find("-")).c_str());
						if (s2.find("i") - s2.find("-") == 1)
						{
							arr4[i][j] = -1;
						}
					}
					s2 = s2.substr(pos_space2 + 1);
				}
				// last column in each row :
				else if (j == cols2 - 1 && i != rows2 - 1)
				{
					int pos_semicolon2 = s2.find(";");
					stringcomp2 = s2.substr(0, pos_semicolon2);
					if (s2.find(" ") < s2.find("+") && s2.find(" ") < s2.find("-"))
					{
						if (s1.find("i") < s1.find(" "))
						{
							arr3[i][j] = 0;
							arr4[i][j] = atof(stringcomp2.c_str());
						}
						else
						{
							arr3[i][j] = atof(stringcomp2.c_str());
							arr4[i][j] = 0;
						}
					}
					else if (s2.find("+") < s2.find(" "))
					{
						arr3[i][j] = atof(s2.substr(0, s2.find("+")).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("+") + 1, s2.find("i") - s2.find("+") - 1).c_str());
						if (s2.find("i") - s2.find("+") - 1 == 0)
						{
							arr4[i][j] = 1;
						}
					}
					else if (s2.find("-") < s2.find(" "))
					{
						arr3[i][j] = atof(s2.substr(0, s2.find("-")).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("-"), s2.find("i") - s2.find("-")).c_str());
						if (s2.find("i") - s2.find("-") == 1)
						{
							arr4[i][j] = -1;
						}
					}
					s2 = s2.substr(pos_semicolon2 + 1);
				}
				// last element in the matrix :  
				else if (j == cols2 - 1 && i == rows2 - 1)
				{
					int pos_Last_bracket2 = s2.find("]");
					stringcomp2 = s2.substr(0, pos_Last_bracket2);
					if (s2.find("]") < s2.find("+") && s2.find("]") < s2.find("-"))
					{
						if (s1.find("i") < s1.find("]"))
						{
							arr3[i][j] = 0;
							arr4[i][j] = atof(stringcomp2.c_str());
						}
						else
						{
							arr3[i][j] = atof(stringcomp2.c_str());
							arr4[i][j] = 0;
						}
					}
					else if (s2.find("+") < s2.find("]"))
					{
						arr3[i][j] = atof(s2.substr(0, s2.find("+")).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("+") + 1, s2.find("i") - s2.find("+") - 1).c_str());
						if (s2.find("i") - s2.find("+") - 1 == 0)
						{
							arr4[i][j] = 1;
						}
					}
					else if (s2.find("-") < s2.find("]"))
					{
						arr3[i][j] = atof(s2.substr(0, s2.find("-")).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("-"), s2.find("i") - s2.find("-")).c_str());
						if (s2.find("i") - s2.find("-") == 1)
						{
							arr4[i][j] = -1;
						}
					}
				}
				else
				{
					int pos_space2 = s2.find(" ");
					stringcomp2 = s2.substr(0, pos_space2);
					if (s2.find(" ") < s2.find("+") && s2.find(" ") < s2.find("-"))
					{
						if (s1.find("i") < s1.find(" "))
						{
							arr3[i][j] = 0;
							arr4[i][j] = atof(stringcomp2.c_str());
						}
						else
						{
							arr3[i][j] = atof(stringcomp2.c_str());
							arr4[i][j] = 0;
						}

					}
					else if (s2.find("+") < s2.find(" "))
					{
						arr3[i][j] = atof(s2.substr(0, s2.find("+")).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("+") + 1, s2.find("i") - s2.find("+") - 1).c_str());
						if (s2.find("i") - s2.find("+") - 1 == 0)
						{
							arr4[i][j] = 1;
						}
					}
					else if (s2.find("-") < s2.find(" "))
					{
						arr3[i][j] = atof(s2.substr(0, s2.find("-")).c_str());
						arr4[i][j] = atof(s2.substr(s2.find("-"), s2.find("i") - s2.find("-")).c_str());
						if (s2.find("i") - s2.find("-") == 1)
						{
							arr4[i][j] = -1;
						}
					}
					s2 = s2.substr(pos_space2 + 1);

				}
			}
		}
		// conversion of string array into float array:

		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < cols2; j++)
			{

				complex<float> complex_2(arr3[i][j], arr4[i][j]);
				arr_complex_2[i][j] = complex_2;

			}
		}
		char op;
		op = character[0];
		
		switch (op)
		{
		case '+':
			if (rows1 != rows2 || cols1 != cols2)
			{
				cout << "Error";
			}
			else
			{
				cout << "[";
				for (int i = 0; i < rows1; i++)
				{
					for (int j = 0; j < cols1; j++)
					{
						if (j == cols1 - 1)
						{
							if (i == rows1 - 1)
							{
								cout << real(arr_complex_1[i][j]) + real(arr_complex_2[i][j]);
								if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) > 0)
								{
									if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == 1)
									{
										cout << "+i";
									}
									else
									{
										cout << "+" << imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) << "i";
									}
								}
								else if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == 0)
									continue;
								else if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) < 0)
								{
									if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == -1)
									{
										cout << "-i";
									}
									else
									{
										cout << imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) << "i";
									}
								}
							}
							else
							{
								cout << real(arr_complex_1[i][j]) + real(arr_complex_2[i][j]);
								if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) > 0)
								{
									if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == 1)
									{
										cout << "+i;";
									}
									else
									{
										cout << "+" << imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) << "i;";
									}
								}

								else if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == 0)
								{
									cout << ";";
								}
								else
								{
									if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == -1)
									{
										cout << "-i;";
									}
									else
									{
										cout << imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) << "i;";
									}
								}
							}
						}
						else
						{
							cout << real(arr_complex_1[i][j]) + real(arr_complex_2[i][j]);
							if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) > 0)
							{
								if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == 1)
								{
									cout << "+i ";
								}
								else
								{
									cout << "+" << imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) << "i ";
								}
							}
							else if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == 0)
							{
								cout << " ";
							}
							else
							{
								if (imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) == -1)
								{
									cout << "-i ";
								}
								else
								{
									cout << imag(arr_complex_1[i][j]) + imag(arr_complex_2[i][j]) << "i";
									cout << " ";
								}
							}
						}
					}
				}
				cout << "]";
			}
			break;

		case '-':
			if (rows1 != rows2 || cols1 != cols2)
			{
				cout << "Error";
			}
			else
			{
				cout << "[";
				for (int i = 0; i < rows1; i++)
				{
					for (int j = 0; j < cols1; j++)
					{
						if (j == cols1 - 1)
						{
							if (i == rows1 - 1)
							{
								cout << real(arr_complex_1[i][j]) - real(arr_complex_2[i][j]);
								if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) > 0)
								{
									if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == 1)
									{
										cout << "+i";
									}
									else
									{
										cout << "+" << imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) << "i";
									}
								}
								else if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == 0)
									continue;
								else if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) < 0)
								{
									if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == -1)
									{
										cout << "-i";
									}
									else
									{
										cout << imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) << "i";
									}
								}
							}
							else
							{
								cout << real(arr_complex_1[i][j]) - real(arr_complex_2[i][j]);
								if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) > 0)
								{
									if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == 1)
									{
										cout << "+i;";
									}
									else
									{
										cout << "+" << imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) << "i;";
									}
								}

								else if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == 0)
								{
									cout << ";";
								}
								else
								{
									if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == -1)
									{
										cout << "-i;";
									}
									else
									{
										cout << imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) << "i;";
									}
								}
							}
						}
						else
						{
							cout << real(arr_complex_1[i][j]) - real(arr_complex_2[i][j]);
							if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) > 0)
							{
								if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == 1)
								{
									cout << "+i ";
								}
								else
								{
									cout << "+" << imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) << "i ";
								}
							}
							else if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == 0)
							{
								cout << " ";
							}
							else
							{
								if (imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) == -1)
								{
									cout << "-i ";
								}
								else
								{
									cout << imag(arr_complex_1[i][j]) - imag(arr_complex_2[i][j]) << "i";
									cout << " ";
								}
							}
						}
					}
				}
				cout << "]";
			}
			break;
		case '*':

			if (cols1 != rows2)
			{
				cout << "Error";
			}
			else
			{
				complex<float> h;
				for (int i = 0; i < rows1; i++)
				{
					for (int j = 0; j < cols2; j++)
					{
						h = 0;
						for (int l = 0; l < rows2; l++)
						{
							h += arr_complex_1[i][l] * arr_complex_2[l][j];
							multiply[i][j] = h;
						}


					}
				}
				cout << "[";
				for (int i = 0; i < rows1; i++)
				{
					for (int j = 0; j < cols2; j++)
					{
						if (j == cols2 - 1)
						{
							if (i == rows1 - 1)
							{
								cout << real(multiply[i][j]);
								if (imag(multiply[i][j]) > 0)
								{
									if (imag(multiply[i][j]) == 1)
									{
										cout << "+i";
									}
									else
									{
										cout << "+" << imag(multiply[i][j]) << "i";
									}
								}
								else if (imag(multiply[i][j]) == 0)
									continue;
								else if (imag(multiply[i][j]) < 0)
								{
									if (imag(multiply[i][j]) == -1)
									{
										cout << "-i";
									}
									else
									{
										cout << imag(multiply[i][j]) << "i";
									}
								}
							}
							else
							{
								cout << real(multiply[i][j]);
								if (imag(multiply[i][j]) > 0)
								{
									if (imag(multiply[i][j]) == 1)
									{
										cout << "+i;";
									}
									else
									{
										cout << "+" << imag(multiply[i][j]) << "i;";
									}
								}

								else if (imag(multiply[i][j]) == 0)
								{
									cout << ";";
								}
								else
								{
									if (imag(multiply[i][j]) == -1)
									{
										cout << "-i;";
									}
									else
									{
										cout << imag(multiply[i][j]) << "i;";
									}
								}
							}
						}
						else
						{

							cout << real(multiply[i][j]);
							if (imag(multiply[i][j]) > 0)
							{
								if (imag(multiply[i][j]) == 1)
								{
									cout << "+i ";
								}
								else
								{
									cout << "+" << imag(multiply[i][j]) << "i ";
								}
							}
							else if (imag(multiply[i][j]) == 0)
							{
								cout << " ";
							}
							else
							{
								if (imag(multiply[i][j]) == -1)
								{
									cout << "-i ";
								}
								else
								{
									cout << imag(multiply[i][j]) << "i";
									cout << " ";
								}
							}
						}
					}
				}

				cout << "]";
			}
			break;


		default:
			cout << "Error \n";
		}

	}
	return 0;
}
