///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:28)

#include "CoreTools/CoreToolsExport.h"

#include "SimpleCSVException.h"
#include "Flags/CSVExceptionFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using namespace std::literals;

CoreTools::SimpleCSV::SimpleCSVException::SimpleCSVException(const FunctionDescribed& functionDescribed, const LastError& lastError, CSVExceptionType errorCode, const String& message)
    : ParentType{ functionDescribed, lastError, errorCode, message }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::SimpleCSVException::SimpleCSVException(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const String& message)
    : ParentType{ functionDescribed, lastError, errorCode, message }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, SimpleCSVException)

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const String& message)
{
    throw ClassType{ functionDescribed, lastError, errorCode, message };
}

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, CSVExceptionType errorCode, const String& message)
{
    LastError lastError{};

    throw ClassType{ functionDescribed, lastError, errorCode, message };
}

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const std::string& message)
{
    ThrowError(functionDescribed, lastError, errorCode, StringConversion::MultiByteConversionStandard(message));
}

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, CSVExceptionType errorCode, const std::string& message)
{
    ThrowError(functionDescribed, errorCode, StringConversion::MultiByteConversionStandard(message));
}

System::String CoreTools::SimpleCSV::SimpleCSVException::GetErrorCodeDescribed() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto errorCodeDescribed = ParentType::GetErrorCodeDescribed();

    const auto code = GetErrorCode();

    switch (code)
    {
        case CoreTools::SimpleCSV::CSVExceptionType::Overflow:
            errorCodeDescribed += SYSTEM_TEXT("（Overflow 溢出）, "sv);
            break;
        case CoreTools::SimpleCSV::CSVExceptionType::ValueType:
            errorCodeDescribed += SYSTEM_TEXT("（ValueType 值类型）, "sv);
            break;
        case CoreTools::SimpleCSV::CSVExceptionType::CellAddress:
            errorCodeDescribed += SYSTEM_TEXT("（CellAddress 单元地址）, "sv);
            break;
        case CoreTools::SimpleCSV::CSVExceptionType::Input:
            errorCodeDescribed += SYSTEM_TEXT("（Input 输入）, "sv);
            break;
        case CoreTools::SimpleCSV::CSVExceptionType::Internal:
            errorCodeDescribed += SYSTEM_TEXT("（Internal 内部的）, "sv);
            break;
        case CoreTools::SimpleCSV::CSVExceptionType::Property:
            errorCodeDescribed += SYSTEM_TEXT("（Property 属性）, "sv);
            break;
        case CoreTools::SimpleCSV::CSVExceptionType::Sheet:
            errorCodeDescribed += SYSTEM_TEXT("（Sheet 工作表）, "sv);
            break;
        default:
            break;
    }

    return errorCodeDescribed;
}
