#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

float aplicarIVA(float precio);
void ordenarNotebooks(eNotebook lista[],int tam);
void mostrarListas(eNotebook lista[],int tam);
void mostrarLista(eNotebook lista);

int reemplazarCaracter(char cadena[],char x,char y);

int main()
{
    //float num=100;
    //aplicarIVA(num);
//-----------------------//
    eNotebook lista[4]=
    {
        {25,"pepe","intel",1500},
        {35,"juan","amd",1300},
        {55,"pipi","intel",1000},
        {66,"roman","amd",1500}
    };
    //mostrarListas(lista,4);
    //ordenarNotebooks(lista,4);
    //mostrarListas(lista,4);
//-----------------------------//
    char cadena[100];

    char x;

    char y;

    printf("Que letra desea reemplazar");
    fflush(stdin);
    scanf("%c",&x);

    printf("Por cual desea reemplazar? ");
    fflush(stdin);
    scanf("%c",&y);

    printf("Ingrese cadena");
    scanf("%s",&cadena);

    reemplazarCaracter(cadena,x,y);

    printf("%s",cadena);
    return 0;
}



float aplicarIVA(float precio)
{
    float incremento;

    incremento = precio* 0.21;


    printf("El iva es de : %f",incremento);

    return precio;
}

void ordenarNotebooks(eNotebook lista[],int tam)
{
    eNotebook auxNotebook;

    for(int i=0; i < tam -1 ; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if ( strcmp(lista[i].marca,lista[j].marca)<0)
            {
                auxNotebook=lista[i];
                lista[i]=lista[j];
                lista[j]=auxNotebook;
            }
            else if(strcmp(lista[i].marca,lista[j].marca) == 0 &&lista[i].precio > lista[j].precio)
            {
                auxNotebook=lista[i];
                lista[i]=lista[j];
                lista[j]=auxNotebook;
            }
        }
    }
}

void mostrarLista(eNotebook lista)
{
    printf("%d  %s  %s  %f\n",lista.id,lista.marca,lista.procesador,lista.precio);

}

void mostrarListas(eNotebook lista[],int tam)
{
    printf("id  marca procesador  precio\n");
    for(int i=0; i<tam; i++)
    {
        mostrarLista(lista[i]);
    }
}

int reemplazarCaracter(char cadena[],char x,char y)
{
    int contador = 0;
    int indice=0;

    while(cadena[indice]!= '\0')
    {
        if (cadena[indice]==x)
        {
            cadena[indice]=y;
            contador++;
        }

        indice++;
    }
    printf("Las veces que se remplazaron fueron: %d\n",contador);

    return contador;
}
