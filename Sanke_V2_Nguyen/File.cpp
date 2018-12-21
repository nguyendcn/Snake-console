#include "File.h"

void permutation(SCORE &A, SCORE &B)
{
	SCORE temp = A;
	A = B;
	B = temp;
}
void arrange(vector<SCORE> &s)
{
	int size = s.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (s[i].score < s[j].score)
				permutation(s[i], s[j]);
		}
	}
}

void File(int hightScore)
{
	vector<Score> topScore;
	clrscr();
	ifstream FileIn("hightScore.in", ios::in); //Mở file hight score;
	if (FileIn.fail()) // Thất bại => lần đầu play;
	{
		SCORE s;
		ofstream FileOut("hightScore.in", ios::out); // Tạo mới file hight socre;
		do {
			cout << "Enter the name(length < 7): ";
			cin >> s.name;
			if (s.name.size() >= 7)
				clrscr();
		} while (s.name.size() >= 7);
		

		for (int i = 0; i < 5; i++) //Add vào file; 
		{
			if (i == 0)
				FileOut << s.name << " " << hightScore << endl;
			else
				FileOut << "Empty" << " " << "0" << endl; // Cho có đủ 5 hight score;
		}
		FileOut.close();

		return;
	}
	else
	{
		//Đọc file vào vector topScore
		while (!FileIn.eof())
		{
			SCORE s;
			FileIn >> s.name >> s.score;
			topScore.push_back(s);
		}
	}
	FileIn.close();

	//TH k phải play lần đầu;
	SCORE s;
	do {
		cout << "Enter the name(length < 7): ";
		cin >> s.name;
		if (s.name.size() >= 7)
			clrscr();
	} while (s.name.size() >= 7);
	s.score = hightScore;
	topScore.push_back(s);
	arrange(topScore); 
	
	//Ghi lại vào file sau khi sắp xếp;
	ofstream FileOut("hightScore.in", ios::out);
	FileOut.clear();

	int maxLength;
	if (topScore.size() < 5)
		maxLength = topScore.size();
	else
	    maxLength = 5; // Top 5 hight score;
	for (int i = 0; i < maxLength; i++)
	{
		FileOut << topScore[i].name << " " << topScore[i].score << " ";
	}
	FileOut.close();
}

void hightScore()
{
	string name; int score;

	ifstream FileIn("hightScore.in", ios::in);
	TextColor(5);
	gotoxy(33, 15); cout << "HIGHT SCORE:" << endl;

	if (FileIn.fail())
	{
		gotoxy(35, 17);    cout << "EMPTY." << endl;
	}
	else
	{
		int x = 0;
		int i = 17;
		while (x < 5)
		{
			FileIn >> name >> score;
			gotoxy(30, i = i + 1);   cout << name;
			gotoxy(45, i);   cout << score;
			x++;
		}
	}

	TextColor(7);

	mButton();
}

int getLowScore()
{
	vector<Score> topScore;

	ifstream FileIn("hightScore.in", ios::in);

	if (FileIn.fail()) // first play
	{
		return 0;
	}

	while (!FileIn.eof())
	{
		Score s;
		FileIn >> s.name >> s.score;
		topScore.push_back(s);
	}
	return topScore[topScore.size() - 1].score; //return low score.

	FileIn.close();
}
