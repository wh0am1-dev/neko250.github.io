# casos de uso

----

> [Volver](index.html)

----

# _objetivos_

- capturar los requisitos funcionales del sistema
- guiar el proceso de desarrollo
- proporcionar una herramienta de comunicación entre usuarios, analistas y diseñadores
- proporcionar una visión del sistema como "caja negra"
- constituir una especificación abstracta del sistema

# _descripción_

un diagrama de casos de uso es un grafo constituido por:

- actores
- casos de uso
- relaciones entre elementos

# _elementos_

## caso de uso

- especifica el comportamiento del sistema de información o de una parte de él según una manera específica de dar respuesta a los usuarios
- representación de un requisitos funcional del sistema
- describe el conjunto de secuencias de acciones (incluyendo variantes) que ejecuta el sistema para producir un resultado observable de interés para un actor
- conjunto de transacciones entre el sistema y los actores
- sirve para validar la arquitectura del sistema y verificar el sistema en desarrollo
- punto de partida para la generación de casos de prueba
- un caso de uso se representa gráficamente mediante una elipse. en su interior se incluye el nombre del caso de uso

### especificación de casos de uso

los niveles de especificación pueden ser:

- una descripción general
- establecimiento de pre- y post-condiciones
- __enumerar y describir los diferentes escenarios del caso de uso__
- casos de uso anidados (diagrama jerárquico)
- diagrama de estados

### escenario

- cada uno de los diferentes caminos que pueden darse en un caso de uso, dependiendo de las condiciones que se den en su realización
- flujo de eventos a través de una variante de un caso de uso
- secuencia específica de acciones que ilustra un comportamiento
- "instancia" de un caso de uso

### descripción de un escenario

- flujo básico de eventos:
	- cómo y cuándo empieza y acaba el caso de uso
	- cuándo interactúa con los actores y qué información se intercambian
- flujos alternativos de comportamiento

### ==caso práctico==

un programa de archivo electrónico puede emplearse para almacenar y recuperar documentos de texto

cualquier documento creado por un procesador de texto, un editor o por otros medios puede archivarse en el sistema de clasificación electrónica

los documentos pueden clasificarse en base a palabras clave, autores, y/o una descripción del documento o resumen que describa el documento

los documentos archivados en el sistema también pueden ser eliminados

----

para una rápida recuperación de los documentos almacenados se emplean índices

los documentos se pueden recuperar según esquemas adecuados que no se encuentran en las clasificaciones convencionales; por ejemplo, los usuarios pueden recuperar o localizar un documento según su contenido, descripción, autor o según palabras clave definidas por el usuario

por tanto, la descripción del documento, los autores, las palabras clave y/o el mismo texto del documento pueden ser objeto de búsqueda

----

un usuario puede especificar criterios de búsqueda, cuyo resultado sea una colección de documentos que cumplen dichos criterios

entonces, los documentos encontrados pueden ser vistos o impresos

al usuario se le da la posibilidad de especificar palabras "intrascendentes", que no serán buscadas ni indexadas, como, por ejemplo, *y, o, no, el, la, los, las, si, etc.*

el usuario puede especificar también qué caracteres alfanuméricos de un documento serán indexados o buscados (el conjunto de caracteres de clasificación), limitando de esta forma la búsqueda y los índices sólo a porciones de documentos

### ==caso práctico: escenarios==

escenario __normal__ del caso de uso __archivar un documento__:

1. el usuario quere archivar un documento
1. el usuario especifica la carpeta y el nombre del archivo del documento
1. el usuario introduce un resumen del documento, las palabras clave y/o el autor
1. el usuario solicita que se archive el documento
1. el documento es archivado

escenario de __excepción__ del caso de uso __archivar un documento__:

1. el usuario quiere archivar un documento
1. el usuario especifica la carpeta en la que está el documento
1. el usuario solicita que se archive el documento
1. el sistema muestra un mensaje de error y solicita al usuario que especifique el nombre del archivo del documento
1. el usuario cancela la operación

## actor

- un actor es algo o alguien que se encuentra fuera del sistema y que interactúa con él
- en general los actores son personas u otros sistemas
- un único actor puede representar a varios usuarios distintos, y un usuario puede actuar como diferentes actores; por ejemplo:
	- el actor `Cliente` representa a varias personas distintas
	- la persona `J. Pérez` puede actuar como el actor `Cliente` y como el actor `Director`
- un caso de uso tiene un efecto tangible para un actor determinado:
	- cálculo de un resultado
	- generación de un objeto
	- cambio de estado de un objeto
- un actor se representa gráficamente mediante un monigote con su nombre debajo

## paquete

- se emplean para la organización de diagramas
- se determina una partición del sistema y a cada una de las divisiones se le asocia un paquete en el que se incluyen los casos de uso correspondientes
- se representa gráficamente con una carpeta con el nombre en su interior

## relaciones

tipos de relaciones:

- relaciones entre actores y casos de uso
- relaciones entre casos de uso:
	- especialización
	- inclusión
	- extensión
- relaciones de especialización entre actores

### actor - caso de uso

- es una relación de __comunicación__
- representa comunicación en uno o dos sentidos (emisión y recepción)
- se representa gráficamente mediante una línea continua

![](http://i.imgur.com/RQ19zPf.png)

### actor - actor

- relación de __generalización__
- se pueden definir categorías generales de actres (por ejemplo `Cliente`) y especializarlos (por ejemplo `Cliente Preferencial`)
- esta relación se representa gráficamente mediante una flecha con la cabeza hueca dirigida al actor más general

![](http://i.imgur.com/qe7XbRn.png)

### generalización de casos de uso

- un caso de uso (*hijo*) hereda el comportamiento y el significado de otro caso de uso (*padre*)
- el caso de uso hijo puede añadir comportamiento o buen redefinir el del padre
- ejemplo: un caso de uso `Validar Usuario` puede tener como hijos los casos de uso `Comprobar Clave` y `Comprobar Firma`
- se representa gráficamente con una flecha hueca dirigida al caso de uso padre

![](http://i.imgur.com/G2A1hU9.png)

### inclusión de casos de uso

- representa un comportamiento común entre varios casos de uso:
	- un caso de uso base `A` incorpora explícitamente el comportamiento de otro caso de uso `B` en el lugar especificado en el caso de uso base
- gráficamente se representa mediante una flecha etiquetada con el estereotipo `<<usa>>` (o `<<includes>>`) que parte del caso de uso base

### ==caso práctico==

se presenta una relación de inlcusión entre los casos de uso:

- `Ver un Documento` y `Buscar un Documento`
- `Imprimir un Documento` y `Buscar un Documento`

![](http://i.imgur.com/zOGLEv0.png)

### ==caso práctico: escenarios==

escenario __normal__ del caso de uso `Ver un Documento` incluir(`Buscar un Documento`)

1. el usuario selecciona un documento entre los encontrados
1. el usuario requiere ver el documento
1. el sistema muestra el documento

escenario de __excepción__ del caso de uso `Ver un Documento` incluir(`Buscar un Documento`)

1. el usuario requiere ver el documento
1. el sistema muestra un mensaje de error indicando que debe seleccionar un documento
1. el usuario finaliza la petición

### extensión de casos de uso

- esta relación representa un comportamiento opcional de un caso de uso:
	- un caso de uso base `A` incorpora implícitamente el comportamiento de otro caso de uso `B` (en el lugar especificado en el primero)
- `A` es el comportamiento habitual del sistema y, dependiendo de alguna condición, tiene un comportamiento adicional o ligeramente diferente representado por `B`
- se representa gráficamente mediante una flecha etiquetada con el estereotipo `<<extiende>>` (o `<<extends>>`) que llega al caso de uso base
- el caso de uso base, por tanto, bajo ciertas condiciones incorpora el comportamiento de otro caso de uso en un punto concreto de su especificación denominado *punto de extensión*
- un caso de uso base puede tener varias relaciones de extensión y, en consecuencia, varios puntos de extensión

### ==caso práctico==

consideremos el caso de uso base `Hacer Pedido` con una relación de extensión con otro caso de uso `Hacer Pedido Urgente`

la especificación de un escenario normal sería:

1. el cliente solicita hacer un pedido
1. el usuario proporciona los datos del pedido
	1. (establecer prioridad)
1. procesar el pedido

![](http://i.imgur.com/XWtxuzP.png)

### ==ejemplo==

![](http://i.imgur.com/8CPK9gd.png)

# _técnicas comunes de modelado_

pasos para la elaboración de un diagrama de casos de uso:

1. identificar los actores que interactúan con el sistema
1. organizar los actores identificando tanto los roles generales como los especializados
1. considerar las formas más importantes que tiene cada actor de interactuar con el sistema
1. considerar las formas excepcionales en las que cada actor puede interactuar con el sistema
1. organizar los comportamientos como casos de uso, utilizando las relaciones de inclusión y extensión

hay dos formas de aplicar los diagramas de casos de uso:

1. __modelado del contexto de un sistema__:
	- se determina qué actores quedan fuera del sistema e interactúan con él
1. __modelado de los requisitos de un sistema__:
	- se especifica qué debe hacer el sistema, independientemente de cómo se haga
	- se especifica el comportamiento del sistema como una caja negra

## modelado del contexto

- se trata de diferenciar entre elementos del sistema y elementos externos al sistema:
	- los elementos del sistema desarrollan el comportamiento de éste
	- los elementos externos interactúan con el sistema
- el *contexto del sistema* se puede definir como los elementos externos que interactúan con el sistema

para modelar el contexto de un sistema:

1. identificar los actores en torno al sistema considerando:
	- qué grupos requieren del sistema para desarrollar sus tareas
	- qué grupos son necesarios para que el sistema desarrolle sus tareas
	- qué interacción tiene el sistema con hardware externo o con otros sistemas
	- qué grupos realizan tareas secundarias de administración y mantenimiento
1. organizar los actores similares en jerarquías de generalización/especialización
1. introducir los actores en el diagrama de casos de uso y especificar las vías de comunicación de cada actor con los casos de uso

## modelado de los requisitos

- un *requisito* se puede definir como una característica de diseño, propiedad o comportamiento de un sistema
- el establecimiento de los requisitos determina un contrato entre el sistema y sus elementos externos
- los requisitos funcionales se pueden expresar mediante casos de uso

para modelar los requisitos hay que seguir los siguientes pasos:

1. establecer el contexto del sistema, identificando los actores
1. considerar qué comportamiento del sistema espera cada actor
1. nombrar los comportamientos como casos de uso
1. factorizar el comportamiento común (relación de uso) en nuevos casos de uso y factorizar el comportamiento variante (relación de extensión) como nuevos casos de uso
1. modelar los casos de uso, actores y relaciones en diagramas de casos de uso

# _especificación de casos de uso_

### escenarios

- escenario principal (o de éxito)
- escenarios alternativos o de excepción (indicar la condición que determina la variación):
	- datos de entrada incorrectos
	- datos de entrada incompletos
	- imposibilidad de completar el caso de uso por vulnerar reglas de negocio
	- otras situaciones de excepción
- observaciones:
	- en el modelo de negocio no se deben tener en cuenta detalles de interfaz de usuario
	- en cada paso, se especifica una acción realizada por el actor o por el sistema
	- especificar claramente cómo se inicia el caso de uso

### pre-condiciones

- condiciones que se asumen para ejecutar el caso de uso
- ejemplo:
	- *el usuario debe tener acceso validado con el perfil de jefe de servicio*

### post-condiciones (o garantías)

__mínimas__:

- condición que se verificará en cualquier escenario del caso de uso
- ejemplo:
	- *en la auditoría de la aplicación quedará registrado el acceso a la validación de solicitudes de cambio de perfil*

__de éxito__:

- condición que se verificará en los escenarios de éxito
- ejemplo:
	- *el estado de la solicitud de cambio de perfil pasará a ser validado por el jefe de servicio*

### prioridad

- es esencial para la planificación del proyecto (y sus iteraciones o incrementos)
- los posibles valores varían en cada organización (alta, media, baja)

----

[Volver](index.html)

----
