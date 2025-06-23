///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:42)

#include "GenerateTesting.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateEngine.h"
#include "AssistTools/GenerateProjects/Using/ProjectGenerationUsing.h"

#include <filesystem>

AssistTools::GenerateTesting::GenerateTesting(const OStreamShared& stream, String output)
    : ParentType{ stream }, output{ std::move(output) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTesting)

void AssistTools::GenerateTesting::ResultTest(const String& directory)
{
    for (const auto& element : std::filesystem::directory_iterator(directory))
    {
        #ifdef SYSTEM_PLATFORM_LINUX

        if (element.is_directory())
        {
            ResultTest(element.path());
        }
        else if (element.is_regular_file())
        {
            RegularFileTest(element.path());
        }

        #else // !SYSTEM_PLATFORM_LINUX

        if (element.is_directory())
        {
            ResultTest(CoreTools::StringConversion::WideCharConversionStandard(element.path()));
        }
        else if (element.is_regular_file())
        {
            RegularFileTest(CoreTools::StringConversion::WideCharConversionStandard(element.path()));
        }

        #endif // SYSTEM_PLATFORM_LINUX
    }
}

void AssistTools::GenerateTesting::RegularFileTest(const String& fileName)
{
    if (fileName.find(SYSTEM_TEXT("Doxyfile")) != String::npos ||
        fileName.find(SYSTEM_TEXT("vcxproj")) != String::npos ||
        fileName.find(SYSTEM_TEXT("props")) != String::npos)
    {
        return;
    }

    const CoreTools::IFileStreamManager streamManager{ fileName };

    const auto content = streamManager.GetFileContent();

    ASSERT_EQUAL(content.find(dollar), String::npos);
}

AssistTools::GenerateTesting::String AssistTools::GenerateTesting::GetOutput() const
{
    return output;
}
