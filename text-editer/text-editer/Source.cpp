#include <fstream>
#include <iostream>
#include <string>
#include<windows.h>
#include<conio.h>

int main(int argc, char* argv[]) {
	BOOL bRet;
	CONSOLE_SCREEN_BUFFER_INFO info;

	bRet = GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&info);

	char c, buffer[100];
	int size;
	//バッファサイズ割り出し
	size = info.dwSize.X * info.dwSize.Y;

	printf("命令入力->w:新規作成 e:ファイル読み出し");
	scanf_s("%c", &c);

	switch (c) {
	case 'w': {
		//新規ファイル作成
		std::fstream writing_file;
		std::string filename = "sample.txt";
		writing_file.open(filename,  std::ios::app);

			printf("入力->");
			scanf_s("%s", &buffer, sizeof(size));
			writing_file << buffer << std::endl;
			std::cout << std::flush;

		writing_file.close();
	}
			  break;

	case 'e': {
		//ファイル読み出し
		std::ifstream ifs("sample.txt");
		if (!ifs) {
			std::cout << "ファイルオープンに失敗" << std::endl;
			std::exit(1);
		}
		//EOFまで文字を読みだす
		while (!ifs.eof()) {
			char c;
			ifs.get(c);
			std::cout << c;
		}
		std::cout << std::flush;
	}
			  break;

	default:
		printf("違反命令");
		break;
	}
	return 0;
}