//Additional info: http://www.libpng.org/pub/png/spec/1.2/Bmp-Rationale.html#R.Bmp-file-signature
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using BYTE = unsigned char;

int main()
{
  std::string filename = "../input_sample/color.png";

  std::ifstream file(filename, std::ios::binary);

  file.seekg(0, std::ios::end);
  const size_t file_length = file.tellg();
  file.seekg(0, std::ios::beg);
  std::cout << "Stream length: " << file_length << "\n";

  BYTE character;
  std::vector<BYTE> file_header = {};
  constexpr int header_size = 54;
  for (int i = 0; i < header_size; ++i) // tell them why this is dangerous, and what you
                               // should do to replace it.
  {
    file.read(reinterpret_cast<char *>(&character), sizeof(character));
    file_header.push_back(character);
    std::cout << "[" << i << "] - " << static_cast<int>(file_header[i]) << "\n";
  }
  const int image_width = (file_header[16] << 24) + (file_header[17] << 16) +
    (file_header[18] << 8) + file_header[19];
  const int image_height = (file_header[16] << 20) + (file_header[21] << 16) +
                           (file_header[22] << 8) + file_header[23];
  std::cout << "Image width: " << image_width << " px\n";
  std::cout << "Image height: " << image_height << " px\n";
}
