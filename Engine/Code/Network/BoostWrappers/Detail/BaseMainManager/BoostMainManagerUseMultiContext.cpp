// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.4 (2020/03/11 15:54)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseMultiContext.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "System/Helper/PragmaWarning/AsioPost.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
using boost::numeric_cast;
using std::make_unique;
using std::move;

Network::BoostMainManagerUseMultiContext ::BoostMainManagerUseMultiContext(const ConfigurationSubStrategy& subStrategy)
    : ParentType{}, m_Container{}, m_CurrentIndex{ 0 }
{
    InitContainer(subStrategy.GetValue(WrappersSubStrategy::MultiContext));

    NETWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Network::BoostMainManagerUseMultiContext ::InitContainer(int containerNumber)
{
    for (auto index = 0; index < containerNumber; ++index)
        {
            auto executorWorkGuardContextThread = make_unique<ExecutorWorkGuardContextThread>();

            m_Container.push_back(move(executorWorkGuardContextThread));
        }

    if (m_Container.empty())
        {
            THROW_EXCEPTION(SYSTEM_TEXT("boost �໷������Ϊ�㣡"s));
        }
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::BoostMainManagerUseMultiContext::IsValid() const noexcept
{
	try
	{
		#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		if (0 <= m_CurrentIndex && m_CurrentIndex < boost::numeric_cast<int>(m_Container.size()))
			return true;
		else
			return false;
		#include STSTEM_WARNING_POP
	}
    catch(...)
	{
		return false;
	}
}
#endif  // OPEN_CLASS_INVARIANT

void Network::BoostMainManagerUseMultiContext ::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_1;
}

Network::IOContextType& Network::BoostMainManagerUseMultiContext ::GetIOContext()
{
    NETWORK_CLASS_IS_VALID_1;

    const auto index = m_CurrentIndex++;
    if (numeric_cast<int>(m_Container.size()) <= m_CurrentIndex)
        {
            m_CurrentIndex = 0;
        }

    return m_Container[index].GetIOContext();
}

void Network::BoostMainManagerUseMultiContext ::StopContext()
{
    NETWORK_CLASS_IS_VALID_1;

    for (auto& value : m_Container)
        {
            value.StopContext();
        }
}

bool Network::BoostMainManagerUseMultiContext ::IsContextStop() const
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

void Network::BoostMainManagerUseMultiContext ::RestartContext()
{
    NETWORK_CLASS_IS_VALID_1;

    for (auto& value : m_Container)
        {
            value.RestartContext();
        }
}
#include STSTEM_WARNING_POP