#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

char member;
int m = 6;
int searchmember;
char regist_member, rconfirm;
int regist_id1, regist_id2;
bool correct_memberid;
bool used_memberid;

int menu, drink_menu, food_menu;
int choosefood;
int rtexture, rseasoning, rgarlic, rgunion, rspice, regg, rnori, rtype, rchange;
int ramenprice = 35000;
int spackChoice, srtypeChoice, stoppingChoice, ssauceChoice1, ssauceChoice2, schange, sushiprice = 0;
int rbricetypeChoice, rbpackChoice, rbtoppingChoice, rbvegChoice, rbpackprice, rbrtypeprice, rbchange, rbtopprice = 0;

array<int, 15>memberid = { 123210011, 123210022, 123210033, 123210044, 123210055 };
array<string, 10>ramen;
array<int, 20>ramenprices;
array<string, 10>sushi;
array<int, 20>sushiprices;
array<string, 10>rbowl;
array<int, 20>rbowlprices;
array<string, 50>topif;
array<int, 10>drink_bill;

int r = 0, s = 0, rb = 0, db = 0;
int tif = 0;

int main_drink;
char sugar, ice;
int many_drink1, many_drink2, many_drink3, many_drink4, many_drink5, many_drink6;
int drink_price[6] = { 8000,15000,5000,12000,16000,19000 };
int pricedrink1 = 0;
int pricedrink2 = 0;
int pricedrink3 = 0;
int pricedrink4 = 0;
int pricedrink5 = 0;
int pricedrink6 = 0;
int pricemilk[3] = { 18000,20000,12000 };
int pricemilk1 = 0;
int pricemilk2 = 0;
int pricemilk3 = 0;
int many_milk1, many_milk2, many_milk3;
int milk_type;
int coffee_type;
int pricecoffee1 = 0;
int pricecoffee2 = 0;
int pricecoffee3 = 0;
int pricecoffee4 = 0;
int many_coffee1, many_coffee2, many_coffee3, many_coffee4;
int pricecoffee[4] = { 20000,25000,35000,26000 };
int many_notes;

string notes[100];

void account();
void menu1();
void drink();
void food();
void ramensel();
void sushisel();
void ricebowsel();
void wholebill();

void coffee_menu();
void menu2();
void milk_menu();

int main() {
	account();
	cout << "\n------------------------------------------------------------------";
	cout << "\n              " << " MINASAN'S RESTAURANT MENU" << "                    ";
	cout << "\n------------------------------------------------------------------";
	cout << "\n1. Food's Menu\n2. Drink's Menu\n3. Exit";
	cout << "\nYour Answer : "; cin >> menu;
	system("cls");

	switch (menu) {

	case 1:food();
		break;
	case 2:drink();
		break;
	case 3:return 0; break;
	default: cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		main();
		break;
	}
}

void account() {

	cout << "\n------------------------------------------------------------------";
	cout << "\n              " << "HELLO WELCOME TO MINASAN'S RESTAURANT" << "                    ";
	cout << "\n------------------------------------------------------------------";
	cout << endl;
	cout << "Are you a member of Minasan's Restaurant ?\n(y/n) : "; cin >> member;

	if (member == 'y') {
		cout << "\nPlease Enter Your Member's ID :"; cin >> searchmember;
		sort(memberid.begin(), memberid.end());
		correct_memberid = binary_search(memberid.begin(), memberid.end(), searchmember);
		if (correct_memberid) {
			cout << "\n------------------------------------------------------------------------------------------------";
			cout << "\n" << "Hello Minasan's Member!\nThere will be many discounts and interesting promos waiting for you!"
				"\nHappy Ordering and Enjoying Our Dishes!" << "                    ";
			cout << "\n------------------------------------------------------------------------------------------------";
			cout << endl;

			system("pause"); system("cls");

		}
		else {
			cout << "There's no customer with this ID...Please re-enter your ID..." << endl;
			system("pause");
			system("cls");
			account();
		}
	}
	else if (member == 'n') {
		cout << "\nAre you interested in becoming one of the members of Minasan's Restaurant? "
			"\nYou Will Get Various Discounts and Interesting Promos!!!"
			"\n\nDo you want to register?(y/n) : "; cin >> regist_member;

		if (regist_member == 'n') {
			cout << "\nOkay! Happy Ordering and Enjoying Our Dishes !" << endl;
			system("pause");
			system("cls");
		}

		if (regist_member == 'y') {

			while (1 < 2) {

				system("cls");
				cout << "\nPlease Enter Your Member's ID \t:(Maximum of 10 digits)";
				cout << "\n\t     Your Member's ID \t: "; cin >> regist_id1;
				cout << "     Confirm Your Member's ID \t: "; cin >> regist_id2;

				if (regist_id1 == regist_id2) {
					sort(memberid.begin(), memberid.end());
					used_memberid = binary_search(memberid.begin(), memberid.end(), regist_id1);

					if (used_memberid) {
						cout << "Sorry This ID is Already Used By Another Customer, Please Make a Diiferent ID...";
						system("pause");
						continue;
					}
					else {
						cout << "\nCongratulations Now You Have Become a Member of Our Restaurant!\nPlease login using your new member!" << endl;
						system("pause");
						memberid[m] = regist_id1;
						m++;
						system("cls");
						account();
						break;
					}
				}

				else if (regist_id1 != regist_id2) {
					cout << "Sorry Your ID Does Not Match, Please Re-enter...";
					system("pause");
					continue;
				}
			}
		}
	}
		
}

int end() {
	return 0;
}
	

void menu1() {
	cout << "\n------------------------------------------------------------------";
	cout << "\n              " << " MINASAN'S RESTAURANT MENU" << "                    ";
	cout << "\n------------------------------------------------------------------";
	cout << "\n1. Food's Menu\n2. Drink's Menu\n3. Done\n4. Cancel";
	cout << "\nYour Answer : "; cin >> menu;
	system("cls");

	switch (menu) {

	case 1: food();
		break;
	case 2: drink();
		break;
	case 3: wholebill(); break;
	case 4: exit(0); break;
	default: cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		menu1();
		break;
	}system("cls");

	end();
}



void food() {
	cout << "\n--------------------------------------------------------------------------";
	cout << "\n            " << " MINASAN'S RESTAURANT FOOD MENU" << "                    ";
	cout << "\n--------------------------------------------------------------------------";
	cout << "\n\t\tMENU\t\t||\t\t   PRICE";
	cout << "\n\t(1) Ramen\t\t||\t\tStarts from Rp 35.000 ";
	cout << "\n\t(2) Sushi\t\t||\t\tStarts from Rp 36.000";
	cout << "\n\t(3) Rice Bowl\t\t||\t\tStarts from Rp 9.000";
	cout << "\n--------------------------------------------------------------------------\nYour Order: "; cin >> choosefood;
	system("cls");
	switch (choosefood) {
	case 1:	ramensel(); break;
	case 2: sushisel(); break;
	case 3: ricebowsel(); break;
	default: cout << "Please choose from the number above." << endl;
		system("pause");
		system("cls");
		food();
		break;
	}
}

void ramenTexture() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Noodle Texture:\n" << endl;
	cout << "1. Extra Firm\n2. Firm\n3. Medium\n4. Soft\n5. Extra Soft" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> rtexture;
	switch (rtexture) {
	case 1: ramen[0] = "Extra Firm Noodle Texture"; break;
	case 2: ramen[0] = "Firm Noodle Texture"; break;
	case 3: ramen[0] = "Medium Noodle Texture"; break;
	case 4: ramen[0] = "Soft Noodle Texture"; break;
	case 5: ramen[0] = "Extra Soft Noodle Texture";  break;
	default: cout << "Please choose from the number above." << endl;
		system("pause");
		system("cls");
		ramenTexture();
		break;
	}
	system("cls");
}

void ramenSeasoning() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Seasoning:\n" << endl;
	cout << "1. Light\n2. Medium\n3. Strong" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> rseasoning;
	switch (rseasoning)
	{
	case 1: ramen[1] = "Light Seasoning"; break;
	case 2: ramen[1] = "Medium Seasoning"; break;
	case 3: ramen[1] = "Strong Seasoning"; break;
	default: cout << "Please choose from the number above." << endl;
		system("pause");
		system("cls");
		ramenSeasoning();
		break;
	}system("cls");
}

void ramenGarlic() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Garlic:\n" << endl;
	cout << "1. None\n2. Drop\n3. Medium\n4. 1/2 Clove\n5. 1 Clove\n6. 2 Clove" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> rgarlic;
	switch (rgarlic)
	{
	case 1: ramen[2] = "No Garlic"; break;
	case 2: ramen[2] = "Drop Gralic"; break;
	case 3: ramen[2] = "Medium Garlic"; break;
	case 4: ramen[2] = "1/2 Clove"; break;
	case 5: ramen[2] = "1 Clove"; break;
	case 6: ramen[2] = "2 Clove"; break;
	default: cout << "Please choose from the number above." << endl;
		system("pause");
		system("cls");
		ramenGarlic();
		break;
	} system("cls");

}

void ramenGunion() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Green Union:\n" << endl;
	cout << "1. With\n2. Without" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> rgunion;
	switch (rgunion)
	{
	case 1: ramen[3] = "With Green Union"; break;
	case 2: ramen[3] = "Without Green Union"; break;
	default:cout << "Please choose from the number above." << endl;
		system("pause");
		system("cls");
		ramenGunion();
		break;
	}system("cls");
}

void ramenSpiceness() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Spiceness Level:\n" << endl;
	cout << "Mild>>>>>>>>>>>>>>>>>>>>>>>>Extra Spicy" << endl;
	cout << "  1  2  3  4  5  6  7  8  9  10" << endl;
	cout << "---------------------------" << endl;
	cout << "Your Choice: "; cin >> rspice;
	if (rspice >= 1 && rspice < 6) {
		ramen[4] = "1-5 Spiceness Level";
	}
	else if (rspice >= 6 && rspice < 11) {
		ramen[4] = "6-10 Spiceness Level";
	}
	else {
		cout << "Please choose from among the numbers above";
		system("pause");
		system("cls");
		ramenSpiceness();
	}system("cls");
}

void ramenEgg() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Boiled Egg:\n" << endl;
	cout << "1. No Egg\n2. Perfectly Cooked Boiled Egg\n3. Half Cooked Boiled Egg" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> regg;
	switch (regg)
	{
	case 1: ramen[5] = "No Egg"; break;
	case 2: ramen[5] = "Perfectly Cooked Egg"; break;
	case 3: ramen[5] = "Half Cooked Egg"; break;
	default: cout << "Please choose from among the numbers above";
		system("pause");
		system("cls");
		ramenEgg();
		break;
	}system("cls");
}

void ramenNori() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Nori:\n" << endl;
	cout << "1. No Nori\n2. Salted Egg\n3. Original" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> rnori;
	switch (rnori)
	{
	case 1: ramen[6] = "No Nori"; break;
	case 2: ramen[6] = "Salted Egg Nori"; break;
	case 3: ramen[6] = "Original Nori"; break;
	default: cout << "Please choose from among the numbers above";
		system("pause");
		system("cls");
		ramenNori();
		break;
	}system("cls");
}

void ramenType() {
	cout << "\nRamen:" << endl;
	cout << "---------------------------" << endl;
	cout << "Noodle type:\n" << endl;
	cout << "1. Thin\n2. Thick" << endl;
	cout << "---------------------------" << endl;
	cout << "Your choice: "; cin >> rtype;
	switch (rtype)
	{
	case 1: ramen[7] = "Thin Noodle"; break;
	case 2: ramen[7] = "Thick Noodle"; break;
	default: cout << "Please choose from among the numbers above";
		system("pause");
		system("cls");
		ramenType();
		break;
	}system("cls");
}

void ramenConfirm() {
	cout << "\nYour ramen type selections:" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << ". " << ramen[i] << endl;
	}
	cout << "\nConfirm?(y/n): "; cin >> rconfirm;
	if (rconfirm == 'y') {
	}
	else if (rconfirm == 'n') {
		cout << "Which category do you want to change?" << endl;
		cout << "(Please select according to the numbers above)" << endl;
		cout << "I want to change number "; cin >> rchange;
		switch (rchange)
		{
		case 1: ramenTexture(); ramenConfirm(); break;
		case 2: ramenSeasoning(); ramenConfirm(); break;
		case 3: ramenGarlic(); ramenConfirm(); break;
		case 4: ramenGunion(); ramenConfirm(); break;
		case 5: ramenSpiceness(); ramenConfirm(); break;
		case 6: ramenEgg(); ramenConfirm(); break;
		case 7: ramenNori(); ramenConfirm(); break;
		case 8: ramenType(); ramenConfirm(); break;
		default:
			cout << "Please choose from among the numbers above." << endl;
			system("pause");
			system("cls");
			ramenConfirm();
			break;
		}
	}
	else {
		cout << "Please choose from among the numbers above" << endl;
		system("pause");
		system("cls");
		ramenConfirm();
	}
}

void ramenbill() {
	int ramenq;
	cout << "Ramen quantity: "; cin >> ramenq;
	ramenprices[r] = ramenq * ramenprice;
	cout << "\nRamen Price: " << ramenprices[r] << endl;
	r++;
	system("pause");
	system("cls");
	menu1();
}

void ramensel() {

	ramenTexture();
	ramenSeasoning();
	ramenGarlic();
	ramenGunion();
	ramenSpiceness();
	ramenEgg();
	ramenNori();
	ramenType();
	ramenConfirm();
	ramenbill();
}

void spackage() {
	cout << "\nSushi:" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Sushi Package:\n" << endl;
	cout << "1. Package 1:(10% Total Discount for Members)\nChoose 2 toppings and will get 6 sushi, 3 sushi/topping\n" << endl;
	cout << "2. Package 2:(15% Total Discount for Members)\nChoose 3 toppings and will get 9 sushi, 3 sushi/topping\n" << endl;
	cout << "3. Package 3:(20% Total Discount for Members)\nChoose 4 toppings and will get 12 Sushi, 3 sushi/topping\n" << endl;
	cout << "4. No Package:(No Discount)\n" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Your choice: "; cin >> spackChoice;
	switch (spackChoice)
	{
	case 1: sushi[0] = "Sushi Package 1"; break;
	case 2: sushi[0] = "Sushi Package 2"; break;
	case 3: sushi[0] = "Sushi Package 3"; break;
	case 4: sushi[0] = "No Package"; break;
	default:
		cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		spackage();
		break;
	}
	system ("cls");
}

void sricetype() {
	cout << "\nSushi:" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Rice type:\n" << endl;
	cout << "1. White Rice\n2. Brown Rice\n3. Shirataki Rice" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Your choice: "; cin >> srtypeChoice;
	switch (srtypeChoice)
	{
	case 1: sushi[1] = "White Rice"; break;
	case 2: sushi[1] = "Brown Rice"; break;
	case 3: sushi[1] = "Shirataki Rice"; break;
	default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		sricetype();
		break;
	}
	system("cls");
}

void stopping() {
	int stchooseif;
	int sushiquantity;
	string top1, top2, top3, top4;
	cout << "\nSushi:" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Topping:\n" << endl;
	cout << "1. Salmon\tRp 11.000\t5. Tuna\t\tRp 10.000\n2. Chicken\tRp 8.000\t6. Octopus\tRp 9.000\n3. Egg\t\tRp 3.000\t7. Ebi\t\tRp 9.000\n4. Beef\t\tRp 8.000\t8. Tobiko\tRp 3.000" << endl;
	cout << "-----------------------------------------------" << endl;
	if (spackChoice == 1) {
		cout << "Your choice: "; cin >> stoppingChoice;
		switch (stoppingChoice)
		{
		case 1: sushi[2] = "Salmon Topping"; break;
		case 2: sushi[2] = "Chicken Topping"; break;
		case 3: sushi[2] = "Egg Topping"; break;
		case 4: sushi[2] = "Beef Topping"; break;
		case 5: sushi[2] = "Tuna Topping"; break;
		case 6: sushi[2] = "Octopus Topping"; break;
		case 7: sushi[2] = "Ebi Topping"; break;
		case 8: sushi[2] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		cout << "Choose your second topping: "; cin >> stchooseif;
		switch (stchooseif)
		{
		case 1: topif[tif] = "Salmon Topping"; break;
		case 2: topif[tif] = "Chicken Topping"; break;
		case 3: topif[tif] = "Egg Topping"; break;
		case 4: topif[tif] = "Beef Topping"; break;
		case 5: topif[tif] = "Tuna Topping"; break;
		case 6: topif[tif] = "Octopus Topping"; break;
		case 7: topif[tif] = "Ebi Topping"; break;
		case 8: topif[tif] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		sushi[2] = sushi[2] +" | " + topif[tif];
	}
	else if (spackChoice == 2) {
		cout << "Your choice: "; cin >> stoppingChoice;
		switch (stoppingChoice)
		{
		case 1: sushi[2] = "Salmon Topping"; break;
		case 2: sushi[2] = "Chicken Topping"; break;
		case 3: sushi[2] = "Egg Topping"; break;
		case 4: sushi[2] = "Beef Topping"; break;
		case 5: sushi[2] = "Tuna Topping"; break;
		case 6: sushi[2] = "Octopus Topping"; break;
		case 7: sushi[2] = "Ebi Topping"; break;
		case 8: sushi[2] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		cout << "Choose your second topping: "; cin >> stchooseif;
		switch (stchooseif)
		{
		case 1: topif[tif] = "Salmon Topping"; break;
		case 2: topif[tif] = "Chicken Topping"; break;
		case 3: topif[tif] = "Egg Topping"; break;
		case 4: topif[tif] = "Beef Topping"; break;
		case 5: topif[tif] = "Tuna Topping"; break;
		case 6: topif[tif] = "Octopus Topping"; break;
		case 7: topif[tif] = "Ebi Topping"; break;
		case 8: topif[tif] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		cout << "Choose your third topping: "; cin >> stchooseif;
		switch (stchooseif)
		{
		case 1: topif[tif+1] = "Salmon Topping"; break;
		case 2: topif[tif+1] = "Chicken Topping"; break;
		case 3: topif[tif+1] = "Egg Topping"; break;
		case 4: topif[tif+1] = "Beef Topping"; break;
		case 5: topif[tif+1] = "Tuna Topping"; break;
		case 6: topif[tif+1] = "Octopus Topping"; break;
		case 7: topif[tif+1] = "Ebi Topping"; break;
		case 8: topif[tif+1] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		sushi[2] = sushi[2] +" | " + topif[tif] +" | " + topif[tif + 1];
	}
	else if (spackChoice == 3) {
		cout << "Your choice: "; cin >> stoppingChoice;
		switch (stoppingChoice)
		{
		case 1: sushi[2] = "Salmon Topping"; break;
		case 2: sushi[2] = "Chicken Topping"; break;
		case 3: sushi[2] = "Egg Topping"; break;
		case 4: sushi[2] = "Beef Topping"; break;
		case 5: sushi[2] = "Tuna Topping"; break;
		case 6: sushi[2] = "Octopus Topping"; break;
		case 7: sushi[2] = "Ebi Topping"; break;
		case 8: sushi[2] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		cout << "Choose your second topping: "; cin >> stchooseif;
		switch(stchooseif)
		{
		case 1: topif[tif] = "Salmon Topping"; break;
		case 2: topif[tif] = "Chicken Topping"; break;
		case 3: topif[tif] = "Egg Topping"; break;
		case 4: topif[tif] = "Beef Topping"; break;
		case 5: topif[tif] = "Tuna Topping"; break;
		case 6: topif[tif] = "Octopus Topping"; break;
		case 7: topif[tif] = "Ebi Topping"; break;
		case 8: topif[tif] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		cout << "Choose your third topping: "; cin >> stchooseif;
		switch (stchooseif)
		{
		case 1: topif[tif + 1] = "Salmon Topping"; break;
		case 2: topif[tif + 1] = "Chicken Topping"; break;
		case 3: topif[tif + 1] = "Egg Topping"; break;
		case 4: topif[tif + 1] = "Beef Topping"; break;
		case 5: topif[tif + 1] = "Tuna Topping"; break;
		case 6: topif[tif + 1] = "Octopus Topping"; break;
		case 7: topif[tif + 1] = "Ebi Topping"; break;
		case 8: topif[tif + 1] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		cout << "Choose your forth topping: "; cin >> stchooseif;
		switch (stchooseif)
		{
		case 1: topif[tif + 2] = "Salmon Topping"; break;
		case 2: topif[tif + 2] = "Chicken Topping"; break;
		case 3: topif[tif + 2] = "Egg Topping"; break;
		case 4: topif[tif + 2] = "Beef Topping"; break;
		case 5: topif[tif + 2] = "Tuna Topping"; break;
		case 6: topif[tif + 2] = "Octopus Topping"; break;
		case 7: topif[tif + 2] = "Ebi Topping"; break;
		case 8: topif[tif + 2] = "Tobiko Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			stopping();
			break;
		}
		sushi[2] = sushi[2] + " | " + topif[tif] +" | " + topif[tif + 1] +" | " + topif[tif + 2];
	}
	else if (spackChoice == 4) {
		cout << "Your choice: "; cin >> stoppingChoice;
		switch (stoppingChoice)
		{
		case 1: sushi[2] = "Salmon Topping"; sushiprice = sushiprice + 11000; break;
		case 2: sushi[2] = "Chicken Topping"; sushiprice = sushiprice + 8000; break;
		case 3: sushi[2] = "Egg Topping"; sushiprice = sushiprice + 3000; break;
		case 4: sushi[2] = "Beef Topping"; sushiprice = sushiprice + 8000; break;
		case 5: sushi[2] = "Tuna Topping";  sushiprice = sushiprice + 10000; break;
		case 6: sushi[2] = "Octopus Topping"; sushiprice = sushiprice + 9000;  break;
		case 7: sushi[2] = "Ebi Topping"; sushiprice = sushiprice + 9000; break;
		case 8: sushi[2] = "Tobiko Topping"; sushiprice = sushiprice + 3000; break;
		default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		stopping();
		break;
	}
		cout << "How many more sushi do you want? "; cin >> sushiquantity;
		for (int indext = 0; indext < sushiquantity; indext++) {
			cout << "Topping for sushi number " << indext + 1 << ": ";
			cin >> stchooseif;
			switch (stchooseif)
			{
			case 1: topif[tif] = "Salmon Topping"; sushiprice = sushiprice + 11000; break;
			case 2: topif[tif] = "Chicken Topping"; sushiprice = sushiprice + 8000; break;
			case 3: topif[tif] = "Egg Topping"; sushiprice = sushiprice + 3000; break;
			case 4: topif[tif] = "Beef Topping"; sushiprice = sushiprice + 8000; break;
			case 5: topif[tif] = "Tuna Topping"; sushiprice = sushiprice + 10000; break;
			case 6: topif[tif] = "Octopus Topping"; sushiprice = sushiprice + 9000;  break;
			case 7: topif[tif] = "Ebi Topping"; sushiprice = sushiprice + 9000; break;
			case 8: topif[tif] = "Tobiko Topping"; sushiprice = sushiprice + 3000; break;
			default:cout << "Please choose from the numbers above." << endl;
				system("pause");
				system("cls");
				stopping();
				break;
			}tif++;
		}
		for (int Findext = 0; Findext <= tif; Findext++) {
			sushi[2] = sushi[2] +" | " + topif[Findext];
		}
		system("cls");
	}
	system("cls");
}


void ssauce() {
	string secsauce;
	cout << "\nSushi:" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Dipping Sauce:\n" << endl;
	cout << "1. Cheese\t5. Wasabi\n2. Soy Sauce\t6. Chili Sauce\n3. Mayo\t\t7. Tomato Sauce\n4. Mustard" << endl;
	cout << "-------------------------------------" << endl;
	cout << "First sauce: "; cin >> ssauceChoice1;
	switch (ssauceChoice1)
	{
	case 1: sushi[3] = "Cheese Sauce"; break;
	case 2: sushi[3] = "Soy Sauce Sauce"; break;
	case 3: sushi[3] = "Mayo Sauce"; break;
	case 4: sushi[3] = "Mustard Sauce"; break;
	case 5: sushi[3] = "Wasabi Sauce"; break;
	case 6: sushi[3] = "Chili Sauce"; break;
	case 7: sushi[3] = "Tomato Sauce"; break;
	default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		ssauce();
		break;
	}
	cout << "Second sauce: "; cin >> ssauceChoice2;
	switch (ssauceChoice2)
	{
	case 1: secsauce = "Cheese Sauce"; break;
	case 2: secsauce = "Soy Sauce Sauce"; break;
	case 3: secsauce = "Mayo Sauce"; break;
	case 4: secsauce = "Mustard Sauce"; break;
	case 5: secsauce = "Wasabi Sauce"; break;
	case 6: secsauce = "Chili Sauce"; break;
	case 7: secsauce = "Tomato Sauce"; break;
	default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		ssauce();
		break;
	}
	sushi[3] = sushi[3] + " | " + secsauce + " | ";
	system("cls");
}


void sushiConfirm() {
	cout << "\nYour sushi type selections:" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << sushi[i] << endl;
	}
	cout << "\nConfirm?(y/n): "; cin >> rconfirm;
	if (rconfirm == 'y') {
	}
	else if (rconfirm == 'n') {
		cout << "Which category do you want to change?" << endl;
		cout << "(Please select according to the numbers above.)" << endl;
		cout << "I want to change number "; cin >> schange;
		switch (schange)
		{
		case 1: spackage(); stopping(); sushiConfirm(); break;
		case 2: sricetype(); sushiConfirm(); break;
		case 3: stopping(); sushiConfirm(); break;
		case 4: ssauce(); sushiConfirm(); break;
		default:
			cout << "Please choose from among the numbers above." << endl;
			system("pause");
			system("cls");
			sushiConfirm();
			break;
		}
	}
	else {
		cout << "Please type y/n" << endl;
		system("pause");
		system("cls");
		sushiConfirm();
	}
}

void sushibill() {
	if (spackChoice == 1) {
		if (correct_memberid) {
			sushiprice = 32400;
		}
		else {
			sushiprice = 36000;
		}
	}
	else if (spackChoice == 2) {
		if (correct_memberid) {
			sushiprice = 40500;
		}
		else {
			sushiprice = 45000;
		}
	}
	else if (spackChoice == 3) {
		if (correct_memberid) {
			sushiprice = 49500;
		}
		else {
			sushiprice = 55000;
		}
	}
	sushiprices[s] = sushiprice;
	cout << "\nSushi Price: " << sushiprices[s] << endl;
	s++;
	system("pause");
	system("cls");
	menu1();
}

void sushisel() {
	spackage();
	sricetype();
	stopping();
	ssauce();
	sushiConfirm();
	sushibill();
}


void rbricetype() {
	cout << "\nRice Bowl:" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Rice Type:\n" << endl;
	cout << "1. White Rice\t\tRp 5000\n2. Brown Rice\t\tRp 7.000\n3. Shirataki Rice\tRp 15.000" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Your choice: "; cin >> rbricetypeChoice;
	switch (rbricetypeChoice)
	{
	case 1: rbowl[0] = "White Rice"; rbrtypeprice = 5000; break;
	case 2: rbowl[0] = "Brown Rice"; rbrtypeprice = 7000; break;
	case 3: rbowl[0] = "Shirataki Rice"; rbrtypeprice = 15000; break;
	default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		rbricetype();
		break;
	}system("cls");
}

void rbpackage() {
	cout << "\nRice Bowl:" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Rice Bowl Package:\n" << endl;
	cout << "1. Package 1:(10% Total Discount for Members)\nChoose 3 Toppings\n" << endl;
	cout << "2. Package 2:(15% Total Discount for Members)\nChoose 4 Toppings\n" << endl;
	cout << "3. Package 3:(20% Total Discount for Members)\nChoose 5 Toppings\n" << endl;
	cout << "4. No Package:(No Discount)\n" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Your choice: "; cin >> rbpackChoice;
	switch (rbpackChoice)
	{
	case 1: rbowl[1] = "Rice Bowl Package 1";
		if (correct_memberid) {
		rbpackprice = 18000;
	}
		  else {
		rbpackprice = 20000;
	} break;
	case 2: rbowl[1] = "Rice Bowl Package 2";
		if (correct_memberid) {
		rbpackprice = 19500;
	}
		  else {
		rbpackprice = 26000;
	}; break;
	case 3: rbowl[1] = "Rice Bowl Package 3";
		if (correct_memberid) {
		rbpackprice = 24000;
	}
		  else {
		rbpackprice = 30000;
	}; break;
	case 4: rbowl[1] = "No Package"; break;
	default:
		cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		spackage();
		break;
	}
	system("cls");
}

void rbtopping() {
	int rbtchooseif;
	int rbowlquantity;
	cout << "\nRice Bowl:" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Topping:\n" << endl;
	cout << "1. Omelette\t\tRp 4.000\t5. Chicken Teriyaki\tRp 16.000\n2. Chicken Katsu\tRp 15.000\t6. Beef Teriyaki\tRp 19.000\n3. Beef Katsu\t\tRp 18.000\t7. Shrimp\t\tRp 16.000\n4. Tempura\t\tRp 18.000\t8. Fried Chicken\tRp 10.000" << endl;
	cout << "-----------------------------------------------" << endl;
	if (rbpackChoice == 1) {
		cout << "Your choice: "; cin >> rbtoppingChoice;
		switch (rbtoppingChoice)
		{
		case 1: rbowl[2] = "Omelette Topping"; break;
		case 2: rbowl[2] = "Chicken Katsu Topping"; break;
		case 3: rbowl[2] = "Beef Katsu Topping"; break;
		case 4: rbowl[2] = "Tempura Topping"; break;
		case 5: rbowl[2] = "Chicken Teriyaki Topping"; break;
		case 6: rbowl[2] = "Beef Teriyaki Topping"; break;
		case 7: rbowl[2] = "Shrimp Topping"; break;
		case 8: rbowl[2] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
			break;
		}
		cout << "Choose your second topping: "; cin >> rbtchooseif;
		switch (rbtchooseif)
		{
		case 1: topif[tif] = "Omelette Topping"; break;
		case 2: topif[tif] = "Chicken Katsu Topping"; break;
		case 3: topif[tif] = "Beef Katsu Topping"; break;
		case 4: topif[tif] = "Tempura Topping"; break;
		case 5: topif[tif] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif] = "Shrimp Topping"; break;
		case 8: topif[tif] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
			break;
		}
		cout << "Choose your second topping: "; cin >> rbtchooseif;
		switch (rbtchooseif)
		{
		case 1: topif[tif + 1] = "Omelette Topping"; break;
		case 2: topif[tif + 1] = "Chicken Katsu Topping"; break;
		case 3: topif[tif + 1] = "Beef Katsu Topping"; break;
		case 4: topif[tif + 1] = "Tempura Topping"; break;
		case 5: topif[tif + 1] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif + 1] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif + 1] = "Shrimp Topping"; break;
		case 8: topif[tif + 1] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
		}
		rbowl[2] = rbowl[2] + " | " + topif[tif] + " | " + topif[tif + 1];
	}
	else if (rbpackChoice == 2) {
		cout << "Your choice: "; cin >> rbtoppingChoice;
		switch (rbtoppingChoice)
		{
		case 1: rbowl[2] = "Omelette Topping"; break;
		case 2: rbowl[2] = "Chicken Katsu Topping"; break;
		case 3: rbowl[2] = "Beef Katsu Topping"; break;
		case 4: rbowl[2] = "Tempura Topping"; break;
		case 5: rbowl[2] = "Chicken Teriyaki Topping"; break;
		case 6: rbowl[2] = "Beef Teriyaki Topping"; break;
		case 7: rbowl[2] = "Shrimp Topping"; break;
		case 8: rbowl[2] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
			break;
		}
		cout << "Choose your second topping: "; cin >> rbtchooseif;
		switch (rbtchooseif)
		{
		case 1: topif[tif] = "Omelette Topping"; break;
		case 2: topif[tif] = "Chicken Katsu Topping"; break;
		case 3: topif[tif] = "Beef Katsu Topping"; break;
		case 4: topif[tif] = "Tempura Topping"; break;
		case 5: topif[tif] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif] = "Shrimp Topping"; break;
		case 8: topif[tif] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
			break;
		}
		cout << "Choose your third topping: "; cin >> rbtchooseif;
		switch (rbtchooseif)
		{
		case 1: topif[tif + 1] = "Omelette Topping"; break;
		case 2: topif[tif + 1] = "Chicken Katsu Topping"; break;
		case 3: topif[tif + 1] = "Beef Katsu Topping"; break;
		case 4: topif[tif + 1] = "Tempura Topping"; break;
		case 5: topif[tif + 1] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif + 1] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif + 1] = "Shrimp Topping"; break;
		case 8: topif[tif + 1] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
		}
		cout << "Choose your forth topping: "; cin >> rbtchooseif;
		switch (rbtchooseif) {
		case 1: topif[tif + 2] = "Omelette Topping"; break;
		case 2: topif[tif + 2] = "Chicken Katsu Topping"; break;
		case 3: topif[tif + 2] = "Beef Katsu Topping"; break;
		case 4: topif[tif + 2] = "Tempura Topping"; break;
		case 5: topif[tif + 2] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif + 2] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif + 2] = "Shrimp Topping"; break;
		case 8: topif[tif + 2] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
		}
		rbowl[2] = rbowl[2] + " | " + topif[tif] + " | " + topif[tif + 1] + " | " + topif[tif + 2];
	}
	else if (rbpackChoice == 3) {
	cout << "Your choice: "; cin >> rbtoppingChoice;
	switch (rbtoppingChoice)
	{
	case 1: rbowl[2] = "Omelette Topping"; break;
	case 2: rbowl[2] = "Chicken Katsu Topping"; break;
	case 3: rbowl[2] = "Beef Katsu Topping"; break;
	case 4: rbowl[2] = "Tempura Topping"; break;
	case 5: rbowl[2] = "Chicken Teriyaki Topping"; break;
	case 6: rbowl[2] = "Beef Teriyaki Topping"; break;
	case 7: rbowl[2] = "Shrimp Topping"; break;
	case 8: rbowl[2] = "Fried Chicken Topping"; break;
	default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		rbtopping();
		break;
	}
		cout << "Choose your second topping: "; cin >> rbtchooseif;
		switch (rbtchooseif)
		{
		case 1: topif[tif] = "Omelette Topping"; break;
		case 2: topif[tif] = "Chicken Katsu Topping"; break;
		case 3: topif[tif] = "Beef Katsu Topping"; break;
		case 4: topif[tif] = "Tempura Topping"; break;
		case 5: topif[tif] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif] = "Shrimp Topping"; break;
		case 8: topif[tif] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
			break;
		}
		cout << "Choose your third topping: "; cin >> rbtchooseif;
		switch (rbtchooseif)
		{
		case 1: topif[tif + 1] = "Omelette Topping"; break;
		case 2: topif[tif + 1] = "Chicken Katsu Topping"; break;
		case 3: topif[tif + 1] = "Beef Katsu Topping"; break;
		case 4: topif[tif + 1] = "Tempura Topping"; break;
		case 5: topif[tif + 1] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif + 1] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif + 1] = "Shrimp Topping"; break;
		case 8: topif[tif + 1] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
		}
		cout << "Choose your forth topping: "; cin >> rbtchooseif;
		switch (rbtchooseif) {
		case 1: topif[tif + 2] = "Omelette Topping"; break;
		case 2: topif[tif + 2] = "Chicken Katsu Topping"; break;
		case 3: topif[tif + 2] = "Beef Katsu Topping"; break;
		case 4: topif[tif + 2] = "Tempura Topping"; break;
		case 5: topif[tif + 2] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif + 2] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif + 2] = "Shrimp Topping"; break;
		case 8: topif[tif + 2] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
		}
		cout << "Choose your fifth topping: "; cin >> rbtchooseif;
		switch (rbtchooseif) {
		case 1: topif[tif + 3] = "Omelette Topping"; break;
		case 2: topif[tif + 3] = "Chicken Katsu Topping"; break;
		case 3: topif[tif + 3] = "Beef Katsu Topping"; break;
		case 4: topif[tif + 3] = "Tempura Topping"; break;
		case 5: topif[tif + 3] = "Chicken Teriyaki Topping"; break;
		case 6: topif[tif + 3] = "Beef Teriyaki Topping"; break;
		case 7: topif[tif + 3] = "Shrimp Topping"; break;
		case 8: topif[tif + 3] = "Fried Chicken Topping"; break;
		default:cout << "Please choose from the numbers above." << endl;
			system("pause");
			system("cls");
			rbtopping();
		}
		rbowl[2] = rbowl[2] + " | " + topif[tif] + " | " + topif[tif + 1] + " | " + topif[tif + 2] + " | " + topif[tif + 3];
	}
		else if (rbpackChoice == 4) {
		cout << "Your choice: "; cin >> rbtoppingChoice;
		switch (rbtoppingChoice)
		{
		case 1: rbowl[2] = "Omelette Topping"; rbtopprice = rbtopprice + 4000; break;
		case 2: rbowl[2] = "Chicken Katsu Topping"; rbtopprice = rbtopprice + 15000; break;
		case 3: rbowl[2] = "Beef Katsu Topping"; rbtopprice = rbtopprice + 18000; break;
		case 4: rbowl[2] = "Tempura Topping"; rbtopprice = rbtopprice + 18000; break;
		case 5: rbowl[2] = "Chicken Teriyaki Topping"; rbtopprice = rbtopprice + 16000; break;
		case 6: rbowl[2] = "Beef Teriyaki Topping"; rbtopprice = rbtopprice + 19000; break;
		case 7: rbowl[2] = "Shrimp Topping"; rbtopprice = rbtopprice + 16000; break;
		case 8: rbowl[2] = "Fried Chicken Topping"; rbtopprice = rbtopprice + 10000; break;
		default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		rbtopping();
		break;
	}
		cout << "How many more topping do you want? "; cin >> rbowlquantity;
		for (int indext = 0; indext < rbowlquantity; indext++) {
			cout << "Topping for rice bowl number " << indext + 1 << ": ";
			cin >> rbtchooseif;
			switch (rbtchooseif)
			{
			case 1: topif[tif] = "Omelette Topping"; rbtopprice = rbtopprice + 4000; break;
			case 2: topif[tif] = "Chicken Katsu Topping"; rbtopprice = rbtopprice + 15000; break;
			case 3: topif[tif] = "Beef Katsu Topping"; rbtopprice = rbtopprice + 18000; break;
			case 4: topif[tif] = "Tempura Topping"; rbtopprice = rbtopprice + 18000; break;
			case 5: topif[tif] = "Chicken Teriyaki Topping"; rbtopprice = rbtopprice + 16000; break;
			case 6: topif[tif] = "Beef Teriyaki Topping"; rbtopprice = rbtopprice + 19000; break;
			case 7: topif[tif] = "Shrimp Topping"; rbtopprice = rbtopprice + 16000; break;
			case 8: topif[tif] = "Fried Chicken Topping"; rbtopprice = rbtopprice + 10000; break;
			default:cout << "Please choose from the numbers above." << endl;
				system("pause");
				system("cls");
				rbtopping();
				break;
			}tif++;
		}
		for (int Findext = 0; Findext <= tif; Findext++) {
			rbowl[2] = rbowl[2] + " | " + topif[Findext];
		}
		system("cls");
	}
	system("cls");
}

void rbvegetable() {
	cout << "\nRice Bowl:" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Vegetables:\n" << endl;
	cout << "1. Tomato\n" << endl;
	cout << "2. Cucumber\n" << endl;
	cout << "3. Cabbage\n" << endl;
	cout << "4. Mushroom\n" << endl;
	cout << "5. Broccoli\n" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Your choice: "; cin >> rbvegChoice;
	switch (rbvegChoice)
	{
	case 1: rbowl[3] = "With Tomatoes"; break;
	case 2: rbowl[3] = "With Cucumbers"; break;
	case 3: rbowl[3] = "With Cabbages"; break;
	case 4: rbowl[3] = "With Mushrooms"; break;
	case 5: rbowl[3] = "With Broccolis"; break;
	default:cout << "Please choose from the numbers above." << endl;
		system("pause");
		system("cls");
		rbvegetable();
		break;
	}system("cls");
}

void rbowlConfirm() {
	cout << "\nYour rice bowl type selections:" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << rbowl[i] << endl;
	}
	cout << "\nConfirm?(y/n): "; cin >> rconfirm;
	if (rconfirm == 'y') {
	}
	else if (rconfirm == 'n') {
		cout << "Which category do you want to change?" << endl;
		cout << "(Please select according to the numbers above.)" << endl;
		cout << "I want to change number "; cin >> rbchange;
		switch (rbchange)
		{
		case 1: rbricetype(); rbowlConfirm(); break;
		case 2: rbpackage(); rbtopping(); rbowlConfirm(); break;
		case 3:	rbtopping(); rbowlConfirm(); break;
		case 4: rbvegetable(); rbowlConfirm(); break;
		default:
			cout << "Please choose from among the numbers above." << endl;
			system("pause");
			system("cls");
			rbowlConfirm();
			break;
		}
	}
	else {
		cout << "Please type y/n" << endl;
		system("pause");
		system("cls");
		rbowlConfirm();
	}
}


void rbowlbill() {
	rbowlprices[rb] = rbrtypeprice + rbpackprice + rbtopprice;
	cout << "Rice Bowl Price: " << rbowlprices[rb] << endl;
	rb++;
	system("pause");
	system("cls");
	menu1();
}

void ricebowsel() {
	rbricetype();
	rbpackage();
	rbtopping();
	rbvegetable();
	rbowlConfirm();
	rbowlbill();
}

void drink() {
	system("cls");
	menu2();


	while (1 < 2) {
		int total_price_milk = pricemilk1 + pricemilk2 + pricemilk3;
		int total_price_coffee = pricecoffee1 + pricecoffee2 + pricecoffee3 + pricecoffee4;
		int total_price_maindrink = pricedrink1 + pricedrink2 + pricedrink3 + pricedrink4 + pricedrink5 + pricedrink6;
		int total_price = total_price_maindrink + total_price_milk + total_price_coffee;
		int pricetemp = 0;
		cout << endl;
		cout << "\nYour Answer \t\t: "; cin >> main_drink;

		if (main_drink == 1) {
			cout << "\nWith ice (y/n) \t\t: "; cin >> ice;
			cout << "With sugar (y/n) \t: "; cin >> sugar;
			cout << "Many Drink \t\t: "; cin >> many_drink1;
			pricedrink1 = (many_drink1 * drink_price[0]) + pricedrink1;
			pricetemp = many_drink1 * drink_price[0];
			cout << "\nTotal Price For Olong Tea : Rp. " << pricetemp;
			continue;

		}

		else if (main_drink == 2) {
			cout << "With ice (y/n) \t\t: "; cin >> ice;
			cout << "With sugar (y/n) \t: "; cin >> sugar;
			cout << "Many Drink \t\t: "; cin >> many_drink2;
			pricedrink2 = many_drink2 * drink_price[1] + pricedrink2;
			pricetemp = many_drink2 * drink_price[1];
			cout << "Total Price For Lemon Tea : Rp. " << pricetemp;
			continue;
		}

		else if (main_drink == 5) {
			cout << "With ice (y/n) \t\t: "; cin >> ice;
			cout << "With sugar (y/n) \t: "; cin >> sugar;
			cout << "Many Drink \t\t: "; cin >> many_drink5;
			pricedrink5 = many_drink5 * drink_price[4] + pricedrink5;
			pricetemp= many_drink5 * drink_price[4];
			cout << "\nTotal Price For Orange Juice : Rp. " << pricetemp;
			continue;
		}

		else if (main_drink == 6) {
			cout << "With ice (y/n) \t\t: "; cin >> ice;
			cout << "With sugar (y/n) \t: "; cin >> sugar;
			cout << "Many Drink \t\t: "; cin >> many_drink6;
			pricedrink6 = many_drink6 * drink_price[5] + pricedrink6;
			pricetemp= many_drink6 * drink_price[5];
			cout << "\nTotal Price For Apple Juice : Rp. " << pricetemp;
			continue;
		}

		else if (main_drink == 3) {
			cout << "\nWith ice (y/n) \t\t: "; cin >> ice;
			cout << "With sugar (y/n) \t: "; cin >> sugar;
			cout << "Many Drink \t\t: "; cin >> many_drink3;
			pricedrink3 = many_drink3 * drink_price[2] + pricedrink3;
			pricetemp = many_drink3 * drink_price[2];
			cout << "\nTotal Price For Mineral Water = Rp. " << pricetemp;
			continue;
		}
		else if (main_drink == 4) {
			cout << "\nWith ice (y/n) \t\t: "; cin >> ice;
			cout << "With sugar (y/n) \t: "; cin >> sugar;
			cout << "Many Drink \t\t: "; cin >> many_drink4;
			pricedrink4 = many_drink4 * drink_price[3] + pricedrink4;
			pricetemp = many_drink4 * drink_price[3];
			cout << "\nTotal Price For Cola = Rp. " << pricetemp;
			continue;
		}



		else if (main_drink == 7) {
		 system("cls");
			coffee_menu();

			while (1 < 2) {
				int pricetemp = 0;

				cout << endl;
				cout << "\nYour Answer \t: "; cin >> coffee_type;

				if (coffee_type == 1) {

					cout << "Many Order \t: "; cin >> many_coffee1;
					pricecoffee1 = many_coffee1 * pricecoffee[0] + pricecoffee1;
					pricetemp= many_coffee1 * pricecoffee[0];
					cout << "Total Price For Americano : Rp. " << pricetemp;
					continue;
				}
				else if (coffee_type == 2) {

					cout << "Many Order \t: "; cin >> many_coffee2;
					pricecoffee2 = many_coffee2 * pricecoffee[1] + pricecoffee2;
					pricetemp= many_coffee2 * pricecoffee[1];
					cout << "Total Price For Espresso : Rp. " << pricetemp;
					continue;
				}
				else if (coffee_type == 3) {

					cout << "Many Order \t: "; cin >> many_coffee3;
					pricecoffee3 = many_coffee3 * pricecoffee[2] + pricecoffee3;
					pricetemp= many_coffee3 * pricecoffee[2];
					cout << "Total Price For Latte : Rp. " << pricetemp;
					continue;
				}

				else if (coffee_type == 4) {

					cout << "Many Order \t: "; cin >> many_coffee4;
					pricecoffee4 = many_coffee4 * pricecoffee[3] + pricecoffee4;
					pricetemp = many_coffee4 * pricecoffee[3];
					cout << "Total Price For Cappucino : Rp. " << pricetemp;
					continue;
				}

				else if (coffee_type == 5) {
					break;
				}
				cout << endl;
				system("pause"); system("cls");
				break;
			}
			system("cls");
			menu2();
			continue;
		}

		else if (main_drink == 8) {
			system("cls");
			milk_menu();

			while (1 < 2) {
				int pricetemp = 0;
				cout << endl;
				cout << "\nYour Answer \t: "; cin >> milk_type;

				if (milk_type == 1) {

					cout << "Many Order \t: "; cin >> many_milk1;
					pricemilk1 = many_milk1 * pricemilk[0] + pricemilk1;
					pricetemp = many_milk1 * pricemilk[0];
					cout << "Total Price For Soy Milk : Rp. " << pricetemp;
					continue;
				}
				else if (milk_type == 2) {

					cout << "Many Order \t: "; cin >> many_milk2;
					pricemilk2 = many_milk2 * pricemilk[1] + pricemilk2;
					pricetemp = many_milk2 * pricemilk[1];
					cout << "Total Price For Almond Milk : Rp. " << pricetemp;
					continue;
				}
				else if (milk_type == 3) {

					cout << "Many Order \t: "; cin >> many_milk3;
					pricemilk3 = many_milk3 * pricemilk[2] + pricemilk3;
					pricetemp = many_milk3 * pricemilk[2];
					cout << "Total Price For Whole Milk : Rp. " << pricetemp;
					continue;
				}

				else if (milk_type == 4) {
					break;
				}cout << endl;
				system("pause"); system("cls");
				break;
			}
			system("cls");
			menu2();
			continue;
		}

		else if (main_drink == 9) {
			system("cls");
			cout << "\n------------------------------------------------------------------";
			cout << "\n               " << "Notes/Request Page" << "                    ";
			cout << "\n------------------------------------------------------------------";
			cout << endl;
			cout << "\nHow Many Notes/Request You Want To Add ? : "; cin >> many_notes;

			for (int c = 0; c < many_notes; c++) {
				cin.ignore();
				cout << "Notes/Request [" << c + 1 << "] : ";
				getline(cin, notes[c]);
			}
			cout << endl;
			system("pause"); system("cls");
			menu2();
			continue;
		}

		else if (main_drink == 10) {
			 system("cls");
			cout << "\n------------------------------------------------------------------";
			cout << "\n          " << "List Of Notes/Request You Added" << "                    ";
			cout << "\n------------------------------------------------------------------";

			for (int d = 0; d < many_notes; d++) {
				cout << "\n[" << d + 1 << "] : " << notes[d];
			}
			cout << endl;
			system("pause"); system("cls");
			menu2();
			continue;
		}

		else if (main_drink == 11) {
		system("cls");
		db++;
		menu1();
		}
		else if (main_drink == 12) {
			system("pause"); system("cls");

			cout << "\n------------------------------------------------------------------";
			cout << "\n            " << "Total Price Of Drink You Ordered" << "                    ";
			cout << "\n------------------------------------------------------------------";
			cout << endl;
			cout << "\nTotal Price : Rp. " << total_price;
			drink_bill[db]= total_price;
			cout << endl;
			system("pause"); system("cls");
			drink();
		}

		cout << endl;
		system("pause"); system("cls");
		continue;
	}
}

void coffee_menu() {

	cout << "\n------------------------------------------------------------------";
	cout << "\n            " << " MINASAN'S RESTAURANT COFFEE MENU" << "                    ";
	cout << "\n------------------------------------------------------------------";
	cout << "\n\t  MENU\t\t||\t\t   PRICE";
	cout << "\n\t(1) Americano\t||\t\tRp. 20,000";
	cout << "\n\t(2) Espresso\t||\t\tRp. 25,000";
	cout << "\n\t(3) Latte\t||\t\tRp. 35,000";
	cout << "\n\t(4) Cappucino\t||\t\tRp. 26,000";
	cout << "\n-------------------------------------------------------------------";
	cout << "\n\t(5) Back To Drink Menu";
	cout << "\n-------------------------------------------------------------------";

}

void menu2() {



	cout << "\n------------------------------------------------------------------";
	cout << "\n            " << " MINASAN'S RESTAURANT DRINK MENU" << "                    ";
	cout << "\n------------------------------------------------------------------";
	cout << "\n\t\tMENU\t\t||\t\t   PRICE";
	cout << "\n\t(1) Olong Tea\t\t||\t\tRp. 8,000";
	cout << "\n\t(2) Lemon Tea\t\t||\t\tRp. 15,000";
	cout << "\n\t(3) Mineral Water\t||\t\tRp. 5,000";
	cout << "\n\t(4) Cola\t\t||\t\tRp. 12,000";
	cout << "\n\t(5) Orange Juice\t||\t\tRp. 16,000";
	cout << "\n\t(6) Apple Juice\t\t||\t\tRp. 19,000";
	cout << "\n\t(7) Coffee\t\t||\t\tRp. 20,000 - 35,000";
	cout << "\n\t(8) Milk\t\t||\t\tRp. 12,000 - 20,000";
	cout << "\n-------------------------------------------------------------------";
	cout << "\n\t(9) Add Notes/Request For Drink Orders";
	cout << "\n\t(10) Check Added Notes/Request For Drink Orders";
	cout << "\n\t(11) Back To Main Menu ";
	cout << "\n\t(12) Check Total Price Of Drink You Ordered";
	cout << "\n-------------------------------------------------------------------";




}


void milk_menu() {
	cout << "\n------------------------------------------------------------------";
	cout << "\n            " << " MINASAN'S RESTAURANT MILK MENU" << "                    ";
	cout << "\n------------------------------------------------------------------";
	cout << "\n\t    MENU\t\t||\t\t   PRICE";
	cout << "\n\t(1) Soy Milk\t\t||\t\tRp. 18,000";
	cout << "\n\t(2) Almond Milk\t\t||\t\tRp. 20,000";
	cout << "\n\t(3) Whole Milk\t\t||\t\tRp. 12,000";
	cout << "\n-------------------------------------------------------------------";
	cout << "\n\t(4) Back To Drink Menu ";
	cout << "\n-------------------------------------------------------------------";


}


void wholebill() {

	int Framenbill = 0;
	int Fsushibill = 0;
	int Frbowlbill = 0;
	int Fdrinkbill = 0;
	int Total;
	int pay;
	int change;

	cout << "\nTotal Bill:" << endl;
	cout << "\n-----------------------------------" << endl;
	for (int i = 0; i < r; i++) {
		Framenbill += ramenprices[i];
	}
	cout << "Total Ramen Bill: " << Framenbill;
	for (int i = 0; i < s; i++) {
		Fsushibill += sushiprices[i];
	}
	cout << "\nTotal Sushi Bill: " << Fsushibill;
	for (int i = 0; i < rb; i++) {
		Frbowlbill += rbowlprices[i];
	}
	cout << "\nTotal Rice Bowl Bill: " << Frbowlbill << endl;
	for (int i = 0; i < db; i++) {
		Fdrinkbill += drink_bill[i];
	}
	cout << "Total Drink Bill: " << Fdrinkbill << endl;
	cout << "-----------------------------------" << endl;
	Total = Framenbill + Fsushibill + Frbowlbill + Fdrinkbill;
	cout << "Total: " << Total << endl;
	cout << "Pay: "; cin>> pay;
	if (Total <= pay) {
		change = pay - Total;
		cout << "Change: " << change << endl;
		cout << "\nThank you for your purchase! Enjoy!" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	else {
		cout << "\nI am sorry. Your money is not enough to pay the bill.\nPlease re-enter enough money." << endl;
		system("pause");
		system("cls");
		wholebill();
	}
}

