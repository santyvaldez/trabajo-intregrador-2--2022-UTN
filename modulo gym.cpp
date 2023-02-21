#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha
{
	int dia, mes, anio;
};

struct profesional
{
	int leg;
	char contra[10];
	int socio;
};

struct entrenador
{
	char ApellidoyNombre [60];
	char dia [60];
	int legajo;
	char username[10];
	char password [10];
    
	
};
struct socio
{
	char ApellidoyNombre[60];
	char domicilio[60];
	int DNI;
	fecha fec;
	int edad;
	float peso;
	float altura;
	int telefono;
	int numsocio;
	char medica[50];
	char rutina[380];
};

struct actividades
{
    int act;
	int legajo;
	int socionum;
	float horario;
	float horariofin;
	int ranking;
	
	};

int dibujarMenu();
bool iniciarse(FILE *f, int &legajo);
void evolucion(FILE *f);
void lista (FILE *socios,FILE *act1);


main()
{
	FILE *socios = fopen("socios2.dat", "a+b");
	FILE *entrenadores = fopen("entrenadores.dat", "rb");
	FILE *act1 = fopen("actividadessocio.dat", "rb");

	if(entrenadores == NULL)
	{
		printf("entrenadores.dat no ha sido creado.\n\n");
		system("pause");
		exit(1);
	}

	bool inicio = false, borrar = false;
	int legajo;
	
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	inicio = iniciarse(entrenadores, legajo);		 	 
					 break;
			case 2: if(inicio == true)
						{
						  lista(socios,act1);
					 	}
						 else printf("\nPrimerio debe Iniciar sesion!\n");
					 break;
		
			case 3:if(inicio == true)
						{
						  evolucion(socios);
					 	}
						 else printf("\nPrimerio debe Iniciar sesion!\n");
					 break;
					 }
		printf("\n");
		system("pause");
	}while(opc != 4);
	
	fclose(socios);
	
	fclose(entrenadores);
	exit(1);
}
int dibujarMenu(){
	system("cls");
	printf("\n\t\t\t******************* Modulo Gym *******************\n");
	printf("\n\t\t\t 1) Iniciar Sesion");
	printf("\n\t\t\t 2) Listado de socios y actividad que desarrolla");
	printf("\n\t\t\t 3) Registrar rutina");
    printf("\n\t\t\t 4) Cerrar la aplicacion");
	printf("\n\n\t\t\t Ingrese la opcion deseada: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}
bool iniciarse(FILE *f, int &legajo)
{
	rewind(f);
	profesional log;
	entrenador p;
	bool iniciado = false;
	int valor;
	system("cls");
	
	do
	{
		printf("\n - Ingrese numero de legajo del entrenador/a: ");
		scanf("%d", &log.leg);
	} while (log.leg >= 9999);
	legajo = log.leg;

	printf("\n - Ingrese contrasena: ");
	_flushall();
	gets(log.contra);
	system("cls");
	
    fread(&p, sizeof(entrenador), 1, f);
    while(!feof(f))
    {
        valor = strcmp(log.contra, p.password);
        
        if(log.leg == p.legajo)
		{
			if(valor == 0)
			{	
				printf("\n - Sesion iniciada correctamente");
				printf("\n\n - Bienvenido/a %s!", p.ApellidoyNombre);
				printf("\n");
				iniciado = true;
			}

		}
        fread(&p, sizeof(entrenador), 1, f);
    }
    if(iniciado == false) printf("\nEl nombre de usuario y/o contrasena no coinciden\n\n");
    return iniciado;
}

void evolucion(FILE *f)
{	
	fclose(f);
	f = fopen("socios2.dat", "r+b");

	system("cls");
	socio soc;
	int numero;
    int b=0;

	printf("\n - Ingrese numero de socio: ");
	scanf("%d",&numero);
	system("cls");
    rewind(f);
	fread(&soc, sizeof(socio), 1, f);
	while(!feof(f))
	{  
		if(numero == soc.numsocio)
		{
			system("cls");
			printf("\n - Detalle la rutina: ");
			_flushall();
			gets(soc.rutina);
			
			fwrite(&soc, sizeof(socio), 1, f);
		    b=1;
		}
	
		fread(&soc, sizeof(socio), 1, f);
	}
	if (b==1)
	{
		printf("\n - Rutina registrada\n");
	}
	else
		{
	    printf("\n - Numero de socio no encontrado!");
		printf("\n - Rutina no registrada\n");	
		} 
	
	fclose(f);
}
void lista(FILE *socios, FILE*act1)
{       
        socios = fopen("socios2.dat", "rb");
        act1 = fopen("actividadessocio.dat", "rb");
        system("cls");
 		socio reg;
 		actividades a;
	    rewind(socios);
	    fread(&reg, sizeof(reg), 1, socios);
	    printf("\n\t\t - Listado de socios y actividad que desarrolla:");
	    printf("\n");
	     fread(&a, sizeof(actividades), 1, act1); 
	    while ( !feof(socios) && !feof(act1) )
	    {  
		  printf("\n");
		  printf("\n\t\t - *%s ", reg.ApellidoyNombre );
		   printf("\n\t\t - Numero de socio: %d",reg.numsocio);
		   if(a.act==1)
		   {
		   	printf("\n\t\t - Actividad que desarrolla: Zumba");
		   }
		   if(a.act==2)
		   {
		   	printf("\n\t\t - Actividad que desarrolla: Spinnig");
		   }
		   if(a.act==3)
		   {
		   	printf("\n\t\t - Actividad que desarrolla: Pilates");
		   }
		   fread(&reg, sizeof(reg), 1, socios);
		    fread(&a, sizeof(actividades), 1, act1);
		}	printf("\n");
		fclose(act1);
		fclose(socios);
		}

