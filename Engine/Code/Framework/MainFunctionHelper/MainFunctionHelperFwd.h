// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H

namespace Framework
{
	class EnvironmentDirectory;
	class MainFunctionHelperBase;
	class ConsoleMainFunctionHelper;

	template <template<typename > class Build,typename Process>
	class WindowMainFunctionHelper;

	template <template<typename > class Build,typename Process>
	class OpenGLGlutMainFunctionHelper;	

	template <template<typename > class Build,typename Process>
	class AndroidMainFunctionHelper;
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H