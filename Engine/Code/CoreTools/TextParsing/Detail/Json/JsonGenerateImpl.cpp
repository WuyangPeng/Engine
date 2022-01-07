///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:44)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"

using std::vector;
using namespace std::literals;

CoreTools::JsonGenerateImpl::JsonGenerateImpl(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
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

System::String CoreTools::JsonGenerateImpl::GetOldContent(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        IFStreamManager iFStreamManager{ fileName };

        iFStreamManager.SetSimplifiedChinese();

        return iFStreamManager.GetFileContent();
    }
    catch (const CoreTools::Error&)
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

System::String CoreTools::JsonGenerateImpl::GenerateCopyright() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("/// Copyright (c) 2010-\n"s);

    content += SYSTEM_TEXT("/// Threading Core Render Engine\n"s);
    content += SYSTEM_TEXT("///\n"s);
    content += SYSTEM_TEXT("/// 作者：彭武阳，彭晔恩，彭晔泽\n"s);
    content += SYSTEM_TEXT("/// 联系作者：94458936@qq.com\n"s);
    content += SYSTEM_TEXT("///\n"s);
    content += SYSTEM_TEXT("/// 标准：std:c++17\n"s);
    content += SYSTEM_TEXT("/// 自动生成\n"s);

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(jsonHead.GetNameSpace() + GetJsonClassName() + GetFileSuffix());

    auto content = SYSTEM_TEXT("#ifndef "s);
    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("#define "s);
    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("namespace "s);

    content += jsonHead.GetNameSpace();
    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_FunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateInnerNameSpaceBegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_Indentation };

    content += SYSTEM_TEXT("namespace "s);

    content += jsonHead.GetJsonClassName();
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_FunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateInnerNameSpaceEnd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_Indentation };

    content += TextParsing::g_FunctionEndBrackets;

    return content;
}

System::String CoreTools::JsonGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(jsonHead.GetNameSpace() + GetJsonClassName() + GetFileSuffix());

    auto content = SYSTEM_TEXT("#endif  // "s);
    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    return content;
}
