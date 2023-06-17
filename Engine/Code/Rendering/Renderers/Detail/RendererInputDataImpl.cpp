///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:44)

#include "Rendering/RenderingExport.h"

#include "RendererInputDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/RendererInput.h"

Rendering::RendererInputDataImpl::RendererInputDataImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : rendererInput{ std::make_shared<RendererInput>(Rendering::RendererTypes::Default) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RendererInputDataImpl::IsValid() const noexcept
{
    if (rendererInput != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::RendererInputDataImpl::Rebuild(RendererTypes type)
{
    RENDERING_CLASS_IS_VALID_1;

    rendererInput = std::make_shared<RendererInput>(type);
}
