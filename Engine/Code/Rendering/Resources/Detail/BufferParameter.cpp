///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 18:14)

#include "Rendering/RenderingExport.h"

#include "BufferParameter.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::BufferParameter::BufferParameter() noexcept
    : offset{ 0 }, componentSize{ 0 }, numComponents{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BufferParameter::BufferParameter(int offset, int componentSize, int numComponents) noexcept
    : offset{ offset }, componentSize{ componentSize }, numComponents{ numComponents }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BufferParameter)

void Rendering::BufferParameter::Set(int aOffset, int aComponentSize, int aNumComponents) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
    componentSize = aComponentSize;
    numComponents = aNumComponents;
}

int Rendering::BufferParameter::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

int Rendering::BufferParameter::GetComponentSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return componentSize;
}

int Rendering::BufferParameter::GetNumComponents() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numComponents;
}
