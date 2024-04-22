/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 09:24)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCSVImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Detail/FileNameParsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::BatchConversionCSVImpl::BatchConversionCSVImpl(String nativeFileName, String outputDirectory)
    : nativeFileName{ std::move(nativeFileName) }, outputDirectory{ std::move(outputDirectory) }
{
    ExecutionFile();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCSVImpl)

void CoreTools::BatchConversionCSVImpl::ExecutionFile() const
{
    if (const auto outputFile = GetOutputFile();
        !outputFile.empty())
    {
        const ExcelConversionCSV excelConversionCSV{ StringConversion::StandardConversionMultiByte(nativeFileName), outputFile, false };
    }
}

System::String CoreTools::BatchConversionCSVImpl::GetOutputFile() const
{
    if (nativeFileName.find(TextParsing::gXlsxExtension) != nativeFileName.size() - TextParsing::gXlsxExtension.size())
    {
        return String{};
    }

    const FileNameParsing fileNameParsing{ nativeFileName };

    auto output = fileNameParsing.GetWithSlashFileName();

    boost::algorithm::replace_last(output, TextParsing::gXlsxExtension, TextParsing::gCsvExtension);

    return outputDirectory + output;
}
