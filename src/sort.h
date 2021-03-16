#pragma once
#include <vector>
#include <algorithm>
#include "dfsEnd.h"

using std::vector;
using std::reverse;




// Find topological sort of nodes.
template <class G>
auto sort(G& x) {
  using K = typename G::TKey;
  auto vis = x.createVertexData(bool());
  vector<K> a;
  for (auto u : x.vertices())
    if (!vis[u]) dfsEndLoop(x, u, vis, a);
  reverse(a.begin(), a.end());
  return a;
}
