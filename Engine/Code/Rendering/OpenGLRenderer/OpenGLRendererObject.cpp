///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 15:49)

#include "Rendering/RenderingExport.h"

#include "OpenGLRendererObject.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLRendererObject::OpenGLRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : ParentType{ graphicsObject, name }, glHandle{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRendererObject)

System::OpenGLUInt Rendering::OpenGLRendererObject::GetGLHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return glHandle;
}

void Rendering::OpenGLRendererObject::SetGLHandle(OpenGLUInt handler) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    glHandle = handler;
}
