#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout << "Number of Processes : \n";
    cin >> num;
    int array_at[num];
    cout << "Enter the ARRIVAL TIME for each process in asscending order: \n";
    for (int i = 0; i < num; i++)
    {
        cin >> array_at[i];
       
    }
    int array_bt[num];
    cout << "Enter the BURST for each process in asscending order : \n";
    for (int i = 0; i < num; i++)
    {
        cin >> array_bt[i];
       
    }
    int array_ct[num];
    int array_tat[num];
    int array_wt[num];
    int bt=0;
    for (int i = 0; i < num; i++)
    {
        bt=bt+array_bt[i];
        array_ct[i]=array_bt[i]+bt;
    }
    for (int i = 0; i < num; i++)
    {
       
        array_tat[i]=array_ct[i]-array_at[i];
    }
    for (int i = 0; i < num; i++)
    {
       
        array_wt[i]=array_tat[i]-array_bt[i];
    }
    cout << "\n";
    cout << "COMPLETION TIME : " << " ";
    for (int i = 0; i < num; i++)
    {
       
        cout << array_ct[i] << " ";
    }
    cout << "\n";
    cout << "TURN AROUND TIME : " << " ";
    for (int i = 0; i < num; i++)
    {
       
        cout << array_tat[i] << " ";
    }
    cout << "\n";
    cout << "WAITING TIME " << " ";

    for (int i = 0; i < num; i++)
    {
       
        cout << array_wt[i] << " ";
    }
    return 0;
}
