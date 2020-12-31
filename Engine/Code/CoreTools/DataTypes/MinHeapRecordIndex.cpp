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

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, MinHeapRecordIndex)

CoreTools::MinHeapRecordIndex::MinHeapRecordIndex(int maxElements)
    : m_Impl{ make_shared<ImplType>(maxElements) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::MinHeapRecordIndex::MinHeapRecordIndex(int newMaxElements, const MinHeapRecordIndex& oldIndex)
    : m_Impl{ make_shared<ImplType>(newMaxElements, *oldIndex.m_Impl) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, MinHeapRecordIndex)

#ifdef OPEN_CLASS_INVARIANT
void CoreTools::MinHeapRecordIndex::PrintIndexInLog() const noexcept
{
    m_Impl->PrintIndexInLog();
}
#endif  // OPEN_CLASS_INVARIANT

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MinHeapRecordIndex, GetMaxElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MinHeapRecordIndex, GetHeapIndex, int, int)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MinHeapRecordIndex, GrowBy, int, void) 

void CoreTools::MinHeapRecordIndex::ChangeIndex(int lhsIndex, int rhsIndex)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Impl->ChangeIndex(lhsIndex, rhsIndex);
}
