# Desarrollo:

##Descripción del documento: 
Éste documento contiene un especie de bitácora en la cuál se describa de donde se obtuvieron todos los recursos para la creación del proyecto, además de que se detalla en las dificultades de la realización del mismo.

No pretende ser una tesis, pero si una manera de llevar un control sobre lo que se estuvo realizando. Además de que es un recurso para futuros proyectos, pretende que se pongan observaciones acerca de las dificultades para no ahondar mucho en futuras producciones.


##Contenido: 

**Integración de audio en el proyecto:**

****

Se empezó por desarrollar un pequeño programa donde se reprodujera un archivo de audio, posteriormente se agregó al mundo virtual. La biblioteca indicaba que se podía proporcionar una ubicación tridimensional de las fuentes de audio y es por ello que se integró al proyecto.

La biblioteca utilizada fué **irrKlang**, su integración al proyecto fué mucho más rápida a comparación de **OpenAL**, se intentó realizar con esa biblioteca varios proyectos chicos y similares, pero en el ambiente de MacOS todo se estaba complicando, y es por ello que se optó por la primer opción ya que con ésta si se pudo realizar algo sencillo y rápido para poder utilizarlo de la manera más rápida posible.

En la carpeta de Miniprog está el **primer mini proyecto** que se realizó con la biblioteca se llama:

'helloIrrKlang' 

¿Qué hace? Reproduce un archivo de sonido con un loop infinito. Si presionas una tecla distinta a 'q' reproduce un pequeño efecto de sonido.


****

**Carga de modelos:**

****
Se está trabajando en ello, se pretende usar ASSIMP para la carga de modelos y animaciones.
