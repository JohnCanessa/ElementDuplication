#include <iostream>
#include <exception>
//#include <string>

using namespace std;

#pragma warning(disable:6011)


/// <summary>
/// Replicate the element at that index and `replace` it with the last element in the array. 
/// If the index specified is beyond the array size, 
/// throw a runtime_error with the error message : “Array index is out of range”.
/// </summary>
void elementDuplication(int* ar, int size, int pos) {

    // **** sanity check(s) ****
    if (ar == NULL || size == 0)
    {
        throw runtime_error("Invalid argument(s)");
    }
    if (pos < 0 || pos > size - 1)
    {
        throw runtime_error("Array index is out of range");
    }

    // **** replicate the element ****
    ar[size - 1] = ar[pos];
}


/// <summary>
/// Test scaffold.
/// </summary>
/// <returns></returns>
int main()
{

    // **** initialization ****
    int size{0};
    int pos{0};
    int* ar = {NULL};

    // **** prompt and get array size ****
    cout << "Enter the size of an array" << endl;
    cin >> size;

    // *** declare array ****
    ar = (int*)calloc(size, sizeof(int));
    if (ar != NULL)
    {
        // **** prompt for array elelemnts and populate array ****
        cout << "Enter the array elements" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> ar[i];
        }

        //// ???? ????
        //for (int i = 0; i < size; i++)
        //    cout << ar[i] << ' ';
        //cout << endl;

        // **** prompt for the pos of the element in the array to be replicated 
        cout << "Enter the index position of the element in the array to be replicated" << endl;
        cin >> pos;

        // **** duplicate element and display result ****
        try
        {

            // **** duplicate element ****
            elementDuplication(ar, size, pos);

            // **** display array ****
            for (int i = 0; i < size; i++)
                cout << ar[i] << ' ';
            cout << endl;
        }
        catch (runtime_error& e)
        {
            cerr << e.what() << endl;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
        }
    }

    // **** assume that all went well ****
    return 0;
}
