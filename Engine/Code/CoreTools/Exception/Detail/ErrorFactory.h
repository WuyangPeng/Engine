///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 15:16)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H
#define CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
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
        using ErrorImplSharedPtr = std::shared_ptr<ErrorImpl>;

        NODISCARD static ErrorImplSharedPtr Create(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message);
        NODISCARD static ErrorImplSharedPtr Create(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
    };
}

#endif  // CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H