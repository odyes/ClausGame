# 1.- Introducción

### 1.1 Abstract
Nuestro objetivo en este proyecto final es crear un juego usando los conocimientos obtenidos en la materia de programación orientada a objetos utilizando programación en C++. El juego fue creado utilizando la librería SMFL y Box2D, con algunos extras agregados por nosotros mismos.


### 1.2 Introducción
Para iniciar nuestro proyecto decidimos concentrarnos en lo importante y comenzamos a establecer las bases de investigación de nuestro proyecto, las cuales fueron, principalmente, investigar sobre librerías SFML, implementaciones de Box2D y creación de sprites. El proyecto fue realizado en su totalidad usando el editor Visual Studio Code de Microsoft.
El videojuego que creamos esta basado en C++, utilizando todos los conocimientos y conceptos establecidos en clase. Utilizando estas herramientas, pudimos expandir nuestro conocimiento sobre Box2D y sobre la biblioteca SFML para poder implementarlos de una manera eficiente en el juego. También investigamos en línea para aclarar unas dudas que teníamos sobre los objetos y sobre el movimiento del personaje.
El juego lo decidimos crear con temática navideña ya que las fechas se aproximan y quisimos crear algo con un ambiente navideño, utilizando sprites y backgrounds relacionados con la navidad y el invierno.


### 1.3 Antecedentes  
SFML fue creado en el 2007 por el SFML team, SFML permite crear aplicaciones multiplataformas que hace transparente el sistema de ventanas y eventos de un sistema operativo. SFML (Simple and Fast Multimedia Library) está escrito en C++ con un enfoque orientado a objetos para el desarrollo de aplicaciones interactivas enfocada en el desarrollo de juegos 2D, y con las versiones más recientes en 3D. Adicionalmente, SFML tiene diversos binding para los lenguajes de programación C, basados en .Net, D, Java, Python, Ruby, Go, OCaml, Nimrod, Euphoria y Rust.
Box2D es un motor de fisicas rígidas 2D escrita en C++ por Erin Catto. Este motor ha sido utilizado en una gran cantidad de juegos, incluyendo a unos muy reconocibles como angry birds, shovel knight o happy wheels. Box2D utiliza la licencia zlib y se puede usar de manera gratuita. Box2D fue desarrollado en Windows utilizando Visual C++. También existen puertos disponibles para Java, C#, y Python. 
Diversos historiadores, entre ellos el español, Francisco José Gómez Fernández, explican que Santa Claus está basado en el obispo cristiano Nicolás de Bari, nacido en el siglo III d.C. en Patara, una ciudad marítima y comercial en la provincia de Antalya, hoy Turquía.
La familia de Nicolás de Bari gozaba de una excelente posición económica. Tras la muerte de sus padres, Nicolás de Bari repartió sus posesiones entre las personas más necesitadas y entregó su fe a la religión para reconfortar su dolor. Con el tiempo, el precursor de Santa Claus se convirtió en obispo de la ciudad de Mira, en Licia, hoy Turquía.
Durante el siglo XVIII, una imagen de San Nicolás de Bari vestido de obispo y de edad avanzada entró a Estados Unidos. Todo se deriva a raíz de la Fiesta de San Nicolás que en holandés se escribe “Sinterklaas” y que se conmemora entre la noche del 5 y 6 de diciembre. La traducción del nombre “Sinterklaas” derivó con el tiempo en Estados Unidos como Santa Claus.

# 2.- Desarrollo

### 2.1 Diseño y temática del juego
Ya que nos decidimos por tener una temática navideña, comenzamos a buscar los sprites que utilizaríamos para la creación de nuestro videojuego. Después de conseguir ideas decidimos utilizar de personaje a Santa Claus ya que es un personaje altamente reconocible y fácil de implementar en un juego. Después de definir el personaje, comenzamos a pensar sobre la dinámica del juego y utilizamos un regalo como el objeto a buscar y a un monstruo como el enemigo principal. Con esto establecido pudimos investigar en línea y encontramos sprites que se apegaban a la ambientación que estábamos buscando (Creditos a los autores en bibliografía).
![gift](https://user-images.githubusercontent.com/75157915/144991318-3c741d0e-e731-4146-b5d9-e73d433ab03c.png)
![santa2](https://user-images.githubusercontent.com/75157915/144989582-3da9d092-92fa-45c1-b483-91ac624243fe.png)
![snow](https://user-images.githubusercontent.com/75157915/144990877-05f0ebe3-ef58-4fe6-9992-3acf3f53ad89.jpg)
![enemy1](https://user-images.githubusercontent.com/75157915/144990931-8577d68f-2027-4c02-b86f-85f8d95ccd5a.png)


### 2.2 Animación del personaje
Para darle más chispa al movimiento de Claus decidimos agregarle una animación simple de movimiento, incluimos una clase llamada “animación” y incluimos un archivo cc para tener a la mano la configuración de los movimientos. De esta manera logramos dar la impresión de que Claus corre mientras recoge regalos en el juego.

###2.3 Regalos
Con el regalo decidimos hacer un item que se ganen puntos cada que se pasa por encima de el y reaparezca en otro lado del mapa. Para hacer esto creamos una clase con el nombre de “gift” con un archivo cc y le aplicamos un respawn con un randomizador para asegurarnos que el regalo no aparezca en el mismo lugar de nuevo, de esta manera logramos hacer que el regalo aparezca de nuevo en un lugar nuevo cada vez que Claus pasa por encima de él.

### 2.4 Enemigo 
Aquí decidimos darle un enemigo a Claus para crearle un desafío al jugar mientras trata de conseguir todos los regalos posibles. Con el enemigo utilizamos de nuevo los componentes que utilizamos en el archivo gift pero le dimos propiedades distintas para que interactúe de la manera deseada con Claus. El enemigo decidimos que se movería a través del mapa y que el personaje tiene que evitarlo mientras trata de obtener regalos. Con esto en cuenta, establecimos las posiciones por las cuales el enemigo se movería y hicimos que el monstruo sea constante para que no desaparezca.

### 2.5 Score y Vidas
Nuestro plan con el puntaje y las vidas era crear una sensación de un minijuego arcade que te da un numero de vidas y tu tienes que conseguir el score más alto que puedas antes de que se acaben las vidas.
Para contar el score utilizamos la interacción de el personaje con los regalos para que cada vez que Claus pasara por encima de uno el score se actualizara, para las vidas utilizamos el mismo mecanismo, pero con un limite de 3 vidas para crearle más desafío al jugador.


# 3.- Contenido de clases 
* En la clase Main es donde incluimos toda la programación esencial del juego, aquí es donde cargamos todas las interacciones que tienen los personajes y es donde programas el sistema de puntaje y de vidas para que se pueda interactuar con las otras clases de una manera simple.
* En la clase de Character es la clase que utilizamos para darle texturas, aplicarle movimiento y los colliders a nuestro personaje, aquí es donde se anima el personaje y donde se ve creo el movimiento de Claus
* En la clase Collisionable escribimos el código necesario para las interacciones que tiene nuestro personaje con el enemigo y el objeto que implementamos, gracias a esto se pueden detectar las colisiones que tiene el personaje con los otros objetos del juego.
* En la clase Gift incluimos los parámetros para el regalo y la manera en que interactúa con el personaje, aquí es donde le aplicamos el respawn al regalo y hicimos que apareciera en otro lado cada vez que se detectaba una interacción con Claus.
* En la clase Enemy es donde se programó el movimiento y las texturas del monstruo, a diferencia de la clase gift, el enemigo lo hicimos un objeto constante que no respawnea en otro lado del mapa después de interactuar con el personaje.


# 4.- Resultado
Finalmente pudimos terminar el videojuego y logramos implementar lo que teníamos en mente. Pudimos crear un juego y logramos terminar el proyecto de una manera satisfactoria ya que pudimos crear un sistema de vidas y puntos exitoso, con ambientación navideña que tuviera un plan de juego simple, con un objetivo y un enemigo que genere desafío a la hora de jugar. 


# 5.- Conclusión
En definitiva, este proyecto fue una experiencia de aprendizaje que nos dejo muchas enseñanzas sobre la creación de juegos en SFML y sobre la creación de cualquier tipo de proyecto en general. Este proyecto nos ayudo a aplicar varios de los conceptos vistos en clase previamente y nos permitió crear algo desde cero con nuestra creatividad mientras nos mostraba muchas otras oportunidades de aprendizaje a lo largo del desarrollo de este mismo. Con todo lo anterior, podemos decir que comprendimos mucho mejor el uso de SFML y la programación en C++ y fuimos capaces de completar la meta que nos pusimos con el juego que creamos de una manera funcional y eficiente. 



# 6.- Referencias 
1.	Ferreira, Z. (2009, 23 diciembre). Openpixels – Chars. Silveira Neto. Recuperado 24 de noviembre de 2021, de http://silveiraneto.net/2009/12/23/openpixels-chars/
2.	Minecraft Wallpaper Template - WallpaperSafari. (s. f.). Wallpapersafari. Recuperado 24 de noviembre de 2021, de https://wallpapersafari.com/w/p2JB61
3.	SFML. (s. f.). SFML. Recuperado 26 de noviembre de 2021, de https://www.sfml-dev.org/
4.	Freepik. (2021, 8 noviembre). gradient christmas frames and borders collection Free Vector. Recuperado 2 de diciembre de 2021, de https://www.freepik.com/
5.	dafont. (s. f.). Xmas Sweater Stitch | dafont.com. Recuperado 3 de diciembre de 2021, de https://www.dafont.com/es/xmas-sweater-stitch.font
6.	SFML. (s. f.-a). Playing sounds and music (SFML / Learn / 2.5 Tutorials). Recuperado 4 de diciembre de 2021, de https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
7.	SFML. (s. f.). Sprites and textures (SFML / Learn / 2.5 Tutorials). Recuperado 3 de diciembre de 2021, de https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
8.	Microsoft. (2021, 1 diciembre). Aquí está otra vez C++: C++ moderno. Microsoft Docs. Recuperado 28 de noviembre de 2021, de https://docs.microsoft.com/es-es/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170
9.	OGA. (2018, 11 febrero). Witch Cackle. OpenGameArt.org. Recuperado 3 de diciembre de 2021, de https://opengameart.org/content/witch-cackle
10.	por Daniel Benítez @dabntz. (2019, 19 noviembre). “Videojuego: «Pizza Guy»”. Un proyecto de dabntz. Domestika. Recuperado 3 de diciembre de 2021, de https://www.domestika.org/es/projects/598044-videojuego-pizza-guy
11.	SFML. (s. f.-a). sf::Music Class Reference (SFML / Learn / 2.5.1 Documentation). Recuperado 30 de noviembre de 2021, de https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Music.php
12.	Sonido Original De Las Luces Navideñas. (2016, 1 diciembre). YouTube. Recuperado 4 de diciembre de 2021, de https://www.youtube.com/watch?v=O1uGdRA73MQ
13.	SFML. (s. f.-a). Generating random numbers (SFML / Learn / 1.6 Tutorials). Recuperado 30 de noviembre de 2021, de https://www.sfml-dev.org/tutorials/1.6/system-random.php
14.	Mendez Ruiz, L. (2017, 12 octubre). [PDF] Videojuegos, C/C++ y SDL - Free Download PDF. Videojuegos, C/C++ y SDL. Recuperado 30 de noviembre de 2021, de https://silo.tips/download/videojuegos-c-c-y-sdl
15.	Milenio. (s. f.). Origen de Santa. Recuperado 5 de diciembre de 2021, de https://www.milenio.com/cultura/santa-claus-origen-historia-llega-navidad
16.	SFML. (2016). Game menu. Recuperado 30 de noviembre de 2021, de https://en.sfml-dev.org/forums/index.php?topic=20525.0
17.	Google. (s. f.). Google Code Archive - Long-term storage for Google Code Project Hosting. Google Code Archive. Recuperado 1 de diciembre de 2021, de https://code.google.com/archive/p/box2d/wikis/FAQ.wiki
18.	Box2D. (s. f.). Box2D: Overview. Recuperado 30 de diciembre de 2021, de https://box2d.org/documentation/
19.	M. (2020, 3 agosto). A Closer Look at SFML. GameFromScratch.Com. Recuperado 2 de diciembre de 2021, de https://gamefromscratch.com/a-closer-look-at-sfml/
20.	Emmett J. Butler. (2012). Howtodetectcollisionbut do notcollide in box2d?. 02/12/2021, de Stackoverrun Sitio web: https://stackoverrun.com/es/q/2939096
21.	Laurent Gomila. (2021). Sprites and textures. 02/12/2021, de SFML Sitio web: https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
22.	Yang Ming. (Abril, 2017). Creando un videojuego en C++. 29/11/2021, de GosuGames Sitio web: https://rodin.uca.es/xmlui/bitstream/handle/10498/17235/Gosu-LinuxMagazine.pdf?sequence=1&isAllowed=y
23.	Catto, E. (s. f.). Box2D v2.3.0 User Manual. box2d.pdf. Recuperado 30 de noviembre de 2021
de 2020, de http://dssp.me/doc/box2d.pdf
24.	Costa, H. (s. f.). 12 frameworks y librerías para desarrollar juegos | Escuela de Videojuegos | Hektor Profe. 12 frameworks y librerías para desarrollar juegos. 
Recuperado 27 de noviembre de 2021, de https://docs.hektorprofe.net/escueladevideojuegos/articulos/frameworks-librerias-
bibliotecas-recopilacion
25.	Derego, L. (2015, 11 diciembre). C++ and SFML Game Tutorial –. lucasderego. de https://lucasderego.wordpress.com/category/c-and-sfml-game-tutorial/
26.	Gomila, L. (s. f.). Opening and managing a SFML window (SFML / Learn / 2.5 Tutorials). SFML. Recuperado 29 de noviembre de 2021, de https://www.sfml-
dev.org/tutorials/2.5/window-window.php}
27.	Gomila, L. (s. f.-e). sf::Keyboard Class Reference (SFML / Learn / 2.5.1 
Documentation). SFML. Recuperado 30 de noviembre de 2021, de https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
28.	Soulié, J. (2007, junio). C++ Language Tutorial. cplusplus.com. 
https://www.cplusplus.com/files/tutorial.pdf
29.	Anónimo. (2013, 12 febrero). SFML 2, biblioteca para el desarrollo de videojuegos. Genbeta. https://www.genbeta.com/desarrollo/sfml-2-biblioteca-para-el-desarrollodevideojuegos#:%7E:text=SFML%20es%20una%20biblioteca%20multiplataforma,el%20desarrollo%20de%20videojuegos%202D.

30.	Dürrenberger, L. (2018). 2D Graphics with SFML Simple and Fast Multimedia Library. 2D Graphics with SFML. 
https://meetingcpp.com/mcpp/slides/2018/2D%20Graphics%20with%20SFML.

