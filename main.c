#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

void elemento(char theArchies[]);
void ver(char theArchies[]);
int retornainador(char theArchies[]);
void piledad(Pila *a, char theArchies[]);
void cargainador(char theArchies[]);
void avergaston(char theArchies[]);

int main()
{

    int num;
    int u;
    int i;
    char yes;
    char ahre[100];
    stAlumno newkid [100];
    Pila pili;
    inicpila(&pili);
    FILE *richi;
    strcpy(ahre, "theArchies.bin");

    richi= fopen("theArchies.bin", "ab");

    do
    {
        printf("Bienvenido a la guida final: Archivos, por favor, elija el numero de ejercicio que quiere ver: ");
        fflush(stdin);
        scanf("%i", &num);
        switch(num)
        {
        case 1:
            elemento(ahre);
            break;

        case 2:
            elemento(ahre);
            ver(ahre);
            break;

        case 3:
            elemento(ahre);
            ver(ahre);
            num = retornainador(ahre);
            printf("\nla cantidad de elementos en el archivo es de: %i", num);
            break;

        case 4:
            verificainador(ahre);
            break;

        case 5:
            verificainador(ahre);
            avergaston(ahre);

            break;

        case 6:
            avergaston(ahre);
            printf("\nPor favor, agregue un elemento mas al archivo\n");
            cargainador(ahre);
            avergaston(ahre);
            break;

        case 7:
            cargainador(ahre);
            piledad(&pili,ahre);
            mostrar(&pili);
            break;

        case 8:
            cargainador(ahre);
            printf("Ingrese la edad que desea buscar: ");
            fflush(stdin);
            scanf("%i", &num);
            u=medijoqueramayor(ahre, num);
            printf("EL numero de alumnos mayores de %i anios, es de %i",num,u);

            break;

        case 9:
            cargainador(ahre);
            u=anota();
            i=anota2();
            enelmedio(ahre,i,u);
            break;

        case 10:

            cargainador(ahre);
            viejoputo(ahre);
            break;

        case 11:
            cargainador(ahre);
            printf("Ingrese el anio ");
            fflush(stdin);
            scanf("%i", &num);
            u=nosenosoydeaca(ahre,num);
            printf("Los alumnos del anio %i , son %i",num,u);
            break;

        case 12:
            num= carganeitor(newkid, 100);
            copiandoviejos(ahre,newkid,num);
            avergaston(ahre);

            cargainador(ahre);
            printf("Ingrese el anio de los alumnos que desea ingresar a la estructura: ");
            fflush(stdin);
            scanf("%i", &num);
            filtro(ahre, num, newkid);


            break;

        case 13:
            cargainador(ahre);
            num=archirevenge(ahre);
            printf("La cantidad de registros que tiene el archivo es ",num);

            break;

        case 14:
            cargainador(ahre);
            printf("Ingrese la posicion que desea ver ");
            fflush(stdin);
            scanf("%i",&num);
            especifico(ahre,num);


            break;

        case 15:
            cargainador(ahre);
            printf("Ingrese la posicion que desea cambios ");
            fflush(stdin);
            scanf("%i",&num);
            chchchanges(ahre,num);

            break;

        case 16:

            break;

        default:
            printf("NUMERO INVALIDO!, seleccione uno entre 1 y 16!");
            break;
        }
        printf("\nDesea ver otro ejercicio? presione 's' pasa si: ");
        fflush(stdin);
        scanf("%c", &yes);
    }
    while(yes=='s'||yes=='S');
    return 0;
}

void elemento(char theArchies[])
{
    int num;
    FILE *archi;
    archi = fopen(theArchies, "ab");

    if(archi != NULL)
    {
        printf("elija el numero que quiere agregar al arcvhivo: ");
        fflush(stdin);
        scanf("%i", &num);

        fwrite(&num, sizeof(int),1,archi);
        fclose(archi);
    }

}

void ver(char theArchies[])
{
    FILE *archi;
    archi = fopen(theArchies, "rb");
    int num=0;
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&num, sizeof(int),1,archi);

            if(!feof(archi))
            {
                printf("\n |%i|", num);
            }
        }
        fclose(archi);
    }
}

int retornainador(char theArchies[])
{
    FILE *archi;
    archi = fopen(theArchies, "rb");
    int num=0;
    int i=0;
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&num, sizeof(int),1,archi);

            if(!feof(archi))
            {
                i++;
            }
        }
        fclose(archi);
    }

    return i;
}

void verificainador(char theArchies[])
{
    FILE*archi;
    archi=fopen(theArchies,"ab");
    int num=3;
    stAlumno alumno;

    if(archi !=NULL)
    {
        while(num<5)
        {
            printf("\nCargue el legajo del alumno : ");
            fflush(stdin);
            scanf("%i",&alumno.legajo);

            printf("\nCargue el nombre del alumno : ");
            fflush(stdin);
            gets(&alumno.nombreYapellido);

            printf("\nCargue la edad del alumno : ");
            fflush(stdin);
            scanf("%i",&alumno.edad);

            printf("\nCargue el anio del alumno : ");
            fflush(stdin);
            scanf("%i",&alumno.anio);

            printf("\n\n");

            fwrite(&alumno, sizeof(stAlumno),1,archi);

            num++;

        }
        fclose(archi);
    }
}

void avergaston(char theArchies[])
{
    stAlumno alumno;
    FILE *archi;
    archi = fopen(theArchies, "rb");

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno, sizeof(stAlumno),1,archi);

            if(!feof(archi))
            {
                printf("\n----------------------------------------------\n");
                printf("\nLegajo: %i", alumno.legajo);
                printf("\nNombre Y Apellido: %s", alumno.nombreYapellido);
                printf("\nEdad: %i", alumno.edad);
                printf("\nAnio: %i", alumno.anio);

                printf("\n----------------------------------------------");
            }
        }
        fclose(archi);
    }
}

void cargainador(char theArchies[])
{
    FILE*archi;
    archi=fopen(theArchies,"ab");
    int num=3;
    stAlumno alumno;
    char yes='s';

    if(archi !=NULL)
    {
        while(yes=='s')
        {
            printf("\nCargue el legajo del alumno : ");
            fflush(stdin);
            scanf("%i",&alumno.legajo);

            printf("\nCargue el nombre del alumno : ");
            fflush(stdin);
            gets(&alumno.nombreYapellido);

            printf("\nCargue la edad del alumno : ");
            fflush(stdin);
            scanf("%i",&alumno.edad);

            printf("\nCargue el anio del alumno : ");
            fflush(stdin);
            scanf("%i",&alumno.anio);

            printf("\n\n");

            fwrite(&alumno, sizeof(stAlumno),1,archi);

            printf("\nDesea agregar otro elemento? presione 's' pasa si: ");
            fflush(stdin);
            scanf("%c", &yes);

        }
        fclose(archi);
    }
}

void piledad(Pila *a, char theArchies[])
{
    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&jorge,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(jorge.edad >= 18)
                {
                    apilar(a,jorge.legajo);
                }
            }
        }
        fclose(archi);
    }
}

int medijoqueramayor(char theArchies[], int num)
{
    int i;
    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&jorge,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(jorge.edad >= num)
                {
                    i++;
                }
            }
        }
        fclose(archi);
    }
    return i;
}

int enelmedio(char theArchies[], int max, int min)
{
    int i;
    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&jorge,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(jorge.edad >= min && jorge.edad<=max)
                {
                    nombress(jorge);
                }
            }
        }
        fclose(archi);
    }
    return i;
}

int anota()
{
    int i=0;
    printf("Ingrese la edad minima que desea buscar: ");
    fflush(stdin);
    scanf("%i", &i);

    return i;
}

int anota2()
{
    int i=0;
    printf("Ingrese la edad maxima que desea buscar: ");
    fflush(stdin);
    scanf("%i", &i);

    return i;
}

void nombress(stAlumno a)
{

    printf("\n----------------------------------------------\n");
    printf("\nNombre Y Apellido: %s", a.nombreYapellido);
    printf("\n----------------------------------------------");

}

void viejoputo(char theArchies[])
{
    int i;
    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;
    stAlumno aux;
    aux.edad=0;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&jorge,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(jorge.edad>aux.edad)
                {
                    aux = jorge;
                }
            }
        }
        fclose(archi);
        printf("\nEl alumno mas grande es:\n");
        verstrct(aux);

    }
}

void verstrct(stAlumno a)
{
    printf("\n----------------------------------------------\n");
    printf("\nLegajo: %i", a.legajo);
    printf("\nNombre Y Apellido: %s", a.nombreYapellido);
    printf("\nEdad: %i", a.edad);
    printf("\nAnio: %i", a.anio);
    printf("\n----------------------------------------------");

}

int nosenosoydeaca(char theArchies[], int num)
{
    int i;
    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&jorge,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(jorge.anio >= num)
                {
                    i++;
                }
            }
        }
        fclose(archi);
    }
    return i;
}


stAlumno unalumbrado()
{

    stAlumno a;



    printf("\nIngrese el numero de legajo: ");
    fflush(stdin);
    scanf("%d", &a.legajo);

    printf("\nIngrese el nombre del alumno: ");
    fflush(stdin);
    gets(a.nombreYapellido);

    printf("\nIngrese ela edad del alumno: ");
    fflush(stdin);
    scanf("%i", &a.edad);

    printf("\nIngrese el anio del alumno: ");
    fflush(stdin);
    scanf("%i", &a.anio);

    return a;
}

int carganeitor(stAlumno arr[], int dim)
{
    int i= 0;
    char yes;

    do
    {
        arr[i]=unalumbrado();

        i++;

        printf("\nDesea continuar? presione 's' para si ");
        fflush(stdin);
        scanf("%c", &yes);
    }
    while(i<dim && yes=='s'||yes=='S');

    return i;
}

void copiandoviejos(char theArchies[],stAlumno aux[], int val)
{
    int i=0;
    FILE*archi;
    archi=fopen(theArchies,"ab");
    stAlumno jorge;

    if(archi != NULL)
    {
        while(i<val)
        {
            jorge=aux[i];
            fwrite(&jorge,sizeof(stAlumno),1,archi);
            i++;
        }
        fclose(archi);
    }
}


void filtro(char theArchies[], int num, stAlumno aux[])
{
    int i=0;
    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&jorge,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(jorge.anio==num)
                {
                    aux[i]=jorge;
                    i++;
                }
            }
        }
        fclose(archi);
        printf("\nESTRCTURA CARGADA:\n");
        int j=0;
        while(j<i)
        {
            verstrct(aux[j]);
            j++;
        }
    }
}

int archirevenge(char theArchies[])
{
    int i=0;
    FILE*archi;
    archi=fopen(theArchies,"rb");
    if (archi!=NULL)
    {
        fseek(archi,0,SEEK_END);

        i=ftell(archi)/sizeof(stAlumno);
        fclose(archi);
    }
    return i;
}

void especifico(char theArchies[], int dato)
{

    FILE*archi;
    archi=fopen(theArchies,"rb");
    stAlumno jorge;

    if(archi != NULL)
    {

        fseek(archi,sizeof(stAlumno)*(dato-1),SEEK_SET);
        fread(&jorge,sizeof(stAlumno),1,archi);
        fclose(archi);

        printf("El alumno en la posicion %i es: ",dato);
        verstrct(jorge);


    }

}

void chchchanges(char theArchies[], int dato)
{

    FILE*archi;
    archi=fopen(theArchies,"r+b");
    stAlumno jorge;

    if(archi != NULL)
    {

        fseek(archi,sizeof(stAlumno)*(dato-1),SEEK_SET);

            printf("\nCargue el legajo del alumno : ");
            fflush(stdin);
            scanf("%i",&jorge.legajo);

            printf("\nCargue el nombre del alumno : ");
            fflush(stdin);
            gets(&jorge.nombreYapellido);

            printf("\nCargue la edad del alumno : ");
            fflush(stdin);
            scanf("%i",&jorge.edad);

            printf("\nCargue el anio del alumno : ");
            fflush(stdin);
            scanf("%i",&jorge.anio);


        fwrite(&jorge,sizeof(stAlumno),1,archi);
        fclose(archi);

        printf("El alumno en la posicion %i es: ",dato);
        avergaston(theArchies);


    }

}
