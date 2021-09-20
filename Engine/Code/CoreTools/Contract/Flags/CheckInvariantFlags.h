///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/21 9:51)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_FLAGS_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class CheckInvariantConditions
    {
        OnlyPreconditions,  // ������ǰ������
        OnlyPostconditions,  // �����Ժ�������
        Fully  // ��ȫ�಻��ʽ
    };

    enum class TriggerAssertCheck
    {
        Invariant,  // ����ʽ
        Assertion,  // ����
    };
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_FLAGS_H