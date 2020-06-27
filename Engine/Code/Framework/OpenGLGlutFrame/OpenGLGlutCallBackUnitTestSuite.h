// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:58)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "OpenGLGlutProcess.h"
#include "OpenGLGlutCallBackInterface.h"
#include "CoreTools/Helper/ExportMacro.h" 
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h" 

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteStream);
FRAMEWORK_EXPORT_SHARED_PTR(OpenGLGlutCallBackUnitTestSuiteImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackUnitTestSuite : public OpenGLGlutCallBackInterface 
	{
	public:		
		using ClassType = OpenGLGlutCallBackUnitTestSuite;
		using ParentType = OpenGLGlutCallBackInterface;
		using ClassShareType = CoreTools::NonCopyClasses;
		using ImplType = OpenGLGlutCallBackUnitTestSuiteImpl;
		using StreamType = WindowMessageUnitTestSuiteStream;
		using Suite = CoreTools::Suite;
		using OStreamShared = CoreTools::OStreamShared;
		using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

	public:
		OpenGLGlutCallBackUnitTestSuite(int64_t delta, const std::string& suiteName);
		~OpenGLGlutCallBackUnitTestSuite() noexcept = default;
		OpenGLGlutCallBackUnitTestSuite(const OpenGLGlutCallBackUnitTestSuite&) noexcept = delete;
		OpenGLGlutCallBackUnitTestSuite& operator=(const OpenGLGlutCallBackUnitTestSuite&) noexcept = delete;
		OpenGLGlutCallBackUnitTestSuite(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept;
		OpenGLGlutCallBackUnitTestSuite& operator=(OpenGLGlutCallBackUnitTestSuite&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool Initialize() override;
		bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate) override;
		bool IdleFunction() override;
		int GetPassedNumber() const noexcept;

	protected:
		OStreamShared GetStreamShared() noexcept;
		void DoAddSuite(const Suite& suite);
		bool IsPrintRun() const noexcept;
		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);		

	private:
		using OpenGLGlutCallBackUnitTestSuiteImplPtr = std::shared_ptr<ImplType>;
		using StreamTypeSharedPtr = std::shared_ptr<StreamType>;

	private:
		virtual void AddSuite() = 0;

		bool AddSuiteOnInitialize();	 

	private:
		StreamTypeSharedPtr m_Stream;
		OpenGLGlutCallBackUnitTestSuiteImplPtr m_Impl;
		bool m_IsInit;
	};

	using OpenGLGlutProcessUnitTestSuite = OpenGLGlutProcess<OpenGLGlutCallBackUnitTestSuite>;
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
