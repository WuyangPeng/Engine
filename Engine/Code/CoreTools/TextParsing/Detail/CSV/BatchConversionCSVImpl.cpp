///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:12)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCSVImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Detail/FileNameParsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::BatchConversionCSVImpl::BatchConversionCSVImpl(const String& nativeFileName, const String& outputDirectory)
{
    ExecutionFile(nativeFileName, outputDirectory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCSVImpl)

void CoreTools::BatchConversionCSVImpl::ExecutionFile(const String& nativeFileName, const String& outputDirectory)
{
    const auto outputFile = GetOutputFile(nativeFileName, outputDirectory);
    if (!outputFile.empty())
    {
        ExcelConversionCSV excelConversionCSV{ StringConversion::StandardConversionMultiByte(nativeFileName), outputFile, false };
    }
}

System::String CoreTools::BatchConversionCSVImpl::GetOutputFile(const String& nativeFileName, const String& outputDirectory)
{
    if (nativeFileName.find(TextParsing::g_XlsxExtension) != nativeFileName.size() - TextParsing::g_XlsxExtension.size())
    {
        return String{};
    }

    FileNameParsing fileNameParsing{ nativeFileName };

    auto output = fileNameParsing.GetWithSlashFileName();

    boost::algorithm::replace_last(output, TextParsing::g_XlsxExtension, TextParsing::g_CsvExtension);

    return outputDirectory + output;
}
