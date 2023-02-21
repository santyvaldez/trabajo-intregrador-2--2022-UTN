#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha
{
	int dia, mes, anio;
};
struct entrenador
{
	char ApellidoyNombre [60];
	char dia [60];
	int legajo;
	char username[10];
	char password [10];
	
};
struct usuario
{
	char username[10];
	char password[10];
	char ApellidoyNombre[60];

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
struct vencimiento
{   
    int numsocio;
    char ApellidoyNombre[60];
	fecha fec;
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
bool iniciars(FILE *f);
void regsocio(FILE *f);
void regactividad(FILE *act,FILE*act1);
void listar (FILE *f,FILE*act1);
void fechadepago(FILE *socios);
main()
{   
    FILE *act = fopen("actividades.dat", "rb");
    FILE *act1 = fopen("actividadessocio.dat", "a+b");
	FILE *socios = fopen("socios2.dat", "a+b");
	FILE *RECEP = fopen("usuarios.dat", "rb");
	FILE *entrenadores = fopen("entrenadores.dat", "rb");
	
	if(entrenadores == NULL)
	{
		printf("entrenadores.dat no ha sido creado.\n\n");
		system("pause");
		exit(1);
}
	bool iniciado = false;
	
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	system("cls");
		        	iniciado = iniciars(RECEP);			 	 
					 break;
					 
			case 2:	system("cls");
			         if(iniciado == true)
						{
							regsocio(socios);
					 	}
						 else printf("\nPrimero debe Iniciar sesion!\n\n");
					 break;
			case 3: system("cls");
			           if(iniciado == true)
			           {
			           	regactividad(act,act1);
					   }
			           
			           break;
			           
			           
			case 4: system("cls");
			           if(iniciado == true)
						{
							 listar (socios,act1);
					 	}
						 else printf("\nPrimero debe Iniciar sesion!\n\n");	 
					 break;
			case 5: system("cls");
			        if(iniciado == true)
			        {
			        	fechadepago(socios);
					}
					else printf("\nPrimero debe Iniciar sesion!\n\n");

		}
		printf("\n");
		system("pause");
	}while(opc != 6);
	
	fclose(socios);
	fclose(RECEP);
	fclose(entrenadores);
	exit(1);
}
int dibujarMenu(){
	system("cls");
	printf("\n\t\t\t ****************** Modulo Recepcion ******************\n");
	printf("\n\t\t\t 1) Iniciar Sesion");
	printf("\n\t\t\t 2) Registrar socios");
	printf("\n\t\t\t 3) Registrar Actividades de Socios");
	printf("\n\t\t\t 4) Lista de socios");
	printf("\n\t\t\t 5) Listado de fechas de pagos");
    printf("\n\t\t\t 6) Cerrar la aplicacion");
	printf("\n\n\t\t\t Ingrese la opcion deseada: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}
bool iniciars(FILE *f)
{
	entrenador login;
	usuario us;
	bool iniciado = false;
	int valor, valor2;
	system("cls");
	
	printf("- Ingrese nombre de usuario: ");
	_flushall();
	gets(login.username);
	printf("\n- Ingrese contrasena: ");
	gets(login.password);
	
    rewind(f);
    fread(&us, sizeof(usuario), 1, f);
    while(!feof(f))
    {
        valor = strcmp(login.username, us.username);
        valor2 = strcmp(login.password, us.password);
        
        if(valor == 0 && valor2 == 0)
		{
			printf("\n\n -Sesion iniciada correctamente.- \n\n");
			iniciado = true;
		}
        fread(&us, sizeof(usuario), 1, f);
    }
    if(iniciado == false) printf("\n\nEl nombre de usuario y/o contrasena no coinciden\n\n");
    return iniciado;
    fclose(f);
}
void regsocio(FILE *socios)
{

	socio m;
	int x;
	system("cls");

	do{
	printf("\t\t\t *Registro de socios*\n\n");
	printf("- Apellido y nombre: ");
	_flushall();
	gets(m.ApellidoyNombre);
   	_flushall(); 
    printf("\n- Numero de socio: ");
	scanf("%d", &m.numsocio);
	
	printf("\n- Domicilio: ");
	_flushall();
	gets(m.domicilio);

	printf("\n- DNI: ");
	scanf("%d", &m.DNI);
_flushall();
	printf("\n\t\t* Fecha de ingreso *\n");
	printf("- Dia: ");
	
	scanf("%d", &m.fec.dia);
	printf("\n- Mes: ");
	scanf("%d", &m.fec.mes);
	printf("\n- Anio: ");
	scanf("%d", &m.fec.anio);
	
	printf("\n- Peso(Kg): ");
	scanf("%f", &m.peso);
	
	printf("\n- Edad: ");
	scanf("%d", &m.edad);
	
	printf("\n- Altura: ");
	scanf("%f", &m.altura);
	
	printf("\n- Telefono: ");
	_flushall();
	scanf("%d",&m.telefono);

	printf("\n- Registro medico: ");
	_flushall();
	gets(m.medica);
	fwrite(&m, sizeof(socio), 1, socios);
	   do{
                printf("\n- Desea agregar otro socio? (SI:1 , NO:0): ");
                scanf("%d" ,&x);
           }while (x!=0 && x!=1);
        
        printf("\n");
        }while (x==1);
        fclose(socios);

}
void listar(FILE *socios,FILE *act1)
{       int act;
        float h;
        fclose(act1);
        act1 = fopen("actividadessocio.dat", "rb");
        socios = fopen("socios2.dat", "rb");
		actividades a;
	    socio reg;
	    rewind(socios);
	    rewind(act1);
	    fread(&reg, sizeof(reg), 1, socios);
	    fread(&a, sizeof(actividades), 1, act1);
	    printf("\n\t\tLISTA DE SOCIOS:");
	    printf("\n");
	    printf("\n\t\tIngrese 1 para la lista de zumba, 2 para spinnig y 3 para la de pilates:"); 
	    scanf("%d",&act);
	    printf("\n\t\t ingrese la hora:");
	    scanf("%f",&h);
	    while ( !feof(socios) && !feof(act1) )
	    {  
	    if(act==a.act && h== a.horario)
		{
		  if(a.socionum==reg.numsocio)
		  printf("\n\t\t");
		  printf("\t %s ", reg.ApellidoyNombre );
		   printf("\n\t\tnumero de socio: %d",a.socionum);
		   
		}
		fread(&a, sizeof(actividades), 1, act1);
		fread(&reg, sizeof(reg), 1, socios);
	    }
		printf("\n");
		fclose(socios);
		fclose(act1);
}
void fechadepago(FILE *socios)
{   
int dia, mes ,anio;
int b=0;
socios=fopen("socios2.dat", "rb");
    _flushall;
	socio reg;
	printf("\n - Ingrese la fecha deseada: ");
	    printf("\n - Dia: ");
	    scanf("%d",&dia);
	    printf("\n - Listado de socios con vencimiento el dia %d respectivamente todos los meses:",dia);
	     printf("\n");
	   	rewind(socios);
	fread(&reg, sizeof(reg), 1, socios);  
	while ( !feof(socios) )
	{  
	    
		if(reg.fec.dia == dia)
		{   
			printf("\n\t ");
			puts(reg.ApellidoyNombre);
		   	b=1;
		}
		
		 fread(&reg, sizeof(reg), 1, socios);
	}
	if(b==0)
	printf("\nNo se encuntran socios en este dia");
	printf("\n");
	fclose(socios);
	
}    
void regactividad(FILE *act,FILE*act1)
{ 
 act = fopen("actividades.dat", "rb");
 act1 = fopen("actividadessocio.dat", "a+b");
actividades a;
int numero,actividad,leg,b=0,x;
float horario;
do{
printf ("\n - Ingrese el numero de socio: ");
scanf("%d",&numero);
printf("\n - Ingrese 1 para Zumba, 2 para Spining o 3 para pilates: ");
scanf("%d",&actividad);
printf("\n - Ingrese el legajo del entrenador responsable: ");
scanf("%d",&leg);
printf("\n - Ingrese el horario del inicio de la actividad: ");
scanf("%f",&horario);
rewind(act);
fread(&a, sizeof(actividades), 1, act);
while(!feof(act))
{
	
if (leg==a.legajo && actividad == a.act)
  {  

  	 a.socionum= numero;
  	 a.act=actividad;
  	 a.legajo=leg;
  	 a.horario=horario;
  	printf("\n - Se registro con exito :)");
  	printf("\n");
  	fwrite(&a, sizeof(actividades), 1, act1);
  	b=1;

}
fread(&a, sizeof(actividades), 1, act);
} 	
	  if(b==0)
	  {
	  	printf("\n - El entrenador no se encuentra o no esta disponible en este horario :(");
	  	printf("\n");
	  }
	  b=0;
	  do{
	  printf("\n - Desea agregar otro socio? (SI:1 , NO:0): ");
             scanf("%d" ,&x); 
    }while(x!=0 && x!=1);
		     
           }while (x==1);
        fclose(act);  
		fclose(act1); 
}   
