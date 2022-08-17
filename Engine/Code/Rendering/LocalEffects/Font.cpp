///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/04 11:54)

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
