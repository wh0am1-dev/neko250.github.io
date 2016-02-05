# clases

----

[Volver](index.html)

----

# _objetivo_

- el objetivo principal de este modelo es la representación de los aspectos __estáticos__ del sistema, utilizando diversos mecanismos de abstracción (clasificación, generalización, agregación)
- es más estable y más fácil de entender que los modelos dinámicos
- su objetivo práctico es identificar clases, relaciones, atributos y operaciones

# _descripción_

- recoge las clases de objetos y sus asociaciones
- presenta la estructura de cada uno de los objetos del sistema y sus relaciones con los demás objetos
- no refleja los comportamientos temporales de las clases
- se pueden jerarquizar mediante paquetes (donde cada uno de ellos agrupa un conjunto de clases)

# _elementos_

## clases

- las clases agrupan o abstraen __objetos__ con atributos, relaciones y operaciones __comunes__ y con la misma semántica y comportamiento
- los objetos son instancias de las clases

observaciones:

- las clases se pueden usar para capturar el dominio del problema
- las clases pueden representar cosas que son software, hardware o conceptuales (abstracciones del dominio del problema)
- las clases se relacionan entre sí según el uso que se le quiera dar al sistema y el comportamiento que se espera de él
- el nombre de una clase de be ser único, sustantivo o expresión nominal

## atributos

- un atributo es una propiedad de una clase, compartida por todos sus objetos, identificada por un nombre, que describe un rango de valores que pueden tomar las instancias de la propiedad
- los atributos de una clase representan los datos asociados a los objetos instanciados por es clase
- los atributos son valores puros de datos, pero sin identidad
- el conjunto de los valores de los atributos determina el estado de un objeto
- cada atributo tiene un nombre único en su clase, sustantivo o expresión nominal
- pueden ser *base* o *derivados* (dependientes de atributos base)

## operaciones

- implementación de un servicio que puede ser requerido a cualquier objeto de la clase para que muestre un comportamiento
- las operaciones representan el comportamiento de los objetos de una clase, y caracterizan a ese objeto

observaciones:

- las operaciones pueden modificar los datos de un objeto
- el nombre (único en su clase) debe ser un verbo o expresión verbal

## notación de clase

- una clase de representa como una caja, separada en tres zonas por líneas horizontales
- en la zona superior se muestra el nombre de la clase y propiedades generales como el estereotipo
- si la clase es abstracta se representa en cursiva
- la zona central contiene una lista de atributos, uno en cada línea, con el formato:

~~~
// visibilidad nombre : tipo = valor_inicial propiedades
habitacionOcupada : boolean = false
~~~

- en la zona inferior se incluye una lista con las operaciones que proporciona la clase, con el formato:

~~~
// nombre : tipo = valor_por_defecto
modificarDireccion(nuevaDireccion : String)
~~~

![](http://i.imgur.com/PmIRmLm.png)

## relaciones

- una relación es una conexión entre elementos
- tipos:
	- asociaciones
	- dependencias
	- generalizaciones

### asociación

- relación estructural que especifica que los objetos de un elemento están conectados con los objetos de otro
- conjunto de enlaces
- un enlace es una instancia de una asociación

![](http://i.imgur.com/c9rgi2x.png)

observaciones:

- se plantean navegables en los dos sentidos, pero el nombre establece el sentido en que se recorre
- pueden ser binarias, ternarias o n-arias
- existen también asociaciones reflexivas
- las relaciones tienen __multiplicidad__: especifica cuántas instancias de una clase están asociadas a una instancia de la otra clase
- a cada clase participante en una asociación se le puede asignar un rol: un rol es la cara que la clase de un extremo de la asociación presenta a la clase del otro extremo
- los roles son necesarios en asociaciones entre objetos pertenecientes a la misma clase

notación:

- una relación de asociación se representa como una línea continua entre las clases asociadas
- la relación puede tener, junto a la línea:
	- un nombre que define la semántica o naturaleza de la asociación:
		- el nombre suele corresponder con expresiones verbales presentes en las especificaciones
		- el nombre no suele ser necesario si se indican los roles
	- rol: cada clase que participa en una asociación tiene un rol en ella
- multiplicidad:
	- la letra *n* y el símbolo *\** representan cualquier número
	- exactamente uno: *1*
	- cero o uno: *0..1*
	- muchos: *0..\**
	- uno o más: *1..\**
	- un número exacto: se especifica
	- combinaciones: por ejemplo: *0..1, 3..4, 6..\** (cualquier número excepto 2 y 5)
- navegabilidad
	- una flecha en el extremo de la línea, indicando el sentido de la navegación

### agregación

- es un caso particular de la asociación, con la semántica *todo-parte*
- representa una relación *tiene-un*

notación:

- se representa con un rombo hueco en la clase cuya instancia es una agregación de las instancias de la otra

### composición

- es un tipo muy representativo de una agregación
- cada componente de una composición puede pertenecer sólo a un todo
- el símbolo es también un rombo, pero está relleno

### dependencia

- representa que un elemento utiliza a otro
- indica que una clase requiere de otra para proporcionar alguno de sus servicios
- un cambio en la especificación de un elemento puede afectar a otro elemento que la utiliza, pero no necesariamente a la inversa

notación:

- una flecha discontinua dirigida al elemento del cual se depende

### generalización o herencia

- es una relación entre un elemento general (llamado *superclase* o *padre*) y un caso más específico de ese elemento (llamado *subclase* o *hijo*)
- una relación de herencia indica que una subclase comparte la estructura o el comportamiento definido en una superclase
- es una relación *es-un* entre clases
- los objetos hijo se pueden emplear en cualquier lugar en el que pueda aparecer el padre, pero no a la inversa (el hijo puede sustituir al padre)
- una clase hija hereda los atributos y operaciones de la clase padre; además:
	- el hijo puede añadir atributos y operaciones propias
	- una operación del hijo con la misma signatura que una del padre redefine la operación del padre (polimorfismo); una redefinición de un atributo o una operación nunca debe cambiar la semántica

notación:

- se representa como una línea continua con una flecha hueca en el extremo que apunta a la superclase

observaciones:

- __clase raíz__: sin padres y con hijos
- __clase hoja__: sin hijos
- __herencia simple__: un solo padre
- __herencia múltiple__: más de un padre; los conflictos en la herencia múltiple deben resolverse explícitamente (en el modelo) siempre que sea posible
- __clases abstractas__: aquellas que no son instanciables directamente, sólo lo son sus descendientes; su función es agrupar las características comunes a varias clases

### paquetes y dependencias

- los paquetes se usan apra dividir el modelo de clases del sistema de información agrupando clases u otros paquetes
- los paquetes se representan mediante un icono con forma de carpeta
- las dependencias entre paquetes se definen a partir de las relaciones establecidas entre los distintos elementos que se agrupan en ellos
- las dependencias se representan con flechas discontinuas entre los paquetes dependientes

# _técnicas de modelado_

en general, para cada diagrama:

- darle un nombre que comunique su propósito
- minimizar los curces de líneas
- lo cercano semánticamente debe estar cerca físicamente
- no mostrar demasiados tipos de relaciones
- en sistemas grandes, usar diagramas jerárquicos

### fuentes

- definición del problema
- expertos del dominio de la aplicación; confrontar el modelo

### tareas

- identificar clases y asociaciones (estructura global)
- añadir atributos
- organizar usando herencia (simplificar)
- añadir operaciones (durante el modelado de comportamiento)

### identificar clases

- se buscan candidatos en:
	- la definición del problema
	- conocimiento del dominio del problema
	- durante el diseño e implementación
- debe tener sentido en el dominio:
	- entidades físicas
	- conceptos

### recomendaciones

- buscar sustantivos
- no preocuparse por la herencia
- centrarse en las clases

## seleccionar las clases correctas

### criterios de selección

- __clases redundantes__: seleccionar el nombre más descriptivo
- __clases irrelevantes__: sin relación con el problema
- __clases con límites mal definidos o ámbito excesivo__
- __atributos__: nombres que definen propiedades
- __operaciones__: nombres que definen acciones o secuencias de acciones
- __roles__: el nombre de la clase debe reflejar la naturaleza intrínseca y no el papel de una asociación
- __estructuras de implementación__: extrañas al mundo real, no entran en el modelo de análisis

### seleccionar las asociaciones correctas

criterios de eliminación:

- asociaciones entre clases eliminadas
- asociaciones irrelevantes (fuera del dominio) o de implementación (estructuras de implementación)
- acciones: las asociaciones son propiedades estructurales o relacinoes permanentes, no sucesos transitorios
- asociaciones ternarias: descomponer en binarias o cualificar o incluir atributos de enlace (si una de las clases no tiene características propias)
- asociaciones derivadas:
	- definibles en términos de otras relaciones, o en términos de atributos
	- los atributos, asociaciones... deben representar información independiente
	- pueden ser útiles en el diseño

### especificación detallada de las asociaciones

- nombres significativos
- añadir roles cuando sea necesario
- añadir las multiplicidades conocidas
- revisar en busca de asociaciones "*perdidas*"

# _etc, etc, etc... etc._

> paso

----

[Volver](index.html)

----
