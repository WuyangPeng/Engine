///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:18)

#include "SceneObject/SceneObjectExport.h"

#include "Placeholder.h"
#include "SceneObject/Helper/SceneObjectClassInvariantMacro.h"

SceneObject::Placeholder::Placeholder() noexcept
{
    SCENE_OBJECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SceneObject, Placeholder)
