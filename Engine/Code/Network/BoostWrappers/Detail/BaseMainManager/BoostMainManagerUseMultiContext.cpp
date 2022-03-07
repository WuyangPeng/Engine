///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 22:27)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseMultiContext.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using boost::numeric_cast;
using std::make_unique;
using std::move;

Network::BoostMainManagerUseMultiContext::BoostMainManagerUseMultiContext(const ConfigurationSubStrategy& subStrategy)
    : ParentType{}, container{}, currentIndex{ 0 }
{
    InitContainer(subStrategy.GetValue(WrappersSubStrategy::MultiContext));

    NETWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Network::BoostMainManagerUseMultiContext::InitContainer(int containerNumber)
{
    for (auto index = 0; index < containerNumber; ++index)
    {
        auto executorWorkGuardContextThread = make_unique<ExecutorWorkGuardContextThread>(CoreTools::DisableNotThrow::Disable);

        container.push_back(move(executorWorkGuardContextThread));
    }

    if (container.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("boost 多环境数量为零！"s));
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

Network::IOContextType& Network::BoostMainManagerUseMultiContext::GetIOContext()
{
    NETWORK_CLASS_IS_VALID_1;

    const auto index = currentIndex++;
    if (numeric_cast<int>(container.size()) <= currentIndex)
    {
        currentIndex = 0;
    }

    return container[index].GetIOContext();
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
