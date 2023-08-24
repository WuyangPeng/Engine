///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:52)

#include "Database/DatabaseExport.h"

#include "CodeEntityAnalysisImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntity.h"

using namespace std::literals;

Database::CodeEntityAnalysisImpl::CodeEntityAnalysisImpl(const std::string& fileName)
    : namespaceName{ GetNamespaceName(fileName) }, fileName{ fileName }, container{}, mainTree{}
{
    Analysis();

    DATABASE_SELF_CLASS_IS_VALID_9;
}

System::String Database::CodeEntityAnalysisImpl::GetNamespaceName(const std::string& fileName)
{
    std::vector<std::string> pathComponents{};
    split(pathComponents, fileName, boost::algorithm::is_any_of("/\\"), boost::token_compress_off);
    if (!pathComponents.empty())
    {
        const auto backComponent = pathComponents.back();

        if (const auto dotPosition = backComponent.find_last_of('.');
            dotPosition != std::string::npos)
        {
            return CoreTools::StringConversion::MultiByteConversionStandard(backComponent.substr(0, dotPosition));
        }
        else
        {
            return CoreTools::StringConversion::MultiByteConversionStandard(backComponent);
        }
    }
    else
    {
        return CoreTools::StringConversion::MultiByteConversionStandard(fileName);
    }
}

void Database::CodeEntityAnalysisImpl::Analysis()
{
    AnalysisJson();
    AnalysisMain();
}

void Database::CodeEntityAnalysisImpl::AnalysisJson()
{
    read_json(fileName, mainTree);
}

void Database::CodeEntityAnalysisImpl::AnalysisMain()
{
    for (const auto& tree : mainTree)
    {
        try
        {
            InsertCodeEntity(tree.first, tree.second);
        }
        catch (const CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, Database, SYSTEM_TEXT("数据库实体类："), tree.first, SYSTEM_TEXT("配置值错误："), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

void Database::CodeEntityAnalysisImpl::InsertCodeEntity(const String& entityClassName, const BasicTree& basicTree)
{
    const auto databaseName = basicTree.get(SYSTEM_TEXT("databaseName"s), SYSTEM_TEXT(""s));

    const auto& entityTree = basicTree.get_child(SYSTEM_TEXT("entity"s));

    const auto fieldContainer = GetFieldContainer(entityTree);

    container.emplace_back(entityClassName, databaseName, fieldContainer);
}

Database::CodeEntityAnalysisImpl::FieldContainer Database::CodeEntityAnalysisImpl::GetFieldContainer(const BasicTree& entityTree)
{
    CodeEntityClass::FieldContainer fieldContainer{};

    for (const auto& tree : entityTree)
    {
        const auto& fieldName = tree.first;

        const auto& dataType = tree.second.get(SYSTEM_TEXT("dataType"s), SYSTEM_TEXT(""s));
        const auto& indexType = tree.second.get(SYSTEM_TEXT("indexType"s), SYSTEM_TEXT(""s));

        fieldContainer.emplace_back(fieldName, dataType, indexType);
    }

    return fieldContainer;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeEntityAnalysisImpl)

System::String Database::CodeEntityAnalysisImpl::GetNamespaceName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return namespaceName;
}

Database::CodeEntityAnalysisImpl::ContainerConstIter Database::CodeEntityAnalysisImpl::GetBegin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container.cbegin();
}

Database::CodeEntityAnalysisImpl::ContainerConstIter Database::CodeEntityAnalysisImpl::GetEnd() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container.cend();
}
