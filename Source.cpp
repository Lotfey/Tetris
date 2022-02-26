# include<iostream>
# include<Windows.h>



std::wstring tetromino[7];

// Variables
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* pField = nullptr;

// Consol screen 
int nScreenWidth = 80;  // size X (columns)
int nScreenHeight =30; // size Y (rows)




// Rotating tetris peices

int rotate(int px, int py, int r)
{
	switch (r%4)

	{
	default: std::cout << "there is no input" << std::endl;
		break;

	case 0: return py * 4 + px;				// 90  degrees
	case 1: return 12 + py * -(px * 4);		// 180 degrees
	case 2: return 15- (py * 4) - px;		// 270 degrees
	case 4: return 3 - py * +(px * 4);		// 270 degrees
	}
	return 0;
}


// this main code creat a tetris game

int main()

{
	// create assetes: 7 tetris shapes 

	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");

	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L".X.");
	tetromino[1].append(L"....");

	tetromino[2].append(L".X..");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"...");

	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");
	 

	// craete play field buffer
	pField = new unsigned char[nFieldHeight * nFieldWidth];

	// Board boundary 
	for (int x = 0; x < nFieldWidth; ++x)
		for (int y = 0; y < nFieldHeight; ++y)
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 ||
										   y == 0 || y == nFieldHeight - 1)
										? 9 : 0;
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; ++i) screen[i] = L' ';

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	bool bGameOver = false;
	while (!bGameOver)
	{
		// Draw gaming field

		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];

		// Display frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}





	return 0;
}
