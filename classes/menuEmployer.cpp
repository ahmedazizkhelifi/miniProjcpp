#include "saveToFiles.cpp"

int choixEmployerPersonelle(string path = "Personnel"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Ajouter un employer\n2. Modifier les donnees d'un employer\n3. Supprimer un employer\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=3; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

void menuEmployerPersonelle(){
    int r= choixEmployerPersonelle();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Ajouter un employer");
            employer e;
            Container<employer> employes;
            employes = LoadEmployer();
            e.saisirEmployer(employes);
            employes.ajouter(e);
            Fichier f("employer");
            f.appendEmployer(e);
            std::cout << "\nEmployer ajoutee avec success.\n\n>>> ";
            pause();
        }
    break;
    case 2:
        {
            header("Modifier les donnees d'un employer");
            pause();   
        }
    case 3:
        {
            header("Supprimer un employer");
            pause();   
        }
    
    default:
        break;
    }
}
int choixEmployerParametre(std::string path = "Parametres"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Parametre du compte\n2. Les date de promotions\n3. Defenir la promotion sur la carte fidelite\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=3; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}


int choixEmployer(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Commandes\n3. Personnel\n4. Statistique\n5. Parametres\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=5; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

int choixGerantStatistique(std::string path = "Statistique"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    // tkharej histograme taa kol mois
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Histogramme de revenue mensuel des factures par annee\n2. Somme des ventes\n3. Statistiques des clients\n4. Depenses sous forme de salaires employes\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=4; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

int choixEmployerProduits(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Produits");
            std::cout << "1. Afficher\n2. Ajouter\n3. Modifier\n4. Supprimer\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<5); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}
int choixParametresDatepromos(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Parametres\\Parametre du compte");
            std::cout << "1. Afficher les dates de promotions\n2. Ajouter une date de promotions\n3. Supprimer une date de promotion\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<=3); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}
int choixEmployerCommandes(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Commandes");
            std::cout << "1. Archive des factures\n2. Nouvelle commande\n3. Supprimer commande\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<=3); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}
void menuParametresDatepromos(){
    int r = choixParametresDatepromos();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Parametres\\Afficher les dates de promotions");
            Container <date> promoDays;
            promoDays = LoadPromoDays();
            cout << "Le nombre de date de promotions est: " << promoDays.taille() << "\n\n";
            for (unsigned int i =0;i<promoDays.taille();i++)
                cout << "Date "<< i << ": "<<promoDays[i].toStr(true) << endl;
            std::cout << "\n\n>>> ";
            pause();
        }
    break;
    case 2:
        {
            header("Parametres\\Ajouter une date de promotions");
            Container <date> promoDays;
            promoDays = LoadPromoDays();
            date d;
            int r = 0;
            do
            {
                d.saisir_date();
                r = ouiNon("confirmer l'ajout du date "+d.toStr(true)+" ","Parametres\\Ajouter une date de promotions");
            } while (!(r==1));
            promoDays.ajouter(d);
            Fichier f("PromoDays");
            f.reset();
            f.appendDate(d);
            std::cout << "\nDate de promotion ajoutee avec success.\n\n>>> ";
            pause();
        }
    break;
    case 3:
        {
            header("Parametres\\Supprimer une date de promotion");
            Container <date> promoDays;
            promoDays = LoadPromoDays();
            date d;
            do
            {
                d.saisir_date();
                int trouve = promoDays.find(d);
                if (trouve == -1){
                    cout << "Date inconnue, saisir q pour quitter.\n\n>>>";
                    char c = ' ';
                    cin >> c;
                    if (c=='q')
                        break;
                }else{
                    r = ouiNon("confirmer la suppression du date "+d.toStr(true)+" ","Parametres\\Ajouter une date de promotions");
                    if (r==0)
                        continue;
                    else
                        {
                            promoDays.supprimerParIndice(trouve);
                            Fichier f("PromoDays");
                            f.reset();
                            for (unsigned int i =0;i<promoDays.taille();i++)
                                f.appendDate(promoDays[i]);
                            std::cout << "\nDate de promotion supprimer avec success.\n\n>>> ";
                        }
                }
            } while (!(r==1));

            pause();
        }
    break;
    default:
        break;
    }

}
void menuEmployerParametres(){
    int r = choixEmployerParametre();
    //"1. \n2. \n3. \n4. \n5. \n\n0. Retour\n\n";

    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Parametres\\Parametre du compte");
            pause();
        }
    break;
    case 2:
        {
            menuParametresDatepromos();
        }
    break;
    case 3:
        {
            header("Parametres\\Defenir la promotion sur la carte fidelite");
            Setting s;
            if (s.estGerant){
                float f = readFloat("","Saisir remise en %:\n",0);
                s.remiseSurCarteF =f;
            } else
            {
                cout << "Seul le gerant peut voir cette page.\n\n>>> ";
                
            }
            pause();
        }
    break;
    default:
        break;
    }
}


void menuEmployerProduits(Container<Produit>& produits){
    int r = choixEmployerProduits();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Produits\\Afficher");
            std::cout << "\nNombre total des produits est: " << produits.taille() << ".\n";
            produits = LoadProduit();
            for (unsigned int i =0;i <produits.taille();i++){
                Produit p = produits[i];
                std::cout << p;
            }
            std::cout << ">>> ";
            system("PAUSE");           
        }
    break;
    case 2:
        {
            //oui non
            r = ouiNon("ajouter un nouveau produit","Produits\\Ajouter");
            if (r==1){
                header("Produits\\Ajouter");
                saveProductToFile(produits);
                break;
            }
            
            // do until confirmer
            header("Produits\\Ajouter");
            std::cout << ">>> ";
            system("PAUSE");
        }
    break;
    case 3:
        {
            r  = ouiNon("modifier un produit","Produits\\Modifier");
            if (r == 1){
                header("Produits\\Modifier");
                std::string id;
                std::cout << "Saisir l'id du produit a modifier.\n\n>>> ";
                std::cin >> id;
                if(produits.idintExist(id)){
                    header("Produits\\Modifier");
                    Produit p = produits.getByintId(id);
                    std::cout << p;
                    r  = ouiNon("modifier produit ID:  "+ id + " ","Produits\\Modifier",0);

                    if (r == 1){
                        do
                        {    
                            produits.modifier(id);
                            r = ouiNon("continuer a modifier le produit ID:  "+ id + " ","Produits\\Modifier",0);
                            Produit p = produits.getByintId(id);
                            std::cout << p;
                        } while (r==1);
                        
                        
                        
                        Fichier f("produits");
                        f.reset();
                        for (unsigned int i =0;i <produits.taille();i++){
                            Produit p = produits[i];
                            f.appendProduit(p);
                        }
                        std::cout << "Produit modifier avec succes.\n\n>>> ";
                        //header("Produits\\Ajouter");
                        system("PAUSE");
                    }
                    else {
                        std::cout << "\n\n>>> ";
                        system("PAUSE");
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;  
    case 4:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer un produit","Produits\\Supprimer");
            if (r == 1){
                header("Produits\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du produit a supprimer.\n\n>>> ";
                std::cin >> id;
                if(produits.idintExist(id)){

                    r  = ouiNon("supprimer produit ID:  "+ id + " ","Produits\\Supprimer");
                    Produit p = produits.getByintId(id);
                    std::cout << p;
                    
                    if (r == 1){
                    produits.supprimer(id);
                    Fichier f("produits");
                    f.reset();
                    for (unsigned int i =0;i <produits.taille();i++){
                        Produit p = produits[i];
                        f.appendProduit(p);
                    }
                    header("Produits\\Ajouter");
                    std::cout << "Produit supprimer avec succes.\n\n>>> ";
                    system("PAUSE");
                    }
                    else {
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;
    default:
        break;
    }    
}

void menuEmployerCommande(Container<Produit> produits,Container<Facture>& factures){
    int r = choixEmployerCommandes();
    switch (r)
    {
    case 0:
        break;
    case 1:
        header("Commandes\\Archive des factures");
        std::cout << "Nombre de commandes total: " <<  factures.taille() <<  std::endl;
        for (unsigned int i = 0; i < factures.taille(); i++){
            Facture fact;
            fact = factures[i];
            std::cout << fact << "\n\n"; 
        }
        std::cout << ">>> ";
        system("PAUSE");
        break;
    case 2:
        header("Commandes\\Nouvelle Commande");
        saveFacture(factures,produits);
        std::cout << ">>> ";
        system("PAUSE");
        break;
    case 3:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer une commande","Commandes\\Supprimer");
            if (r == 1){
                header("Commande\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du commande a supprimer.\n\n>>> ";
                std::cin >> id;
                Facture fact = factures.getBystrId(id);
                if (factures.idstrExist(id))
                {
                    header("Commandes\\Supprimer");
                    std::cout << fact;
                    r  = ouiNon("supprimer commande ID:  "+ id + " ","Commandes\\Supprimer",0);
                    Facture fact = factures.getBystrId(id);
                    std::cout << fact;
                    if (r == 1){
                        factures.supprimer(id);
                        Fichier f("facture");
                        f.reset();
                        for (unsigned int i =0;i <factures.taille();i++){
                            Facture fact = factures[i];
                            f.appendFacture(fact);
                            header("Commandes\\Ajouter");
                            std::cout << "Commande supprimer avec succes.\n\n>>> ";
                            system("PAUSE");
                        }
                    }else  break;

                }else{
                        std::cout << "Id n'existe pas.\n\n>>> ";
                        system("PAUSE");
                        break;
                }
            }
        }
        break;
    default:
        break;
    }
}


void menuGerantStatistique(Container<Facture> factures,Container<employer> employes,Container<client> clients){
    int r = choixGerantStatistique();
    switch (r)
    {
    case 0:
        /* code */
        break;
    case 1:
        {
            //histo
            //header("Statistique\\Histogramme de revenue mensuel des factures par annee");
            int annee = readInt("Statistique\\Histogramme de revenue mensuel des factures par annee","Saisir l'annee: ");
            statHistograme(factures,annee);
            std::cout << ">>> ";
            pause();
        }
        break;
    case 2:
        {
            header("Statistique\\Somme des ventes");
            statSommeVente(factures,employes);
            std::cout << ">>> "; 
            pause();
        }
    break;
    case 3:
        {
            header("Statistique\\Statistique des clients");
            statClients(clients);
            std::cout << ">>> "; 
            pause();
        }
    break;
    case 4:
    {
        header("Statistique\\Depenses sous forme de salaires employes");
        statDepenseEnSalaireEmployer(employes);
        std::cout << "\n\n>>> ";
        pause(); 
    }
    default:
        break;
    }
}