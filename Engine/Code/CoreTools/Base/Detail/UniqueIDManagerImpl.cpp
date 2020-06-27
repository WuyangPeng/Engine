// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 09:57)

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
	CORE_TOOLS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_UniqueID.size()), "����Խ�硣");
	CORE_TOOLS_ASSERTION_3(m_UniqueID[index] < m_UniqueID[index] + 1, "��ֵ�����");

	return ++m_UniqueID[index];
}

