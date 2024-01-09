///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/10 14:53)

#include "Rendering/RenderingExport.h"

#include "ConstantColorEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"

Rendering::ConstantColorEffectImpl::ConstantColorEffectImpl() noexcept
    : colorConstant{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ConstantColorEffectImpl::ConstantColorEffectImpl(int numColorConstantBytes)
    : colorConstant{ std::make_shared<ConstantBuffer>("colorConstant", numColorConstantBytes, true) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ConstantColorEffectImpl)

Rendering::ConstantColorEffectImpl::ConstConstantBufferSharedPtr Rendering::ConstantColorEffectImpl::GetColorConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return colorConstant;
}

Rendering::ConstantColorEffectImpl::ConstantBufferSharedPtr Rendering::ConstantColorEffectImpl::GetColorConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return colorConstant;
}
