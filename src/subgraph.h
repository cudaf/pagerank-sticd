#pragma once
#include <unordered_set>

using std::unordered_set;




template <class G, class K>
auto& subgraph(G& x, unordered_set<K> vs, G& a) {
  for (auto u : x.vertices()) {
    if (vs.count(u) == 0) continue;
    a.addVertex(u, x.vertexData(u));
    for (auto v : x.edges(u))
      if (vs.count(v) > 0) a.addEdge(u, v, x.edgeData(u, v));
  }
  return a;
}
