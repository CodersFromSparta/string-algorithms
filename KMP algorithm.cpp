#include <iostream>
#include <vector>
using namespace std;
template<typename T>
//overloading operator << to print vector containing multiple match positions
ostream& operator<< (ostream& out, const vector<T> v) {
    int last = v.size() - 1;
    out << "[";
    for(int i = 0; i < last; i++)
        out << v[i] << ", ";
    out << v[last] << "]";
    return out;
}
//----------------------------
//  Returns a vector containing the zero based index of
//  the start of each match of the string K in S.
//  Matches may overlap
//----------------------------
vector<int> KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
    //Partial Match Table
	vector<int> matches;

    if(K.size() == 0)
    {
        matches.push_back(0);
        return matches;
    }
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;

	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) matches.push_back(sp - K.size());
	}

	return matches;
}
int main()
{
    string Text, Pattern;
    vector<int> x;
    //cout << "Enter the text : ";
    cin >> Text;
    cout << Text << endl;
    //cout << "\nEnter the pattern : ";
    cin >> Pattern;
    cout << Pattern<<endl;
    x = KMP(Text, Pattern);
    if(x.empty())
       cout << "\nNo valid shifts occurred\n";
    else{
    	//cout << "\nPattern was found in " << x << " shifts at position : " << x+1;
    	cout << x << endl;
	}
	return 0;
}
