/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/08 22:38)

#include "EnvironmentDirectoryTesting.h"
#include "System/DynamicLink/LibraryTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using System::operator++;

namespace
{
    constexpr auto separate = SYSTEM_TEXT("/");
}

Framework::EnvironmentDirectoryTesting::EnvironmentDirectoryTesting(const OStreamShared& stream, const String& engineDirectory, bool isFile)
    : ParentType{ stream },
      descriptionType{ { Description::Resource, SYSTEM_TEXT("Resource") },
                       { Description::Configuration, SYSTEM_TEXT("Configuration") },
                       { Description::Directory, SYSTEM_TEXT("") },
                       { Description::LittleEndian, SYSTEM_TEXT("LittleEndian") },
                       { Description::BigEndian, SYSTEM_TEXT("BigEndian") },
                       { Description::Shader, SYSTEM_TEXT("Shader") },
                       { Description::Scene, SYSTEM_TEXT("Scene") },
                       { Description::Texture, SYSTEM_TEXT("Texture") },
                       { Description::Vertex, SYSTEM_TEXT("Vertex") },
                       { Description::Image, SYSTEM_TEXT("Image") },
                       { Description::Default, SYSTEM_TEXT("Default") },
                       { Description::OpenGL, SYSTEM_TEXT("OpenGL") },
                       { Description::DirectX, SYSTEM_TEXT("DirectX") },
                       { Description::Null, SYSTEM_TEXT("") },
                       { Description::Framework, SYSTEM_TEXT("Framework") },
                       { Description::EngineEnvironment, SYSTEM_TEXT("EngineTestingInclude") } },
      environmentDirectory{ GetDescription(Description::EngineEnvironment), engineDirectory },
      isFile{ isFile }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EnvironmentDirectoryTesting)

void Framework::EnvironmentDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::EnvironmentDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecutableConfigurationDirectoryTest);
}

void Framework::EnvironmentDirectoryTesting::ValueTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EngineEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EngineDirectoryTest);

    for (auto upperDirectory = UpperDirectory::Resource; upperDirectory <= UpperDirectory::Configuration; ++upperDirectory)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DirectoryTest, upperDirectory);
    }

    for (auto renderingAnalysisDirectory = RenderingAnalysisDirectory::Directory; renderingAnalysisDirectory <= RenderingAnalysisDirectory::Image; ++renderingAnalysisDirectory)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DefaultPathTest, renderingAnalysisDirectory);
        ASSERT_NOT_THROW_EXCEPTION_1(LittleEndianDefaultTest, renderingAnalysisDirectory);
        ASSERT_NOT_THROW_EXCEPTION_1(LittleEndianOpenGLTest, renderingAnalysisDirectory);
        ASSERT_NOT_THROW_EXCEPTION_1(LittleEndianDirectXTest, renderingAnalysisDirectory);
        ASSERT_NOT_THROW_EXCEPTION_1(BigEndianDefaultTest, renderingAnalysisDirectory);
        ASSERT_NOT_THROW_EXCEPTION_1(BigEndianOpenGLTest, renderingAnalysisDirectory);
        ASSERT_NOT_THROW_EXCEPTION_1(BigEndianDirectXTest, renderingAnalysisDirectory);
    }
}

void Framework::EnvironmentDirectoryTesting::EngineEnvironmentTest()
{
    ASSERT_EQUAL(GetDescription(Description::EngineEnvironment), environmentDirectory.GetEngineEnvironment());
}

void Framework::EnvironmentDirectoryTesting::EngineDirectoryTest()
{
    const auto engineDirectory = environmentDirectory.GetEngineDirectory();

    ASSERT_FALSE(engineDirectory.empty());
}

void Framework::EnvironmentDirectoryTesting::DirectoryTest(UpperDirectory upperDirectory)
{
    const auto directory = environmentDirectory.GetDirectory(upperDirectory);
    const auto description = GetDescription(System::EnumCastUnderlying<Description>(upperDirectory), isFile);
    const auto engineDirectory = environmentDirectory.GetEngineDirectory();

    ASSERT_EQUAL(directory, engineDirectory + description + separate);
}

void Framework::EnvironmentDirectoryTesting::DefaultPathTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    const auto path0 = environmentDirectory.GetPath(renderingAnalysisDirectory);
    const auto path1 = environmentDirectory.GetPath(RenderingDirectory::Default, renderingAnalysisDirectory);
    const auto path2 = environmentDirectory.GetPath(EndianDirectory::LittleEndian, RenderingDirectory::Default, renderingAnalysisDirectory);

    ASSERT_THREE_EQUAL(path0, path1, path2);
}

void Framework::EnvironmentDirectoryTesting::LittleEndianDefaultTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(renderingAnalysisDirectory, EndianDirectory::LittleEndian, RenderingDirectory::Default);
}

void Framework::EnvironmentDirectoryTesting::LittleEndianOpenGLTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(renderingAnalysisDirectory, EndianDirectory::LittleEndian, RenderingDirectory::OpenGL);
}

void Framework::EnvironmentDirectoryTesting::LittleEndianDirectXTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(renderingAnalysisDirectory, EndianDirectory::LittleEndian, RenderingDirectory::DirectX);
}

void Framework::EnvironmentDirectoryTesting::BigEndianDefaultTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(renderingAnalysisDirectory, EndianDirectory::BigEndian, RenderingDirectory::Default);
}

void Framework::EnvironmentDirectoryTesting::BigEndianOpenGLTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(renderingAnalysisDirectory, EndianDirectory::BigEndian, RenderingDirectory::OpenGL);
}

void Framework::EnvironmentDirectoryTesting::BigEndianDirectXTest(RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(renderingAnalysisDirectory, EndianDirectory::BigEndian, RenderingDirectory::DirectX);
}

void Framework::EnvironmentDirectoryTesting::PathTest(RenderingAnalysisDirectory renderingAnalysisDirectory, EndianDirectory endianDirectory, RenderingDirectory renderingDirectory)
{
    const auto path = environmentDirectory.GetPath(endianDirectory, renderingDirectory, renderingAnalysisDirectory);
    const auto directory = environmentDirectory.GetDirectory(UpperDirectory::Resource);
    const auto renderingDescription = GetRenderingDescription(System::EnumCastUnderlying<Description>(renderingDirectory));
    const auto endianDescription = GetEndianDescription(System::EnumCastUnderlying<Description>(endianDirectory), System::EnumCastUnderlying<Description>(renderingDirectory));
    const auto analysisDescription = GetAnalysisDescription(System::EnumCastUnderlying<Description>(renderingAnalysisDirectory), System::EnumCastUnderlying<Description>(renderingDirectory));

    ASSERT_EQUAL(path, directory + renderingDescription + endianDescription + analysisDescription);
}

System::String Framework::EnvironmentDirectoryTesting::GetRenderingDescription(Description renderingDirectory) const
{
    auto renderingDescription = GetDescription(renderingDirectory, isFile);

    if (!renderingDescription.empty())
    {
        renderingDescription += separate;
    }

    return renderingDescription;
}

System::String Framework::EnvironmentDirectoryTesting::GetEndianDescription(Description endianDirectory, Description renderingDirectory) const
{
    auto endianDescription = GetDescription(endianDirectory, isFile);

    if (isFile)
    {
        endianDescription = GetPrefix(renderingDirectory) + endianDescription;
    }

    if (!endianDescription.empty())
    {
        endianDescription += separate;
    }

    return endianDescription;
}

System::String Framework::EnvironmentDirectoryTesting::GetAnalysisDescription(Description renderingAnalysisDirectory, Description renderingDirectory) const
{
    auto analysisDescription = GetDescription(renderingAnalysisDirectory, isFile);

    if (isFile && renderingAnalysisDirectory != Description::Directory)
    {
        analysisDescription = GetPrefix(renderingDirectory) + analysisDescription;
    }

    if (!analysisDescription.empty())
    {
        analysisDescription += separate;
    }

    return analysisDescription;
}

System::String Framework::EnvironmentDirectoryTesting::GetDescription(Description description, bool isDirectoryFile) const
{
    if ((IsRendering(description) || IsLittleEndian(description)) && !isDirectoryFile)
    {
        return GetDescription(Description::Null, false);
    }

    if (const auto iter = descriptionType.find(description);
        iter != descriptionType.cend())
    {
        const auto& element = iter->second;
        if (isDirectoryFile && IsDirectory(description))
        {
            return GetDescription(Description::Framework, false) + element;
        }

        return element;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到相关描述"s))
    }
}

System::String Framework::EnvironmentDirectoryTesting::GetPrefix(Description description) const
{
    if (const auto iter = descriptionType.find(description);
        iter != descriptionType.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到相关描述"s))
    }
}

bool Framework::EnvironmentDirectoryTesting::IsDirectory(Description description) noexcept
{
    if (description == Description::Resource || description == Description::Configuration || IsRendering(description))
        return true;
    else
        return false;
}

bool Framework::EnvironmentDirectoryTesting::IsRendering(Description description) noexcept
{
    if (description == Description::Default || description == Description::OpenGL || description == Description::DirectX)
        return true;
    else
        return false;
}

bool Framework::EnvironmentDirectoryTesting::IsLittleEndian(Description description) noexcept
{
    if (description == Description::LittleEndian)
        return true;
    else
        return false;
}

void Framework::EnvironmentDirectoryTesting::ExecutableConfigurationDirectoryTest()
{
    const auto executableConfigurationDirectory = environmentDirectory.GetExecutableConfigurationDirectory();

    const auto executableNameRemoveSuffix = CoreTools::StringConversion::MultiByteConversionStandard(System::GetExecutableNameRemoveSuffix()) + SYSTEM_TEXT("/");

    ASSERT_EQUAL(executableConfigurationDirectory, environmentDirectory.GetDirectory(UpperDirectory::Configuration) + executableNameRemoveSuffix);
}