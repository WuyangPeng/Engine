// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 11:01)

#include "Rendering/RenderingExport.h"

#include "CollapseRecord.h"
#include "Detail/CollapseRecordImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, CollapseRecord)
Rendering::CollapseRecord ::CollapseRecord(int vKeep, int vThrow, int numVertices, int numTriangles)
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
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, GetIndices, const std::vector<int>);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecord, GetIndex, int, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, GetIndicesSize, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetVKeep, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetVThrow, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetNumVertices, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CollapseRecord, GetNumTriangles, int);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, CollapseRecord, Load, CoreTools::BufferSourceSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, CollapseRecord, Save, CoreTools::BufferTargetSharedPtr, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, GetStreamingSize, int);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecord, ClearIndices, void)

bool Rendering ::operator==(const CollapseRecord& lhs, const CollapseRecord& rhs)
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

#include STSTEM_WARNING_POP