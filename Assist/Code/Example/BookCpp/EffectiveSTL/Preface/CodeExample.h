///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:46)

#ifndef EFFECTIVE_STL_PREFACE_CODE_EXAMPLE_H
#define EFFECTIVE_STL_PREFACE_CODE_EXAMPLE_H

#include "Example/BookCpp/EffectiveSTL/EffectiveSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveSTL
    {
        class EFFECTIVE_STL_DEFAULT_DECLARE CodeExample final
        {
        public:
            using ClassType = CodeExample;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            CodeExample() noexcept;

            void Main() const;

            [[nodiscard]] bool LastGreaterThanFirst(const std::vector<int>& container) const noexcept;
        };
    }
}

#endif  // EFFECTIVE_STL_PREFACE_CODE_EXAMPLE_H
