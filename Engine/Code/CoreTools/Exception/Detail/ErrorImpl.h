//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:20)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_IMPL_H
#define CORE_TOOLS_EXCEPTION_ERROR_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ErrorImpl
    {
    public:
        using ClassType = ErrorImpl;
        using String = System::String;

    public:
        ErrorImpl(const FunctionDescribed& functionDescribed, const String& message);
        virtual ~ErrorImpl() noexcept = 0;
        ErrorImpl(const ErrorImpl&) = default;
        ErrorImpl& operator=(const ErrorImpl&) = default;
        ErrorImpl(ErrorImpl&&) noexcept = default;
        ErrorImpl& operator=(ErrorImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] const char* GetCurrentFunction() const noexcept;
        [[nodiscard]] const char* GetFileName() const noexcept;
        [[nodiscard]] int GetLine() const noexcept;
        [[nodiscard]] const FunctionDescribed& GetFunctionDescribed() const noexcept;

        [[nodiscard]] virtual const String GetError() const;

    private:
        FunctionDescribed m_FunctionDescribed;
        String m_ErrorMessage;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_ERROR_IMPL_H