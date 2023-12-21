/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:45)

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

Rendering::RendererObjectImpl::GraphicsObjectSharedPtr Rendering::RendererObjectImpl::GetGraphicsObject()
{
    RENDERING_CLASS_IS_VALID_1;

    return const_pointer_cast<GraphicsObject>(static_cast<const ClassType>(*this).GetGraphicsObject());
}

Rendering::RendererObjectImpl::ConstGraphicsObjectSharedPtr Rendering::RendererObjectImpl::GetGraphicsObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto result = graphicsObject.lock();

    if (!result)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject对象已被销毁。"))
    }

    return result;
}

std::string Rendering::RendererObjectImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return name;
}
