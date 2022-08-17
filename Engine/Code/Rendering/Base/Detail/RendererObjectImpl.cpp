///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/07 17:33)

#include "Rendering/RenderingExport.h"

#include "RendererObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::RendererObjectImpl::RendererObjectImpl(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : graphicsObject{ graphicsObject }, name{ name }
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

Rendering::RendererObjectImpl::GraphicsObjectSharedPtr Rendering::RendererObjectImpl::GetGraphicsObject() const
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
