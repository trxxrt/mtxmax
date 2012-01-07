#include "m_pd.h"

/* On declare helloworld_class de type t_class (les classes d'objets puredata) */
static t_class *helloworld_class;

/* C'est la structure de notre objet dans puredata.
   La méthode helloworld_new retourne un pointeur vers une instance de cette structure */
typedef struct _helloworld {
  t_object  x_obj;
} t_helloworld;

/* La fonction que l'on souhaite réaliser (il peut y en avoir plusieurs !) */
static void helloworld_bang(t_helloworld *x)
{
  post("Hello world !!");
}

/* Cette fonction est le constructeur qui associe la structure t_helloworld et l'instance de l'objet. 
   Elle retourne un pointeur vers une instance de la structure. */
static void *helloworld_new(void)
{
  t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);

  return (void *)x;
}

/* Cette fonction est la seule que puredata exige à proprement parler (même si c'est mieux d'en avoir plus...)
   Son fonctionnement reste toujours un peu opaque à mes yeux :D */
void helloworld_setup(void) {

  helloworld_class = class_new(gensym("helloworld"),
        		       (t_newmethod)helloworld_new,
        			0, 
				sizeof(t_helloworld),
        			CLASS_DEFAULT, 
				0);

  /* ajoute le lancement de la fonction helloworld_bang quand un bang est reçu en entrée */
  class_addbang(helloworld_class, helloworld_bang);
}

