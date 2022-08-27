#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define UNDEFINED -1

void lcs(int** memory, std::string s1, std::string s2){
    for(int i=0; i<=s1.length(); i++)
        memory[i][0] = 0;
    for(int j=0; j<=s2.length(); j++)
        memory[0][j] = 0;

    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length(); j++){
            if(s1[i-1] == s2[j-1])
                memory[i][j] = 1+memory[i-1][j-1];
            else if(memory[i-1][j] >= memory[i][j-1])
                memory[i][j] = memory[i-1][j];
            else
                memory[i][j] = memory[i][j-1];
        }
    }
}

void print_lcs(int** memory, std::string s1, std::string s2, int i, int j){
    if(!i || !j) return;
    if(s1[i-1] == s2[j-1]){
        print_lcs(memory, s1, s2, i-1, j-1);
        std::cout<<s1[i-1];
    }
    else if(memory[i-1][j] >= memory[i][j-1])
        print_lcs(memory, s1, s2, i-1, j);
    else
        print_lcs(memory, s1, s2, i, j-1);
}

int main(){
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    
    int **memory = new int*[s1.length()+1];
    for(int i=0; i<s1.length()+1; i++)
        memory[i] = new int[s2.length()+1];
    
    lcs(memory, s1, s2);
    std::cout<<memory[s1.length()][s2.length()]<<"\n";
    print_lcs(memory, s1, s2, s1.length(), s2.length());
    std::cout<<"\n";

    for(int i=0; i<=s1.length(); i++)
        delete[] memory[i];
    delete[] memory;
    return 0;
}