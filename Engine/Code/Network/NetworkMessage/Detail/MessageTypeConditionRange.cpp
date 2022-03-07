///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:34)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionRange.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::MessageTypeConditionRange::MessageTypeConditionRange(int beginVersion, int endVersion)
    : ParentType{}, beginVersion{ beginVersion }, endVersion{ endVersion }
{
    if (endVersion < beginVersion)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("起始版本号大于结束版本号。"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionRange::IsValid() const noexcept
{
    if (beginVersion <= endVersion)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionRange::IsVersionsConform(int version) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return beginVersion <= version && version <= endVersion;
}

int Network::MessageTypeConditionRange::GetMinVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return beginVersion;
}

int Network::MessageTypeConditionRange::GetMaxVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return endVersion;
}
