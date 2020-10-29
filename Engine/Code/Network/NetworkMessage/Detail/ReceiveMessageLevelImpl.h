//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:44)

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

        [[nodiscard]] int GetTopLevelSize() const;
        [[nodiscard]] const ConstMessageInterfaceSharedPtr operator[](int index) const;

        // �Զ���Ķ�����б��档
        void Insert(const MessageInterfaceSharedPtr& message);

        [[nodiscard]] MessageContainerConstIter begin() const noexcept;
        [[nodiscard]] MessageContainerConstIter end() const noexcept;

    private:
        // ������������
        MessageContainer m_TopLevel;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H
