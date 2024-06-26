/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:32)

#include "Network/NetworkExport.h"

#include "BufferSendStreamMultiIndexContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamMultiIndexContainer() noexcept
    : socketIdContainer{}, handleIdContainer{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::BufferSendStreamMultiIndexContainer::IsValid() const noexcept
{
    if (socketIdContainer.size() == handleIdContainer.size())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Network::BufferSendStreamMultiIndexContainer::Insert(int64_t socketId, ACEHandleType handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
{
    NETWORK_CLASS_IS_VALID_1;

    auto bufferSendStreamContainer = std::make_shared<BufferSendStreamContainer>(socketId, handle, bufferSize, parserStrategy, encryptedCompressionStrategy);

    socketIdContainer.emplace(socketId, bufferSendStreamContainer);
    handleIdContainer.emplace(handle, bufferSendStreamContainer);
}

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamContainerSharedPtr Network::BufferSendStreamMultiIndexContainer::GetBufferSendStreamContainerBySocketId(int64_t socketId)
{
    NETWORK_CLASS_IS_VALID_1;

    if (const auto iter = socketIdContainer.find(socketId);
        iter != socketIdContainer.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的socketId"s))
    }
}

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamContainerSharedPtr Network::BufferSendStreamMultiIndexContainer::GetBufferSendStreamContainerByHandle(ACEHandle handle)
{
    NETWORK_CLASS_IS_VALID_1;

    if (const auto iter = handleIdContainer.find(handle);
        iter != handleIdContainer.cend())
    {
        if (auto result = iter->second.lock();
            result != nullptr)
        {
            return result;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的handle"s))
}

void Network::BufferSendStreamMultiIndexContainer::Erase(int64_t socketId)
{
    NETWORK_CLASS_IS_VALID_1;

    if (const auto iter = socketIdContainer.find(socketId);
        iter != socketIdContainer.cend())
    {
        handleIdContainer.erase(iter->second->GetACEHandle());
        socketIdContainer.erase(iter);
    }
}

Network::BufferSendStreamMultiIndexContainer::SocketIdContainerConstIter Network::BufferSendStreamMultiIndexContainer::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return socketIdContainer.begin();
}

Network::BufferSendStreamMultiIndexContainer::SocketIdContainerConstIter Network::BufferSendStreamMultiIndexContainer::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return socketIdContainer.end();
}
