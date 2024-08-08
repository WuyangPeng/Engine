/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/07 10:42)

#include "EnvironmentDirectoryTesting.h"
#include "Flags/DescriptionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using System::operator++;
using namespace std::literals;

Framework::EnvironmentDirectoryTesting::EnvironmentDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream },
      descriptionType{ { Description::Resource, SYSTEM_TEXT("Resource"s) },
                       { Description::Configuration, SYSTEM_TEXT("Configuration"s) },
                       { Description::Directory, SYSTEM_TEXT(""s) },
                       { Description::LittleEndian, SYSTEM_TEXT("LittleEndian"s) },
                       { Description::BigEndian, SYSTEM_TEXT("BigEndian"s) },
                       { Description::Shader, SYSTEM_TEXT("Shader"s) },
                       { Description::Scene, SYSTEM_TEXT("Scene"s) },
                       { Description::Texture, SYSTEM_TEXT("Texture"s) },
                       { Description::Vertex, SYSTEM_TEXT("Vertex"s) },
                       { Description::Image, SYSTEM_TEXT("Image"s) },
                       { Description::Default, SYSTEM_TEXT("Default"s) },
                       { Description::OpenGL, SYSTEM_TEXT("OpenGL"s) },
                       { Description::DirectX, SYSTEM_TEXT("DirectX"s) },
                       { Description::Null, SYSTEM_TEXT(""s) },
                       { Description::Framework, SYSTEM_TEXT("Framework"s) },
                       { Description::EngineEnvironment, SYSTEM_TEXT("EngineTestingInclude"s) } },
      defaultEnvironmentDirectory{ GetDescription(Description::EngineEnvironment), SYSTEM_TEXT("Default"s) },
      fileEnvironmentDirectory{ GetDescription(Description::EngineEnvironment), SYSTEM_TEXT("FrameworkEngineDirectory"s) }
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
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecutableConfigurationDirectoryTest);
}

void Framework::EnvironmentDirectoryTesting::DefaultValueTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(EngineEnvironmentTest, defaultEnvironmentDirectory);
    ASSERT_NOT_THROW_EXCEPTION_1(EngineDirectoryTest, defaultEnvironmentDirectory);

    for (auto i = UpperDirectory::Resource; i <= UpperDirectory::Configuration; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DirectoryTest, false, i);
    }

    for (auto i = RenderingAnalysisDirectory::Directory; i <= RenderingAnalysisDirectory::Image; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DefaultPathTest, false, i);
        ASSERT_NOT_THROW_EXCEPTION_2(LittleEndianDefaultTest, false, i);
        ASSERT_NOT_THROW_EXCEPTION_2(LittleEndianOpenGLTest, false, i);
        ASSERT_NOT_THROW_EXCEPTION_2(LittleEndianDirectXTest, false, i);
        ASSERT_NOT_THROW_EXCEPTION_2(BigEndianDefaultTest, false, i);
        ASSERT_NOT_THROW_EXCEPTION_2(BigEndianOpenGLTest, false, i);
        ASSERT_NOT_THROW_EXCEPTION_2(BigEndianDirectXTest, false, i);
    }
}

void Framework::EnvironmentDirectoryTesting::FileValueTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(EngineEnvironmentTest, fileEnvironmentDirectory);
    ASSERT_NOT_THROW_EXCEPTION_1(EngineDirectoryTest, fileEnvironmentDirectory);

    for (auto i = UpperDirectory::Resource; i <= UpperDirectory::Configuration; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DirectoryTest, true, i);
    }

    for (auto i = RenderingAnalysisDirectory::Directory; i <= RenderingAnalysisDirectory::Image; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DefaultPathTest, true, i);
        ASSERT_NOT_THROW_EXCEPTION_2(LittleEndianDefaultTest, true, i);
        ASSERT_NOT_THROW_EXCEPTION_2(LittleEndianOpenGLTest, true, i);
        ASSERT_NOT_THROW_EXCEPTION_2(LittleEndianDirectXTest, true, i);
        ASSERT_NOT_THROW_EXCEPTION_2(BigEndianDefaultTest, true, i);
        ASSERT_NOT_THROW_EXCEPTION_2(BigEndianOpenGLTest, true, i);
        ASSERT_NOT_THROW_EXCEPTION_2(BigEndianDirectXTest, true, i);
    }
}

void Framework::EnvironmentDirectoryTesting::EngineEnvironmentTest(const TestingType& environmentDirectory)
{
    ASSERT_EQUAL(GetDescription(Description::EngineEnvironment), environmentDirectory.GetEngineEnvironment());
}

void Framework::EnvironmentDirectoryTesting::EngineDirectoryTest(const TestingType& environmentDirectory)
{
    const auto engineDirectory = environmentDirectory.GetEngineDirectory();

    ASSERT_FALSE(engineDirectory.empty());
}

void Framework::EnvironmentDirectoryTesting::DirectoryTest(bool isFile, UpperDirectory upperDirectory)
{
    const auto& environmentDirectory = isFile ? fileEnvironmentDirectory : defaultEnvironmentDirectory;

    const auto directory = environmentDirectory.GetDirectory(upperDirectory);
    const auto description = GetDescription(System::EnumCastUnderlying<Description>(upperDirectory), isFile);

    const auto engineDirectory = environmentDirectory.GetEngineDirectory();

    ASSERT_EQUAL(directory, engineDirectory + description + SYSTEM_TEXT("/"s));
}

void Framework::EnvironmentDirectoryTesting::DefaultPathTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    const auto& environmentDirectory = isFile ? fileEnvironmentDirectory : defaultEnvironmentDirectory;

    const auto path0 = environmentDirectory.GetPath(renderingAnalysisDirectory);
    const auto path1 = environmentDirectory.GetPath(RenderingDirectory::Default, renderingAnalysisDirectory);
    const auto path2 = environmentDirectory.GetPath(EndianDirectory::LittleEndian, RenderingDirectory::Default, renderingAnalysisDirectory);

    ASSERT_EQUAL(path0, path1);
    ASSERT_EQUAL(path1, path2);
}

void Framework::EnvironmentDirectoryTesting::LittleEndianDefaultTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(isFile, renderingAnalysisDirectory, EndianDirectory::LittleEndian, RenderingDirectory::Default);
}

void Framework::EnvironmentDirectoryTesting::LittleEndianOpenGLTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(isFile, renderingAnalysisDirectory, EndianDirectory::LittleEndian, RenderingDirectory::OpenGL);
}

void Framework::EnvironmentDirectoryTesting::LittleEndianDirectXTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(isFile, renderingAnalysisDirectory, EndianDirectory::LittleEndian, RenderingDirectory::DirectX);
}

void Framework::EnvironmentDirectoryTesting::BigEndianDefaultTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(isFile, renderingAnalysisDirectory, EndianDirectory::BigEndian, RenderingDirectory::Default);
}

void Framework::EnvironmentDirectoryTesting::BigEndianOpenGLTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(isFile, renderingAnalysisDirectory, EndianDirectory::BigEndian, RenderingDirectory::OpenGL);
}

void Framework::EnvironmentDirectoryTesting::BigEndianDirectXTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory)
{
    PathTest(isFile, renderingAnalysisDirectory, EndianDirectory::BigEndian, RenderingDirectory::DirectX);
}

void Framework::EnvironmentDirectoryTesting::PathTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory, EndianDirectory endianDirectory, RenderingDirectory renderingDirectory)
{
    const auto& environmentDirectory = isFile ? fileEnvironmentDirectory : defaultEnvironmentDirectory;

    const auto path = environmentDirectory.GetPath(endianDirectory, renderingDirectory, renderingAnalysisDirectory);

    const auto directory = environmentDirectory.GetDirectory(UpperDirectory::Resource);

    auto renderingDescription = GetDescription(System::EnumCastUnderlying<Description>(renderingDirectory), isFile);
    if (!renderingDescription.empty())
    {
        renderingDescription += SYSTEM_TEXT("/"s);
    }

    auto endianDescription = GetDescription(System::EnumCastUnderlying<Description>(endianDirectory), isFile);
    if (isFile)
    {
        endianDescription = GetPrefix(System::EnumCastUnderlying<Description>(renderingDirectory)) + endianDescription;
    }
    if (!endianDescription.empty())
    {
        endianDescription += SYSTEM_TEXT("/"s);
    }

    auto analysisDescription = GetDescription(System::EnumCastUnderlying<Description>(renderingAnalysisDirectory), isFile);
    if (isFile && renderingAnalysisDirectory != RenderingAnalysisDirectory::Directory)
    {
        analysisDescription = GetPrefix(System::EnumCastUnderlying<Description>(renderingDirectory)) + analysisDescription;
    }
    if (!analysisDescription.empty())
    {
        analysisDescription += SYSTEM_TEXT("/"s);
    }

    ASSERT_EQUAL(path, directory + renderingDescription + endianDescription + analysisDescription);
}

System::String Framework::EnvironmentDirectoryTesting::GetDescription(Description description, bool isFile) const
{
    if ((IsRendering(description) || IsLittleEndian(description)) && !isFile)
    {
        return GetDescription(Description::Null, false);
    }

    if (const auto iter = descriptionType.find(description);
        iter != descriptionType.cend())
    {
        auto element = iter->second;
        if (isFile && IsDirectory(description))
        {
            element = GetDescription(Description::Framework, false) + element;
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
}