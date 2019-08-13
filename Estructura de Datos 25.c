#include<stdio.h>
#include<stdlib.h>
#define T 50
void Abre1(FILE**);
void Carga1(FILE*);
void Lee1(FILE*,float*);
void Abre2(FILE**);
void Carga2(FILE*,float);
void Lee2(FILE*,FILE*,int*,int*);
void Imprimir(float,int,int);

int main()
{
    system("color F0");
    FILE *arch1=NULL, *arch2=NULL;
    float prome;
    int mayor=0,menor=0;
    Abre1(&arch1);
    Carga1(arch1);
    rewind(arch1);
    Lee1(arch1,&prome);
    Abre2(&arch2);
    Carga2(arch2,prome);
    rewind(arch1);
    rewind(arch2);
    Lee2(arch1,arch2,&mayor,&menor);
    Imprimir(prome,mayor,menor);
    getchar();
    getchar();
}

void Abre1(FILE ** arch1)
{
    char cad[T];
    printf("\n\t\t\t\tArchivos.\n\n");
    printf("\nIngresa el Nombre del Primer Archivo con la Extencion -.txt-: ");
    gets(cad);
    *arch1=fopen(cad,"w+");
    if(*arch1==NULL)
    {
        printf("\n\nError. No Se Pudo Abrir el Archivo.\n\n");
        getchar();
        exit(1);
    }
}

void Carga1(FILE *arch1)
{
    char cad[T],*var=NULL;
    int num;
    printf("\nIngresa los Elemento al Archivo. Para Terminar de Cargar Ingresa el Nulo.\n");
    printf("\nIngresa el Nombre del Alumno: ");
    var=gets(cad);
    if(var!=NULL)
    {
        printf("Ingesa la Edad de %s:",cad);
        scanf("%d",&num);
    }
    while(var!=NULL)
    {
        fprintf(arch1,"%-10s %-2d\n",cad,num);
        fflush(stdin);
        printf("\nIngresa el Nombre del Alumno: ");
        var=gets(cad);
        if(var!=NULL)
        {
            printf("Ingesa la Edad de %s:",cad);
            scanf("%d",&num);
        }
    }
}

void Lee1(FILE *arch1, float *prome)
{
    char cad[T];
    int edad=0,centi=0;
    float suma=0;
    printf("\n\nLa Informacion Ingresada en el Primer Archivo es:\n");
    fscanf(arch1,"%s %d",cad,&edad);
    while(!feof(arch1))
    {
        printf("\nEl Alumno %-10s tiene una Edad de %-2d anios.",cad,edad);
        suma+=edad;
        fscanf(arch1,"%s %d",cad,&edad);
        centi++;
    }
    *prome=suma/centi;
}

void Abre2(FILE ** arch2)
{
    char cad[T];
    printf("\n\nIngresa el Nombre del Segundo Archivo con la Extencion -.txt-: ");
    gets(cad);
    *arch2=fopen(cad,"w+");
    if(*arch2==NULL)
    {
        printf("\n\nError. No Se Pudo Abrir el Archivo.\n\n");
        getchar();
        exit(1);
    }
}

void Carga2(FILE *arch2, float prome)
{
    fprintf(arch2,"%-10f",prome);
}

void Lee2(FILE *arch1, FILE *arch2, int *mayor, int *menor)
{
    float prom=0;
    char cad[T];
    int edad;
    fscanf(arch2,"%f",&prom);
    fscanf(arch1,"%s %d",cad,&edad);
    while(!feof(arch1))
    {
        if(edad>prom)
        {
            ++(*mayor);
        }
        if(edad<prom)
        {
            ++(*menor);
        }
        fscanf(arch1,"%s %d",cad,&edad);
    }


}

void Imprimir(float prome, int mayor, int menor)
{
    printf("\n\nEl Promedio de la Edad de los Alumnos es de: %f",prome);
    printf("\n%d Alumnos Estan Arriba de la Edad Promedio.",mayor);
    printf("\n%d Alumnos Estan Abajo de la Edad Promedio.\n\n",menor);
}

