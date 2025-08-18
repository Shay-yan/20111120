#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Pet_accommodation_class_animal.hpp"

using std::cout, std::cin, std::vector, std::string, std::ifstream, std::ofstream;
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
    cout << "[" << i + 1 << "]" << '\t' 
    << "名字:" << p[i].name() << "  " << "饱食度:"
    << p[i].satiety() << "  " << "心情:" << p[i].mood() << '\n';
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

int feed_animal(animal &p, int n) { 
  return p.feed(n);
}// 宠物吃饭

int play_animal(animal &p, int n) {
  return p.make_happy(n);
} // 宠物开心

void animal_erase(int erase_umber, vector<animal>& erase_animal) {
  erase_animal.erase(erase_animal.begin() + erase_umber - 1);
} // 删除宠物

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
        cout << "\n\n\t查看菜单\n"
          << "---------------------\n"
          << "\t投喂(F)\n"
          << "\t玩耍(K)\n"
          << "\t弃养(P)\n"
          << "\t改名(L)\n"
          << "\t否则退出\n"
          << "提示：请输字符：\n";
          string temp;
          cin >> temp;
          if(temp == "F" || temp == "K" || temp == "P" || temp == "L")
          {
            int n;
            cout << "请输入序号:";
            cin.ignore();
            cin >> n;
            if(n > animal_number.size() - 1) {
              cout << "无效";
            } else if (temp == "F") {
              cout << "饱食度 +" << n << "剩余："
                   << feed_animal(animal_number[n], 2);
            } else if (temp == "K") {
              cout << "心情 +" << n << "剩余：" 
              << play_animal(animal_number[n], 2);
            } else if(temp == "P") {
              animal_erase(n, animal_number);
              cout << "成功\n";
            } else {
              cout << "改为什么名字呢？\n";
              cin >> temp;
              animal_rename(animal_number[n], temp);
              cout << "成功\n" << "它有一个新名字了：" << animal_number[n].name() << '\n';
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