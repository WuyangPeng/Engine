///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/18 21:51)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM10_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM10_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms10
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms10Example final
                {
                public:
                    using ClassType = Terms10Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms10Example() noexcept;

                    void EnumExample() const noexcept;
                    void EnumClassExample() const noexcept;
                    void EnumConversionExample() const;
                    void EnumClassConversionExample() const;
                    void Tuple0Example() const;
                    void Tuple1Example() const;
                    void Tuple2Example() const;
                    void Tuple3Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM10_EXAMPLE_H
