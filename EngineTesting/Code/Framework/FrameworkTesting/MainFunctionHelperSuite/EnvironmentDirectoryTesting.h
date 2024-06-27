/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/27 14:06)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H

#include "Flags/DescriptionFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <map>

namespace Framework
{
    class EnvironmentDirectoryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnvironmentDirectoryTesting;
        using ParentType = UnitTest;
        using TestingType = EnvironmentDirectory;

        using String = System::String;

    public:
        explicit EnvironmentDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void DefaultValueTest();
        void FileValueTest();

        void EngineEnvironmentTest(const TestingType& environmentDirectory);
        void EngineDirectoryTest(const TestingType& environmentDirectory);
        void DirectoryTest(bool isFile, UpperDirectory upperDirectory);
        void DefaultPathTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);
        void LittleEndianDefaultTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);
        void LittleEndianOpenGLTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);
        void LittleEndianDirectXTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);
        void BigEndianDefaultTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);
        void BigEndianOpenGLTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);
        void BigEndianDirectXTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory);

        void PathTest(bool isFile, RenderingAnalysisDirectory renderingAnalysisDirectory, EndianDirectory endianDirectory, RenderingDirectory renderingDirectory);

    private:
        using DescriptionType = std::map<Description, String>;

    private:
        NODISCARD System::String GetDescription(Description description, bool isFile = false) const;
        NODISCARD System::String GetPrefix(Description description) const;
        NODISCARD static bool IsDirectory(Description description) noexcept;
        NODISCARD static bool IsRendering(Description description) noexcept;
        NODISCARD static bool IsLittleEndian(Description description) noexcept;

    private:
        DescriptionType descriptionType;
        TestingType defaultEnvironmentDirectory;
        TestingType fileEnvironmentDirectory;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H