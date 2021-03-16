#pragma once
#include <vector>

using std::vector;




// Traverses nodes in depth-first manner, listing on exit.
template <class G, class C, class K>
void dfsEndLoop(G& x, K u, C& vis, vector<K>& a) {
  vis[u] = true;
  for (auto& v : x.edges(u))
    if (!vis[v]) dfsEndLoop(x, v, vis, a);
  a.push_back(u);
}

template <class G, class K>
auto dfsEnd(G& x, K u) {
  auto vis = x.createVertexData(bool());
  vector<K> a;
  dfsEndLoop(x, u, vis, a);
  return a;
}
