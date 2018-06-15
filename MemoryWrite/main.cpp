#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	int newValue = 16128; // New value for target address
	HWND hwnd = FindWindowA(NULL, "Fusion 3.64 - Genesis - ROCKET KNIGHT ADVENTURES"); // Title of application
	do {
		if (hwnd == NULL) // If handle not found
		{
			cout << "Cannot find window" << endl;
			Sleep(3000);
			exit(-1);
		}
		else
		{
			DWORD procID;
			GetWindowThreadProcessId(hwnd, &procID);
			HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

			if (procID == NULL)
			{
				cout << "Cannot obtain process" << endl;
				Sleep(3000);
				exit(-1);
			}

			else
			{
				WriteProcessMemory(handle, (LPVOID)0x0A780CE0, &newValue, sizeof(newValue), 0); // Change address accordingly
			}
		}
		Sleep(1000);
	} while (1); // Keep writing to memory address

	return 0;
}