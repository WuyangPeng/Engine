///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:46)

#ifndef MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_H
#define MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_H

#include "Example/BookCpp/MoreEffectiveCpp/MoreEffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace MoreEffectiveCpp
    {
        class MORE_EFFECTIVE_CPP_DEFAULT_DECLARE Terminology final
        {
        public:
            using ClassType = Terminology;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Terminology() noexcept;

            void Main() const;
        };
    }
}

#endif  // MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_H
