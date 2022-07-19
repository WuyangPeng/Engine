///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 18:20)

#ifndef SCENE_PLACEHOLDER_PLACEHOLDER_H
#define SCENE_PLACEHOLDER_PLACEHOLDER_H

#include "Scene/SceneDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Scene
{
    class SCENE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCENE_PLACEHOLDER_PLACEHOLDER_H
