#include <iostream>
#include <fstream>

int main() {
    // 创建一个 ofstream 对象并打开文件
    std::ofstream outputFile("example.txt");

    // 检查文件是否成功打开
    if (!outputFile.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    // 写入数据到文件
    outputFile << "Hello, C++!" << std::endl;
    outputFile << "This is a line of text." << std::endl;
    outputFile << 42 << std::endl;

    // 关闭文件
    outputFile.close();

    std::cout << "文件已成功创建并写入数据。" << std::endl;

    return 0;
}
