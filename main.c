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
    int jour ;
    int mois ;
    int annee ;

}Reservation;


int nomber_reservation = 10;


void ajoutes_une_reservation(Reservation reservation[]){
    int nomber_repetition ;
    int nomstatut ;

    printf("Vous avez choisi d'ajouter un nouveau Reservation.\n\n");
    printf("veuillez entrez le nombre des reservation: ");
    scanf("%d",&nomber_repetition);
    printf("------------------\n");

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
            printf("DATE DE RESERVATION (jj/mm/aaaa): ");
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
    printf("------------------\n");

    switch(choix_m_s){
        case 1 :do {printf("entrez le reference unique de reserfation : ");
                scanf("%d", &modifier);
                } while (modifier <= 0 || modifier > nomber_reservation);
                printf("------------------\n");
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
                           scanf(" %s", &reservation[nomber_reservation-1].prenom);
                           break;
                    default:printf("Choix invalide.\n");
                           break;
                }

        case 2 :printf("Votre choix est de supprimer une reservation:\n");
                do {printf("entrez la référence unique de réservation que vous souhaitez supprimer: ");
                scanf("%d", &supprimer);
                } while (supprimer <= 0 || supprimer > nomber_reservation);
                printf("------------------\n");

                int found = 0;

                for (int i = 0; i < nomber_reservation; i++) {
                if (reservation[i].reference_unique == supprimer) {
                    for (int j = i; j < nomber_reservation - 1; j++) {
                        reservation[j] = reservation[j+1];
                }
                (nomber_reservation)--;
                found = 1;
                printf("reservation %d supprime avec succes!\n", supprimer);
                break;
                    }
                }
                if (!found) {
                    printf("reservation avec reference unique %d introuvable!\n", supprimer);
                }
                break;

    }
}

void afficher_reservation(Reservation reservation[]){
    for(int i=0 ; i<nomber_reservation ;i++){
        printf("reservation %d :",reservation[i].reference_unique);
        printf("nom : %s <<<  prenom : %s <<< telephon : %s <<< age : %d <<< Statut : %s  <<< date de reservation : %d/%d/%d    . \n\n\n",reservation[i].nom,
        reservation[i].prenom,reservation[i].telephone,reservation[i].age,reservation[i].statut,reservation[i].jour,reservation[i].mois,reservation[i].annee);
        printf("---------------------------------------------------------------------------------------\n");
    }
}


void tribulleparnom(Reservation reservation[], int nomber_reservation) {
    for (int i = 0; i < nomber_reservation ; i++) {
        for (int j = i + 1; j < nomber_reservation ; j++) {
            if (strcmp(reservation[i].nom, reservation[j].nom) > 0) {
                Reservation temp = reservation[i];
                reservation[i] = reservation[j];
                reservation[j] = temp;
            }
        }
    }
}

void tribulleparstatut(Reservation reservation[],int nomber_reservation){
    for (int i = 0; i < nomber_reservation - 1; i++) {
        for (int j = 0; j < nomber_reservation - i - 1; j++) {
            if (strcmp(reservation[j].statut, reservation[j + 1].statut) < 0) {
                Reservation temp = reservation[j];
                reservation[j] = reservation[j + 1];
                reservation[j + 1] = temp;
            }
        }
    }
}

void afficherReservations(Reservation reservation[], int nomber_reservation) {
    for (int i = 0; i < nomber_reservation; i++) {
        printf("Reservation %d:\n", reservation[i].reference_unique);
        printf("Nom: %s <<< Prenom: %s <<< Telephone: %s <<< Age: %d <<< Statut: %s <<< Date de reservation: %d/%d/%d\n\n",
               reservation[i].nom, reservation[i].prenom, reservation[i].telephone, reservation[i].age,
               reservation[i].statut, reservation[i].jour, reservation[i].mois, reservation[i].annee);
    }
}

void tri_reservations(Reservation reservation[] , int nomber_reservation){
    int choix_t ;
    printf("Votre choix est de recherche une reservation . \n");
    printf("1.tri les reserfations par statut . \n");
    printf("2.tri les reserfations par nom. \n");
    printf("choisier un nomber : ");
    scanf("%d",&choix_t);
    printf("------------------\n");

    switch(choix_t){
        case 1: tribulleparstatut(reservation,nomber_reservation);
                printf("reservation essayee par statut:\n");
                afficherReservations(reservation, nomber_reservation);
                break;
        case 2:
                tribulleparnom(reservation,nomber_reservation);
                printf("reservation essayee par nom:\n");
                afficherReservations(reservation, nomber_reservation);
                break;
        break;

    }


}

void recherche_reservations(Reservation reservation[]){
    int choix_r ;
    int reservation_r_u;
    char reservation_n[20] ;
    printf("Votre choix est de recherche une reservation . \n");
    printf("1.recherche un reserfation par reference unique . \n");
    printf("2.recherche un reserfation par nom. \n");
    printf("choisier un nomber : ");
    scanf("%d",&choix_r);
    printf("------------------\n");

    switch(choix_r){
        case 1: printf("entrez reference unique pour le reservation que vous afficher:");
                scanf("%d", &reservation_r_u);
                printf("------------------\n");
                if (reservation_r_u <= 0 || reservation_r_u > nomber_reservation) {
                    printf("Invalid choice.\n");
                }
                else {
                for (int i = 0; i < reservation_r_u; i++) {
                    if (reservation[i].reference_unique == reservation_r_u) {
                        printf("reservation %d : \n",reservation[i].reference_unique);
                        printf("nom : %s <<<  prenom : %s <<< telephon : %s <<< age : %d <<< Statut : %s  <<< date de reservation : %d/%d/%d    . \n\n\n",reservation[i].nom,
                        reservation[i].prenom,reservation[i].telephone,reservation[i].age,reservation[i].statut,reservation[i].jour,reservation[i].mois,reservation[i].annee);
                    }
                }
                return;
                }
        case 2: printf("entrez le nom pour le reservation que vous afficher:");
                scanf(" %[^\n]s", &reservation_n);
                printf("------------------\n");

                for (int i = 0; i < reservation_r_u; i++) {
                    if (strcmp(reservation[i].nom , reservation_n)==0){
                        printf("reservation %d : \n",reservation[i].reference_unique);
                        printf("nom : %s <<<  prenom : %s <<< telephon : %s <<< age : %d <<< Statut : %s   <<< date de reservation : %d/%d/%d    . \n\n\n",reservation[i].nom,
                        reservation[i].prenom,reservation[i].telephone,reservation[i].age,reservation[i].statut,reservation[i].jour,reservation[i].mois,reservation[i].annee);
                    }
                    else{
                        printf("ce nom n'existe pas .");
                    }
                }
                return;
    }
}

void statistiques(Reservation reservation[]){
    int c_statistique ;
    int somme = 0 ;
    int sommeage1 = 0 ;
    int sommeage2 = 0 ;
    int sommeage3 = 0 ;
    int somestatut1 = 0 ;
    int somestatut2 = 0 ;
    int somestatut3 = 0 ;
    int somestatut4 = 0 ;
    float moyenne ;
    printf("1.Calculer la moyenne d'age des patients ayant reserve . \n");
    printf("2.Afficher le nombre de patients par tranche d'age . \n");
    printf("3.le nombre total de reservations par statut . \n");
    printf("choisie un nomber : ");
    scanf("%d",&c_statistique);
    printf("------------------\n");

    switch(c_statistique){
    case 1: for(int i = 0 ; i < nomber_reservation ; i++){
                somme += reservation[i].age;
                moyenne = somme / nomber_reservation ;
            }
            printf("le moyenne est : %.2f \n ",moyenne);
            break;
    case 2 : for(int i =0 ; i < nomber_reservation ; i++){
                if(reservation[i].age > 0 && reservation[i].age < 18){
                    sommeage1 ++ ;
                }
             }
             printf("le nombre de patients enter ( 0-18 ans ) : %d \n",sommeage1);

             for(int i=0 ; i < nomber_reservation ; i++){
                if (reservation[i].age > 19 && reservation[i].age < 35){
                    sommeage2 ++ ;
                }
             }
             printf("le nombre de patients enter ( 19-35 ans ) : %d \n",sommeage2);

             for(int i =0 ; i < nomber_reservation ; i++){
                if(reservation[i].age > 35) {
                    sommeage3 ++ ;
                }
             }
             printf("le nombre de patients enter (36+ ans) : %d \n",sommeage3);
             break;
    case 3:for(int i =0 ; i < nomber_reservation ; i++){
                if(strcmp(reservation[i].statut , "valide")== 0 ){
                    somestatut1 ++ ;
                }
             }
             printf("le nombre tptal de reserfation statut ( valide ) : %d \n",somestatut1);

             for(int i=0 ; i < nomber_reservation ; i++){
                if (strcmp(reservation[i].statut,"annule")==0){
                    somestatut2 ++ ;
                }
             }
             printf("le nombre tptal de reserfation statut( annule ) : %d \n",somestatut2);

             for(int i =0 ; i < nomber_reservation ; i++){
                if(strcmp(reservation[i].statut,"reporte")==0) {
                    somestatut3 ++ ;
                }
             }
             printf("le nombre tptal de reserfation statut(reporte) : %d \n",somestatut3);

             for(int i =0 ; i < nomber_reservation ; i++){
                if(strcmp(reservation[i].statut,"traite")==0) {
                    somestatut4 ++ ;
                }
             }
             printf("le nombre tptal de reserfation statut (traite) : %d \n",somestatut4);
    }
}

void menu(){
    printf("1.Ajouter une reservation . \n");
    printf("2.Modifier ou supprimer une reservation . \n");
    printf("3.Afficher les details d'une reservation  . \n");
    printf("4.Tri des reservations . \n");
    printf("5.Recherche des reservations . \n");
    printf("6.Statistiques . \n");
    printf("0.existe le programme . \n");
    printf("choiser un nomber :");

}

int main() {
    Reservation reservation[10]={{1,"hamza","lamin","0612345676",20,"valide",10,02,2024},
                               {2,"crictiono","ronaldo","06757577575",39,"valide",10,02,2024},
                               {3,"lionil","messi","0614253625",35,"annule",03,10,2024},
                               {4,"zakariae","el hassad","0699767689",19,"traite",03,10,2024},
                               {5,"lamin","yamal","0699767689",17,"traite",03,10,2024},
                               {6,"Jude","Jude Bellingham","0699767689",21,"reporte",03,10,2024},
                               {7,"Jamal","Musiala","0699767689",10,"valide",03,10,2024},
                               {8,"Joshua","Kimmich","0699767689",29,"reporte",03,10,2024},
                               {9,"Vinicius","Junior","0699767689",25,"reporte",03,10,2024},
                               {10,"Kylian","Mbappe","0699767689",25,"reporte",03,10,2024},
                            };

    int nomber_reservation = sizeof(reservation) / sizeof(reservation[0]);
    int choix ;
    //Reservation reservation[MAX_RESERVATION];
    do{
        menu();
        scanf("%d",&choix);
        printf("------------------\n");
        switch(choix){
            case 1: ajoutes_une_reservation(reservation);
            break;
            case 2: modifier_ou_supprimer(reservation);
            break;
            case 3: afficher_reservation(reservation);
            break;
            case 4: tri_reservations(reservation,nomber_reservation);
            break;
            case 5: recherche_reservations(reservation);
            break;
            case 6: statistiques(reservation);
            break;
            case 0: printf("Quitter le programme.\n . ");
            break;
            default:printf("Cette option n'existe pas");
            break;
       }
    }while(choix != 0);
    return 0;
}
