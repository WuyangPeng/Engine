///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/21 15:45)

#include "Rendering/RenderingExport.h"

#include "OverlayEffect.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

std::shared_ptr<const Rendering::VertexBuffer> Rendering::OverlayEffect::GetVertexBuffer() const noexcept
{
    return nullptr;
}

std::shared_ptr<const Rendering::IndexBuffer> Rendering::OverlayEffect::GetIndexBuffer() const noexcept
{
    return nullptr;
}

std::shared_ptr<const Rendering::VisualEffect> Rendering::OverlayEffect::GetEffect() const noexcept
{
    return nullptr;
}
