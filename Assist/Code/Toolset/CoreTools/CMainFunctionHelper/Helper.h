// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/03 22:48)

#ifndef C_MAIN_FUNCTION_HELPER_HELPER_H
#define C_MAIN_FUNCTION_HELPER_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionHelper.h"

namespace CMainFunctionHelper
{
	class Helper : public CoreTools::CMainFunctionHelper
	{
	public:
		using ClassType = Helper;
		using ParentType = CMainFunctionHelper;

	public:
		Helper(int argc, char** argv);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		  int DoRun() override;
	};
}

#endif // C_MAIN_FUNCTION_HELPER_HELPER_H