///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/25 15:59)

#ifndef CORE_TOOLS_CONTRACT_ASSERTION_H
#define CORE_TOOLS_CONTRACT_ASSERTION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

// ʹ��CoreTools��Assertion�����ļ�/�и��١�
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Assertion final
    {
    public:
        using ClassType = Assertion;

    public:
        template <typename... Types>
        Assertion(bool condition, const FunctionDescribed& functionDescribed, const char* format, Types&&... arguments);

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORE_TOOLS_CONTRACT_ASSERTION_H
