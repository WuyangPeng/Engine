///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:08)

#include "Rendering/RenderingExport.h"

#include "RendererObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::RendererObjectImpl::RendererObjectImpl(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : graphicsObject{ graphicsObject }, name{ name }, glHandle{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RendererObjectImpl::IsValid() const noexcept
{
    if (graphicsObject.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::RendererObjectImpl::GraphicsObjectSharedPtr Rendering::RendererObjectImpl::GetGraphicsObject()
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto result = graphicsObject.lock();

    if (!result)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject�����ѱ����١�"));
    }

    return result;
}

Rendering::RendererObjectImpl::ConstGraphicsObjectSharedPtr Rendering::RendererObjectImpl::GetGraphicsObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto result = graphicsObject.lock();

    if (!result)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject�����ѱ����١�"));
    }

    return result;
}

std::string Rendering::RendererObjectImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return name;
}

System::OpenGLUInt Rendering::RendererObjectImpl::GetGLHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return glHandle;
}

void Rendering::RendererObjectImpl::SetGLHandle(OpenGLUInt handler) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    glHandle = handler;
}
