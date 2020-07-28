// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 15:54)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseMultiContext.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::move;
using std::make_unique;
using boost::numeric_cast;

Network::BoostMainManagerUseMultiContext
	::BoostMainManagerUseMultiContext(const ConfigurationSubStrategy& subStrategy)
	:ParentType{}, m_Container{}, m_CurrentIndex{ 0 }
{
	InitContainer(subStrategy.GetValue(WrappersSubStrategy::MultiContext));

	NETWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Network::BoostMainManagerUseMultiContext
	::InitContainer(int containerNumber)
{
	for (auto index = 0; index < containerNumber; ++index)
	{
		auto executorWorkGuardContextThread = make_unique<ExecutorWorkGuardContextThread>();

		m_Container.push_back(move(executorWorkGuardContextThread));
	}

	if (m_Container.empty())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("boost 多环境数量为零！"s));
	}
}

Network::BoostMainManagerUseMultiContext
	::~BoostMainManagerUseMultiContext()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::BoostMainManagerUseMultiContext
	::IsValid() const noexcept
{
	if (0 <= m_CurrentIndex && m_CurrentIndex < static_cast<int>(m_Container.size()))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Network::BoostMainManagerUseMultiContext
	::Run()
{
	NETWORK_CLASS_IS_VALID_1;
}

Network::IOContextType& Network::BoostMainManagerUseMultiContext
	::GetIOContext()
{
	NETWORK_CLASS_IS_VALID_1;

	auto index = m_CurrentIndex++;
	if (numeric_cast<int>(m_Container.size()) <= m_CurrentIndex)
	{
		m_CurrentIndex = 0;
	}

	return m_Container[index].GetIOContext();
}

void Network::BoostMainManagerUseMultiContext
	::StopContext()
{
	NETWORK_CLASS_IS_VALID_1;

	for (auto& value : m_Container)
	{
		value.StopContext();
	}
}

bool Network::BoostMainManagerUseMultiContext
	::IsContextStop() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	for (const auto& value : m_Container)
	{
		if (!value.IsContextStop())
		{
			return false;
		}
	}

	return true;
}

void Network::BoostMainManagerUseMultiContext
	::RestartContext()
{
	NETWORK_CLASS_IS_VALID_1;

	for (auto& value : m_Container)
	{
		value.RestartContext();
	}
}

