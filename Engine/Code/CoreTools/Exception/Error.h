//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:21)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_H
#define CORE_TOOLS_EXCEPTION_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/format/format_fwd.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ErrorImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Error
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(Error);
        using String = System::String;
        using WindowError = System::WindowError;
        using Format = boost::basic_format<System::TChar>;

    public:
        Error(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message);
        Error(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
        virtual ~Error() noexcept = default;
        Error(const Error&) = default;
        Error& operator=(const Error&) = default;
        Error(Error&&) noexcept = default;
        Error& operator=(Error&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual const String GetError() const;

        [[nodiscard]] const char* GetCurrentFunction() const noexcept;
        [[nodiscard]] const char* GetFileName() const noexcept;
        [[nodiscard]] int GetLine() const noexcept;
        [[nodiscard]] const FunctionDescribed& GetFunctionDescribed() const noexcept;

        [[noreturn]] static void ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
        [[noreturn]] static void ThrowError(const FunctionDescribed& functionDescribed, const String& message);

    private:
        IMPL_TYPE_DECLARE(Error);
    };
}

#endif  // CORE_TOOLS_EXCEPTION_ERROR_H