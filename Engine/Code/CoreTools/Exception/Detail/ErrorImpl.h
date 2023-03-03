///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 13:30)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_IMPL_H
#define CORE_TOOLS_EXCEPTION_ERROR_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/Exception/ExceptionInternalFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ErrorImpl
    {
    public:
        using ClassType = ErrorImpl;
        using String = System::String;
        using FactoryType = ErrorFactory;

    public:
        ErrorImpl(const FunctionDescribed& functionDescribed, String message) noexcept;
        virtual ~ErrorImpl() noexcept = 0;
        ErrorImpl(const ErrorImpl& rhs) = default;
        ErrorImpl& operator=(const ErrorImpl& rhs) = default;
        ErrorImpl(ErrorImpl&& rhs) noexcept = default;
        ErrorImpl& operator=(ErrorImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD const char* GetCurrentFunction() const noexcept;
        NODISCARD const char* GetFileName() const noexcept;
        NODISCARD int GetLine() const noexcept;
        NODISCARD const FunctionDescribed& GetFunctionDescribed() const noexcept;

        NODISCARD virtual String GetError() const;

    private:
        FunctionDescribed functionDescribed;
        String errorMessage;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_ERROR_IMPL_H