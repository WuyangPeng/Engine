/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:12)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H

#include "Network/NetworkDll.h"

#include "MessageTypeConditionImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionRange final : public MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionRange;
        using ParentType = MessageTypeConditionImpl;

    public:
        MessageTypeConditionRange(int beginVersion, int endVersion);

        CLASS_INVARIANT_FINAL_DECLARE;

    public:
        NODISCARD bool IsVersionsConform(int version) const noexcept override;
        NODISCARD int GetMinVersion() const noexcept override;
        NODISCARD int GetMaxVersion() const noexcept override;

    private:
        int beginVersion;
        int endVersion;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
