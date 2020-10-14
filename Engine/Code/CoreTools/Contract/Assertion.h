//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/10 13:03)

#ifndef CORE_TOOLS_CONTRACT_ASSERTION_H
#define CORE_TOOLS_CONTRACT_ASSERTION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

// 使用CoreTools的Assertion用于文件/行跟踪。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Assertion final
    {
    public:
        using ClassType = Assertion;

    public:
        Assertion(bool condition, const FunctionDescribed& functionDescribed, const char* format, ...);

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORE_TOOLS_CONTRACT_ASSERTION_H
