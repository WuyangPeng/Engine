///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:52)

#include "CoreTools/CoreToolsExport.h"

#include "CodeMappingAnalysisImpl.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::CodeMappingAnalysisImpl::CodeMappingAnalysisImpl(String fileName)
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
    IFStreamManager stream{ fileName };
    stream.SetSimplifiedChinese();

    read_json(stream.GetFileStream(), mainTree);
}

void CoreTools::CodeMappingAnalysisImpl::AnalysisMain()
{
    for (const auto& tree : mainTree)
    {
        try
        {
            codeMapping.Insert(tree.first, tree.second.get_value<String>());
        }
        catch (const Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, Database, SYSTEM_TEXT("数据库映射类："), tree.first, SYSTEM_TEXT("配置值错误："), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CodeMappingAnalysisImpl)

System::String CoreTools::CodeMappingAnalysisImpl::GetElement(const String& codeKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto result = codeMapping.GetElement(codeKey);

    return result;
}
