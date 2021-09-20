///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/28 9:37)

#ifndef EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_WIDGET_H
#define EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_WIDGET_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Preface
        {
            // �ඨ��
            class Widget final
            {
            public:
                Widget() noexcept = default;
                ~Widget() noexcept = default;
                Widget(const Widget& rhs) noexcept = default;
                Widget& operator=(const Widget& rhs) noexcept = default;

                // rhs�Ǹ���ֵ��������������ֵ�����ͱ�
                Widget(Widget&& rhs) noexcept = default;
                Widget& operator=(Widget&& rhs) noexcept = default;
            };

            class Matrix final
            {
            };

            NODISCARD Matrix operator+(MAYBE_UNUSED const Matrix& lhs, MAYBE_UNUSED const Matrix& rhs) noexcept;

            // �����е�ʡ�ԺŶ���Դ�����ɲ��֡�
            template <typename... Ts>
            void ProcessVals(MAYBE_UNUSED const Ts&... params) noexcept
            {
                // ...
                // ����һ���е�ʡ�Ժţ����ʾ������������������롱��
            }

            // SomeFunc���β�w��ֵ����
            void SomeFunc(MAYBE_UNUSED Widget w) noexcept;

            void PrefaceDeclaration() noexcept;
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_WIDGET_H
