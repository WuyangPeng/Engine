///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/03 19:42)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM34_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM34_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms34
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms34Example final
                {
                public:
                    using ClassType = Terms34Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms34Example() noexcept;

                    void SetSound0Example() const noexcept;
                    void SetSound1Example() const noexcept;
                    void SetSound2Example() const;
                    void SetSound3Example() const;
                    void SetSound4Example() const;
                    void SetSound5Example() const noexcept;
                    void SetSound6Example() const noexcept;
                    void SetSound7Example() const;

                    void Between0Example() const noexcept;
                    void Between1Example() const;
                    void Between2Example() const;
                    void Between3Example() const noexcept;

                    void CompressExample() const;

                    void PolyWidget0Example() const;
                    void PolyWidget1Example() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM34_EXAMPLE_H
