///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 09:19)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

#include <map>
#include <set>

using namespace std::literals;

CoreTools::JsonTotalGenerateImpl::JsonTotalGenerateImpl(String nameSpace, JsonHeadContainer jsonHeadContainer) noexcept
    : nameSpace{ std::move(nameSpace) }, jsonHeadContainer{ std::move(jsonHeadContainer) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonTotalGenerateImpl)

void CoreTools::JsonTotalGenerateImpl::GenerateFile(const String& directory) const
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

System::String CoreTools::JsonTotalGenerateImpl::GetOldContent(const String& fileName)
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return TextParsing::gNewline.data();
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + nameSpace + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + GetFileSuffix());

    String content{ TextParsing::gEndif };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    DataType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName(), value);
    }

    auto content = GenerateDataHead(dataType);

    content += TextParsing::gIncludePrefix;
    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gHeadFileSuffix;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateEnumHead(const EnumType& enumType)
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateDataHead(const DataType& dataType)
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::gIncludePrefix;
        content += value.first;
        content += TextParsing::gHeadDetailFileSuffix;
    }

    if (!dataType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateFwdHead()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gTextParsingFwd };

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerHead() const
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIncludePrefix };

    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gHeadFileSuffix;
    content += TextParsing::gNewlineCharacter;

    EnumType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIncludePrefix;
        content += value;
        content += TextParsing::gHeadFileSuffix;
    }

    content += TextParsing::gStringConversion;
    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gIncludeJsonRow;
    content += TextParsing::gIncludeJsonHead;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gFilesystemInclude;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gUsingNamespaceLiterals;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gNamespace };

    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateEnumFwd(const EnumType& enumType)
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateInnerNameSpaceBegin(const JsonHead& jsonHead) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIndentation };

    content += TextParsing::gNamespace;
    content += TextParsing::gSpace;

    content += jsonHead.GetJsonClassName();
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateInnerNameSpaceEnd() const
{
    String content{ TextParsing::gIndentation };

    content += TextParsing::gFunctionEndBrackets;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateDataFwd(const DataType& dataType) const
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gClass;
        content += TextParsing::gSpace;
        content += value.first;
        content += TextParsing::gContainer;
        content += TextParsing::gSemicolonNewline;

        if (value.second.HasNested())
        {
            content += TextParsing::gNewlineCharacter;

            content += GenerateInnerNameSpaceBegin(value.second);

            ClassNameType classNameType{};

            for (const auto& innerValue : value.second)
            {
                if (innerValue->GetJsonDataType() == JsonDataType::Nested || innerValue->GetJsonDataType() == JsonDataType::NestedArray)
                {
                    const auto className = GetClassNameType(*innerValue);
                    classNameType.insert(className.begin(), className.end());
                }
            }

            for (const auto& name : classNameType)
            {
                if (name.empty())
                    continue;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gClass;
                content += TextParsing::gSpace;
                content += name;
                content += TextParsing::gSemicolonNewline;
            }

            content += GenerateInnerNameSpaceEnd();
        }

        content += TextParsing::gNewlineCharacter;
    }

    if (!dataType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

CoreTools::JsonTotalGenerateImpl::ClassNameType CoreTools::JsonTotalGenerateImpl::GetClassNameType(const JsonNode& jsonNode)
{
    ClassNameType result{};

    result.emplace(StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName()));

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        if (value->GetJsonDataType() == JsonDataType::Nested || value->GetJsonDataType() == JsonDataType::NestedArray)
        {
            const auto className = GetClassNameType(*value);
            result.insert(className.begin(), className.end());
        }
    }

    return result;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateFwd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    DataType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName(), value);
    }

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

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerClassName() const
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerDefaultFunction() const
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{};

    EnumType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
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
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSpace;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
        content += TextParsing::gSemicolonNewline;
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

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{};

    EnumType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
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
        content += TextParsing::gLeftBrackets;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gSpace;
        content += TextParsing::gSmallConst;
        content += TextParsing::gSpace;
        content += TextParsing::gNoexcept;
        content += TextParsing::gNewline;

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

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerDefaultFunctionDefinition(const String& className, const EnumType& dataType) const
{
    String content{};

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

        content += TextParsing::gClassNameEqual;
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
        content += TextParsing::gJsonRow;
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
    content += TextParsing::gNewline;

    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gVerify;
    content += TextParsing::gBrackets;
    content += TextParsing::gSmallConst;
    content += TextParsing::gNewline;
    content += TextParsing::gFunctionBeginBrackets;

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIfNot;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;
        content += TextParsing::gRightBrackets;
        content += TextParsing::gNewline;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionBeginBrackets;

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gThrowException;
        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gNotExistent;

        content += TextParsing::gIndentation;
        content += TextParsing::gFunctionEndBrackets;

        content += TextParsing::gNewline;
    }

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gOpenClassInvariant;
    content += TextParsing::gNewline;

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

    auto index = 0;
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
            content += TextParsing::gNewline;
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
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReturnFalse;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionEndBrackets;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewline;
    content += TextParsing::gOpenClassInvariantEndif;
    content += TextParsing::gNewline;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    auto content = nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gStringDirectory;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gColon;
    content += TextParsing::gSpace;

    EnumType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    auto index = 0;
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

        content += TextParsing::gNewline;

        ++index;
    }

    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gParsingDirectoryCall;

    content += TextParsing::gIndentation;
    content += TextParsing::gVerify;
    content += TextParsing::gLeftBrackets;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gUserSelfClassIsValid1;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewline;

    content += TextParsing::gVoid;
    content += TextParsing::gSpace;
    content += nameSpace;
    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += TextParsing::gParsing;
    content += TextParsing::gStringDirectory;
    content += TextParsing::gNewline;

    content += TextParsing::gFunctionBeginBrackets;
    content += TextParsing::gIndentation;
    content += TextParsing::gFilesystemPath;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gDirectoryIterator;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gPathNative;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("if (fileName.find(SYSTEM_TEXT(\".json\"s)) != (fileName.size() - 5))\n"s);

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
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gJsonRowBasicTree;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gReadJson;
    content += TextParsing::gNewline;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gJsonRowConstruction;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gJsonHeadConstruction;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gGetJsonClassName;
    content += TextParsing::gNewline;

    content += GenerateContainerDefaultFunctionDefinition(className, dataType);

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };
    content += TextParsing::gPrivate;

    EnumType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
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
    content += TextParsing::gNewline;

    return content;
}
