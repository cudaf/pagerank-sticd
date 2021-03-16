#pragma once
#include "components.h"
#include "blockgraph.h"
#include "sort.h"
#include "subgraph.h"
#include "pageRank.h"




template <class G, class T>
auto pageRankSticdCore(G& x, G& y, T p, T E) {
  float t;
  DiGraph<> b, s;
  auto rank = x.createVertexData(T());
  auto done = x.createVertexData(bool());
  auto cs = components(x, y);
  blockgraph(x, cs, b);
  auto bn = sort(b);
  for (auto bi : bn) {
    subgraph(x, cs[bi], s);
    pageRank(t, s);
  }
  for (var i=0, I=yn.length; i<I; i++) {
    // var xi = subgraph(x, Array.prototype.concat.apply([], cs.slice(0, i+1)));
    // ranks = pageRank(xi, o, ranks, done);
    // done = done.map((d, i) => d || xi.nodes[i]);
  }
  return ranks;
}


template <class G, class T>
auto pageRankSticd(float& t, G& x, G& y, T p, T E) {
  auto a = x.createVertexData(T());
  auto r = x.createVertexData(T());
  t = measureDuration([&]() { pageRankSticdCore(a, r, x, p, E); });
  return a;
}

template <class G, class T=float>
auto pageRankPush(float& t, G& x, pageRankOptions<T> o=pageRankOptions<T>()) {
  return pageRankPush(t, x, o.damping, o.convergence);
}
