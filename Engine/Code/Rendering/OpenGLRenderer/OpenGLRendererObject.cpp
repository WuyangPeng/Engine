/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 11:29)

#include "Rendering/RenderingExport.h"

#include "OpenGLRendererObject.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::OpenGLRendererObject::OpenGLRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : ParentType{ graphicsObject, name }, glHandle{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRendererObject)

System::OpenGLUnsignedInt Rendering::OpenGLRendererObject::GetGLHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return glHandle;
}

void Rendering::OpenGLRendererObject::SetGLHandle(OpenGLUInt handler) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    glHandle = handler;
}

void Rendering::OpenGLRendererObject::Enable()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用Enable"))
}

void Rendering::OpenGLRendererObject::Disable()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用Disable"))
}

bool Rendering::OpenGLRendererObject::Update()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用Update"))
}

bool Rendering::OpenGLRendererObject::Update(int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用Update"))
}

bool Rendering::OpenGLRendererObject::Update(int item, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(item, level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用Update"))
}

bool Rendering::OpenGLRendererObject::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用CopyGpuToCpu"))
}

bool Rendering::OpenGLRendererObject::CopyGpuToCpu(int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用CopyGpuToCpu"))
}

bool Rendering::OpenGLRendererObject::CopyGpuToCpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(item, level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用CopyGpuToCpu"))
}

bool Rendering::OpenGLRendererObject::CopyCpuToGpu()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用CopyCpuToGpu"))
}

bool Rendering::OpenGLRendererObject::CopyCpuToGpu(int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用CopyCpuToGpu"))
}

bool Rendering::OpenGLRendererObject::CopyCpuToGpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(item, level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用CopyCpuToGpu"))
}

bool Rendering::OpenGLRendererObject::GetNumActiveElements()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject禁止调用GetNumActiveElements"))
}
