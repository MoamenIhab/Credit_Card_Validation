/*Moamen Ihab's code
Credit Card Validation Software in C++
-----------------------------------------------------*/
#include<iostream>
#include<unistd.h>

using namespace std;


int main(void)
{
    //Prompting the user for Valid Input
    unsigned long int input = 0;
    do{
      cout <<"Number:";
     cin >> input;
    }
    while(input <0);
    //checking the Number count of the card
    unsigned long int num = input;

     int count =0;
    while(num >0)
    {
        num = num/10;
        count++;
    }
    if ((count != 13) && (count !=15) && (count != 16))
    {
        cout << "INVALID CARD" <<endl;
    }
    else{
    int arr[count];
    num = input;
    int mlt = 0;
    int r1 = 0;
    int r2 = 0;
    int t1, t2 = 0;
    //having an array carry each number for further calculations
    for (int i = 0; i<count;i++)
    {
        arr[i]= num % 10;
        num = num /10;
    }
    //Luhn's algo for validation
    num = input;
    for (int y = 1; y<count+1;y=y+2)
    {

        mlt=arr[y]*2;
        if(mlt / 10 > 0)
        {
            t1 = mlt %10;
            t2 = mlt /10;
            t1 = t1 + t2;
            r1 = r1 +t1;
        }
        else{ r1 = r1 + mlt;}

    }
    for(int w = 0; w <count; w=w+2)
    {
        r2 = r2+arr[w] ;
    }
    r2=r2+r1;
    int v1 = arr[count-1];
    int v2 = (arr[count-1]*10)+arr[count-2];


// Printing Out Results
if (r2 % 10 == 0)
{
    if (v1 == 4 && count >= 13 && count <= 16 )
    {
        cout << "Valid Card"<< endl;
        cout << "Credit Card Company:";
        sleep(1);
        cout << "VISA" << endl;
    }
    else if (v2 >= 51 && v2 <= 55 && count == 16 )
    {
        cout << "Valid Card"<< endl;
        cout << "Credit Card Company:";
        sleep(1);
        cout << "MASTERCARD" <<endl;
    }
    else if ((v2 == 34 || v2 == 37) && count == 15 )
    {
        cout << "Valid Card"<< endl;
        cout << "Credit Card Company:";
        sleep(1);
        cout << "AMERICAN EXPRESS" << endl;
    }
    else if (v1 == 6 && count == 16 )
    {
        cout << "Valid Card"<< endl;
        cout << "Credit Card Company:";
        sleep(1);
        cout << "DISCOVER" << endl;
    }
    else
    {
       cout << "INVALID CARD" << endl;
    }
}
 else
    {
        cout << "INVALID CARD" <<endl;
    }

}


}
