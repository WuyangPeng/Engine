// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/10 12:34)

#include "Network/NetworkExport.h" 

#include "ConfigurationParameterImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_pair;
using std::string;

Network::ConfigurationParameterImpl
	::ConfigurationParameterImpl()
	:m_Container{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationParameterImpl)

void Network::ConfigurationParameterImpl
	::AddParameter(const String& key, const String& parameter)
{
	NETWORK_CLASS_IS_VALID_9;

	m_Container[key].insert(parameter);
}

bool Network::ConfigurationParameterImpl
	::IsParameterExist(const String& key, const String& parameter) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto iter = m_Container.find(key);

	if (iter != m_Container.cend())
	{
		return iter->second.find(parameter) != iter->second.cend();
	}

	return false;
}

const Network::ConfigurationParameterImpl::Parameter Network::ConfigurationParameterImpl
	::GetParameter(const String& key) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto iter = m_Container.find(key);

	if (iter != m_Container.cend())
	{
		return iter->second;
	}

	return Parameter{};
}

