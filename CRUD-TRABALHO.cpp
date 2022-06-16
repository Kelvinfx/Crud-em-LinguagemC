/*BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
/*MÓDULO DE LINHA*/
void linha(){
	int i;
	for (i=0; i<120; i++){
		printf("-");
	}
}
/*USO DO TYPEDEF STRUCT PARA O REGISTRO*/
typedef struct{
	char nome1[40], nome2[40];
	int  passagem, ativo, codigo, destino1;
	char destino;
} Viagem;

Viagem viagem[MAX];

void menu();
void cadastrar();
void remover();
void pesquisar();
void alterar();
void listar();
/* MAIN */
int main(int argc, char const *argv[]){
	linha();
	menu();
	
	return 0;
}
/* MENU -- TELA INICIAL DO PROGRAMA*/
void menu(){
	system("cls");
	int op;
	do{
	system("cls");
	linha();
	printf("\n                                         BEM-VINDO AO PASSAGEM DE ONIBUS.COM\n");
	linha();
	printf("\n                                            1- ...Cadastrar Passageiro...");
	printf("\n                                            2-  ...Remover Passageiro...");
	printf("\n                                            3- ...Pesquisar Passageiro...");
	printf("\n                                            4-  ...Alterar Passageiro...");
	printf("\n                                            5-  ...Listar Passageiros...");
	printf("\n                                            0-         ...SAIR...\n");

	linha();
	printf("\n                                   Digite o numero correspondente com o que voce deseja: ");
	scanf("%d", &op);
	linha();
	getchar();
	/*SWITCH para mudar a interface*/
	switch(op){
		case 1 :
			cadastrar();
		break;
		case 2 :
			remover();
		break;
		case 3 :
			pesquisar();
		break;
		case 4 :
			alterar();
		break;
		case 5 :
			listar();
		break;
	}
	getchar();
	}while(op!=0);
	
	

}
/*TELA DE CADASTRO*/
void cadastrar(){
	
    char nome1[40], nome2[40];
    int  i, op, destino, passagem, codigo;
    
	do{
		
		system("cls");
		linha();
		printf("\n                                                 ---CADASTRO DO CLIENTE---\n");
		linha();
		printf("\n     Digite o codigo do cliente: ");
		scanf("%d", &codigo);
		printf("     Digite seu primeiro nome..: ");
		scanf("%s", nome1);
		printf("     Digite seu segundo nome...: ");
		scanf("%s", nome2);
		printf("     Destino ( 1-PARAIBA, 2-BAHIA, 3-ALAGOAS, 4-CEARA, 5-RIO GRANDE DO NORTE ): ");
		scanf("%d", &destino);
		
		if (destino==1){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &passagem);
		switch(passagem){
			case 1 :
				passagem=120;
			break;
			case 2 :
				passagem=150;
			break;
		}
	    }else
	    
		if(destino==2){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &passagem);
		switch(passagem){
			case 1 :
				passagem=300;
			break;
			case 2 :
				passagem=340;
			break;
		}
		}
		else
		
		if(destino==3){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &passagem);
		switch(passagem){
			case 1 :
				passagem=200;
			break;
			case 2 :
				passagem=240;
			break;
		}
		}
		else
		if(destino==4){
		
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &passagem);
		switch(passagem){
			case 1 :
				passagem=320;
			break;
			case 2 :
				passagem=360;
			break;
		}
		}
		else
		if(destino==5){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &passagem);
		switch(passagem){
			case 1 :
				passagem=290;
			break;
			case 2 :
				passagem=330;
			break;
		}
		}
		
	    for(i=0; i<MAX; i++){
	    	
	    	if(viagem[i].ativo==0){
	    	
	    	strcpy(viagem[i].nome1,nome1);
	    	strcpy(viagem[i].nome2,nome2);
	    	viagem[i].passagem = passagem;
	        viagem[i].passagem = passagem;
	    	viagem[i].destino = destino;
	    	viagem[i].codigo = codigo;
	    	viagem[i].ativo=1;
	    	break;
	    }
		}
		linha();
		printf("\n     1-Para continuar cadastrando ou 0-Para sair: ");
		scanf("%d", &op);
		
	}while(op!=0);
}
/*FUNÇÃO DE REMOVER UM OU MAIS PASSAGEIRO(S)*/
void remover(){
	
	int codigor, i;
	listar();
	printf("\n     Digite o codigo do passageiro que quer remover: ");
	scanf("%d", &codigor);
	
	codigor--;
	viagem[codigor].ativo=0;
	linha();
	printf("\n                                     PASSAGEIRO REMOVIDO COM SUCESSO!\n");
	linha();
	getchar();
	
}
/*FUNÇÃO PARA PESQUISAR UM PASSAGEIRO*/
void pesquisar(){
	int op, i;
	int codigop;
	do{
	system("cls");
	linha();
	printf("\n                                                    --PESQUISA DE PASSAGEIRO--\n");
	linha();
	printf("\n     Digite o codigo do passageiro: ");
	scanf("%d", &codigop);

	linha();
	for (i=0; i<MAX; i++){
	if(viagem[i].codigo == codigop){
	
		printf("\n     Seu codigo : %d", viagem[i].codigo);

		printf("\n     Nome: %s %s", viagem[i].nome1, viagem[i].nome2);
		printf("\n     Valor da passagem: R$ %d", viagem[i].passagem);
		
		switch(viagem[i].destino){
			case 1 :
				printf("\n     Destino: PARAIBA\n");
			break;
			case 2 :
				printf("\n     Destino: BAHIA\n");
			break;
            case 3 :
				printf("\n     Destino: ALAGOAS\n");
			break;		
			case 4 :
				printf("\n     Destino: CEARA\n");
			break;	
			case 5 :
				printf("\n     Destino: RIO GRANDE DO NORTE\n");
			break;	
			}
			
	    switch(viagem[i].passagem){
	    	case 120 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 150 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 300 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 340 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 200 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 240 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 320 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 360 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 290 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 330 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
		    }
		    linha();
	   }
	}
	if(viagem[i].codigo != codigop){
		printf("\n     PASSAGEIRO NAO ENCONTRADO!\n");
		linha();
		getchar();
	}
	
	printf("\n     Digite 1 se quiser persquisar outro passageiro ou 0 para sair: ");
	scanf("%d", &op);
  }while(op!=0);
}
/*FUNÇÃO DE ALTERAR O DESTINO DO PASSAGEIRO*/
void alterar(){
	int codigod, op, i, sn, Npassagem, Ndestino;
	
	do{
	
		system("cls");
		listar();
		printf("\n");
		linha();
		printf("\n                                                   ALTERAR PASSAGEIRO\n");
		linha();
		printf("\n     Digite o codigo do passageiro: ");
		scanf("%d", &codigod);
		
		if(viagem[MAX].codigo == codigod){
			printf("     Deseja alterar o destino do passageiro?");
			printf("(1-SIM ou 0-NAO): ");
			scanf("%d", &sn);
			if(sn==1){
				printf("     Destino ( 1-PARAIBA, 2-BAHIA, 3-ALAGOAS, 4-CEARA, 5-RIO GRANDE DO NORTE ): ");
		scanf("%d", &Ndestino);
		
		if (Ndestino==1){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &Npassagem);
		switch(Npassagem){
			case 1 :
				Npassagem=120;
			break;
			case 2 :
				Npassagem=150;
			break;
		}
	    }else
	    
		if(Ndestino==2){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &Npassagem);
		switch(Npassagem){
			case 1 :
				Npassagem=300;
			break;
			case 2 :
				Npassagem=340;
			break;
		}
		}
		else
		
		if(Ndestino==3){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &Npassagem);
		switch(Npassagem){
			case 1 :
				Npassagem=200;
			break;
			case 2 :
				Npassagem=240;
			break;
		}
		}
		else
		if(Ndestino==4){
		
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &Npassagem);
		switch(Npassagem){
			case 1 :
				Npassagem=320;
			break;
			case 2 :
				Npassagem=360;
			break;
		}
		}
		else
		if(Ndestino==5){
			
		printf("     Tipo de passagem ( 1-CONVENCIONAL, 2-EXECUTIVO ): ");
		scanf("%d", &Npassagem);
		switch(Npassagem){
			case 1 :
				Npassagem=290;
			break;
			case 2 :
				Npassagem=330;
			break;
		}
		}
		
	    
	    			for(i=0; i<MAX; i++){
	    	if(viagem[i].codigo==codigod){
	    
	    			
	    	viagem[i].passagem = Npassagem;
	    	viagem[i].destino = Ndestino;
	    	viagem[i].ativo = 1;
	    	
	    	break;
	    }
		}
		linha();
	    printf("\n     PASSAGEIRO ALTERADO COM SUCESSO!!!\n");
	    linha();
	    getchar();
		
			}else
			if(sn==0){
			
			}
		}
		if(viagem[MAX].codigo != codigod){
			linha();
			printf("\n     PASSAGEIRO NAO ENCONTRADO!!!\n");
			linha();
		}
		
			
	    printf("\n     1-Para continuar alterando ou 0-Para sair: ");
		scanf("%d", &op);
		
	}while(op==1);
}
/*LISTA DOS CADASTRADIS*/
void listar(){
	int i;
	system("cls");
	linha();
	printf("\n                                                 Lista de Passageiros\n");
	linha();
	for(i=0; i<MAX; i++){
	 if(viagem[i].ativo==1){
	 	printf("\n     Seu codigo : %d", viagem[i].codigo);

		printf("\n     Nome: %s %s", viagem[i].nome1, viagem[i].nome2);
		printf("\n     Valor da passagem: R$ %d", viagem[i].passagem);
		
		switch(viagem[i].destino){
			case 1 :
				printf("\n     Destino: PARAIBA\n");
			break;
			case 2 :
				printf("\n     Destino: BAHIA\n");
			break;
            case 3 :
				printf("\n     Destino: ALAGOAS\n");
			break;		
			case 4 :
				printf("\n     Destino: CEARA\n");
			break;	
			case 5 :
				printf("\n     Destino: RIO GRANDE DO NORTE\n");
			break;	
			}
			
	    switch(viagem[i].passagem){
	    	case 120 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 150 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 300 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 340 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 200 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 240 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 320 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 360 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
	    	case 290 :
	    		printf("     Passagem: CONVENCIONAL\n");
	    	break;
	    	case 330 :
	    		printf("     Passagem: EXECUTIVA\n");
	    	break;
		    }
		
		linha();
		
    }  
	}
}

