///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:34)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionSpecific.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::MessageTypeConditionSpecific::MessageTypeConditionSpecific(const VersionType& version)
    : ParentType{}, specificVersion{ version }
{
    if (specificVersion.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("版本号数据为空。"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionSpecific::IsValid() const noexcept
{
    if (ParentType::IsValid() && !specificVersion.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionSpecific::IsVersionsConform(int version) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return specificVersion.contains(version);
}

int Network::MessageTypeConditionSpecific::GetMinVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *specificVersion.begin();
}

int Network::MessageTypeConditionSpecific::GetMaxVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *specificVersion.rbegin();
}
