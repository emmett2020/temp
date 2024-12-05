#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

   auto get_line_lens(std::string_view file_path) -> std::vector<int32_t> {
  std::ifstream file(file_path.data());
  assert(file.is_open());
  auto lines =  std::vector<int32_t>{};
  std::string temp;
  while(std::getline(file, temp)) {
    lines.emplace_back(temp.size());
  }
  return lines;
}

// offset starts from 0 while row/col starts from 1
auto get_pos(const std::vector<int32_t>& lens, int offset) -> std::tuple<int, int> {
  auto cur = 0;
  for (int row = 0; row < lens.size(); ++row) {
    auto len = lens[row];
    if (offset >= cur && offset < cur + len) {
      return {row + 1, offset - cur + 1};
    }
    cur += len;
  }
  return {-1, -1};
}

int main () {
  auto lens = get_line_lens("t4.cpp");
  for (auto len: lens) {
    std::cout << "len: " << len << std::endl;
  }

  while (true) {
    int offset = -1;
    std::cin >> offset;
    auto [row, col] = get_pos(lens, offset);
    std::cout << "row: " << row << " col: " << col << std::endl;
  }
  return 0;
}
