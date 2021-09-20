// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/02 15:34)

#include "MacintoshMainFunctionHelper1.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <vld.h>

int main()
{
	EXCEPTION_TRY
	{
		Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };

	#include STSTEM_WARNING_PUSH

		#include SYSTEM_WARNING_DISABLE(26414) 
		auto helper = std::make_shared<Framework::MacintoshMainFunctionHelper1>(environmentDirectory);

	#include STSTEM_WARNING_POP

		return helper->Run();
	}
	EXCEPTION_ENTRY_POINT_CATCH

	return -1;
}


