/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:21)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionRange.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::MessageTypeConditionRange::MessageTypeConditionRange(int beginVersion, int endVersion)
    : ParentType{}, beginVersion{ beginVersion }, endVersion{ endVersion }
{
    if (endVersion < beginVersion)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ�汾�Ŵ��ڽ����汾�š�"s))
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
