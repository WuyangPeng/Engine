///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 20:50)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H

#include "AndroidMessageLoop.h"
#include "System/Android/AndroidNativeAppGlue.h"

namespace Framework
{
    template <typename AndroidProcess>
    class AndroidFrameBuild
    {
    public:
        using ClassType = AndroidFrameBuild<AndroidProcess>;

        using AndroidApp = System::AndroidApp;

    public:
        explicit AndroidFrameBuild(AndroidApp* state);
        virtual ~AndroidFrameBuild() noexcept = default;
        AndroidFrameBuild(const AndroidFrameBuild& rhs) noexcept = default;
        AndroidFrameBuild& operator=(const AndroidFrameBuild& rhs) noexcept = default;
        AndroidFrameBuild(AndroidFrameBuild&& rhs) noexcept = default;
        AndroidFrameBuild& operator=(AndroidFrameBuild&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void EnterMessageLoop();

        NODISCARD AndroidApp* GetAndroidApp() noexcept;

    private:
        NODISCARD bool InitApplication();

    private:
        static constexpr auto interval = 60;

        AndroidApp* state;
        AndroidProcess androidProcess;
        AndroidMessageLoop androidMessageLoop;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H
