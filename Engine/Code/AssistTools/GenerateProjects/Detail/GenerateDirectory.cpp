/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:59)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateDirectory.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::GenerateDirectory::GenerateDirectory(String input, String output) noexcept
    : input{ std::move(input) }, output{ std::move(output) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateDirectory)

System::String AssistTools::GenerateDirectory::GetInputDirectory() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return input;
}

System::String AssistTools::GenerateDirectory::GetOutputDirectory() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return output;
}

AssistTools::GenerateDirectory AssistTools::GenerateDirectory::GetGenerateDirectory(const StringView& pathRoute) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return GenerateDirectory{ input + slash.data() + pathRoute.data(), output + slash.data() + pathRoute.data() };
}

AssistTools::GenerateDirectory AssistTools::GenerateDirectory::GetGenerateDirectory(const StringView& inputPathRoute, const StringView& outputPathRoute) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return GenerateDirectory{ input + slash.data() + inputPathRoute.data(), output + slash.data() + outputPathRoute.data() };
}

AssistTools::GenerateDirectory AssistTools::GenerateDirectory::GetGenerateDirectory(const StringView& inputPathRoute, const String& outputPathRoute) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return GenerateDirectory{ input + slash.data() + inputPathRoute.data(), output + slash.data() + outputPathRoute };
}

void AssistTools::GenerateDirectory::CreateFileDirectory() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    System::CreateFileDirectory(output);
}

void AssistTools::GenerateDirectory::AddOutputPathRoute(const StringView& outputPathRoute)
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    output += slash.data();
    output += outputPathRoute;
}
