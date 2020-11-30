//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:40)

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
        [[nodiscard]] bool IsVersionsConform(int version) const final;
        [[nodiscard]] int GetMinVersion() const noexcept final;
        [[nodiscard]] int GetMaxVersion() const final;

    private:
        VersionType m_Version;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H
