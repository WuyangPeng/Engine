///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 10:38)

#include "CoreTools/CoreToolsExport.h"

#include "CodeMappingAnalysisImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

CoreTools::CodeMappingAnalysisImpl::CodeMappingAnalysisImpl(const std::wstring& fileName)
    : CodeMappingAnalysisImpl{ StringConversion::WideCharConversionMultiByte(fileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CodeMappingAnalysisImpl::CodeMappingAnalysisImpl(std::string fileName)
    : fileName{ std::move(fileName) }, codeMapping{ CodeMapping::Create() }, mainTree{}
{
    Analysis();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CodeMappingAnalysisImpl::Analysis()
{
    AnalysisJson();
    AnalysisMain();
}

void CoreTools::CodeMappingAnalysisImpl::AnalysisJson()
{
    read_json(fileName, mainTree);
}

void CoreTools::CodeMappingAnalysisImpl::AnalysisMain()
{
    for (const auto& [codeKey, element] : mainTree)
    {
        AnalysisMain(codeKey, element);
    }
}

void CoreTools::CodeMappingAnalysisImpl::AnalysisMain(const std::string& codeKey, const BasicTree& element)
{
    try
    {
        InsertElement(codeKey, element);
    }
    catch (const Error& error)
    {
        PrintErrorLog(codeKey, error);
    }
}

void CoreTools::CodeMappingAnalysisImpl::InsertElement(const std::string& codeKey, const BasicTree& element)
{
    codeMapping.Insert(StringConversion::Utf8ConversionStandard(codeKey),
                       StringConversion::Utf8ConversionStandard(element.get_value<std::string>()));
}

void CoreTools::CodeMappingAnalysisImpl::PrintErrorLog(const std::string& codeKey, const Error& error) noexcept
{
    LOG_SINGLETON_ENGINE_APPENDER(Error,
                                  CoreTools,
                                  SYSTEM_TEXT("映射键值："),
                                  codeKey,
                                  SYSTEM_TEXT("，错误："),
                                  error,
                                  SYSTEM_TEXT("。"),
                                  CoreTools::LogAppenderIOManageSign::TriggerAssert);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CodeMappingAnalysisImpl)

System::String CoreTools::CodeMappingAnalysisImpl::GetElement(const String& codeKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return codeMapping.GetElement(codeKey);
}
