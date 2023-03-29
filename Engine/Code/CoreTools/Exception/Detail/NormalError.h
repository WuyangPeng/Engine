///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:02)

#ifndef CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H
#define CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "ErrorImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE NormalError final : public ErrorImpl
    {
    public:
        using ClassType = NormalError;
        using ParentType = ErrorImpl;

    public:
        explicit NormalError(const FunctionDescribed& functionDescribed, const String& message);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H