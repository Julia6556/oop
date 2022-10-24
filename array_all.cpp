
#include<iostream>//бібліотека потоків
using namespace std;

#include<ctime>//random
#include<malloc.h>
#include<fstream>//file
#include<conio.h>//getch
#include<windows.h>//system cls
#include<vector>
#include<cmath>//math.h

int *arr;//new and malloc array
int arrs[100];//static array 100
vector<int> ar;//vector

void create_arr(int code, int size){//add memory to the array(code - 1static, 2malloc, 3new, 4vector)
	switch(code){
		case 1:
			cout<<"\n\nChoosed static array\n\n";
			break;
		case 2:
			arr = (int*)malloc(size*sizeof(int));
			cout<<"\n\nChoosed dynamic malloc array\n\n";
			break;
		case 3:
			arr = new int[size]; // (new) зручний спосіб виділення пам'яті замість malloc, calloc, free + виділяє пам'ять під масив об'єктів
			cout<<"\n\nChoosed dynamic new array\n\n";
			break;
		case 4:
			ar.resize(size,true);
			cout<<"\n\nChoosed vector class array\n\n";//структура даних, яка вже є моделлю динамічного масиву + не потрібно працювати розподілом
			break;
	}
}

int main(){
	srand(time(NULL));//start random, генерація випадкових чисел
	
	int size = 0;//array size
	int choose = 0;//users choos for menus
	bool flag = true;//flag for breake cycles while
	int code_array=0;//choosed array(1 - static, 2 - malloc, 3 - new, 4 - vector)
	ifstream file;//file in directory
	file.open("file.txt");
	
	while(flag){//choose type of memory
		cout<<"What type of array you wanna choose?\n\n";
		cout<<"1 - Static\n2 - Dynamic malloc\n3 - Dynamic new\n4 - Vector class lib\n\n>> ";
		cin>>choose;
		switch(choose){
			case 1:
				code_array = choose;
				flag = false;
				break;
			case 2:
				code_array = choose;
				flag = false;
				break;
			case 3:
				code_array = choose;
				flag = false;
				break;
			case 4:
				code_array = choose;
				flag = false;
				break;
			default:
				cout<<"\n\nIncorrect input! Choose 1, 2, 3 or 4\n\n";
				_getch();
				system("cls");
		}
	}
	
	cout<<"Enter a size of array(>0 or it will    be created autometically) >> ";
	cin>>size;
	
	if(size<=0 || size > 99)//if -<size<99 use random size
		size = rand()%10+5;
	
	create_arr(code_array, size);
	
	flag = true;
	while(flag){//enter array
		cout<<"\n\nSize = "<<size<<"\n\nWhat type of create array you want to choose?\n\n";
		cout<<"1 - Keyboard\n2 - File file.txt in directory\n3 - Random\n\n>> "; cin>>choose;
		switch(choose){
			case 1://keyboard
				for(int i = 0; i < size; i++){
					cout<<">> ";
					if(code_array==1){
						cin>>arrs[i];
					}
					else if(code_array==2 || code_array==3){
						cin>>arr[i];
					}
					else if(code_array==4){
						cin>>ar[i];
					}
				}
				flag = false;
				break;
			case 2://file
				for(int i = 0; i < size; i++){
					if(code_array==1){
						file>>arrs[i];
					}
					else if(code_array==2 || code_array==3){
						file>>arr[i];
					}
					else if(code_array==4){
						file>>ar[i];
					}
				}
				flag = false;
				file.close();
				break;
			case 3://rand
				for(int i = 0; i < size; i++){
					if(code_array==1){
						arrs[i] = rand()%80-40;
					}
					else if(code_array==2 || code_array==3){
						arr[i] = rand()%80-40;
					}
					else if(code_array==4){
						ar[i] = rand()%80-40;
					}
				}
				flag = false;
				break;
			default:
				cout<<"\n\nIncorrect input! Choose 1, 2 or 3\n\n";
				_getch();
				system("cls");
		}
	}
	
	cout<<"\n\nArray are:\n\n";//show array
	if(code_array==1){
		for(int i = 0; i < size; i++){
			cout<<arrs[i]<<"\t";//де t табуляція 
		}
	}
	else if(code_array==2 || code_array==3){
		for(int i = 0; i < size; i++){
			cout<<arr[i]<<"\t";
		}
	}
	else if(code_array==4){
		for(int i = 0; i < size; i++){
			cout<<ar[i]<<"\t";
		}
	}
	
	//task 1
	vector<int> arr_new;
	arr_new.resize(size, true);//new array, де resize змінює розмір масиву
	
	for(int i = 0; i < size; i++){
		if(code_array==1){
			arr_new[i] = pow(2, arrs[i])*arrs[i];// де pow піднесення до степеня		
			}
		else if(code_array==2 || code_array==3){
			arr_new[i] = pow(2, arr[i])*arr[i];
		}
		else if(code_array == 4){
			arr_new[i] = pow(2, ar[i])*ar[i];
		}
	}
	
	cout<<"\n\nTask 1 new array (2^i)*(ai) are:\n\n";
	for(int i = 0; i < size; i++){//sometimes there are TOO LARGE numbers
		cout<<arr_new[i]<<"\t";
	}
	
	//task 2
	int c,d;//diapason
	int index_max_last = 0;//last max element index
	int first_paired = 0;//first paired element index
	
	cout<<"\n\nEnter an borders [c,d] >> "; cin>>c; cin>>d;
	
	for(int i = 0; i < size; i++){//find index of first paired element
		if(code_array==1){
			if(arrs[i]%2==0){
				first_paired = i;
				break;
			}
		}
		else if(code_array==2 || code_array==3){
			if(arr[i]%2==0){
				first_paired = i;
				break;
			}
		}
		else if(code_array == 4){
			if(ar[i]%2==0){
				first_paired = i;
				break;
			}
		}
	}
	
	index_max_last = first_paired;
	
	for(int i = 0; i < first_paired; i++){//find index of last max element from c to d
		if(code_array==1){
			if(arrs[i]>=c && arrs[i]<=d && arrs[i]>arrs[index_max_last])
				index_max_last = i;
		}
		else if(code_array==2 || code_array==3){
			if(arr[i]>=c && arr[i]<=d && arr[i]>arr[index_max_last])
				index_max_last = i;
		}
		else if(code_array == 4){
			if(ar[i]>=c && ar[i]<=d && ar[i]>ar[index_max_last]) //&& оператор і
				index_max_last = i;
		}
	}
	
	cout<<"\n\nLast max element [c,d] before first paired element = "<<index_max_last<<"\n\n";
	
	_getch();
	return 0;
}
