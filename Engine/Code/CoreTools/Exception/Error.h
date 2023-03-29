///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:02)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_H
#define CORE_TOOLS_EXCEPTION_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/format/format_fwd.hpp>
#include <string>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(ErrorImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Error
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(Error);
        using String = System::String;
        using WindowError = System::WindowError;
        using Format = boost::basic_format<System::TChar>;

    public:
        Error(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message);
        Error(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
        virtual ~Error() noexcept = default;
        Error(const Error& rhs) = default;
        Error& operator=(const Error& rhs) = default;
        Error(Error&& rhs) noexcept = default;
        Error& operator=(Error&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual String GetError() const;

        NODISCARD const char* GetCurrentFunction() const noexcept;
        NODISCARD const char* GetFileName() const noexcept;
        NODISCARD int GetLine() const noexcept;
        NODISCARD const FunctionDescribed& GetFunctionDescribed() const noexcept;

        [[noreturn]] static void ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
        [[noreturn]] static void ThrowError(const FunctionDescribed& functionDescribed, const String& message);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_ERROR_H