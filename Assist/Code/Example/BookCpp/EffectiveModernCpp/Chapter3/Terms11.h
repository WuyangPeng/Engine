///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 15:03)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms11
            {
                namespace Example0
                {
                    template <class charT, class traits = std::char_traits<charT>>
                    class BasicIos : public std::ios_base
                    {
                    public:
                        // ...

                    private:
                        BasicIos(const BasicIos&);  // 未定义
                        BasicIos& operator=(const BasicIos&);  // 未定义
                    };
                }

                namespace Example1
                {
                    template <class charT, class traits = std::char_traits<charT>>
                    class BasicIos : public std::ios_base
                    {
                    public:
                        // ...

                        BasicIos(const BasicIos&) = delete;
                        BasicIos& operator=(const BasicIos&) = delete;

                        // ...
                    };
                }

                namespace Example0
                {
                    bool IsLucky(MAYBE_UNUSED int number) noexcept;
                }

                namespace Example1
                {
                    bool IsLucky(MAYBE_UNUSED int number) noexcept;  // 原始版本

                    bool IsLucky(char) = delete;  // 拒绝char型别

                    bool IsLucky(bool) = delete;  // 拒绝bool型别

                    bool IsLucky(double) = delete;  // 拒绝double和float型别
                }

                template <typename T>
                void ProcessPointer(MAYBE_UNUSED T* ptr)
                {
                }

                template <>
                void ProcessPointer<void>(void* ptr) = delete;

                template <>
                void ProcessPointer<char>(char* ptr) = delete;

                template <>
                void ProcessPointer<const void>(const void* ptr) = delete;

                template <>
                void ProcessPointer<const char>(const char* ptr) = delete;

                namespace Example0
                {
                    class Widget
                    {
                    public:
                        // ...
                        template <typename T>
                        void ProcessPointer(MAYBE_UNUSED T* ptr) noexcept
                        {
                        }

                    private:
                        template <>
                        void ProcessPointer<void>(void* ptr);  // 错误
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        // ...
                        template <typename T>
                        void ProcessPointer(MAYBE_UNUSED T* ptr)
                        {
                        }
                    };

                    // 仍然具备public访问层级，但被删除了。
                    template <>
                    void Widget::ProcessPointer<void>(void* ptr) = delete;
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_H
