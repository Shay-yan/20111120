#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Pet_accommodation_class_animal.hpp"

using std::cout, std::cin, std::vector, std::string, std::ifstream, std::ofstream, std::to_string;
int panel() {
  cout  << "\t��ʼ�˵�\n"
        << "----------------------\n"
        << "\t����(1)\n"
        << "\t�鿴(2)\n"
        << "\t�˳�(3)\n";
  int t;
  cin >> t;
  return t;
} // ��ʼ�˵����û�ѡ��

void check(const vector<animal>& p) {
  if(p.empty())
  {
    cout << "��û�������κγ���";
    return;
  } 
  for(int i = 0;i < p.size();++i){
    cout << "[" << i + 1 << "]" << "����:" << p[i].name() << "��ʳ��" 
    << p[i].satiety() << "����:" << p[i].mood() << '\n';
  }
} // �оٳ���

void load(vector<animal>& temp) {
  ifstream fin("animal.txt");
  animal temp_animal("", 0, 0);
  while(fin >> temp_animal) temp.push_back(temp_animal);
  fin.close();
} // д��������animal_number

void save(vector<animal> &temp) {
  ofstream fout("animal.txt", std::ios::app);
  for(animal &i : temp)
  fout << i;
} // д����animal.txt

string feed_animal(animal &p, int n) { 
  string feed_animal_temp = "��ʳ��+";
  feed_animal_temp += to_string(n);
  feed_animal_temp += "\tʣ�ࣺ";
  feed_animal_temp += to_string(p.feed(n));
  return feed_animal_temp;
}// ����Է�

string play_animal(animal &p, int n) {
  string temp = "����+";
  temp += to_string(n);
  temp += "\tʣ�ࣺ";
  temp += to_string(p.make_happy(n));
  return temp;
} // ���￪��

int main() {
  vector<animal> animal_number;
  load(animal_number);
  while(true)
  {
    int choice = panel();
    if(choice == 3){
      return 0;
    }
    else if(choice == 2){
      check(animal_number);
      while(true)
      {
        cout << "\n\n\t�鿴�˵�\n"
          << "---------------------\n"
          << "\tͶι(F)\n"
          << "\t��ˣ(K)\n"
          << "\t�����˳�\n"
          << "��ʾ�������ַ���\n";
          string temp;
          cin >> temp;
          if(temp == "F" || temp == "K")
          {
            int n;
            cout << "���������:";
            cin.ignore();
            cin >> n;
            if(n > animal_number.size() - 1) {
              cout << "��Ч";
            }
            else if(temp == "F") {
              cout << feed_animal(animal_number[n], 2) << '\n';
            }
            else if(temp == "K") {
              cout << play_animal(animal_number[n], 2);
            }
          }
          else
          {
            break;
          }
      }

    }
    else if(choice == 1){
      cin.ignore();
      cout << "��ϲ����������һֻ����,��ʲô�����أ�\n";
      string temp;
      cin >> temp;
      animal t(temp);
      animal_number.push_back(t);
      save(animal_number);
      cout << "�ɹ�����\n";
    }
    else{
      cout << "��Чֵ";
    }
  }
  return 0;
}