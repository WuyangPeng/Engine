///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:43)

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

System::String CoreTools::CSVGenerateImpl::GenerateCopyright()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("/// Copyright (c) 2010-\n"s);

    content += SYSTEM_TEXT("/// Threading Core Render Engine\n"s);
    content += TextParsing::gAnnotation;
    content += TextParsing::gNewlineCharacter;

    content += SYSTEM_TEXT("/// 作者：彭武阳，彭晔恩，彭晔泽\n"s);
    content += SYSTEM_TEXT("/// 联系作者：94458936@qq.com\n"s);
    content += TextParsing::gAnnotation;
    content += TextParsing::gNewlineCharacter;

    content += SYSTEM_TEXT("/// 标准：std:c++20\n"s);
    content += SYSTEM_TEXT("/// 自动生成\n"s);

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(csvHead.GetNameSpace() + GetCSVClassName() + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gNamespace };

    content += csvHead.GetNameSpace();
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::CSVGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(csvHead.GetNameSpace() + GetCSVClassName() + GetFileSuffix());

    String content{ TextParsing::gEndif };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

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
        for (const auto result = csvHead.GetKeyName(); const auto& value : result)
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

System::String CoreTools::CSVGenerateImpl::GetOldContent(const String& fileName)
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
