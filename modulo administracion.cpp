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

struct usuario{
	char username[10];
	char password[10];
	char ApellidoyNombre[60];
};
struct actividades
{
    int act;
	int legajo;
	int socionum;
	float horario;
	float horariofin;
	
};
struct mayor
{
	int legajo;
	int canthora;
};
int dibujarMenu();
void regrecep(bool &admin);
void regentrenador();
bool checklogin();
void actgym(FILE *act,FILE*cargahora);
float pagoentenador(FILE *entrenadores);
void ranking(FILE*cargahora);

main(){
	FILE *cargahora=fopen("cargahora.dat","a+b");
	FILE *act = fopen("actividades.dat", "a+b");
	FILE *entrenadores = fopen("entrenadores.dat", "rb");
	bool login = false;
	bool admin = false;
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	system("cls");
					login = checklogin();
				 	 if(login == true) {
						printf("\n -Sesion iniciada correctamente- \n\n");
						}
						else {
						printf("\nLoguearse es requerido para esta accion!\n\n");}
					 break;
		    case 2:  if(admin == true)
						{
							login = checklogin();
							if(login == true) regrecep(admin);
						}
					else regrecep(admin);
					break;
			case 3: if(login == true)
						{
							regentrenador();
						}
					else {
						printf("\nLoguearse es requerido para esta accion!\n\n");} ;
					break;
					 
					
			case 4:  if(login == true)
						{
							actgym(act,cargahora);
						}
					else {
						printf("\nLoguearse es requerido para esta accion!\n\n");} ;
					break;
					
			case 5:  if(login == true)
						{
							pagoentenador(entrenadores);
						}
					else {
						printf("\nLoguearse es requerido para esta accion!\n\n");} ;
					break;
			case 6: if(login == true)
			     	{
			     		ranking(cargahora);
					 }
					 else {
						printf("\nLoguearse es requerido para esta accion!\n\n");} ;
					break;
			}
		printf("\n");
		system("pause");
	}while(opc != 7);
	exit(1);}
int dibujarMenu(){
	system("cls");
	printf("\n\t\t\t***************** Modulo Administracion *****************\n");
	printf("\n\t\t\t 1) Iniciar Sesion");
	printf("\n\t\t\t 2) Registrar usuario");	
	printf("\n\t\t\t 3) Registrar entrenador");
	printf("\n\t\t\t 4) Registrar actividades del gym");
	printf("\n\t\t\t 5) Calcular el pago del entrenador");
	printf("\n\t\t\t 6) Entrenador con mayor carga horaria");
	printf("\n\t\t\t 7) Cerrar la aplicacion");
	printf("\n\n\t\t\t  Ingrese la opcion deseada: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}
void regrecep(bool &admin){
	FILE *RECEP = fopen("usuarios.dat", "a+b");
	system("cls");
	usuario us;
	bool u = false;
	int mayus=0, digitos=0, opcion, x;

	system("cls");
	if(admin == false)
	{
		printf("\n\t\t\t*CREAR USUARIO*");
	
		admin = true;
		printf("\n\t\n\n");
		system("pause");
	}

	
	do{

		do
		{	system("cls");
			printf("\t\t\tCONDICIONES:\n\n");
			printf(" - Entre 6 y 10 caracteres\n - Letras, numeros, simbolos (+,-,/,*,?,�,!,�)\n - Comenzar con letra minuscula\n - Tener al menos 2 letras mayusculas\n - Tener como maximo 3 digitos\n");
			printf("\n\nCree nombre de usuario ->  ");
			_flushall();	
			gets(us.username);
			if(strlen(us.username)>= 6 && strlen(us.username) <= 10)
			{
				if(us.username[0] >= 97 && us.username[0] <= 122)
				{
					for(int i=0; i < strlen(us.username); i++)
					{
						if (us.username[i] >=65 && us.username[i] <=90) mayus++;
						if (us.username[i] == 43 || us.username[i] == 45 || us.username[i] == 47 || us.username[i] == 42 ||
						 us.username[i] == 63 || us.username[i] == 168 || us.username[i] == 173 || us.username[i] == 33 || us.username[i] >= 48 || us.username[i] <= 57)
						 digitos++;
						 if(mayus >= 2 && digitos <= 3)
						 {
						 	if(us.username[i] >= 65 || us.username[i] <= 90 || us.username[i] >= 97 || us.username[i] <= 122 || us.username[i] >= 48 || us.username[i] <= 57 || us.username[i] == 43 || 
								 us.username[i] == 45 || us.username[i] == 47 || us.username[i] == 42 ||
								 us.username[i] == 63 || us.username[i] == 168 || us.username[i] == 173 || us.username[i] == 33)
								 {
								 	u = true;
								 }
						 }
					}
				}
			}
		}while(u == false);
		
		char contra[15], auxc[15], ull[10];
		int cmin=0, cmay=0, cnum=0, a, b, c1, lon1;
		bool ecar=false, econs=false, error=false, eletconsec=false;
		
		system("cls");
		printf("\t\t\tCONDICIONES PARA CONTRASENA");
		printf("\n\n - Contener al menos una letra mayuscula, una minuscula y un numero\n - No contener ningun caracter de puntuacion, ni acentos, ni espacios\n - Solo contener caracteres alfanumericos\n - Tener entre 6 y 32 caracteres\n - No tener mas de 3 caracteres consecutivos\n - No tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente)\n");
		_flushall();
		
		do{	
		printf("\n- Ingrese su Contrasena: ");
		gets(contra);
		lon1 = strlen(contra);
            strcpy(auxc,contra);
            strlwr(auxc);
			
			
            if (lon1>=6 && lon1<=32)
            {  
                for (int i = 0; i < lon1; i++)
                {

                    if((contra[i]>='a') || (contra[i]<'z'))
                    {
                        cmin++;

                    }

                    if ((contra[i]>='A') || (contra[i]<'Z'))
                    {
                        cmay++;
      
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        cnum++;

                    }
                    

                    if ((contra[i]<47 || contra[i]>58) && (contra[i]<65 || contra[i]>90) && (contra[i]<97 || contra[i]>122))
                    {

                        ecar=false;
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        a=contra[i];
                        b=a+1;
                        c1=a+2;

                        if (contra[i+1]==b && contra[i+2]==c1)
                        {
                            econs=true;
 
                        }                    
                    } 
                    
                    
                    if(auxc[i]>96 && auxc[i]<123)
                    {                    
                        a=auxc[i];
                        b=a+1;
                        if(auxc[i+1]==b)
                        {
                            printf("\nLetra 1: %c",auxc[i]);
                            printf("\nLetra: %c",auxc[i+1]);
                            eletconsec=true;
                        }
                    }               
                }			

                if (cmin==1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cmay<1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cnum<1)
                {
                    printf("\nDEBE TENER AL MENOS 1 NUMERO!!\n");
                    error=true;
                }
                

                if(ecar==true)
                {
                    printf("\nDEBE CONTENER SOLO CARACTERES ALFANUMERICOS!!\n");
                    error=true;
                }
                
                
 
                if (econs==true)
                {
                    printf("\nNO DEBE TENER MAS DE 3 NUMEROS CONSECUTIVOS!!\n");
                    error=true;                
                }
                

                if (eletconsec==true)
                {
                    printf("\nNO DEBE TENER LETRAS CONSECUTIVAS!!\n");
                    error=true;
                }
            }
            
            else error=true;
            
        }while (error==true);

        if (error==false)
        {       
            strcpy(us.password, contra);
            printf("\n- Ingrese el apellido y nombre: ");        
            _flushall();
            gets(us.ApellidoyNombre);
			fwrite(&us, sizeof(usuario), 1, RECEP);
            do{
                printf("\n- Desea agregar otro usuario? (SI:1 , NO:0): ");
                scanf("%d" ,&x);
            }while (x!=0 && x!=1);
        }
        
    	printf("\n");
    }while (x==1);
	

	fclose(RECEP);
}
bool checklogin()
{
	usuario check;
	int valor, valor2;
	char usu[10], pass[10];
	bool login = false;
	FILE *RECEP = fopen("usuarios.dat", "rb");
	if(RECEP == NULL)
	{
		printf("\nusuarios.dat no ha sido creado\n\n");
		system("pause");
		exit(1);
	}
	
	system("cls");
	printf("* Inicio de Sesion:* \n\n");
	printf("- Ingrese nombre de usuario: ");
	_flushall();
	gets(usu);
	
	printf("\n- Ingrese contrasena: ");
	gets(pass);
	
	fread(&check, sizeof(usuario), 1, RECEP);
	while(!feof(RECEP))
	{
		valor = strcmp(usu, check.username);
		valor2 = strcmp(pass, check.password);
		if(valor == 0 and valor2 == 0)
			{
				login = true;
			}
	fread(&check, sizeof(usuario), 1, RECEP);
	}
	
	return login;	
	fclose(RECEP);
}
void regentrenador()
{
	FILE *entrenadores = fopen("entrenadores.dat", "a+b");
	entrenador entre;
	int mayus=0, digitos=0, x;

	system("cls");
	
	do{
		do{
			printf("\tIngrese  el legajo entrenador (max. 4 digitos): ");
			scanf("%d", &entre.legajo);
		}while(entre.legajo > 9999);

		
		char contra[15], auxc[15], ull[10];
		int cmin=0, cmay=0, cnum=0, a, b, c1, lon1;
		bool ecar=false, econs=false, error=false, eletconsec=false;
		
		system("cls");
		printf("\t\t\tCONDICIONES PARA CONTRASENA");
		printf("\n\n- Contener al menos una letra mayuscula, una minuscula y un numero\n - No contener ningun caracter de puntuacion, ni acentos, ni espacios\n - Solo contener caracteres alfanumericos\n - Tener entre 6 y 32 caracteres\n - No tener mas de 3 caracteres consecutivos\n - No tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente)\n");
		_flushall();
		
		do{	
		printf("\nIngrese su contrasena ->  ");
		gets(contra);
		lon1 = strlen(contra);
            strcpy(auxc,contra);
            strlwr(auxc);

            if (lon1>=6 && lon1<=32)
            { 	
                for (int i = 0; i < lon1; i++)
                {

                    if((contra[i]>='a') || (contra[i]<'z'))
                    {
                        cmin++;

                    }

                    if ((contra[i]>='A') || (contra[i]<'Z'))
                    {
                        cmay++;
      
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        cnum++;

                    }
                    

                    if ((contra[i]<47 || contra[i]>58) && (contra[i]<65 || contra[i]>90) && (contra[i]<97 || contra[i]>122))
                    {

                        ecar=true;
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        a=contra[i];
                        b=a+1;
                        c1=a+2;

                        if (contra[i+1]==b && contra[i+2]==c1)
                        {
                            econs=true;
 
                        }                    
                    } 
                    

                    
                    if(auxc[i]>96 && auxc[i]<123)
                    {                    
                        a=auxc[i];
                        b=a+1;
                        if(auxc[i+1]==b)
                        {
                            printf("\nLetra 1: %c",auxc[i]);
                            printf("\nLetra: %c",auxc[i+1]);
                            eletconsec=true;
                        }
                    }               
                }			

                if (cmin==1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cmay<1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cnum<1)
                {
                    printf("\nDEBE TENER AL MENOS 1 NUMERO!!\n");
                    error=true;
                }
                

                if(ecar==true)
                {
                    printf("\nDEBE CONTENER SOLO CARACTERES ALFANUMERICOS!!\n");
                    error=true;
                }
                
                
 
                if (econs==true)
                {
                    printf("\nNO DEBE TENER MAS DE 3 NUMEROS CONSECUTIVOS!!\n");
                    error=true;                
                }
                

                if (eletconsec==true)
                {
                    printf("\nNO DEBE TENER LETRAS CONSECUTIVAS!!\n");
                    error=true;
                }     
            }
            
            else error=true;
            
        }while (error==true);

        if (error==false)
        {       
            strcpy(entre.password, contra);
            printf("\n- Ingrese el apellido y nombre: ");        
            _flushall();
            gets(entre.ApellidoyNombre);
            printf("\n Dias de atencion: ");
			gets(entre.dia);
			
			
			fwrite(&entre, sizeof(entrenador), 1, entrenadores);
				system("cls");
            do{
                printf("\n- Desea agregar otro entrenador ? (SI:1 , NO:0): ");
                scanf("%d" ,&x);
            }while (x!=0 && x!=1);}
        
    		printf("\n");
   		 }while (x==1);
	
	
	fclose(entrenadores);
}
void actgym(FILE *act, FILE*cargahora)
{
	fclose(act);
    act = fopen("actividades.dat", "a+b");
    cargahora=fopen("cargahora.dat", "a+b");
	system("cls");
	actividades actgym;
	mayor r;
	int x;
	do
	{
	printf("\n - Ingrese 1 para Zumba, 2 para Spining o 3 para pilates: ");
	scanf("%d",&actgym.act); 
	if(actgym.act == 1 or actgym.act == 2 or actgym.act == 3) 
	{
	printf("\n - Ingrese el legajo del entrenador a cargo: ");
	scanf("%d",&actgym.legajo);
	printf("\n - Ingrese el horario del inicio de la actividad: ");
	scanf("%f",&actgym.horario);
	printf("\n - Ingrese el horario del fin de la actividad: ");
	scanf("%f",&actgym.horariofin);
	r.legajo=actgym.legajo;
	r.canthora++;
	fwrite(&r, sizeof(mayor), 1, cargahora);
	fwrite(&actgym, sizeof(actividades), 1, act);
    }
    else 
    printf("\n - Ingrese un numero correcto por favor");
	do{
	printf("\n - Desea agregar otra actividad? (SI:1 , NO:0): ");
    scanf("%d" ,&x);
    }while (x!=0 && x!=1);
    printf("\n");
    }while(x==1);
    fclose(act);
    fclose(cargahora);
}
float pagoentenador(FILE *entrenadores)
{ 
	fclose(entrenadores);
	entrenadores = fopen("entrenadores.dat", "rb");
	system("cls");
	entrenador ent;
	int legajo,cantz,cants,cantp,pago,pagofinal;
	int cantidad=0;
	printf("\n - Ingrese el legajo del entrenador/a: ");
	scanf("%d",&legajo);
    rewind(entrenadores);
	fread(&ent, sizeof(entrenador), 1, entrenadores);
	while(!feof(entrenadores))
	{  
		if(legajo == ent.legajo)
		{
			system("cls");
			printf("\n - Bienvenido/a %s!", ent.ApellidoyNombre);
			printf("\n\n - Cantidad de personas en la act Zumba: ");
			_flushall();
			scanf("%d",&cantz);
			printf("\n - Cantidad de personas en la act Spining: ");
			_flushall();
			scanf("%d",&cants);
			printf("\n - Cantidad de personas en la act Pilates: ");
			_flushall();
			scanf("%d",&cantp);
			cantidad= cantz + cants + cantp;
			printf("\n -Cantidad total de personas a cargo del/la profe %s es: %d",ent.ApellidoyNombre,cantidad);
			printf("\n");
			printf("\n - Tarifa por persona: ");
			scanf("%d",&pago);
			pagofinal=cantidad*pago;
			printf("\n - Pago total del/la entrenador/a %s es %d: ",ent.ApellidoyNombre,pagofinal);
			printf("\n");
		}
		else 
		{
			printf("\n - Numero de legajo no registrado");
			printf("\n");
		}
	
	fread(&ent, sizeof(entrenador), 1, entrenadores);
	}	
	fclose(entrenadores);
	}	
void ranking( FILE *cargahora)
{  
    int aux=0;
    int leg;
    cargahora=fopen("cargahora.dat", "rb");
    mayor r;
    fread(&r, sizeof(mayor), 1, cargahora);
	while(!feof(cargahora))
	{     
	
		if(aux<r.canthora)
		{   
			aux=r.canthora;
			leg=r.legajo;
		}
		 fread(&r, sizeof(mayor), 1, cargahora);
	}
	system("cls");
    printf("\n - El entrenador con mayor carga horaria es *%d* con %d horas", leg,aux);
	printf("\n");
	fclose(cargahora);
 }	
    			 
					 
					 
					 
					 
					 
					 
					 
					 			 
