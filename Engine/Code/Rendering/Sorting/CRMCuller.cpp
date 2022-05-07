///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 16:10)

#include "Rendering/RenderingExport.h"

#include "CRMCuller.h"

Rendering::CRMCuller::CRMCuller(const ConstCameraSharedPtr& camera)
    : ParentType{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CRMCuller)

void Rendering::CRMCuller::Insert(const VisualSharedPtr& visible)
{
    RENDERING_CLASS_IS_VALID_1;

    if (unique.find(visible) == unique.end())
    {
        ParentType::Insert(visible);
    }
}
