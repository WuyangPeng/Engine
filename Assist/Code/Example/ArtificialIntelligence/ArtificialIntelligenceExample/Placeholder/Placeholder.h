///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:03)

#ifndef ARTIFICIAL_INTELLIGENCE_EXAMPLE_PLACEHOLDER_H
#define ARTIFICIAL_INTELLIGENCE_EXAMPLE_PLACEHOLDER_H

#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ArtificialIntelligenceExample
{
    class ARTIFICIAL_INTELLIGENCE_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ARTIFICIAL_INTELLIGENCE_EXAMPLE_PLACEHOLDER_H
