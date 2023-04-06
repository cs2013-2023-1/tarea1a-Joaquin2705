#include "foo.h"

Matriz2D::Matriz2D(){
    this->filas=3;
    this->columnas=3;
    ptr=new float*[filas];
    for(int i=0;i<filas;i++){
        ptr[i]=new float[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            float numero=rand()%10;
            ptr[i][j]=numero/10;
        }
    }

}

Matriz2D::Matriz2D(int n){
    this->filas=n;
    this->columnas=n;
    ptr=new float*[n];
    for(int i=0;i<n;i++){
        ptr[i]=new float[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            float numero=rand()%10;
            ptr[i][j]=numero/10;
        }
    }


}

Matriz2D::Matriz2D(int n, int m): filas(n),columnas(m){
    ptr=new float*[n];
    for(int i=0;i<n;i++){
        ptr[i]=new float[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            float numero=rand()%10;
            ptr[i][j]=numero/10;
        }
    }


}

Matriz2D::Matriz2D(const Matriz2D& m){
    filas=m.filas;
    columnas=m.columnas;
    ptr=m.ptr;
}

Matriz2D::Matriz2D(Matriz2D&& m){
    this->filas=m.filas;
    this->columnas=m.columnas;
    this->ptr=m.ptr;
    m.ptr=NULL;
}

Matriz2D t(Matriz2D& m){
    Matriz2D transpuesta(m.columnas,m.filas);
    for(int i=0;i<transpuesta.filas;i++) {
        for (int j = 0; j < transpuesta.columnas; j++) {
            transpuesta.ptr[i][j] = m.ptr[j][i];
        }
    }
    return transpuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    for (int i=0;i<m.filas;i++) {
        for (int j=0;j<m.columnas;j++) {
            os << m.ptr[i][j] << " ";
        }
        os<<endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    Matriz2D suma(m1.filas,m2.columnas);
    for(int i=0;i<suma.filas;i++){
        for(int j=0;j<suma.columnas;j++){
            suma.ptr[i][j]= m1.ptr[i][j]+m2.ptr[i][j];
        }
    }
    return suma;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    Matriz2D resta(m1.filas,m2.columnas);
    for(int i=0;i<resta.filas;i++){
        for(int j=0;j<resta.columnas;j++){
            resta.ptr[i][j]= m1.ptr[i][j]-m2.ptr[i][j];
        }
    }
    return resta;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
   if(m1.columnas==m2.filas){
        Matriz2D multiplicacion(m1.filas,m2.columnas);
        for(int i=0;i<multiplicacion.filas;i++){
            for(int j=0;j<multiplicacion.columnas;j++){
                multiplicacion.ptr[i][j]=0;
                for(int w=0;w<m1.columnas;w++){
                    multiplicacion.ptr[i][j]+=m1.ptr[i][w]*m2.ptr[w][j];
                }
            }
        }
        return multiplicacion;
    }
    else{
        return 0;
    }
}

Matriz2D operator+(const Matriz2D& m, float n){
    Matriz2D multiplicacion(m.filas,m.columnas);
    for(int i=0;i<multiplicacion.filas;i++){
        for(int j=0;j<multiplicacion.columnas;j++){
            multiplicacion.ptr[i][j]= m.ptr[i][j]+ n;
        }
    }
    return multiplicacion;
}

Matriz2D operator-(const Matriz2D& m, float n){
    Matriz2D multiplicacion(m.filas,m.columnas);
    for(int i=0;i<multiplicacion.filas;i++){
        for(int j=0;j<multiplicacion.columnas;j++){
            multiplicacion.ptr[i][j]= m.ptr[i][j]- n;
        }
    }
    return multiplicacion;
}

Matriz2D operator*(const Matriz2D& m, float n){
    Matriz2D multiplicacion(m.filas,m.columnas);
    for(int i=0;i<multiplicacion.filas;i++){
        for(int j=0;j<multiplicacion.columnas;j++){
            multiplicacion.ptr[i][j]= m.ptr[i][j]* n;
        }
    }
    return multiplicacion;
}

Matriz2D operator/(const Matriz2D& m, float n){
    Matriz2D multiplicacion(m.filas,m.columnas);
    for(int i=0;i<multiplicacion.filas;i++){
        for(int j=0;j<multiplicacion.columnas;j++){
            multiplicacion.ptr[i][j]= m.ptr[i][j]/ n;
        }
    }
    return multiplicacion;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
