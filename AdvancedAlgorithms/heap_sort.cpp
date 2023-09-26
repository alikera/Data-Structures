#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<pair<long long int, long long int> >& cities, long long int i, long long int size)
{
    long long int right = (2 * i) + 2;
    long long int max = i;
    long long int left = (2 * i) + 1;
 
    if (left < size && cities[left].first > cities[max].first)
        max = left;
 
    if (right < size && cities[right].first > cities[max].first)
        max = right;
 
    if (max != i)
    {
        swap(cities[i], cities[max]);
        heapify(cities, max, size);
    }
}

void build_heap(vector<pair<long long int, long long int> >& cities, long long int size)
{
    for (long long int i = (size / 2) - 1; i >= 0; i--)
        heapify(cities, i, size);
}
void heap_sort(vector<pair<long long int, long long int> >& cities, long long int size)
{
    build_heap(cities, size);
    for (long long int i = size - 1; i > 0; i--) 
    {
        swap(cities[0], cities[i]);
        heapify(cities, 0, i);
    }
}

int main()
{
    long long int n,d, shokolat, zarfiat;
    long long int prev = 0;
    long long int flag = 0;
    long long int max = 0;
    long long int curr = 0;
    long long int sum = 0;
    long long int sorted_untill = 0;
    cin >> n;

    vector<pair<long long int, long long int> > cities;

    for (long long int i = 0; i < n; ++i)
    {
        cin >> d;
        cities.push_back(make_pair(d,0));
    }

    for (long long int i = 0; i < n; ++i)
    {
        cin >> shokolat;
        cities[i].second = shokolat;
    }

    cin >> zarfiat;


    heap_sort(cities, n);

    curr = zarfiat;




    curr -= cities[0].first;
    if (curr < 0)
    {
        cout<< -1 << endl;
        return 0;
    }
    if(cities[1].first - cities[0].first > zarfiat)
    {
        cout<< -1 << endl;
        return 0;
    }





    long long int j = 1;
    long long int temp = 0;
    long long int sort_ended = 1;
    while(cities[0].second <= cities[j].second)
    {
        /* j++ */
        if(cities[j-1].second <= cities[j].second && sort_ended != 0)
            sorted_untill = j;

        else
            sort_ended = 0;

        j++;
        if (j == n)
        {
            j--;
            break;           
        }
    }

    temp = cities[j].first - cities[0].first;
    // cout << "temp" << temp << endl;
    if (temp >= zarfiat)
    {
        sum += (zarfiat - curr) * cities[0].second;
        curr = zarfiat;
    }
    else
    {
        if(temp > curr)
        {
            sum += (temp - curr) * cities[0].second;
            curr = temp;
        }
    }

    // cout << curr << endl;
    if(curr < cities[1].first - cities[0].first)
    {
        sum += (cities[1].first - cities[0].first - curr) * cities[0].second;
        curr += cities[1].first - cities[0].first - curr;
    }

    // cout << sorted_untill << endl;
        // cout << sum << endl;



    for (long long int i = 1; i < n - 1; ++i)
    {
        flag = 0;
        // cout << "curr "<<curr << i<< endl;
        if(sorted_untill < i)
            sorted_untill = i;

        curr -= cities[i].first - cities[i-1].first;

        if(cities[n-1].first - cities[i].first <= curr)
            continue;

        if (curr < 0)
        {
            cout<< -1 << endl;
            return 0;
        }
        if(cities[i+1].first - cities[i].first > zarfiat)
        {
            cout<< -1 << endl;
            return 0;
        }
        // cout << "curr_After "<<curr << endl;

        // cout << cities[i].first << endl;

        // if (i < sorted_untill)
        // {
        //     j = sorted_untill+1;
        // }
        j = sorted_untill+1;
        // cout << j << endl;

        if (j == n)
        {
            j--;
        }
        if(cities[j].first - cities[i].first < zarfiat)
        {
            j = sorted_untill+1;
            if (j == n)
            {
                j--;
            }
            temp = 0;
            sort_ended = 1;
            while(cities[i].second <= cities[j].second)
            {
                /* j++ */
                if(cities[j-1].second <= cities[j].second && sort_ended != 0 && i >= sorted_untill)
                    sorted_untill = j;

                else
                    sort_ended = 0;

                j++;

                if (j == n)
                {
                    j--;
                    break;
                }
                // cout << "here" << endl;
                // if (cities[j].first - cities[i].first >= zarfiat)
                //     break;
            }
        }

        temp = cities[j].first - cities[i].first;
            // cout << j <<" temp " << temp << endl;

        if (temp >= zarfiat)
        {
            sum += (zarfiat - curr) * cities[i].second;
            curr = zarfiat;
        }
        else
        {
            if(temp > curr)
            {
                sum += (temp-curr) * cities[i].second;
                curr = temp;
            }
        }

        if(curr < cities[i+1].first - cities[i].first)
        {
            long long int x = (cities[i+1].first - cities[i].first - curr) * cities[i].second;

            sum += x;
            curr += cities[i+1].first - cities[i].first - curr;
            // cout << "delta "<< x << endl;
        }
        // cout << i << " "<<sorted_untill <<" curr " <<curr<< endl;
        // cout << sum << endl << endl;

    }

    cout << sum << endl;

}