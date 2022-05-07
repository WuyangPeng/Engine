///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 10:52)

#include "Rendering/RenderingExport.h"

#include "CollapseRecord.h"
#include "Detail/CollapseRecordImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, CollapseRecord)

Rendering::CollapseRecord::CollapseRecord(int vKeep, int vThrow, int numVertices, int numTriangles)
    : impl{ vKeep, vThrow, numVertices, numTriangles }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CollapseRecord)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, CollapseRecord, SetIndices, std::vector<int>, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, SetVKeep, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, SetVThrow, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, SetNumVertices, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, SetNumTriangles, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, GetIndices, std::vector<int>);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, GetIndex, int, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, GetIndicesSize, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetVKeep, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetVThrow, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetNumVertices, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetNumTriangles, int);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, Save, CoreTools::BufferTarget&, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, GetStreamingSize, int);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, ClearIndices, void)

bool Rendering::operator==(const CollapseRecord& lhs, const CollapseRecord& rhs)
{
    if (lhs.GetVKeep() == rhs.GetVKeep() &&
        lhs.GetVThrow() == rhs.GetVThrow() &&
        lhs.GetNumTriangles() == rhs.GetNumTriangles() &&
        lhs.GetNumVertices() == rhs.GetNumVertices() &&
        lhs.GetIndices() == rhs.GetIndices())
    {
        return true;
    }
    else
    {
        return false;
    }
}
