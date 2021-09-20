//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/16 11:38)

#include "CoreTools/CoreToolsExport.h"

#include "MinHeapRecordIndex.h"
#include "Detail/MinHeapRecordIndexImpl.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;

CoreTools::MinHeapRecordIndex::MinHeapRecordIndex(int maxElements)
    : impl{ maxElements }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::MinHeapRecordIndex::MinHeapRecordIndex(int newMaxElements, const MinHeapRecordIndex& oldIndex)
    : impl{ newMaxElements, *oldIndex.impl }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MinHeapRecordIndex)

#ifdef OPEN_CLASS_INVARIANT
void CoreTools::MinHeapRecordIndex::PrintIndexInLog() const noexcept
{
    impl->PrintIndexInLog();
}
#endif  // OPEN_CLASS_INVARIANT

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MinHeapRecordIndex, GetMaxElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MinHeapRecordIndex, GetHeapIndex, int, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MinHeapRecordIndex, GrowBy, int, void)

void CoreTools::MinHeapRecordIndex::ChangeIndex(int lhsIndex, int rhsIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ChangeIndex(lhsIndex, rhsIndex);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, MinHeapRecordIndex)