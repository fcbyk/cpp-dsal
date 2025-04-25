#pragma once
#include <iostream>
#include <string>
#include <utility>

namespace fcbyk {

    /**
     * @brief 通用打印函数模板
     * @tparam T 可打印类型
     * @param value 要打印的值
     * @details
     * 默认行为与std::cout一致，对以下类型有特殊处理：<br>
     * • bool类型输出"true"/"false"<br>
     * • 字符串类型直接输出内容<br>
     * • 数组类型输出为[a, b, c]格式<br>
     * <br>
     * 注意：对自定义类型需要重载 operator <<
     */
    template <typename T>
    void print(const T& value) {
        std::cout << value;
    }

    /**
     * @brief bool类型的特化打印
     * @param value 布尔值
     * @details 将bool值输出为 true/false 而非1/0
     */
    template <>
    inline void print<bool>(const bool& value) {
        std::cout << (value ? "true" : "false");
    }

    /**
     * @brief std::string 类型的特化打印
     * @param str 字符串对象
     */
    template <>
    inline void print<std::string>(const std::string& str) {
        std::cout << str;
    }

    /**
     * @brief C风格字符串的特化打印
     * @param str 以空字符结尾的字符串指针
     */
    template <>
    inline void print<const char*>(const char* const& str) {
        std::cout << str;
    }

    /**
     * @brief 处理初始化列表的带换行打印
     * @tparam T 列表元素类型（自动推导）
     * @param list 要打印的初始化列表
     * @details
     * 此函数专门处理用花括号{}初始化的列表，输出格式为：[元素1, 元素2, 元素3]<br>
     *
     * 特性：<br>
     * - 自动处理任意类型的初始化列表<br>
     * - 元素间用逗号和空格分隔<br>
     * - 列表首尾包含方括号<br>
     * - 打印完成后自动换行<br>
     *
     * @note 需要C++11及以上标准支持
     * @see print() 基础打印函数
     */
    template <typename T>
    void println(std::initializer_list<T> list) {
        std::cout << "[";
        bool first = true;
        for (const auto& item : list) {
            if (!first) std::cout << ", ";
            print(item);
            first = false;
        }
        std::cout << "]\n";
    }

    /**
     * @brief 字符串字面量的特化打印
     * @tparam N 字符串长度（自动推导，包含空字符）
     * @param str 字符串字面量
     * @details 处理如"hello"这样的编译期字符串
     */
    template <size_t N>
    inline void print(const char (&str)[N]) {
        std::cout << str;
    }

    /**
     * @brief 普通字符数组的打印
     * @tparam N 数组长度
     * @param arr 字符数组
     * @details 输出格式为[a, b, c]，适用于不以空字符结尾的字符数组
     */
    template <size_t N>
    inline void print(char (&arr)[N]) {
        std::cout << "[";
        for (size_t i = 0; i < N; ++i) {
            print(arr[i]);
            if (i != N - 1) std::cout << ", ";
        }
        std::cout << "]";
    }

    /**
     * @brief 通用数组的打印
     * @tparam T 数组元素类型
     * @tparam N 数组长度
     * @param arr 任意类型数组
     * @details 输出格式为[a, b, c]，支持任意元素类型的数组
     */
    template <typename T, size_t N>
    inline void print(const T (&arr)[N]) {
        std::cout << "[";
        for (size_t i = 0; i < N; ++i) {
            print(arr[i]);
            if (i != N - 1) std::cout << ", ";
        }
        std::cout << "]";
    }

    /**
     * @brief 带换行的可变参数打印
     * @tparam Args 可变参数类型包
     * @param args 要打印的参数包
     * @details 依次打印所有参数后自动换行，支持任意数量和类型的参数
     */
    template <typename... Args>
    void println(Args&&... args) {
        (print(std::forward<Args>(args)), ...);
        std::cout << std::endl;
    }

    /**
     * @brief 无参换行打印
     * @details 仅打印一个换行符
     */
    inline void println() {
        std::cout << std::endl;
    }

}