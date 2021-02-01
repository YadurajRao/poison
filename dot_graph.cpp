#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& a);

template <typename T, typename U, typename V>
ostream& operator<<(ostream& os, const tuple<T, U, V>& a);

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a);

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& a) {
  os << "(" << a.first << ", " << a.second << ")";
  return os;
}

template <typename T, typename U, typename V>
ostream& operator<<(ostream& os, const tuple<T, U, V>& a) {
  os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  os << "{";
  for (unsigned i = 0; i < a.size(); i++) {
    os << a[i];
    if (i != a.size()) os << ", ";
  }
  os << "}";
  return os;
}

template <typename T, typename U>
void DotWriter(ofstream& ofs, const vector<pair<T, T>>& edges,
               const vector<U>& labels, T root, bool has_labels = false,
               bool is_directed = false) {
  assert(ofs.is_open());
  assert(!has_labels || (edges.size() == labels.size()));
  if (is_directed) {
    ofs << "digraph G {\n";
  } else {
    ofs << "graph G {\n";
  }
  ofs << "  nodesep = 2.0;\n";
  ofs << "  edge [color=\"#ff5555\"];\n";
  unordered_set<T> st;
  for (unsigned i = 0; i < edges.size(); i++) {
    T from = edges[i].first, to = edges[i].second;
    st.insert(from);
    st.insert(to);
    ofs << "  " << from << (is_directed ? " -> " : " -- ") << to;
    ofs << " [style=bold";
    if (has_labels) {
      ofs << ",label=\"" << labels[i] << "\"";
    }
    ofs << "];\n";
  }
  bool is_rooted = false;
  for (auto it = st.begin(); it != st.end(); it++) {
    ofs << "  " << *it << " [shape=circle";
    if (root == *it) {
      ofs << ",peripheries=2";
      is_rooted = true;
    }
    ofs << "];\n";
  }
  ofs << "}\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // Example usage
  vector<pair<int, int>> edges;
  vector<int> labels;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    pair<int, int> ed;
    int la;
    cin >> ed.first >> ed.second >> la;
    edges.emplace_back(ed);
    label.push_back(la);
  }
  ofstream ofs;
  ofs.open("DotTarget.dot");
  DotWriter(ofs, edges, labels, 1, true, false);
  return 0;
}
