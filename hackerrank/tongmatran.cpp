// in ra ma trận là tổng của 2 ma trận cho trước

#include <iostream>
#include <vector>

using namespace std;

// Hàm đọc ma trận có kích thước N x M
vector<vector<int>> readMatrix(int N, int M) {
    // Khởi tạo ma trận rỗng N x M
    vector<vector<int>> matrix(N, vector<int>(M)); 
    
    // Đọc N * M phần tử
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Hàm in ma trận
void printMatrix(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    if (N == 0) return;
    int M = matrix[0].size();
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << matrix[i][j] << (j == M - 1 ? "" : " "); // In cách nhau bởi dấu cách
        }
        cout << endl; // Xuống dòng sau mỗi hàng
    }
}

void solve() {
    int N, M;
    // Đọc kích thước N (hàng) và M (cột)
    cin >> N >> M; 

    // Đọc Ma trận A (N x M)
    vector<vector<int>> A = readMatrix(N, M);

    // Đọc Ma trận B (N x M)
    vector<vector<int>> B = readMatrix(N, M);

    // Khởi tạo Ma trận kết quả C (N x M)
    vector<vector<int>> C(N, vector<int>(M));

    // Thực hiện phép cộng ma trận
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Cộng phần tử tương ứng: C[i][j] = A[i][j] + B[i][j]
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // In Ma trận kết quả C
    printMatrix(C);
}

int main() {
    // Sử dụng ios::sync_with_stdio(false); để tăng tốc độ nhập/xuất
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Đọc số lượng test case (T <= 1000)
    cin >> T; 

    while (T--) {
        solve();
    }

    return 0;
}