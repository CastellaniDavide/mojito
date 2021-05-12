/**
 * @file mojito.cpp
 *
 * @version 01.01 202155
 *
 * @brief mojito
 *
 * @ingroup mojito
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

struct pos
{
    int x;
    int y;
};

struct ragazzo
{
    pos da;
    pos a;
};

// Variabiles
int N;
pos grid, dog;
vector <ragazzo> ragazzi;
vector <int> visti;

int calc_dist(pos pos1, pos pos2)
{
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

void solve()
{
    int ragazzo_vicino = -1;
    int distanza = INT_MIN;
    for (size_t i = 0; i < N; ++i)
    {
        int d = calc_dist(dog, ragazzi[i].da);
        if (d < distanza)
        {
            distanza = d;
            ragazzo_vicino = i;
        }
    }

    if(std::find(visti.begin(), visti.end(), ragazzo_vicino) == visti.end())   // If not exists yet
    {
        visti.push_back(ragazzo_vicino);
        dog = ragazzi[ragazzo_vicino].a;
        solve();
    }
}

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Input
    cin >> grid.x, grid.y;
    cin >> dog.x, dog.y;
    cin >> N;

    for (size_t i = 0; i < N; ++i)
    {
        ragazzo temp;
        cin >> temp.da.x >> temp.da.y >> temp.a.x >> temp.a.y;
        ragazzi.push_back(temp);
    }

    solve();

    // Output
    cout << visti.size() << endl;

    // End
    return 0;
}
