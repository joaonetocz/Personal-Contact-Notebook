#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct agenda{
    int pg;//0-NADA 1+-PREENCHIDO
    char nome[30], email[30], fone[10], endereco[100], CEP[9];
    };

    int main ()
    {
        int n, m, pag, c, pd, j=0, op, i;
        char bnome[30], bletra;
        struct agenda ag[50];
        for(i=0; i<50; i++){
            ag[i].pg=0;
                     strcpy(ag[i].nome,"");
                     strcpy(ag[i].endereco,"");
                     strcpy(ag[i].fone,"");
                     strcpy(ag[i].email,"");
                     strcpy(ag[i].CEP,"");
        }
        inicio:
        do{
        if(j>0)printf("Digite um valor entre 1 e 7\n");
        printf("\n1- Cadastrar uma nova entrada\n2- Buscar dados de uma pessoa\n3- Digite a primeira letra do nome de um contato a ser procurado\n4- Digite o nome de uma pessoa para excluir\n5- Digite o numero da pagina que deseja obter dados\n6- Procurar uma pagina vazia\n7- Sair\n");
        scanf("%d", &op);
        j++;}while(op<1||op>7); j=0;
        switch(op){
            case 1:do{if(j>0) printf("\nDigite um valor entre 1 e 50\n");
            printf("\nDigite a pagina da agenda: ");
            scanf("%d", &m);j++;}while(m<1||m>50); j=0;
            m=m-1;
            if(ag[m].pg!=0){ printf("Essa pagina já esta preechida. Deseja Apagar?(1 - Sim. 2 - Nao)");
            do{scanf("%d", &c);}while(c<1||c>2);
            if (c==2) goto inicio;
            }ag[m].pg = m+1;
            printf("\nDigite o nome: ");
            fflush(stdin);
            gets(ag[m].nome);
            printf("\nDigite o e-mail: ");
            fflush(stdin);
            gets(ag[m].email);
            printf("\nDigite o numero para contato: ");
            fflush(stdin);
            gets(ag[m].fone);
            printf("\nDigite o endereco: ");
            fflush(stdin);
            gets(ag[m].endereco);
            printf("\nDigite o CEP: ");
            fflush(stdin);
            gets(ag[m].CEP);
            goto inicio;
            break;
            case 2:
            printf("Digite o nome da pessoa a ser buscada(Sensivel a maiusculos e minusculos)");
            fflush(stdin);
            gets(bnome); j=0;
            for(i=0; i<50; i++)
            {
                if(strcmp(bnome, ag[i].nome)==0){
                printf("\nPagina em que esta cadastrado: %d\nNome: %s\nE-mail: %s\nFone: %s\nEndereco: %s\nCEP: %s\n\n", ag[i].pg, ag[i].nome, ag[i].email, ag[i].fone, ag[i].endereco, ag[i].CEP );
                j++;}
            }
            if(j==0) printf("\nNenhum contato encotrado."); j=0;
            goto inicio;
            break;

            case 3:
            printf("Digite a primeira letra do nome do contato a ser procurado: ");
            fflush(stdin);
            scanf("%c", &bletra); j=0;
            for(i=0; i<50;i++){
                if(bletra==ag[i].nome[0]){j++;
                        printf("Nome iniciado com %c:  %s\n", bletra, ag[i].nome);}}
            if(j==0) printf("\nNenhum contato encotrado."); j=0;
            goto inicio;
            goto inicio;
            break;

            case 4:
            printf("Digite o Nome da pessoa para excluir: ");
            fflush(stdin);
            gets(bnome);j=0;
            for(i=0; i<50; i++)
            {

                if(strcmp(bnome, ag[i].nome)==0)
                {
                 printf("Tem certeza que deseja excluir os dados de: %s?(1- Sim. 2- Nao.)", ag[i].nome);
                 do{scanf("%d", &c);}while(c<1||c>2);
                 if(c==1){
                     ag[i].pg=0;
                     strcpy(ag[i].nome,"");
                     strcpy(ag[i].endereco,"");
                     strcpy(ag[i].fone,"");
                     strcpy(ag[i].email,"");
                     strcpy(ag[i].CEP,"");

                 }

                } else j++;

            }
            if(j==50) printf("\nNenhum contato encontrado.");
            else printf("\nContato excluido."); j=0;
            goto inicio;
            break;

           case 5:
           do{
           printf("Digite o Numero da pagina que deseja obter dados: ");
           scanf("%d",&pd);
           }while(pd<0||pd>50);
           pd=pd-1;
           printf("Nome: %s\n", ag[pd].nome);
           printf("E mail: %s\n", ag[pd].email);
           printf("Fone: %s\n", ag[pd].fone);
           printf("Endereco: %s\n",ag[pd].endereco);
           printf("CEP: %s\n",ag[pd].CEP);
           goto inicio;
           break;
           case 6:
            for(i=0; i<50;i++)
            {
                if(ag[i].pg==0){ printf("A pagina %d esta vazia\n", i+1 );
                break;}
            }
            goto inicio;

           case 7:
           return 0;
           break;
        }
    }
