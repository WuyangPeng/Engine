///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 16:02)

#ifndef ANIMATION_EXAMPLE_PLACEHOLDER_H
#define ANIMATION_EXAMPLE_PLACEHOLDER_H

#include "Example/Animation/AnimationExample/AnimationExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AnimationExample
{
    class ANIMATION_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ANIMATION_EXAMPLE_PLACEHOLDER_H
