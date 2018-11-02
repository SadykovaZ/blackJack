#include "BlackJackConsoleView.h"



BlackJackConsoleView::BlackJackConsoleView()
	:game(0,0)
{
	cout << "Hello!";
	printAddMoney();
	cout << "\n-------\n";
	printSetBet();
}

void BlackJackConsoleView::start()
{
	int choice = 0;
	while (1) {
		system("cls");
		printScreen();
		cin >> choice;
		//если игры нет
		if (!game.isGameStart()) {
			if (choice == 4) break;
			
			if (choice == 1) {
				game.startRound();
				continue;
			}
			if (choice == 2) {
				printAddMoney();
				continue;
			}
			if (choice == 3) {
				printSetBet();
				continue;
			}

			
		}
		
		if (game.isGameStart()) {
			//1 - get new Card 2 - stop 3 - exit
			//int result = game.checkRound();
			//if (result == 1) continue;
			//if (result == 2) {

			//}
			////
			//}

	}
	system("cls");
	cout << "Good bye!\n";
}

void BlackJackConsoleView::printScreen()
{
	cout << "------------------------------\n";
	cout << "diller\'s cards\n";
	for (size_t i = 0; i < game.getDillerCards().size(); i++)
	{
		cout << game.getDillerCards()[i].getInfo()<<endl;
	}
	cout << "\ndiller\'s points = " << game.getPoints(game.getDillerCards());
	cout << "\n\nYour cards\n";
	for (size_t i = 0; i < game.getPlayerCards().size(); i++)
	{
		cout << game.getPlayerCards()[i].getInfo() << endl;
	}
	cout << "\nYour points = " << game.getPoints(game.getPlayerCards());
	cout << "\nYour money = " << game.getMoney();
	cout << "\nYour bet = " << game.getBet();
	cout << "\n-----------------\n";
	printMenu();
}

void BlackJackConsoleView::printMenu()
{
	//если игра началась
	if (game.isGameStart()) {
		cout << "1 - get new Card\n2 - stop\n3 - exit";
	}
	else {
		//нет нового раунда
		cout << "1 - new game\n2 - Add money\n3 - Set Bet\n4 - exit";
	}
}

void BlackJackConsoleView::printAddMoney()
{
	cout << "Add money";
	int m;
	cin >> m;
	game.addMoney(m);
}

void BlackJackConsoleView::printSetBet()
{
	cout << "set bet";
	int b;
	cin >> b;
	game.setBet(b);
}



