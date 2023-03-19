#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<ctime>

using namespace std;

int main() {
    srand(time(NULL));
    int n;
    cout << "n = ?" << endl << "> ";
    cin >> n;
    vector <int> post_id;
    vector <int> user_id;
    vector <float> involvement;

    for (int i = 1; i <= n; i++) {
        post_id.push_back(i);
        user_id.push_back((rand() % n / 10)+1);
        involvement.push_back(rand() % 10001);
    }

    random_shuffle(post_id.begin(), post_id.end());
    random_shuffle(user_id.begin(), user_id.end());

    fstream fout;
    fout.open("data.csv", ios::out);

    for (int i = 0; i < n; i++) {
        fout << post_id[i] << ","
            << user_id[i] << ","
            << involvement[i] / 10000 << endl;
    }
    fout.close();
    return 0;
}
