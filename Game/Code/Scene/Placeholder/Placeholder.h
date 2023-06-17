///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:25)

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
