#include <iostream>
using namespace std;


int main() {
  int myArray[26] = {0}; // 0으로 이루어진 26개의 배열 생성 
  string word; // 단어를 입력받을 변수 
  cin >> word; // 사용자 입력 
  
  for (int i=0; i < word.length(); i++) { 
    myArray[int(word[i])-97]++; // 아스키코드를 이용해 알파벳의 인덱스에 맞는 값을 count해줌 
  }
	
	// 출력
  for (int i = 0; i < 26; i++) { 
    cout << myArray[i] << ' ';
  }
}