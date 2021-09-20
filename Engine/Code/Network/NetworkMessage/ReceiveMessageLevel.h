//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:16)

#ifndef NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"
#include <vector>

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(ReceiveMessageLevel,ReceiveMessageLevelImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ReceiveMessageLevel final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ReceiveMessageLevel);
        using MessageContainer = std::vector<MessageInterfaceSharedPtr>;
        using MessageContainerConstIter = MessageContainer::const_iterator;

    public:
        ReceiveMessageLevel();

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetTopLevelSize() const;
        [[nodiscard]] const ConstMessageInterfaceSharedPtr operator[](int index) const;

        // 对顶层的对象进行保存。
        void Insert(const MessageInterfaceSharedPtr& message);

        [[nodiscard]] MessageContainerConstIter begin() const noexcept;
        [[nodiscard]] MessageContainerConstIter end() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H
