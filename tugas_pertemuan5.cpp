#include <iostream>
using namespace std;

// fungsi binary search iteratif
int iteratifBS(int data[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (data[mid] == target)
        {
            return mid;
        }
        else if (target < data[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// fungsi pengurutan ascending
void sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int data[20];
    int n = 0;
    int nilai = 0;
    int target;

    // user input nilai
    while (n < 20)
    {
        cout << "Masukkan nilai (-1 berhenti) : ";
        cin >> nilai;

        if (nilai == -1)
        {
            break;
        }

        data[n] = nilai;

        n++; // ukuran array yg kepake dihitung otomatis
    }

    cout << endl;

    sort(data, n); // data diurutkan

    // seluruh isi ditampilkan
    cout << "Data : ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Nilai yg dicari : ";
    cin >> target;

    int hasil = iteratifBS(data, n, target);

    if (hasil != -1)
    {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
