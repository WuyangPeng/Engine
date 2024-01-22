/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:14)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H

#include "Framework/FrameworkDll.h"

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

        void Initializer(AndroidApp* androidApp);
        void Terminators();

        void InitAndroidProcess();
        void InitAndroidImpl(AndroidApp* androidApp);

        void DestroyAndroidImpl() noexcept;
        void DestroyAndroidProcess() noexcept;

    private:
        BuildSharedPtr build;
        AndroidMainFunctionSchedule androidMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
