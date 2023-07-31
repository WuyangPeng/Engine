///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:43)

#ifndef ANIMATION_TOOLSET_PLACEHOLDER_H
#define ANIMATION_TOOLSET_PLACEHOLDER_H

#include "Toolset/Animation/AnimationToolset/AnimationToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AnimationToolset
{
    class ANIMATION_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ANIMATION_TOOLSET_PLACEHOLDER_H