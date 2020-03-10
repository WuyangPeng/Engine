// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:50)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H

#include "Framework/FrameworkDll.h" 

#include "System/Helper/UnicodeUsing.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE MainFunctionHelperBaseImpl
	{
	public:
		using ClassType = MainFunctionHelperBaseImpl;

	public:
		explicit MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory);		
		
		CLASS_INVARIANT_DECLARE;

		System::String GetEngineInstallationDirectory() const;		

	private:
		void GenerateEnvironment();

	private:
		EnvironmentDirectory m_EnvironmentDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H