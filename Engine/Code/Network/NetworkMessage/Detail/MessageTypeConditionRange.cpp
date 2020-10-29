//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:43)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionRange.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::MessageTypeConditionRange::MessageTypeConditionRange(int beginVersion, int endVersion)
    : ParentType{}, m_BeginVersion{ beginVersion }, m_EndVersion{ endVersion }
{
    if (m_EndVersion < m_BeginVersion)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ�汾�Ŵ��ڽ����汾�š�"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::MessageTypeConditionRange::IsValid() const noexcept
{
    if (m_BeginVersion <= m_EndVersion)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionRange::IsVersionsConform(int version) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_BeginVersion <= version && version <= m_EndVersion;
}

int Network::MessageTypeConditionRange::GetMinVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_BeginVersion;
}

int Network::MessageTypeConditionRange::GetMaxVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_EndVersion;
}
