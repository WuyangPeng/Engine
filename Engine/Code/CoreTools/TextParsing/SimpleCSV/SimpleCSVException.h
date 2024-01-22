/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:49)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_EXCEPTION_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_EXCEPTION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Exception/GameErrorDetail.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE SimpleCSVException final : public GameError<CSVExceptionType>
    {
    public:
        using ClassType = SimpleCSVException;
        using ParentType = GameError<CSVExceptionType>;

    public:
        SimpleCSVException(const FunctionDescribed& functionDescribed, const LastError& lastError, CSVExceptionType errorCode, const String& message);
        SimpleCSVException(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const String& message);

        CLASS_INVARIANT_FINAL_DECLARE;

        SYSTEM_NORETURN static void ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const std::wstring& message);
        SYSTEM_NORETURN static void ThrowError(const FunctionDescribed& functionDescribed, CSVExceptionType errorCode, const std::wstring& message);
        SYSTEM_NORETURN static void ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const std::string& message);
        SYSTEM_NORETURN static void ThrowError(const FunctionDescribed& functionDescribed, CSVExceptionType errorCode, const std::string& message);

    protected:
        NODISCARD String GetErrorCodeDescribed() const override;
    };
}

#define THROW_SIMPLE_CSV_EXCEPTION(errorCode, error)                                                                 \
    {                                                                                                                \
        using namespace std::literals;                                                                               \
        CoreTools::SimpleCSV::SimpleCSVException::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), (errorCode), (error)); \
    }

#define THROW_LAST_ERROR_SIMPLE_CSV_EXCEPTION(lastError, errorCode, error)                                                        \
    {                                                                                                                             \
        using namespace std::literals;                                                                                            \
        CoreTools::SimpleCSV::SimpleCSVException::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), (lastError), (errorCode), (error)); \
    }

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_EXCEPTION_H