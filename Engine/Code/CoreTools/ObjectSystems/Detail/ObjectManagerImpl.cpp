// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:49)

#include "CoreTools/CoreToolsExport.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "ObjectManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"

using std::string;
using std::make_pair;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)

CoreTools::ObjectManagerImpl
	::ObjectManagerImpl() noexcept
	:m_Factories{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManagerImpl)

CoreTools::ObjectManagerImpl::FactoryFunction CoreTools::ObjectManagerImpl
	::Find(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	const auto iter = m_Factories.find(name);
	if (iter != m_Factories.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ���ָ���Ĺ���������"s));
	}
}

void CoreTools::ObjectManagerImpl
	::Insert(const string& name, FactoryFunction function)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Factories.insert({ name, function });
}

void CoreTools::ObjectManagerImpl
	::Remove(const string& name)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Factories.erase(name);
}

uint64_t CoreTools::ObjectManagerImpl
	::NextUniqueID()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Object);
}

#include STSTEM_WARNING_POP