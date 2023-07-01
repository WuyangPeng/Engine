///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:24)

#include "Rendering/RenderingExport.h"

#include "OpenGLDrawingState.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::OpenGLDrawingState::OpenGLDrawingState(const DrawingStateSharedPtr& drawingState, const std::string& name)
    : ParentType{ drawingState, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLDrawingState)

bool Rendering::OpenGLDrawingState::Update() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}
