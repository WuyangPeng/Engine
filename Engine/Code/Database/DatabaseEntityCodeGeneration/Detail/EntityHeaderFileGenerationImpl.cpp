/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:51)

#include "Database/DatabaseExport.h"

#include "EntityHeaderFileGenerationImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntity.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"

Database::EntityHeaderFileGenerationImpl::EntityHeaderFileGenerationImpl(String fileName, String namespaceName, CodeEntityClass codeEntityClass, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : fileName{ std::move(fileName) },
      namespaceName{ std::move(namespaceName) },
      codeEntityClass{ std::move(codeEntityClass) },
      codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, EntityHeaderFileGenerationImpl)

System::String Database::EntityHeaderFileGenerationImpl::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CoreTools::IFileStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    auto content = streamManager.GetFileContent();

    const auto copyright = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright"));

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Copyright$"), copyright);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Namespace$"), namespaceName);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$NamespaceUppercaseSeparator$"), CoreTools::StringUtility::ToUpperMacro(namespaceName));

    const auto entityClassName = codeEntityClass.GetEntityClassName();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Class$"), entityClassName);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassUppercaseSeparator$"), CoreTools::StringUtility::ToUpperMacro(entityClassName));

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyType$"), codeEntityClass.GetKeyType());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$KeyName$"), codeEntityClass.GetKeyName());
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$DatabaseName$"), codeEntityClass.GetDatabaseName());

    const auto getDeclaration = codeMappingAnalysis.GetElement(SYSTEM_TEXT("GetDeclaration"));
    const auto setDeclaration = codeMappingAnalysis.GetElement(SYSTEM_TEXT("SetDeclaration"));
    const auto modifyDeclaration = codeMappingAnalysis.GetElement(SYSTEM_TEXT("ModifyDeclaration"));
    const auto describe = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Describe"));
    const auto field = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Field"));

    String getDeclarationContent{};
    String setDeclarationContent{};
    String modifyDeclarationContent{};
    String describeContent{};
    String fieldContent{};
    for (const auto& element : codeEntityClass)
    {
        auto copyGetDeclaration = getDeclaration;
        auto copySetDeclaration = setDeclaration;
        auto copyModifyDeclaration = modifyDeclaration;
        auto copyDescribe = describe;
        auto copyField = field;

        boost::algorithm::replace_all(copyDescribe, SYSTEM_TEXT("$Entity$"), element.GetFieldName());
        boost::algorithm::replace_all(copyField, SYSTEM_TEXT("$Entity$"), element.GetFieldName());

        boost::algorithm::replace_all(copyGetDeclaration, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
        boost::algorithm::replace_all(copySetDeclaration, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
        boost::algorithm::replace_all(copyField, SYSTEM_TEXT("$EntityType$"), element.GetDataType());

        boost::algorithm::replace_all(copyGetDeclaration, SYSTEM_TEXT("$EntityFirstUppercase$"), CoreTools::StringUtility::ToFirstLetterUpper(element.GetFieldName()));
        boost::algorithm::replace_all(copySetDeclaration, SYSTEM_TEXT("$EntityFirstUppercase$"), CoreTools::StringUtility::ToFirstLetterUpper(element.GetFieldName()));

        if (element.GetDataType() == SYSTEM_TEXT("Int32") ||
            element.GetDataType() == SYSTEM_TEXT("Int32Count") ||
            element.GetDataType() == SYSTEM_TEXT("Int64") ||
            element.GetDataType() == SYSTEM_TEXT("Int64Count") ||
            element.GetDataType() == SYSTEM_TEXT("Double") ||
            element.GetDataType() == SYSTEM_TEXT("Bool"))
        {
            boost::algorithm::replace_all(copyGetDeclaration, SYSTEM_TEXT("$EntityIsNoexcept$"), SYSTEM_TEXT(" noexcept"));
        }
        else
        {
            boost::algorithm::replace_all(copyGetDeclaration, SYSTEM_TEXT("$EntityIsNoexcept$"), SYSTEM_TEXT(""));
        }

        if (element.GetDataType() == SYSTEM_TEXT("Int32Count") ||
            element.GetDataType() == SYSTEM_TEXT("Int64Count"))
        {
            boost::algorithm::replace_all(copyModifyDeclaration, SYSTEM_TEXT("$EntityType$"), element.GetDataType());
            boost::algorithm::replace_all(copyModifyDeclaration, SYSTEM_TEXT("$EntityFirstUppercase$"), CoreTools::StringUtility::ToFirstLetterUpper(element.GetFieldName()));
        }

        if (element.GetDataType() == SYSTEM_TEXT("Bool"))
        {
            boost::algorithm::replace_all(copyGetDeclaration, SYSTEM_TEXT("$IsBool$"), SYSTEM_TEXT("Is"));
        }
        else
        {
            boost::algorithm::replace_all(copyGetDeclaration, SYSTEM_TEXT("$IsBool$"), SYSTEM_TEXT("Get"));
        }

        if (element.GetIndexType() == SYSTEM_TEXT("Key"))
        {
            boost::algorithm::replace_all(copyDescribe, SYSTEM_TEXT("$EntityIsKey$"), SYSTEM_TEXT("_id"));
            boost::algorithm::replace_all(copyField, SYSTEM_TEXT("$EntityIsIndex$"), SYSTEM_TEXT(", IndexType::Key"));
        }
        else
        {
            boost::algorithm::replace_all(copyDescribe, SYSTEM_TEXT("$EntityIsKey$"), element.GetFieldName());
            boost::algorithm::replace_all(copyField, SYSTEM_TEXT("$EntityIsIndex$"), SYSTEM_TEXT(""));
        }

        getDeclarationContent += copyGetDeclaration;
        getDeclarationContent += SYSTEM_TEXT("\n");

        setDeclarationContent += copySetDeclaration;
        setDeclarationContent += SYSTEM_TEXT("\n");

        describeContent += copyDescribe;
        describeContent += SYSTEM_TEXT("\n");

        fieldContent += copyField;
        fieldContent += SYSTEM_TEXT("\n");

        if (element.GetDataType() == SYSTEM_TEXT("Int32Count") ||
            element.GetDataType() == SYSTEM_TEXT("Int64Count"))
        {
            modifyDeclarationContent += copyModifyDeclaration;

            modifyDeclarationContent += SYSTEM_TEXT("\n");
        }
    }

    if (!getDeclarationContent.empty())
    {
        getDeclarationContent += SYSTEM_TEXT("\n");
    }

    if (!setDeclarationContent.empty())
    {
        setDeclarationContent += SYSTEM_TEXT("\n");
    }

    if (!modifyDeclarationContent.empty())
    {
        modifyDeclarationContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetDeclaration$"), getDeclarationContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SetDeclaration$"), setDeclarationContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ModifyDeclaration$"), modifyDeclarationContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Describe$"), describeContent);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Field$"), fieldContent);

    return content;
}
