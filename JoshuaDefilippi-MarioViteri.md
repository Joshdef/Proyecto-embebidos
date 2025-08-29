1)  **Introducción**

La distribución automática de alimentos del camarón en estanques
acuícolas busca diseñar y construir una tolva alimentadora automática.
Para ello, el sistema cuenta con un tornillo sinfín y un motor de
corriente continua, el cual dosifica la comida en la medida requerida,
entregando un suministro preciso. El sistema es capaz de activar el
tornillo con control local vía LoRa, mientras que el monitoreo se
realiza de forma remota a través de una aplicación móvil realizada en
Android Studio que se conecta a Firebase para mostrar el estado del
sistema y sensores, batería, además de permitir el envío de comandos.

En los sistemas acuícolas tradicionales, la **alimentación manual**
representa hasta el 60 % de los costos de operación. Además, el exceso
de alimento no consumido genera un **impacto ambiental negativo**, pues
se acumula en el fondo de los estanques, deteriora la calidad del agua y
aumenta la mortalidad de los organismos. Con la automatización se busca
reducir el desperdicio de balanceado, optimizar la eficiencia productiva
y minimizar los costos asociados, lo que justifica el desarrollo de este
sistema

En el dispositivo, además se puede supervisar la temperatura del agua,
así como el nivel de alimento que queda en la tolva. Estos controles
permiten una alimentación automatizada y adaptativa que minimiza el
desperdicio y protege el cultivo.

2)  **Alcance y limitaciones**

Alcance

-   Desarrollo de un sistema dosificador automático sobre la base de un
    microcontrolador ESP32, con conectividad LoRa y Wi-Fi.

-   Control del motor mediante un circuito con un MOSFET, buscando
    ahorrar energía.

-   Incorporación de sensores para detectar la temperatura y controlar
    el nivel del agua.

-   Recepción de comandos mediante un nodo transmisor LoRa.

-   Supervisión en tiempo real mediante integración a Firebase.

-   Desarrollo de una aplicación para Android.

Limitaciones

-   El rango máximo de comunicación LoRa puede verse reducido en
    presencia de obstáculos o interferencias, limitando la cobertura en
    algunas zonas de la camaronera.

-   La autonomía del sistema depende de la duración de la batería
    Li-Ion, la cual requiere recarga periódica.

-   El uso de la aplicación móvil depende de la disponibilidad de
    internet para sincronizar datos en Firebase.

-   El sistema aún no cuenta con un mecanismo de autodiagnóstico ante
    fallos en los sensores o el motor, lo que puede retrasar la
    detección de problemas.

3)  **Diagrama de contexto**

![](media/image1.jpeg){width="4.742595144356955in"
height="2.5576038932633423in"}

**Descripción:** El Sistema consta de dos partes: la alimentadora y la
estación. La alimentadora se encuentra en la zona de trabajo (piscina),
controla los sensores y actuadores. La estación se encarga de recibir
las lecturas de los sensores, procesarlas y cargarlas a una base de
datos. Finalmente, mediante un dispositivo móvil Android se visualiza
los parámetros más relevantes de la piscina.

4)  **Diagrama de bloques**

![](media/image2.png){width="4.564061679790027in"
height="2.580415573053368in"}

5)  **Diagrama de estados**

![](media/image3.png){width="4.383333333333334in"
height="3.204861111111111in"}

6)  **Diagrama de interfaces**

![](media/image4.jpeg){width="2.5179965004374454in" height="2.0in"}

7)  **Alternativas de Diseño**

+-----------------+----------------+-----------------+-----------------+
| > Elemento      | Opciones       | Solución        | Justificación   |
|                 |                | elegida         |                 |
+=================+================+=================+=================+
| > Comunicación  | Wi-Fi,         | LoRa            | Mayor alcance y |
| > entre módulos | Bluetooth,     |                 | bajo consumo    |
|                 | LoRa           |                 | energético      |
+-----------------+----------------+-----------------+-----------------+
| > Comunicación  | HTTP           | Firebase        | Comunicación en |
| > remota        | ,MQTT,Firebase |                 | tiempo real y   |
|                 |                |                 | fácil           |
|                 |                |                 | integración con |
|                 |                |                 | Android         |
+-----------------+----------------+-----------------+-----------------+
| > Control del   | Relé, Puente   | MOSFET IRLZ44N  | Eficiente para  |
| > motor         | H, MOSFET      |                 | solo un mismo   |
|                 |                |                 | sentido de giro |
+-----------------+----------------+-----------------+-----------------+
| > Sensor de     | Celda de       | Sensor          | Económico y     |
| > nivel         | carga,         | capacitivo      | fácil de        |
|                 | capacitivo,    |                 | implementar.    |
|                 | Ultrasonico    |                 |                 |
+-----------------+----------------+-----------------+-----------------+
| > Suministro    | Red eléctrica, | Bateria LI-ION  | Autonomía y     |
| > energético    | batería        |                 | portabilidad    |
+-----------------+----------------+-----------------+-----------------+
| > App móvil     | WebApp, nativa | F               | Conocimientos   |
|                 |                | irebase+Android | previos.        |
|                 |                | Studio          |                 |
+-----------------+----------------+-----------------+-----------------+
| > Carga de      | Cargador       | TP4056          | Solución simple |
| > batería       | externo,       |                 | y económica     |
|                 | TP4056         |                 |                 |
+-----------------+----------------+-----------------+-----------------+

8)  **Plan de Pruebas y Validación**

    -   LoRa: Evaluación de rango, latencia, errores y respuesta ante
        datos faltantes.

    -   Motor: Verifique la entrega de dosis en relación con el tiempo y
        la consistencia durante la carga.

    -   Sensores: Validar la medición de temperatura contra un
        termómetro calibrado y verificar el nivel de lectura de
        alimentos.

    -   Aplicación móvil: Verifique la sincronización con Firebase,
        ejecución de comandos, notificaciones y visualización de datos.

    -   Energía: Medir el consumo activo y en espera. Predecir la
        autonomía.

    -   Robusto: Probar en entornos húmedos y similar pérdida de Wi-Fi.

9)  **Consideraciones éticas**

    -   Accesibilidad: Automatiza procesos para productores de pequeña
        escala.

    -   Sostenibilidad: Reduce desperdicios, mejora la calidad del agua.

    -   Privacidad: Protege el acceso con credenciales seguras.

10) **Mejoras futuras**

-   Añadir panel solar con carga inteligente.

-   Añadir control por horario o historial.

-   Medición de batería

-   Módulo de autodiagnóstico. - que verifique periódicamente el
    correcto funcionamiento de los sensores y el motor. Este sistema
    podría emitir alertas preventivas mediante la aplicación móvil en
    caso de detectar fallos, lo que permitiría una **intervención
    temprana** y reduciría riesgos de pérdidas productivas en el entorno
    acuícola.
