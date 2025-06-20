#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "abcdef";
    // Compare substring "bcd" starting at index 1 with "bcd"
    if (s.compare(4, 3, "efg") == 0)
    {
        cout << "Substring matches 'efg'" << endl;
    }
    else
    {
        cout << "Substring does not match 'efg'" << endl;
    }

    // Compare substring "ef" starting at index 4 with "ef"
    if (s.compare(4, 2, "ef") == 0)
    {
        cout << "Substring matches 'ef'" << endl;
    }
    else
    {
        cout << "Substring does not match 'ef'" << endl;
    }

    // Compare substring at index 5 with "fg" (should not match)
    if (s.compare(5, 2, "fg") == 0)
    {
        cout << "Substring matches 'fg'" << endl;
    }
    else
    {
        cout << "Substring does not match 'fg'" << endl;
    }

    // Compare substring at index 5 with "f" (should match)
    if (s.compare(5, 2, "f") == 0)
    {
        cout << "Substring matches 'f'" << endl;
    }
    else
    {
        cout << "Substring does not match 'f'" << endl;
    }

    return 0;
}
