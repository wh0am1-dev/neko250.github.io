# alloy

[index](https://carlos-aguilar.com/neko250.github.io/uma/formales/index.html)

## febrero 2014

- cada objeto está en una y sólo una caja
- alguna caja sólo contiene objetos rojos
- una caja contiene todos los rombos
- todos los rombos son verdes
- no hay cuadrados amarillos

```
abstract sig Color {}
one sig Rojo, Verde, Amarillo extends Color {}

abstract sig Objeto {
  color: one Color
}

sig Triangulo, Cuadrado, Rombo extends Objeto {}

sig Caja {
  contiene: Objeto set -> one Tiempo
}

sig Tiempo {}

fact {
  o: Objeto | #contiene.o = 1
}

fact {
  some c: Caja | c.contiene.color in Rojo
}

fact {
  #contiene.Rombo = 1
}

fact {
  all r: Rombo | r.color in Verde
}

fact {
  no c: Cuadrado | c.color in Amarillo
}

pred anadir(c:Caja, o:Objeto, t,t':Tiempo) {
  contiene = contiene + (c -> (c.contiene.t + o) -> t')
}
```

## septiembre 2014

- hay exactamente 5 figuras y 20 naipes
- todos los naipes son diferentes
- para cada juego, las manos de dos jugadores distintos de ese juego no tienen cartas en común
- juego: 3 jugadores con 2 naipes cada uno y una casa con 3 naipes

```
abstract sig Palo, Figura {}

one sig Comodin, As, J, Q, K extends Figura {}

one sig Corazon, Pica, Diamante, Trebol extends Palo {}

sig Naipe {
  palo: Palo
  fig: Figura
}

sig Jugador {
  mano: set Naipe
}

sig Casa {
  visibles: Naipe set -> one Tiempo
}

sig Juego {
  jug: set Jugador
  casa: one Casa
}

sig Tiempo {}

fact {
  #Figura = 5
  #Naipe = 20
}

fact {
  all disj n, n' : Naipe | no n = n'
  all disj n, n' : Naipe | no (n.palo = n'.palo and n.figura = n'.figura)
}

fact {
  all jue : Juego, all disj j, j' : Jugador | (j in jue.jug and j' in jue.jug) and (j.mano != j'.mano)
}

fact {
  all jue : Juego, all c : Casa, all j : Jugador all t : Tiempo | (j in jue.jug and c in jue.casa) and (not j.mano in c.visibles.t) 
}

pred awanga(j: Juego) {
  #j.jug = 3
  #j.jug.mano = 2
  #j.casa = 1
  #j.casa.visibles = 3
}

pred unaCartaMas(j : Juego, t, t' : Tiempo, n : Naipe) {
  j.casa.visibles = j.casa.visibles + ((j.casa.visibles.t + n) -> t')
}
```

[index](https://carlos-aguilar.com/neko250.github.io/uma/formales/index.html)
