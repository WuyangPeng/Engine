///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:53)

#ifndef DISCOVERING_MODERN_CPP_PREFACE_GRADIENT_H
#define DISCOVERING_MODERN_CPP_PREFACE_GRADIENT_H

#include "Example/BookCpp/DiscoveringModernCpp/DiscoveringModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace DiscoveringModernCpp
    {
        class DISCOVERING_MODERN_CPP_DEFAULT_DECLARE Gradient
        {
        public:
            using ClassType = Gradient;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Gradient() noexcept;

            void GradientDescent(double* x,
                                 double* y,
                                 double s,
                                 double eps,
                                 double (*f)(double, double),
                                 double (*gx)(double, double),
                                 double (*gy)(double, double)) const noexcept;

            template <typename Value, typename P1, typename P2, typename F, typename G>
            Value GradientDescent(Value x, P1 s, P2 eps, F f, G g) const noexcept;
        };       
    }
}

#endif  // DISCOVERING_MODERN_CPP_PREFACE_GRADIENT_H
