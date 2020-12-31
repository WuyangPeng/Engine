// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:47)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H

namespace Framework
{
	enum class EndianDirectory;
	enum class RenderingDirectory;
	enum class AnalysisDirectory;
	enum class UpperDirectory;
	enum class RenderingAnalysisDirectory;

	enum class MainFunctionSchedule;
	enum class ConsoleMainFunctionSchedule;
	enum class WindowMainFunctionSchedule;
	enum class OpenGLGlutMainFunctionSchedule;
	enum class AndroidMainFunctionSchedule;
	enum class MacintoshMainFunctionSchedule;

	class EnvironmentDirectory;
	class MainFunctionHelperBase;
	class ConsoleMainFunctionHelperBase;

	template <template<typename> class Build, typename Process>
	class ConsoleMainFunctionHelper;

	template <template<typename> class Build, typename Process>
	class WindowMainFunctionHelper;

	template <template<typename> class Build, typename Process>
	class OpenGLGlutMainFunctionHelper;

	template <template<typename> class Build, typename Process>
	class AndroidMainFunctionHelper;

	template <template<typename> class Build, typename Process>
	class MacintoshMainFunctionHelper;
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H