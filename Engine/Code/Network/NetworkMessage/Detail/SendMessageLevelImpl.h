//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:44)

#ifndef NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H
#define NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/MessageInterface.h"

#include <set>
#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SendMessageLevelImpl final
    {
    public:
        using ClassType = SendMessageLevelImpl;

    public:
        explicit SendMessageLevelImpl(int messageMaxSize);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetTopLevelSize() const;
        [[nodiscard]] const ConstMessageInterfaceSharedPtr operator[](int index) const;
        [[nodiscard]] MessageInterfaceSharedPtr operator[](int index);

        // �Զ���Ķ�����б��档
        void Insert(const MessageInterfaceSharedPtr& message);

        [[nodiscard]] int GetRemainingSize() const noexcept;
        [[nodiscard]] int GetCurrentSize() const noexcept;

        void Clear() noexcept;

    private:
        using MessagePtrContainer = std::vector<MessageInterfaceSharedPtr>;

    private:
        // ������������
        MessagePtrContainer m_TopLevel;
        int m_MessageMaxSize;
        int m_CurrentSize;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H
