#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//definicion de constantes
#define LON 101
#define TEN 40
#define TIEMPO 118
#define MOD 200 //Para imprimir cada cierto número de puntos(cada segundo)
#define N_PUNTOS 100 

void copiar(double *inicio, double *llegada, int tamano);

//Inicio del codigo principal
int main(int argc, char **argv){

  //definicion de variables  
  int i;
  double x;
  double rho = atof(argv[1]);

  char arr[sizeof(rho)];

  snprintf(arr,sizeof(rho),"%f",rho);

  char nombre[20];
  strcpy (nombre, "string_");
  strcat (nombre, arr);
  strcat (nombre, ".dat");

  FILE *f = fopen(nombre, "w");  
  
  double c = sqrt(TEN/rho);
  int n_iter = TIEMPO*MOD; //numero de iteraciones que se realizaran-para alcanzar los 120 s con dt 0.005
  double dx = (double) LON/(N_PUNTOS);
  double dt = 0.005;
  double r = c*dt/dx;
  double rdos = pow(r,2);
  
  double *xs = malloc(sizeof(double)*N_PUNTOS);
  double *us_ini = malloc(sizeof(double)*N_PUNTOS);
  double *us_pre = malloc(sizeof(double)*N_PUNTOS);
  double *us_pas = malloc(sizeof(double)*N_PUNTOS); 
  double *us_fut = malloc(sizeof(double)*N_PUNTOS);
    double next;  

  //Se inicializan
  for (i=0; i<N_PUNTOS;i++){ 
    x = (double) i*dx;
    if (x==0 || (x==N_PUNTOS-1)){
      xs[i]=x;
      us_ini[i] = 0.0;
    }
    else if(x <= 0.8*LON){
      us_ini[i]=1.25*x/LON;
    }
    else{
      us_ini[i]=5-5*x/LON;
    }
    xs[i]=x;
    us_fut[i]=0;
    fprintf(f, "%f\t",x);
  }
  fprintf(f, "\n");  
  fprintf(f, "%f\t", 0.0);
  
  //Se resuleve - evolucion de la cuerda en el tiempo
  for (i=1; i<N_PUNTOS-1;i++){
    next = us_ini[i] + rdos*(us_ini[i+1] - 2.0*us_ini[i] + us_ini[i-1]);
    us_fut[i] = next;
    fprintf(f, "%f\t", next);
  }
  fprintf(f, "%f\t", 0.0);
  fprintf(f, "\n");
    copiar(us_ini, us_pas, N_PUNTOS);
  copiar(us_fut, us_pre, N_PUNTOS);
  
  int j;
  for (j=0; j<n_iter;j++){    
    if(j%MOD == 0){
      fprintf(f, "%f\t", 0.0);
    }    
    for (i=1; i<N_PUNTOS-1;i++){
      next = (2.0*(1.0-rdos))*us_pre[i] - us_pas[i] + rdos*(us_pre[i+1] +  us_pre[i-1]);
      us_fut[i] = next;
      if(j%MOD == 0){
	fprintf(f, "%f\t", next);
      }     
    }
    if(j%MOD == 0){
      fprintf(f, "%f\t", 0.0);
      fprintf(f, "\n");
    }
    copiar(us_pre, us_pas, N_PUNTOS);
    copiar(us_fut, us_pre, N_PUNTOS);
  }
  
  fclose(f);
  
  return 0;
}

//Copiar. Para hacer el codigo mas corto y sencillo de leer - Permite duplicar
void copiar(double *inicio, double *llegada, int tamano)
{
  int i;
  for (i=0;i<tamano;i++){
    llegada[i]=inicio[i];
  }
}
