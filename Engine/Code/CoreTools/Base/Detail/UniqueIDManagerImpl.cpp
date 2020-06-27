// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 09:57)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIDManagerImpl.h" 
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::UniqueIDManagerImpl
	::UniqueIDManagerImpl(int count)
	:m_UniqueID(count)
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UniqueIDManagerImpl
	::IsValid() const noexcept
{
	if (0u < m_UniqueID.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint64_t CoreTools::UniqueIDManagerImpl
	::NextUniqueID(int index)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_UniqueID.size()), "索引越界。");
	CORE_TOOLS_ASSERTION_3(m_UniqueID[index] < m_UniqueID[index] + 1, "数值溢出。");

	return ++m_UniqueID[index];
}

