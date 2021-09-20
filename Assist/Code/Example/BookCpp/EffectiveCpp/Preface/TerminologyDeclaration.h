///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:46)

#ifndef EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H
#define EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H

#include "Example/BookCpp/EffectiveCpp/EffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        // ��������ʽ
        extern int x;
        // ��������ʽ
        [[nodiscard]] constexpr std::size_t NumDigits(int number) noexcept;
        // ������ʽ
        class Widget;
        // ģ������ʽ
        template <typename T>
        class GraphNode;

        // ��������ʽ
        // �˺�����������������ָ���������ʮλ������2����λ������3��
        [[nodiscard]] constexpr std::size_t NumDigits(int number) noexcept
        {
            std::size_t digitsSoFar = 1;
            while ((number /= 10) != 0)
            {
                ++digitsSoFar;
            }
            return digitsSoFar;
        }

        // class �Ķ���ʽ
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

        // template �Ķ���ʽ
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
            // Ĭ�Ϲ��캯��
            A() = default;
        };

        class B
        {
        public:
            // Ĭ�Ϲ��캯��
            explicit B(int a = 0, bool b = true) noexcept;
        };

        class C
        {
        public:
            // ����Ĭ�Ϲ��캯��
            explicit C(int a) noexcept;
        };

        void DoSomething(B bObject) noexcept;
        [[nodiscard]] bool HasAcceptableQuality(Widget w) noexcept;
    }
}

#endif  // EFFECTIVE_CPP_PREFACE_TERMINOLOGY_DECLARATION_H
