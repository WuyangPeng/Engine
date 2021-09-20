///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/21 18:24)

#ifndef CPP_COMMON_KNOWLEDGE_PREFACE_CODE_EXAMPLE_H
#define CPP_COMMON_KNOWLEDGE_PREFACE_CODE_EXAMPLE_H

#include "Example/BookCpp/CppCommonKnowledge/CppCommonKnowledgeDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace CppCommonKnowledge
    {
        class CPP_COMMON_KNOWLEDGE_DEFAULT_DECLARE Overload final
        {
        public:
            using ClassType = Overload;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Overload() noexcept;

            void Main() const noexcept;
        };
    }
}

#endif  // CPP_COMMON_KNOWLEDGE_PREFACE_CODE_EXAMPLE_H
