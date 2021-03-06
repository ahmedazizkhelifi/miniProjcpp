#include "produit.h"
#include<ctime>
#include <string.h>
#include <conio.h>
#include "settings.h"


float max(float tab[])
{

    float max = tab[0];
        for(unsigned int i = 0; i<12;i++){
            if (tab[i]>max){
                max = tab[i];
            }
        }
        return max;
}

void buildHistogram(float b,float a, int& maxHistogramme)
{   
    int x = 0;
    if(a!=0)
        x=(int)(b/a);
    if (x>maxHistogramme)
        maxHistogramme = x;
    cout << maxHistogramme << " ";

    for(int i=0;i<x;i++)
        cout<<"x";
    cout<<"\n";
/*     for(int i=0;i<x;i++)
        cout<<"*"; */
}

void pause(){
    system("pause");
}
std::string readPassword(){
    char c = ' ';
    std::string password = "";
    while (c!=13){  // c = 13 is 'Enter' key.
    c = getch();
    if (c!=13){
        password +=c;
        std::cout << "*";
        }
    }
    return password;
}


std::string processId(std::string id){
    string ch;
    if (id[0] == 'c'){
        ch = "Client " + id.substr(1,id.length()-1);
        return ch;
    }
    else if (id[0] == 'e'){
        ch = "Employer " + id.substr(1,id.length()-1);
        return ch;
    }
    return id;
}

void timeline()
{
  time_t t;
  time(&t);
  std::string curtime=ctime(&t);
  std::cout<<curtime;
}
void header(std::string path = ""){
    system("cls");
    std::cout << "APPLICATION NAME\\" << path << "\n";
    timeline();
    Setting s;
    if (!(s.id == "_")){
        string ch = processId(s.id);
        ch =ch+ ": "+ s.nom + " " + s.prenom; 
        std::cout << ch << "\n\n";
    }else{
        std::cout << "\n";
    }
}
int ouiNon(std::string text = "_text_", std::string path ="_path_",int h = 1,int fullText = 0){
    std::string r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            if (h==1)
                header(path);
            else
                std::cout << "\n";
            if (fullText==1)
                std::cout << text << "[O/n]\n\n";
            else
                std::cout << "(deco)Voulez-vous vraiment " << text << "?[O/n]\n\n";
            std::cout << ">>>";
            std::cin >> r;
            //system("cls");
            validation = r=="O" || r =="o" || r=="N" || r =="n";
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);
    if (r=="O" || r =="o"  )
        return 1;
    else 
        return 0;
}



int readInt(std::string path ="___",std::string text ="___", int h = 1){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            if (h ==1)
                header(path);
            else
                std::cout << "\n";
            std::cout << text;
            std::cout << ">>> ";
            std::cin >> r;
            //validation = (r>=0 && r<1); // menu tests
            validation = true;
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

float readFloat(std::string path ="___",std::string text ="___", int h = 1){
    float r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            if (h ==1)
                header(path);
            else
                std::cout << "\n";
            std::cout << text;
            std::cout << ">>> ";
            std::cin >> r;
           // validation = (r>=0 && r<3); // menu tests
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

/* 
int menuPrincipaleChoix(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Commandes\n3. Personnel\n4. ______\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>0 && r<4; // menu tests
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







int menuProduitChoix(std::string path = "Produits"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header(path);
            std::cout << "1. Ajouter\n2. Afficher\n3. Modifier\n4. Supprimer\n5. Statistique\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<4); // menu tests
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

void menuProduit(std::vector<Produit>& v){
    int r = menuProduitChoix();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            int yn = ouiNon("ajouter un nouveau produit","Produit\\Ajouter");
            if (yn == 1){
                header("Produit\\Ajouter"); 
                Produit P1;
                std::cin>> P1;
                
                v.push_back(P1);
            }
            else
                break;


        }
        break;
    case 2:
        {
            header("Produit\\Afficher");
            if(v.size() == 0)
                std::cout<< "Il n'y a rien a afficher.\n";
            else
                std::cout<<"Nombre de produits: " << v.size() << "\n";

            for(size_t i = 0; i < v.size(); ++i) 
                std::cout << v[i];
            std::cout << "\n>>> ";
            system("PAUSE");           
        }
        break;
    default:
        break;
    }
}


void menuPrincipale(std::vector<Produit>& v){
    int r = menuPrincipaleChoix();
    switch (r)
    {
    case 1:
        menuProduit(v);
        break;
    
    default:
        break;
    }
}
 */