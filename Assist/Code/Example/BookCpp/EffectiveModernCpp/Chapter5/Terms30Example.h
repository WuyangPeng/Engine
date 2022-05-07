///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/20 21:47)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms30
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms30Example final
                {
                public:
                    using ClassType = Terms30Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms30Example() noexcept;

                    void BracesExample() const;
                    void StaticExample() const;
                    void ProcessValExample() const noexcept;
                    void IPv4Example() const noexcept;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_EXAMPLE_H