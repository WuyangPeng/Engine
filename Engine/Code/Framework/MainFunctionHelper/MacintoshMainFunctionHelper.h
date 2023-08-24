///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:23)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_H

#include "Framework/FrameworkDll.h"

#include "MainFunctionHelperBase.h"

namespace Framework
{
    template <template <typename> class Build, typename Process>
    class MacintoshMainFunctionHelper : public MainFunctionHelperBase
    {
    public:
        using ClassType = MacintoshMainFunctionHelper<Build, Process>;
        using ParentType = MainFunctionHelperBase;

        using ClassShareType = CoreTools::NonCopyClasses;
        using BuildType = Build<Process>;

    public:
        explicit MacintoshMainFunctionHelper(const EnvironmentDirectory& environmentDirectory);
        ~MacintoshMainFunctionHelper() noexcept;
        MacintoshMainFunctionHelper(const MacintoshMainFunctionHelper& rhs) noexcept = delete;
        MacintoshMainFunctionHelper& operator=(const MacintoshMainFunctionHelper& rhs) noexcept = delete;
        MacintoshMainFunctionHelper(MacintoshMainFunctionHelper&& rhs) noexcept;
        MacintoshMainFunctionHelper& operator=(MacintoshMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Destroy() override;

    private:
        using BuildSharedPtr = std::shared_ptr<BuildType>;

    private:
        int DoRun() noexcept override;
        NODISCARD virtual int RunMacintoshMainLoop() noexcept;

        void Initializer();
        void Terminators();

        void InitMacintoshProcess() noexcept;
        void InitMacintoshImpl();

        void DestroyMacintoshImpl() noexcept;
        void DestroyMacintoshProcess() noexcept;

    private:
        BuildSharedPtr build;
        MacintoshMainFunctionSchedule macintoshMainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_H
