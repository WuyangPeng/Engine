//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:08)

#include "Network/NetworkExport.h"

#include "BufferSendStreamMultiIndexContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamMultiIndexContainer() noexcept
    : m_SocketIDContainer{}, m_HandleIDContainer{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::BufferSendStreamMultiIndexContainer::IsValid() const noexcept
{
    if (m_SocketIDContainer.size() == m_HandleIDContainer.size())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void Network::BufferSendStreamMultiIndexContainer::Insert(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy)
{
    NETWORK_CLASS_IS_VALID_1;

    BufferSendStreamContainerSharedPtr bufferSendStreamContainer{ make_shared<BufferSendStreamContainer>(socketID, handle, bufferSize, parserStrategy) };

    m_SocketIDContainer.insert({ socketID, bufferSendStreamContainer });
    m_HandleIDContainer.insert({ handle, bufferSendStreamContainer });
}

Network::BufferSendStreamMultiIndexContainer::BufferSendStreamContainerSharedPtr Network::BufferSendStreamMultiIndexContainer::GetBufferSendStreamContainerBySocketID(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    const auto iter = m_SocketIDContainer.find(socketID);

    if (iter != m_SocketIDContainer.cend())
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

    const auto iter = m_HandleIDContainer.find(handle);

    if (iter != m_HandleIDContainer.cend())
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

    const auto iter = m_SocketIDContainer.find(socketID);

    if (iter != m_SocketIDContainer.cend())
    {
        m_HandleIDContainer.erase(iter->second->GetACEHandle());
        m_SocketIDContainer.erase(iter);
    }
}

Network::BufferSendStreamMultiIndexContainer::SocketIDContainerConstIter Network::BufferSendStreamMultiIndexContainer::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_SocketIDContainer.begin();
}

Network::BufferSendStreamMultiIndexContainer::SocketIDContainerConstIter Network::BufferSendStreamMultiIndexContainer::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_SocketIDContainer.end();
}
