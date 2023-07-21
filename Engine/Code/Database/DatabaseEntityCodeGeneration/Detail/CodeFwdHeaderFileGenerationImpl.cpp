///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/03 21:53)

#include "Database/DatabaseExport.h"

#include "CodeFwdHeaderFileGenerationImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"

Database::CodeFwdHeaderFileGenerationImpl::CodeFwdHeaderFileGenerationImpl(String fileName, CodeEntityAnalysis codeEntityAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : fileName{ std::move(fileName) },
      codeEntityAnalysis{ std::move(codeEntityAnalysis) },
      codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeFwdHeaderFileGenerationImpl)

System::String Database::CodeFwdHeaderFileGenerationImpl::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CoreTools::IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    auto content = streamManager.GetFileContent();

    const auto copyright = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright"));

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Copyright$"), copyright);

    const auto namespaceName = codeEntityAnalysis.GetNamespaceName();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Namespace$"), namespaceName);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$NamespaceUppercaseSeparator$"), CoreTools::StringUtility::ToUpperMacro(namespaceName));

    const auto classDeclaration = codeMappingAnalysis.GetElement(SYSTEM_TEXT("ClassDeclaration"));

    String classDeclarationContent{};
    for (const auto& element : codeEntityAnalysis)
    {
        auto copyClassDeclaration = classDeclaration;
        boost::algorithm::replace_all(copyClassDeclaration, SYSTEM_TEXT("$Class$"), element.GetEntityClassName());

        classDeclarationContent += copyClassDeclaration;
        classDeclarationContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassDeclaration$"), classDeclarationContent);

    return content;
}
