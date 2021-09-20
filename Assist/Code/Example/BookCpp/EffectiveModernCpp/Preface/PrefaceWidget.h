///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/28 9:37)

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
            // 类定义
            class Widget final
            {
            public:
                Widget() noexcept = default;
                ~Widget() noexcept = default;
                Widget(const Widget& rhs) noexcept = default;
                Widget& operator=(const Widget& rhs) noexcept = default;

                // rhs是个左值，尽管它具有右值引用型别
                Widget(Widget&& rhs) noexcept = default;
                Widget& operator=(Widget&& rhs) noexcept = default;
            };

            class Matrix final
            {
            };

            NODISCARD Matrix operator+(MAYBE_UNUSED const Matrix& lhs, MAYBE_UNUSED const Matrix& rhs) noexcept;

            // 这两行的省略号都是源码的组成部分。
            template <typename... Ts>
            void ProcessVals(MAYBE_UNUSED const Ts&... params) noexcept
            {
                // ...
                // 而这一行中的省略号，则表示“这里可能有其他代码”。
            }

            // SomeFunc的形参w按值传递
            void SomeFunc(MAYBE_UNUSED Widget w) noexcept;

            void PrefaceDeclaration() noexcept;
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_WIDGET_H
