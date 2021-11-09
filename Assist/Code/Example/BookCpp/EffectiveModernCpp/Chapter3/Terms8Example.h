///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/18 21:51)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM8_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM8_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms8
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms8Example final
                {
                public:
                    using ClassType = Terms8Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms8Example() noexcept;

                    void OverloadExample() const;
                    void FindRecordExample() const noexcept;
                    void MutexExample0() const;
                    void MutexExample1() const;
                    void MutexExample2() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM8_EXAMPLE_H
