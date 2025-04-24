## 📦 使用方法

---

### 方式一：通过 `FetchContent` 引入（推荐）

在你的 `CMakeLists.txt` 中添加以下内容：

```cmake
include(FetchContent)

FetchContent_Declare(
  fcbyk_dsal
  GIT_REPOSITORY https://github.com/your-username/cpp-dsal.git
  GIT_TAG main # 或指定版本号，例如 v1.0.0
)

FetchContent_MakeAvailable(fcbyk_dsal)

target_link_libraries(${PROJECT_NAME} PRIVATE fcbyk::fcbyk_dsal)
```

使用示例：

```cpp
#include <fcbyk/hello.hpp>

int main() {
    fcbyk::hello();
    return 0;
}
```

> ✅ **注意**：在 CLion 中 External Libraries 可能不显示源码，但功能正常，支持跳转和补全。

---

### 方式二：通过 `add_subdirectory`（本地开发推荐）

如果你将本项目作为子模块或直接下载源码，可添加：

```cmake
add_subdirectory(path/to/fcbyk_dsal)
target_link_libraries(${PROJECT_NAME} PRIVATE fcbyk::fcbyk_dsal)
```

---

### 方式三：安装 + `find_package`

```bash
git clone https://github.com/your-username/cpp-dsal.git
cd cpp-dsal
cmake -B build
cmake --build build
cmake --install build
```

然后在其他项目中：

```cmake
find_package(fcbyk_dsal REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fcbyk::fcbyk_dsal)
```