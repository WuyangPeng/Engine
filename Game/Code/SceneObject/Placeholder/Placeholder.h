///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 10:49)

#ifndef SCENE_OBJECT_PLACEHOLDER_PLACEHOLDER_H
#define SCENE_OBJECT_PLACEHOLDER_PLACEHOLDER_H

#include "SceneObject/SceneObjectDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace SceneObject
{
    class SCENE_OBJECT_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCENE_OBJECT_PLACEHOLDER_PLACEHOLDER_H
