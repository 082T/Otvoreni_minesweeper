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



int main()
{

	std::pair<int, int> rc;
	std::vector< std::pair <std::pair<int, int>, int> > codes;
	std::vector<std::vector<char> > matrix, matrix_sorted, matrix_solved;


	//upis podataka

	int question = example_test();

	switch (question) {
	case 1:
		rc = { 10,10 };
		codes = get_codes_example1();
		break;
	case 2:
		rc = { 10,10 };
		codes = get_codes_example2();
		break;
	case 3:
		rc = get_r_c();
		codes = get_codes(rc);
		break;
	}

	int visualization = visualizion_test();
	int koji_algoritam = bfs_ili_dfs_ili_greedy();

	system("cls");


	//kraj upisa i pocetak algoritma
	
	matrix = get_mat(rc, codes);
	matrix_sorted = sort_mat(matrix, rc);
	if (visualization == 2)
	{
		print_mat(matrix_sorted, rc);
		std::cout << std::endl;
	}

	int koraci_o = 0;
	int koraci_p = 0;
	switch (koji_algoritam) {
	case 1:
		matrix_solved = bfs(matrix_sorted, rc, &koraci_o, &koraci_p, visualization);
		break;
	case 2:
		matrix_solved = dfs(matrix_sorted, rc, &koraci_o, &koraci_p, visualization);
		break;
	case 3:
		matrix_solved = greedy(matrix_sorted, rc, &koraci_o, &koraci_p, visualization);
		break;
	}

	//kraj algoritma i ispis
	
	if (matrix_solved == std::vector<std::vector<char>>())
	{
		system("cls");
		std::cout << "Nema rjesenja";
		std::cout << std::endl;
	}
	else print_rjesenje(matrix_solved, rc, koraci_o, koraci_p);
	 

	


	return 0;
}