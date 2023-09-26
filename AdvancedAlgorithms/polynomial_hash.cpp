#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<bool> my_hash;
int LUT[26];
int trigger = 1;
long long int power_26(long long int y)
{
    long long int t;
    if(y == 0)
        return 1;

    t = power_26(y / 2);

    if (y % 2 == 0)
        return t * t;
    else
    {
        if(y > 0)
            return 26 * t * t;
        else
            return (t * t) / 26;
    }
}

void creat_look_up_table()
{
    for (int i = 0; i < 26; ++i)
        LUT[i] = i + 1;
}
long long int polynomial_hash(string v_hash, long long int from, long long int to)
{
    long long int hash_output = 0;
    trigger++;
    long long int p =1;
    for (long long int i = from; i < to; i++)
    {
        p = p*101;
        hash_output =( (to-from)*int(v_hash[i])+(hash_output + LUT[v_hash[i] - 'a'] * LUT[(v_hash[i] - 'a' + 97) % 27])*p ) % (long long int)(327047902219);
    }

    return hash_output;
}
// void create_hash_table(string name, vector<long long int>& hash_table, long long int length)
// {
//     for (long long int i = 1; i <= length; ++i)
//     {
//         string temp = name.substr(0, i);
//         cout << temp << endl;
//         hash_table.push_back(polynomial_hash(temp, length, name ) );
//     }
// }

// void create_hash_end(string name, vector<long long int>& hash_end, long long int length)
// {
//     for (long long int i = 1; i <= length; ++i)
//     {
//         string temp = name.substr(length - i, i);
//         cout << temp << endl;
//         hash_end.push_back(polynomial_hash(temp, length, name ) );
//     }
// }
int main()
{
    long long int n,m;
    cin >> n >> m;
    string name;
    cin >> name;
    long long int result = 1;
    long long int length = name.size();
    vector<bool> h(length, false);
    my_hash = h;
    if(m == 0)
    {
        for (long long int i = 0; i < n; ++i)
            result = (result * 26)%1000000007;
        
        cout << result << endl;

        return 0;
    }
    creat_look_up_table();
    // cout << polynomial_hash(name, 0,1) << endl;
    // cout << polynomial_hash(name, length-2,length-1) << endl;


    // vector<long long int> hash_table;
    // create_hash_table(name, hash_table, length);

    // vector<long long int> hash_end;
    // create_hash_end(name, hash_end, length);

    // cout << hash_end.size() << " " << hash_table.size() << endl;

    long long int index;
    cin >> index;
    index--;
    long long int prev = index;
    long long int counter = 0;
    counter += prev;
    long long int curr;
    for (long long int i = 1; i < m; ++i)
    {
        cin >> curr;
        curr--;

        if(prev + length <= curr)
        {
            counter += curr - length - prev;
            prev = curr;
            continue;
        }

        long long int dist = curr - prev;
        if(my_hash[length-dist])
        {
            prev = curr;
            continue;
        }

        if(polynomial_hash(name, 0, length-dist) != polynomial_hash(name, dist, length))
        {
            cout << 0 << endl;
            return 0;
        }
        else
            my_hash[length-dist] = true;

        prev = curr;
    }
    if(m > 1)
        counter += n - length - curr;
    else if(m == 1)
        counter += n - length - prev;
    else
        counter = n;

    for (long long int i = 0; i < counter; ++i)
        result = (result * 26)%1000000007;

    cout << result << endl;
    return 0;
}
