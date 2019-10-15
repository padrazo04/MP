#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct libro {
  char titulo[MAX];
  char autor[MAX];
  float precio;
  int uds;
};

int compruebaLibro(char *nombreFichero);
void nuevoLibro(char *nombreFichero);
int cuentaLibros(char *nombreFichero);
void listarLibros(char *nombreFichero);
int venderLibro(char *nombreFichero);
int borrarLibros(char *nombreFichero);

int main(int argc, char const *argv[]) {
  if(argc!=2) {
    printf("SINTAXIS INCORRECTA\n<ejecutable> <ficheroBinario>\n");
    return -1;
  }
  char nombreFichero[MAX];
  strcpy(nombreFichero, argv[1]);
  volatile int opc=0;

  while(opc!=7)
  {
    printf("1. Comprobar libro por titulo\n");
    printf("2. Nuevo libro\n");
    printf("3. Contar libros\n");
    printf("4. Listar libros (vect dinam)\n");
    printf("5. Vender libro por titulo\n");
    printf("6. Borrar libros con 0 uds\n");
    printf("7. Salir\n");
    printf("Introduce una opcion: ");
    scanf("%d", &opc);

    switch(opc)
    {
      case 1: {
        if(compruebaLibro(nombreFichero))
          printf("\nEl libro esta disponible\n\n");
        else printf("\nEl libro no se ha encontrado\n\n");
      } break;
      case 2: {
        nuevoLibro(nombreFichero);
      } break;
      case 3: {
        printf("\nNumero de libros -> %d\n\n", cuentaLibros(nombreFichero));
      } break;
      case 4: {
        listarLibros(nombreFichero);
      } break;
      case 5: {
        if(venderLibro(nombreFichero)) printf("\nLibro vendido\n\n");
        else printf("\nError al vender el libro\n\n");
      } break;
      case 6: {
        if(borrarLibros(nombreFichero)) printf("\nSe han borrado libros\n\n");
        else printf("\nNo habia libros que borrar\n\n");
      } break;
      case 7: {
        printf("ADIOS\n");
      } break;
      default:
        printf("\nIntroduzca un numero correcto\n\n");
    }
  }

}

int compruebaLibro(char *nombreFichero){
  FILE *f;
  f=fopen(nombreFichero, "rb");
  if(f==NULL) {
    printf("Error al abrir el fichero\n");
    exit(-1);
  }
  int encontrado=0;
  struct libro aux, buscado;
  printf("TITULO A BUSCAR: ");
  getchar();
  fgets(buscado.titulo, MAX, stdin);
  buscado.titulo[strlen(buscado.titulo)-1]='\0';

  while(fread(&aux, sizeof(struct libro), 1, f) == 1)
  {
    if(strcmp(aux.titulo, buscado.titulo) == 0) {
      encontrado=1;
      return encontrado;
    }
  }
  return encontrado;
}
void nuevoLibro(char *nombreFichero){
  FILE *f;
  f=fopen(nombreFichero, "ab");
  if(f==NULL) {
    printf("Error al abrir el fichero\n");
    exit(-1);
  }
  struct libro aux;
  printf("TITULO: ");
  getchar();
  fgets(aux.titulo, MAX, stdin);
  aux.titulo[strlen(aux.titulo)-1]='\0';
  printf("AUTOR: ");
  fgets(aux.autor, MAX, stdin);
  aux.autor[strlen(aux.autor)-1]='\0';
  printf("PRECIO: ");
  scanf("%f", &aux.precio);
  printf("UDS: ");
  scanf("%d",&aux.uds);
  fwrite(&aux, sizeof(struct libro), 1, f);
  fclose(f);
}
int cuentaLibros(char *nombreFichero){
  FILE *f;
  f=fopen(nombreFichero, "rb");
  if(f==NULL) {
    printf("Error al abrir el fichero\n");
    exit(-1);
  }
  fseek(f, 0, SEEK_END);
  return ftell(f)/sizeof(struct libro);
}
void listarLibros(char *nombreFichero){
  FILE *f;
  f=fopen(nombreFichero, "rb");
  if(f==NULL) {
    printf("Error al abrir el fichero\n");
    exit(-1);
  }
  int nregistros = cuentaLibros(nombreFichero), i=0;
  struct libro *libreria, aux;
  libreria=(struct libro *)malloc(nregistros * sizeof(struct libro));
  while(fread(&aux, sizeof(struct libro), 1, f)==1)
  {
    libreria[i]=aux;
    i++;
  }
  for(int i=0; i<nregistros; i++) {
    printf("Titulo: %s\n", libreria[i].titulo);
    printf("Autor: %s\n", libreria[i].autor);
    printf("Precio: %.2f Uds: %d\n\n", libreria[i].precio, libreria[i].uds);
  }
  free(libreria);
}
int venderLibro(char *nombreFichero){
  FILE *f;
  f=fopen(nombreFichero, "r+b");
  if(f==NULL) {
    printf("Error al abrir el fichero\n");
    exit(-1);
  }
  char titulobuscado[MAX];
  struct libro aux;
  int found=0;
  printf("TITULO A VENDER: ");
  getchar();
  fgets(titulobuscado, MAX, stdin);
  titulobuscado[strlen(titulobuscado)-1]='\0';

  while(fread(&aux, sizeof(struct libro), 1, f) == 1)
  {
    if(strcmp(aux.titulo, titulobuscado) == 0)
    {
      if(aux.uds == 0) printf("\nNo quedan unidades del libro\n");
      else {
        found=1;
        aux.uds-=1;
        fseek(f, -(int)sizeof(struct libro), SEEK_CUR);
        fwrite(&aux, sizeof(struct libro), 1, f);
        fflush(f);
      }
    }
  }
  return found;
}
int borrarLibros(char *nombreFichero) {
  FILE *f1, *f2;
  f1=fopen(nombreFichero, "rb");
  if(f1==NULL) {
    printf("Error al abrir el fichero\n");
    exit(-1);
  }
  f2=fopen("temp", "wb");
  if(f2==NULL) {
    printf("Error al crear el fichero temporal\n");
    exit(-1);
  }
  int borrado=0;
  struct libro aux;
  while(fread(&aux, sizeof(struct libro), 1, f1) == 1)
  {
    if(aux.uds != 0) fwrite(&aux, sizeof(struct libro), 1, f2);
    else borrado=1;
  }
  fclose(f1);
  fclose(f2);
  remove(nombreFichero);
  rename("temp", nombreFichero);
  return borrado;
}
