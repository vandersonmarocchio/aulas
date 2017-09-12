%% lista(+X) is semidet
%
% Verdadeiro se X  ́e uma lista.
lista(vazia).
lista(cons(_, B)) :- lista(B).
