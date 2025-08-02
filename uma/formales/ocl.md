# ocl

[index](https://carlos-aguilar.com/neko250.github.io/uma/formales/index.html)

## febrero 2014

### 2

porque devuelve una colección compuesta por los valores del atributo de la clase que contiene el `set` original y pueden estar duplicados si ninguna restricción lo prohibe

```
class Persona
attributes
  fecha-nacimiento: Integer
end
```

una clase `Persona` tiene un atributo `fecha-nacimiento`, al ejecutar `Persona.allInstances().collect(fecha-nacimiento)`, puede darse que dos personas hayan nacido en el mismo día, ergo dup-dup

### 2

devuelve una colección con todas las instancias existentes de la clase sobre la que se llama al método

```
Persona.allInstances(): Set(Persona)
```

no se puede usar sobre clases con infinitas instancias

### 3

```
class Fiesta
operations
  algunMenor() : Boolean
end

class Persona
attributes
  edad : Integer
end

association VaA between
  Fiesta[*]
  Persona[1..*] role publico
end

context Fiesta::algunMenor() : Boolean
  body: publico.iterate(p; acc : Boolean = false | acc or p.edad < 18)
```

## septiembre 2014

### 1

- en una baraja debe haber exactamente 13 naipes cuyo palo sea corazon

```
composition BaN between
  Baraja[1]
  Naipe[*] role naipes
end

context Baraja
  inv: naipes->select(palo = Palo::corazon)->size() = 13
```

### 2

- los naipes de la mano de un jugador no pueden coincidir ni con los que están en la mano de la banca ni con los que están en la mano de otro jugador

```
aggregation JaJ between
  Juego[*] role juegos
  Jugador[*] role jugadores
end

association JaM between
  Jugador[1]
  Naipe[2] role mano
end

context Juego
  inv: Juego.allInstances()->forAll(j : Juego |
    j.jugadores->forAll(j1, j2 : Jugador |
      j1 <> j2 implies j1.mano->excludesAll(j2.mano)))
```

### 3

- cada ronda tiene que tener los mismos naipes de la anterior más uno nuevo

```
aggregation JaR between
  Juego[1]
  Ronda[1..3] ordered role rondas
end

context Juego
  inv: Juego.allInstances()->forAll(j : Juego |
    (j.rondas->iterate(r; acc : Integer = 0 |
      acc + r.manoBanca->size())) = (j.rondas->first().manoBanca->size() * 3 + 3))
```

### 4

- definir apostar

```
context Ronda::apostar(j : Jugador, cantidad : Integer)
  pre: cantidad >= self.apuesta and cantidad <= j.bote
  post: j.bote = j.bote@pre - cantidad and self.apuesta = self.apuesta@pre + cantidad
```

### 5

- las manos de la banca y los jugadores devueltas por `Juego::manos()` son diferentes

```
context Juego::manos() : Set(Set(Naipe))
  post: result->forAll(s1, s2 : Set(Naipe) | s1 <> s2 implies s1.excludesAll(s2))
```

[index](https://carlos-aguilar.com/neko250.github.io/uma/formales/index.html)
