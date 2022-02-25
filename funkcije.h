#pragma once

#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <set>

//usporedba elemenata za priority_queue
class mycomparison
	{
	public:
		bool operator() (const std::pair<int, std::vector<std::vector<char>>>& m1, const std::pair<int, std::vector<std::vector<char>>>& m2);
	};

//vraca koordinate i brojeve na njima za (a) primjer iz zadatka
std::vector< std::pair <std::pair<int, int>, int> > get_codes_example1();

//vraca koordinate i brojeve na njima za (b) primjer iz zadatka
std::vector< std::pair <std::pair<int, int>, int> > get_codes_example2();

//prima matricu
//vraca zbroj svih brojeva u matrici
int prebroji(std::vector<std::vector<char>> matrix);

//prima matricu
//vraca zbroj svih zlata u matrici
int prebroji_zlato(std::vector<std::vector<char>> matrix);

//upit za odabir algoritma
int bfs_ili_dfs_ili_greedy();

//upit za testni primjer
int example_test();

//upit za vizualizaciju
int visualizion_test();

//prima int, mjenja "int" boju teksta
void SetColor(int ForgC);

//prima matricu, i, j, par brojeva (retci,stupci)
//vraca parove koordinati oko i,j koji imaju '.', tojest na koje je moguce postaviti zlato
std::vector<std::pair<int, int>> dobi_okolo(std::vector<std::vector<char>> mat_v1, int i, int j, std::pair<int,int> rc);

//prima matricu, par brojeva (retci,stupci)
//vraca 0 ako oko nekog broja u matrici nema dovoljno '.', tojest nema dovoljno mogucnosti za staviti zlato, u protivnom vraca 1
int dots_ok(std::vector<std::vector<char> > matrix, std::pair<int,int> rc);

//prima matricu i par brojeva (retci, stupci)
//vraca zbroj tocaka u matrici
int dots_number(std::vector<std::vector<char> > matrix, std::pair<int, int> rc);

//prima matricu, indekse i,j, par brojeva (retci, stupci)
//ako je 0 oko pozicije (i,j); vraca 1, 
//ako je drugi broj oko pozicije (i,j) i nema 0; vraca 0
int isnotthere(std::vector< std::vector<char> > matrix, int i, int j, std::pair<int, int> rc);

//upit za broj redaka i stupaca u matrici
//vraca: par (retci,stupci)
std::pair<int,int> get_r_c();

//upit za upis parova koordinata i brojeva koji se nalaze na njima
//vraca: par(par(redak,stupac), broj)
std::vector< std::pair <std::pair<int, int>, int> > get_codes(std::pair<int, int> rs);

//(za testiranje) prima: par(par(redak,stupac), broj)
//ispisuje ga u obliku (a,b) c
void print_codes(std::vector< std::pair <std::pair<int, int>, int> > kodovi);

//prima par brojeva (retci,stupci) i par(par(redak,stupac),broj) koordinata i brojke koja se na njima nalazi
//vraca popunjenu matricu s navedenim brojevima
std::vector< std::vector<char> > get_mat(std::pair<int, int> rc, std::vector< std::pair <std::pair<int, int>, int> > codes);

//prima matricu i par brojeva (retci, stupci)
//ispisuje matricu
void print_mat(std::vector<std::vector<char> > matrix, std::pair<int,int> rc);

//prima matricu i par brojeva (retci,stupci)
//vraca matricu popunjenu '*' tamo gdje zlato ne moze biti
std::vector< std::vector<char> > sort_mat(std::vector< std::vector<char> > matrix, std::pair<int, int> rc);

//prima matricu, indekse i,j, par brojeva (retci, stupci)
//stavlja zlato na poziciju i,j, smanjuje okolne brojeve za 1, poziva funkciju sort_mat u slucaju da se '1' smanjio na '0'
//vraca novonastalu matricu
std::vector<std::vector<char>> place_gold(std::vector<std::vector<char>> matrix, int i, int j, std::pair<int, int> rc);

//BFS algoritam:
//prima matricu, par brojeva (retci,stupci), koraci=0 (koji se svakom iteracijom algoritma povecavaju za 1), visualize=(1 ili 2, sadrzi rezultat pocetnog upita o vizualizaciji algoritma) 
//povecava korake tijekom izvodenja algoritma
//vraca matricu rjesenja
std::vector<std::vector<char> > bfs(std::vector<std::vector<char> > matrix_sorted, std::pair<int, int> rc, int *koraci_o, int* koraci_p, int visualize);

//DFS algoritam, analogno kao BFS, samo koristi stack umjesto queue
std::vector<std::vector<char> > dfs(std::vector<std::vector<char> > matrix_sorted, std::pair<int, int> rc, int* koraci_o, int* koraci_p, int visualize);

//greedy algoritam, analogno kao BFS, samo koristi priority_queue umjesto queue
//pamti matrice koje smo prosli u closed setu
//priority_queue stavlja na prvo mjesto matricu koja je najblize rjesenju, tojest kojoj je zbroj brojeva najmanji
//povecava korake tijekom izvodenja algoritma
//vraca matricu rjesenja
std::vector<std::vector<char>> greedy(std::vector<std::vector<char>> matrix_sorted, std::pair<int, int> rc, int* koraci_o, int* koraci_p, int visualize);

//prima matricu, broj (retci,stupci), broj koraka
//ocisti ekran, ispisuje matricu i broj koraka
void print_rjesenje(std::vector<std::vector<char> >matrix_solved, std::pair<int,int> rc, int koraci_o, int koraci_p);


