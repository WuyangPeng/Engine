///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/06 21:47)

#ifndef THE_ACE_PROGRAMMERS_GUIDE_PLACEHOLDER_H
#define THE_ACE_PROGRAMMERS_GUIDE_PLACEHOLDER_H

#include "Example/BookOperatingSystem/TheACEProgrammersGuide/TheACEProgrammersGuideDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace TheACEProgrammersGuide
{
    class THE_ACE_PROGRAMMERS_GUIDE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // THE_ACE_PROGRAMMERS_GUIDE_PLACEHOLDER_H
