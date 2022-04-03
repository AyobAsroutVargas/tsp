#include "dp-tsp.h"

DpTsp::DpTsp(std::string filename) {
  distanceMatrix_.parseFromFile(filename);
}

int DpTsp::Solve(){
  ALL_VISITED = (1<<distanceMatrix_.matrix.size()) -1;
  return dpTsp(1,0);
}

int DpTsp::dpTsp(int visitedNodes, int pos) {
  if(visitedNodes == ALL_VISITED) {
    return distanceMatrix_.matrix[pos][0];
  }

  int minPatth = INT_MAX;
  for(int city = 0; city < distanceMatrix_.matrix.size(); city++) {
    if((visitedNodes&(1<<city)) == 0) { //Si el nodo city no ha sido visitado
      int newPath = distanceMatrix_.matrix[pos][city] + dpTsp(visitedNodes|(1<<city),city); //coste de ir desde la posicion actual a city + coste minimo de visitar todos los nodos restantes y volver al inicio
      minPatth = std::min(minPatth, newPath);
    }
  }
  return minPatth;
}