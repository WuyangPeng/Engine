///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/05 10:58)

#include "Rendering/RenderingExport.h"

#include "TextEffect.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <stdexcept>

std::shared_ptr<const Rendering::VertexShader> Rendering::TextEffect::GetVertexShader() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::shared_ptr<const Rendering::PixelShader> Rendering::TextEffect::GetPixelShader() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::shared_ptr<const Rendering::ConstantBuffer> Rendering::TextEffect::GetTranslate() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::shared_ptr<const Rendering::ConstantBuffer> Rendering::TextEffect::GetColor() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}
