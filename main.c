#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESERVATION 20

typedef struct  {
    int reference_unique;
    char nom[20];
    char prenom[20];
    char telephone[20];
    int age ;
    char statut[50];
    int annee ;
    int mois ;
    int jour ;

}Reservation;




//Reservation reservation[2]={{1,'hamza','lamin',0612345676,20,'10/2/2024','valide'},
                           // {2,'simo','java',06757577575,8,'10/2/2024','valide'},
                           // };
  //sizeof(reservation) / sizeof(reservation[0]);
//int nomber_reservation = sizeof(reservation) / sizeof(reservation[0]);
int nomber_reservation = 2;


void ajoutes_une_reservation(Reservation reservation[]){
    int nomber_repetition ;
    int nomstatut ;

    printf("Vous avez choisi d'ajouter un nouveau Reservation.\n\n");
    printf("veuillez entrez le nombre des reservation: ");
    scanf("%d",&nomber_repetition);

    if(nomber_reservation < MAX_RESERVATION){



        for(int i=0 ; i<nomber_repetition ; i++){
            reservation[nomber_reservation].reference_unique = nomber_reservation + 1 ;
            printf("reservation : %d \n",reservation[nomber_reservation].reference_unique);
            printf("NOM : ");
            scanf(" %[^\n]s", reservation[nomber_reservation].nom);

            printf("PRENOM : ");
            scanf(" %[^\n]s", reservation[nomber_reservation].prenom);

            printf("TELEPHONE : ");
            scanf(" %s", reservation[nomber_reservation].telephone);

            printf("AGE : ");
            scanf(" %d", &reservation[nomber_reservation].age);

            printf("STATUT : \n");
            printf("1. valide \n");
            printf("2. reporte \n");
            printf("3. annule \n");
            printf("4. traite \n");
            printf("Choisissez un statut : ");
            scanf("%d", &nomstatut);
            switch (nomstatut) {
                case 1:
                    strcpy(reservation[nomber_reservation].statut, "valide");
                    break;
                case 2:
                    strcpy(reservation[nomber_reservation].statut, "reporte");
                    break;
                case 3:
                    strcpy(reservation[nomber_reservation].statut, "annule");
                    break;
                case 4:
                    strcpy(reservation[nomber_reservation].statut, "traite");
                    break;
                default:
                    printf("Votre choix est invalide.\n");
                    return;
           }


            if(1<reservation[nomber_reservation].mois<12 && 1<reservation[nomber_reservation].jour<31){
            printf("DATE DE RESERVATION (xx/xx/xxxx): ");
            scanf(" %d / %d / %d", &reservation[nomber_reservation].jour,&reservation[nomber_reservation].mois,&reservation[nomber_reservation].annee);
            }
            else{
                printf("vous avez une erreur dans le mois ou le jour .");
                return;
            }
            printf("\n\n");
            nomber_reservation++;
        }
    }
    else {
        printf("limite de reservation atteinte. Impossible d'ajouter plus de reservation.\n\n\n");
    }
}

void modifier_ou_supprimer(Reservation reservation[]){
    int choix_m_s ;
    int modifichoix;
    int modifier;
    int supprimer;
    printf("1.modifier un reserfation . \n");
    printf("2.supprimer un reserfation . \n");
    printf("choisier un nomber : ");
    scanf("%d",&choix_m_s);

    switch(choix_m_s){
        case 1 :do {printf("entrez le reference unique de reserfation : ");
                scanf("%d", &modifier);
                } while (modifier <= 0 || modifier > nomber_reservation);
                printf("Choose what to modify:\n");
                printf("1. name \n");
                printf("2. prenom\n");
                printf("3. telephone\n");
                printf("4. age\n");
                printf("5. date de reserfation\n");
                printf("6. statut\n");
                printf("Enter your choice: ");
                scanf("%d", &modifichoix);
                while (modifichoix < 1 || modifichoix > 6) {
                    printf("Invalid choice. Please enter a valid choice (1 or 2).\n");
                    printf("Enter your choice: ");
                    scanf("%d", &modifichoix);
                }

                switch (modifichoix) {
                    case 1:printf("name : ");
                           scanf(" %[^\n]s", reservation[nomber_reservation-1].nom);
                           break;
                    case 2:printf("prenom: ");
                           scanf(" %[^\n]s", &reservation[nomber_reservation-1].prenom);
                           break;
                    case 3:printf("telephone: ");
                           scanf(" %s", &reservation[nomber_reservation-1].telephone);
                           break;
                    case 4:printf("age: ");
                           scanf("%d", &reservation[nomber_reservation-1].age);
                           break;
                    case 5:printf("date de reserfation: ");
                           scanf("%d / %d / %d", &reservation[nomber_reservation-1].jour,&reservation[nomber_reservation-1].mois,&reservation[nomber_reservation-1].annee);
                           break;
                    case 6:printf("statut: ");
                           scanf("%d", &reservation[nomber_reservation-1].prenom);
                           break;
                    default:printf("Choix invalide.\n");
                            break;
                }
        case 2 :do {printf("entrez le reference unique de reserfation : ");
                scanf("%d", &supprimer);
                } while (supprimer <= 0 || supprimer > nomber_reservation);
                printf("Votre choix est de supprimer une reservation:\n");
                printf("Quel reservation souhaitez-vous supprimer: ");//check what is that
                scanf("%d", &supprimer);

                int found = 0;

                if (supprimer <= 0 || supprimer > nomber_reservation) {
                    printf("reference unique invalide!\n");
                }
                else {
                for (int i = 0; i < nomber_reservation; i++) {
                if (reservation[i].reference_unique == supprimer) {
                    for (int j = i; j < nomber_reservation - 1; j++) {
                        reservation[j] = reservation[j + 1];
                }
                nomber_reservation--;
                found = 1;
                printf("reservation %d supprimé avec succès!\n", supprimer);
                break;
                    }
                }
                if (!found) {
                    printf("reservation avec référence unique %d introuvable!\n", supprimer);
                }
                }
                break;

    }
}

void afficher_reservation(Reservation reservation[]){
    for(int i=0 ; i<nomber_reservation ;i++){
        printf("reservation %d :",reservation[i].reference_unique);
        printf("nom : %s <<<  prenom : %s <<< telephon : %s <<< age : %d <<< Statut : %s  <<<  date de reservation : %d/   . \n\n\n",reservation[i].nom,
                reservation[i].prenom,reservation[i].telephone,reservation[i].age, reservation[i].statut,reservation[i].jour,reservation[i].mois,reservation[i].annee);
    }
}

void tri_reservations(Reservation reservation[]){
}

void recherche_reservations(Reservation reservation[]){
    int reservation_r_u;
    printf("reference unique pour le reservation que vous afficher:");
    scanf("%d", &reservation_r_u);
    if (reservation_r_u <= 0 || reservation_r_u > nomber_reservation) {
        printf("Invalid choice.\n");
    } else {
        for (int i = 0; i < reservation_r_u; i++) {
            if (reservation[i].reference_unique == reservation_r_u) {
                printf("reservation %d : \n",reservation[i].reference_unique);
                printf("nom : %s <<<  prenom : %s <<< telephon : %s <<< age : %d <<< date de reservation : %d/%d/%d    . \n\n\n",reservation[i].nom,
                reservation[i].prenom,reservation[i].telephone,reservation[i].age,reservation[i].jour,reservation[i].mois,reservation[i].annee);
            }
        }
        return;
    }
}

void menu(){
    printf("1.Ajouter une reservation . \n");
    printf("2.Modifier ou supprimer une reservation . \n");
    printf("3.Afficher les détails d'une reservation  . \n");
    printf("4.Tri des reservations . \n");
    printf("5.Recherche des reservations . \n");
    printf("5.Statistiques . \n");
    printf("0.existe le programme . \n");
    printf("choiser un nomber :");

}
int main() {
    Reservation reservation[2]={{1,"hamza","lamin","0612345676",20,"valide",10,2,2024},
                               {2,"simo","java","06757577575",8,"valide",10,2,2024},
                            };

    int nomber_reservation = sizeof(reservation) / sizeof(reservation[0]);
    int choix ;
    //Reservation reservation[MAX_RESERVATION];
    do{
        menu();
        scanf("%d",&choix);
        switch(choix){
            case 1: ajoutes_une_reservation(reservation);
            break;
            case 2: modifier_ou_supprimer(reservation);
            break;
            case 3: afficher_reservation(reservation);
            break;
            case 4: tri_reservations(reservation);
            break;
            case 5: recherche_reservations(reservation);
            break;
       }
    }while(choix != 0);
    return 0;
}
