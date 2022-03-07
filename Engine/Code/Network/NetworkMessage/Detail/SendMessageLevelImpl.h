///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 11:53)

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

        NODISCARD int GetTopLevelSize() const;
        NODISCARD ConstMessageInterfaceSharedPtr operator[](int index) const;
        NODISCARD MessageInterfaceSharedPtr operator[](int index);

        // �Զ���Ķ�����б��档
        void Insert(const MessageInterfaceSharedPtr& message);

        NODISCARD int GetRemainingSize() const noexcept;
        NODISCARD int GetCurrentSize() const noexcept;

        void Clear() noexcept;

    private:
        using MessagePtrContainer = std::vector<MessageInterfaceSharedPtr>;

    private:
        // ������������
        MessagePtrContainer topLevel;
        int messageMaxSize;
        int currentSize;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H
