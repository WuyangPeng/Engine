// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:49)

#include "CoreTools/CoreToolsExport.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "ObjectManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"

using std::string;
using std::make_pair;

CoreTools::ObjectManagerImpl
	::ObjectManagerImpl()
	:m_Factories{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManagerImpl)

CoreTools::ObjectManagerImpl::FactoryFunction CoreTools::ObjectManagerImpl
	::Find(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto iter = m_Factories.find(name);
	if (iter != m_Factories.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"));
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

