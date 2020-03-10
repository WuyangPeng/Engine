// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:48)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLinkImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectInterfaceLess.h"
#include "CoreTools/MemoryTools/ConstFirstSubclassSmartPointerDetail.h"

#include <boost/numeric/conversion/cast.hpp>
#include <algorithm>

using std::make_pair;

CoreTools::ObjectLinkImpl
	::ObjectLinkImpl()
	:m_Linked{}, m_Ordered{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ObjectLinkImpl
	::IsValid() const noexcept
{
	if (m_Linked.size() == m_Ordered.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ObjectInterfaceSmartPointer CoreTools::ObjectLinkImpl
	::GetObjectPtr(uint64_t uniqueID)
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto iter = m_Linked.find(uniqueID);

	if (iter != m_Linked.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("׼����ȡ��objectָ��û�����ӣ�"));
	}
}

int CoreTools::ObjectLinkImpl
	::GetOrderedSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Ordered.size());
}

CoreTools::ObjectInterfaceSmartPointer& CoreTools::ObjectLinkImpl
	::operator[](int index)
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < GetOrderedSize(), "��������");

	return m_Ordered[index];
}

void CoreTools::ObjectLinkImpl
	::Insert(uint64_t uniqueID, const ObjectInterfaceSmartPointer& ptr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Linked.insert({ uniqueID, ptr });
	m_Ordered.push_back(ptr);
}

void CoreTools::ObjectLinkImpl
	::Sort()
{
	CLASS_IS_VALID_1;

	sort(m_Ordered.begin(), m_Ordered.end(), ObjectInterfaceSmartPointerLess{});
}



