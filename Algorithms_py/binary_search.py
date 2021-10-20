#include<iostream>
using namespace std;

int main()
{
    int DATA[20], n, i, j, middle, first, last, item, k, t;
    cout<<"This program searches an element in the given array using binary search method: \n";
    cout<<"Enter the number of elements you want to enter in the array: \n";
    cin>>n;
    cout<<"You need to insert the elements one by one\n";
    for(i=0;i<n;i++)
    {
        cout<<"Enter element: ";
        cin>>DATA[i];
    }
    cout<<"Our inserted array is:";
    for(i=0;i<n;i++)
    {
        cout<<DATA[i]<<"  ";
    }
    cout<<endl;
    cout<<"Enter the element you want to search in the array: \n";
    cin>>item;
    for(j=0;j<n;j++)
    {
        for(k=0;k<n-j-1;k++)
        {
            if (DATA[k]>DATA[k+1])
            {
                t=DATA[k];
                DATA[k]=DATA[k+1];
                DATA[k+1]=t;
            }
        }
    }
    //Displaying sorted array elements
    cout<<"Sorted array:- \n";
    for(i=0;i<n;i++)
    {
        cout<<DATA[i]<<" ";
    }
    cout<<endl;
	first = 0;
	last = n-1;
	middle = (first+last)/2;
	while (first <= last)
	{
	   if(DATA[middle] < item)
	   {
		first = middle + 1;

	   }
	   else if(DATA[middle] == item)
	   {
		cout<<"Element found in the array at index "<<middle+1<<"\n"; 
                break; 
           } 
           else { 
                last = middle - 1; 
           } 
           middle = (first + last)/2; 
        } 
        if(first > last)
	    {
	       cout<<"Element not found in the array";
	    }
	return 0;
}


