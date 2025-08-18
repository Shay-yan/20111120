#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Pet_accommodation_class_animal.hpp"

using std::cout, std::cin, std::vector, std::string, std::ifstream, std::ofstream;
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
    cout << "[" << i + 1 << "]" << '\t' 
    << "����:" << p[i].name() << "  " << "��ʳ��:"
    << p[i].satiety() << "  " << "����:" << p[i].mood() << '\n';
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

int feed_animal(animal &p, int n) { 
  return p.feed(n);
}// ����Է�

int play_animal(animal &p, int n) {
  return p.make_happy(n);
} // ���￪��

void animal_erase(int erase_umber, vector<animal>& erase_animal) {
  erase_animal.erase(erase_animal.begin() + erase_umber - 1);
} // ɾ������

void animal_rename(animal &rename_animal, string &new_name) {
  rename_animal.rename(new_name);
}
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
          << "\t����(P)\n"
          << "\t����(L)\n"
          << "\t�����˳�\n"
          << "��ʾ�������ַ���\n";
          string temp;
          cin >> temp;
          if(temp == "F" || temp == "K" || temp == "P" || temp == "L")
          {
            int n;
            cout << "���������:";
            cin.ignore();
            cin >> n;
            if(n > animal_number.size() - 1) {
              cout << "��Ч";
            } else if (temp == "F") {
              cout << "��ʳ�� +" << n << "ʣ�ࣺ"
                   << feed_animal(animal_number[n], 2);
            } else if (temp == "K") {
              cout << "���� +" << n << "ʣ�ࣺ" 
              << play_animal(animal_number[n], 2);
            } else if(temp == "P") {
              animal_erase(n, animal_number);
              cout << "�ɹ�\n";
            } else {
              cout << "��Ϊʲô�����أ�\n";
              cin >> temp;
              animal_rename(animal_number[n], temp);
              cout << "�ɹ�\n" << "����һ���������ˣ�" << animal_number[n].name() << '\n';
            }
            check(animal_number);
            cin.ignore();
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