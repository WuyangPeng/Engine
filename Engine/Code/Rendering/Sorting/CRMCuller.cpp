///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:28)

#include "Rendering/RenderingExport.h"

#include "CRMCuller.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

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
