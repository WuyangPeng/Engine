/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/08 15:48)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureSingleImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLTextureSingleImpl::OpenGLTextureSingleImpl() noexcept
    : levelPixelUnpackBuffer{}, levelPixelPackBuffer{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLTextureSingleImpl)

System::OpenGLUInt Rendering::OpenGLTextureSingleImpl::GetLevelPixelUnpackBuffer(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return levelPixelUnpackBuffer.at(index);
}

System::OpenGLUInt Rendering::OpenGLTextureSingleImpl::GetLevelPixelPackBuffer(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return levelPixelPackBuffer.at(index);
}

void Rendering::OpenGLTextureSingleImpl::SetLevelPixelUnpackBuffer(int index, OpenGLUInt buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    levelPixelUnpackBuffer.at(index) = buffer;
}

void Rendering::OpenGLTextureSingleImpl::SetLevelPixelPackBuffer(int index, OpenGLUInt buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    levelPixelPackBuffer.at(index) = buffer;
}
