// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:45)

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
		using String = System::String;

	public:
		explicit MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory) noexcept;

		CLASS_INVARIANT_DECLARE;

		String GetEngineInstallationDirectory() const;
		EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

	private:
		EnvironmentDirectory m_EnvironmentDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_IMPL_H