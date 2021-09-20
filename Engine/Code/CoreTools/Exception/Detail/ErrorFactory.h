///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/30 15:11)

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