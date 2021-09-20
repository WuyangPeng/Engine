///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/06 21:47)

#ifndef MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_PLACEHOLDER_H
#define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_PLACEHOLDER_H

#include "Example/BookOperatingSystem/MasteringComplexityWithACEAndPatterns/MasteringComplexityWithACEAndPatternsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MasteringComplexityWithACEAndPatterns
{
    class MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_PLACEHOLDER_H
