///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/28 9:37)

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
                // 对象声明式
                extern int x;

                // 类声明
                class Widget;

                // 函数声明
                bool Func(const Widget& w) noexcept;

                // 限定作用域的枚举声明
                enum class Color;
            }

            NODISCARD bool WidgetDeclaration() noexcept;
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_DECLARATION_H
