#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Lib
{
   public:
       char nomLibro[100],autor[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(nomLibro,"Sin resultados");
           strcpy(autor,"Sin resultados");
           strcpy(sc,"Sin resultados");
           strcpy(sc1,"Sin resultados");
           q=0;
           B=0;
           p=0;
       }
          void get();
          void estudiante();
          void pass();
          void administrador();
          void password();
          void getdata();
          void mostrar(int);
          void libros(int);
          void modificar();
          void ver(int);
          int branch(int);
          void error();
          void der(char[],int,int);
          void correcto(int,int,int,int,int,int);
};
void Lib::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tIntroduzca los datos :-\n";
                    cout<<"\n\t\tNombre del libro : ";
                    cin.getline(nomLibro,100);
                    for(i=0;nomLibro[i]!='\0';i++)
                    {
                    if(nomLibro[i]>='a'&&nomLibro[i]<='z')
                       nomLibro[i]-=32;
                    }
                    cout<<"\n\t\tAutor del libro : ";
                    cin.getline(autor,50);
                    cout<<"\n\t\tAno de publicacion : ";
                    cin.getline(sc1,50);
                    cout<<"\n\t\tIntroduzca ID del libro : ";
                    cin.getline(sc,20);
                    cout<<"\n\t\tDias en prestamo : ";
                    cin>>p;
                    cout<<"\n\t\tCantidad : ";
                    cin>>q;
}
void Lib::mostrar(int i)
{
    cout<<"\n\t\tNombre del libro : "<<nomLibro<<endl;
    cout<<"\n\t\tAutor : "<<autor<<endl;
    cout<<"\n\t\tID del libro : "<<sc<<endl;
    cout<<"\n\t\tAno de publicacion : "<<sc1<<endl;
    if(i==2)
    {
        cout<<"\n\t\tDias en prestamo : "<<p<<endl;
        cout<<"\n\t\tCantidad : "<<q<<endl;
    }
}
  void Lib::libros(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tSin resultados.";
                else
                {
                    cout<<"\n\t    ************ Lista de libros ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                mostrar(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPresione para continuar....";
                getch();
                system("cls");
                if(i==1)
                    estudiante();
                else
                    administrador();
    }
  void Lib::modificar()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Modificar :-\n";
    cout<<"\n\t\t1.Modificar libro existente\n\n\t\t2.Agregar nuevo libro\n\n\t\t3.Eliminar libro\n\n\t\t4.Volver\n";
    cout<<"\n\n\t\tSeleccione una opcion: ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tSin resultados\n";
                        cout<<"\n\t\tPresione para continuar....";
                        getch();
                        system("cls");
                        administrador();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tBuscar :-\n";
                        cout<<"\n\t\t1.Buscar con el nombre\n\n\t\t2.Buscar con ID\n";
                        cout<<"\n\t\tSeleccione una opcion : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tNombre del libro : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&nomLibro[i]!='\0'&&st1[i]!='\0'&&(st1[i]==nomLibro[i]||st1[i]==nomLibro[i]+32);i++);
                                        if(nomLibro[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tIntroduzca ID del libro : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tError....:(\n";
                            cout<<"\n\t\tPresione para continuar....";
                            getch();
                            system("cls");
                            modificar();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tSin resultado.\n";
                            cout<<"\n\t\tPresione una tecla....";
                            getch();
                            system("cls");
                            modificar();
                        }
                        else
                            cout<<"\n\t\tActualizado con exito.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tSe agrego con exito.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tSin resultado\n";
                        cout<<"\n\t\tPresione para continuar....";
                        getch();
                        intf1.close();
                        system("cls");
                        administrador();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tBorrar:-\n";
                        cout<<"\n\t\t1.Por nombre\n\n\t\t2.Por ID del libro\n";
                        cout<<"\n\t\tSeleccione una opcion : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tNombre del libro : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&nomLibro[i]!='\0'&&st1[i]!='\0'&&(st1[i]==nomLibro[i]||st1[i]==nomLibro[i]+32);i++);
                                        if(nomLibro[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tID del libro : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tError.....:(\n";
                            cout<<"\n\t\tPresione para continuar....";
                            getch();
                            system("cls");
                            modificar();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tSin resultados.\n";
                            cout<<"\n\t\tPresione para continuar....";
                            getch();
                            system("cls");
                            modificar();
                        }
                        else
                            cout<<"\n\t\tEliminado con exito.\n";

    }
    else if(i==4)
    {
    system("cls");
    administrador();
    }
    else
    {
    cout<<"\n\t\tError.\n";
    cout<<"\n\t\tPresione para continuar.....";
    getch();
    system("cls");
    modificar();
    }
    cout<<"\n\t\tPresione para continuar.....";
    getch();
    system("cls");
    administrador();

  }
  int Lib::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>Generos :-\n";
      cout<<"\n\t\t1.Matematicas\n\n\t\t2.Fisica\n\n\t\t3.Algebra\n\n\t\t4.Ingenieria\n\n\t\t5.Calculo\n\n\t\t6.Programacion\n\n\t\t7.Volver al menu\n";
      cout<<"\n\t\tSeleccione una opcion : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  estudiante();
                  else
                    administrador();
          default : cout<<"\n\t\tSeleccione una opcion :(";
                    getch();
                    system("cls");
                    branch(x);
        }
  }
  void Lib::ver(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tSin resultados.\n";
            cout<<"\n\t\t->Presiona para continuar.....";
            getch();
            system("cls");
            if(x==1)
            estudiante();
            else
            administrador();
        }

      system("cls");
      cout<<"\n\t\tSeleccione una opcion:-\n";
      cout<<"\n\t\t1.Buscar por nombre\n\n\t\t2.Buscar por ID del libro\n";

      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tNombre del libro : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&nomLibro[i]!='\0'&&ch[i]!='\0'&&(ch[i]==nomLibro[i]||ch[i]==nomLibro[i]+32);i++);
            if(nomLibro[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tLibro encontrado  :-\n";
                        mostrar(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tID del libro : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tLibro encontrado :-\n";
                            mostrar(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tOpcion no valida :(";
             getch();
             system("cls");
             ver(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tLibro no disponible :( \n";

    cout<<"\n\t\tPresiona para continuar....";
    getch();
    system("cls");
    if(x==1)
    estudiante();
    else
    administrador();


  }
void Lib::error()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Prestamos :-\n";
    cout<<"\n\t\t1.Prestamo\n\n\t\t2.Ver prestamo de libro \n\n\t\t3.Buscar estudiantes con prestamo\n\n\t\t4.Buscar con codigo\n\n\t\t5.Regresar libro\n\n\t\t6.Regresar\n\n\t\tElegir opcion : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Por favor introduzca los datos :-\n";
    cout<<"\n\t\tNombre del libro : ";
    cin.getline(nomLibro,100);
    cout<<"\n\t\tID del libro : ";
    cin.getline(sc,20);
    //strcpy(st,sc);
    der(sc,b,1);
    cout<<"\n\t\tNombre del estudiante : ";
    cin.getline(autor,100);
    cout<<"\n\t\tCodigo del estudiante : ";
    cin.getline(sc1,20);
    cout<<"\n\t\tSeleccione fecha: ";
    cin>>q>>B>>p;
    ofstream outf("estudiante.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tGracias.\n";
    }
    else if(i==2)
    {
    ifstream intf("estudiante.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->Datos :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tNombre del estudiante : "<<autor<<"\n\t\t"<<"Codigo del estudiante : "<<sc1<<"\n\t\t"<<"Nombre del libro : "<<nomLibro<<"\n\t\t"<<"ID del libro : "<<sc<<"\n\t\t"<<"Fecha : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Por favor, introduzca los datos :-\n";
        cout<<"\n\n\t\tNombre del estudiante: ";
        cin.getline(st,50);
        cout<<"\n\n\t\tCodigo del estudiante : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("estudiante.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
              if(sc1[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->Datos :-\n";
                      cout<<"\n\t\tNombre del estudiante : "<<autor;
                      cout<<"\n\t\tCodigo del estudiante : "<<sc1;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Detalles del libro *******\n";
                  cout<<"\n\t\tNombre del libro : "<<nomLibro;
                  cout<<"\n\t\tID del libro : "<<sc;
                  cout<<"\n\t\tFecha : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tSin resultados.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Introducir los siguientes datos :-\n";
    cout<<"\n\n\t\tCodigo del estudiante : ";
    cin.getline(st,50);
    cout<<"\n\t\tID del libro : ";
    cin.getline(st1,20);
    fstream intf("estudiante.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\n\t\tSeleccionar fecha nueva : ";
                    cin>>q>>B>>p;
                    correcto(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tActualizado exitosamente2."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Introducir los siguientes datos :-\n";
    cout<<"\n\t\tID del libro : ";
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\n\t\tCodigo del estudiante : ";
    cin.getline(st,20);
    cout<<"\n\t\tFecha de hoy : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("estudiante.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    correcto(q,B,p,d,m,y);
                    cout<<"\n\t\tActualizado exitosamente.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("estudiante.txt");
    rename("temp.txt","estudiante.txt");
    }
    else if(i==6)
    {
    system("cls");
    administrador();
    }
    else
        cout<<"\n\t\tOpcion no valida.\n";

    cout<<"\n\n\t\tPresiona para continuar.....";
    getch();
    system("cls");
    administrador();
}
void Lib::correcto(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tDias a usar el libro : "<<n2;

}
void Lib::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
        if(sc[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tNo se encontro el libro.\n";
        cout<<"\n\n\t\tPulsa para continuar.....";
        getch();
        system("cls");
        error();
    }
    intf.close();
}
void Lib::get()
{
   int i;
        cout<<"\n\t*********** LIBRERIA CUCEI ***********\n"<<"\n\t\t\t\n";
        cout<<"\n\t\t>>Seleccione una opcion para ingresar \n";
        cout<<"\n\t\t1.Estudiante\n\n\t\t2.Administrador\n\n\t\t3.Cerrar programa\n";
        cout<<"\n\t\tSelecciona tu opcion: ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            estudiante();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPor favor seleccione una opcion valida :(";
            getch();
            system("CLS");
           get();
        }
}
void Lib::estudiante()
{
    int i;
        cout<<"\n\t************ Bienvenido estudiante ************\n";
        cout<<"\n\t\t>>Selecciona una opcion:\n";
        cout<<"\n\t\t1.Ver libros\n\n\t\t2.Buscar un libro\n\n\t\t3.Ir al menu principal\n\n\t\t4.Cerrar programa\n";
        cout<<"\n\t\tIr a : ";
        cin>>i;
            if(i==1)
                libros(1);
            else if(i==2)
                ver(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tSeleccione una opcion valida :(";
                getch();
                system("cls");
                estudiante();
            }
}
void Lib::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tIntroducir contrasena : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        administrador();
    }
    else
    {
        cout<<"\n\n\t\tContrasena incorrecta.\n\n\t\intentelo de nuevo.....\n";
        getch();
        system("cls");
        get();
    }
}
void Lib::administrador()
{
    int i;
        cout<<"\n\t************ Bienvenido administrador ************\n";
        cout<<"\n\t\t>>Seleccione una opcion valida:\n";
        cout<<"\n\t\t1.Ver libros\n\n\t\t2.Buscar un libro \n\n\t\t3.Modificar/Agregar libro\n\n\t\t4.Prestamo de libro\n\n\t\t5.Ir al menu principal\n\n\t\t6.Cambiar contrasena \n\n\t\t7.Cerrar programa\n";
        cout<<"\n\t\tIr a : ";
        cin>>i;
        switch(i)
        {
            case 1:libros(2);
                     break;
            case 2:ver(2);
                     break;
            case 3:modificar();
                     break;
            case 4:error();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:password();
                    break;
            case 7:exit(0);
            default:cout<<"\n\t\tSeleccione una opcion valida :(";
            getch();
            system("cls");
            administrador();
        }
}
void Lib::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\n\t\tIntroducir contrasena anterior : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**La contrasena debe ser menor a 20 caracteres, no usar espacios**\n\n";
        cout<<"\n\t\tIntroducir nueva contrasena : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tOpcion no valida \n\n\t\tPresione para volver a intentar.....";
                getch();
                system("cls");
                password();
                administrador();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tLa contrasena se modifico correctamente.";
        cout<<"\n\t\tPresione para continuar......";
        getch();
        system("cls");
        administrador();
    }
    else
    {
        cout<<"\n\n\t\t Error.....\n";
        cout<<"\n\t\tPresione 2 para volver al menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            administrador();
        }
    }
}
int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}
