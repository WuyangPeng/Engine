///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/15 16:34)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SubResource, GetItem, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SubResource, GetLevel, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SubResource, GetData, Rendering::SubResource::SpanIterator)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SubResource, GetRowPitch, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SubResource, GetSlicePitch, int)