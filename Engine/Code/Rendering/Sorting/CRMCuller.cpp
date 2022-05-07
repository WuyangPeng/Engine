///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/19 16:10)

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
