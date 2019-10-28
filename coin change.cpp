#define MAX_POINT 16 
#define ARR_SIZE 100 
#include<iostream> 
using namespace std;
/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size); 
  
/* The function prints all combinations of numbers 1, 2, ...MAX_POINT 
that sum up to n. 
i is used in recursion keep track of index in arr[] where next 
element is to be added. Initital value of i must be passed as 0 */
string s;
void printCompositions(int n, int i) 
{ 
  
    /* array must be static as we want to keep track 
    of values stored in arr[] using current calls of 
    printCompositions() in function call stack*/
    //static int arr[ARR_SIZE]; 
    
    if (n == 0 && s.length()==4) 
    { 
        //printArray(arr, i);
		cout<<s<<endl; 
    } 
    else if(n > 0) 
    { 
        int k;  
        for (k = 1; k <= MAX_POINT; k++) 
        { 
        //arr[i]= k;
		s.insert(s.length(),1,'a'+k-1); 
        printCompositions(n-k, i+1); 
        s.erase(s.length()-1,1);
        } 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Utility function to print array arr[] */ 
void printArray(int arr[], int arr_size) 
{ 
    int i; 
    for (i = 0; i < arr_size; i++) 
       cout<<arr[i]; 
    cout<<endl;
} 
  
/* Driver function to test above functions */
int main() 
{ 
    int n = 40; 
      
    cout<<"Lexographically smallest combintion formed by alphabets for "<<n<<" are : \n";
    printCompositions(n, 0); 
    return 0; 
} 
