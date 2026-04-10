#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct predmet {
	
	int healt;
	int damageBonus;
	string name;

};




	struct Player {
		
		vector <predmet> inventory;
		string className;
		int damage;
		int hp;
		int mana;
		int manaCost;
		int armor;
		int damageMagich;
		string weapon;

		
	};


	void showStats(Player& player) {
		
		
		player.className = "Маг";
		player.hp = 80;
		player.armor = 1;
		player.mana = 40;
		player.manaCost = 15;
		player.damageMagich = 15;
		player.weapon = "Жезл";
		player.damage = 6;


		cout << "Здоровье " << player.hp << endl;
		cout << "Броня " << player.armor << endl;
		cout << "Урон " << player.damage << endl;
		cout << "Мана " << player.mana << endl;
		cout << "Мана кост " << player.manaCost << endl;
		cout << "Оружие " << player.weapon << endl;


	}


	





	int main() {
		system("chcp 65001 > nul");
		Player player;
		showStats(player);
		vector<predmet> inventory;
		int vibor;
		predmet healthZelye = { 20, 0 ,"Зелье здоровье" };
		predmet damageZelye = { 0, 10 ,"Урон зелье" };

		inventory.push_back(healthZelye);
		inventory.push_back(damageZelye);




		//РАБОЧАЯ ОСНОВА
		// поиск предметов в массиве и использование 
		for (int i = 0; i < inventory.size(); i++) {

			cout << "Предметы " << inventory[i].name
				<< "(Лечение: " << inventory[i].healt
				<< " Доп урон: " << inventory[i].damageBonus << ")" << endl;
		}

		bool used = true;
		while (used) {
			cout << "Выберите зелье" << endl
				<< "1 - Зелье здоровье" << endl
				<< "2 - Зелье дамага" << endl;

			cin >> vibor;


			if (vibor == 1) {

				int index = -1;

				for (int a = 0; a < inventory.size(); a++) { //перебор пока не найдем нужный индекс
					if (inventory[a].healt > 0) {// как находим проверяем то ли зелье 
						index = a;// сохраняем
						break;// выходим из цикла
					}
				}

				if (index != -1) { //использование если не равно -1 то идет использование 
					player.hp += inventory[index].healt;
					cout << "ХП увеличина но " << inventory[index].healt << " Ваше здоровье " << player.hp << endl;
					inventory.erase(inventory.begin() + index);
				}

				else { // если зелье кончилось
					cout << "Зелье хп не осталось" << endl;
				}

			}

			

			else if (vibor == 2) { 
				int indexDamage = -1;

				for (int k = 0; k < inventory.size();k++) { //все так же ищем индекс проверяем

					if (inventory[k].damageBonus > 0) { //проверяем нужный ли
						indexDamage = k;//запоминаем
						break;//выходим из цикла
					}
				}

				if (indexDamage != -1) { //использование предметов
					int zelyeDamaga = player.damage += inventory[indexDamage].damageBonus;
					cout << "Дамаг увеличин на  " << inventory[indexDamage].damageBonus << " Ваш урон =  " << player.damage << endl;
					inventory.erase(inventory.begin() + indexDamage);
				}
				else {
					cout << "Зелье Урона не осталось" << endl;
				}
			}
			
			


			//СТАРАЯ ВЕРСИЯ ЧЕРЕЗ ИФ ДОЛГО ТЯЖЕЛО И НЕ УДОБНО

			/*

			if (vibor == 1) {
				if (inventory[0].healt > 0) {
					cout << "Вы выбрали зелье хила" << endl;
					int zelyeHp = player.hp += inventory[0].healt;
					cout << "ХП увеличина но " << inventory[0].healt << " Ваше здоровье " << player.hp << endl;
					inventory.erase(inventory.begin());

				}
				else {
					cout<<"Зелье хила кончилось"<<endl;
				}

			}



			int index = -1;
			*/


			/*
			if (vibor == 2) {
				if (inventory.size() > 1 && inventory[1].damageBonus > 0) {
					cout << "Вы выбрали зелье дамага" << endl;
					int zelyeDamaga = player.damage += inventory[1].damageBonus;
					cout << "Дамаг увеличин на  " << inventory[1].damageBonus << " Ваш урон =  " << player.damage << endl;
					inventory.erase(inventory.begin() + 1);

				}

				if (inventory.size() > 0 && inventory[0].damageBonus > 0) {
					cout << "Вы выбрали зелье дамага" << endl;
					int zelyeDamaga = player.damage += inventory[0].damageBonus;
					cout << "Дамаг увеличин на  " << inventory[0].damageBonus << " Ваш урон =  " << player.damage << endl;
					inventory.erase(inventory.begin());

				}



			}
			*/



		}
	}








	
	
	


	
	




