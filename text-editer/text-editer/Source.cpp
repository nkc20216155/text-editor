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
	//�o�b�t�@�T�C�Y����o��
	size = info.dwSize.X * info.dwSize.Y;

	printf("���ߓ���->w:�V�K�쐬 e:�t�@�C���ǂݏo��");
	scanf_s("%c", &c);

	switch (c) {
	case 'w': {
		//�V�K�t�@�C���쐬
		std::fstream writing_file;
		std::string filename = "sample.txt";
		writing_file.open(filename,  std::ios::app);

			printf("����->");
			scanf_s("%s", &buffer, sizeof(size));
			writing_file << buffer << std::endl;
			std::cout << std::flush;

		writing_file.close();
	}
			  break;

	case 'e': {
		//�t�@�C���ǂݏo��
		std::ifstream ifs("sample.txt");
		if (!ifs) {
			std::cout << "�t�@�C���I�[�v���Ɏ��s" << std::endl;
			std::exit(1);
		}
		//EOF�܂ŕ�����ǂ݂���
		while (!ifs.eof()) {
			char c;
			ifs.get(c);
			std::cout << c;
		}
		std::cout << std::flush;
	}
			  break;

	default:
		printf("�ᔽ����");
		break;
	}
	return 0;
}