//20242428 김범수

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

//2-2

// 파라미터
#define LEN_MIN  15   // 기차길이
#define LEN_MAX  50
#define STM_MIN  0    // 마동석체력
#define STM_MAX  5
#define PROB_MIN  10  // 확률
#define PROB_MAX  90
#define AGGRO_MIN  0  // 어그로범위
#define AGGRO_MAX  5

// 마동석이동방향
#define MOVE_LEFT  1
#define MOVE_STAY  0

// 좀비의공격대상
#define ATK_NONE  0
#define ATK_CITIZEN  1
#define ATK_DONGSEOK  2

// 마동석행동
#define ACTION_REST  0
#define ACTION_PROVOKE  1
#define ACTION_PULL  2

void intro();
int trainlen();
int Mhelth();
int percenta();
void trainstate(int, int, int, int, int);
void cstay(int, int);
void zstay(int);
void mstay(int, int, int);
void mallstay(int, int, int);
void cmov(int, int);
void zmov(int);
void mmov(int, int, int);
int minput();
int msidez();
void cprint();
void zprint();
int mprint();
void cendprint();
void zendprint1();
void zendprint2(int, int, int);
void mendprint();
int mchprint();
void mrprint();
void mpprint();

void intro() {
	printf("                                부산행\n");
	printf(".____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____\n");
	printf("|#### #### #### #### #### #### #### #### #### #### #### #### #### #### ####-])\n");
	printf("|--------------------------------------------------------------------------/)\n");
	printf("@ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @  @ @\n\n");
}
int trainlen(void) {
	int a;
	printf("train length(15~50)>> ");
	scanf_s("%d", &a);
	return a;
}
int Mhelth(void) {
	int a;
	printf("madongseok stamina(0~5)>> ");
	scanf_s("%d", &a);
	return a;
}
int percenta(void) {
	int a;
	printf("percentile probability 'p'(10~90)>> ");
	scanf_s("%d", &a);
	return a;
}
void trainstate(int tl, int cp, int zp, int mp, int imp) {
	for (int i = 0; i < tl; ++i) {
		printf("#");
	}
	printf("\n#");
	for (int i = 0; i < cp; ++i) {
		printf(" ");
	}
	printf("C");
	for (int i = 0; i < zp; ++i) {
		printf(" ");
	}
	printf("Z");
	for (int i = 0; i < mp; ++i) {
		printf(" ");
	}
	printf("M");
	for (int i = 0; i < imp; ++i) {
		printf(" ");
	}
	printf("#\n");
	for (int i = 0; i < tl; ++i) {
		printf("#");
	}
	printf("\n\n");
}
void cstay(int a, int b) {
	printf("citizen: stay %d (aggro: %d -> %d)\n", a, b + 1, b);
}
void cmov(int a, int b) {
	printf("citizen: %d -> %d (aggro: %d -> %d)\n", a + 1, a, b - 1, b);   //어그로 -안뜨게 하는 것 부터 시작
}
void zstay(int a) {
	printf("zombie: stay %d\n", a);
}
void zmov(int a) {
	printf("zombie: %d -> %d\n\n", a + 1, a);
}
void mstay(int a, int b, int c) {
	printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)\n", a, b + 1, b, c);
}
void mallstay(int a, int b, int c) {
	printf("madongseok: stay %d(aggro: %d, stamina: %d)\n", a, b, c);
}
void mmov(int a, int b, int c) {
	printf("madongseok: %d -> %d(aggro: %d -> %d, stamina: %d)\n", a + 1, a, b - 1, b, c);
}
int minput() {
	int a;
	printf("madongseok move(0:stay, 1:left)>> ");
	scanf_s("%d", &a);
	return a;
}
int msidez() {
	int a;
	printf("madongseok move(0:stay)>> ");
	scanf_s("%d", &a);
	return a;
}
void cprint() {
	printf("citizen does nothing.\n");
}
void zprint() {
	printf("zombie attcked nobody.\n");
}
int mprint() {
	int a;
	printf("madongseok action(0. rest, 1.provoke)>> ");
	scanf_s("%d", &a);
	return a;
}
void cendprint() {
	printf("YOU WIN!\n");
}
void zendprint1() {
	printf("GAME OVER! citizen dead...\n");
}
void zendprint2(int a, int b, int c) {
	printf("Zombie attacked madongseok (aggro: %d vs. %d, magongseok stamina: %d -> %d)\n\n", a, b, c + 1, c);
}
void mendprint() {
	printf("GAME OVER! madongseok dead...\n");
}
int mchprint() {
	int a;
	printf("madongseok action(0, rest, 1.provoke, 2.pull)>> ");
	scanf_s("%d", &a);
	return a;
}
void mrprint() {
	printf("madongseok rest...\n");
}
void mpprint() {
	printf("madongseok provoked zombie...\n");
}

int main(void) {

	int zcantm = 0;
	int TLA, MHA, PPA, cpos, zpos, mpos, imptya, caggro = 1, maggro = 1, cmove, zmove, mmove, C, Z, M, aevnum = 0, mdef, cdef, zdef;
	int cm = 0, cznm = 0, cnm = 0, cmamx = 0, cmami = 0, zennm = 0, zcm = 0, zmm = 0, zmnm = 0;    //어떤경우 움직였는지
	srand((unsigned int)time(NULL));
//2-1
	intro();    //부산헹1 정리
	while (1) {                    //기차길이
		TLA = trainlen();
		if (TLA >= LEN_MIN && TLA <= LEN_MAX) {
			break;
		}
	}
	while (1) {                   //마동석 체력
		MHA = Mhelth();
		if (MHA >= STM_MIN && MHA <= STM_MAX) {
			break;
		}
	}
	while (1) {                   //확률
		PPA = percenta();
		if (PPA >= PROB_MIN && PPA <= PROB_MAX) {
			break;
		}
	}

	cpos = TLA - 8;     //초기값
	zpos = 3;
	mpos = 0;
	imptya = 0;
	C = TLA - 7;
	Z = TLA - 3;
	M = TLA - 2;
	printf("\n");
	trainstate(TLA, cpos, zpos, mpos, imptya);   //초기값 출력
	printf("\n\n");

	while (1) {

		aevnum = aevnum + 1;
		int crp = rand() % 100 + 1;
		cmove = C;                //위치 값
		zmove = Z;
		mmove = M;
		cdef = C - 1;             //예외 처리를 위한 변수
		zdef = Z - 1;
		mdef = M - 1;
//2-3
		if (crp > PPA) {            //시민 움직이기
			cpos = cpos - 1;
			zpos = zpos + 1;
			C = C - 1;
			caggro = caggro + 1;
			if (caggro >= AGGRO_MAX) {
				caggro = caggro - 1;
				cmamx = 1;
			}
			else {
				cm = 1;
			}
		}
		else {
			caggro = caggro - 1;      //어그로 감소
			if (caggro < AGGRO_MIN) {
				caggro = AGGRO_MIN;
				cmami = 1;
			}
			else {
				cnm = 1;
			}
		}
		cdef = C - 1;

		if (aevnum % 2 == 0 || zcantm == 1) {          //짝수턴 마다 좀비 움직이기
			zcantm = 0;
			zennm = 1;
		}
		else {
			if (mdef == Z) {
				if (caggro >= maggro) {  //그 외는 시민
					Z = Z - 1;
					zpos = zpos - 1;
					mpos = mpos + 1;
					zcm = 1;
				}
				else {
					zmnm = 1;
				}
			}
			else if (zdef == C) {
				if (caggro < maggro) {  //마동석어그로가 크면 마동석한테 이동
					Z = Z + 1;
					zpos = zpos + 1;
					mpos = mpos - 1;
					zmm = 1;
				}
				else {
					zmnm = 1;
				}
			}
			else if (mdef == Z && zdef == C) {
				zmnm = 1;               //시민 좀비 둘 다 붙어있어서 좀비가 안움직음
			}
			else {
				if (caggro >= maggro) {  //그 외는 시민
					Z = Z - 1;
					zpos = zpos - 1;
					mpos = mpos + 1;
					zcm = 1;
				}
				else if (caggro < maggro) {  //마동석어그로가 크면 마동석한테 이동
					Z = Z + 1;
					zpos = zpos + 1;
					mpos = mpos - 1;
					zmm = 1;
				}
			}
		}
		if (zpos < 0) {
			zpos = zpos + 1;
		}
		zdef = Z - 1;

		trainstate(TLA, cpos, zpos, mpos, imptya);   //1 출력
		if (cm == 1) {                //시민 출력
			cmov(C, caggro);
		}
		if (cmamx == 1) {
			printf("citizen: %d -> %d (aggro: %d)\n", C + 1, C, caggro);
		}
		if (cnm == 1) {
			cstay(C, caggro);
		}
		if (cmami == 1) {
			printf("citizen: stay %d (aggro: %d)\n", C, caggro);
		}
		if (zcm == 1) {          //좀비 출력
			zmov(Z);
		}
		if (zmm == 1) {
			printf("zombie: %d -> %d\n", Z - 1, Z);
		}
		if (zmnm == 1) {
			zstay(Z);
		}
		if (zennm == 1) {
			printf("zombie: stay %d(cannot move)\n", Z);  //좀비 짝수턴 출력
		}
		printf("\n");

		int mznm = 0, mm = 0, mmanm = 0, mnmanm = 0;
		while (1) {                       //마동석 이동
			if (Z == mdef) {           //마동석, 좀비가 붙어있을 때
				int msoma = msidez();
				if (msoma == MOVE_STAY) {
					if (maggro == AGGRO_MIN) {
						mnmanm = 1;
					}
					else {
						maggro = maggro - 1;
						mznm = 1;
					}
					break;
				}
			}
			else {
				int msom = minput();
				if (msom == MOVE_STAY) {
					if (maggro == AGGRO_MIN) {
						mnmanm = 1;
					}
					else {
						maggro = maggro - 1;
						mznm = 1;
					}
					break;
				}
				if (msom == MOVE_LEFT) {
					M = M - 1;
					mpos = mpos - 1;
					imptya = imptya + 1;
					if (maggro >= AGGRO_MAX) {
						maggro = AGGRO_MAX;
						mmanm = 1;
					}
					else {
						maggro = maggro + 1;
						mm = 1;
					}
					break;
				}
			}
		}
		mdef = M - 1;

		trainstate(TLA, cpos, zpos, mpos, imptya);    //2 출력
		printf("\n");

		if (mznm == 1) {                //마동석 출력
			mstay(M, maggro, MHA);
		}
		if (mm == 1) {
			mmov(M, maggro, MHA);
		}
		if (mmanm == 1) {
			printf("madongseok: %d -> %d(aggro: %d, stamina: %d)\n", M + 1, M, maggro, MHA);
		}
		if (mnmanm == 1) {
			mallstay(M, maggro, MHA);
		}
		printf("\n");
//2-4
		if (cdef == 0) {              //시민 행동 패이지 출력
			cendprint();
			break;
		}
		else {
			cprint();
		}

		if (C == zdef && Z == mdef) {         //좀비 시패이지 출력
			if (caggro > maggro) {
				zendprint1();
				break;
			}
			else {
				MHA = MHA - 1;
				zendprint2(caggro, maggro, MHA);
				if (MHA <= STM_MIN) {
					mendprint();
					break;
				}
			}
		}
		else if (C == zdef) {
			zendprint1();
			break;
		}
		else if (Z == mdef) {
			MHA = MHA - 1;
			printf("Zombie attacked madongseok(madongseok stamina: %d -> %d)\n", MHA + 1, MHA);
			if (MHA == STM_MIN) {
				mendprint();
				break;
			}
		}
		else {
			zprint();
		}
		printf("\n");
		while (1) {                               //마동석 행동 출력
			if (mdef == Z) {
				int mcht = mchprint();
				if (mcht == ACTION_REST) {
					if (maggro <= AGGRO_MIN) {
						if (MHA < STM_MAX) {
							MHA = MHA + 1;
							mrprint();
							printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n", M, maggro, MHA - 1, MHA);
						}
						else {
							mrprint();
							printf("madongseok: %d (aggro: %d, stamina: %d)\n", M, maggro, MHA);
						}
					}
					else {
						maggro = maggro - 1;
						if (MHA < STM_MAX) {
							MHA = MHA + 1;
							mrprint();
							printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, maggro + 1, maggro, MHA - 1, MHA);
						}
						else {
							mrprint();
							printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, maggro + 1, maggro, MHA);
						}
					}
					break;
				}
				else if (mcht == ACTION_PROVOKE) {
					if (maggro >= AGGRO_MAX) {
						mpprint();
						printf("madongseok: %d (aggro: %d, stamina: %d)\n", M, maggro, MHA);
					}
					else {
						int keepmag = maggro;
						maggro = maggro + 2;
						if (maggro < AGGRO_MAX) {
							maggro = AGGRO_MAX;
						}
						mpprint();
						printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, keepmag, maggro, MHA);
					}
					break;
				}
				else if (mcht == ACTION_PULL) {
					int mcper = rand() % 100 + 1;
					if (mcper > PPA) {
						int keepmag1 = maggro;
						maggro = maggro + 2;
						if (maggro > AGGRO_MAX) {
							maggro = AGGRO_MAX;
						}
						MHA = MHA - 1;
						zcantm = 1;    //마동석 좀비 붙잡기 성공 좀비 다음턴 못움직임
						printf("madongseok pulled zombie... Next turn, it can't move\n");
						printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, keepmag1, maggro, MHA + 1, MHA);
					}
					else {
						int keepmag2 = maggro;
						maggro = maggro + 2;
						if (maggro > AGGRO_MAX) {
							maggro = AGGRO_MAX;
						}
						MHA = MHA - 1;
						printf("madongseok failed to pull zombie\n");
						printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, keepmag2, maggro, MHA + 1, MHA);
					}
					break;
				}
			}
			else {
				int mch = mprint();
				if (mch == ACTION_REST) {
					if (maggro <= AGGRO_MIN) {
						if (MHA >= STM_MAX) {
							mrprint();
							printf("madongseok: %d (aggro: %d, stamina: %d)\n", M, maggro, MHA);
						}
						else {
							MHA = MHA + 1;
							mrprint();
							printf("madongseok: %d (aggro: %d, stamina: %d -> %d)\n", M, maggro, MHA - 1, MHA);
						}
					}
					else {
						maggro = maggro - 1;
						if (MHA >= STM_MAX) {
							mrprint();
							printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, maggro + 1, maggro, MHA);
						}
						else {
							MHA = MHA + 1;
							mrprint();
							printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, maggro + 1, maggro, MHA - 1, MHA);
						}
					}
					break;
				}
				else if (mch == ACTION_PROVOKE) {
					if (maggro >= AGGRO_MAX) {
						mpprint();
						printf("madongseok: %d (aggro: %d, stamina: %d)\n", M, maggro, MHA);
					}
					else {
						int keepmag = maggro;
						maggro = AGGRO_MAX;
						mpprint();
						printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, keepmag, maggro, MHA);
					}
					break;
				}
			}
		}
		if (MHA == STM_MIN) {
			mendprint();
			break;
		}
		zennm = 0, cm = 0, cznm = 0, cnm = 0, cmamx = 0, cmami = 0, zcm = 0, zmm = 0, zmnm = 0;
		mznm = 0, mm = 0, mmanm = 0, mnmanm = 0;
		printf("\n\n");
	}

	return 0;
}