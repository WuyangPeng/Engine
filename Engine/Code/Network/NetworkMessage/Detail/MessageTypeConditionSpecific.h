///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 11:24)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H

#include "Network/NetworkDll.h"

#include "MessageTypeConditionImpl.h"

#include <set>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionSpecific final : public MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionSpecific;
        using ParentType = MessageTypeConditionImpl;
        using VersionType = std::set<int>;

    public:
        explicit MessageTypeConditionSpecific(const VersionType& version);

        CLASS_INVARIANT_FINAL_DECLARE;

    public:
        NODISCARD bool IsVersionsConform(int version) const final;
        NODISCARD int GetMinVersion() const noexcept final;
        NODISCARD int GetMaxVersion() const final;

    private:
        VersionType m_Version;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H
