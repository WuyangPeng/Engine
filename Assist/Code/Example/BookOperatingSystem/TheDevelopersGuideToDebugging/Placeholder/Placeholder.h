///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef THE_DEVELOPERS_GUIDE_TO_DEBUGGING_PLACEHOLDER_H
#define THE_DEVELOPERS_GUIDE_TO_DEBUGGING_PLACEHOLDER_H

#include "Example/BookOperatingSystem/TheDevelopersGuideToDebugging/TheDevelopersGuideToDebuggingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace TheDevelopersGuideToDebugging
{
    class THE_DEVELOPERS_GUIDE_TO_DEBUGGING_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // THE_DEVELOPERS_GUIDE_TO_DEBUGGING_PLACEHOLDER_H
