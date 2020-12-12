/*Entre linea 590 y 600 fijarse que no anda, dejarlo asi o corregir*/




#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct veterinario{
	char usuario[10];
    char contrasenia[10];
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

void cargar2(FILE *user){
	usuario u;
	system("cls");
				int cm=0, cn=0,valor,i,n;
				bool b1, b2 , b3, b4, b5,aceptar,band=0,bande=0,primero=0,bucle;
				char aux[20];
				usuario vector[100];
				
				user=fopen("Usuarios.dat","rb");
				if(user==NULL)
				primero=1;
				fclose(user);
				
				user=fopen("Usuarios.dat","a+b");
				printf("\nHa seleccionado 'Registrar Usuario Asistente', por favor ingrese los datos que se solicitan a continuacion: \n\n");
				printf("Nombre de usuario \n(Tiene que comenzar con una letra minuscula, tener al menos 2 mayusculas, y no mas de 3 digitos): ");
				
				gets(aux);
				_flushall();
				b1=false; b2=false; b3=false; b4=false; b5=false;
				/*
				b1==Sea unico para cada usuario*
				b2==Comenzar con una letra minuscula*
				b3==Tener al menos 2 letras mayusculas*
				b4==Tener como maximo 3 digitos*
				b5==Cantidad de caracteres*
				
				*/
				//fread(&u,sizeof(usuario),1,user);
		    	while(b1==false && b2==false && b3==false && b4==false && b5==false){
    			
    			
    			if(primero!=1)
    			{
    				while(b1==false)
	    			{
	    				rewind(user);
	    				fread(&u,sizeof(usuario),1,user);
		    			i=0;
		    			
						while(!feof(user)){
							vector[i]= u;
							i++;
							fread(&u,sizeof(usuario),1,user);
						}
						n=i;
						/*
						for(i=0;i<n;i++)
						{
							puts(vector[i].usuario);
						}
						system("pause");*/
							
							band=0;
							for(i=0;i<n;i++)
							{
								if(strcmp(aux,vector[i].usuario)==0)
								{
									printf("\nEste nombre de usuario ya existe, por favor digite otro: ");
									gets(aux);
									_flushall();
									band=1;
									b1=false;
									i=n;
								}
							}
							
							if(band==0)
							{
								b1=true;
							}
					}
				}
    				
							
							
					if(aux[0]>=97 and aux[0]<=122){
						b2=true;
						fread(&u,sizeof(usuario),1,user);
					}
					else{
						b2=false;
						printf("El nombre no comienza con minuscula, por favor digite otro: ");
						_flushall();
						gets(aux);
						fread(&u,sizeof(usuario),1,user);
					}
																													
					for(i=1;i<20;i++){
						if(aux[i]>= 65 and aux[i]<= 90){
							cm++;
						}
					}
					if(cm<2){
						printf("\nNo posee 2 mayusculas o mas, por favor digite otro:  ");
						_flushall();
						gets(aux);
						fread(&u,sizeof(usuario),1,user);
						b3=false;
					}
					else{
						b3=true;
						fread(&u,sizeof(usuario),1,user);
					}
					for(i=0;i<20;i++){
						if(aux[i]=='1'){
							cn++;
						}
						else{
							if(aux[i]=='2'){
								cn++;
							}
							else{
								if(aux[i]=='3'){
									cn++;
								}
								else{
									if(aux[i]=='4'){
										cn++;	
						   			}
						   			else{
						   				if(aux[i]=='5'){
						   					cn++;
									    }
									    else{
									    	if(aux[i]=='6'){
									    		cn++;
											}
											else{
												if(aux[i]=='7'){
													cn++;
												}
												else{
													if(aux[i]=='8'){
														cn++;
													}
													else{
														if(aux[i]=='9'){
															cn++;
														}
														else{
															if(aux[i]=='0'){
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
					}
					
					if(cn>3){
						printf("\nEl maximo de numeros permitidos es 3, por favor digite otro: ",cn);
						_flushall();
						gets(aux);
						b4=false;
						fread(&u,sizeof(usuario),1,user);
					}
					else{
						b4=true;
						fread(&u,sizeof(usuario),1,user);
					}
					if(strlen(aux)>10 || strlen(aux)<6){
						printf("\nEl tama%co del nombre no es valido, por favor digite otro: ",164);
						_flushall();
						gets(aux);
						b5=false;
						fread(&u,sizeof(usuario),1,user);
					}
					else{
						b5=true;
						fread(&u,sizeof(usuario),1,user);
					}				
				} 
					printf("\nIngrese la contrase%ca para el usuario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrase%ca: ",164,164);
				_flushall();
				gets(u.contrasenia);
				aceptar=false;
				
				while(aceptar==false){
				if(strstr(u.contrasenia,"Q")==NULL && strstr(u.contrasenia,"W")==NULL && strstr(u.contrasenia,"E")==NULL && strstr(u.contrasenia,"R")==NULL && strstr(u.contrasenia,"T")==NULL && strstr(u.contrasenia,"Y")==NULL && strstr(u.contrasenia,"U")==NULL && strstr(u.contrasenia,"I")==NULL && strstr(u.contrasenia,"O")==NULL && strstr(u.contrasenia,"P")==NULL && strstr(u.contrasenia,"A")==NULL && strstr(u.contrasenia,"S")==NULL && strstr(u.contrasenia,"D")==NULL && strstr(u.contrasenia,"F")==NULL && strstr(u.contrasenia,"G")==NULL && strstr(u.contrasenia,"H")==NULL && strstr(u.contrasenia,"J")==NULL && strstr(u.contrasenia,"K")==NULL && strstr(u.contrasenia,"L")==NULL && strstr(u.contrasenia,"Ñ")==NULL && strstr(u.contrasenia,"Z")==NULL && strstr(u.contrasenia,"X")==NULL && strstr(u.contrasenia,"C")==NULL && strstr(u.contrasenia,"V")==NULL && strstr(u.contrasenia,"B")==NULL && strstr(u.contrasenia,"N")==NULL && strstr(u.contrasenia,"M")==NULL)
				{
					printf("La contrase%ca no posee mayuscula, ingrese de nuevo la contrase%ca",164,164);
					_flushall();
					gets(u.contrasenia);
				}
				else
				{
					if(strstr(u.contrasenia,"q")==NULL && strstr(u.contrasenia,"w")==NULL && strstr(u.contrasenia,"e")==NULL && strstr(u.contrasenia,"r")==NULL && strstr(u.contrasenia,"t")==NULL && strstr(u.contrasenia,"y")==NULL && strstr(u.contrasenia,"u")==NULL && strstr(u.contrasenia,"i")==NULL && strstr(u.contrasenia,"o")==NULL && strstr(u.contrasenia,"p")==NULL && strstr(u.contrasenia,"a")==NULL && strstr(u.contrasenia,"s")==NULL && strstr(u.contrasenia,"d")==NULL && strstr(u.contrasenia,"f")==NULL && strstr(u.contrasenia,"g")==NULL && strstr(u.contrasenia,"h")==NULL && strstr(u.contrasenia,"j")==NULL && strstr(u.contrasenia,"k")==NULL && strstr(u.contrasenia,"l")==NULL && strstr(u.contrasenia,"ñ")==NULL && strstr(u.contrasenia,"z")==NULL && strstr(u.contrasenia,"x")==NULL && strstr(u.contrasenia,"c")==NULL && strstr(u.contrasenia,"v")==NULL && strstr(u.contrasenia,"b")==NULL && strstr(u.contrasenia,"n")==NULL && strstr(u.contrasenia,"m")==NULL)
					{
						printf("La contrase%ca no posee minuscula, ingrese de nuevo la contrase%ca",164,164);
						_flushall();
						gets(u.contrasenia);
					}
					else
					{
						if(strstr(u.contrasenia,"0")==NULL && strstr(u.contrasenia,"1")==NULL && strstr(u.contrasenia,"2")==NULL && strstr(u.contrasenia,"3")==NULL && strstr(u.contrasenia,"4")==NULL && strstr(u.contrasenia,"5")==NULL && strstr(u.contrasenia,"6")==NULL && strstr(u.contrasenia,"7")==NULL && strstr(u.contrasenia,"8")==NULL && strstr(u.contrasenia,"9")==NULL)
						{
							printf("La contrase%ca no posee numeros, ingrese de nuevo la contrase%ca",164,164);
							_flushall();
							gets(u.contrasenia);
						}
						else
						{
							if(strstr(u.contrasenia,",")!=NULL && strstr(u.contrasenia,".")!=NULL && strstr(u.contrasenia,"-")!=NULL && strstr(u.contrasenia,"á")!=NULL && strstr(u.contrasenia,"é")!=NULL && strstr(u.contrasenia,"í")!=NULL && strstr(u.contrasenia,"ó")!=NULL && strstr(u.contrasenia,"ú")!=NULL && strstr(u.contrasenia,",")!=NULL && strstr(u.contrasenia,"Á")!=NULL && strstr(u.contrasenia,"É")!=NULL && strstr(u.contrasenia,"Í")!=NULL && strstr(u.contrasenia,"Ó")!=NULL && strstr(u.contrasenia,"Ú")!=NULL)
							{
								printf("La contrase%ca posee signos de puntuacion, ingrese de nuevo la contrase%ca",164,164);
								_flushall();
								gets(u.contrasenia);
							}
							else
							{
								if(strlen(u.contrasenia)<6)
								{
									printf("La contrase%ca es muy corta, ingrese de nuevo la contrase%ca",164,164);
									_flushall();
									gets(u.contrasenia);
								}
								else
								{
									if(strlen(u.contrasenia)>32)
									{
										printf("La contrase%ca es muy larga, ingrese de nuevo la contrase%ca",164,164);
										_flushall();
										gets(u.contrasenia);
									}
									else
									{
										for(i=0;i<strlen(u.contrasenia);i++)
										{
											if((u.contrasenia[i+2]==u.contrasenia[i+1]+1) && (u.contrasenia[i+1]==u.contrasenia[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contrase%ca: ",164);
												_flushall();
												gets(u.contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("Contrase%ca aceptada",164);
											
										}
									}
								}
							}
						}
					}
				}
			}
				
			strcpy(u.usuario,aux);
			fwrite(&u,sizeof(usuario),1,user);
			printf("\nEl usuario asistente fue guardado correctamente");
			fclose(user);
			
			system("pause");
			system("cls");
}




main()
{
	veterinario vet;
	int opc,i,band,cant,bandera;
	FILE *p;
	FILE *user;
	
	do{
		system("CLS");
		printf("\nModulo Administracion");
		printf("\n=====================\n");
		printf("1)Registrar Veterinario\n");
		printf("2)Registrar Usuario Asistente\n");
		printf("3)Atenciones por Veterinarios\n");
		printf("4)Ranking de Veterinarios por Atenciones\n");
		printf("5)Cerrar la Aplicacion\n");
		printf("ELIJA UNA OPCION DEL 1 AL 5: ");
		scanf("%d", &opc);
		_flushall();
		
		system("CLS");
			if(opc==1){
			system("cls");
				int cm=0, cn=0,valor,i,n;
				bool b1, b2 , b3, b4, b5,aceptar,band=0,primero=0,bande,bandera,bucle;
				char aux[20],aux2[20];
				veterinario vector[100];

				
				user=fopen("Veterinarios.dat","rb");
				if(user==NULL)
				primero=1;
				fclose(user);
				
				user=fopen("Veterinarios.dat","a+b");
				printf("\nHa seleccionado 'Registrar Veterinario', por favor ingrese los datos que se solicitan a continuacion: \n\n");
				printf("Nombre de usuario \n(Tiene que comenzar con una letra minuscula, tener al menos 2 mayusculas, y no mas de 3 digitos): ");
				
				gets(aux);
				_flushall();
				b1=false; b2=false; b3=false; b4=false; b5=false;
				/*
				b1==Sea unico para cada usuario*
				b2==Comenzar con una letra minuscula*
				b3==Tener al menos 2 letras mayusculas*
				b4==Tener como maximo 3 digitos*
				b5==Cantidad de caracteres*
				
				*/
				//fread(&u,sizeof(usuario),1,user);
		    	while(b1==false && b2==false && b3==false && b4==false && b5==false){
    			
    			
    			if(primero!=1)
    			{
    				while(b1==false)
	    			{
	    				rewind(user);
	    				fread(&vet,sizeof(veterinario),1,user);
		    			i=0;
		    			
						while(!feof(user)){
							vector[i] = vet;
							i++;
							fread(&vet,sizeof(veterinario),1,user);
						}
						n=i;
						/*
						for(i=0;i<n;i++)
						{
							puts(vector[i].apeynombre);
						}
						system("pause");*/
							
							band=0;
							for(i=0;i<n;i++)
							{
								if(strcmp(aux,vector[i].usuario)==0)
								{
									printf("\nEste nombre de usuario ya existe, por favor digite otro: ");
									gets(aux);
									_flushall();
									band=1;
									b1=false;
									i=n;
								}
								
							
							}
							
							if(band==0)
							{
								b1=true;
							}
					}
				}
					
							
							
					if(aux[0]>=97 and aux[0]<=122){
						b2=true;
						fread(&vet,sizeof(veterinario),1,user);
					}
					else{
						b2=false;
						printf("El nombre no comienza con minuscula, por favor digite otro: ");
						_flushall();
						gets(aux);
						fread(&vet,sizeof(veterinario),1,user);
					}
																													
					for(i=1;i<20;i++){
						if(aux[i]>= 65 and aux[i]<= 90){
							cm++;
						}
					}
					if(cm<2){
						printf("\nNo posee 2 mayusculas o mas, por favor digite otro:  ");
						_flushall();
						gets(aux);
						fread(&vet,sizeof(veterinario),1,user);
						b3=false;
					}
					else{
						b3=true;
						fread(&vet,sizeof(veterinario),1,user);
					}
					for(i=0;i<20;i++){
						if(aux[i]=='1'){
							cn++;
						}
						else{
							if(aux[i]=='2'){
								cn++;
							}
							else{
								if(aux[i]=='3'){
									cn++;
								}
								else{
									if(aux[i]=='4'){
										cn++;	
						   			}
						   			else{
						   				if(aux[i]=='5'){
						   					cn++;
									    }
									    else{
									    	if(aux[i]=='6'){
									    		cn++;
											}
											else{
												if(aux[i]=='7'){
													cn++;
												}
												else{
													if(aux[i]=='8'){
														cn++;
													}
													else{
														if(aux[i]=='9'){
															cn++;
														}
														else{
															if(aux[i]=='0'){
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
					}
					
					if(cn>3){
						printf("\nEl maximo de numeros permitidos es 3, por favor digite otro: ",cn);
						_flushall();
						gets(aux);
						b4=false;
						fread(&vet,sizeof(veterinario),1,user);
					}
					else{
						b4=true;
						fread(&vet,sizeof(veterinario),1,user);
					}
					if(strlen(aux)>10 || strlen(aux)<6){
						printf("\nEl tama%co del nombre no es valido, por favor digite otro: ",164);
						_flushall();
						gets(aux);
						b5=false;
						fread(&vet,sizeof(veterinario),1,user);
					}
					else{
						b5=true;
						fread(&vet,sizeof(veterinario),1,user);
					}				
				} 
				
			
				
					printf("\nIngrese la contrase%ca para el usuario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrase%ca: ",164,164);
				_flushall();
				gets(vet.contrasenia);
				aceptar=false;
				
				while(aceptar==false){
				if(strstr(vet.contrasenia,"Q")==NULL && strstr(vet.contrasenia,"W")==NULL && strstr(vet.contrasenia,"E")==NULL && strstr(vet.contrasenia,"R")==NULL && strstr(vet.contrasenia,"T")==NULL && strstr(vet.contrasenia,"Y")==NULL && strstr(vet.contrasenia,"U")==NULL && strstr(vet.contrasenia,"I")==NULL && strstr(vet.contrasenia,"O")==NULL && strstr(vet.contrasenia,"P")==NULL && strstr(vet.contrasenia,"A")==NULL && strstr(vet.contrasenia,"S")==NULL && strstr(vet.contrasenia,"D")==NULL && strstr(vet.contrasenia,"F")==NULL && strstr(vet.contrasenia,"G")==NULL && strstr(vet.contrasenia,"H")==NULL && strstr(vet.contrasenia,"J")==NULL && strstr(vet.contrasenia,"K")==NULL && strstr(vet.contrasenia,"L")==NULL && strstr(vet.contrasenia,"Ñ")==NULL && strstr(vet.contrasenia,"Z")==NULL && strstr(vet.contrasenia,"X")==NULL && strstr(vet.contrasenia,"C")==NULL && strstr(vet.contrasenia,"V")==NULL && strstr(vet.contrasenia,"B")==NULL && strstr(vet.contrasenia,"N")==NULL && strstr(vet.contrasenia,"M")==NULL)
				{
					printf("La contrase%ca no posee mayuscula, ingrese de nuevo la contrase%ca",164,164);
					_flushall();
					gets(vet.contrasenia);
				}
				else
				{
					if(strstr(vet.contrasenia,"q")==NULL && strstr(vet.contrasenia,"w")==NULL && strstr(vet.contrasenia,"e")==NULL && strstr(vet.contrasenia,"r")==NULL && strstr(vet.contrasenia,"t")==NULL && strstr(vet.contrasenia,"y")==NULL && strstr(vet.contrasenia,"u")==NULL && strstr(vet.contrasenia,"i")==NULL && strstr(vet.contrasenia,"o")==NULL && strstr(vet.contrasenia,"p")==NULL && strstr(vet.contrasenia,"a")==NULL && strstr(vet.contrasenia,"s")==NULL && strstr(vet.contrasenia,"d")==NULL && strstr(vet.contrasenia,"f")==NULL && strstr(vet.contrasenia,"g")==NULL && strstr(vet.contrasenia,"h")==NULL && strstr(vet.contrasenia,"j")==NULL && strstr(vet.contrasenia,"k")==NULL && strstr(vet.contrasenia,"l")==NULL && strstr(vet.contrasenia,"ñ")==NULL && strstr(vet.contrasenia,"z")==NULL && strstr(vet.contrasenia,"x")==NULL && strstr(vet.contrasenia,"c")==NULL && strstr(vet.contrasenia,"v")==NULL && strstr(vet.contrasenia,"b")==NULL && strstr(vet.contrasenia,"n")==NULL && strstr(vet.contrasenia,"m")==NULL)
					{
						printf("La contrase%ca no posee minuscula, ingrese de nuevo la contrase%ca",164,164);
						_flushall();
						gets(vet.contrasenia);
					}
					else
					{
						if(strstr(vet.contrasenia,"0")==NULL && strstr(vet.contrasenia,"1")==NULL && strstr(vet.contrasenia,"2")==NULL && strstr(vet.contrasenia,"3")==NULL && strstr(vet.contrasenia,"4")==NULL && strstr(vet.contrasenia,"5")==NULL && strstr(vet.contrasenia,"6")==NULL && strstr(vet.contrasenia,"7")==NULL && strstr(vet.contrasenia,"8")==NULL && strstr(vet.contrasenia,"9")==NULL)
						{
							printf("La contrase%ca no posee numeros, ingrese de nuevo la contrase%ca",164,164);
							_flushall();
							gets(vet.contrasenia);
						}
						else
						{
							if(strstr(vet.contrasenia,",")!=NULL && strstr(vet.contrasenia,".")!=NULL && strstr(vet.contrasenia,"-")!=NULL && strstr(vet.contrasenia,"á")!=NULL && strstr(vet.contrasenia,"é")!=NULL && strstr(vet.contrasenia,"í")!=NULL && strstr(vet.contrasenia,"ó")!=NULL && strstr(vet.contrasenia,"ú")!=NULL && strstr(vet.contrasenia,",")!=NULL && strstr(vet.contrasenia,"Á")!=NULL && strstr(vet.contrasenia,"É")!=NULL && strstr(vet.contrasenia,"Í")!=NULL && strstr(vet.contrasenia,"Ó")!=NULL && strstr(vet.contrasenia,"Ú")!=NULL)
							{
								printf("La contrase%ca posee signos de puntuacion, ingrese de nuevo la contrase%ca",164,164);
								_flushall();
								gets(vet.contrasenia);
							}
							else
							{
								if(strlen(vet.contrasenia)<6)
								{
									printf("La contrase%ca es muy corta, ingrese de nuevo la contrase%ca",164,164);
									_flushall();
									gets(vet.contrasenia);
								}
								else
								{
									if(strlen(vet.contrasenia)>32)
									{
										printf("La contrase%ca es muy larga, ingrese de nuevo la contrase%ca",164,164);
										_flushall();
										gets(vet.contrasenia);
									}
									else
									{
										for(i=0;i<strlen(vet.contrasenia);i++)
										{
											if((vet.contrasenia[i+2]==vet.contrasenia[i+1]+1) && (vet.contrasenia[i+1]==vet.contrasenia[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contrase%ca: ",164);
												_flushall();
												gets(vet.contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("Contrase%ca aceptada",164);
											
										}
									}
								}
							}
						}
					}
				}
			}
			
				printf("\nIngrese numero de matricula: ");
					_flushall();
					gets(aux2);
					rewind(user);
					while(!feof){
					fread(&vet,sizeof(veterinario),1,user);
					if(strcmp(aux2,vet.matricula)==0){
						printf("\nEste matricula ya existe, por favor digite otro: ");//Arreglar??
									_flushall();
									gets(aux2);
					
					}
					
		    			
				
				}
	
								

			strcpy(vet.matricula,aux2);
			printf("\nIngrese nombre y apellido del veterinario: ");
			_flushall();
			gets(vet.apeynombre);
			strupr(vet.apeynombre);
			printf("\nIngrese dni: ");
			_flushall();
			gets(vet.dni);
			printf("\nIngrese telefono: ");
			_flushall();
			gets(vet.tel);
			strcpy(vet.usuario,aux);
			fwrite(&vet,sizeof(veterinario),1,user);
			printf("\nEl veterinario fue guardado correctamente.");
			fclose(user);
			
			system("pause");
			system("cls");
			}
		    if(opc==2){
		    	cargar2(user);
		    }
			if(opc==3){
				break;
			}
		    if(opc==4){
		    	break;
		    }
		    if(opc==5){
		    	return 0;
		    }
			if(opc>5){printf("LA OPCION INGRESADA ES INCORRECTA"); getch();}
		}
		while(opc>0);
	
}
