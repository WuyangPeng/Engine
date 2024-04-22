/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:49)

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