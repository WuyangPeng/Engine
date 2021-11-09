///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/22 20:42)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM21_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM21_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms21
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms21Example final
                {
                public:
                    using ClassType = Terms21Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms21Example() noexcept;

                    void MakeExample() const;
                    void ProcessWidget0Example() const;
                    void DeleterExample() const;
                    void Vector0Example() const;
                    void Vector1Example() const;
                    void ReallyBigType0Example() const;
                    void ReallyBigType1Example() const;
                    void ProcessWidget1Example() const;
                    void ProcessWidget2Example() const;
                    void ProcessWidget3Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM21_EXAMPLE_H
