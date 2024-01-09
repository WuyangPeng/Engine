/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:07)

#include "Rendering/RenderingExport.h"

#include "SubResource.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Detail/Textures/SubResourceImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SubResource)

Rendering::SubResource::SubResource(int item, int level, const SpanIterator& data, int rowPitch, int slicePitch)
    : impl{ item, level, data, rowPitch, slicePitch }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SubResource)

int Rendering::SubResource::GetItem() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetItem();
}

int Rendering::SubResource::GetLevel() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLevel();
}

Rendering::SubResource::SpanIterator Rendering::SubResource::GetData() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetData();
}

int Rendering::SubResource::GetRowPitch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRowPitch();
}

int Rendering::SubResource::GetSlicePitch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSlicePitch();
}
