# JUnit

- JUnit es un marco de trabajo para escribir pruebas de unidad
- Desarrollado por Erich Gamma y Kent Beck
- Nor permite:
	- Definir y ejecutar test y grupos de tests (test suite)
	- Utilizar las pruebas como una forma efectiva de especificación
	- Apoyo a la refactorización
	- Integrar código revisado en nuestro ejecutables
- Disponible en diferentes IDEs (eclipse, JavaBeans, JBuilder...)
- Información disponible en [junit.org](junit.org)
- JUnit 3 y 4

## Terminología

- __test runner__: software que ejecuta las pruebas e informa sobre los resultados
- __test suite__: colección de casos de prueba
- __test case__: prueba que comprueba la respuesta de un método ante una entrada
- __unit test__: prueba de la unidad mínima de código que se puede probar, típicamente una clase
- __test fixture__: situación o entorno en el que se realiza una prueba
- __integration test__: prueba de cómo de bien las clases interaccionan (soporte limitado)
- __mock objects__: versiones falsas de otras clases con las que interacciona la clase siendo probada (soporte nulo)

## Estructura de las clases de prueba JUnit

- `@BeforeClass public static void setUpBeforeClass()`
- `@AfterClass public static void tearDownAfterClass()`
- `@Before public void setUp()`
	- Crea una situación (test fixture) creando e inicializando objetos
- `@After public void tearDown()`
- `@Test public void test()`
- `@Test(timeout = 1000) public void test()`
- `@Test(expected = RuntimeException.class) public void test()`
	- Métodos de prueba

## Asertos

- Podemos utilizar asertos en cualquier programa Java para establecer condiciones que han de satisfacerse
- Si no se cumple la condición del aserto se lanza una excepción `AssertionFailedError`
	- JUnit captura estos errores, recopila los resultados de los tests y los muestra

### Asertos disponibles

- `static void assertTrue(boolean test)`
- `static void assertTrue(String msg, boolean test)`
	- Comprueba que la condición se satisfaga
	- El mensaje se incluye en el error
- `static void assertFalse([String msg,] boolean test)`
- `static void assertEquals([String msg,] Object expected, Object actual)`
- `static void assertSame([String msg,] Object expected, Object actual)`
- `static void assertNotNull([String msg,] Object object)`
- `static void assertNotSame([String msg,] Object unexpected, Object actual)`
- `static void assertNull([String msg,] Object object)`
- `static void fail([String msg])`

## Cuando creamos tests

- Frecuentemente el tamaño de las pruebas es mucho mayor que el código de la aplicación.. aunque más repetitivo
- Probar código complejo puede ser complejo... y las pruebas pueden ser complejas también
- Cuanto mayor sea el tiempo que dediquemos a hacer buenas pruebas menor será el tiempo de desarrollo
- A menudo las pruebas nos ayudan a aclarar el comportamiento de los métodos

## Sentencia assert

- Dos sentencias disponibles:
	- `assert boolean_condition;`
	- `assert boolean_condition : error_message;`
- No reemplaza el lanzamiento de excepciones
- Aplicaciones finales no deben lanzar `AssertionFailedError`

## Cuestiones a tener en cuenta

- Puede ser complicado probar objetos que estados complicados, porque puede requerir muchos métodos hasta alcanza el estado deseado
	- Escribimos largos tests con montones de mensajes
	- Facilitamos el acceso a la estructura para poder analizar mejor el estado
	- Añadimos formas de inicialización con los estados que necesitamos
- Las salidas pueden ser complicadas de capturar
- JUnit no nos ayuda con las GUIs
- El uso de JUnit moldea nuestro SW para que sea más testeable

## Conclusiones

- Otros frameworks para pruebas de unidad:
	- xUnit, testNG...
	- FIT (*Framework for Integrated Test*) [http://fit.c2.com](http://fit.c2.com)
		- Comunicación entre desarrolladores y usuarios mediante tablas HTML
		- FitNesse
