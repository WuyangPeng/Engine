///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:27)

#include "Rendering/RenderingExport.h"

#include "MemberLayoutImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

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

    auto size = CoreTools::GetStreamSize(name);

    size += CoreTools::GetStreamSize(offset);
    size += CoreTools::GetStreamSize(numElements);

    return size;
}
