cmake_minimum_required(VERSION 3.28)

project(fcbyk_dsal
        VERSION 1.0.0
        LANGUAGES CXX
        DESCRIPTION "fcbyk's C++ Data Structures and Algorithms Library (GitHub: cpp-dsal)"
)

# 命名空间配置
set(NAMESPACE fcbyk)
set(TARGET_NAME fcbyk_dsal)
set(REPO_NAME "cpp-dsal")
set(TARGET_NAMESPACE "fcbyk")

# C++标准配置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 安装辅助模块
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# 添加库目标
add_library(${TARGET_NAME} STATIC
        src/fcbyk/hello.cpp
)

# 添加别名目标，方便引用
add_library(${TARGET_NAMESPACE}::${TARGET_NAME} ALIAS ${TARGET_NAME})

# 头文件包含路径
target_include_directories(${TARGET_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# 安装头文件
install(DIRECTORY include/${TARGET_NAMESPACE}
        DESTINATION include
)

# 安装库文件
install(TARGETS ${TARGET_NAME}
        EXPORT ${TARGET_NAME}Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION include
)

# 生成导出目标
install(EXPORT ${TARGET_NAME}Targets
        FILE ${TARGET_NAME}Targets.cmake
        NAMESPACE ${TARGET_NAMESPACE}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME}
)

# 配置包配置文件
set(CONFIG_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME})
configure_package_config_file(
        cmake/${TARGET_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}Config.cmake
        INSTALL_DESTINATION ${CONFIG_INSTALL_DIR}
        PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)

# 写入版本文件
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

# 安装配置文件
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}ConfigVersion.cmake
        DESTINATION ${CONFIG_INSTALL_DIR}
)

# 启用测试
enable_testing()

# 测试目标
add_executable(run_test tests/test_print.cpp)
target_link_libraries(run_test PRIVATE ${TARGET_NAME})

# 添加测试
add_test(
        NAME run_test
        COMMAND run_test
)