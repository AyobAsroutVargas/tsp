#include "naive-tsp.h"

NaiveTsp::NaiveTsp(std::string filename) {
  distanceMatrix_.parseFromFile(filename);
}

int NaiveTsp::Solve(){
  std::vector<int> nodes;
  for (int i = 0; i < distanceMatrix_.nodes.size(); i++) {
    nodes.push_back(i);
  }

  int minPath = INT_MAX;
  do {
    int currentPath = 0;

    int k = 0;
    for (int i = 0; i < nodes.size(); i++) {
      currentPath += distanceMatrix_.matrix[k][nodes[i]];
      k = nodes[i];
    }
    currentPath += distanceMatrix_.matrix[k][0];

    minPath = std::min(minPath, currentPath);
  } while (std::next_permutation(nodes.begin(), nodes.end()));
  return minPath;
}
