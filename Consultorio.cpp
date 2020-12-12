#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct veterinario
{
	char usuario[10];
    char contrasenia[10];
	char apeynombre[60];
	char matricula[20];
	char dni[20];
	char tel[25];
};




int menu(int &band, char dr[60]);

main()
{
	FILE *user;
	veterinario vet;
	int op, band= 0, b1, b2, i, n;
	char usuar[10], contra[10], dr[60], matr[20], dni[20], tel[25];
	veterinario vector[100];
	
	do
	{
		op=menu(band, dr);
		
		switch(op)
		{
			case 1:
				user=fopen("Veterinarios.dat","r+b");
				if(user==NULL)
				{
					system("cls");
					printf("ERROR. Comunicarse con el administrador.\n\n");
					system("pause");
					system("cls");
				}
				
				else
				{
					if(band==0)
					{
						system("cls");
						printf("Ingrese el nombre de usuario: ");
						gets(usuar);
						_flushall();
						printf("\nIngrese la contraseña: ");
						gets(contra);
						_flushall();
						
						
						rewind(user);
						fread(&vet,sizeof(veterinario),1,user);

						
						i=0;
						while(!feof(user))
						{
							vector[i]= vet;
							i++;
							fread(&vet,sizeof(veterinario),1,user);
						}
						n=i;
						
						
						fclose(user);
						/*
						for(i=0;i<n;i++)
						{
							puts(vector[i].usuario);
						}
						
						system("pause");*/
						
						b1=0;
						while(b1==0)
						{
							for(i=0;i<n;i++)
							{
								if((strcmp(usuar,vector[i].usuario)==0) and (strcmp(contra,vector[i].contrasenia)==0))
								{
									b1= 1;
									strcpy(dr, vector[i].apeynombre);
									strcpy(matr, vector[i].matricula);
									strcpy(dni, vector[i].dni);
									strcpy(tel, vector[i].tel);
									i=n;
								}
							}
							
							if(b1==0)
							{
								printf("\nEl nombre de usuario o la contrasenia son incorrectos, ingrese nuevamente:\n\n");
								printf("Usuario: "); gets(usuar);
								_flushall();
								printf("Contrasenia: "); gets(contra);
								_flushall();
							}
						}
						
						band=1;
						system("cls");
						printf("\tDoctor/a: "); puts(dr);
						printf("\n\tMatricula: "); puts(matr);
						printf("\n\tDNI: "); puts(dni);
						printf("\n\tTelefono: "); puts(tel);
						printf("\n\n");
						system("pause");
						system("cls");
						
						printf("\n\tInicion de sesion exitoso. Bienvenido Dr. "); puts(dr);
						printf("\n\n");
						system("pause");
						system("cls");
					}
					
					else
					{
						band=0;
						system("cls");
						printf("Sesion cerrada.\n\n");
						system("pause");
						system("cls");
					}
				}
				
		}
	}
	while(op!=4);
}




int menu(int &band, char dr[60])
{
	int opcion;
	
	if(band==0)
	{
		printf("\tModulo Consultorio Veterinario\n");
		printf("\t==============================\n\n"); 
	}
	
	else
	{
		printf("\tModulo Consultorio Veterinario      "); puts(dr);
		printf("\n");
		printf("\t==============================\n\n");
	}
	
	if(band==0)
	{
		printf("\t1.- Iniciar Sesion\n");
	}
	
	else
	{
		printf("\t1.- Cerrar Sesion\n");
	}
	printf("\t2.- Visualizar Lista de Espera de Turnos (informe)\n");
	printf("\t3.- Registrar Evolucion de la Mascota\n\n");
	printf("\t4.- Cerrar la aplicacion.\n\n");
	printf("\tIngrese una opcion: ");
	scanf("%d", &opcion);
	_flushall();
	
	return opcion;
}
