///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 10:00)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

#include <set>

NETWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(MessageTypeConditionImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageTypeCondition final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(MessageTypeCondition);
        using VersionType = std::set<int>;

    public:
        NODISCARD static MessageTypeCondition CreateNullCondition();
        explicit MessageTypeCondition(const VersionType& version);
        MessageTypeCondition(int beginVersion, int endVersion);
        MessageTypeCondition(VersionsCondition condition, int version);

        CLASS_INVARIANT_DECLARE;

    private:
        explicit MessageTypeCondition(CoreTools::DisableNotThrow disableNotThrow);

    public:
        NODISCARD bool IsVersionsConform(int version) const;
        NODISCARD int GetMinVersion() const;
        NODISCARD int GetMaxVersion() const;

        NODISCARD bool operator<(const MessageTypeCondition& rhs) const;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H
