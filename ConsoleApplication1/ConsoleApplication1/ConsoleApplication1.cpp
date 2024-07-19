//Алгоритм Кнута-Морриса-Пратта

#include <iostream>
#include <vector>
#include <string>



int main()
{
    setlocale(LC_ALL, "ru");
    using namespace std;

    string target_word;
    string input_word;
    vector<int> max_word;
    vector<int> result;

    max_word.push_back(0);

    cout << "Введите текст: ";
    getline(cin,input_word);

    cout << "Введите искомый текст: ";
    getline(cin, target_word);

    int j = 0;
    int i = 1;

      
   while (i != target_word.size()) {

        if (target_word[i] != target_word[j] && j == 0) {
            max_word.push_back(0);
            i++;
        }
        else if (target_word[i] != target_word[j] && j > 0) {
            j = max_word[j-1];
        }
        else if (target_word[i] == target_word[j]) {
            max_word.push_back(j + 1);
            i++;
            j++;
        }
        
    }

   int top_index = 0, bot_index = 0;

   while (bot_index != target_word.size()) {

       if (target_word[bot_index] != input_word[top_index]) {
           result.clear();
       }

       if (target_word[bot_index] == input_word[top_index]) {
           result.push_back(top_index);
           top_index++;
           bot_index++;
       }

       else if (bot_index > 0) {
           bot_index = max_word[bot_index - 1];
       }

       else top_index++;
            
                            
   }

   cout << "Совпали элементы: ";
   for (int k = 0; k < result.size(); k++) {
       cout << result[k]<<" ";
   }
           
    return 0;
}