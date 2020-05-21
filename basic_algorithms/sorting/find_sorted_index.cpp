#include <iostream>

using namespace std;

struct info
{
    int data;
    int curr;
    int prev;
};

void swap(info &x, info &y)
{
    info temp = x;
    x = y;
    y = temp;
    
    int i = x.curr;
    x.curr = y.curr;
    y.curr = i;
    
}
    
int main(void)
{
    int N;
    cin >> N;

    info arr[N];
    int index[N];
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].data;
        arr[i].curr = i;
        arr[i].prev = i;
    }
    
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i+1; j < N; j++)
        {
            if (arr[j].data < arr[min].data) min = j;
        }
        swap(arr[i], arr[min]);
    }
    for (int i = 0; i < N; i++) index[arr[i].prev] = arr[i].curr; 
    for (int i = 0; i < N; i++) cout << index[i]+1 << " ";
    cout << endl;
    
}