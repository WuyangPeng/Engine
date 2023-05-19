///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:23)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseMultiContext.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::BoostMainManagerUseMultiContext::BoostMainManagerUseMultiContext(const ConfigurationSubStrategy& subStrategy)
    : ParentType{}, container{}, currentIndex{ 0 }
{
    InitContainer(subStrategy.GetValue(WrappersSubStrategy::MultiContext));

    NETWORK_SELF_CLASS_IS_VALID_1;
}

void Network::BoostMainManagerUseMultiContext::InitContainer(int containerNumber)
{
    for (auto index = 0; index < containerNumber; ++index)
    {
        auto executorWorkGuardContextThread = std::make_unique<ExecutorWorkGuardContextThread>(CoreTools::DisableNotThrow::Disable);

        container.push_back(std::move(executorWorkGuardContextThread));
    }

    if (container.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("boost 多环境数量为零！"s))
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::BoostMainManagerUseMultiContext::IsValid() const noexcept
{
    try
    {
        if (0 <= currentIndex && currentIndex < boost::numeric_cast<int>(container.size()))
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Network::BoostMainManagerUseMultiContext::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_1;
}

Network::IoContextType& Network::BoostMainManagerUseMultiContext::GetContext()
{
    NETWORK_CLASS_IS_VALID_1;

    const auto index = currentIndex++;
    if (boost::numeric_cast<int>(container.size()) <= currentIndex)
    {
        currentIndex = 0;
    }

    return container[index].GetContext();
}

void Network::BoostMainManagerUseMultiContext::StopContext()
{
    NETWORK_CLASS_IS_VALID_1;

    for (auto& value : container)
    {
        value.StopContext();
    }
}

bool Network::BoostMainManagerUseMultiContext::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    for (const auto& value : container)
    {
        if (!value.IsContextStop())
        {
            return false;
        }
    }

    return true;
}

void Network::BoostMainManagerUseMultiContext::RestartContext()
{
    NETWORK_CLASS_IS_VALID_1;

    for (auto& value : container)
    {
        value.RestartContext();
    }
}
