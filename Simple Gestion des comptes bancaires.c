#include <stdio.h>


// structure du compte banquaire du client : 
typedef struct {
    int num_de_compte ; 
    char nom_client[30];
    char prenom_client[30];
}Client;



int choix ; 

void choix_operation(){
printf("\n1 - Ajouter un nouveau client ");
printf("\n2 - Supprimer un client");
printf("\n3 - Modifier les informations d'un client");
printf("\n0 - Quitter ");
printf("\n \n Choisir l'op%cration souhait%ce (1 / 2 / 3 / 0 ): ",130,130);
 scanf("%d",&choix);

while(choix != 0 && choix!= 1 && choix !=2 && choix !=3){
    printf("\n Non valide choix");
    printf("\n \n Choisir l'op%cration souhait%ce (1 / 2 / 3 / 0 ): ",130,130);
    scanf("%d",&choix);
}}

void Afficher_Liste(int max , Client clients[max]){
    for (int i = 0 ; i<max ; i++) {
    if (clients[i].num_de_compte == 0){
        break;
    }
    else {
    printf("%d",clients[i].num_de_compte);
    printf(" %s",clients[i].nom_client);
    printf(" %s",clients[i].prenom_client);
    printf("\n");
    }
}

}
// Fct pour vérifier si le Num de compte existe dèja : 
void Verifier_repetition(int i,Client clients[]){
          int k = 0 ;
    while (k<i){
            if (clients[i].num_de_compte==clients[k].num_de_compte){
              printf("\nCe Num%cro de compte est deja utilis%c",130,130);
                printf("\nNum%cro de compte : ",130);
                scanf("%d",&clients[i].num_de_compte);
                k = 0 ; 
            }
            else {
            k++ ;
            }
    }
}

// Fct pour assurer que le NUM de compte doit etre différent de 0 :
void Refuser_0(int i ,Client clients[]){
    while (clients[i].num_de_compte==0){
        printf("Le num de compte doit etre diff%crent de 0",130);
        printf("\nNum%cro de compte : ",130);
        scanf("%d",&clients[i].num_de_compte);
        Verifier_repetition(i,clients);
    }
}

void Ajouter_client(int i , Client clients[]){
    printf("\nNum%cro de compte : ",130);
    scanf("%d",&clients[i].num_de_compte);
    Verifier_repetition(i,clients);
    Refuser_0(i,clients);
    printf("\nNom  : ");
    scanf("%s",&clients[i].nom_client);
    printf("\nPr%cnom :  ",130);
    scanf("%s",&clients[i].prenom_client);
}

void Modifier_client(int i , Client clients[]){
    printf("\nSaisir les modifications : \n");
    printf("\nNum%cro de compte : ",130);
    scanf("%d",&clients[i].num_de_compte);
    Refuser_0(i,clients);    
    int k = 0 ;
    while(clients[k].num_de_compte!=0){
        if (k==i){
            k++;
            continue;
        }
        else if (clients[k].num_de_compte==clients[i].num_de_compte){
            printf("Ce Num de compte deja existe");
            printf("\nNum%cro de compte : ",130);
            scanf("%d",&clients[i].num_de_compte);
            Refuser_0(i,clients);    
            k=0;
        }
        else {
            k++;
        }
    }
    printf("\nNom  : ");
    scanf("%s",&clients[i].nom_client);
    printf("\nPr%cnom :  ",130);
    scanf("%s",&clients[i].prenom_client);
        
}

int main () {

//On fixe un maximum des clients (changeable) (exemple : 10000 ): 
Client client_default={0,"default","default"};
int max = 10000 ; 
Client clients[max] ;

for (int i = 0 ; i<max ; i++){
    clients[i]=client_default;
}

// ajout de 5 clients : 
printf("Ajouter les 5 premiers clients : \n");
for (int i = 0 ; i<=4 ; i++) {
    printf("Entrer les infos du client num%cro %d : ",130,i+1);
    Ajouter_client(i,clients);    
}
int nbr_clients = 5 ;


// simple affichage de la liste des clients saisis : 

printf("\nla  liste des clients : \n \n");
Afficher_Liste(max ,clients);

//choix : 
choix_operation();
//

while (choix != 0 ){

// choix 1  (l'ajout d'un nouveau client  ):

if (choix == 1){
    nbr_clients+=1;
    printf("Entrer les infos du nouveau client : ");
    Ajouter_client(nbr_clients-1,clients);      
}


// choix 2  (Suppression d'un client selon son num de compte): 
 
else if (choix == 2 ){
   
    printf("\nDonnez le valide Num%cro de compte du client que vous souhaitez supprimer : ",130);
    int num ; 
    scanf("%d",&num);
    while(num==0){
        printf("Le num de compte est diff%crent de 0",130);
         printf("\nDonnez le valide Num%cro de compte du client que vous souhaitez supprimer : ",130);
        scanf("%d",&num);
    }
 
    for (int i = 0 ; i< nbr_clients ; i++){
        if (clients[i].num_de_compte==num){
            for (int j = i; j<nbr_clients;j++){
                 clients[j]=clients[j+1];
                    }     
        clients[nbr_clients]=client_default;
         nbr_clients-=1;
        }
        

    }
    
}

// choix 3 (Modification des informations d'un client) : 

else if (choix == 3){
    printf("\nDonnez le valide num%cro du compte du client %c modifier : ",130,133);
    int num1 ; 
    scanf("%d",&num1);
     while(num1==0){
        printf("Le num de compte est diff%crent de 0",130);
         printf("\nDonnez le valide num%cro du compte du client %c modifier : ",130);
        scanf("%d",&num1);
    }
    int c = 0 ;
    for (int i = 0 ;  i < nbr_clients ; i++){
        if (clients[i].num_de_compte == num1 ){
            Modifier_client(i,clients);
            
    }
}

}

// affichage de la nouvelle liste : 

printf("\nla nouvelle liste des clients : \n\n");
Afficher_Liste(max ,clients);

// choix d'opération : 
choix_operation();
}
printf("\nLa gestion des comptes bancaires est termin%ce",130);
     
 
}





