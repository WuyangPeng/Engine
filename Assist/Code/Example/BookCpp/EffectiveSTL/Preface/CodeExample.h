///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:46)

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
