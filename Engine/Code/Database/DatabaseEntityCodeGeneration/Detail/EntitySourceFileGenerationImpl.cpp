///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:53)

#include "Database/DatabaseExport.h"

#include "EntitySourceFileGenerationImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntity.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"

Database::EntitySourceFileGenerationImpl::EntitySourceFileGenerationImpl(String fileName, String namespaceName, CodeEntityClass codeEntityClass, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : fileName{ std::move(fileName) },
      namespaceName{ std::move(namespaceName) },
      codeEntityClass{ std::move(codeEntityClass) },
      codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, EntitySourceFileGenerationImpl)

System::String Database::EntitySourceFileGenerationImpl::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CoreTools::IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    auto content = streamManager.GetFileContent();

    const auto copyright = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright"));

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Copyright$"), copyright);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Namespace$"), namespaceName);

    const auto entityClassName = codeEntityClass.GetEntityClassName();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Class$"), entityClassName);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyType$"), codeEntityClass.GetKeyType());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyName$"), codeEntityClass.GetKeyName());

    const auto fieldAssignment = codeMappingAnalysis.GetElement(SYSTEM_TEXT("FieldAssignment"));
    const auto fieldInit = codeMappingAnalysis.GetElement(SYSTEM_TEXT("FieldInit"));
    const auto getDefine = codeMappingAnalysis.GetElement(SYSTEM_TEXT("GetDefine"));
    const auto setDefine = codeMappingAnalysis.GetElement(SYSTEM_TEXT("SetDefine"));
    const auto modifyDefine = codeMappingAnalysis.GetElement(SYSTEM_TEXT("ModifyDefine"));
    const auto databaseField = codeMappingAnalysis.GetElement(SYSTEM_TEXT("DatabaseField"));

    String fieldAssignmentContent{};
    String fieldInitContent{};
    String getDefineContent{};
    String setDefineContent{};
    String modifyDefineContent{};
    String databaseFieldContent{};
    auto index = 0;
    for (const auto& element : codeEntityClass)
    {
        auto copyFieldAssignment = fieldAssignment;
        auto copyFieldInit = fieldInit;
        auto copyGetDefine = getDefine;
        auto copySetDefine = setDefine;
        auto copyModifyDefine = modifyDefine;
        auto copyDatabaseField = databaseField;

        boost::algorithm::replace_all(copyFieldAssignment, SYSTEM_TEXT("$Entity$"), element.GetFieldName());
        boost::algorithm::replace_all(copyFieldInit, SYSTEM_TEXT("$Entity$"), element.GetFieldName());
        boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$Entity$"), element.GetFieldName());
        boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$Entity$"), element.GetFieldName());
        boost::algorithm::replace_all(copyDatabaseField, SYSTEM_TEXT("$Entity$"), element.GetFieldName());

        boost::algorithm::replace_all(copyFieldAssignment, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
        boost::algorithm::replace_all(copyFieldInit, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
        boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
        boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$EntityType$"), element.GetDataType());

        boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$Namespace$"), namespaceName);
        boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$Namespace$"), namespaceName);

        boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$Class$"), entityClassName);
        boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$Class$"), entityClassName);

        boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$EntityFirstUppercase$"), CoreTools::StringUtility::ToFirstLetterUpper(element.GetFieldName()));
        boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$EntityFirstUppercase$"), CoreTools::StringUtility::ToFirstLetterUpper(element.GetFieldName()));

        if (element.GetDataType() == SYSTEM_TEXT("Int32") ||
            element.GetDataType() == SYSTEM_TEXT("Int32Count") ||
            element.GetDataType() == SYSTEM_TEXT("Int64") ||
            element.GetDataType() == SYSTEM_TEXT("Int64Count") ||
            element.GetDataType() == SYSTEM_TEXT("Double") ||
            element.GetDataType() == SYSTEM_TEXT("Bool"))
        {
            boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$EntityIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$EntityIsNoexcept$"), SYSTEM_TEXT(""));
        }

        if (element.GetDataType() == SYSTEM_TEXT("Int32Count") ||
            element.GetDataType() == SYSTEM_TEXT("Int64Count"))
        {
            boost::algorithm::replace_all(copyModifyDefine, SYSTEM_TEXT("$Entity$"), element.GetFieldName());
            boost::algorithm::replace_all(copyModifyDefine, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
            boost::algorithm::replace_all(copyModifyDefine, SYSTEM_TEXT("$Namespace$"), namespaceName);
            boost::algorithm::replace_all(copyModifyDefine, SYSTEM_TEXT("$Class$"), entityClassName);
            boost::algorithm::replace_all(copyModifyDefine, SYSTEM_TEXT("$EntityFirstUppercase$"), CoreTools::StringUtility::ToFirstLetterUpper(element.GetFieldName()));
        }

        if (element.GetDataType() == SYSTEM_TEXT("Bool"))
        {
            boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$IsBool$"), SYSTEM_TEXT("Is"));
            boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$IsBool$"), SYSTEM_TEXT("Is"));
        }
        else
        {
            boost::algorithm::replace_all(copyGetDefine, SYSTEM_TEXT("$IsBool$"), SYSTEM_TEXT("Get"));
            boost::algorithm::replace_all(copySetDefine, SYSTEM_TEXT("$IsBool$"), SYSTEM_TEXT("Get"));
        }

        if (index != 0)
        {
            boost::algorithm::replace_all(copyDatabaseField, SYSTEM_TEXT("$EntityIndent$"), SYSTEM_TEXT("                                                            "));
        }
        else
        {
            boost::algorithm::replace_all(copyDatabaseField, SYSTEM_TEXT("$EntityIndent$"), SYSTEM_TEXT(""));
        }

        ++index;

        if (index == codeEntityClass.GetSize())
        {
            boost::algorithm::replace_all(copyFieldAssignment, SYSTEM_TEXT("$FieldIsEnd$"), SYSTEM_TEXT(""));
            boost::algorithm::replace_all(copyFieldInit, SYSTEM_TEXT("$FieldIsEnd$"), SYSTEM_TEXT(""));
            boost::algorithm::replace_all(copyDatabaseField, SYSTEM_TEXT("$FieldIsEnd$"), SYSTEM_TEXT(""));
        }
        else
        {
            boost::algorithm::replace_all(copyFieldAssignment, SYSTEM_TEXT("$FieldIsEnd$"), SYSTEM_TEXT(","));
            boost::algorithm::replace_all(copyFieldInit, SYSTEM_TEXT("$FieldIsEnd$"), SYSTEM_TEXT(","));
            boost::algorithm::replace_all(copyDatabaseField, SYSTEM_TEXT("$FieldIsEnd$"), SYSTEM_TEXT(","));
        }

        fieldAssignmentContent += copyFieldAssignment;
        fieldAssignmentContent += SYSTEM_TEXT("\n");

        if (index != 1)
        {
            fieldInitContent += copyFieldInit;
            fieldInitContent += SYSTEM_TEXT("\n");
        }

        getDefineContent += copyGetDefine;
        getDefineContent += SYSTEM_TEXT("\n");

        setDefineContent += copySetDefine;
        setDefineContent += SYSTEM_TEXT("\n");

        databaseFieldContent += copyDatabaseField;
        if (index != codeEntityClass.GetSize())
        {
            databaseFieldContent += SYSTEM_TEXT("\n");
        }

        if (element.GetDataType() == SYSTEM_TEXT("Int32Count") ||
            element.GetDataType() == SYSTEM_TEXT("Int64Count"))
        {
            modifyDefineContent += copyModifyDefine;

            modifyDefineContent += SYSTEM_TEXT("\n");
        }
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$FieldAssignment$"), fieldAssignmentContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$FieldInit$"), fieldInitContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetDefine$"), getDefineContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SetDefine$"), setDefineContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ModifyDefine$"), modifyDefineContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DatabaseField$"), databaseFieldContent);

    return content;
}
