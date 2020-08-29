// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:48)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"
#include "Framework/Application/ApplicationFwd.h"

namespace Framework
{
	template <template<typename> class Build, typename Process>
	class OpenGLGlutMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = OpenGLGlutMainFunctionHelper<Build, Process>;
		using ParentType = MainFunctionHelperBase;
		using ClassShareType = CoreTools::NonCopyClasses;
		using BuildType = Build<Process>;

	public:
		OpenGLGlutMainFunctionHelper(int argc, char** argv, const GLUTApplicationInformation& information,
									 const EnvironmentDirectory& environmentDirectory);
		~OpenGLGlutMainFunctionHelper() noexcept;
		OpenGLGlutMainFunctionHelper(const OpenGLGlutMainFunctionHelper& rhs) noexcept = delete;
		OpenGLGlutMainFunctionHelper& operator=(const OpenGLGlutMainFunctionHelper& rhs) noexcept = delete;
		OpenGLGlutMainFunctionHelper(OpenGLGlutMainFunctionHelper&& rhs) noexcept;
		OpenGLGlutMainFunctionHelper& operator=(OpenGLGlutMainFunctionHelper&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Init();
		void Destroy() override;

	private:
		using BuildSharedPtr = std::shared_ptr<BuildType>;

	private:
		int DoRun() override;
		virtual int RunOpenGLGlutMainLoop();

		void Initializers(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);
		void Terminators();

		void InitOpenGLGlutProcess();
		void InitCamera();
		void InitImpl(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

		void DestroyImpl() noexcept;
		void DestroyCamera() noexcept;
		void DestroyOpenGLGlutProcess();

	private:
		BuildSharedPtr m_Build;
		OpenGLGlutMainFunctionSchedule m_OpenGLGlutMainFunctionSchedule;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_H