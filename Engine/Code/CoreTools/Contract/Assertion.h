///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/22 14:40)

#ifndef CORE_TOOLS_CONTRACT_ASSERTION_H
#define CORE_TOOLS_CONTRACT_ASSERTION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"

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
