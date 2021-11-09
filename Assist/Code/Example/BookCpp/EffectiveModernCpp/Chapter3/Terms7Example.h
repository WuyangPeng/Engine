///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/18 21:51)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms7
            {
                class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE Terms7Example final
                {
                public:
                    using ClassType = Terms7Example;

                public:
                    CLASS_INVARIANT_DECLARE;

                public:
                    Terms7Example() noexcept;

                    void InitExample() const noexcept;
                    void WidgetExample() const noexcept;
                    void Vector0Example() const;
                    void AtomicExample() const noexcept;
                    void SumExample() const noexcept;
                    void WidgetConstruction0Example() const noexcept;
                    void WidgetConstruction1Example() const noexcept;
                    void WidgetConstruction2Example() const;
                    void WidgetConstruction3Example() const;
                    void WidgetConstruction4Example() const noexcept;
                    void WidgetConstruction5Example() const noexcept;
                    void WidgetConstruction6Example() const;
                    void Vector1Example() const;
                    void DoSomeWorkExample() const;
                };
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_EXAMPLE_H
