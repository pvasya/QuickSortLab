#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void quickSort(vector<int>& vec, int low, int high, vector<int>& vec2, vector<float>& vec3) {
	if (low >= high)
		return;
	int pivot = vec[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (vec[j] <= pivot) {
			i++;
			swap(vec[i], vec[j]);
			swap(vec2[i], vec2[j]);
			swap(vec3[i], vec3[j]);
		}
	}
	swap(vec[i + 1], vec[high]);
	swap(vec2[i + 1], vec2[high]);
	swap(vec3[i + 1], vec3[high]);
	int index = i + 1;
	quickSort(vec, low, index - 1,vec2,vec3);
	quickSort(vec, index + 1, high, vec2, vec3);
}

void quickSort(vector<float>& vec, int low, int high, vector<int>& vec2, vector<int>& vec3) {
	if (low >= high)
		return;
	float pivot = vec[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (vec[j] <= pivot) {
			i++;
			swap(vec[i], vec[j]);
			swap(vec2[i], vec2[j]);
			swap(vec3[i], vec3[j]);
		}
	}
	swap(vec[i + 1], vec[high]);
	swap(vec2[i + 1], vec2[high]);
	swap(vec3[i + 1], vec3[high]);
	int index = i + 1;
	quickSort(vec, low, index - 1, vec2, vec3);
	quickSort(vec, index + 1, high, vec2, vec3);
}

int main() {
	int i = 0;
	int ii;
	string data,s,value;
	cout << "Enter a file name to sort" << endl << "> ";
	cin >> data;
	vector <int> post_id;
	vector <int> user_id;
	vector <float> involvement;
	ifstream file(data + ".csv");
	while (getline(file, s)) {
		ii = 0;
		value = "";
		while (s[ii] != ',') {
			value += s[ii++];
		}
		post_id.push_back(stoi(value));
		value = "";
		ii++;
		while (s[ii] != ',') {
			value += s[ii++];
		}
		user_id.push_back(stoi(value));
		value = "";
		ii++;
		while (ii<s.length()) {
			value += s[ii++];
		}
		involvement.push_back(stof(value));
	}
	file.close();
	
	quickSort(user_id, 0, user_id.size()-1, post_id, involvement);
	int k = 0, j = 0;
	while (j < involvement.size()) {
		if(user_id[k] != user_id[j]) {
			quickSort(involvement, k, j-1, post_id, user_id);
			k = j;
		}
		j++;
	}
	quickSort(involvement, k, user_id.size()-1, post_id, user_id);

	fstream fout;
	fout.open("sorted.csv", ios::out);
	for (int i = 0; i < involvement.size(); i++) {
		fout << post_id[i] << ","
			<< user_id[i] << ","
			<< involvement[i]<< endl;
	}
	fout.close();
	return 0;
}