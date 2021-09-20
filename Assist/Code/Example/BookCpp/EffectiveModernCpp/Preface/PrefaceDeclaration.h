///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/28 9:37)

#ifndef EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_DECLARATION_H
#define EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_DECLARATION_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Preface
        {
            namespace Declaration
            {
                // ��������ʽ
                extern int x;

                // ������
                class Widget;

                // ��������
                bool Func(const Widget& w) noexcept;

                // �޶��������ö������
                enum class Color;
            }

            NODISCARD bool WidgetDeclaration() noexcept;
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_DECLARATION_H
