///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:23)

#ifndef NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H
#define NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/MessageInterface.h"

#include <map>
#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ReceiveMessageLevelImpl final
    {
    public:
        using ClassType = ReceiveMessageLevelImpl;

        using MessageContainer = std::vector<MessageInterfaceSharedPtr>;
        using MessageContainerConstIter = MessageContainer::const_iterator;

    public:
        ReceiveMessageLevelImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetTopLevelSize() const;
        NODISCARD ConstMessageInterfaceSharedPtr operator[](int index) const;

        // �Զ���Ķ�����б��档
        void Insert(const MessageInterfaceSharedPtr& message);

        NODISCARD MessageContainerConstIter begin() const noexcept;
        NODISCARD MessageContainerConstIter end() const noexcept;

    private:
        // ������������
        MessageContainer topLevel;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H
