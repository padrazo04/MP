#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libros.h"
#define MAX 30

int compruebaLibro(char *nombreFichero);
void nuevoLibro(char *nombreFichero);
int cuentaLibros(char *nombreFichero);
void listarLibros(char *nombreFichero);
void venderLibro(char *nombreFichero, char *titulo);
//void borrarLibros(char *nombreFichero);

int main(int argc, char const *argv[]) {
  if(argc!=2) {
    printf("Error, la sintaxis de los argumentos en linea de ordenes debe ser:\n.<ejecutable> <nombredelFichero>\n");
    exit(-1);
  }
  char nombreFichero[MAX];
  strcpy(nombreFichero, argv[1]);
  int opc;
  do {
    printf("---------------------------------\n\tMIS LIBROS - MENU\n---------------------------------\n");
    printf("1. Comprobar libro\n");
    printf("2. Introducir nuevo libro\n");
    printf("3. Contar libros\n");
    printf("4. Listar libros en vector dinamico\n");
    printf("5. Vender libro por titulo\n");
    printf("6. Borrar libros agotados\n");
    printf("7. Salir\n");
    printf("\nIntroduzca la accion a realizar --> ");
    scanf("%d",&opc);

    switch (opc) {
      case 1:
        if(compruebaLibro(nombreFichero)==0)
          printf("\nEl libro esta disponible\n");
        else printf("No existe ese libro o ha habido un error\n");
        break;
      case 2: nuevoLibro(nombreFichero);
        break;
      case 3: printf("El numero de libros diferentes es %d\n", cuentaLibros(nombreFichero));
        break;
      case 4: listarLibros(nombreFichero);
        break;
      case 5: {
        char titulo[MAX];
        printf("Introduce el titulo a buscar: ");
        getchar();
        fgets(titulo, MAX, stdin);
        venderLibro(nombreFichero, titulo);
      } break;
      case 6: borrarLibros(nombreFichero);
        break;
      case 7: printf("Que tenga un buen dia\n");
        break;
      default: printf("\nIntroduce una opcion correcta\n\n");
    }
  } while (opc!=7);
  return 0;
}

int compruebaLibro(char *nombreFichero) {
  FILE *f=fopen(nombreFichero, "r");
  if(f==NULL) {
    printf("\nError al abrir el fichero en modo lectura\n");
    return -1;
  }

  char titulo[MAX], aux[MAX];
  getchar();
  printf("Introduce el titulo a buscar: ");
  fgets(titulo, MAX, stdin);
//  titulo[strlen(titulo)-1]='\0';
  int cont=3;
  while((fgets(aux, MAX, f))!=NULL) {
    if(((strcmp(aux, titulo))==0) && ((cont%3)==0)) {
      fclose(f);
      return 0;
    }
    cont++;
  }
  fclose(f);
  return -1;
}

void nuevoLibro(char *nombreFichero) {
  FILE *f=fopen(nombreFichero, "a");
  if(f==NULL) {
    printf("Error\n");
    exit(-1);
  }

  char titulo[MAX], autor[MAX];
  int uds;
  float precio;
  getchar();
  printf("Introduce el titulo: ");
  fgets(titulo, MAX, stdin);
  titulo[strlen(titulo)-1]='\0';
  printf("Introduce el autor: ");
  fgets(autor, MAX, stdin);
  autor[strlen(autor)-1]='\0';
  printf("Introduce el precio: ");
  scanf("%f", &precio);
  printf("Introduce las unidades: ");
  scanf("%d", &uds);

  fprintf(f, "%s\n%s\n%.2f %d\n",titulo, autor, precio, uds);
  fclose(f);
}

int cuentaLibros(char *nombreFichero) {
  FILE *f=fopen(nombreFichero, "r");
  if(f==NULL) {
    printf("Error\n");
    exit(-1);
  }

  char aux[MAX];
  int cont=0;
  while(fgets(aux, MAX, f)!=NULL)  //Nº LIBROS
    cont++;
  rewind(f);
  cont/=3;

  char titulos[cont][MAX];
  for(int i=0; i<cont; i++) {       //ASIGNAR LIBROS A VECTOR
    fgets(titulos[i], MAX, f);
    fgets(aux, MAX, f);
    fgets(aux, MAX, f);
  }
  fclose(f);

  for(int i=0; i<cont; i++)       //ORDENAMOS EL VECTOR
    for(int j=i+1; j<cont; j++)
      if((strcmp(titulos[i],titulos[j]))>0) {
        strcpy(aux, titulos[i]);
        strcpy(titulos[i], titulos[j]);
        strcpy(titulos[j], aux);
      }

  int i=0, j=i+1, repe, nlibros=cont;   //REDUCIMOS LOS REPETIDOS
  while(i<cont) {
    repe=1;
    while(j<cont) {
      if((strcmp(titulos[i], titulos[j]))==0) {
        repe++;
        nlibros--;
      }
      j++;
    }
    i+=repe;
    j=i+1;
  }
  return nlibros;
}

void listarLibros(char *nombreFichero) {
  FILE *f=fopen(nombreFichero, "r");
  if(f==NULL) {
    printf("Error\n");
    exit(-1);
  }

  struct libros {
    char titulo[MAX];
    char autor[MAX];
    float precio;
    int uds;
  };

  //char aux[MAX];
  int n=0, c;
  struct libros *libreria;
  while((c=fgetc(f))!=EOF)      //CONTAMOS EL NUMERO DE REGISTROS
    if(c=='.')
      n++;
  rewind(f);
  libreria=(struct libros *)malloc(n*sizeof(struct libros));   //RESERVAMOS MEMORIA PARA N REGISTROS
  for(int i=0; i<n; i++) {      //ASIGNAMOS VALORES AL VECTOR DINAMICO
    fgets(libreria[i].titulo, MAX, f);
    fgets(libreria[i].autor, MAX, f);
    fscanf(f, "%f %d",&(libreria[i].precio), &(libreria[i].uds)); //¿Como con aritmetica de punteros?
    getc(f);
  }
  for(int i=0; i<n; i++) {      //MOSTRAMOS VECTOR DINAMICO
    fprintf(stdout, "TITULO:\t%sAUTOR:\t%sPRECIO:\t%.2f\tUNIDADES:%d\n\n", libreria[i].titulo, libreria[i].autor, libreria[i].precio, libreria[i].uds);
  }
  fclose(f);
  free(libreria);
}

void venderLibro(char *nombreFichero, char *titulo){
  FILE *f=fopen(nombreFichero, "r");
  if(f==NULL) {
    printf("Error al abrir %s\n", nombreFichero);
    exit(-1);
  }

  char aux[MAX];
  int uds, found=0;
  float precio;
  while((fgets(aux, MAX, f))!=NULL) {
    if((strcmp(aux, titulo))==0) {
      fgets(aux, MAX, f);
      fscanf(f, "%f%d", &precio, &uds);
      getc(f);
      if(uds>0) {
        printf("Libro disponible\n");
        found=1;
      }
      break;
    }
  }

  if(found==0) {
    printf("No está disponible el libro %s", titulo);
    fclose(f);
  }
  else {
    rewind(f);
    FILE *f2=fopen("fichDest", "w");
    if(f==NULL) {
      printf("Error al crear %s\n", "fichDest");
      exit(-1);
    }

    while((fgets(aux, MAX, f))!=NULL) {
      if((strcmp(aux, titulo))==0) {
        fputs(aux,f2);
        fgets(aux, MAX, f);
        fputs(aux,f2);
        fscanf(f, "%f%d", &precio, &uds);
        getc(f);
        fprintf(f2, "%f %d\n", precio, uds-1);
      } else fputs(aux, f2);
    }
    fclose(f);
    fclose(f2);
    remove(nombreFichero);
    rename("fichDest", nombreFichero);
  }
}

/*void borrarLibros(char *nombreFichero) {
  FILE *f=fopen(nombreFichero, "r");
  if(f==NULL) {
    printf("Error al abrir %s\n", nombreFichero);
    exit(-1);
  }
  char aux[MAX];
  int cont1=1, cont2=0, uds;
  float precio;
  while((fgets(aux, MAX, f))!=NULL) {
    cont1++;
    if((cont1%3)==0) {
      fscanf(f, "%f%d", &precio, &uds);
      getc(f);
      cont1++;
      if(uds==0)
        cont2++;
    }
  }
  if(cont2==0) {
    printf("No hay registros que borrar\n");
    fclose(f);
  }
  else {
    FILE *f2=fopen("fichDest", "w");
    if(f==NULL) {
      printf("Error al crear %s\n", "fichDest");
      exit(-1);
    }
    rewind(f);
    char deadbooks[cont2][MAX];
    long desp=0;
    int cont3=4, i=0;
    cont1=2;
    while(((fgets(aux, MAX, f))!=NULL) && (i<cont2)) {
      if((cont1%3)==0) {
        fscanf(f, "%f%d", &precio, &uds);
        getc(f);
        cont1++;
        cont3++;
        if(uds==0) {
          fseek(f, desp, SEEK_SET);
          fgets(deadbooks[i], MAX, f);
          cont1++;
          cont3++;
          i++;
        }
      }
      if((cont3%3)==0)
        desp=ftell(f);
      if((cont1%3)!=0) {
        cont1++;
        cont3++;
      }
    }
    for(int i=0; i<cont2; i++)
      printf("%s",deadbooks[i]);
    rewind(f);
    cont3=1;
    while((fgets(aux, MAX, f))!=NULL) {
      //printf("%s",aux);
      for(int i=0; i<cont2; i++)
        if(strcmp(deadbooks[i], aux)==0) {
          fgets(aux, MAX, f);
          fgets(aux, MAX, f);
          cont3=0;
          break;
        }
      if(cont3!=0) {
        fputs(aux, f2);
        fgets(aux, MAX, f);
        fputs(aux, f2);
        fgets(aux, MAX, f);
        fputs(aux, f2);
      } cont3=1;
    }
    fclose(f);
    fclose(f2);
    remove(nombreFichero);
    rename("fichDest", nombreFichero);
  }
}*/
