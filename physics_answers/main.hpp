#pragma once
#pragma execution_character_set( "utf-8" )

#include <cstdio>
#include <windows.h>
#include <skCrypter.h>
#include <lazy_import.hpp>

#include "text_template.hpp"

#define ReadProcMem LI(BOOL, ReadProcessMemory).call

HWND hwnd;
DWORD ProcId;

int module_variant;
const char* procName;

PBYTE* task_adr;
PBYTE* var_adr;
PBYTE* answ1_adr;
PBYTE* answ2_adr;
PBYTE* answ3_adr;
PBYTE* answ4_adr;

ULONG32 task_num;
ULONG32 var_num;
double answ1;
double answ2;
double answ3;
double answ4;
