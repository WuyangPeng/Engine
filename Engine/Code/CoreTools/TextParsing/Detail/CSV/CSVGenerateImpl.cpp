///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:18)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateHead.h"
#include "CSVGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using std::set;
using std::vector;
using namespace std::literals;

CoreTools::CSVGenerateImpl::CSVGenerateImpl(const CSVHead& csvHead) noexcept
    : csvHead{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateImpl)

void CoreTools::CSVGenerateImpl::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvClassName = GetCSVClassName();
    const auto fileName = directory + GetFilePrefix() + csvClassName + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent();

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::CSVGenerateImpl::GenerateCopyright() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("/// Copyright (c) 2010-\n"s);

    content += SYSTEM_TEXT("/// Threading Core Render Engine\n"s);
    content += TextParsing::g_Annotation;
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("/// 作者：彭武阳，彭晔恩，彭晔泽\n"s);
    content += SYSTEM_TEXT("/// 联系作者：94458936@qq.com\n"s);
    content += TextParsing::g_Annotation;
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("/// 标准：std:c++17\n"s);
    content += SYSTEM_TEXT("/// 自动生成\n"s);

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(csvHead.GetNameSpace() + GetCSVClassName() + GetFileSuffix());

    String content{ TextParsing::g_Ifndef };

    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Define;
    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_Namespace };

    content += csvHead.GetNameSpace();
    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_FunctionBeginBrackets;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(csvHead.GetNameSpace() + GetCSVClassName() + GetFileSuffix());

    String content{ TextParsing::g_Endif };

    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GetKeyTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (csvHead.GetCSVFormatType() != CSVFormatType::Key)
    {
        if (csvHead.GetDataType(0) == CSVDataType::Int64)
        {
            return CSVTypeConversion::GetActualType(CSVDataType::Int64);
        }
    }
    else
    {
        const auto result = csvHead.GetKeyName();

        for (const auto& value : result)
        {
            if (csvHead.GetDataType(value) == CSVDataType::Int64)
            {
                return CSVTypeConversion::GetActualType(CSVDataType::Int64);
            }
        }
    }

    return CSVTypeConversion::GetActualType(CSVDataType::Int);
}

System::String CoreTools::CSVGenerateImpl::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetCSVClassName();
}

System::String CoreTools::CSVGenerateImpl::GetOldContent(const String& fileName) const
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

CoreTools::CSVFormatType CoreTools::CSVGenerateImpl::GetCSVFormatType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead.GetCSVFormatType();
}

CoreTools::CSVHead CoreTools::CSVGenerateImpl::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return csvHead;
}
