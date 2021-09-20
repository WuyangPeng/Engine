///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/29 15:02)

#ifndef EFFECTIVE_MODERN_CPP_PREFACE_CONSTRUCTOR_TEMPLATE_ARGUMENT_DEDUCTION_H
#define EFFECTIVE_MODERN_CPP_PREFACE_CONSTRUCTOR_TEMPLATE_ARGUMENT_DEDUCTION_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Preface
        {
            // ��ģ��ʵ���ͱ��Ƶ��Ĺ��캯����
            template <typename T0, typename T1, typename T2>
            class ConstructorTemplateArgumentDeduction
            {
            public:
                using ClassType = ConstructorTemplateArgumentDeduction<T0, T1, T2>;

            public:
                CLASS_INVARIANT_DECLARE;

            public:
                ConstructorTemplateArgumentDeduction(T0 t0, T1 t1, T2 t2) noexcept;

            private:
                T0 t0;
                T1 t1;
                T2 t2;
            };
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_CONSTRUCTOR_TEMPLATE_ARGUMENT_DEDUCTION_H
