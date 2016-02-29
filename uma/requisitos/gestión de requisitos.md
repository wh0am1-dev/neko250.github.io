# gestión de requisitos

----

[Volver](index.html)

----

## gestión de cambios en los requisitos

los requisitos pueden cambiar antes de que el sistema esté terminado por múltiples motivos:

- __se descubre un requisito que se había olvidado__: puede ocurrir cuando un usuario esté trabajando con un sistema existente o cuando se pruebe una versión parcial
- __se detecta un defecto__: el arreglo de los errores detectados también se debe considerar como un nuevo requisito
- __se comprueba que se ha malentendido una necesidad__: es habitual que el cliente descubra cuando se le enseñe el sistema que el desarrollador no había entendido bien el requisito o que lo que había pedido el cliente no era en realidad lo que necesitaba
- __políticas de empresa__: si hay varios participantes, es posible que los equilibrios de poder en la empresa varíen y que las prioridades de los participantes cambien, y con ellos los requisitos que desean del sistema
- __el mercado cambia__: puede ocurrir que salga un nuevo producto de la competencia con características que se deban igualar o superar
- __cambia la legislación__: la nueva legislación puede cambiar los procedimientos de trabajo o añadir o cambiar requisitos

la gestión de cambios tiene como objetivo mantener los cambios bajo control

en cada una de las fases de desarrollo, hay una serie de actividades que hacer en el ámbito de la gestión de requisitos

como resultado de la fase de captura de requisitos se obtiene un documento que recopila los requisitos acordados con el cliente, que representan la funcionalidad básica del sistema; aunque se producirán cambios, este documento sirve de orientación para evitar derivar la atención a aspectos alejados de los requisitos iniciales o cambios innecesarios

cuando se produzca un cambio en un requisito o se detecte un error, los elementos de cada fase creados como consecuencia de la implementación de un requisito pueden verse afectados y es fundamental poder encontrar esos elementos relacionados; se debe poder trazar las consecuencias de la implementación de cada requisito en todas las fases del sistema; la traza también incluye información sobre quién generó el requisito, porqué se incluyó o sus relaciones con otros requisitos

para conseguir una buena trazabilidad es necesario, en primer lugar, tener identificado de manera única todos los requisitos con un identificador que permita acceder a él desde todas las fases del desarrollo; también hace falta definir una política de traza que incluya qué información de traza se va a incluir por cada requisito y cómo se va a representar; existen en el mercado herramientas de gestión de requisitos que incluyen la posibilidad de guardar y manejar la información de traza, relacionando los requisitos entre sí y con elementos de fases posteriores del desarrollo

asimismo, es recomendable definir políticas de trabajo para la gestión de requisitos; las políticas informan da los miembros de desarrollo de lo que se espera que hagan, pero sin detallar cómo tienen que hacerlo; la política de gestión de requisitos puede incluir los objetivos de esa gestón, los documentos que se deben usar, las normas para describir los requisitos, la política de cambios, la política de revisión y validación, la política de trazabilidad o criterios sobre cuándo pueden ignorarse esas políticas; la política de gestión de los cambios en los requisitos definiría cuál es el proceso a la hora de definir, informar, evaluar, aprobar, abordar y validar los cambios que van surgiendo en los requisitos

algunos tipos de requisitos deben manejarse por separado por su naturaleza; p0or un lado, los requisitos que afectan al sistema de manera global suelen ser más difícil de cambiar porque afectan a múltiples partes del sistema; tenerlos identificados de manera temprana permite prestar atención desde un  principio a su análisis y verificación para reducir la posibilidad de que cambie debido a una mala interpretación o a un olvido; también es conveniente distinguir los requisitos más volátilies, es decir, aquellos que tienen más probabilidad de cambiar; si fuera posible, estos requisitos se deberían implementar en subsistemas con un acoplamiento muy bajo con el resto del sistema para reducir las modificaiones en el sistema debido a cambios en esos requisitos

aunque el control de los cambios se puede definir como la tarea fundamental de la gestión de requisitos, existen otras, como el seguimiento del cumplimiento de los requisitos, en términos de plazos o costes; si un requisito se está retrasando demasiado, hay que evaluar si es realista, o considerar si se puede eliminar o reducir si no es una característica fundamental del sistema

la gestón de los requisitos no acaba con la implantación del sistema; la retroalimentación que se produce durante el uso de una versión servirá como información adicional para identificar y evaluar los requisitos de la siguiente versión o de productos similares

![](http://i.imgur.com/W7h6akv.png)

## gestión de peticiones

cuando un participante solicite un cambio en los requisitos, ya sea un requisito nuevo o una modificación sobre un requisito ya existente, se debe hacer una gestión adecuada de la petición para asegurar que se atiende adecuadamente, que se entiende su alcance y sus consecuencias y que integra bien con el resto del sistema

las peticiones de cambios deben registrarse en un documento que contenga la suficiente información como para que el equipo de desarrollo pueda construirla finalmente

una posible plantilla es:

| petición de cliente; fecha: [...]; proyecto: [...]; cliente final: [...]      |
|-------------------------------------------------------------------------------|
| solicitante: [...]; nombre: [...]; responsabilidad en el proyecto: [...]      |
| ámbito (para qué parte del sistema se solicita el nuevo requisito ?)          |
| descripción (describir de un modo preciso en qué consiste el nuevo requisito) |
| causa de la petición (qué beneficio se obtiene con esta característica ?)     |
| criterio de aceptación (criterio de verificación / testeo)                    |

## trazabilidad de requisitos

la *trazabilidad de requisitos* es una de las acciones de la gestión de los requisitos; se puede definir como la habilidad para describir y seguir la vida de un requisito, tanto hacia adelante como hacia atrás, idealmente a lo largo de todo el ciclo de vida; se puede establecer una analogía entre la utilidad de la trazabilidad de los requisitos y la trazabilidad en otras actividades económicas, como por ejemplo la alimentación; en el caso de grandes aplicaciones es de suma importancia en la fase de mantenimiento

esta trazabilidad de los requisitos se puede conseguir asociando información relacionada como:

- los requisitos con los componentes del sistema que se encargan de satisfacer esos requisitos; entre esos componentes están las clases, tablas de la base de datos, elementos de interfaz de usuario, etc. que implementan el requisito
- los objetivos del sistema y los requisitos derivados de esos objetivos
- las propuestas de cambios y los requisitos a los que afectan esos cambios
- las decisiones y los motivos y supuestos en los que se basan esos cambios
- los requisitos y los casos de prueba que sirven para validar esos requisitos
- los componentes del sistema y los recursos necesarios para implementar esos requisitos

### utilidad de la trazabilidad de requisitos

la trazabilidad de requisitos tiene diferentes usos a lo largo del desarrollo de un sistema software; por ejemplo, cuando se produce un cambio en un requisito, el hecho de saber a qué elementos del sistema afecta el requisito que se va a cambiar permite un análisis de impacto más rápido y preciso

la trazabilidad también permite conocer los motivos por los que un cierto objeto ha sido creado, modificado y evolucionado; esto permite justificar decisiones y compromisos a lo largo del desarrollo y es una fuente valiosa de información para mejorar el proceso de producción

la trazabilidad también permite asegurar que todos los requisitos están cubiertos por los componentes del sistema y que no se ha añadido ninguna función no pedida por el cliente; los resultados prácticos muestran una relación directa entre una buena gestión de la trazabilidad y la consecución de resultados de calidad, reduciento los costes de mantenimiento de los sistemas

por ejemplo: trsa un tiempo de uso de una aplicación web, el cliente decide que algunos aspectos del interfaz de usuario, como por ejemplo cómo se escoge los posibles valores para pagar una compra, no son cómodos para el cliente, y propone cambiarlo; antes de hacer el cambio, hay que estudiar si el requisito que originó ese elemento del interfaz de usuario se compatible o no con la nueva solicitud del usuario; para encontrar fácilmente ese requisito de origen es necesario mantener una buena trazabilidad entre el requisito y los elementos de interfaz que lo han implementado

### tipos de trazabilidad de requisitos

la trazabilidad de requisitos se puede dividir en dos grandes tipos, en base al momento en el que se hace y los elementos que se relacionan con los requisitos, la *pre-trazabilidad* y la *post-trazabilidad*

la *pre-trazabilidad* se refiere a aquellos aspectos de la vida del requisito antes de que el requisito se añada a la especificación de requisitos y se centra en permitir una mejor comprensión de los requisitos; la *pre-trazabilidad* incluye trazar la obtención y la definición de los requisitos; se busca relacionar los requisitos con su origen, que puede ser variado; un requisito puede provenir de una necesidad de una parte interesada, o puede venir impuesto por una regla de negocio o por algún tipo de documentación, como una norma técnica o una ley; también ser incluiría en esta parte la relación entre un requisito y los requisitos más detallados en que se descompone un requisito de alto nivel; esta parte de la trazabilidad intenta facilitar el descubrimiento de los requisitos que se verán afectados cuando haya un cambio en las reglas del negocio, en las políticas de la organización o en el uso del sistema

la *post-trazabilidad* se refiere a los aspectos de la vida de un requisito desde el momento en el que ha sido incluido en la especificación de requisitos; se centra en facilitar el estudio y la validación del sistema que se contruye; la *post-trazabilidad* intenta asegurar que se contruyen todos los requisitos, relacionando los requisitos con los elementos de los sucesivos modelos (análisis, diseño, implementación) y con los componentes del sistema que se encargan de llevar a cabo ese requisito; también debe incluir la relación con los casos de prueba, que sirven para probar y validar la correción de la implementación frente a los requisitos; la *post-trazabilidad* ayuda a mejorar el análisis del impacto de un cambio en un requisito porque se puede saber mejor a qué elementos del sistema va a afectar

otro aspecto importante de la trazabilidad es mantener la información sobre las diferentes versiones en un mismo requisito, cuáles han sido los cambios, quién los ha pedido, los motivos, los elementos que se han visto afectados, etc.

![](http://i.imgur.com/Sws8ygm.png)

### matriz de trazabilidad

una de las herramientas que se usan para documentar la trazabilidad son las *matrices de trazabilidad*, en las que se relacionan los requisitos con otros elementos del desarrollo

un ejemplo habitual es una matriz de requisitos en cuyas filas estén los requisitos funcionales y en cuyas columnas estén los casos de prueba que sirven para validar los requisitos

![](http://i.imgur.com/jvJYF9U.png)

## técnicas de gestión de requisitos ágiles

### el proceso de gestión de cambios ágil

los métodos ágiles usan estrategias flexibles para ajustarse a los cambios en los requisitos, que pueden ser muy frecuentes; la idea de las metodologías ágiles es que para ofrecer al cliente un producto de calidad, el sistema final tiene que tener en cuenta todos los cambios en las necesidades del cliente que se peoduzcan durante el desarrollo del sistema

se parte de la suposición de que es posible que no haya suficiente tiempo para implementar todos los requisitos planteados por el cliente; para lograr que el cliente consiga un producto de mayor valor en el caso de que no se consigan implementar todos los requisitos se implementarán primero los de mayor prioridad

![](http://i.imgur.com/s9n2Q9o.png)

la estrategia *Disciplined Agile Delivery* (__DAD__) usa un registro donde se guardan todas las actividades que el equipo de desarrollo tiene que llevar a cabo; en el caso de __SCRUM__, ese registro se llama *registro del producto* y contiene una lista de requisitos funcionales ordenados por prioridad; en __DAD__ no sólo se consideran requisitos funcionales, sino cualquier otro trabajo que tenga que llevar a cabo el equipo de desarrollo (cursos de formación, vacaciones, revisiones del trabajo de compañeros, etc.); con esa estrategia, el equipo dispone de una lista de actividades, priorizadas y estimadas, que tienen que ser abordadas, incluyendo los requisitos del sistema; los participantes son los responsables de la priorización y los desarrolladores son los responsables de las estimaciones; las prioridades de los requisitos no funcionales o bien se negocian entre los participantes y los desarrolladores o bien se planifican para periodos de poca actividad

al principio de cada iteración, el equipo de desarrollo cogerá la actividad de más alta prioridad del registro que crean que pueden implementar durante esa iteración, trabajará conjuntamente con el cliente para desarrollarlas y al final de la interación mostrará a los clientes el resultado del trabajo

###### se congelan los requisitos durante las iteraciones ?

__SCRUM__ no permite el cambio de requisitos durante una iteración; si se quiere cambiar un requisito que se está implementando, hay que esperar a la siguiente iteración y tratar la modificación como un nuevo requisito; por su parte, __XP__ y __DAD__ sí permiten el cambio de requisitos durante las iteraciones; en ese caso, es posible que haya que postergar algunos de los requisitos de la iteración actual a la siguiente

### priorización de requisitos

los nuevos requisitos, incluyendo los defectos encontrados en las pruebas por los usuarios, son priorizados por los participantes y añadidos al registro en el lugar adecuado; los participantes tienen el derecho a definir nuevos requisitos, cambiar de opinión sobre requisitos existentes e incluso cambiar la prioridad de los requisitos si lo ven adecuado; sin embargo, los participantes tienen la responsabilidad de tomar decisiones y proporcionar información con suficiente antelación

es importante que sea una única persona la responsable de la priorización de los requisitos; en __SCRUM__ es el *product owner*, que actúa de representante de todos los participantes; en algunos proyectos, esa responsabilidad puede tenerla un analista de negocio

### estimación de requisitos

los desarrolladores son los responsables de la estimación del esfuerzo requerido para implementar los requisitos en los que se trabaje; la estimación es una tarea que se mejora con la práctica, y es más fácil estimar tareas de complejidad baja, por lo que se intenta dividir los requisitos funcionales en tareas suficientemente sencillas como para que se puedan hacer en una sola iteración de pocas semanas

### riesgos de esta estrategia

algunas de las críticas que se hacen sobre la gestión iterativa o ágil de los requisitos son:

- no está claro al principio cuál será el coste total del proyecto
- los participantes tienen que actuar responsablemente y tomar decisiones y proporcionar información con suficiente tiempo
- los participantes pueden priorizar los requisitos de tal forma que se retrasen requisitos que afectan de manera significativa a la arquitectura del sistema
- aún siguiendo esta estrategia, es necesario un poco de modelado inicial

----

[Volver](index.html)

----
