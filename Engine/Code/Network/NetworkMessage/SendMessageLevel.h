/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:19)

#ifndef NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(SendMessageLevel, SendMessageLevelImpl);

// 被加载的顶层对象。
namespace Network
{
    class NETWORK_DEFAULT_DECLARE SendMessageLevel final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SendMessageLevel);

    public:
        explicit SendMessageLevel(int messageMaxSize);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetTopLevelSize() const;
        NODISCARD ConstMessageInterfaceSharedPtr operator[](int index) const;
        NODISCARD MessageInterfaceSharedPtr operator[](int index);

        // 对顶层的对象进行保存。
        void Insert(const MessageInterfaceSharedPtr& message);

        NODISCARD int GetRemainingSize() const noexcept;
        NODISCARD int GetCurrentSize() const noexcept;

        void Clear();

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H
