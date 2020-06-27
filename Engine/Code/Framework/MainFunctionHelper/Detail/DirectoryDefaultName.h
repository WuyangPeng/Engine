// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/29 11:23)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_DEFAULT_NAME_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_DEFAULT_NAME_H

#include "Framework/FrameworkDll.h" 

#include "System/Helper/UnicodeUsing.h" 
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE DirectoryDefaultName
	{
	public:
		using ClassType = DirectoryDefaultName;
		using String = System::String;

	public:
		static const String GetDefaultNullName();
		static const String GetSuffix();
		static const String GetDefaultKeyName(AnalysisDirectory analysisDirectory);
		static const String GetDefaultName(AnalysisDirectory analysisDirectory);
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_DEFAULT_NAME_H