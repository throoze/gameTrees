#ifndef HASH_TABLE
#define HASH_TABLE
#include <tr1/unordered_map>

#ifndef OTHELLO
#define OTHELLO
#include "othello_cut.h"
#endif

using namespace std;

struct info_t {
  int value;
  int alpha;
  int betha;
  info_t(){}
};

struct stored_info_t {
  // [information to be stored in hash table]
  info_t white;
  info_t black;
  stored_info_t(){} // need at least one ctor without arguments
};

struct hash_function_t : public tr1::hash<state_t> {
    size_t operator()(const state_t &state) const {
        return state.hash();
    }
};

class hash_table_t : public tr1::unordered_map<state_t, stored_info_t, hash_function_t> {
};

stored_info_t lookup() {
  return NULL;
}

hash_table_t trans;

#endif
