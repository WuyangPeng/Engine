//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:16)

#ifndef NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_EXPORT_SHARED_PTR(SendMessageLevelImpl);

namespace Network
{
    // 被加载的顶层对象。
    class NETWORK_DEFAULT_DECLARE SendMessageLevel final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SendMessageLevel);

    public:
        explicit SendMessageLevel(int messageMaxSize);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetTopLevelSize() const;
        [[nodiscard]] const ConstMessageInterfaceSharedPtr operator[](int index) const;
        [[nodiscard]] MessageInterfaceSharedPtr operator[](int index);

        // 对顶层的对象进行保存。
        void Insert(const MessageInterfaceSharedPtr& messagePtr);

        [[nodiscard]] int GetRemainingSize() const noexcept;
        [[nodiscard]] int GetCurrentSize() const noexcept;

        void Clear();

    private:
        IMPL_TYPE_DECLARE(SendMessageLevel);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H
