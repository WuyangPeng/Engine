//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:43)

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
        THROW_EXCEPTION(SYSTEM_TEXT("�汾������Ϊ�ա�"s));
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

int Network::MessageTypeConditionSpecific::GetMinVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *m_Version.begin();
}

int Network::MessageTypeConditionSpecific::GetMaxVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return *m_Version.rbegin();
}
