///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/13 20:28)

#ifndef DISCOVERING_MODERN_CPP_PREFACE_GRADIENT_DETAIL_H
#define DISCOVERING_MODERN_CPP_PREFACE_GRADIENT_DETAIL_H

#include "Gradient.h"
#include "Example/BookCpp/DiscoveringModernCpp/Helper/DiscoveringModernCppClassInvariantMacro.h"

template <typename Value, typename P1, typename P2, typename F, typename G>
Value BookAdvanced::DiscoveringModernCpp::Gradient::GradientDescent(Value x, P1 s, P2 eps, F f, G g) const noexcept
{
    DISCOVERING_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    auto val = f(x);
    auto delta = val;

    do
    {
        x -= s * g(x);
        const auto newVal = f(x);
        delta = abs(newVal - val);
        val = newVal;

    } while (eps < delta);

    return x;
}

#endif  // DISCOVERING_MODERN_CPP_PREFACE_GRADIENT_DETAIL_H
