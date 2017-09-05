/* ex 2.1
homem(albert).
homem(edward).
mulher(alice).
mulher(victoria).
% o primeiro argumento  ́e o(a) filho(a),
% o segundo argumento a m ̃ae e o terceiro o pai
pais(edward, victoria, albert).
pais(alice, victoria, albert).
irma_de(X, Y) :-
mulher(X),
pais(X, M, F),
pais(Y, M, F).
*/

/* ex 2.2
bruxo(rony).
bruxo(X) :- temVassoura(X), temVarinha(X).
temVarinha(harry).
jogadorQuadribol(harry).
temVassoura(X) :- jogadorQuadribol(X).
*/

/* ex 2.3
likes(sam,Food) :- indian(Food), mild(Food).
likes(sam,Food) :- chinese(Food).
likes(sam,Food) :- italian(Food).
likes(sam,chips).
indian(curry).
indian(dahl).
indian(tandoori).
indian(kurma).
mild(dahl).

mild(tandoori).
mild(kurma).
chinese(chow_mein).
chinese(chop_suey).
chinese(sweet_and_sour).
italian(pizza).
italian(spaghetti).
*/

/* ex 2.4
a) true
b) false
c) true
d) true
e) false
f) false
g) true
h) true
i) true
j) true
k) false
l) true
m) true
n) true
*/

/* ex 2.5
mulher(vincent).
mulher(mia).
homem(jules).
pessoa(X) :- homem(X); mulher(X).
ama(X, Y) :- pai(X, Y).
pai(Y, Z) :- homem(Y), filho(Z, Y).
pai(Y, Z) :- homem(Y), filha(Z, Y).
*/

/* 2.6
pai(adao, abel).
pai(adao, caim).
pai(adao, sete).
pai(caim, enoque).
pai(enoque, irad).
pai(irad, meujael).
pai(meujael, metusael).
pai(metusael, lameque).
pai(lameque, jabal).
pai(lameque, jubal).

pai(lameque, tubalcaim).
pai(lameque, naama).
mae(eva, abel).
mae(eva, caim).
mae(eva, sete).
mae(ada, jabal).
mae(ada, jubal).
mae(zila, tubalcaim).
mae(zila, naama).
homem(sete).
homem(caim).
homem(jabal).
homem(jubal).
homem(tubalcaim).
mulher(naama).

homem(X) :- pai(X, Y).
mulher(X) :- mae(X, Y).
irmao(X, Y) :-
  pai(A, X),
  pai(A, Y),
  mae(B, X),
  mae(B, Y).
casados(X,Y) :-
  pai(X,A),
  mae(Y,A).
avo(X,Y) :-
  pai(X,A),
  pai(A,Y).
irma_de(X,Y) :-
  mulher(X),
  pai(A, X),
  mae(B, X),
  pai(A, Y),
  mae(B, Y).
irmao_de(X,Y) :-
  homem(X),
  pai(A, X),
  mae(B, X),
  pai(A, Y),
  mae(B, Y).
e_pai(X) :- pai(X, Y).
e_mae(X) :- mae(X, Y).
e_filho(X) :-
  pai(Y, X),
  mae(A, X).
ancestral(X,Y) :-
  pai(X, Y);
  mae(X, Y);
  ancestral(A,Y).
*/

triangulo(A, B ,C, T) :-
  A = B;
  B = C;
  A = C;
  T = 'equilatero'.


triangulo(A, B ,C, T) :-
    A \= B;
    B = C;
    A \= C;
    T = 'isosceles'.
