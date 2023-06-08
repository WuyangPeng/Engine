///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/07 10:21)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <map>
#include <set>

CoreTools::CSVTotalGenerateImpl::CSVTotalGenerateImpl(String nameSpace, CSVHeadContainer csvHeadContainer) noexcept
    : nameSpace{ std::move(nameSpace) }, csvHeadContainer{ std::move(csvHeadContainer) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerateImpl)

void CoreTools::CSVTotalGenerateImpl::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto fileName = directory + TextParsing::gForwardSlash + nameSpace + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent();

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::CSVTotalGenerateImpl::GetOldContent(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        IFStreamManager iFStreamManager{ fileName };

        iFStreamManager.SetSimplifiedChinese();

        return iFStreamManager.GetFileContent();
    }
    catch (const Error&)
    {
        // 文件不存在是正常的。
        return String{};
    }
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return System::String{ TextParsing::gNewlineCharacter };
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIfndef };

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + GetFileSuffix());

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIfndef };

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + nameSpace + GetFileSuffix());

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gEndif };

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + GetFileSuffix());

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    EnumType enumType{};
    DataType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() == CSVFormatType::Enum)
        {
            enumType.emplace(value.GetCSVClassName());
        }
        else
        {
            dataType.emplace(value.GetCSVClassName(), value);
        }
    }

    auto content = GenerateEnumHead(enumType);
    content += GenerateDataHead(dataType);

    content += TextParsing::gIncludePrefix;
    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gHeadFileSuffix;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateEnumHead(const EnumType& enumType)
{
    String content{};

    for (const auto& value : enumType)
    {
        content += TextParsing::gIncludePrefix;
        content += TextParsing::gFlags;
        content += TextParsing::gForwardSlash;
        content += value;
        content += TextParsing::gHeadFileSuffix;
    }

    if (!enumType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateDataHead(const DataType& dataType)
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::gIncludePrefix;
        content += value.first;
        content += TextParsing::gHeadFileSuffix;

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += TextParsing::gIncludePrefix;
            content += value.first;
            content += TextParsing::gBase;
            content += TextParsing::gHeadFileSuffix;
        }

        if (value.second.GetCSVFormatType() == CSVFormatType::Unique)
        {
            content += TextParsing::gIncludePrefix;
            content += value.first;
            content += TextParsing::gContainer;
            content += TextParsing::gHeadFileSuffix;
        }
        else
        {
            content += TextParsing::gIncludePrefix;
            content += value.first;
            content += TextParsing::gContainer;
            content += TextParsing::gHeadDetailFileSuffix;
        }
    }

    if (!dataType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateFwdHead()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gTextParsingFwd };

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gCoreToolsHeadFile };

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIncludePrefix;
    content += nameSpace;
    content += TextParsing::gFwd;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUnicodeUsing;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gMemoryInclude;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIncludePrefix };

    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gHeadFileSuffix;
    content += TextParsing::gNewlineCharacter;

    EnumType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIncludePrefix;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gHeadFileSuffix;
    }

    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gIncludeCSVContent;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gFilesystemInclude;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gUsingNamespaceLiterals;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gNamespace };

    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateEnumFwd(const EnumType& enumType)
{
    String content{};

    for (const auto& value : enumType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gEnumClass;
        content += value;
        content += TextParsing::gSemicolonNewline;
    }

    if (!enumType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateDataFwd(const DataType& dataType)
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gClass;
        content += TextParsing::gSpace;
        content += value.first;
        content += TextParsing::gSemicolonNewline;

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gClass;
            content += TextParsing::gSpace;
            content += value.first;
            content += TextParsing::gBase;
            content += TextParsing::gSemicolonNewline;
        }

        content += TextParsing::gIndentation;
        content += TextParsing::gClass;
        content += TextParsing::gSpace;
        content += value.first;
        content += TextParsing::gContainer;
        content += TextParsing::gSemicolonNewline;

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gUsing;
            content += TextParsing::gSpace;
            content += value.first;
            content += TextParsing::gMappingType;
            content += TextParsing::gSpace;
            content += TextParsing::gEqualSign;
            content += TextParsing::gSpace;
            content += value.first;
            content += TextParsing::gBase;
            content += TextParsing::gSemicolonNewline;
        }
        else
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gUsing;
            content += TextParsing::gSpace;
            content += value.first;
            content += TextParsing::gMappingType;
            content += TextParsing::gSpace;
            content += TextParsing::gEqualSign;
            content += TextParsing::gSpace;
            content += value.first;
            content += TextParsing::gSemicolonNewline;
        }
    }

    if (!dataType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateFwd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    EnumType enumType{};
    DataType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() == CSVFormatType::Enum)
        {
            enumType.emplace(value.GetCSVClassName());
        }
        else
        {
            dataType.emplace(value.GetCSVClassName(), value);
        }
    }

    content += GenerateEnumFwd(enumType);
    content += GenerateDataFwd(dataType);

    content += TextParsing::gIndentation;
    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };

    content += TextParsing::gClass;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gSpace;
    content += TextParsing::gFinal;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassType;
    content += className;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };

    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gExplicit;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gDirectoryParameter;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassInvariantDeclare;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{};

    EnumType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gNodiscard;
        content += TextParsing::gSharedPtrConst;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gRightAngleBracket;
        content += TextParsing::gSpace;
        content += TextParsing::gGet;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gConstNoexcept;
    }

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += TextParsing::gPrivate;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += TextParsing::gParsing;
    content += TextParsing::gStringDirectory;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gVerifyConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{};

    EnumType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gSharedPtrConst;
        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gRightAngleBracket;
        content += TextParsing::gSpace;

        content += nameSpace;
        content += TextParsing::gDoubleColon;
        content += className;
        content += TextParsing::gDoubleColon;
        content += TextParsing::gGet;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gBrackets;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gUserClassIsValidConst1;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gReturn;
        content += TextParsing::gSpace;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;
        content += TextParsing::gSemicolonNewline;

        content += TextParsing::gFunctionEndBrackets;
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunctionMemberListDefinition(const EnumType& dataType) const
{
    auto index = 0;
    String content{};
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += TextParsing::gMemberIndentation;
        }

        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;
        content += TextParsing::gInit;

        if (index != boost::numeric_cast<int>(dataType.size()) - 1)
        {
            content += TextParsing::gComma;
        }

        content += TextParsing::gNewlineCharacter;

        ++index;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerParsingDefinition(const String& className, const EnumType& dataType) const
{
    String content{};

    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gParsing;
    content += TextParsing::gStringDirectory;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gFilesystemPath;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gDirectoryIterator;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gPathNative;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gFileNameFind;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gContinue;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gCSVContentInit;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gGetCSVClassName;
    content += TextParsing::gNewlineCharacter;

    auto firstData = true;
    for (const auto& value : dataType)
    {
        if (firstData)
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
        }
        else
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += TextParsing::gElse;
            content += TextParsing::gSpace;
        }
        content += TextParsing::gCsvClassNameEquation;
        content += value;
        content += TextParsing::gSystemTextEndNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;
        content += TextParsing::gSpace;
        content += TextParsing::gEqualSign;
        content += TextParsing::gSpace;
        content += TextParsing::gMakeShared;
        content += TextParsing::gLeftAngleBracket;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gRightAngleBracket;
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gCsvContent;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSemicolonNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        firstData = false;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerVerifyDefinition(const String& className, const EnumType& dataType) const
{
    String content{};

    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gVerify;
    content += TextParsing::gBrackets;
    content += TextParsing::gSmallConst;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIfNot;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gThrowException;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gNotExistent;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewlineCharacter;
    }

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerIsValidDefinition(const String& className, const EnumType& dataType) const
{
    String content{};

    content += TextParsing::gOpenClassInvariant;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gBool;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gIsValid;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIf;

    int index = 0;
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += TextParsing::gMemberIndentation;
            content += TextParsing::gSpace;
            content += TextParsing::gSpace;
        }

        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;

        if (index == boost::numeric_cast<int>(dataType.size()) - 1)
        {
            content += TextParsing::gRightBrackets;
            content += TextParsing::gNewlineCharacter;
        }
        else
        {
            content += TextParsing::gAndNewline;
        }

        ++index;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnTrue;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gElse;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnFalse;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gOpenClassInvariantEndif;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gDirectory;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gColon;
    content += TextParsing::gSpace;

    EnumType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    content += GenerateContainerDefaultFunctionMemberListDefinition(dataType);

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gParsingDirectoryCall;

    content += TextParsing::gIndentation;
    content += TextParsing::gVerify;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserSelfClassIsValid1;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    content += GenerateContainerParsingDefinition(className, dataType);

    content += GenerateContainerVerifyDefinition(className, dataType);

    content += GenerateContainerIsValidDefinition(className, dataType);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };
    content += TextParsing::gPrivate;

    EnumType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gSharedPtrConst;
        content += value;
        content += TextParsing::gContainer;
        content += TextParsing::gRightAngleBracket;
        content += TextParsing::gSpace;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;
        content += TextParsing::gSemicolonNewline;
    }

    content += TextParsing::gIndentation;
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}
