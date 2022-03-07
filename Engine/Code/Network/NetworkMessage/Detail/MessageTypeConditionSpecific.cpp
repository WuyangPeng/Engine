///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:34)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionSpecific.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::MessageTypeConditionSpecific::MessageTypeConditionSpecific(const VersionType& version)
    : ParentType{}, m_Version{ version }
{
    if (m_Version.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("版本号数据为空。"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionSpecific::IsValid() const noexcept
{
    if (ParentType::IsValid() && !m_Version.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionSpecific::IsVersionsConform(int version) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (m_Version.find(version) != m_Version.cend())
        return true;
    else
        return false;
}

int Network::MessageTypeConditionSpecific::GetMinVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *m_Version.begin();
}

int Network::MessageTypeConditionSpecific::GetMaxVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *m_Version.rbegin();
}
