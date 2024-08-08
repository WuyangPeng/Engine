/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/08 22:38)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/FrameworkTesting/MainFunctionHelperSuite/Flags/DescriptionFlags.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <map>

namespace Framework
{
    class EnvironmentDirectoryTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnvironmentDirectoryTesting;
        using ParentType = UnitTest;
        using TestingType = EnvironmentDirectory;

        using String = System::String;

    public:
        EnvironmentDirectoryTesting(const OStreamShared& stream, const String& engineDirectory, bool isFile);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void ValueTest();
        void EngineEnvironmentTest();
        void EngineDirectoryTest();
        void ExecutableConfigurationDirectoryTest();

        void DirectoryTest(UpperDirectory upperDirectory);
        void DefaultPathTest(RenderingAnalysisDirectory renderingAnalysisDirectory);
        void LittleEndianDefaultTest(RenderingAnalysisDirectory renderingAnalysisDirectory);
        void LittleEndianOpenGLTest(RenderingAnalysisDirectory renderingAnalysisDirectory);
        void LittleEndianDirectXTest(RenderingAnalysisDirectory renderingAnalysisDirectory);
        void BigEndianDefaultTest(RenderingAnalysisDirectory renderingAnalysisDirectory);
        void BigEndianOpenGLTest(RenderingAnalysisDirectory renderingAnalysisDirectory);
        void BigEndianDirectXTest(RenderingAnalysisDirectory renderingAnalysisDirectory);

        void PathTest(RenderingAnalysisDirectory renderingAnalysisDirectory, EndianDirectory endianDirectory, RenderingDirectory renderingDirectory);

    private:
        using DescriptionType = std::map<Description, String>;

    private:
        NODISCARD String GetDescription(Description description, bool isDirectoryFile = false) const;
        NODISCARD String GetRenderingDescription(Description renderingDirectory) const;
        NODISCARD String GetEndianDescription(Description endianDirectory, Description renderingDirectory) const;
        NODISCARD String GetAnalysisDescription(Description renderingAnalysisDirectory, Description renderingDirectory) const;
        NODISCARD String GetPrefix(Description description) const;
        NODISCARD static bool IsDirectory(Description description) noexcept;
        NODISCARD static bool IsRendering(Description description) noexcept;
        NODISCARD static bool IsLittleEndian(Description description) noexcept;

    private:
        DescriptionType descriptionType;
        TestingType environmentDirectory;
        bool isFile;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H