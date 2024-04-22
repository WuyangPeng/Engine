/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:20)

#include "Network/NetworkExport.h"

#include "MessageManagerImpl.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::MessageManagerImpl::MessageManagerImpl() noexcept
    : idFactories{}, describeFactories{}, fullVersion{ CoreTools::Version::GetTcreFullVersion() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageManagerImpl)

Network::MessageManagerImpl::FactoryFunction Network::MessageManagerImpl::Find(int64_t messageId, int version) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = idFactories.find(messageId);
        iter != idFactories.cend())
    {
        for (const auto& element : iter->second)
        {
            if (element.first.IsVersionsConform(version))
            {
                return element.second;
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"s))
}

Network::MessageManagerImpl::FactoryFunction Network::MessageManagerImpl::Find(const std::string& messageDescribe, int version) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = describeFactories.find(messageDescribe);
        iter != describeFactories.cend())
    {
        for (const auto& element : iter->second)
        {
            if (element.first.IsVersionsConform(version))
            {
                return element.second;
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"s))
}

void Network::MessageManagerImpl::Insert(int64_t messageId, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
    NETWORK_CLASS_IS_VALID_9;

    idFactories[messageId].insert({ messageTypeCondition, function });
}

void Network::MessageManagerImpl::Insert(const std::string& message, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
    NETWORK_CLASS_IS_VALID_9;

    describeFactories[message].insert({ messageTypeCondition, function });
}

void Network::MessageManagerImpl::Remove(int64_t messageId, const MessageTypeCondition& messageTypeCondition)
{
    NETWORK_CLASS_IS_VALID_9;

    idFactories[messageId].erase(messageTypeCondition);

    if (idFactories[messageId].empty())
    {
        idFactories.erase(messageId);
    }
}

void Network::MessageManagerImpl::Remove(int64_t messageId) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    idFactories.erase(messageId);
}

void Network::MessageManagerImpl::SetFullVersion(int aFullVersion) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    fullVersion = aFullVersion;
}

int Network::MessageManagerImpl::GetFullVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return fullVersion;
}
