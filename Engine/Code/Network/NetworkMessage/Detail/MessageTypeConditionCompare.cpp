//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 13:42)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionCompare.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageManager.h"

using std::max;
using std::min;

Network::MessageTypeConditionCompare::MessageTypeConditionCompare(VersionsCondition condition, int version) noexcept
    : ParentType{}, m_Condition{ condition }, m_Version{ version }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTypeConditionCompare)

bool Network::MessageTypeConditionCompare::IsVersionsConform(int version) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    switch (m_Condition)
    {
        case Network::VersionsCondition::Greater:
            return m_Version < version;
        case Network::VersionsCondition::GreaterEequal:
            return m_Version <= version;
        case Network::VersionsCondition::Equality:
            return m_Version == version;
        case Network::VersionsCondition::LessEequal:
            return version <= m_Version;
        case Network::VersionsCondition::Less:
            return version < m_Version;
        default:
            return false;
    }
}

int Network::MessageTypeConditionCompare::GetMinVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto minVersion = 0;

    switch (m_Condition)
    {
        case Network::VersionsCondition::Greater:
            minVersion = m_Version + 1;
            break;
        case Network::VersionsCondition::GreaterEequal:
        case Network::VersionsCondition::Equality:
            minVersion = m_Version;
            break;
        case Network::VersionsCondition::LessEequal:
        case Network::VersionsCondition::Less:
            minVersion = 0;
            break;
        default:
            minVersion = m_Version;
            break;
    }

    return min(minVersion, MESSAGE_MANAGER_SINGLETON.GetFullVersion());
}

int Network::MessageTypeConditionCompare::GetMaxVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto minVersion = 0;

    switch (m_Condition)
    {
        case Network::VersionsCondition::Greater:
        case Network::VersionsCondition::GreaterEequal:
            minVersion = MESSAGE_MANAGER_SINGLETON.GetFullVersion();
            break;
        case Network::VersionsCondition::Equality:
        case Network::VersionsCondition::LessEequal:
            minVersion = m_Version;
            break;
        case Network::VersionsCondition::Less:
            minVersion = m_Version - 1;
            break;
        default:
            minVersion = m_Version;
            break;
    }

    return max(minVersion, 0);
}

