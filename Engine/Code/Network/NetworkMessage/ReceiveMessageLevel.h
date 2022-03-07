///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:17)

#ifndef NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"
#include <vector>

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(ReceiveMessageLevel, ReceiveMessageLevelImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ReceiveMessageLevel final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ReceiveMessageLevel);
        using MessageContainer = std::vector<MessageInterfaceSharedPtr>;
        using MessageContainerConstIter = MessageContainer::const_iterator;

    public:
        NODISCARD static ReceiveMessageLevel Create();

    private:
        explicit ReceiveMessageLevel(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetTopLevelSize() const;
        NODISCARD ConstMessageInterfaceSharedPtr operator[](int index) const;

        // 对顶层的对象进行保存。
        void Insert(const MessageInterfaceSharedPtr& message);

        NODISCARD MessageContainerConstIter begin() const noexcept;
        NODISCARD MessageContainerConstIter end() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H
