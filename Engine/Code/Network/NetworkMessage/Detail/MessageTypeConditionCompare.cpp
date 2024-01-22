/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:20)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionCompare.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageManager.h"

Network::MessageTypeConditionCompare::MessageTypeConditionCompare(VersionsCondition condition, int version) noexcept
    : ParentType{}, condition{ condition }, compareVersion{ version }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTypeConditionCompare)

bool Network::MessageTypeConditionCompare::IsVersionsConform(int version) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    switch (condition)
    {
        case VersionsCondition::Greater:
            return compareVersion < version;
        case VersionsCondition::GreaterEqual:
            return compareVersion <= version;
        case VersionsCondition::Equality:
            return compareVersion == version;
        case VersionsCondition::LessEqual:
            return version <= compareVersion;
        case VersionsCondition::Less:
            return version < compareVersion;
        default:
            return false;
    }
}

int Network::MessageTypeConditionCompare::GetMinVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto minVersion = 0;

    switch (condition)
    {
        case VersionsCondition::Greater:
            minVersion = compareVersion + 1;
            break;
        case VersionsCondition::GreaterEqual:
        case VersionsCondition::Equality:
            minVersion = compareVersion;
            break;
        case VersionsCondition::LessEqual:
        case VersionsCondition::Less:
            minVersion = 0;
            break;
        default:
            minVersion = compareVersion;
            break;
    }

    return std::min(minVersion, MESSAGE_MANAGER_SINGLETON.GetFullVersion());
}

int Network::MessageTypeConditionCompare::GetMaxVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto minVersion = 0;

    switch (condition)
    {
        case VersionsCondition::Greater:
        case VersionsCondition::GreaterEqual:
            minVersion = MESSAGE_MANAGER_SINGLETON.GetFullVersion();
            break;
        case VersionsCondition::Equality:
        case VersionsCondition::LessEqual:
            minVersion = compareVersion;
            break;
        case VersionsCondition::Less:
            minVersion = compareVersion - 1;
            break;
        default:
            minVersion = compareVersion;
            break;
    }

    return std::max(minVersion, 0);
}
