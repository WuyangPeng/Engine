///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 15:42)

#include "GenerateTesting.h"
#include "CoreTools/FileManager/IFStreamManager.h"
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
        if (element.is_directory())
        {
            ResultTest(element.path());
        }
        else if (element.is_regular_file())
        {
            RegularFileTest(element.path());
        }
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

    const CoreTools::IFStreamManager streamManager{ fileName };

    const auto content = streamManager.GetFileContent();

    ASSERT_EQUAL(content.find(dollar), String::npos);
}

AssistTools::GenerateTesting::String AssistTools::GenerateTesting::GetOutput() const
{
    return output;
}
