#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

namespace {
auto get_line_lens(std::string_view file_path) -> std::vector<uint32_t> {
  auto lines = std::vector<uint32_t>{};
  auto file = std::ifstream{file_path.data()};

  auto temp = std::string{};
  while (std::getline(file, temp)) {
    // LF
    lines.emplace_back(temp.size() + 1);
  }
  return lines;
}

// offset starts from 0 while row/col starts from 1
auto get_position(const std::vector<uint32_t> &lens, int offset)
    -> std::tuple<int32_t, int32_t> {
  auto cur = uint32_t{0};
  for (int row = 0; row < lens.size(); ++row) {
    auto len = lens[row];
    if (offset >= cur && offset < cur + len) {
      return {row + 1, offset - cur + 1};
    }
    cur += len;
  }
  return {-1, -1};
}

} // namespace

int main() {
  auto ret = get_line_lens("t3.cpp");
  while (true) {
    std::cout << "enter offset: ";
    int offset = 0;
    std::cin >> offset;
    auto [row, col] = get_position(ret, offset);
    std::cout << "row: " << row << ", col: " << col << "\n";
  }
  return 0;
}
