///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/04 11:54)

#include "Rendering/RenderingExport.h"

#include "RendererObject.h"
#include "Detail/RendererObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererObject)

Rendering::RendererObject::RendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : impl{ graphicsObject, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererObject)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererObject, GetGraphicsObject, Rendering::RendererObject::GraphicsObjectSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererObject, GetName, std::string)