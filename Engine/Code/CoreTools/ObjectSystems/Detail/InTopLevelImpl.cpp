// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:48)

#include "CoreTools/CoreToolsExport.h"

#include "InTopLevelImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::InTopLevelImpl
	::InTopLevelImpl() noexcept
	:m_TopLevel{}, m_UniqueID{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::InTopLevelImpl
	::IsValid() const noexcept
{
	if (m_TopLevel.size() == m_UniqueID.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool CoreTools::InTopLevelImpl
	::IsTopLevel(uint64_t uniqueID) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_UniqueID.find(uniqueID) != m_UniqueID.cend();
}

int CoreTools::InTopLevelImpl
	::GetTopLevelSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_TopLevel.size());
}

const CoreTools::ConstObjectInterfaceSmartPointer& CoreTools::InTopLevelImpl
	::operator[](int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < GetTopLevelSize(), "索引错误！");

	return m_TopLevel[index];
}

CoreTools::ObjectInterfaceSmartPointer& CoreTools::InTopLevelImpl
	::operator[](int index)
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < GetTopLevelSize(), "索引错误！");

	return m_TopLevel[index];
}

void CoreTools::InTopLevelImpl
	::Insert(const ObjectInterfaceSmartPointer& objectPtr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_UniqueID.insert(objectPtr->GetUniqueID()).second)
	{
		m_TopLevel.push_back(objectPtr);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("一个object指针只可以被插入一次！"s));
	}
}





