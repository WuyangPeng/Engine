/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:03)

#include "Rendering/RenderingExport.h"

#include "MemberLayout.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Detail/Buffers/MemberLayoutImpl.h"

Rendering::MemberLayout::MemberLayout(const std::string& name, int offset, int numElements)
    : impl{ name, offset, numElements }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MemberLayout)

std::string Rendering::MemberLayout::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

int Rendering::MemberLayout::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

int Rendering::MemberLayout::GetNumElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumElements();
}

int Rendering::MemberLayout::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}
