// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 13:32)

#include "CoreTools/CoreToolsExport.h"

#include "SmartPointerManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

CoreTools::SmartPointerManagerImpl
	::SmartPointerManagerImpl()
	:m_ReferenceContainer{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SmartPointerManagerImpl
	::IsValid() const noexcept
{
	for (const auto& value : m_ReferenceContainer)
	{
		if (value.first == nullptr || value.second <= 0)
		{
			return false;
		}
	}

	return true;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::SmartPointerManagerImpl
	::CopyIncreaseReference(const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	if (IsNullPtr(data))
	{
		return 0;
	}

	auto iter = m_ReferenceContainer.find(data);

	if (iter != m_ReferenceContainer.cend())
	{
		return ++(iter->second);
	}
	else
	{
		CORE_TOOLS_ASSERTION_2(false, "指针不在引用计数容器中。");
		return -1;
	}
}

int CoreTools::SmartPointerManagerImpl
	::IncreaseReference(const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	if (IsNullPtr(data))
	{
		return 0;
	}

	auto iter = m_ReferenceContainer.find(data);

	if (iter != m_ReferenceContainer.cend())
	{
		return ++(iter->second);
	}
	else
	{
		if (m_ReferenceContainer.insert({ data, 1 }).second)
			return 1;
		else
			return 0;
	}
}

int CoreTools::SmartPointerManagerImpl
	::DecreaseReference(const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	if (IsNullPtr(data))
	{
		return 0;
	}

	auto iter = m_ReferenceContainer.find(data);

	if (iter != m_ReferenceContainer.cend())
	{
		if (--iter->second == 0)
		{
			m_ReferenceContainer.erase(iter);
			return 0;
		}
		else
		{
			return iter->second;
		}
	}
	else
	{
		CORE_TOOLS_ASSERTION_2(false, "指针不在引用计数容器中。");
		return -1;
	}
}

bool CoreTools::SmartPointerManagerImpl
	::IsSmartPointer(const void* data) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	if (IsNullPtr(data))
	{
		return false;
	}

	auto iter = m_ReferenceContainer.find(data);

	if (iter != m_ReferenceContainer.cend())
		return true;
	else
		return false;
}

bool CoreTools::SmartPointerManagerImpl
	::IsNullPtr(const void* data) const
{
	if (data == nullptr)
		return true;
	else
		return false;
}





