#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int* cpu;
	int* p;
	int* flag;
	int n;
	FILE* fp = fopen("2in.txt", "rt");
	FILE* fpo = fopen("2out.txt", "w");
	printf("����\n\n");
	printf("1. ������ ������ ����� �������\n");
	printf("2. ������������� ��������� ��������\n");
	printf("3. ������� �� �����\n");
	int m;
	scanf("%d", &m);
	switch (m) {
	case 1:
		printf("������� ���������� ���������: ");
		scanf("%d", &n);
		cpu = (int*)malloc(n * sizeof(int));
		flag = (int*)malloc(n * sizeof(int));
		p = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; ++i) {
			scanf("%d", &cpu[i]);
			flag[i] = 0;
		}
		break;
	case 2:
		printf("������� ���������� ���������: ");
		scanf("%d", &n);
		cpu = (int*)malloc(n * sizeof(int));
		flag = (int*)malloc(n * sizeof(int));
		p = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; ++i) {
			cpu[i] = rand() % 50;
			flag[i] = 0;
		}
		break;
	case 3:
		fscanf(fp, "%d", &n);
		cpu = (int*)malloc(n * sizeof(int));
		flag = (int*)malloc(n * sizeof(int));
		p = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; ++i) {
			fscanf(fp, "%d", &cpu[i]);
			flag[i] = 0;
		}
		fclose(fp);
		break;
	default:
		printf("�� �������� ��, ������� 1, 2 ��� 3!!!.\n");
		return 0;
	}
	if (n < 21) {
		printf("�������� ������: \n");
		printf("����� ��������: ");
		for (int i = 0; i < n; ++i) {
			printf("%5d ", i + 1);
		}
		printf("\n");
		printf("����� ��������: ");
		for (int i = 0; i < n; ++i) {
			printf("%5d ", cpu[i]);
		}
		printf("\n");
	}
	else {
		fprintf(fpo, "%s", "�������� ������ : \n");
		fprintf(fpo, "%s", "����� ��������: ");
		for (int i = 0; i < n; ++i) {
			fprintf(fpo, "%5d ", i + 1);
		}
		fprintf(fpo, "%s", "\n");
		fprintf(fpo, "%s", "����� ��������: ");
		for (int i = 0; i < n; ++i) {
			fprintf(fpo, "%5d ", cpu[i]);
		}
		fprintf(fpo, "%s", "\n");
	}
	int ni, kv, summv, ost, np, flag1, flag2, i1;
	ni = 0;
	np = 0;
	ost = 0;
	if (n < 21) {
		printf("��������� ������� ������: \n");
		printf("����� ��������   ����� ������� ��   ��������� ��������� ����� ��   ����� ���������� ��������   ����� ���������� ��������   ���������� ����� ��\n");
	}
	else {
		fprintf(fpo, "%s", "��������� ������� ������ : \n");
		fprintf(fpo, "%s", "����� ��������   ����� ������� ��   ��������� ��������� ����� ��   ����� ���������� ��������   ����� ���������� ��������   ���������� ����� ��\n");
	}
	while (np < n) {
		ni += 1;
		kv = rand() % 25;
		summv = kv + ost;
		flag1 = 0;
		flag2 = 0;
		while (flag1 == 0) {
			int min = 10000;
			int mini = -1;
			for (int i = 0; i < n; ++i) {
				if (flag[i] == 0) {
					if (((summv - cpu[i]) < min) && ((summv - cpu[i]) >= 0)) {
						min = summv - cpu[i];
						mini = i;
					}
				}
			}
			i1 = mini;
			if (i1 >= 0) {
				flag[i1] = 1;
				ost = summv - cpu[i1];
				if (flag2 == 0) {
					if (n < 21) {
						printf("%14d ", ni);
						printf("%18d ", kv);
						printf("%30d ", summv);
						printf("%27d ", i1 + 1);
						printf("%27d ", cpu[i1]);
						printf("%21d \n", ost);
					}
					else {
						fprintf(fpo, "%14d ", ni);
						fprintf(fpo, "%18d ", kv);
						fprintf(fpo, "%30d ", summv);
						fprintf(fpo, "%27d ", i1 + 1);
						fprintf(fpo, "%27d ", cpu[i1]);
						fprintf(fpo, "%21d \n", ost);
					}
					flag2 += 1;
				}
				else {
					if (n < 21) {
						printf("               ");
						printf("                   ");
						printf("%30d ", summv);
						printf("%27d ", i1 + 1);
						printf("%27d ", cpu[i1]);
						printf("%21d \n", ost);
					}
					else {
						fprintf(fpo, "               ");
						fprintf(fpo, "                   ");
						fprintf(fpo, "%30d ", summv);
						fprintf(fpo, "%27d ", i1 + 1);
						fprintf(fpo, "%27d ", cpu[i1]);
						fprintf(fpo, "%21d \n", ost);
					}
				}
				summv = ost;
				p[np] = i1;
				np += 1;
			}
			else {
				if (flag2 == 0) {
					if (n < 21) {
						printf("%14d ", ni);
						printf("%18d ", kv);
						printf("%30d ", summv);
						printf("                          -");
						printf("                           -");
						printf("%22d \n", ost);
					}
					else {
						fprintf(fpo, "%14d ", ni);
						fprintf(fpo, "%18d ", kv);
						fprintf(fpo, "%30d ", summv);
						fprintf(fpo, "                          -");
						fprintf(fpo, "                           -");
						fprintf(fpo, "%22d \n", ost);
					}
					flag2 += 1;
				}
				else {
					if (n < 21) {
						printf("               ");
						printf("                   ");
						printf("%30d ", summv);
						printf("                          -");
						printf("                           -");
						printf("%22d \n", ost);
					}
					else {
						fprintf(fpo, "               ");
						fprintf(fpo, "                   ");
						fprintf(fpo, "%30d ", summv);
						fprintf(fpo, "                          -");
						fprintf(fpo, "                           -");
						fprintf(fpo, "%22d \n", ost);
					}
				}
				flag1 = 1;
				ost = summv;
				break;
			}

		}
	}
	if (n < 21) {
		printf("������� ����������: \n");
		for (int i = 0; i < n; ++i) {
			printf("%5d ", p[i] + 1);
		}
	}
	else {
		fprintf(fpo, "%s", "������� ���������� : \n");
		for (int i = 0; i < n; ++i) {
			fprintf(fpo, "%5d ", p[i] + 1);
		}
	}
	fclose(fpo);
	return 0;
}
