# cloud computing

modelo que permite el acceso bajo demanda y de forma ubicua a un *pool* compartido de recursos computacionales configurables, que pueden ser adquiridos y liberados rápidamente con mínimo esfuerzo e interacción con el proveedor del servicio

## recursos

- computación
  - servidores, equilibrado de carga, procesador, os, ram...
- almacenamiento
  - capacidad, filesystem, dbs...
- red
  - ips, bandwidth, firewall...
- apps
  - software básido, de desarrollo...
- servicios

## características

- autoservicio bajo demanda
  - el consumidor adquiere recursos según sus necesidades
  - sin interacción humana con el proveedor
- acceso en la red
  - los recursos están disponibles en la red
  - son accesibles desde plataformas heterogéneas
- pool de recursos
  - para servir a múltiples consumidores al mismo tiempo
  - el consumidor no tiene control de su localización exacta
- elasticidad
  - los recursos se adquieren y liberan de forma elástica
  - escalando automáticamente de acuerdo a la demanda
  - para el consumidor aparecen como ilimitados
- uso medible
  - se monitoriza, controla y optimiza el uso de los recursos
  - proceso transparente tanto para el consumidor como para el proveedor
  - permite un mecanismo de pago por uso

## cloud vs outsourcing y hosting

en ambos existe una cuota fija preestablecida

### outsourcing (externalización)

- una organización externaliza sus procesos o servicios IT en un proveedor, a menudo offshore
- el proveedor se encarga de la compra y mantenimiento de HS y SW y de gestionar los datos del cliente

### hosting (alojamiento)

- una organización compra o alquila un servidor
- compartido, dedicado o gestionado
- despliega sus apps
- capacidades computacionales limitadas

## tipos de clouds

- cloud privado
  - operado por una única organización para uso propio
- cloud comunitario
  - compartido por varias organizaciones con intereses similares
- cloud público
  - ofrecido por un proveedor al público general
- cloud híbrido
  - combinación de dos o más clouds
- cloud heterogéneo
  - formado por diversos tipos de servidores
- cloud distribuido
  - formado por servidores distribuidos geográficamente

## modelos de servicio

- iaas: infrastructure as a service
- paas: platform as a service
- saas: software as a service
- xaas: anything as a service
  - faas: function as a service
  - staas: storage as a service
  - dbaas: database as a service
  - caas: communication as a service
  - naas: network as a service
  - maas: monitoring as a service
  - bpaas: business processes as a service
  - peaas: people as a service (duh... :ok_hand:)

### iaas

ofrece servicios básicos de:

- máquinas virtuales
- control y equilibrado de carga, autoescalado (hipervisor)
- almacenamiento en disco, bloques u objetos
- direccionamiento ip, firewall
- software básico preinstalado...

> amazon ec2, google compute engine, microsoft azure, at&t, hp, oracle, ibm, eucalyptus, cloudstack, openstack...

### paas

ofrece servicios básicos de:

- entorno cloud para desarrollar y ejecutar aplicaciones web
- transparencia en la gestión de los recursos básicos iaas:
  - máquinas virtuales, escalado y replicación, equilibrio de carga...
- recursos predefinidos ya instalados y configurados
  - lenguajes de programación, bibliotecas, apis, dbs...

> google app engine, microsoft azure websites, heroku, cloud foundry...

### serverless computing

- modelo de computación en la nube guiado por eventos
  - nanoservicios que implementan una operación concreta
- abstrae todo lo relacionado con los servidores
  - vm, escalado, equilibrado de carga...
  - próximo al nivel de abstraccion paas
- function as a service
  - pago por milisegundos de uso (frente a horas de iaas)

> amazon lambda, google cloud functions, azure functions...

### software as a service

- aplicaciones o servicios web
- se ejecutan en la plataforma del proveedor
- destinados a usuarios finales
- accesibles también a través de una api

> salesforce, zoho, google, microsoft, dropbox, prezi, wikia, youtube, flickr, ig, spotify, whatsapp...

## fortalezas y oportunidades

- eficiencia
  - optimiza el uso de los recursos disponibles
  - reduce costes medioambientales
  - reduce el tiempo de llegada al mercado
- economía de escala
  - soluciones asequibles
  - reduce drásticamente la inversión inicial
  - ajusta dinámicamente el coste al uso de los recursos

las tecnologías cloud son una alternativa atractiva a los centros de datos de empresa y resultan muy adecuadas para startups

## debilidades y amenazas

- seguridad
  - pérdida de control sobre datos sensibles
  - aspectos legales de protección de datos personales
- volatilidad
  - tecnologías y mercado aún jóvenes e inestables
  - cualquier proveedor puede desaparecer a corto o medio plazo
  - o cambiar significativamente sus políticas de negocio y facturación
- heterogeneidad
  - numerosos proveedores
  - sistemas propietarios
  - falta de estándares

las tecnologías cloud pueden ser causa de morir de éxito y presentan serios problemas de vendor lock-in

### vendor lock-in

- dependencia de un cliente respecto a los productos y servicios ofrecidos por su proveedor con elevados costes para cambiar de proveedor
- fragmenta el mercado y dificulta la libre competencia
- en sistemas cloud la oferta de recursos similares no está estandarizada
- el vendor lock-in dificulta
  - portabilidad
  - interoperabilidad
  - migración
