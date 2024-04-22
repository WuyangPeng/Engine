/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 09:23)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerSourceFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateContainerSourceFile::CSVTotalGenerateContainerSourceFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ nameSpace, csvHeadContainer, codeMappingAnalysis },
      templateName{ SYSTEM_TEXT("/EngineeringContainerCpp.txt") },
      containerInclude{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ContainerInclude")) },
      containerMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ContainerMember")) },
      beginContainerMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BeginContainerMember")) },
      endContainerMember{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndContainerMember")) },
      elseSetContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ElseSetContainer")) },
      setContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("SetContainer")) },
      verifyContainer{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("VerifyContainer")) },
      getContainerDefine{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("GetContainerDefine")) },
      containerNotEqualNullptr{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("ContainerNotEqualNullptr")) },
      beginContainerNotEqualNullptr{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("BeginContainerNotEqualNullptr")) },
      endContainerNotEqualNullptr{ codeMappingAnalysis.GetElement(SYSTEM_TEXT("EndContainerNotEqualNullptr")) }
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
    auto content = GetTemplateContent(codeDirectory + templateName);

    const auto dataType = GetDataType();

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerInclude$"), GetContainerIncludeContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerMember$"), GetContainerMemberContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SetContainer$"), GetSetContainerContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$VerifyContainer$"), GetVerifyContainerContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ContainerNotEqualNullptr$"), GetContainerNotEqualNullptrContent(dataType));
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$GetContainerDefine$"), GetContainerDefineContent(dataType));

    return ReplaceTemplate(content);
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerIncludeContent(const ContainerType& dataType) const
{
    String content{};
    for (const auto& element : dataType)
    {
        content += ReplaceClassName(containerInclude, element);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerMemberContent(const ContainerType& dataType) const
{
    String content{};

    auto index = 0;
    for (const auto& element : dataType)
    {
        content += GetContainerMemberContent(index, boost::numeric_cast<int>(dataType.size()), element);

        ++index;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerMemberContent(int index, int size, const String& element) const
{
    auto content = index == 0 ? beginContainerMember : (index == size - 1 ? endContainerMember : containerMember);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

    return content + TextParsing::gNewlineCharacter;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetSetContainerContent(const ContainerType& dataType) const
{
    String content{};
    auto index = 0;
    for (const auto& element : dataType)
    {
        content += GetSetContainerContent(index, element);

        ++index;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetSetContainerContent(int index, const String& element) const
{
    auto content = index == 0 ? setContainer : elseSetContainer;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassName$"), element);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

    return content + TextParsing::gNewlineCharacter;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetVerifyContainerContent(const ContainerType& dataType) const
{
    String content{};
    for (const auto& element : dataType)
    {
        content += GetVerifyContainerContent(element);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetVerifyContainerContent(const String& element) const
{
    auto content = verifyContainer;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

    return content + TextParsing::gNewlineCharacter;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerNotEqualNullptrContent(const ContainerType& dataType) const
{
    String content{};
    auto index = 0;

    for (const auto& element : dataType)
    {
        content += GetContainerNotEqualNullptrContent(index, boost::numeric_cast<int>(dataType.size()), element);

        ++index;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerNotEqualNullptrContent(int index, int size, const String& element) const
{
    auto content = index == 0 ? beginContainerNotEqualNullptr : (index == size - 1 ? endContainerNotEqualNullptr : containerNotEqualNullptr);

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

    if (index != size - 1)
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerDefineContent(const ContainerType& dataType) const
{
    String content{};

    for (const auto& element : dataType)
    {
        content += GetContainerDefineContent(element);
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContainerDefineContent(const String& element) const
{
    auto content = getContainerDefine;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ClassName$"), element);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$SmallClassName$"), StringUtility::ToFirstLetterLower(element));

    return content + TextParsing::gNewlineCharacter;
}