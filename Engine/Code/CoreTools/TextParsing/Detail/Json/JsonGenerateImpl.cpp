///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:26)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"

CoreTools::JsonGenerateImpl::JsonGenerateImpl(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateImpl)

void CoreTools::JsonGenerateImpl::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvClassName = GetJsonClassName();
    const auto fileName = directory + GetFilePrefix() + csvClassName + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent();

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::JsonGenerateImpl::GetJsonClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return jsonHead.GetJsonClassName();
}

System::String CoreTools::JsonGenerateImpl::GetOldContent(const String& fileName)
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

CoreTools::JsonHead CoreTools::JsonGenerateImpl::GetJsonHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return jsonHead;
}

System::String CoreTools::JsonGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(jsonHead.GetNameSpace() + GetJsonClassName() + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gNamespace };

    content += TextParsing::gSpace;
    content += jsonHead.GetNameSpace();
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateInnerNameSpaceBegin() const
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

System::String CoreTools::JsonGenerateImpl::GenerateInnerNameSpaceEnd()
{
    String content{ TextParsing::gIndentation };

    content += TextParsing::gFunctionEndBrackets;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(jsonHead.GetNameSpace() + GetJsonClassName() + GetFileSuffix());

    String content{ TextParsing::gEndif };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    return content;
}
