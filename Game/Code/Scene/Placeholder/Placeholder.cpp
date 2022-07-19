///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 18:20)

#include "Scene/SceneExport.h"

#include "Placeholder.h"
#include "Scene/Helper/SceneClassInvariantMacro.h"

Scene::Placeholder::Placeholder() noexcept
{
    SCENE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Scene, Placeholder)
