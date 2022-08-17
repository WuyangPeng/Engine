///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/05 10:58)

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
