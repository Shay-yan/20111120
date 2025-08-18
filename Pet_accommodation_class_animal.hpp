#include <string>
#include <iostream>

using std::string, std::istream, std::ostream;
class animal{
  int satiety_; // 饱食度
  int mood_level_; // 心情度
  string animal_name_; // 名字
public:
  animal(const string &user_animal_name, int user_satiety = 50,
         int user_Mood_level = 50)
      : animal_name_(user_animal_name), satiety_(user_satiety),
        mood_level_(user_Mood_level) {}

  int feed(int food_satiety) {
    satiety_ += food_satiety;
    return satiety_;
  }

    int make_happy(int way_happy){
      mood_level_ += way_happy;
      return mood_level_;
    }

    string be_named(string& new_animal_name){
      animal_name_ = new_animal_name;
      return animal_name_;
    }

    void rename(string& new_animal_name) {
      animal_name_ = new_animal_name;
    }
    
      friend istream &operator>>(istream &ti, animal &temp) {
      string t;
      int n, y;
      if(ti >> t >> n >> y){
        temp = animal(t, n, y);
      }
      return ti;
    }

    friend ostream& operator<<(ostream &ti, const animal& temp){
      return ti << temp.name() << ' ' << temp.satiety() << ' ' << temp.mood() << '\n';
    }

    string name() const { return animal_name_; }
    int mood() const { return mood_level_; }
    int satiety() const { return satiety_; }
};