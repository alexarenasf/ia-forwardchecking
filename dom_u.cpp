using namespace std;
#include "forwardchecking.h"

void ForwardChecking::Dominio(int i){
  cout << "Dom_u(" << i << ") = {";
  for(unsigned int l = 0; l < this->Dom_u[i].size(); l++){
    if(l>0)
      cout << ", ";
    cout << this->Dom_u[i][l];
  }
  cout << "}" << endl;
}

void ForwardChecking::ImagenDominioCrear(int t, int i){ 
  for(unsigned int n = 0; n < this->Dom_u[i].size(); n++)
    this->ImDom_u[t][i].push_back(this->Dom_u[i][n]);
}

void ForwardChecking::ImagenDominioRestaurar(int t){
  for(int i = this->H + 1; i <= this->H + this->N; i++){
    //Restaurar imagenes en t
    this->Dom_u[i].clear();
    this->Dom_u[i].resize(this->ImDom_u[t][i].size());
    for(unsigned int n = 0; n < this->ImDom_u[t][i].size(); n++)
      this->Dom_u[i][n] = this->ImDom_u[t][i][n];
    
    //Borrar imagenes posteriores a t
    for(int tt = t; tt <= this->H + this->N; tt++){
      this->ImDom_u[tt][i].clear();
    }
  }
}


bool ForwardChecking::DominioVacio(int i){
  return this->Dom_u[i].empty();
}

void ForwardChecking::DominioEliminar(int i, int n){
  this->Dom_u[i].erase(remove(this->Dom_u[i].begin(), this->Dom_u[i].end(), n), this->Dom_u[i].end());
  if(this->Dom_u[i].empty())
    this->Dom_u[i].clear();
}

bool ForwardChecking::DominioContiene(int i, int n){
  return find(Dom_u[i].begin(), Dom_u[i].end(), n) != Dom_u[i].end();
}

int ForwardChecking::DominioPop(int i){
  int primero = this->Dom_u[i].front();
  this->Dom_u[i].erase(this->Dom_u[i].begin());
  return primero;
}


