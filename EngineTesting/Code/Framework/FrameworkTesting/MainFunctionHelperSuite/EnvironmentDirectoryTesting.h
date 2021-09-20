// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/29 11:32)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <map>

namespace Framework
{
	enum class Description;

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
		void DoRunUnitTest() final;

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
		System::String GetDescription(Description description, bool isFile = false) const;
		System::String GetPrefix(Description description) const;
		static bool IsDirectory(Description description) noexcept;
		static bool IsRendering(Description description) noexcept;
		static bool IsLittleEndian(Description description) noexcept;

	private:
		DescriptionType m_Description;
		TestingType m_DefaultEnvironmentDirectory;
		TestingType m_FileEnvironmentDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ENVIRONMENT_DIRECTORY_TESTING_H