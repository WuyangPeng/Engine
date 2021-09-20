///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:46)

#ifndef EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H
#define EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H

#include "Example/BookCpp/EffectiveCpp/EffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        // 对象声明式
        extern int x;
        // 函数声明式
        [[nodiscard]] constexpr std::size_t NumDigits(int number) noexcept;
        // 类声明式
        class Widget;
        // 模板声明式
        template <typename T>
        class GraphNode;

        // 函数定义式
        // 此函数返回其参数的数字个数，例如十位数返回2，百位数返回3。
        [[nodiscard]] constexpr std::size_t NumDigits(int number) noexcept
        {
            std::size_t digitsSoFar = 1;
            while ((number /= 10) != 0)
            {
                ++digitsSoFar;
            }
            return digitsSoFar;
        }

        // class 的定义式
        class Widget
        {
        public:
            Widget() = default;
            ~Widget() noexcept = default;
            Widget(const Widget& rhs) = default;
            Widget& operator=(const Widget& rhs) = default;
            Widget(Widget&& rhs) noexcept = default;
            Widget& operator=(Widget&& rhs) noexcept = default;
        };

        // template 的定义式
        template <typename T>
        class GraphNode
        {
        public:
            GraphNode() = default;
            ~GraphNode() noexcept = default;
            GraphNode(const GraphNode& rhs) = default;
            GraphNode& operator=(const GraphNode& rhs) = default;
            GraphNode(GraphNode&& rhs) noexcept = default;
            GraphNode& operator=(GraphNode&& rhs) noexcept = default;
        };

        class A
        {
        public:
            // 默认构造函数
            A() = default;
        };

        class B
        {
        public:
            // 默认构造函数
            explicit B(int a = 0, bool b = true) noexcept;
        };

        class C
        {
        public:
            // 不是默认构造函数
            explicit C(int a) noexcept;
        };

        void DoSomething(B bObject) noexcept;
        [[nodiscard]] bool HasAcceptableQuality(Widget w) noexcept;
    }
}

#endif  // EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H
