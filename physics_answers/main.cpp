#include "main.hpp"
#pragma execution_character_set( "utf-8" )

using namespace std;

int main()
{
	SetConsoleOutputCP(65001); system(skCrypt("@echo off"));
	printf(banner);
	printf(module_list); scanf_s("%d", &module_variant);

	switch (module_variant) {
	case 1:
		procName =   "Project1";
		task_adr =   (PBYTE*)0x00479BE4;
		var_adr =    (PBYTE*)0x00479BE8;
		answ1_adr =  (PBYTE*)0x00479C14;
		answ2_adr =  (PBYTE*)0x00479C1C;
		answ3_adr =  (PBYTE*)0x00479C24;
		answ4_adr =  (PBYTE*)0x00479C2C;
		break;
	case 2:
		procName =   "Project1";
		task_adr =   (PBYTE*)0x0047ABE4;
		var_adr =    (PBYTE*)0x0047ABE8;
		answ1_adr =  (PBYTE*)0x0047AC14;
		answ2_adr =  (PBYTE*)0x0047AC1C;
		answ3_adr =  (PBYTE*)0x0047AC24;
		answ4_adr =  (PBYTE*)0x0047AC2C;
		break;
	case 3:
		procName =   "ProjectModul4";
		task_adr =   (PBYTE*)0x0047BBE4;
		var_adr =    (PBYTE*)0x0047ABE8;
		answ1_adr =  (PBYTE*)0x0047BC24;
		answ2_adr =  (PBYTE*)0x0047BC2C;
		answ3_adr =  (PBYTE*)0x0047BC34;
		answ4_adr =  (PBYTE*)0x0047BC3C;
		break;
	case 4:
		procName =   "Project1";
		task_adr =   (PBYTE*)0x00476BDC;
		var_adr =    (PBYTE*)0x00476BE0;
		answ1_adr =  (PBYTE*)0x00476C0C;
		answ2_adr =  (PBYTE*)0x00476C14;
		answ3_adr =  (PBYTE*)0x00476C1C;
		answ4_adr =  (PBYTE*)0x00476C24;
		break;
	case 5:
	case 7:
	case 9:
		procName =   "Project1";
		task_adr =   (PBYTE*)0x00476BE4;
		var_adr =    (PBYTE*)0x00476BE8;
		answ1_adr =  (PBYTE*)0x00476C14;
		answ2_adr =  (PBYTE*)0x00476C1C;
		answ3_adr =  (PBYTE*)0x00476C24;
		answ4_adr =  (PBYTE*)0x00476C2C;
		break;
	case 6:
	case 8:
	case 10:
	case 11:
		procName =   "Project1";
		task_adr =   (PBYTE*)0x00477BE4;
		var_adr =    (PBYTE*)0x00477BE8;
		answ1_adr =  (PBYTE*)0x00477C14;
		answ2_adr =  (PBYTE*)0x00477C1C;
		answ3_adr =  (PBYTE*)0x00477C24;
		answ4_adr =  (PBYTE*)0x00477C2C;
		break;
	default:
		printf(skCrypt("Модуль не найден\n"));
		system(skCrypt("pause"));
		exit(-1);
		break;
	}

	while (true) {
		hwnd = FindWindowA(NULL, procName);
		if (hwnd == NULL) {
			printf(skCrypt("Программа не найдена\n"));
			system(skCrypt("pause"));
		} else {
			break;
		}
	}
	LI(DWORD, GetWindowThreadProcessId).call(hwnd, &ProcId);
	HANDLE handle = LI(HANDLE, OpenProcess).call(PROCESS_ALL_ACCESS, FALSE, ProcId);

	if (ProcId == NULL) {
		exit(-1);
	} else {
		system("mode con cols=35 lines=8");
		while (true) {
			ReadProcMem(handle, task_adr, &task_num, sizeof(task_num), 0);
			ReadProcMem(handle, var_adr, &var_num, sizeof(var_num), 0);
			ReadProcMem(handle, answ1_adr, &answ1, sizeof(answ1), 0);
			ReadProcMem(handle, answ2_adr, &answ2, sizeof(answ2), 0);
			ReadProcMem(handle, answ3_adr, &answ3, sizeof(answ3), 0);
			ReadProcMem(handle, answ4_adr, &answ4, sizeof(answ4), 0);
			system(skCrypt("cls"));
			printf(skCrypt("Номер задания: %d\n"), task_num);
			printf(skCrypt("Номер варианта: %d\n"), var_num);
			printf(skCrypt("Ответ 1: %g\n"), answ1);
			printf(skCrypt("Ответ 2: %g\n"), answ2);
			printf(skCrypt("Ответ 3: %g\n"), answ3);
			printf(skCrypt("Ответ 4: %g\n\n"), answ4);
			system(skCrypt("pause"));
		}
	}

	return 0;
}