///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/04 11:54)

#include "Rendering/RenderingExport.h"

#include "Font.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <stdexcept>

std::shared_ptr<const Rendering::VertexBuffer> Rendering::Font::GetVertexBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::shared_ptr<const Rendering::IndexBuffer> Rendering::Font::GetIndexBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}

std::shared_ptr<const Rendering::TextEffect> Rendering::Font::GetTextEffect() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    throw std::logic_error("The method or operation is not implemented.");
}
