///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 17:14)

#include "Network/NetworkExport.h"

#include "BufferSendStreamMultiIndexContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamMultiIndexContainer() noexcept
    : socketIDContainer{}, handleIDContainer{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::BufferSendStreamMultiIndexContainer::IsValid() const noexcept
{
    if (socketIDContainer.size() == handleIDContainer.size())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Network::BufferSendStreamMultiIndexContainer::Insert(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
{
    NETWORK_CLASS_IS_VALID_1;

    auto bufferSendStreamContainer = make_shared<BufferSendStreamContainer>(socketID, handle, bufferSize, parserStrategy, encryptedCompressionStrategy);

    socketIDContainer.insert({ socketID, bufferSendStreamContainer });
    handleIDContainer.insert({ handle, bufferSendStreamContainer });
}

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamContainerSharedPtr Network::BufferSendStreamMultiIndexContainer::GetBufferSendStreamContainerBySocketID(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    const auto iter = socketIDContainer.find(socketID);

    if (iter != socketIDContainer.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的socketID"s));
    }
}

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamContainerSharedPtr Network::BufferSendStreamMultiIndexContainer::GetBufferSendStreamContainerByHandle(ACEHandle handle)
{
    NETWORK_CLASS_IS_VALID_1;

    const auto iter = handleIDContainer.find(handle);

    if (iter != handleIDContainer.cend())
    {
        auto result = iter->second.lock();

        if (result)
        {
            return result;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的handle"s));
}

void Network::BufferSendStreamMultiIndexContainer::Erase(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    const auto iter = socketIDContainer.find(socketID);

    if (iter != socketIDContainer.cend())
    {
        handleIDContainer.erase(iter->second->GetACEHandle());
        socketIDContainer.erase(iter);
    }
}

Network::BufferSendStreamMultiIndexContainer::SocketIDContainerConstIter Network::BufferSendStreamMultiIndexContainer::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return socketIDContainer.begin();
}

Network::BufferSendStreamMultiIndexContainer::SocketIDContainerConstIter Network::BufferSendStreamMultiIndexContainer::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return socketIDContainer.end();
}
