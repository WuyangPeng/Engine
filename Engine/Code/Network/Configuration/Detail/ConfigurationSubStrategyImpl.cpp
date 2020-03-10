// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 12:38)

#include "Network/NetworkExport.h" 

#include "ConfigurationSubStrategyImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_pair;

Network::ConfigurationSubStrategyImpl
	::ConfigurationSubStrategyImpl()
	:m_Container{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationSubStrategyImpl)

bool Network::ConfigurationSubStrategyImpl
	::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto iter = m_Container.find(wrappersSubStrategy);

	return iter != m_Container.cend();
}

int Network::ConfigurationSubStrategyImpl
	::GetValue(WrappersSubStrategy wrappersSubStrategy) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto iter = m_Container.find(wrappersSubStrategy);

	if (iter != m_Container.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的子策略。"));
	}
}

void Network::ConfigurationSubStrategyImpl
	::Insert(WrappersSubStrategy wrappersSubStrategy, int value)
{
	NETWORK_CLASS_IS_VALID_9;

	m_Container.insert({ wrappersSubStrategy, value });
}
