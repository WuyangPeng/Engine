/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:13)

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

        // 对顶层的对象进行保存。
        void Insert(const MessageInterfaceSharedPtr& message);

        NODISCARD int GetRemainingSize() const noexcept;
        NODISCARD int GetCurrentSize() const noexcept;

        void Clear() noexcept;

    private:
        using MessagePtrContainer = std::vector<MessageInterfaceSharedPtr>;

    private:
        // 顶层对象的流。
        MessagePtrContainer topLevel;
        int messageMaxSize;
        int currentSize;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H
