#ifndef DATE_H
#define DATE_H
#include <time.h>
#include<string>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
using namespace std;
class date
{
     public:
 int jour;
 int mois;
 int annee;

     date();
     date(int ,int  ,int );
     date(string);
     int bissextile(int);
     void saisir_date();
     void afficher_date();
     int est_sup(date);

     void set_jour(int j){jour=j;}
     void set_mois(int m){mois=m;}
     void set_annee(int a){annee=a;}
     date getToday();
     string toStr(bool = false);

     int get_jour(){return jour;}
     int get_mois(){return mois;}
     int get_annee(){return annee;}
     static string getMonthName(int monthNumber)
     {
    string months[] = {"Janvier", "Fevrier", "Mars",
                       "Avril", "Mai", "Juin",
                       "Juillet", "Aout", "Septembre",
                       "Octobre", "Novembre", "Decembre"
                      } ;

    return (months[monthNumber]);
    }

     friend ostream& operator<<(ostream&,date&);
     friend istream& operator>>(istream&,date&);
     bool operator<=(date&);
     bool operator==(date&);

     ~date(){}
};// <
date::date()
{
    jour=0;
    mois=0;
    annee=0;
}

date::date(int j,int m,int a)
{
    jour=j;
    mois=m;
    annee=a;
}
date::date(string line){
    stringstream ss(line);
    ss >> jour >> mois >> annee;
}

void date::saisir_date()
{
    cout<<"\n donnez l'annee :"<<endl;
    cin>>annee;
    if((annee<1900)||(annee>2040))
    {
        do
        {
            cout<<"\n veuillez saisir une autre annee :"<<endl;
            cin>>annee;
        }
        while((annee<1900)||(annee>2040));
    }

    cout<<"\n donnez le mois :"<<endl;
    cin>>mois;
    if((mois<1)||(mois>12))
    {
        do
        {
            cout<<"\n veuillez saisir un autre mois :"<<endl;
            cin>>mois;
        }
        while((mois<1)||(mois>12));
    }
    cout<<"\n donnez le jour :"<<endl;
    cin>>jour;
    switch(mois)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        {
            if((jour<1)||(jour>31))
            {
                do
                {
                    cout<<"\n veuillez saisir un autre jour :"<<endl;
                    cin>>jour;
                }
                while((jour<1)||(jour>31));
            }
            break;
        }
    case 4:case 6:case 9:case 11:
        {
            if((jour<1)||(jour>30))
            {
                do
                {
                    cout<<"\n veuillez saisir un autre jour :"<<endl;
                    cin>>jour;
                }
                while((jour<1)||(jour>30));
            }
            break;
        }
    case 2:
        {
            if(bissextile(annee)==1)
            {
                if((jour<1)||(jour>29))
                {
                    do
                    {
                        cout<<"\n veuillez saisir un autre jour :"<<endl;
                        cin>>jour;
                    }
                    while((jour<1)||(jour>29));
                }
            }
            else if((jour<1)||(jour>28))
            {
                do
                {
                    cout<<"\n veuillez saisir un autre jour :"<<endl;
                    cin>>jour;
                }
                while((jour<1)||(jour>28));
            }
            break;
        }
    }

}

string date::toStr(bool t){
    if (t)
        return (to_string(jour)+ "/" + to_string(mois)+ "/" +to_string(annee));
    else
        return (to_string(jour)+ " " + to_string(mois)+ " " +to_string(annee)+"\n");
}

void date::afficher_date()
{
    cout<<"\n la date est "<<jour<<"/"<<mois<<"/"<<annee<<endl;
}

int date::est_sup(date t)
{
    if(annee<t.annee)
        return 1;
    else if(annee>t.annee)
        return -1;
    else if(mois<t.mois)
        return 1;
    else if(mois>t.mois)
        return -1;
    else if(jour<t.jour)
        return 1;
    else if(jour>t.jour)
        return -1;
    return 0;
}
ostream& operator<<(ostream& out,date& d)
{
    out<<d.jour<<"/"<<d.mois<<"/"<<d.annee<<endl;
    return out;
}

istream& operator>>(istream& in,date& d)
{
    cout<<"\n donnez la date :"<<endl;
    in>>d.jour>>d.mois>>d.annee;
    return in;
}
 bool date::operator<=(date& d)
 {
     if(annee<d.annee)
        return false;
    else if(annee>d.annee)
        return true;
    else if(mois<d.mois)
        return false;
    else if(mois>d.mois)
        return true;
    else if(jour<d.jour)
        return false;
    else if(jour>d.jour)
        return true;
    else 
        return true;
 }
 bool date::operator==(date& d)
 {
     if(annee==d.get_annee() && mois==d.get_mois() && jour==d.get_jour())
        return true;
     return false;
 }
int date::bissextile(int a)
{
    if((a%4)==0)
    {
        if((a%100)==0)
        {
            if((a%400)==0)
                return 1;
            else return 0;
        }
        return 1;
    }
    return 0;
}   

date date::getToday(){

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    date d(day,month,year);
    return d;
}

#endif