///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 15:02)

#include "AndroidMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

#ifndef SYSTEM_PLATFORM_ANDROID

int main()
{
    System::AndroidApp androidApp{};

    return Framework::AndroidMainEntryPoint<Framework::AndroidMainEntryPoint1>(&androidApp, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
}

#elif defined(FRAMEWORK_ANDROID_TEST)

int main()
{
    System::AndroidApp androidApp{};

    return Framework::AndroidMainEntryPoint<Framework::AndroidMainEntryPoint1>(&androidApp, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
}

void android_main(MAYBE_UNUSED System::AndroidApp* androidApp)
{
}

#else  // !FRAMEWORK_ANDROID_TEST && !SYSTEM_PLATFORM_ANDROID

void android_main(System::AndroidApp* androidApp)
{
    Framework::AndroidMainEntryPoint<Framework::AndroidMainEntryPoint1>(androidApp, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
}

#endif  // SYSTEM_PLATFORM_ANDROID
