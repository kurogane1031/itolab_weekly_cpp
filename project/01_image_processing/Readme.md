# Image Processing
The aim for this project is to learn how to read image file using c++.

### <a name="week04-beginning"></a>WEEK04: Read image file as binary
Let's start by just reading our sample png image in the `input_sample` folder.
The name of the file is `color3.png`. 

Let's begin by defining a `std::string` type variable called `filename` in the body of `main()` function.
To use `std::string`, the header file called `string` needs to be included.

```cpp
#include <string>

int main()
{
  std::string filename = "color.png";
}
```

Note that `color.png` is just a *string literal*. We do the actual reading by using `ifstream`, as follows.
To use it, `fstream` header is needed. To initialized `std::ifstream`, `const char* filename` and `ios_base::openmode` [1](http://www.cplusplus.com/reference/fstream/ifstream/ifstream/). 

```cpp
std::ifstream file(filename, std::ios::binary)
```

Here, filename `color.png` is read as binary file (`std::ios::binary`).

##### Why do I have `std::`?
Now, one may notice that I didn't use `using namespace std;` at the `global scope` to omitted the usage of `std`.

Wait, what is global scope?

To simplify things, it things outside of any function or class or anything. Example of `using namespace std` at global scope and omitting `std` is as follows

```cpp
#include <string>
using namespace std; // using namespace std at global scope

int main()
{
  string filename = "color.png";
}
```
Cpp core guideline explains the reason [2](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#sf7-dont-write-using-namespace-at-global-scope-in-a-header-file). 
Basically if for some reason somebody writes a code like this

```cpp
#include <string>
using namespace std; // this is bad, a no no

bool copy( ... ) { ...; }
int main()
{
  copy( ... ); // there is now a local string and a std::string. The compiler will throw an error since it doesnt know which one you're trying to use
}

```
since there might be a local function that has similar name to the one in `std` libraries, it will become an ambiguous situation. 

##### Get the length of the binary stream
Back to our original implementation. There are a two things we can do for this week. First is to read the length of the binaries in `file`. Assign it to some variable. Here we will use two member function from `ifstream`; `seekg` and `tellg` and two from `std::ios`; `std::ios::end` and `std::ios::beg`

```cpp
file.seekg(0, std::ios::end); // set the position of the input sequence to the end of the stream
const int file_length = file.tellg(); // tell the current position of the stream
file.seekg(0,std::ios::beg); // bring back position to the beginning of the stream.
```
The easiest way to imagine is a stream is a bunch of people lining up. `seekg` is an arrow pointing any position you specify, cast of `file.seekg(0, std::ios::end)` will move that arrow all the way until it points to the last person standing at line. `tellg` will tell you the position number where is your arrow pointing at. Then `file.seekg(0, std::ios::beg)` bring back the arrow to the first person from the line.

Now why did I use `const` there? Why not just declare it without `const`. `const` is a promise we tell to the compiler that a variable will not change throughout the runtime. In this case, `file_length` tells us the total length of the binary stream in `color.png`. So it shouldn't change and will not change. Whenever somebody read my code, despite not having any comments beside it, they should know the variable `file_length` is not something they should manipulate.

##### Read file header and get the width of the image
```cpp
unsigned char character;
constexpr int header_size = 54;
std::vector<unsigned char> file_header;
for (int i = 0; i < header_size; ++i)
{
  file.read(reinterpret_cast<unsigned char*>(&character), sizeof(character));
  file_header.push_back(character);
}
```

Now several things to notice here. One is `std::vector`, next is the `reinterpret_cast` with `sizeof` and third is the `push_back`. `std::vector` and `push_back`. Our laboratory will cover `array` and `vector` topic from the book next week, so all of these will be explain accordingly together with `reinterpret_cast`. 

Now, why `header_size = 54`? Well, most of the crucial information from an image, for example file `signature`, `width`, `height` or `compression` type is stored here.  Libpng explains this topic well [3](http://www.libpng.org/pub/png/spec/1.2/PNG-Structure.html) so you can go and read it there. 

Now since the information is stored in the header, we can simply just search the necessary place for the width of the image. For simplicity, it is located at index `16` to `19`, in `big endian` format. `Big endian` will be explained next week too.

```
const int image_width = (file_header[16] << 24) + (file_header[17] << 16) + (file_header[18] << 8) + file_header[19];
```

Now, you can do the same too for the height, which located at index `20` to `23`.
```
const int image_height = (file_header[16] << 20) + (file_header[21] << 16) + (file_header[22] << 8) + file_header[23];
```
Since there is too many things to discussed about, I will update the notes from time to time.

The copy of the code is available in `src` folder. For simplicity, starting next week, we will use `bmp` file instead of `png`. The reason i talk about `png` this week is only to introduce the `endianess`. 
