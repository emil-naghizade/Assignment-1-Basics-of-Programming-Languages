# Assignment-1-Basics-of-Programming-Languages

# Task 1.
The computer memory is the large array of bytes and indices to this array is called addresses. When the given data is programmed to be stored in a certain address, that means the bit string representing the data is stored in consecutive memory bytes starting from that address. However, storage of the given data in memory can be in two orders, whether from most significant bit (MSB) to least significant bit (LSB), or in reverse order. The endianness refers to these arrangements of data bytes stored in computer memory. The arrangement of storing the MSB in the smaller address is named as big-endian while the reverse order is referred to as little-endian. Endianness can impact the data interpretation and sharing, therefore, the use cases of each endian for different architecture should be considered. 
Big-endian is mainly used in network communications and some file formats. The main reasons for this include human readability, performance consideration, historical precedence and standardization:
  
  •	Human Readability – big-endian has high readability from human perspective since it aligns with the natural left-to-right reading format. 
  •	Historical precedence and standardization – because of high readability, many early network protocols used big-endian format, and this led to continuous use of big-endian format in later protocols in order to provide standardization between network protocols. 
  •	Performance Consideration – The design of these architectures also makes big-endian format more efficient in parsing of multi-byte data types. In many network protocols MSBs contain important control information (e.g., IP header). In addition, some file formats start with specific sequence of bytes indicating the type of encoding or file type. Big-endian format ensures this critical information is read first.

Little-endian is the more efficient arrangement for CPUs in terms of processing and manipulating the data at the hardware level. The use cases where the little-endian has advantage are as following:
 
  •	Accessing small data types – storing the LSB first in memory in little-endian format makes an easy access to the small data types without reading entire multi-byte data type.
  •	Incrementing values – direct access to LSB allows for faster data manipulation since incrementing starts from LSB. For instance, incrementing the first byte of 32-bit integer 00000007 can be performed directly by accessing LSB, unlike big-endian format where traversing through bytes starting from MSB to LSB is required. 
  •	Handling Overflow – during arithmetic operations overflow and carry propagation mainly starts from the LSB and the carry is added to next byte. For instance, incrementing 32-bit integer FFFFFFFF leads to carry propagation starting from LSB and change in first byte from FF to 00 allows for faster check of carry propagation. Direct access to LSB allows for a reduced number of operations in comparison to the big-endian format.
  
In summary, little-endian format is more efficient in arithmetic operations and enables quick execution. The big-endian format is used in instances where the essential information is stored in the most significant bytes. This format is effective in quickly identifying the key attributes and processing data. However, effectiveness of big-endian format stems from its historical precedence, such that altering the network protocols in a way that essential information is stored in least significant bytes will eliminate the listed advantages of big-endian. 

# Task 2

tpl = (1,2,3)
print('Size of the tuple:',tpl.__sizeof__())

This code returns the size of the tuple. In python, the tuple is immutable so that it cannot be resized, and its elements cannot be modified. Since the tuple is fixed size, overhead for dynamic resizing is not required and it occupies less memory than list.


lst = [1,2,3]
print('Size of the list:',lst.__sizeof__())

This code returns the size of the list. In python, the list is mutable so that it can be resized and it elements can be accessed and modified. Therefore, the list requires additional overhead for dynamic resizing and modification. This leads to occupying more memory and makes it less memory-efficient than tuple.


# Task 3

The task is to perform a matrix multiplication. The code has been written in two programming languages; C++ and Python. In C++ code 2 test cases are provided:
1. With Predefined matrices
2. With matrices defined by user input.

In Python code 3 test cases are provided:
1. With Predefined matrices
2. With matrices that - sizes defined by user input, elements defined by random function. This is added to generate unit tests for C++ code.
3. With matrices defined by user input.

Codes provided by ChatGPT for this task is as follows:
#Python code
def matrix_multiply(A, B):
    if len(A[0]) != len(B):
        raise ValueError("Incompatible matrices for multiplication.")
    
    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    
    return result

// Predefined matrices test

def test_predefined_matrices():
    A = [[1, 2, 3],
         [4, 5, 6]]
    B = [[7, 8],
         [9, 10],
         [11, 12]]
    
    C = matrix_multiply(A, B)
    print("Predefined matrices result:")
    print(C)  # Output: [[58, 64], [139, 154]]

"""User input matrices test"""
def test_user_input_matrices():
    print("Enter matrix A dimensions (rows cols):")
    rows_A, cols_A = map(int, input().split())
    A = []
    print("Enter matrix A:")
    for _ in range(rows_A):
        row = list(map(int, input().split()))
        A.append(row)

    print("Enter matrix B dimensions (rows cols):")
    rows_B, cols_B = map(int, input().split())
    B = []
    print("Enter matrix B:")
    for _ in range(rows_B):
        row = list(map(int, input().split()))
        B.append(row)

    try:
        C = matrix_multiply(A, B)
        print("User-defined matrices result:")
        for row in C:
            print(row)
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    test_predefined_matrices()
    test_user_input_matrices()
""" End of code """


// C++ code

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    if (A[0].size() != B.size()) {
        throw invalid_argument("Incompatible matrices for multiplication.");
    }
    
    vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
    
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B[0].size(); ++j) {
            for (size_t k = 0; k < B.size(); ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}

// Predefined matrices test

void testPredefinedMatrices() {
    vector<vector<int>> A = {{1, 2, 3},
                              {4, 5, 6}};
    vector<vector<int>> B = {{7, 8},
                              {9, 10},
                              {11, 12}};
    vector<vector<int>> expected = {{58, 64},
                                     {139, 154}};
    vector<vector<int>> result = matrixMultiply(A, B);
    
    cout << "Predefined matrices result:\n";
    for (const auto& row : result) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// User input matrices test

void testUserInputMatrices() {
    int rows_A, cols_A;
    cout << "Enter matrix A dimensions (rows cols): ";
    cin >> rows_A >> cols_A;
    vector<vector<int>> A(rows_A, vector<int>(cols_A));
    
    cout << "Enter matrix A:\n";
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_A; ++j) {
            cin >> A[i][j];
        }
    }

    int rows_B, cols_B;
    cout << "Enter matrix B dimensions (rows cols): ";
    cin >> rows_B >> cols_B;
    vector<vector<int>> B(rows_B, vector<int>(cols_B));
    
    cout << "Enter matrix B:\n";
    for (int i = 0; i < rows_B; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            cin >> B[i][j];
        }
    }

    try {
        vector<vector<int>> C = matrixMultiply(A, B);
        cout << "User-defined matrices result:\n";
        for (const auto& row : C) {
            for (int value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

int main() {
    testPredefinedMatrices();
    testUserInputMatrices();
    return 0;
}

// End of code

The input for ChatGPT to generate these codes are as follows:

1.	Implement matrix multiplication in Python and C-like languages (C, C++, or Java). Write unit tests for C-like implementation to make sure the multiplication is correct. Perform an analysis of the code size and execution time.
2.	Each code should have 2 test cases, one with predefined matrices, another with matrices created by user input
The difference between codes provided by ChatGPT and my codes is error handling. ChatGPT utilized error handling for invalid arguments while I have bypassed this with if conditions and matrices with elements of ‘-1’.


# Task 4

The task is to perform a matrix slicing and displaying the implementation on the graphical image. The code has been written in two programming languages; C++ and Python. In the codes written by me for both programming languages implementation on the graphical image part have not been performed. First, random matrix is created with user defined size and then slicing is performed based on the user defined coordinates. The output is the sliced matrix of the random generated matrix.

Codes provided by ChatGPT for this task is as follows:

// Python code

import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# Load an image and convert it to a matrix (array)
image = Image.open('your_image.jpg')  # Replace with your image path
image_matrix = np.array(image)

# Get user-defined slicing dimensions
x_start = int(input("Enter the starting row (y-coordinate): "))
y_start = int(input("Enter the starting column (x-coordinate): "))
height = int(input("Enter the height of the slice: "))
width = int(input("Enter the width of the slice: "))

# Ensure slicing indices are within image bounds
x_end = min(x_start + height, image_matrix.shape[0])
y_end = min(y_start + width, image_matrix.shape[1])
sliced_image_matrix = image_matrix[x_start:x_end, y_start:y_end]

# Display the original image
plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.imshow(image_matrix)
plt.title('Original Image')
plt.axis('off')

# Display the sliced image
plt.subplot(1, 2, 2)
plt.imshow(sliced_image_matrix)
plt.title('Sliced Image')
plt.axis('off')

plt.show()
""" End of code """

//C++ code
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the image
    cv::Mat image = cv::imread("your_image.jpg");  // Replace with your image path

    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // Get user-defined slicing dimensions
    int x_start, y_start, height, width;
    std::cout << "Enter the starting row (y-coordinate): ";
    std::cin >> x_start;
    std::cout << "Enter the starting column (x-coordinate): ";
    std::cin >> y_start;
    std::cout << "Enter the height of the slice: ";
    std::cin >> height;
    std::cout << "Enter the width of the slice: ";
    std::cin >> width;

    // Ensure slicing indices are within image bounds
    int x_end = std::min(x_start + height, image.rows);
    int y_end = std::min(y_start + width, image.cols);
    cv::Rect roi(y_start, x_start, y_end - y_start, x_end - x_start);
    cv::Mat sliced_image = image(roi);

    // Display the original image
    cv::imshow("Original Image", image);
    
    // Display the sliced image
    cv::imshow("Sliced Image", sliced_image);

    cv::waitKey(0);
    return 0;
}

//End of code
