/*트럼프 카드의 정보를 저장하기 위하여 구조체 struct Card { int suit; int rank; }; 를 정의하였 다.이 구조체의 멤버 suit는 카드의 무늬
(“spade”, “diamond”, “heart”, “clover”)를 저 장하기 위한 변수로 각각 ‘s’, ‘d’, ‘h’, ‘c’의 값으로 입력하고 enum SUIT
{ SPADE, DIAMIND, HEART, CLOVER } 로 저장한다.또한 멤버 rank(‘A’, 2 - 10, ‘J’, ‘Q’, ‘K’) 는 정 수 1 - 13의 값으로 입력하고 저장한다고
가정하시오.이 구조체의 배열을 이용하여 5장의 카드를 입 력 받아 순서대로 출력하는 프로그램을 작성하시오.단 각 카드는 rank가 작은 것을 먼저 출력하며,
rank 값이 같을 경우에는 위에 열거된 무늬 순으로 출력하시오.또한 동일한 카드를 입력할 경우에 는 “중복”, 불가능한 카드를 입력하면 “오류” 라고
출력하시오.“중복”과 “오류”가 동시에 발생하는 경우에는 “오류”로 출력하시오.
(Ex.s 1 h 2 s 3 c 2 c 3 (s 1) (h 2) (c 2) (s 3) (c 3) / s 1 h 2 c 2 c 3 s 1  중복 / s 1 h 2 c 2 c 3 s 14  오류)*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Card {
	int suit;
	int rank;
};
enum SUIT
{
	SPADE, DIAMOND, HEART, CLOVER
};
int test_dup_sorted(struct Card input[]);
int input_card(struct Card input[]);
void sort_card(struct Card input[]);
void printf_card(struct Card input[]);
int main(void)
{
	struct Card input[5];
	input_card(input);
	if (test_dup_sorted(input))
	{
		printf("중복\n");
		return 0;
	}
	sort_card(input);
	printf_card(input);

	return 0;
}
int test_dup_sorted(struct Card input[])
{
	int i;
	for (i = 0; i < 4; i++)
		if ((input[i].rank == input[i + 1].rank) && (input[i].suit == input[i + 1].suit))
		{
			return 1;
		}
	return 0;
}
int input_card(struct Card input[])
{
	int i = 0;
	char s[4];
	while (1)
	{
		scanf("%s%d", s, &input[i].rank);
		switch (s[0]) {
		case's':input[i].suit = SPADE; break;
		case'd':input[i].suit = DIAMOND; break;
		case'h':input[i].suit = HEART; break;
		case'c':input[i].suit = CLOVER; break;
		default:printf("오류\n"); return 1;
		}
		if (input[i].rank < 1 || input[i].rank>13)
		{
			printf("오류\n"); return 1;
		}
		if (i == 4)
			break;
		i++;
	}
	return 0;
}
void sort_card(struct Card input[])
{
	{
		struct Card tmp;
		int i, j;

		input_card(input, 5);
		for (j = 0; j<4; j++)
			for (i = 0; i<4; i++)
				if (input[i].rank > input[i + 1].rank || (input[i].rank ==
					input[i + 1].rank&&input[i].suit > input[i + 1].suit))
				{
					tmp = input[i];
					input[i] = input[i + 1];
					input[i + 1] = tmp;
				}
	}
}
void printf_card(struct Card input[])
{
	int i=0;
	for (i = 0; i < 5; i++)
	{
		switch (input[i].suit)
		{
		case SPADE: printf("(spade "); break;
		case DIAMOND: printf("(diamond "); break;
		case HEART: printf("(heart "); break;
		case CLOVER: printf("(clover "); break;
		}
		switch (input[i].rank)
		{
		case 1: printf(" A) "); break;
		case 11: printf(" J) "); break;
		case 12: printf(" Q) "); break;
		case 13: printf(" K) "); break;
		default: printf(" %d) ", input[i].rank); break;
		}
	}
}