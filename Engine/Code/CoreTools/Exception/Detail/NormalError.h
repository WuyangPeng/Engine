//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 14:20)

#ifndef CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H
#define CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H

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