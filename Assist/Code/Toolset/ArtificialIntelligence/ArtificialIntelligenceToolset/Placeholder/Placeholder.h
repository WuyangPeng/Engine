///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:38)

#ifndef ARTIFICIAL_INTELLIGENCE_TOOLSET_PLACEHOLDER_H
#define ARTIFICIAL_INTELLIGENCE_TOOLSET_PLACEHOLDER_H

#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ArtificialIntelligenceToolset
{
    class ARTIFICIAL_INTELLIGENCE_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ARTIFICIAL_INTELLIGENCE_TOOLSET_PLACEHOLDER_H
