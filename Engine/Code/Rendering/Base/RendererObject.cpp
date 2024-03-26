/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:44)

#include "Rendering/RenderingExport.h"

#include "RendererObject.h"
#include "Detail/RendererObjectImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererObject)

Rendering::RendererObject::RendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : impl{ graphicsObject, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererObject)

Rendering::RendererObject::GraphicsObjectSharedPtr Rendering::RendererObject::GetGraphicsObject()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetGraphicsObject();
}

Rendering::RendererObject::ConstGraphicsObjectSharedPtr Rendering::RendererObject::GetGraphicsObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGraphicsObject();
}

std::string Rendering::RendererObject::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

System::OpenGLUnsignedInt Rendering::RendererObject::GetGLHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return 0;
}
