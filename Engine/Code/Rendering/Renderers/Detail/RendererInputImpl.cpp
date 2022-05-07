///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 16:00)

#include "Rendering/RenderingExport.h"

#include "RendererInputImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/RendererFactory.h"

Rendering::RendererInputImpl::RendererInputImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererInputImpl)

Rendering::RendererInputImpl::RendererInputSharedPtr Rendering::RendererInputImpl::Create(RendererTypes type)
{
    return RendererFactory::CreateInput(type);
}
