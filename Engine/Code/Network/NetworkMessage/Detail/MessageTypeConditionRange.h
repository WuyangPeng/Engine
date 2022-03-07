///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 11:23)

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
        NODISCARD bool IsVersionsConform(int version) const noexcept final;
        NODISCARD int GetMinVersion() const noexcept final;
        NODISCARD int GetMaxVersion() const noexcept final;

    private:
        int beginVersion;
        int endVersion;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
