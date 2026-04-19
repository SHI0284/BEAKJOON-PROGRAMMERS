#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (int k = 0; k < queries.size(); k++) {
        int i = queries[k][0];
        int j = queries[k][1];
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    return arr;
}