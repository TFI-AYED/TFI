#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct fecha{
	char dia[60];
	char mes[60];
	char anio[60];
};

struct veterinario{
	char apeynombre[60];
	char matricula[20];
	char dni[20];
	char tel[25];
};

struct usuario{
	char usuario[10];
    char contrasenia[10];
    char apeynom[60];
};
struct mascota{
	char apeynom[60];
	char domicilio[60];
	char dnidue[60];
	char localidad[60];
	fecha fec;
	char peso[60];
	char tel[25];
};
struct turnos{
	char matricula[60];
	fecha fech;
	char dni_due[60];
	char deat[60]; //detalle atencion
};

void verificar(FILE *user){
	veterinario vet;
	usuario u;
	system("cls");
				int cm=0, cn=0,valor,i,n;
				bool b1, b2 , b3, b4, b5,aceptar,band=0,bande=0,primero=0,bucle;
				char aux[20],aux2[20];
				usuario vector[100];
				user=fopen("Usuarios.dat","r");
				printf("\nHa seleccionado 'ingresar usuario', por favor ingrese los datos que se solicitan a continuacion: \n\n");
			    printf("\nIngrese usuario:  ");
				_flushall();
				gets(aux);
				printf("\nIngrese contrasenia: ");
				_flushall();
				gets(aux2);
				b1=false; b2=false; b3=false; b4=false; b5=false;
				/*
				b1==Sea unico para cada usuario*
				b2==Comenzar con una letra minuscula*
				b3==Tener al menos 2 letras mayusculas*
				b4==Tener como maximo 3 digitos*
				b5==Cantidad de caracteres*
				
				*/
				//fread(&u,sizeof(usuario),1,user);
		    	while(b1==false){
    			
    			
    
    				while(b1==false)
	    			{
	    				rewind(user);
	    				fread(&u,sizeof(usuario),1,user);
		    			i=0;
		    			
						while(!feof(user)){
							vector[i]= u;
							i++;
							fread(&u,sizeof(usuario),1,user);
							//printf("hola");
						}
						n=i;
						
						//printf("hola");
							
							band=0;
							for(i=0;i<n;i++)
							{
								if(strcmp(aux,vector[i].usuario)==0 && strcmp(aux2,vector[i].contrasenia)==0)
								{
									printf("\nIngreso con exito al sistema");
									band=1;
									b1=true;
									i=n;
									getch();
								}
								
							
							}
							
							if(band==0)
							{
								system("CLS");
								printf("\nNombre o contraseña incorrectos, ingrese nuevamente: ");
								printf("\nIngrese usuario: ");
								_flushall();
								gets(aux);
								printf("\nIngrese contrasenia: ");
								_flushall();
								gets(aux2);
								b1=false;
							}
					}
					/*
					if(band==0)
					b1=true;*/
				
}
}
void mascotas(FILE *user){
	mascota mas;
	user=fopen("Mascotas.dat","ab");
		fread(&mas,sizeof(mascota),1,user);
		printf("\nUsted selecciono registrar mascota");
		printf("\nIngrese apellido y nombre de la mascota: ");
		_flushall();
		gets(mas.apeynom);
		printf("\nIngrese Domicilio dueño: ");
		_flushall();
		gets(mas.domicilio);
		printf("\nIngrese DNI dueño: ");
		_flushall();
		gets(mas.dnidue);
		printf("\nIngrese localidad: ");
		_flushall();
		gets(mas.localidad);
		printf("\nIngrese Fecha");
		printf("\nIngrese dia: ");
		_flushall();
		gets(mas.fec.dia);
		printf("\nIngrese mes: ");
		_flushall();
		gets(mas.fec.mes);
		printf("\nIngrese anio: ");
		_flushall();
		gets(mas.fec.anio);
		printf("\nIngrese peso: ");
		_flushall();
		gets(mas.peso);
		printf("\nIngrese telefono: ");
		_flushall();
		gets(mas.tel);
		fread(&mas,sizeof(mascota),1,user);
		fwrite(&mas,sizeof(mascota),1,user);
	     fclose(user);
}


main(){
	mascota mas;
	turnos t;
	veterinario vet;
	usuario u;
	int opc,i,band,cant,bandera;
	FILE *p;
	FILE *user;
	
	do{
		system("CLS");
		printf("\nModulo Recepcion");
		printf("\n=====================\n");
		printf("1)Iniciar sesion\n");
		printf("2)Registrar Mascota\n");
		printf("3)Registrar Turno\n");
		printf("4)Listado de Atenciones por Veterinarios y Fecha\n");
		printf("5)Cerrar la Aplicacion\n");
		printf("ELIJA UNA OPCION DEL 1 AL 5: ");
		scanf("%d", &opc);
		_flushall();
		
		system("CLS");
		if(opc==1){
			verificar(user);
		}
		if(opc==2){
			mascotas(user);
		}
}
while(opc>0);
}
