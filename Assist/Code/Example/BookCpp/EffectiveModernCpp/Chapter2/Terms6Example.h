///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/18 21:51)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER2_TERM6_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER2_TERM6_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter2
        {
            namespace Terms6
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms6Example final
                {
                public:
                    using ClassType = Terms6Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms6Example() noexcept;

                    void VectorExample() const;
                    void AutoErrorExample() const;
                    void MatrixExample() const noexcept;
                    void StaticCastExample() const;
                    void CalcEpsilonExample() const noexcept;
                    void IndexExample() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER2_TERM6_EXAMPLE_H
