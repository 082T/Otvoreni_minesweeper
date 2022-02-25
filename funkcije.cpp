#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <thread>
#include <windows.h>
#include <ctype.h>
#include <set>

#include"funkcije.h"



bool mycomparison::operator() (const std::pair<int, std::vector<std::vector<char>>>& m1, const std::pair<int, std::vector<std::vector<char>>>& m2)
{
	return m1.first > m2.first;
}

std::vector<std::pair<std::pair<int, int>, int>> get_codes_example1()
{
	return { { {0,6},2 } , { {0,8},2 } , { {1,1},0 } , { {1,2},1 } , { {1,5},3 } , { {1,6},4 },
	{ {1,8},3 } , { {2,1},0 } , { {2,3},1 } , { {2,8},4 } , { {3,4},1 } , { {3,9},2 } , { {4,0},2 },
	{ {4,7},3 } , { {4,8},2 } , { {5,2},4 } , { {5,6},2 } , { {5,7},3 } , { {6,0},2 } , { {6,3},0 },
	{ {7,0},2 } , { {7,3},2 } , { {7,4},1 } , { {7,6},3 } , { {7,7},4 } , { {7,8},4 } , { {8,7},3 },
	{ {9,1},2 } , { {9,2},1 } , { {9,3},2 } , { {9,6},3 } , { {9,8},2 } };
}

std::vector<std::pair<std::pair<int, int>, int>> get_codes_example2()
{
	return { { {1,0},0 } , { {1,2},1 } , { {1,4},1 } , { {1,7},1 } , { {1,8},2 } , { {1,9},1 },
	{ {2,0},0 } , { {2,3},2 } , { {2,5},1 } , { {2,7},0 } , { {2,9},1 } , { {3,5},1 } , { {3,6},2 },
	{ {3,8},3 } , { {4,0},1 } , { {4,3},3 } , { {5,4},1 } , { {5,5},3 } , { {5,7},3 } , { {5,9},1 },
	{ {6,0},2 } , { {6,2},2 } , { {7,4},3 } , { {7,6},3 } , { {7,7},2 } , { {8,0},2 } , { {8,4},6 },
	{ {8,7},3 } , { {8,9},1 } , { {9,1},0 } , { {9,6},4 } };
}

int prebroji(std::vector<std::vector<char>> matrix)
{
	int koliko = 0;
	for (std::vector<std::vector<char>>::iterator i1 = matrix.begin(); i1 != matrix.end(); i1++)
	{
		for (std::vector<char>::iterator i2 = i1->begin(); i2 != i1->end(); i2++)
		{
			if ((*i2) > '0' && (*i2) < '9')
			{
				koliko += (*i2) - '0';
			}
		}
	}
	return koliko;
}

int prebroji_zlato(std::vector<std::vector<char>> matrix)
{
	int koliko = 0;
	for (std::vector<std::vector<char>>::iterator i1 = matrix.begin(); i1 != matrix.end(); i1++)
	{
		for (std::vector<char>::iterator i2 = i1->begin(); i2 != i1->end(); i2++)
		{
			if ((*i2) == 'G') koliko++;
		}
	}
	return koliko;
}

int bfs_ili_dfs_ili_greedy()
{
	std::cout << "Za BFS upisite 1," << std::endl << "za DFS upisite 2, " << std::endl << "Za greedyBFS upisite 3: ";
	int answer;
	std::cin >> answer;
	return answer;
}

int example_test()
{
	std::cout << "Za testni primjer-a upisite 1,"
		<< std::endl
		<< "za testni primjer-b upisite 2,"
		<< std::endl
		<< "za rucni upis upisite 3: ";
	int a;
	std::cin >> a;
	return a;
}

int visualizion_test()
{
	std::cout << "Ako zelite vizualizaiju, upisite 1,"
		<< std::endl
		<< "ako ne zelite vizualizaciju, upisite 2: ";
	int a;
	std::cin >> a;
	return a;
}

void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;  //SetColor(0-256),247=normal
}

std::vector<std::pair<int, int>> dobi_okolo(std::vector<std::vector<char>> mat_v1, int i, int j, std::pair<int, int> rc)
{
	std::vector<std::pair<int, int>> parovi;
	if (i > 0 && j > 0) //gore lijevo
	{
		if (mat_v1[i - 1][j - 1] == '.') parovi.push_back({ i - 1,j - 1 });
	}
	if (i > 0) //gore
	{
		if (mat_v1[i-1][j] == '.') parovi.push_back({ i-1,j });
	}
	if (i > 0 && j < rc.second - 1) //gore desno
	{
		if (mat_v1[i - 1][j + 1] == '.') parovi.push_back({ i - 1,j + 1 });
	}
	if (j > 0) //lijevo
	{
		if (mat_v1[i][j-1] == '.') parovi.push_back({ i,j-1 });
	}
	if (j < rc.second - 1) //desno
	{
		if (mat_v1[i][j + 1] == '.') parovi.push_back({ i,j + 1 });
	}
	if (i < rc.first - 1 && j>0) //dolje lijevo
	{
		if (mat_v1[i + 1][j - 1] == '.') parovi.push_back({ i + 1,j - 1 });
	}
	if (i < rc.first - 1) //dolje
	{
		if (mat_v1[i+1][j] == '.') parovi.push_back({ i+1,j });
	}
	if (i < rc.first - 1 && j < rc.second - 1) //dolje desno
	{
		if (mat_v1[i+1][j+1] == '.') parovi.push_back({ i+1,j+1 });
	}

	return parovi;
}

int dots_ok(std::vector<std::vector<char>> matrix, std::pair<int,int> rc)
{
	for (int i = 0; i < rc.first; i++)
	{
		for (int j = 0; j < rc.second; j++)
		{
			if (matrix[i][j] > '0' && matrix[i][j] < '9')
			{
				int around = 0;
				
				if (i > 0) //gore
				{
					if (matrix[i - 1][j] == '.') around++;
				}
				if (i < rc.first-1) //dolje
				{
					if (matrix[i + 1][j] == '.') around++;
				}
				if (j > 0) //lijevo
				{
					if (matrix[i][j - 1] == '.') around++;
				}
				if (j < rc.second-1) //desno
				{
					if (matrix[i][j + 1] == '.') around++;
				}
				if (i > 0 && j > 0) //gore lijevo
				{
					if (matrix[i - 1][j - 1] == '.') around++;
				}
				if (i > 0 && j < rc.second - 1) //gore desno
				{
					if (matrix[i - 1][j + 1] == '.') around++;
				}
				if (i < rc.first - 1 && j > 0) //dolje lijevo
				{
					if (matrix[i + 1][j - 1] == '.') around++;
				}
				if (i < rc.first - 1 && j < rc.second - 1) //dolje desno
				{
					if (matrix[i + 1][j + 1] == '.') around++;
				}

				if (around < (matrix[i][j] - '0')) return 0;
			}
		}
	}

	return 1;
}

int dots_number(std::vector<std::vector<char>> matrix, std::pair<int,int> rc)
{
	int count = 0;
	for (int i = 0; i < rc.first; i++)
	{
		for (int j = 0; j < rc.second; j++)
		{
			if (matrix[i][j] == '.') count++;
		}
	}
	return count;
}

int isnotthere(std::vector<std::vector<char>> matrix, int i, int j, std::pair<int, int> rc)
{
	if (matrix[i][j] != '.') return 0;

	if (i > 0) 
	{
		if (matrix[i - 1][j] == '0') return 1;
	}
	if (i < rc.first - 1)
	{
		if (matrix[i + 1][j] == '0') return 1;
	}
	if (j > 0)
	{
		if (matrix[i][j - 1] == '0') return 1;
	}
	if (j < rc.second - 1)
	{
		if (matrix[i][j + 1] == '0') return 1;
	}
	if (i > 0 && j > 0)
	{
		if (matrix[i - 1][j - 1] == '0') return 1;
	}
	if (i > 0 && j < rc.second - 1)
	{
		if (matrix[i - 1][j + 1] == '0') return 1;
	}
	if (i < rc.first - 1 && j > 0)
	{
		if (matrix[i + 1][j - 1] == '0') return 1;
	}
	if (i < rc.first - 1 && j < rc.second - 1)
	{
		if (matrix[i + 1][j + 1] == '0') return 1;
	}
	//--------------------------------------------------------------------
	if (i > 0) 
	{
		if (matrix[i - 1][j] > '0' && matrix[i - 1][j] < '9') return 0;
	}
	if (i < rc.first - 1)
	{
		if (matrix[i + 1][j] > '0' && matrix[i + 1][j] < '9') return 0;
	}
	if (j > 0)
	{
		if (matrix[i][j - 1] > '0' && matrix[i][j - 1] < '9') return 0;
	}
	if (j < rc.second - 1)
	{
		if (matrix[i][j + 1] > '0' && matrix[i][j + 1] < '9') return 0;
	}
	if (i > 0 && j > 0)
	{
		if (matrix[i - 1][j - 1] > '0' && matrix[i - 1][j - 1] < '9') return 0;
	}
	if (i > 0 && j < rc.second-1)
	{
		if (matrix[i - 1][j + 1] > '0' && matrix[i - 1][j + 1] < '9') return 0;
	}
	if (i < rc.first - 1 && j > 0)
	{
		if (matrix[i + 1][j - 1] > '0' && matrix[i + 1][j - 1] < '9') return 0;
	}
	if (i < rc.first - 1 && j < rc.second - 1)
	{
		if (matrix[i + 1][j + 1] > '0' && matrix[i + 1][j + 1] < '9') return 0;
	}

	return 1;
}

std::pair<int,int> get_r_c()
{
	std::pair<int,int> rc;
	std::cout << "Broj redaka: ";
	std::cin >> rc.first;
	std::cout << "Broj stupaca: ";
	std::cin >> rc.second;

	return rc;
}

std::vector< std::pair <std::pair<int, int>, int> > get_codes(std::pair<int, int> rs)
{
	std::vector< std::pair <std::pair<int, int>, int> > kodovi;

	std::cout << "Upis parova, int int int (red,stupac,broj) (-1 bilogdje za kraj): " << std::endl;
	while (1)
	{
		std::pair <std::pair<int, int>, int> trojka;
		std::pair<int, int> koords;
		int num;
		
		std::cout << "->";
		std::cin >> koords.first;
		if (koords.first >= rs.first || koords.first <= -2)
		{
			std::cout << "error, row" << std::endl;
			continue;
		}
		if (koords.first == -1)
		{
			break;
		}
		std::cin >> koords.second;
		if (koords.second >= rs.second || koords.second <= -2)
		{
			std::cout << "error, column" << std::endl;
			continue;
		}
		if (koords.second == -1)
		{
			break;
		}
		trojka.first = koords;
		std::cin >> num;
		if (num <= -2)
		{
			std::cout << "error, number" << std::endl;
			continue;
		}
		if (num == -1) break;
		trojka.second = num;

		kodovi.push_back(trojka);
	}
	return kodovi;
}

void print_codes(std::vector<std::pair<std::pair<int, int>, int>> kodovi)
{
	for (std::vector<std::pair<std::pair<int, int>, int> >::iterator i = kodovi.begin(); i != kodovi.end(); i++)
	{
		std::cout << "(" << i->first.first << "," << i->first.second << ")" << " " << i->second << std::endl;
	}
}

std::vector<std::vector<char>> get_mat(std::pair<int, int> rc, std::vector<std::pair<std::pair<int, int>, int>> codes)
{
	std::vector<std::vector<char>> matrix;

	for (int i = 0; i < rc.first; i++)
	{
		std::vector<char> red;
		for (int j = 0; j < rc.second; j++)
		{
			red.push_back('.');
		}
		matrix.push_back(red);
	}
	for (std::vector<std::pair<std::pair<int, int>, int>>::iterator i = codes.begin(); i != codes.end(); i++)
	{
		matrix[i->first.first][i->first.second] = i->second+'0';
	}
	
	return matrix;
}

void print_mat(std::vector<std::vector<char>> matrix, std::pair<int,int> rc)
{
	for (int i = 0; i < rc.first; i++)
	{
		for (int t = 0; t < 4 * rc.second-1; t++)
			std::cout << "-";
		std::cout << std::endl;
		std::cout << "|";
		for (int j = 0; j < rc.second; j++)
		{
			if (matrix[i][j] == 'G')
			{
				SetColor(110);
				std::cout << matrix[i][j];
				SetColor(247);
			}
			else if (matrix[i][j] > '0' && matrix[i][j] < '9')
			{
				SetColor(204);
				std::cout << matrix[i][j];
				SetColor(247);
			}
			else if (matrix[i][j] == '*' || matrix[i][j] == '0')
			{
				SetColor(0);
				std::cout << matrix[i][j];
				SetColor(247);
			}
			else std::cout << matrix[i][j];
			
			if (j != rc.second - 1) std::cout << " | ";
		}
		std::cout << "|" << std::endl;
	}
	for (int t = 0; t < 4 * rc.second - 1; t++)
		std::cout << "-";
	std::cout << std::endl;
}

std::vector<std::vector<char>> sort_mat(std::vector<std::vector<char>> matrix, std::pair<int, int> rc)
{
	std::vector<std::vector<char> > matrix_sorted;
	matrix_sorted = matrix;
	for (int i = 0; i < rc.first; i++)
	{
		for (int j = 0; j < rc.second; j++)
		{
			if (isnotthere(matrix, i, j, rc) == 1)
			{
				matrix_sorted[i][j] = '*';
			}
			else matrix_sorted[i][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < rc.first; i++)
	{
		for (int j = 0; j < rc.second; j++)
		{
			if (matrix_sorted[i][j] == '0')
			{
				matrix_sorted[i][j] = '*';
			}
		}
	}
	return matrix_sorted;
}

std::vector<std::vector<char>> place_gold(std::vector<std::vector<char>> matrix, int i, int j, std::pair<int, int> rc)
{
	std::vector<std::vector<char>> mat_new = matrix;

	mat_new[i][j] = 'G';

	if (i > 0)
	{
		if (mat_new[i - 1][j] > '0' && mat_new[i - 1][j] < '9')
		{
			mat_new[i - 1][j] = mat_new[i - 1][j] - 1;
			if (mat_new[i - 1][j] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (i < rc.first - 1)
	{
		if (mat_new[i + 1][j] > '0' && mat_new[i + 1][j] < '9') 
		{
			mat_new[i + 1][j] = mat_new[i + 1][j] - 1;
			if (mat_new[i + 1][j] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (j > 0)
	{
		if (mat_new[i][j - 1] > '0' && mat_new[i][j - 1] < '9')
		{
			mat_new[i][j - 1] = mat_new[i][j - 1] - 1;
			if (mat_new[i][j - 1] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (j < rc.second - 1)
	{
		if (mat_new[i][j + 1] > '0' && mat_new[i][j + 1] < '9')
		{
			mat_new[i][j + 1] = mat_new[i][j + 1] - 1;
			if (mat_new[i][j + 1] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (i > 0 && j > 0)
	{
		if (mat_new[i - 1][j - 1] > '0' && mat_new[i - 1][j - 1] < '9')
		{
			mat_new[i - 1][j - 1] = mat_new[i - 1][j - 1] - 1;
			if (mat_new[i - 1][j - 1] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (i > 0 && j < rc.second - 1)
	{
		if (mat_new[i - 1][j + 1] > '0' && mat_new[i - 1][j + 1] < '9')
		{
			mat_new[i - 1][j + 1] = mat_new[i - 1][j + 1] - 1;
			if (mat_new[i - 1][j + 1] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (i < rc.first - 1 && j > 0)
	{
		if (mat_new[i + 1][j - 1] > '0' && mat_new[i + 1][j - 1] < '9')
		{
			mat_new[i + 1][j - 1] = mat_new[i + 1][j - 1] - 1;
			if (mat_new[i + 1][j - 1] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	if (i < rc.first - 1 && j < rc.second - 1)
	{
		if (mat_new[i + 1][j + 1] > '0' && mat_new[i + 1][j + 1] < '9')
		{
			mat_new[i + 1][j + 1] = mat_new[i + 1][j + 1] - 1;
			if (mat_new[i + 1][j + 1] == '0') mat_new = sort_mat(mat_new, rc);
		}
	}
	return mat_new;
}

std::vector<std::vector<char>> bfs(std::vector<std::vector<char>> matrix_sorted, std::pair<int, int> rc, int* koraci_o, int* koraci_p, int visualize)
{
	std::queue< std::vector<std::vector<char>>> open;
	std::vector<std::vector<char>> mat_v1,mat_v2;

	open.push(matrix_sorted);

	while (!open.empty())
	{
		mat_v1 = open.front();
		open.pop();

		*koraci_o = *koraci_o + 1;
		// 1. nacrtaj 
		if (visualize == 1)
		{
			system("cls");
			print_mat(mat_v1, rc);
			std::cout << "Na koraku: " << *koraci_o << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		// 2. provjeri ako je gotovo
		if (dots_number(mat_v1, rc) == 0 && prebroji(mat_v1) == 0)
		{
			return mat_v1;
		}
		// 3. nadi prvi broj u matrici
		int ii=0, jj=0;
		int t = 0;
		for (int i = 0; i < rc.first; i++)
		{
			for (int j = 0; j < rc.second; j++)
			{
				if (mat_v1[i][j] > '0' && mat_v1[i][j] < '9')
				{
					ii = i;
					jj = j;
					t = 1;
					break;
				}
			}
			if (t == 1) break;
		}
		// 4. stavi zlato okolo i stavi u queue
		std::vector<std::pair<int, int>> okolo = dobi_okolo(mat_v1, ii, jj, rc);
		for (std::vector < std::pair<int, int>>::iterator it = okolo.begin(); it != okolo.end(); it++)
		{
			int i = it->first;
			int j = it->second;
			mat_v2 = place_gold(mat_v1, i, j, rc);
			int ok = dots_ok(mat_v2, rc);
			if (ok == 0) continue;
			*koraci_p = *koraci_p + 1;
			open.push(mat_v2);
		}
	}
	return std::vector<std::vector<char>>();
}

std::vector<std::vector<char>> dfs(std::vector<std::vector<char>> matrix_sorted, std::pair<int, int> rc, int* koraci_o, int* koraci_p, int visualize)
{
	std::stack< std::vector<std::vector<char>>> open;
	std::vector<std::vector<char>> mat_v1, mat_v2;

	open.push(matrix_sorted);

	while (!open.empty())
	{
		mat_v1 = open.top();
		open.pop();
		
		*koraci_o = *koraci_o + 1;		
		// 1. nacrtaj 
		if (visualize == 1)
		{
			system("cls");
			print_mat(mat_v1, rc);
			std::cout << "Na koraku: " << *koraci_o << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		// 2. provjeri ako je gotovo
		if (dots_number(mat_v1, rc) == 0 && prebroji(mat_v1) == 0)
		{
			return mat_v1;
		}
		// 3. nadi prvi broj u matrici
		int ii = 0, jj = 0;
		int t = 0;
		for (int i = 0; i < rc.first ; i++)
		{
			for (int j = 0; j < rc.second; j++)
			{
				if (mat_v1[i][j] > '0' && mat_v1[i][j] < '9')
				{
					ii = i;
					jj = j;
					t = 1;
					break;
				}
			}
			if (t == 1) break;
		}
		// 4. stavi zlato okolo i stavi u stack
		std::vector<std::pair<int, int>> okolo = dobi_okolo(mat_v1, ii, jj, rc);
		for (std::vector < std::pair<int, int>>::reverse_iterator it = okolo.rbegin(); it != okolo.rend(); it++)
		{
			int i = it->first;
			int j = it->second;
			mat_v2 = place_gold(mat_v1, i, j, rc);
			int ok = dots_ok(mat_v2, rc);
			if (ok == 0) continue;
			*koraci_p = *koraci_p + 1;
			open.push(mat_v2);
		}
	}
	return std::vector<std::vector<char>>();
}

std::vector<std::vector<char>> greedy(std::vector<std::vector<char>> matrix_sorted, std::pair<int, int> rc, int* koraci_o, int* koraci_p, int visualize)
{
	//priority queue parova (int, matrica) sortiran tako da je najmanji int prvi na redu
	std::priority_queue < std::pair<int, std::vector<std::vector<char>>>,
		                  std::vector < std::pair<int, std::vector<std::vector<char>>> >,
		                  mycomparison > prq;
	std::vector<std::vector<char>> mat_v1, mat_v2;

	std::set<std::vector<std::vector<char>>> closed;

	prq.push({ prebroji(matrix_sorted),matrix_sorted });

	while (!prq.empty())
	{
		mat_v1 = prq.top().second;
		prq.pop();

		closed.insert(mat_v1);
		*koraci_o = *koraci_o + 1;
		// 1. nacrtaj
		if (visualize == 1)
		{
			system("cls");
			print_mat(mat_v1, rc);
			std::cout << "Na koraku: " << *koraci_o << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		// 2. provjeri ako je gotovo
		if (dots_number(mat_v1, rc) == 0 && prebroji(mat_v1) == 0)
		{
			return mat_v1;
		}
		// 3. nadi prvi broj u matrici
		int ii = 0, jj = 0;
		int t = 0;
		for (int i = 0; i < rc.first; i++)
		{
			for (int j = 0; j < rc.second; j++)
			{
				if (mat_v1[i][j] > '0' && mat_v1[i][j] < '9')
				{
					ii = i;
					jj = j;
					t = 1;
					break;
				}
			}
			if (t == 1) break;
		}
		// 4. stavi zlato okolo i vrati u priority_queue
		std::vector<std::pair<int, int>> okolo = dobi_okolo(mat_v1, ii, jj, rc);
		for (std::vector < std::pair<int, int>>::iterator it = okolo.begin(); it != okolo.end(); it++)
		{
			int i = it->first;
			int j = it->second;
			mat_v2 = place_gold(mat_v1, i, j, rc);
			
			int ok = dots_ok(mat_v2, rc);
			if (ok == 0) continue;

			if (closed.find(mat_v2) != closed.end())
			{
				continue;
			}

			*koraci_p = *koraci_p + 1;
			prq.push({ prebroji(mat_v2),mat_v2 });
		}
	}
	return std::vector<std::vector<char>>();
}

void print_rjesenje(std::vector<std::vector<char>> matrix_solved, std::pair<int, int> rc, int koraci_o, int koraci_p)
{
	system("cls");
	print_mat(matrix_solved, rc);
	std::cout << "Broj otvorenih matrica: " << koraci_o << std::endl;
	std::cout << "Broj pohranjenih matrica: " << koraci_p << std::endl;
}








