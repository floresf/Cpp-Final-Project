// Fernando Flores
// 5/5/2013
// FINAL PROJECT



#include <iostream>
#include <string>
#include <iomanip>
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
using namespace std;



// Edit PRODUCTION WORKER Functions
void displayProd(ProductionWorker [], int);
void delProdWorker(ProductionWorker [], int);
void editProdWorker(ProductionWorker [], int);

// Edit TEAM LEADER Functions
void displayLead(TeamLeader [], int);
void delLead(TeamLeader [], int);
void editLead(TeamLeader [], int);

// Edit SHIFT SUPERVISOR Functions
void displaySuper(ShiftSupervisor [], int);
void delSuper(ShiftSupervisor [], int);
void editSuper(ShiftSupervisor [], int);

// Display Menu
void displayMenu();
void displayProdMenu();
void displayTeamMenu();
void displaySuperMenu();

// Team Leader constants
const double MONTHLY_BONUS = 120.75;
const int REQ_TRAIN_HOURS = 200;

// Shift Supervisor constants
const double ANNUAL_SALARY = 52450.50;
const double ANNUAL_PROD_BONUS = 2600.75;


int main()
{
	// Array const sizes
	const int PROD_WORKERS = 3,
		TEAM_LEADS = 2,
		SHIFT_SUPERS = 1;

	// Choice for menu
	int choice;
	bool menuLoop = true;

	// Arrays of respective objects created.
	ProductionWorker prodWorkers[PROD_WORKERS] = {
				ProductionWorker(),
				ProductionWorker(),
				ProductionWorker() };

	TeamLeader teamLeads[TEAM_LEADS] = {
				TeamLeader(),
				TeamLeader() };
	
	ShiftSupervisor shiftSuper[SHIFT_SUPERS] =
				{ ShiftSupervisor() };



	bool tryAgain = true;


	// PROMPT INTRODUCTION TO STARK INDUSTRIES EMPLOYEE TRANSFER PROGRAM

	cout << "\tWelcome to the Stark Industries Employee Transfer Program.\n\n";
	cout << "The company at this time can only except a small amount of transfers.\n";
	cout << "This has been pre-programmed to allow only 3 transfer Production Workers,\n";
	cout << "2 transfer Team Leaders, and 1 transfer Shift Supervisor.\n\n";

	
	/////////////////////////////////////// PRODUCTION WORKER SUBMISSION //////////////////////////////////
	
	
	cout << "First we will enter the data for the Production Workers.\n";
	cout << "For identity protection we will only enter the last name of the employee\nat this time.\n\n";
	cout << "Enter the data for the corresponding Production Worker Employee." << endl << endl;

	for (int i = 0; i < PROD_WORKERS; i ++)
	{
		string empName;
		int empNumber;
		string hireDate;
		int workShift;
		double hrPayRate;


		cout << "Production Worker " << (i + 1) << ":" << endl;
		cout << "Enter the last name of the employee: ";
		cin >> empName;
		cout << endl;
		cout << "Enter the employee number: ";
		cin >> empNumber;
		cout << endl;
		cout << "Enter the hire date(XX/XX/XX): ";
		cin >> hireDate;
		cout << "Enter the work shift(1 or 2): ";
		cin >> workShift;
		cout << endl;
		cout << "Enter worker's hourly pay rate: $";
		cin >> hrPayRate;
		cout << endl;

		bool tryAgain = true;

		while (tryAgain)
		{
			try
			{
				prodWorkers[i].setName(empName);
				prodWorkers[i].setNumber(empNumber);
				prodWorkers[i].setDate(hireDate);
				prodWorkers[i].setShift(workShift);
				prodWorkers[i].setPayRate(hrPayRate);

				//if no exception is thrown, then the exit
				//loop by changing 'tryAgain'
				tryAgain = false;
			}
			catch (ProductionWorker::InvalidEmployeeNumber)
			{
				cout << "\tEmployee Number cannot be less than 0 or greater than 9999.\n";
				cout << "Enter a new valid Employee Number: ";
				cin >> empNumber;
			}
			catch (ProductionWorker::InvalidShift)
			{
				cout << "\tError: Work shift must be either 1 or 2.\n";
				cout << "Enter a new valid work shift: ";
				cin >> workShift;

			}
			catch (ProductionWorker::InvalidPayRate)
			{
				cout << "Error: Hourly pay rate cannot be negative.\n";
				cout << "Enter a new valid hourly pay rate: ";
				cin >> hrPayRate;
			}
		}
	}

	cout << "/////////////////////////////////////////////\n";
	cout << "Transfer Production Employees Submitted!////\n";
	cout << "///////////////////////////////////////////\n";
	cout << endl;

	

	//////////////////////////////////////// TEAM LEADER SUBMISSION //////////////////////////////////
	cout << "Next the Team Leaders will be entered.\n";
	cout << "For identity protection we will only enter the last name of the employee at this time.\n";
	cout << "Enter the data for the corresponding Team Leader Employee." << endl << endl;

	for (int index = 0; index < TEAM_LEADS; index ++)
	{
		string empName;
		int empNumber;
		string hireDate;
		int workShift;
		double hrPayRate;
		double monthlyBonus;
		int reqTrainHours;
		int attTrainHours;


		cout << "Team Leader " << (index + 1) << ":" << endl;
		cout << "Enter the last name of the employee: ";
		cin >> empName;
		cout << endl; //////////////////
		cout << "Enter the employee number: ";
		cin >> empNumber;
		cout << endl; /////////////////
		cout << "Enter the hire date(XX/XX/XX): ";
		cin >> hireDate;
		cout << endl; ////////////////
		cout << "Enter the work shift(1 or 2): ";
		cin >> workShift;
		cout << endl; ////////////////
		cout << "Enter worker's hourly pay rate: $";
		cin >> hrPayRate;
		cout << endl; ///////////////
		cout << "\t**Monthly bonus amount is fixed. Amount $" << MONTHLY_BONUS << " submitted.**\n";
		cout << "\t**The required training hours per year is " << REQ_TRAIN_HOURS << ".**\n" << endl;
		cout << "Enter training hours completed so far by Team Leader " << empName << ": ";
		cin >> attTrainHours;
		if (attTrainHours < 0 || attTrainHours > 200)
		{
			cout << "" << endl;
		}
		else
		{
			cout << "\t**Great! Only " << (REQ_TRAIN_HOURS - attTrainHours) << " hours to go!**\n";
		}
		cout << endl;

		bool tryAgain = true;

		while (tryAgain)
		{
			try
			{
				teamLeads[index].setName(empName);
				teamLeads[index].setNumber(empNumber);
				teamLeads[index].setDate(hireDate);
				teamLeads[index].setShift(workShift);
				teamLeads[index].setPayRate(hrPayRate);
				teamLeads[index].setMonthlyBonus(MONTHLY_BONUS);
				teamLeads[index].setReqHours(REQ_TRAIN_HOURS);
				teamLeads[index].setAttHours(attTrainHours);

				//if no exception is thrown, then the exit
				//loop by changing 'tryAgain'
				tryAgain = false;
			}
			catch (TeamLeader::InvalidEmployeeNumber)
			{
				cout << "\tEmployee Number cannot be less than 0 or greater than 9999.\n";
				cout << "Enter a new valid Employee Number: ";
				cin >> empNumber;
			}
			catch (TeamLeader::InvalidShift)
			{
				cout << "\tError: Work shift must be either 1 or 2.\n";
				cout << "Enter a new valid work shift: ";
				cin >> workShift;
			}
			catch (TeamLeader::InvalidPayRate)
			{
				cout << "Error: Hourly pay rate cannot be negative.\n";
				cout << "Enter a new valid hourly pay rate: ";
				cin >> hrPayRate;
			}
			catch (TeamLeader::InvalidHours)
			{
				cout << "Error: Training Hours completed cannot exceed total Training hours.\n";
				cout << "Enter a new valid entry: ";
				cin >> attTrainHours;
			}
		}
	}
	cout << "/////////////////////////////////////////////\n";
	cout << "Transfer Team Leader Employees Submitted!///\n";
	cout << "///////////////////////////////////////////\n";
	cout << endl;
	
	/////////////////////////////////////// SHIFT SUPERVISOR SUBMISSION /////////////////////////////////////
	cout << "Next the Shift Supervisors will be entered.\n";
	cout << "For identity protection we will only enter the last name\nof the employee at this time.\n";
	cout << "Enter the data for the corresponding Shift Supervisor Employee." << endl << endl;

	tryAgain = true;
	for (int count = 0; count < SHIFT_SUPERS; count ++)
	{
		string empName;
		int empNumber;
		string hireDate;


		cout << "Shift Supervisor " << (count + 1) << ":" << endl;
		cout << "\tEnter the last name of the employee: ";
		cin >> empName;
		cout << endl; //////////////////
		cout << "\tEnter the employee number: ";
		cin >> empNumber;
		cout << endl; /////////////////
		cout << "\tEnter the hire date(XX/XX/XX): ";
		cin >> hireDate;
		cout << endl; ////////////////
		cout << "\t**Annual salary is fixed. Amount $" << ANNUAL_SALARY << " submitted.**\n\n";
		cout << "\t**Annual production bonus is also fixed at $" << ANNUAL_PROD_BONUS << " but is subject**\n\n";
		cout << "\t**to change depending on Shift Supervisor's results. Amount submitted.**\n";
		cout << endl;

		

		while (tryAgain)
		{
			try
			{
				shiftSuper[count].setName(empName);
				shiftSuper[count].setNumber(empNumber);
				shiftSuper[count].setDate(hireDate);
				shiftSuper[count].setSalary(ANNUAL_SALARY);
				shiftSuper[count].setAnBonus(ANNUAL_PROD_BONUS);

				//if no exception is thrown, then the exit
				//loop by changing 'tryAgain'
				tryAgain = false;
			}
			catch (TeamLeader::InvalidEmployeeNumber)
			{
				cout << "\tEmployee Number cannot be less than 0 or greater than 9999.\n";
				cout << "Enter a new valid Employee Number: ";
				cin >> empNumber;
			}
		}
	}

	cout << "//////////////////////////////////////////////////\n";
	cout << "Transfer Shift Supervisor Employees Submitted!///\n";
	cout << "////////////////////////////////////////////////\n";
	cout << endl << endl;


	

	

	/////////////////////////// MENU ////////////////////////////////////////

	
	while (menuLoop)
	{
		displayMenu();
	
		cin >> choice;
		// validate!!!!!!
		while (choice < 0 || choice > 6)
		{
			cout << "Invalid entry. Please enter a number between 0 and 5: ";
			cin >> choice;
		}
		cout << endl;

		switch (choice)
		{
			case 0:
				exit(0);

				
				                           /////////////////////////////////////////////////
				                  //////////////////////////////////////////////////////////////////////////
				///////////////////////////////////////////////// PRODUCTION AREA ////////////////////////////////////
			case 1:
				// Display PRODUCTION WORKERS
				displayProd(prodWorkers, PROD_WORKERS);
				break;

			case 2:
				// EDIT Production Workers
				displayProdMenu();
				cin >> choice;
				// validate!!!!!!
				while (choice < 0 || choice > 3)
				{
					cout << "Invalid entry. Please enter a number between 0 and 3: ";
					cin >> choice;
				}
				cout << endl;

				switch (choice)
				{
					case 0:
						exit(0);

					case 1:
						// DELETE A PRODUCTION WORKER
						delProdWorker(prodWorkers, PROD_WORKERS);
						break;

					case 2:
						// EDIT a Production Worker
						editProdWorker(prodWorkers, PROD_WORKERS);
						break;


					case 3:
						// Display TEAM LEADERS
						displayMenu();
						break;

					default:
						cout << "nothing entered" << endl;
				}

				break;

				                                          /////////////////////////
				                           ///////////////////////////////////////////////////////
				////////////////////////////////////////////////  TEAM AREA  ///////////////////////////////

			case 3:
				// Display TEAM LEADERS
				displayLead(teamLeads, TEAM_LEADS);
				break;

			case 4:
				// EDIT Production Workers
				displayTeamMenu();
				cin >> choice;
				// validate!!!!!!
				while (choice < 0 || choice > 3)
				{
					cout << "Invalid entry. Please enter a number between 0 and 3: ";
					cin >> choice;
				}
				cout << endl;

				switch (choice)
				{
					case 0:
						exit(0);

					case 1:
						// DELETE A TEAM LEADER
						delLead(teamLeads, TEAM_LEADS);
						break;

					case 2:
						// EDIT A TEAM LEADER
						editLead(teamLeads, TEAM_LEADS);
						break;

					case 3:
						// Display TEAM LEADERS
						displayMenu();
						break;

					default:
						cout << "nothing entered" << endl;
				}

				break;
				                                             /////////////////////////
				                           ///////////////////////////////////////////////////////
				////////////////////////////////////////////////  SUPER AREA  ///////////////////////////////
			case 5:
				// Display SHIFT SUPERVISORS
				displaySuper(shiftSuper, SHIFT_SUPERS);
				break;

			case 6:
				// EDIT SHIFT SUPERVISORS
				displaySuperMenu();
				cin >> choice;
				// validate!!!!!!
				while (choice < 0 || choice > 3)
				{
					cout << "Invalid entry. Please enter a number between 0 and 3: ";
					cin >> choice;
				}
				cout << endl;

				switch (choice)
				{
					case 0:
						exit(0);

					case 1:
						// DELETE A TEAM LEADER
						delSuper(shiftSuper, SHIFT_SUPERS);
						break;

					case 2:
						// EDIT A TEAM LEADER
						editSuper(shiftSuper, SHIFT_SUPERS);
						break;

					case 3:
						// Display TEAM LEADERS
						displayMenu();
						break;

					default:
						cout << "nothing entered" << endl;
				}

				break;

			default:
				cout << "nothing entered" << endl;
			}
		}


	return 0;
}
//////////////////////////////////////////////////////// END MAIN /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////  MAIN MENU  ///////////////////////////////////////////////
void displayMenu()
{
	cout << "-------------- Customer Account Program --------------" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "|/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\|" << endl;
	cout << "|Display Transfer Production Workers......... Enter 1|" << endl;
	cout << "|Edit Transfer Production Workers............ Enter 2|" << endl;
	cout << "|Display Transfer Team Leaders............... Enter 3|" << endl;
	cout << "|Edit Transfer Team Leaders.................. Enter 4|" << endl;
	cout << "|Display Transfer Shift Supervisors.......... Enter 5|" << endl;
	cout << "|Edit Transfer Shift Supervisors............. Enter 6|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|End program................................. Enter 0|" << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";
}

////////////////////////// PRODUCTION WORKER MENU  ////////////////////////////////////
void displayProdMenu()
{
	cout << "-------------- Customer Account Program --------------" << endl;
	cout << "-----------***Production Worker Edit Menu***----------" << endl;
	cout << "|/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\|" << endl;
	cout << "|Delete a Production Worker.................. Enter 1|" << endl;
	cout << "|Re-Enter Data for a Production Worker ...... Enter 2|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|Return to Main Menu ........................ Enter 3|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|End program................................. Enter 0|" << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";
}

void displayTeamMenu()
{
	cout << "-------------- Customer Account Program --------------" << endl;
	cout << "--------------***Team Leader Edit Menu***-------------" << endl;
	cout << "|/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\|" << endl;
	cout << "|Delete a Team Leader ....................... Enter 1|" << endl;
	cout << "|Re-Enter Data for a Team Leader ............ Enter 2|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|Return to Main Menu ........................ Enter 3|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|End program................................. Enter 0|" << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";

}

void displaySuperMenu()
{
	cout << "-------------- Customer Account Program --------------" << endl;
	cout << "--------------***Team Leader Edit Menu***-------------" << endl;
	cout << "|/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\|" << endl;
	cout << "|Delete a Shift Supervisor .................. Enter 1|" << endl;
	cout << "|Re-Enter Data for a Shift Supervisor ....... Enter 2|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|Return to Main Menu ........................ Enter 3|" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|End program................................. Enter 0|" << endl;
	cout << "******************************************************" << endl;
	cout << "Enter your choice: ";

}

//////////////////////////////////////////////// END MENUS ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////// PRODUCTION WORKER EDIT ///////////////////////////////////////////////////////
void displayProd(ProductionWorker prods[], int size)
{
	cout << "////////////////////////////////////////////////////////\n";
	cout << "          <<NEW TRANSFER PRODUCTION WORKERS>>           \n";
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(2) << left << fixed;
		cout << "Production Worker " << (i + 1) << ":\n\n";
		cout << "Last Name:\t\t\t\t" << prods[i].getName() << endl;
		cout << "Employee Number:\t\t\t" << prods[i].getNumber() << endl;
		cout << "Employee Hire Date:\t\t\t" << prods[i].getDate() << endl;
		cout << "Employee Work Shift:\t\t\t" << prods[i].getShift() << endl;
		cout << "Employee Pay Rate:\t\t\t$" << prods[i].getPayRate() << endl;
		cout << "...........................................................\n";
	}

	cout << endl;
}


void delProdWorker(ProductionWorker prods[], int size)
{
	// Displays COMPLETE LIST OF PRODUCTION WORKERS FOR REFERENCE
	displayProd(prods, size);

	// Holds the user input for last name
	int workerNum;

	cout << "Enter the number of the Production Worker to delete: ";
	cin >> workerNum;

	// Subtract one from workerNum to make up for index
	workerNum -= 1;

	for (int i = 0; i < size; i++)
	{
		if (i == workerNum )
		{
			prods[i].setName("");
			prods[i].setNumber(0);
			prods[i].setDate("");
			prods[i].setShift(1);
			prods[i].setPayRate(0.0);
		}
	}
	cout << "***Production Worker deleted.***" << endl << endl;
}


void editProdWorker(ProductionWorker prods[], int size)
{
	// To hold input 
	string empName;
	int empNumber;
	string hireDate;
	int workShift;
	double hrPayRate;

	bool tryAgain = true;

	// Holds the user input for employee number
	int workerNum;

	// Displays COMPLETE LIST OF PRODUCTION WORKERS FOR REFERENCE
	displayProd(prods, size);

	cout << "Enter the number of the Production Worker to edit: ";
	cin >> workerNum;

	// Subtract one from workerNum to make up for index
	workerNum -= 1;

	for (int i = 0; i < size; i++)
	{
		if (i == workerNum)
		{
			cout << "For identity protection we will only enter the last name of the employee\nat this time.\n\n";
			cout << endl << endl;


			cout << "Production Worker " << (i + 1) << ":" << endl;
			cout << "Enter the last name of the employee: ";
			cin >> empName;
			cout << endl;
			cout << "Enter the employee number: ";
			cin >> empNumber;
			cout << endl;
			cout << "Enter the hire date(XX/XX/XX): ";
			cin >> hireDate;
			cout << "Enter the work shift(1 or 2): ";
			cin >> workShift;
			cout << endl;
			cout << "Enter worker's hourly pay rate: $";
			cin >> hrPayRate;
			cout << endl;

			

			while (tryAgain)
			{
				try
				{
					prods[i].setName(empName);
					prods[i].setNumber(empNumber);
					prods[i].setDate(hireDate);
					prods[i].setShift(workShift);
					prods[i].setPayRate(hrPayRate);

					//if no exception is thrown, then the exit
					//loop by changing 'tryAgain'
					tryAgain = false;
					}
				catch (ProductionWorker::InvalidEmployeeNumber)
				{
					cout << "\tEmployee Number cannot be less than 0 or greater than 9999.\n";
					cout << "Enter a new valid Employee Number: ";
					cin >> empNumber;
				}
				catch (ProductionWorker::InvalidShift)
				{
					cout << "\tError: Work shift must be either 1 or 2.\n";
					cout << "Enter a new valid work shift: ";
					cin >> workShift;

				}
				catch (ProductionWorker::InvalidPayRate)
				{
					cout << "Error: Hourly pay rate cannot be negative.\n";
					cout << "Enter a new valid hourly pay rate: ";
					cin >> hrPayRate;
				}
			}
		}
	}

	cout << "***Production Worker Data changed.***" << endl << endl;
}


///////////////////////////////////////////// TEAM LEADER EDIT /////////////////////////////////////////

void displayLead(TeamLeader leads[], int size)
{

	cout << "////////////////////////////////////////////////////////\n";
	cout << "             <<NEW TRANSFER TEAM LEADERS>>              \n";
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(2) << left << fixed;
		cout << "Team Leader " << (i + 1) << ":\n\n";
		cout << "Last Name:\t\t\t\t" << leads[i].getName() << endl;
		cout << "Employee Number:\t\t\t" << leads[i].getNumber() << endl;
		cout << "Employee Hire Date:\t\t\t" << leads[i].getDate() << endl;
		cout << "Employee Work Shift:\t\t\t" << leads[i].getShift() << endl;
		cout << "Employee Pay Rate:\t\t\t$" << leads[i].getPayRate() << endl;
		cout << "Employee Monthly Bonus:\t\t\t$" << leads[i].getMonthlyBonus() << endl;
		cout << "Employee Required Training Hrs:\t\t" << leads[i].getReqHours() << endl;
		cout << "Employee Training Hrs Attended:\t\t" << leads[i].getAttHours() << endl;
		cout << "...........................................................\n";
	}

	cout << endl;
}

void delLead(TeamLeader leads[], int size)
{
	// Displays COMPLETE LIST OF PRODUCTION WORKERS FOR REFERENCE
	displayLead(leads, size);

	// Holds the user input for last name
	int workerNum;

	cout << "Enter the number of the Team Leader to delete: ";
	cin >> workerNum;

	// Subtract one from workerNum to make up for index
	workerNum -= 1;

	for (int i = 0; i < size; i++)
	{
		if (i == workerNum )
		{
			leads[i].setName("");
			leads[i].setNumber(0);
			leads[i].setDate("");
			leads[i].setShift(1);
			leads[i].setPayRate(0.0);
			leads[i].setMonthlyBonus(0.0);
			leads[i].setReqHours(0);
			leads[i].setAttHours(0);
		}
	}

	cout << "***Team Leader deleted.***" << endl << endl;
}

void editLead(TeamLeader leads[], int size)
{
	// To hold input 
	string empName;
	int empNumber;
	string hireDate;
	int workShift;
	double hrPayRate;
	int attTrainHours;

	bool tryAgain = true;

	// Holds the user input for employee number
	int workerNum;

	// Displays COMPLETE LIST OF PRODUCTION WORKERS FOR REFERENCE
	displayLead(leads, size);

	cout << "Enter the number of the Team Leader to edit: ";
	cin >> workerNum;

	// Subtract one from workerNum to make up for index
	workerNum -= 1;

	for (int i = 0; i < size; i++)
	{
		if (i == workerNum)
		{
			
			cout << "For identity protection we will only enter the last name of the employee\nat this time.\n\n";
			cout << endl << endl;


			cout << "Team Leader " << (i + 1) << ":" << endl;
			cout << "Enter the last name of the employee: ";
			cin >> empName;
			cout << endl;
			cout << "Enter the employee number: ";
			cin >> empNumber;
			cout << endl;
			cout << "Enter the hire date(XX/XX/XX): ";
			cin >> hireDate;
			cout << "Enter the work shift(1 or 2): ";
			cin >> workShift;
			cout << endl;
			cout << "Enter worker's hourly pay rate: $";
			cin >> hrPayRate;
			cout << endl;
			cout << setprecision(2) << fixed;
			cout << "\t**Monthly bonus amount is fixed. Amount " << MONTHLY_BONUS << ", submitted.**\n";
			cout << "\t**The required training hours per year is " << REQ_TRAIN_HOURS << ".**\n" << endl;
			cout << "Enter training hours completed so far by Team Leader " << empName << ": ";
			cin >> attTrainHours;
			if (attTrainHours < 0 || attTrainHours > 200)
			{
				cout << " " << endl;
			}
			else
			{
				cout << "\t**Great! Only " << (REQ_TRAIN_HOURS - attTrainHours) << " hours to go!**\n";
			}
			cout << endl;

			

			while (tryAgain)
			{
				try
				{
					leads[i].setName(empName);
					leads[i].setNumber(empNumber);
					leads[i].setDate(hireDate);
					leads[i].setShift(workShift);
					leads[i].setPayRate(hrPayRate);
					leads[i].setMonthlyBonus(MONTHLY_BONUS);
					leads[i].setReqHours(REQ_TRAIN_HOURS);
					leads[i].setAttHours(attTrainHours);

					//if no exception is thrown, then the exit
					//loop by changing 'tryAgain'
					tryAgain = false;
					}
				catch (ProductionWorker::InvalidEmployeeNumber)
				{
					cout << "\tEmployee Number cannot be less than 0 or greater than 9999.\n";
					cout << "Enter a new valid Employee Number: ";
					cin >> empNumber;
				}
				catch (ProductionWorker::InvalidShift)
				{
					cout << "\tError: Work shift must be either 1 or 2.\n";
					cout << "Enter a new valid work shift: ";
					cin >> workShift;

				}
				catch (ProductionWorker::InvalidPayRate)
				{
					cout << "Error: Hourly pay rate cannot be negative.\n";
					cout << "Enter a new valid hourly pay rate: ";
					cin >> hrPayRate;
				}
				catch (TeamLeader::InvalidHours)
				{
					cout << "Error: Training Hours completed cannot exceed total Training hours.\n";
					cout << "Enter a new valid entry: ";
					cin >> attTrainHours;
				}
			}
		}
	}

	cout << "***Team Leader data changed.***" << endl << endl;
}

//////////////////////////////////////////////// SHIFT SUPERVISOR EDIT ////////////////////////////////// 

void displaySuper(ShiftSupervisor supers[], int size)
{
	cout << "////////////////////////////////////////////////////////\n";
	cout << "           <<NEW TRANSFER SHIFT SUPERVISORS>>           \n";
	cout << endl;
	
	
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(2) << left << fixed;
		cout << "Shift Supervisor " << (i + 1) << ":\n\n";
		cout << "Last Name:\t\t\t\t" << supers[i].getName() << endl;
		cout << "Employee Number:\t\t\t" << supers[i].getNumber() << endl;
		cout << "Employee Hire Date:\t\t\t" << supers[i].getDate() << endl;
		cout << "Employee Annual Salary:\t\t\t$" << supers[i].getSalary() << endl;
		cout << "Employee Annual Bonus:\t\t\t$" << supers[i].getBonus() << endl;
		cout << "...........................................................\n";
	}

	cout << endl;
}

void delSuper(ShiftSupervisor supers[], int size)
{
	// Displays COMPLETE LIST OF PRODUCTION WORKERS FOR REFERENCE
	displaySuper(supers, size);

	// Holds the user input for last name
	int workerNum;

	cout << "Enter the number of the Shift Supervisor to delete: ";
	cin >> workerNum;

	// Subtract one from workerNum to make up for index
	workerNum -= 1;

	for (int i = 0; i < size; i++)
	{
		if (i == workerNum )
		{
			supers[i].setName("");
			supers[i].setNumber(0);
			supers[i].setDate("");
			supers[i].setSalary(0.0);
			supers[i].setAnBonus(0.0);
		}
	}

	cout << "***Shift Supervisor deleted.***" << endl << endl;
}


void editSuper(ShiftSupervisor supers[], int size)
{
	// To hold input 
	string empName;
	int empNumber;
	string hireDate;

	bool tryAgain = true;

	// Holds the user input for employee number
	int workerNum;

	// Displays COMPLETE LIST OF PRODUCTION WORKERS FOR REFERENCE
	displaySuper(supers, size);

	cout << "Enter the number of the Shift Supervisor to edit: ";
	cin >> workerNum;

	// Subtract one from workerNum to make up for index
	workerNum -= 1;

	for (int i = 0; i < size; i++)
	{
		if (i == workerNum)
		{
			cout << "For identity protection we will only enter the last name of the employee\nat this time.\n\n";
			cout << endl << endl;


			cout << "Shift Supervisor " << (i + 1) << ":" << endl;
			cout << "Enter the last name of the employee: ";
			cin >> empName;
			cout << endl;
			cout << "Enter the employee number: ";
			cin >> empNumber;
			cout << endl;
			cout << "Enter the hire date(XX/XX/XX): ";
			cin >> hireDate;
			cout << endl; 
			cout << setprecision(2) << fixed;
			cout << "\t**Annual salary is fixed. Amount $" << ANNUAL_SALARY << " submitted.**\n\n";
			cout << "\t**Annual production bonus is also fixed at $" << ANNUAL_PROD_BONUS << " but is subject**\n\n";
			cout << "\t**to change depending on Shift Supervisor's results. Amount submitted.**\n";
			cout << endl;
			

			while (tryAgain)
			{
				try
				{
					supers[i].setName(empName);
					supers[i].setNumber(empNumber);
					supers[i].setDate(hireDate);
					supers[i].setSalary(ANNUAL_SALARY);
					supers[i].setAnBonus(ANNUAL_PROD_BONUS);

				//if no exception is thrown, then the exit
				//loop by changing 'tryAgain'
				tryAgain = false;
				}
				catch (ProductionWorker::InvalidEmployeeNumber)
				{
					cout << "\tEmployee Number cannot be less than 0 or greater than 9999.\n";
					cout << "Enter a new valid Employee Number: ";
					cin >> empNumber;
				}
			}
		}
	}

	cout << "***Shift Supervisor data changed.***" << endl << endl;
}
