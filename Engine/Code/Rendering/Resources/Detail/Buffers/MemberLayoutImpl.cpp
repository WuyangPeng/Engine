///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/09 14:07)

#include "Rendering/RenderingExport.h"

#include "MemberLayoutImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

Rendering::MemberLayoutImpl::MemberLayoutImpl(const std::string& name, int offset, int numElements)
    : name{ name }, offset{ offset }, numElements{ numElements }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MemberLayoutImpl)

std::string Rendering::MemberLayoutImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

int Rendering::MemberLayoutImpl::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

int Rendering::MemberLayoutImpl::GetNumElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numElements;
}

int Rendering::MemberLayoutImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(name);

    size += CORE_TOOLS_STREAM_SIZE(offset);
    size += CORE_TOOLS_STREAM_SIZE(numElements);

    return size;
}
