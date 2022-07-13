///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 15:37)

#ifndef ARTIFICIAL_INTELLEGENCE_TOOLSET_PLACEHOLDER_H
#define ARTIFICIAL_INTELLEGENCE_TOOLSET_PLACEHOLDER_H

#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ArtificialIntellegenceToolset
{
    class ARTIFICIAL_INTELLEGENCE_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ARTIFICIAL_INTELLEGENCE_TOOLSET_PLACEHOLDER_H
