// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/25 14:42)

#include "AndroidMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h" 

#include <vld.h> 

#ifndef SYSTEM_PLATFORM_ANDROID

	int main()
	{ 
		System::AndroidApp androidApp{ }; 

		return Framework::AndroidMainEntryPoint<Framework::AndroidMainEntryPoint1>(&androidApp, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
	}

#elif defined(FRAMEWORK_ANDROID_TEST)

	int main() 
	{ 
		System::AndroidApp androidApp{ };

		return Framework::AndroidMainEntryPoint<Framework::AndroidMainEntryPoint1>(&androidApp, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
	} 
	
	void android_main(System::AndroidApp* androidApp)
	{ 
		SYSTEM_UNUSED_ARG(androidApp); 
	}

#else // !FRAMEWORK_ANDROID_TEST && !SYSTEM_PLATFORM_ANDROID
 
	void android_main(System::AndroidApp* androidApp) 
	{ 
		Framework::AndroidMainEntryPoint<Framework::AndroidMainEntryPoint1>(androidApp, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
	}

#endif // SYSTEM_PLATFORM_ANDROID


