#include "Kayttoliittyma.h"

Kayttoliittyma::Kayttoliittyma(Asema* asema)
{
	_asema = asema;
}

void Kayttoliittyma::piirraLauta()
{
	const char sarakkeet[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	for (int i = 7; i >= -1; i--)
	{
		if (i > -1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN | BACKGROUND_BLUE);
			std::wcout << i;

			for (int j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					if (i % 2 == 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
							BACKGROUND_GREEN);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
							BACKGROUND_GREEN | BACKGROUND_BLUE);
					}
				}
				else
				{
					if ( i % 2 != 0 )
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
							BACKGROUND_GREEN);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
							BACKGROUND_GREEN | BACKGROUND_BLUE);
					}
				}
				//std::wcout << L'\u265F';

				if (_asema->lauta[i][j])
				{
					std::wcout << _asema->lauta[i][j]->getUnicode();
				}
				else
				{
					std::wcout << " ";
				}
			}
		}
		else
		{
			for ( int j = 0; j < 9; j++)
			{
				std::wcout << sarakkeet[ j ];
			}
		}

		std::wcout << '\n';
	}
}
