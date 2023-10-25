///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:26)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateContainerSourceFile::CSVTotalGenerateContainerSourceFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateContainerSourceFile)

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetFileSuffix() const
{
    return TextParsing::gContainerSourceFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContent(const String& codeDirectory) const
{
    auto content = GetTemplateContent(codeDirectory + SYSTEM_TEXT("/EngineeringContainerCpp.txt"));

    EnumType dataType{};

    for (const auto& element : GetCSVHeadContainer())
    {
        if (element.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(element.GetCSVClassName());
        }
    }

    const auto codeMapping = GetCodeMappingAnalysis();
    const auto containerInclude = codeMapping.GetElement(SYSTEM_TEXT("ContainerInclude"));

    String containerIncludeContent{};
    for (const auto& element : dataType)
    {
        auto copyContainerInclude = containerInclude;

        boost::algorithm::replace_all(copyContainerInclude, SYSTEM_TEXT("$ClassName$"), element);

        containerIncludeContent += copyContainerInclude;
        containerIncludeContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerInclude$"), containerIncludeContent);

    const auto containerMember = codeMapping.GetElement(SYSTEM_TEXT("ContainerMember"));

    String containerMemberContent{};
    auto containerMemberIndex = 0;
    for (const auto& element : dataType)
    {
        auto copyContainerMember = containerMember;

        if (containerMemberIndex == 0)
        {
            copyContainerMember = codeMapping.GetElement(SYSTEM_TEXT("BeginContainerMember"));
        }
        else if (containerMemberIndex == boost::numeric_cast<int>(dataType.size() - 1))
        {
            copyContainerMember = codeMapping.GetElement(SYSTEM_TEXT("EndContainerMember"));
        }

        boost::algorithm::replace_all(copyContainerMember, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

        containerMemberContent += copyContainerMember;
        containerMemberContent += SYSTEM_TEXT("\n");

        ++containerMemberIndex;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerMember$"), containerMemberContent);

    const auto setContainer = codeMapping.GetElement(SYSTEM_TEXT("ElseSetContainer"));

    String setContainerContent{};
    auto setContainerIndex = 0;
    for (const auto& element : dataType)
    {
        auto copySetContainer = setContainer;

        if (setContainerIndex == 0)
        {
            copySetContainer = codeMapping.GetElement(SYSTEM_TEXT("SetContainer"));
        }

        boost::algorithm::replace_all(copySetContainer, SYSTEM_TEXT("$ClassName$"), element);
        boost::algorithm::replace_all(copySetContainer, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

        setContainerContent += copySetContainer;
        setContainerContent += SYSTEM_TEXT("\n");

        ++setContainerIndex;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SetContainer$"), setContainerContent);

    const auto verifyContainer = codeMapping.GetElement(SYSTEM_TEXT("VerifyContainer"));

    String verifyContainerContent{};
    for (const auto& element : dataType)
    {
        auto copyVerifyContainer = verifyContainer;

        boost::algorithm::replace_all(copyVerifyContainer, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

        verifyContainerContent += copyVerifyContainer;
        verifyContainerContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$VerifyContainer$"), verifyContainerContent);

    const auto containerNotEqualNullptr = codeMapping.GetElement(SYSTEM_TEXT("ContainerNotEqualNullptr"));

    String containerNotEqualNullptrContent{};
    auto containerNotEqualNullptrIndex = 0;
    for (const auto& element : dataType)
    {
        auto copyContainerNotEqualNullptr = containerNotEqualNullptr;

        if (containerNotEqualNullptrIndex == 0)
        {
            copyContainerNotEqualNullptr = codeMapping.GetElement(SYSTEM_TEXT("BeginContainerNotEqualNullptr"));
        }
        else if (containerNotEqualNullptrIndex == boost::numeric_cast<int>(dataType.size() - 1))
        {
            copyContainerNotEqualNullptr = codeMapping.GetElement(SYSTEM_TEXT("EndContainerNotEqualNullptr"));
        }

        boost::algorithm::replace_all(copyContainerNotEqualNullptr, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

        containerNotEqualNullptrContent += copyContainerNotEqualNullptr;
        if (containerNotEqualNullptrIndex != boost::numeric_cast<int>(dataType.size() - 1))
        {
            containerNotEqualNullptrContent += SYSTEM_TEXT("\n");
        }

        ++containerNotEqualNullptrIndex;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerNotEqualNullptr$"), containerNotEqualNullptrContent);

    const auto getContainerDefine = codeMapping.GetElement(SYSTEM_TEXT("GetContainerDefine"));

    String getContainerDefineContent{};
    for (const auto& element : dataType)
    {
        auto copyGetContainerDefine = getContainerDefine;

        boost::algorithm::replace_all(copyGetContainerDefine, SYSTEM_TEXT("$ClassName$"), element);
        boost::algorithm::replace_all(copyGetContainerDefine, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

        getContainerDefineContent += copyGetContainerDefine;
        getContainerDefineContent += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerDefine$"), getContainerDefineContent);

    return ReplaceTemplate(content);
}
