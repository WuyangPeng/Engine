///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:52)

#include "Database/DatabaseExport.h"

#include "CodeHeaderFileGenerationImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"

Database::CodeHeaderFileGenerationImpl::CodeHeaderFileGenerationImpl(String fileName, CodeEntityAnalysis codeEntityAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : fileName{ std::move(fileName) },
      codeEntityAnalysis{ std::move(codeEntityAnalysis) },
      codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeHeaderFileGenerationImpl)

System::String Database::CodeHeaderFileGenerationImpl::GetContent() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CoreTools::IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    auto content = streamManager.GetFileContent();

    const auto copyright = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright"));

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Copyright$"), copyright);

    const auto namespaceName = codeEntityAnalysis.GetNamespaceName();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$NamespaceUppercaseSeparator$"), CoreTools::StringUtility::ToUpperMacro(namespaceName));

    const auto includeClass = codeMappingAnalysis.GetElement(SYSTEM_TEXT("IncludeClass"));

    String includeClassContent{};
    for (const auto& element : codeEntityAnalysis)
    {
        auto copyIncludeClass = includeClass;
        boost::algorithm::replace_all(copyIncludeClass, SYSTEM_TEXT("$Class$"), element.GetEntityClassName());

        includeClassContent += copyIncludeClass;
        includeClassContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$IncludeClass$"), includeClassContent);

    return content;
}
