#include "linq.hpp"
#include <assert.h>
#include <vector>

using linq::from;

void from_to_vector() {
  std::vector<int> xs = { 1, 2, 3 };
  std::vector<int> res = from(xs.begin(), xs.end()).to_vector();
  assert(res == xs);
}

void from_select() {
  const int xs[] = { 1, 2, 3 };
  std::vector<int> res = from(xs, xs + 3).to_vector();
  std::vector<int> expected = { 1, 2, 3 };
  assert(res == expected);
}

void from_drop_select() {
  const int xs[] = { 1, 2, 3 };
  std::vector<int> res = from(xs, xs + 3).drop(1).to_vector();
  std::vector<int> expected = { 2, 3 };
  assert(res == expected);
}

int main() {
  from_to_vector();
  from_select();
  from_drop_select();
  return 0;
}
