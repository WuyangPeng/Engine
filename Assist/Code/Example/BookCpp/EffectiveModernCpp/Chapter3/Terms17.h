///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms17
            {
                namespace Example0
                {
                    class Widget
                    {
                    public:
                        // ...
                        Widget(Widget&& rhs);  // 移动构造函数

                        Widget& operator=(Widget&& rhs);  // 移动赋值运算符

                        // ...

                        ~Widget() noexcept = default;
                        Widget(const Widget& rhs) = default;
                        Widget& operator=(const Widget& rhs) = default;
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        ~Widget() noexcept;  // 用户定义的析构函数

                        // ...

                        Widget(const Widget& rhs) = default;  // 默认的复制构造函数的行为是正确的
                        Widget& operator=(const Widget& rhs) = default;  // 默认的复制赋值运算符的行为是正确的

                        // ...
                        Widget(Widget&& rhs) noexcept = default;
                        Widget& operator=(Widget&& rhs) noexcept = default;
                    };
                }

                class Base
                {
                public:
                    ~Base() noexcept = default;  // 使析构函数成为虚的
                    Base(Base&& rhs) noexcept = default;  // 提供移动操作的支持
                    Base& operator=(Base&& rhs) noexcept = default;

                    Base(const Base& rhs) = default;  //  提供复制操作的支持
                    Base& operator=(const Base& rhs) = default;

                    // ...
                };

                namespace Example0
                {
                    class StringTable
                    {
                    public:
                        StringTable() noexcept;
                        // ...
                        // 实现插入、擦除、检索等操作的函数
                        // 但没有函数来实现复制、移动和析构

                    private:
                        std::map<int, std::string> values;
                    };
                }

                void MakeLogEntry(MAYBE_UNUSED std::string_view log) noexcept;

                namespace Example1
                {
                    class StringTable
                    {
                    public:
                        StringTable() noexcept;
                        ~StringTable() noexcept;

                        // ...
                        // 其他函数不变

                    private:
                        std::map<int, std::string> values;  // 数据成员也不变
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        // ...
                        template <typename T>
                        Widget(const T& rhs);  // 以任意型别构造Widget

                        template <typename T>
                        Widget& operator=(const T& rhs);  // 以任意型别对Widget赋值

                        // ...
                    };
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_H
