

#include "std_lib_facilities.h"
#include "matrix.h"
#include "dummy.h"
void fillInFibonacciNumbers(int result[],int length){
	int number1=0;
	int number2=1;
	for (int i = 0; i < length; i++)
	{
		int fibNumber=number1+number2;
		result[i]=number1;
		//cout << result[i]<< " ";
		number1=number2;
		number2=fibNumber;
	}
	//delete[] result;
}
void printArray(int arr[],int length){
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}
void createFibonacci(){
	int nNumbers;
	cout << "Skriv inn antall tall: ";
	cin >> nNumbers;
	int*arr = new int[nNumbers];
	fillInFibonacciNumbers(arr,nNumbers);
	printArray(arr,nNumbers);
}


int main()
{
	int sjekk=1;
	while (sjekk!=0)
	{
		cout << "1. Fibonacci\n2.getMatrix\n3.Dummy\n4.OperatorSjekk\n";
		cin >> sjekk;
		if (sjekk==1){
			createFibonacci();
		}
		else if(sjekk==2){
			Matrix A{4};
			Matrix B;
			Matrix C{10,3};
			for (int i = 0; i < C.getRows(); i++)
			{
				for (int j = 0; j < C.getColumns(); j++)
				{
					C.set(i,j,2.0*i+j);
				}
				
			}
			
			//double out= B.get(3,3);
			
			cout << "Verdi: " << A.get(3,3) << endl;
			cout << "Verdi: " << B << endl;
			cout << "Verdi: " << C.get(2,6) << endl;
			cin.get(); //hindre at programmet slutter???

			//cout << out << endl;
		}
		else if(sjekk==3){
			dummyTest();
		}
		else if(sjekk==4){
			Matrix D{2,2};
			D.set(0,0,1.0);
			D.set(0,1,2.0);
			D.set(1,0,3.0);
			D.set(1,1,4.0);
			Matrix E{2,2};
			E.set(0,0,4.0);
			E.set(0,1,3.0);
			E.set(1,0,2.0);
			E.set(1,1,1.0);
			Matrix F{2,2};
			F.set(0,0,1.0);
			F.set(0,1,3.0);
			F.set(1,0,1.5);
			F.set(1,1,2.0);
			cout <<(D+=E+F) << endl;
			//cout << (D+=E+F) << endl;
	
		}

	}
	
	//int* fibArr=new int;
	//fillInFibonacciNumbers(fibArr,15);


	keep_window_open();
}

//------------------------------------------------------------------------------
