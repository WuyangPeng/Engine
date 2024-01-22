/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:53)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCSV.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/BatchConversionCSVImpl.h"

#include <filesystem>

CoreTools::BatchConversionCSV::BatchConversionCSV(const String& inputDirectory, const String& outputDirectory)
{
    Execution(inputDirectory, outputDirectory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCSV)

void CoreTools::BatchConversionCSV::Execution(const String& inputDirectory, const String& outputDirectory)
{
    for (const std::filesystem::path path{ StringConversion::StandardConversionWideChar(inputDirectory) };
         const auto& inputPath : std::filesystem::directory_iterator(path))
    {
#ifdef SYSTEM_PLATFORM_LINUX

        const auto& nativeFileName = StringConversion::MultiByteConversionStandard(inputPath.path().native());

#else  // !SYSTEM_PLATFORM_LINUX

        const auto& nativeFileName = StringConversion::WideCharConversionStandard(inputPath.path().native());

#endif  // SYSTEM_PLATFORM_LINUX

        const BatchConversionCSVImpl impl{ nativeFileName, outputDirectory };
    }
}
