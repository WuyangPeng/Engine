///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:38)

#include "Database/DatabaseExport.h"

#include "CodeMappingAnalysisImpl.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

Database::CodeMappingAnalysisImpl::CodeMappingAnalysisImpl(String fileName)
    : fileName{ std::move(fileName) }, codeMapping{ CodeMapping::Create() }, mainTree{}
{
    Analysis();

    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::CodeMappingAnalysisImpl::Analysis()
{
    AnalysisJson();
    AnalysisMain();
}

void Database::CodeMappingAnalysisImpl::AnalysisJson()
{
    CoreTools::IFStreamManager stream{ fileName };
    stream.SetSimplifiedChinese();

    read_json(stream.GetFileStream(), mainTree);
}

void Database::CodeMappingAnalysisImpl::AnalysisMain()
{
    for (const auto& tree : mainTree)
    {
        try
        {
            codeMapping.Insert(tree.first, tree.second.get_value<String>());
        }
        catch (const CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, Database, SYSTEM_TEXT("数据库映射类："), tree.first, SYSTEM_TEXT("配置值错误："), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeMappingAnalysisImpl)

System::String Database::CodeMappingAnalysisImpl::GetElement(const String& codeKey) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    auto result = codeMapping.GetElement(codeKey);

    return result;
}
