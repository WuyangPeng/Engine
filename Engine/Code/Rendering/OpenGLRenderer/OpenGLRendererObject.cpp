/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/06 11:29)

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

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����Enable"))
}

void Rendering::OpenGLRendererObject::Disable()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����Disable"))
}

bool Rendering::OpenGLRendererObject::Update()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����Update"))
}

bool Rendering::OpenGLRendererObject::Update(int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����Update"))
}

bool Rendering::OpenGLRendererObject::Update(int item, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(item, level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����Update"))
}

bool Rendering::OpenGLRendererObject::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����CopyGpuToCpu"))
}

bool Rendering::OpenGLRendererObject::CopyGpuToCpu(int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����CopyGpuToCpu"))
}

bool Rendering::OpenGLRendererObject::CopyGpuToCpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(item, level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����CopyGpuToCpu"))
}

bool Rendering::OpenGLRendererObject::CopyCpuToGpu()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����CopyCpuToGpu"))
}

bool Rendering::OpenGLRendererObject::CopyCpuToGpu(int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����CopyCpuToGpu"))
}

bool Rendering::OpenGLRendererObject::CopyCpuToGpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(item, level);

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����CopyCpuToGpu"))
}

bool Rendering::OpenGLRendererObject::GetNumActiveElements()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("OpenGLRendererObject��ֹ����GetNumActiveElements"))
}
