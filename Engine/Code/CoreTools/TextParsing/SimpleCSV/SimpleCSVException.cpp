/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 11:28)

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

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const std::wstring& message)
{
    throw ClassType{ functionDescribed, lastError, errorCode, StringConversion::WideCharConversionStandard(message) };
}

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, CSVExceptionType errorCode, const std::wstring& message)
{
    const LastError lastError{};

    throw ClassType{ functionDescribed, lastError, errorCode, StringConversion::WideCharConversionStandard(message) };
}

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, CSVExceptionType errorCode, const std::string& message)
{
    throw ClassType{ functionDescribed, lastError, errorCode, StringConversion::MultiByteConversionStandard(message) };
}

void CoreTools::SimpleCSV::SimpleCSVException::ThrowError(const FunctionDescribed& functionDescribed, CSVExceptionType errorCode, const std::string& message)
{
    const LastError lastError{};

    throw ClassType{ functionDescribed, lastError, errorCode, StringConversion::MultiByteConversionStandard(message) };
}

System::String CoreTools::SimpleCSV::SimpleCSVException::GetErrorCodeDescribed() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto errorCodeDescribed = ParentType::GetErrorCodeDescribed();

    switch (const auto code = GetErrorCode(); code)
    {
        case CSVExceptionType::Overflow:
            errorCodeDescribed += SYSTEM_TEXT("��Overflow �����, "sv);
            break;
        case CSVExceptionType::ValueType:
            errorCodeDescribed += SYSTEM_TEXT("��ValueType ֵ���ͣ�, "sv);
            break;
        case CSVExceptionType::CellAddress:
            errorCodeDescribed += SYSTEM_TEXT("��CellAddress ��Ԫ��ַ��, "sv);
            break;
        case CSVExceptionType::Input:
            errorCodeDescribed += SYSTEM_TEXT("��Input ���룩, "sv);
            break;
        case CSVExceptionType::Internal:
            errorCodeDescribed += SYSTEM_TEXT("��Internal �ڲ��ģ�, "sv);
            break;
        case CSVExceptionType::Property:
            errorCodeDescribed += SYSTEM_TEXT("��Property ���ԣ�, "sv);
            break;
        case CSVExceptionType::Sheet:
            errorCodeDescribed += SYSTEM_TEXT("��Sheet ������, "sv);
            break;
        default:
            break;
    }

    return errorCodeDescribed;
}
