# bases de datos: simulacro dml

## pregunta 1

> obtenga el nombre de cada asignatura junto con el nombre y apellidos del alumno más joven matriculado en ella. no muestre información duplicada

```sql
SELECT asig.nombre, al.nombre, al.apellido1, al.apellido2
FROM asignatura asig
JOIN matricula mat ON asig.codigo = mat.asignatura
JOIN alumno al ON mat.alumno = al.dni
WHERE (mat.asignatura, al.fecha_nacimiento) IN (
  SELECT mat.asignatura, max(al.fecha_nacimiento)
  FROM matricula mat
  JOIN alumno al ON mat.alumno = al.dni
  GROUP BY mat.asignatura
);
```

## pregunta 2

> obtenga nombre y número de créditos de las asignaturas que no son impartidas por profesores con menos de 50 años

```sql
SELECT asig.nombre, asig.creditos
FROM asignatura asig
JOIN impartir imp ON asig.codigo = imp.asignatura
WHERE imp.profesor NOT IN (
  SELECT id
  FROM profesor
  WHERE MONTHS_BETWEEN(SYSDATE, fecha_nacimiento) / 12 < 50
);
```

## pregunta 3

> obtenga el nombre y 2 apellidos de los profesores de los módulos 1 y 3 junto con el nombre de la asignatura que imparten y el número de créditos que tiene dicha asignatura (use el atributo `creditos` de la tabla `asignatura`). el módulo es el primer caracter del atributo `despacho` (utilice `substr`). si un profesor no imparte ninguna asignatura, también debe aparecer en el listado con el valor `0` en el campo `creditos`

```sql
SELECT prof.nombre, prof.apellido1, prof.apellido2, asig.nombre, nvl(asig.creditos, 0)
FROM profesor prof
JOIN impartir imp ON prof.id = imp.profesor
LEFT OUTER JOIN asignatura asig ON imp.asignatura = asig.codigo # why this left-fucking-outer join ?
WHERE SUBSTR(prof.despacho, 1, 1) IN ('1', '3');
```

## pregunta 4

> obtener la nota media de todos los alumnos que no nacieron en fin de semana, redondeando a 2 decimales. para calcular la nota media use `decode` y considere `AP = 1`, `NT = 2`, `SB = 3` y `MH = 4`. no sume los suspensos ni los no presentados

```sql
SELECT al.nombre, al.apellido1, al.apellido2, ROUND(AVG(DECODE(mat.calificacion, 'AP', 1, 'NT', 2, 'SB', 3, 'MH', 4)), 2) nota
FROM matricular mat
JOIN alumno al ON mat.alumno = al.dni
WHERE mat.calificacion IN ('AP', 'NT', 'SB', 'MH')
  AND TO_CHAR(al.fecha_nacimiento, 'day') NOT LIKE 'sabado%'
  AND TO_CHAR(al.fecha_nacimiento, 'day') NOT LIKE 'domingo%'
GROUP BY al.nombre, al.apellido1, al.apellido2;
```

## pregunta 5

> muestre el nombre y apellidos de alumnos de la misma población y provincia que estén matriculados en más de 3 asignaturas en común en el mismo curso

```sql
SELECT al1.nombre, al1.apellido1, al1.apellido2, al2.nombre, al2.apellido1, al2.apellido2
FROM alumno al1, alumno al2
WHERE al1.dni < al2.dni
  AND al1.cpro = al2.cpro
  AND al1.cmun = al2.cmun
  AND (
    SELECT COUNT(DISTINCT mat1.asignatura)
    FROM matricula mat1, matricula mat2
    WHERE mat1.alumno = al1.dni
      AND mat2.alumno = al2.dni
      AND mat1.curso = mat2.curso
      AND mat1.asignatura = mat2.asignatura
  ) > 3;
```
