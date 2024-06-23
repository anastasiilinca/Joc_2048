Joc 2048 - Scurta descriere a programului

Biblioteca folosita pentru interfata grafica: ncurses

Descriere generala: 

Programul de fata reprezinta o simulare a celebrului joc 2048, caruia i
s-au adaugat cateva functionalitati noi:
- afisarea ultimei mutari efectuate
- se ofera jucatorului 3 indicii pe care le poate folosi oricand in joc
(indiciu = efectuarea automata a celei mai optime mutari)
- afisarea punctajului adus de ultima mutare
- afisarea punctajului obtinut la castigarea jocului
- celulele sunt colorate pentru o mai buna vizualizare a tablei de joc

Jocul prezinta un meniu care poate fi accesat si in timpul jocului, acesta
putand fi continuat prin optiunea Resume
Celulele pot fi mutate cu ajutorul tastelor directionale.
Meniul poate fi reaccesat prin apasarea tastei 'q'.
Indiciile pot fi cerute prin apasarea tastei 'h'.

1. FUNCTII (continute in fisierele header "functions.h" si "functions.c")

1.1. menu() - creeaza un meniu de comenzi
1.2. play() - efectueaza jocul in sine
1.3. rand_strt() - genereaza pozitii random pentru celulele de start
1.4. print_color() - coloreaza celulele
1.5. game_won() - verifica daca jucatorul a castigat
1.6. game_over() - verifica daca jucatorul a pierdut
1.7. auto_play() - efectueaza cea mai favorabila miscare automat
1.8. add_token() - adauga o celula noua
1.9. merge() - efectueaza unirea celulelor
1.10. new_game() - seteaza tabla grafica de joc + matricea asociata
1.11. valid_moves() - verifica in ce driectii se po efectua mutari valide
in fiecare moment al jocului

2. MAIN

Contine:
-initializarea ecranului
-initializarea culorilor
-initializarea meniului si implicit a jocului
