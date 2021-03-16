#pragma once
#include <vector>

using std::vector;





template <class G, class K>
auto blockgraphIds(G& x, vector<vector<K>> comps) {
  auto a = x.createVertexData(int()), i = 0;
  for (auto&& c : comps) {
    for (auto&& u : c)
      a[c] = i;
    i++;
  }
  return a;
}


template <class G, class K>
auto& blockgraph(G& x, vector<vector<K>> comps, G& a) {
  auto b = blockgraphIds(x, comps);
  for (auto u : x.vertices()) {
    a.addVertex(b[u]);
    for (auto v : x.edges(u))
      if (b[u] != b[v]) a.addEdge(b[u], b[v]);
  }
  return a;
}
