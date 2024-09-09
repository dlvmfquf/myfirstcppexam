#pragma once

/*
0. 기본 베팅금액을 냄 - 저장할 변수 bettingMoney
0-1. 화투패 초기화 및 섞기 - 화투패 저장 - Card board;
1. 한장을 받음 - 변수 card playerDeck[2]
1-1. 컴퓨터도 한장 받음 - 변수  card comDeck[2]
2. 베팅 (다이, 콜, 하프, 쿼터, 따당) - 키보드 입력 후 누른 것에 따라 행동
2-1.다이(d) - 해당 라운드에서 지금까지 투자한 돈과 승리를 모두 포기 후 게임에서 빠짐 -- 1ㄷ1이라 다이하면 그 라운드가 끝남.
2-1-1. 다이했을 때 컴터가 콜하면 컴터에 선턴 넘어감 
2-2. 콜(c) - 베팅한 만큼의 돈을 걸고 판 끝내기 신청 - 상대방은 콜/다이만 가능
2-3. 하프(h) - 깔린 돈의 절반만큼 베팅
2-4. 쿼터(q) - 깔린 돈의 25% 베팅
2-5. 따당(t) - 앞사람이 건 돈의 2배 베팅
3. 한장을 또 받음
4. 패를 오픈해 높은 족보면 돈을 따감
5. 콜 또는 다이를 하면 그 라운드를 끝냄(1ㄷ1이라서)
6. 라운드가 끝남
7. 누가 이겼는지 계산
8. 돈 지급
9. 다음 라운드를 할 것인지 질문
10. 한다고 했을 시 보유 자금이 기본 베팅금액보다 적으면 게임이 불가능하다며 보유 자금을 보여주고 게임을 끝냄
10-1. 한다고 했을 시 보유 자금에서 기본 베팅금액 차감후 다음 라운드 시작
10-2. 안한다고 했을 시 보유 자금을 보여주며 게임을 끝냄

특수규칙
구사 - 4월+9월 - 땡이 없는 경우 그 판 무승부 후 돈을 그대로 놓은 채 재대결
땡잡이 - 3월 광+ 7월 열끗 - 장땡 미만의 땡을 다 잡을 수 있음 그런데 땡이 없으면 최하위 패

*/

//화투패는 월(1월 ~ 10월), 월이 아닌 것(광, 열끗 = 1/일반 = 0)으로 구성
struct Card
{
	int month;
	int lightOrAnimal;
};

class MainQuizGame
{
public:
	
	//게임 시작
	void StartGame();

	//화투패 초기화
	void InitCards();

	//화투패 섞기
	void ShuffleCards();
	
	//게임중
	void RunGame();

	//금액 보여주기
	void ShowMoney();

	//첫번째 카드 보여주기
	void ShowFirstCard();

	//두번째 카드 보여주기
	void ShowSecondCard();
	
	//기본 금액 베팅하기
	void BetStartMoney();

	//카드 한장 지급
	void GiveCard();

	//플레이어 행동
	void actPlayer();

	//다이
	void Die();

	//콜
	void Call();

	//하프
	void ActHalf();

	//쿼터
	void ActQuarter();

	//턴 변경
	void ChangeTurn();

	//패(플레이어) 계산
	void CalPlayerCards();

	//패(컴터) 계산
	void CalComCards();

	//결과 출력
	void PrintResult();

	//컴터 행동
	void ActCom();

	//돈 지급
	void GiveMoney();

	//행동리셋
	void ReSetAct();

	//계속할건지 말건지
	void Continue();

public:
	int index = 0;
	int playerMoney = 10000;
	int comMoney = 10000;
	int betMoney = 0;
	int playerBettingMoney = 0;
	int comBettingMoney = 0;
	int playerTurn = 1;
	int comTurn = 0;
	int comAct = 0;
	int playerAct = 0;
	int playerScore = 0;
	int comScore = 0;
	int playerWin = 0;

	bool isGamePlaying = true;
	Card board[20] = {};
	Card playerDeck[2] = {};
	Card comDeck[2] = {};



};