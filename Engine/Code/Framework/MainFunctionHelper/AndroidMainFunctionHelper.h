///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:39)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

namespace Framework
{
    template <template <typename> class Build, typename Process>
    class AndroidMainFunctionHelper : public MainFunctionHelperBase
    {
    public:
        using ClassType = AndroidMainFunctionHelper<Build, Process>;
        using ParentType = MainFunctionHelperBase;
        using ClassShareType = CoreTools::NonCopyClasses;
        using BuildType = Build<Process>;
        using AndroidApp = System::AndroidApp;

    public:
        AndroidMainFunctionHelper(AndroidApp* androidApp, const EnvironmentDirectory& environmentDirectory);
        ~AndroidMainFunctionHelper() noexcept;
        AndroidMainFunctionHelper(const AndroidMainFunctionHelper& rhs) noexcept = delete;
        AndroidMainFunctionHelper& operator=(const AndroidMainFunctionHelper& rhs) noexcept = delete;
        AndroidMainFunctionHelper(AndroidMainFunctionHelper&& rhs) noexcept;
        AndroidMainFunctionHelper& operator=(AndroidMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Destroy() override;

    protected:
        NODISCARD AndroidApp* GetAndroidApp();

    private:
        using BuildSharedPtr = std::shared_ptr<BuildType>;

    private:
        int DoRun() override;
        NODISCARD virtual int RunAndroidMainLoop();

        void Initializers(AndroidApp* androidApp);
        void Terminators();

        void InitAndroidProcess();
        void InitImpl(AndroidApp* androidApp);

        void DestroyImpl() noexcept;
        void DestroyAndroidProcess() noexcept;

    private:
        BuildSharedPtr build;
        AndroidMainFunctionSchedule androidMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
