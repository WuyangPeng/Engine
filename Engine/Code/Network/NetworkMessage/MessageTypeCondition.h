//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:05)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h"

#include <set>

NETWORK_EXPORT_SHARED_PTR(MessageTypeConditionImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageTypeCondition final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(MessageTypeCondition);
        using VersionType = std::set<int>;

    public:
        explicit MessageTypeCondition(const VersionType& version);
        MessageTypeCondition(int beginVersion, int endVersion);
        MessageTypeCondition(VersionsCondition condition, int version);
        MessageTypeCondition();

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] bool IsVersionsConform(int version) const;
        [[nodiscard]] int GetMinVersion() const;
        [[nodiscard]] int GetMaxVersion() const;

        [[nodiscard]] bool operator<(const MessageTypeCondition& rhs) const;

    private:
        IMPL_TYPE_DECLARE(MessageTypeCondition);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H
