#include <iostream>
#include <cstdlib>

using namespace std;

void wyswietl(int n, int** A){
    cout<<"Macierz sasiedztwa: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void sasiedzi(int n, int** A){
    cout<<"Zadanie 1:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==1){
                cout<<"Wierzcholek "<<i<<" sasiaduje z wierzcholkiem "<<j<<"\n";
            }
        }
        cout<<"\n";
    }

    cout<<"------------------------------------------------------------------\n";
}
void sasiedzi_kazdego(int n, int** A){
    cout<<"Zadanie 2:\n";

    int licznik;
    bool czy_byl = false;
    for(int i=0;i<n;i++){
        licznik=0;
        for(int j=0;j<n;j++){
            if(A[i][j]==1)
                licznik++;
        }
        if(licznik==n-1 || licznik==n){
            cout<<"Wierzcholek "<<i<<" jest sasiadem kazdego wierzcholka\n";
            czy_byl=true;
        }
    }
    if(!czy_byl){
        cout<<"Nie ma wierzcholka, ktory sasiaduje ze wszystkimi\n";
    }

    cout<<"------------------------------------------------------------------\n";
}
void stopien_wychodzacy(int n, int** A){
    cout<<"Zadanie 3:\n";

    int licznik;
    for(int i=0;i<n;i++){
        licznik=0;
        for(int j=0;j<n;j++){
            if(A[i][j]==1)
                licznik++;
        }
        cout<<"Stopien wychodzacy wierzcholka "<<i<<": "<<licznik<<"\n";

    }

    cout<<"------------------------------------------------------------------\n";
}
void stopien_wchodzacy(int n, int** A){
    cout<<"Zadanie 4:\n";

    int licznik;
    for(int j=0;j<n;j++){
        licznik=0;
        for(int i=0;i<n;i++){
            if(A[i][j]==1)
                licznik++;
        }
        cout<<"Stopien wchodzacy wierzcholka "<<j<<": "<<licznik<<"\n";
    }

    cout<<"------------------------------------------------------------------\n";
}
void izolowany(int n, int** A){
    cout<<"Zadanie 5:\n";

    bool czy_izo;
    bool czy_byl=false;
    for(int i=0;i<n;i++){
        czy_izo = true;
        for(int j=0;j<n;j++){
            if(A[i][j]==1 || A[j][i]==1){
                czy_izo = false; break;
            }
        }
        if(czy_izo){
            cout<<"Wierzcholek "<<i<<" jest izolowany\n";
            czy_byl=true;
        }
    }
    if(!czy_byl){
        cout<<"Nie ma wierzcholkow izolowanych\n";
    }

    cout<<"------------------------------------------------------------------\n";
}
void petla(int n, int** A){
    cout<<"Zadanie 6:\n";

    bool czy_izo;
    for(int i=0;i<n;i++){
        if(A[i][i]==1){
            cout<<"Wierzcholek "<<i<<" jest petla\n";
        }
    }

    cout<<"------------------------------------------------------------------\n";
}
void kr_dwukierunkowa(int n, int** A){
    cout<<"Zadanie 7:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==1 && A[j][i]==1 && i!=j){
                cout<<"Krawedz dwukierunkowa pomiedzy wierzcholkiem "<<i<<", a wierzcholkiem "<<j<<"\n";
            }
        }
    }

    cout<<"------------------------------------------------------------------\n";
}
/*
0 0
0 1
0 2
0 3
0 4
1 2
2 3
3 0
3 4
4 1
*/
int main(){
    int n, m;
    cout<<"Podaj liczbe wierzcholkow i krawedzi\n";
    cin>>n>>m;
    int ** A = new int * [n];
    for(int i=0;i<n;i++){
        A[i] = new int [n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=0;
        }
    }
    int a,b;
    cout<<"Podaj sasiadujace wierzcholki oddzielone spacja.\n";
    for(int i=0;i<m;i++){
        cin>>a>>b;
            A[a][b]=1;
    }
    system("CLS");
    wyswietl(n,A);
    sasiedzi(n,A);
    sasiedzi_kazdego(n,A);
    stopien_wychodzacy(n,A);
    stopien_wchodzacy(n,A);
    izolowany(n,A);
    petla(n,A);
    kr_dwukierunkowa(n,A);
    delete [] A;
}
