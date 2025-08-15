#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Pet_accommodation_class_animal.hpp"

using std::cout, std::cin, std::vector, std::string, std::ifstream, std::ofstream, std::to_string;
int panel() {
  cout  << "\t开始菜单\n"
        << "----------------------\n"
        << "\t领养(1)\n"
        << "\t查看(2)\n"
        << "\t退出(3)\n";
  int t;
  cin >> t;
  return t;
} // 开始菜单让用户选择

void check(const vector<animal>& p) {
  if(p.empty())
  {
    cout << "你没有领养任何宠物";
    return;
  } 
  for(int i = 0;i < p.size();++i){
    cout << "[" << i + 1 << "]" << "名字:" << p[i].name() << "饱食度" 
    << p[i].satiety() << "心情:" << p[i].mood() << '\n';
  }
} // 列举宠物

void load(vector<animal>& temp) {
  ifstream fin("animal.txt");
  animal temp_animal("", 0, 0);
  while(fin >> temp_animal) temp.push_back(temp_animal);
  fin.close();
} // 写出宠物至animal_number

void save(vector<animal> &temp) {
  ofstream fout("animal.txt", std::ios::app);
  for(animal &i : temp)
  fout << i;
} // 写入至animal.txt

string feed_animal(animal &p, int n) { 
  string feed_animal_temp = "饱食度+";
  feed_animal_temp += to_string(n);
  feed_animal_temp += "\t剩余：";
  feed_animal_temp += to_string(p.feed(n));
  return feed_animal_temp;
}// 宠物吃饭

string play_animal(animal &p, int n) {
  string temp = "心情+";
  temp += to_string(n);
  temp += "\t剩余：";
  temp += to_string(p.make_happy(n));
  return temp;
} // 宠物开心

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
        cout << "\n\n\t查看菜单\n"
          << "---------------------\n"
          << "\t投喂(F)\n"
          << "\t玩耍(K)\n"
          << "\t否则退出\n"
          << "提示：请输字符：\n";
          string temp;
          cin >> temp;
          if(temp == "F" || temp == "K")
          {
            int n;
            cout << "请输入序号:";
            cin.ignore();
            cin >> n;
            if(n > animal_number.size() - 1) {
              cout << "无效";
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
      cout << "恭喜！你领养了一只宠物,叫什么名字呢？\n";
      string temp;
      cin >> temp;
      animal t(temp);
      animal_number.push_back(t);
      save(animal_number);
      cout << "成功！！\n";
    }
    else{
      cout << "无效值";
    }
  }
  return 0;
}