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
    bool visto = false;
};

// Variabiles
int N, sol;
pos grid, dog;
vector <ragazzo> ragazzi;

int calc_dist(pos pos1, pos pos2)
{
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

void solve(pos by)
{
    int ragazzo_vicino = -1;
    int distanza = INT_MAX;
    for (size_t i = 0; i < N; ++i)
    {
        int d = calc_dist(by, ragazzi[i].da);
        if (d < distanza)
        {
            distanza = d;
            ragazzo_vicino = i;
        }
    }

    if(!ragazzi[ragazzo_vicino].visto)
    {
        ragazzi[ragazzo_vicino].visto = true;
        sol++;
        solve(ragazzi[ragazzo_vicino].a);
    }
}

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Input
    cin >> grid.x >> grid.y;
    cin >> dog.x >> dog.y;
    cin >> N;
    sol = 0;

    for (size_t i = 0; i < N; ++i)
    {
        ragazzo temp;
        cin >> temp.da.x >> temp.da.y >> temp.a.x >> temp.a.y;
        ragazzi.push_back(temp);
    }

    solve(dog);

    // Output
    cout << sol << endl;

    // End
    return 0;
}
