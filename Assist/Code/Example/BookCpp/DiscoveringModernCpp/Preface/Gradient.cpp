///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:53)

#include "Example/BookCpp/DiscoveringModernCpp/DiscoveringModernCppExport.h"

#include "Gradient.h"
#include "Example/BookCpp/DiscoveringModernCpp/Helper/DiscoveringModernCppClassInvariantMacro.h"

BookAdvanced::DiscoveringModernCpp::Gradient::Gradient() noexcept
{
    DISCOVERING_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::DiscoveringModernCpp, Gradient)

void BookAdvanced::DiscoveringModernCpp::Gradient::GradientDescent(double* x, double* y, double s, double eps, double (*f)(double, double), double (*gx)(double, double), double (*gy)(double, double)) const noexcept
{
    DISCOVERING_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    if (f == nullptr || gx == nullptr || gy == nullptr || x == nullptr || y == nullptr)
        return;

    double val = f(*x, *y);
    double delta = 0.0;

    do
    {
        *x -= s * gx(*x, *y);
        *y -= s * gy(*x, *y);

        const double newVal = f(*x, *y);

        delta = abs(newVal - val);
        val = newVal;

    } while (eps < delta);
}
