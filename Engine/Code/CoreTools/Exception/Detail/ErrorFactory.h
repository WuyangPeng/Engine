//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:20)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H
#define CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ErrorFactory final
    {
    public:
        using ClassType = ErrorFactory;
        using String = System::String;
        using WindowError = System::WindowError;
        using ErrorImplPtr = std::shared_ptr<ErrorImpl>;

        [[nodiscard]] static ErrorImplPtr CreateError(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message);
        [[nodiscard]] static ErrorImplPtr CreateError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
    };
}

#endif  // CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H