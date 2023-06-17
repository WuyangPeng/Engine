///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:08)

#include "Rendering/RenderingExport.h"

#include "RendererObjectBridge.h"
#include "Detail/RendererObjectBridgeImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/GraphicsObject.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererObjectBridge)

Rendering::RendererObjectBridge::RendererObjectBridgeSharedPtr Rendering::RendererObjectBridge::Create()
{
    return std::make_shared<RendererObjectBridge>(CoreTools::DisableNotThrow::Disable);
}

Rendering::RendererObjectBridge::RendererObjectBridge(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererObjectBridge);

Rendering::RendererObjectBridge::RendererObjectSharedPtr Rendering::RendererObjectBridge::BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->BindRendererObject(rendererTypes, graphicsObject);
}

void Rendering::RendererObjectBridge::UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UnbindRendererObject(graphicsObject);
}

Rendering::RendererObjectBridge::RendererObjectSharedPtr Rendering::RendererObjectBridge::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetRendererObject(graphicsObject);
}

Rendering::RendererObjectBridge::ConstRendererObjectSharedPtr Rendering::RendererObjectBridge::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRendererObject(graphicsObject);
}
