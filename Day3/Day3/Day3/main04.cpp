#include <iostream>

using namespace std;

void main()
{
	srand(time(NULL));
	int PlayerLv = 1;
	int GoblinLv = 1;
	int choice = 0;
	cout << "던전에 들어온 걸 환영합니다. 당신의 레벨은 1로 초기화 되었습니다." << endl;
	cout << "전진하면서 나타나는 고블린을 잡으며 최대한 높은 레벨로 탈출하십시오." << endl;
	cout << ".       ." << endl;
	cout << ".       ." << endl;
	cout << ".       ." << endl;
	cout << "Lv.1 고블린을 만났습니다 \n1. 싸운다(싸울 경우 ((고블린 레벨)/(1+당신의 레벨 *2)%의 확률로 목숨을 잃습니다)" << endl;
	cout << "2. 도망친다(도망칠 경우 고블린이 10%의 확률로 당신이 도망친 길을 발견해내어 사망합니다)" << endl;
	cin >> choice;


	//첫번째 선택
	//1 - 싸우기
	if (choice == 1)
	{
		cout << "1. 싸운다" << endl;
		int winrate = rand() % (GoblinLv * (1 + PlayerLv * 2));

		//1 - 싸워서 이겼다
		if (winrate > 0)
		{
			PlayerLv++;
			GoblinLv++;
			cout << "힘겨운 싸움 끝에 고블린을 쓰러뜨리고 레벨이 증가 하였습니다." << endl;
			cout << "현재 Lv." << PlayerLv << "입니다" << endl;
			cout << ".       ." << endl;
			cout << ".       ." << endl;
			cout << ".       ." << endl;
			cout << "Lv.2 고블린을 만났습니다 \n1. 싸운다" << endl;
			cout << "2. 도망친다" << endl;
			cin >> choice;
			
			//두번째 선택
			//2 - 싸우기
			if (choice == 1)
			{
				cout << "1. 싸운다" << endl;
				int winrate = rand() % (GoblinLv * (1 + PlayerLv * 2));

				//2 - 싸워서 이겼다
				if (winrate > 3)
				{
					PlayerLv++;
					GoblinLv++;
					cout << "힘겨운 싸움 끝에 고블린을 쓰러뜨리고 레벨이 증가 하였습니다." << endl;
					cout << "현재 Lv." << PlayerLv << "입니다" << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << "Lv.3 고블린을 만났습니다 \n1. 싸운다" << endl;
					cout << "2. 도망친다" << endl;
					cin >> choice;

					//세번째 선택 
					//3 - 싸우기
					if (choice == 1)
					{
						cout << "1. 싸운다" << endl;
						int winrate = rand() % (GoblinLv * (1 + PlayerLv * 2));

						//4 - 싸워서 이겼다
						if (winrate > 8)
						{
							PlayerLv++;
							GoblinLv++;
							cout << "힘겨운 싸움 끝에 고블린을 쓰러뜨리고 레벨이 증가 하였습니다." << endl;
							cout << "현재 Lv." << PlayerLv << "입니다" << endl;
							cout << "축하드립니다 던전을 빠져나오셨습니다. " << endl;
						}
						
						//4 - 싸워서 졌다
						else
						{
							cout << "마지막 빛을 쫓던 도중 고블린이 당신의 빛을 꺼뜨렸습니다.." << endl;
							cout << "당신의 여정은 이렇게 끝났습니다." << endl;
						}

					}

					//3 - 도망가기
					else if (choice == 2)
					{
						cout << "2. 도망친다" << endl;
						int suvrate = 1 + (rand() % 10);
						GoblinLv++;

						//4 - 도망가서 살았다
						if (suvrate < 10)
						{
							cout << "무사히 빠져나올 수 있었습니다." << endl;
							cout << "축하드립니다 던전을 빠져나오셨습니다. " << endl;
							cout << "현재 Lv." << PlayerLv << "입니다." << endl;
						}
						
						//4 - 도망가다 죽었다
						else
						{
							cout << "마지막 빛을 쫓던 도중 고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
							cout << "당신의 여정은 이렇게 끝났습니다." << endl;
						}
					}

					//3 - 1도 2도 안고름
					else
					{
						cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
					}
				}

				//2 - 싸워서 졌다
				else
				{
					cout << "힘겨운 싸움 끝에 결국 패배하고 말았습니다." << endl;
				}

			}

			//2 - 도망가기
			else if (choice == 2)
			{
				cout << "2. 도망친다" << endl;
				int suvrate = 1 + (rand() % 10);
				GoblinLv++;

				//2 - 도망가서 살았다
				if (suvrate < 10)
				{
					cout << "무사히 빠져나올 수 있었습니다." << endl;
					cout << "현재 Lv." << PlayerLv << "입니다" << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << "Lv.3 고블린을 만났습니다 \n1. 싸운다" << endl;
					cout << "2. 도망친다" << endl;
					cin >> choice;
					
					//세번째 선택(플레이어 2렙 고블린 3렙)
					//3 - 싸우기
					if (choice == 1)
					{
						cout << "1. 싸운다" << endl;
						int winrate = rand() % (GoblinLv * (1 + PlayerLv * 2));
						//3 - 싸워서 이겼다 
						if (winrate > 8)
						{
							PlayerLv++;
							
							cout << "힘겨운 싸움 끝에 고블린을 쓰러뜨리고 레벨이 증가 하였습니다." << endl;
							cout << "현재 Lv." << PlayerLv << "입니다" << endl;
							cout << "축하드립니다 던전을 빠져나오셨습니다. " << endl;
						}

						else 
						{
							cout << "마지막 빛을 쫓던 도중 고블린이 당신의 빛을 꺼뜨렸습니다.." << endl;
							cout << "당신의 여정은 이렇게 끝났습니다." << endl;
						}
					}


					//3 - 도망가기
					else if (choice == 2)
					{
						cout << "2. 도망친다" << endl;
						int suvrate = 1 + (rand() % 10);
						//3 - 도망가서 살았다
						GoblinLv++;
						if (suvrate < 10)
						{
							cout << "무사히 빠져나올 수 있었습니다." << endl;
							cout << "현재 Lv." << PlayerLv << "입니다" << endl;
							cout << ".       ." << endl;
							cout << ".       ." << endl;
							cout << ".       ." << endl;
							cout << "Lv."<< GoblinLv <<" 고블린을 만났습니다 \n1. 싸운다" << endl;
							cout << "2. 도망친다" << endl;
							cin >> choice;

							//4번째 선택 (플레이어 1렙, 고블린 3렙)
							//4 - 싸우기
							if (choice == 1)
							{
								cout << "1. 싸운다" << endl;
								cout << "마지막 빛을 쫓던 도중 고블린이 당신의 빛을 꺼뜨렸습니다.." << endl;
								cout << "당신의 여정은 이렇게 끝났습니다." << endl;
							}

							//4 - 도망가기
							else if (choice == 2)
							{
								cout << "2. 도망친다" << endl;
								int suvrate = 1 + (rand() % 10);

								//4 - 도망가서 살았다
								if (suvrate < 10)
								{
									cout << "무사히 빠져나올 수 있었습니다." << endl;
									cout << "축하드립니다 던전을 빠져나오셨습니다. " << endl;
									cout << "현재 Lv." << PlayerLv << "입니다." << endl;
								}
								//4 - 도망가다 죽었다
								else
								{
									cout << "마지막 빛을 쫓던 도중 고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
									cout << "당신의 여정은 이렇게 끝났습니다." << endl;
								}
							}

							//4 - 1도 2도 안고름
							else 
							{
								cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
							}
						}
						else
						{
							cout << "마지막 빛을 쫓던 도중 고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
							cout << "당신의 여정은 이렇게 끝났습니다." << endl;
						}

					}
					
					//3 - 1도 2도 안고름
					else
					{
						cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
					}
				}

				//2 - 도망가서 죽었다
				else
				{
					cout << "고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
					cout << "당신의 여정은 이렇게 끝났습니다." << endl;
				}

			}

			//2 - 1도 2도 안고름
			else
			{
				cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
			}


		}
		//1 - 싸워서 졌다
		else
		{
			cout << "힘겨운 싸움 끝에 결국 패배하고 말았습니다." << endl;
		}
	}



	// 첫번째 선택

	else if (choice == 2)
	{
		cout << "2. 도망친다" << endl;
		int suvrate = 1 + (rand() % 10);
		//1 - 도망가서 살았다
		GoblinLv++;
		if (suvrate < 10)
		{
			cout << "무사히 빠져나올 수 있었습니다." << endl;
			cout << "현재 Lv." << PlayerLv << "입니다" << endl;
			cout << ".       ." << endl;
			cout << ".       ." << endl;
			cout << ".       ." << endl;
			cout << "Lv.2 고블린을 만났습니다 \n1. 싸운다" << endl;
			cout << "2. 도망친다" << endl;
			cin >> choice;

			//두번째 선택
			//2 - 싸우기
			if (choice == 1)
			{
				cout << "1. 싸운다" << endl;
				int winrate = rand() % (GoblinLv * (1 + PlayerLv * 2));
				//2 - 싸워서 이겼다 
				if (winrate > 3)
				{
					PlayerLv++;
					GoblinLv++;
					cout << "힘겨운 싸움 끝에 고블린을 쓰러뜨리고 레벨이 증가 하였습니다." << endl;
					cout << "현재 Lv." << PlayerLv << "입니다" << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << "Lv.3 고블린을 만났습니다 \n1. 싸운다" << endl;
					cout << "2. 도망친다" << endl;
					cin >> choice;

					//세번째 선택(플레이어 1렙 고블린 3렙)
					if (choice == 1)
					{
						cout << "1. 싸운다" << endl;
						cout << "마지막 빛을 쫓던 도중 고블린이 당신의 빛을 꺼뜨렸습니다.." << endl;
						cout << "당신의 여정은 이렇게 끝났습니다." << endl;
					}
					
					else if (choice == 2)
					{
						cout << "2. 도망친다" << endl;
						int suvrate = 1 + (rand() % 10);
						GoblinLv++;

						//4 - 도망가서 살았다
						if (suvrate < 10)
						{
							cout << "무사히 빠져나올 수 있었습니다." << endl;
							cout << "축하드립니다 던전을 빠져나오셨습니다. " << endl;
							cout << "현재 Lv." << PlayerLv << "입니다." << endl;
						}
						//4 - 도망가다 죽었다
						else
						{
							cout << "마지막 빛을 쫓던 도중 고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
							cout << "당신의 여정은 이렇게 끝났습니다." << endl;
						}
					}

					else
					{
						cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
					}

				}


				//2 - 싸워서 졌다
				else
				{
					cout << "힘겨운 싸움 끝에 결국 패배하고 말았습니다." << endl;
				}

			}


			//두번째 선택
			//2 - 도망가기
			else if (choice == 2)
			{
				cout << "2. 도망친다" << endl;
				int suvrate = 1 + (rand() % 10); 
				GoblinLv++;
				
				//2 - 도망가서 살았다
				if (suvrate < 10)
				{

					cout << "무사히 빠져나올 수 있었습니다." << endl;
					cout << "현재 Lv." << PlayerLv << "입니다" << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << ".       ." << endl;
					cout << "Lv.3 고블린을 만났습니다 \n1. 싸운다" << endl;
					cout << "2. 도망친다" << endl;
					cin >> choice;


					//세번째 선택
					//3 - 싸우기
					if (choice == 1)
					{
						cout << "1. 싸운다" << endl;
						cout << "마지막 빛을 쫓던 도중 고블린이 당신의 빛을 꺼뜨렸습니다.." << endl;
						cout << "당신의 여정은 이렇게 끝났습니다." << endl;

					}
					//3 - 도망가기
					else if (choice == 2)
					{
						cout << "2. 도망친다" << endl;
						int suvrate = 1 + (rand() % 10);
					

						//4 - 도망가서 살았다
						if (suvrate < 10)
						{
							cout << "무사히 빠져나올 수 있었습니다." << endl;
							cout << "축하드립니다 던전을 빠져나오셨습니다. " << endl;
							cout << "현재 Lv." << PlayerLv << "입니다." << endl;
						}
						//4 - 도망가다 죽었다
						else
						{
							cout << "마지막 빛을 쫓던 도중 고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
							cout << "당신의 여정은 이렇게 끝났습니다." << endl;
						}
					}
					//3 - 1도 2도 안고름
					else
					{
						cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
					}
				}
				//2 - 도망가다 죽었다
				else
				{
					cout << "고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
					cout << "당신의 여정은 이렇게 끝났습니다." << endl;
				}

			}
			//2 - 1도 2도 안고름
			else
			{
				cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
			}


		}

		//1 - 도망가다 죽었다
		else
		{
			cout << "고블린이 당신의 길을 발견해 습격 당했습니다." << endl;
			cout << "당신의 여정은 이렇게 끝났습니다." << endl;
		}
	}

	//1 - 1도 2도 안고름
	else
	{
		cout << "당신은 잘못된 선택으로 인해 목숨을 잃게 되었습니다..";
	}


}
