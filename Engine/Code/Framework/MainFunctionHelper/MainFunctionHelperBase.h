/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:14)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H

#include "Framework/FrameworkDll.h"

#include "EnvironmentDirectory.h"
#include "MainFunctionHelperFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(MainFunctionHelperBaseImpl);
template class FRAMEWORK_DEFAULT_DECLARE std::weak_ptr<Framework::MainFunctionHelperBase>;
template class FRAMEWORK_DEFAULT_DECLARE std::enable_shared_from_this<Framework::MainFunctionHelperBase>;

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE MainFunctionHelperBase : public std::enable_shared_from_this<MainFunctionHelperBase>
    {
    public:
        NON_COPY_TYPE_DECLARE(MainFunctionHelperBase);

        using String = System::String;

    public:
        explicit MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory);
        virtual ~MainFunctionHelperBase() noexcept;
        MainFunctionHelperBase(const MainFunctionHelperBase& rhs) noexcept = delete;
        MainFunctionHelperBase& operator=(const MainFunctionHelperBase& rhs) noexcept = delete;
        MainFunctionHelperBase(MainFunctionHelperBase&& rhs) noexcept;
        MainFunctionHelperBase& operator=(MainFunctionHelperBase&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD String GetEngineInstallationDirectory() const;

        NODISCARD int Run();

        virtual void Destroy();

    protected:
        NODISCARD bool IsDestroy() const noexcept;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const;

    private:
        void MainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory);
        void DoMainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory);
        void MainFunctionHelperDestroy();

        void InitUniqueIdManager();
        void InitLog(const EnvironmentDirectory& environmentDirectory);
        void InitInitTerm();
        void InitImpl(const EnvironmentDirectory& environmentDirectory);
        void InitJsonAnalysis();

        void DestroyJsonAnalysis() noexcept;
        void DestroyMainImpl() noexcept;
        void DestroyInitTerm();
        void DestroyLog() noexcept;
        void DestroyUniqueIdManager() noexcept;

        NODISCARD virtual int DoRun() = 0;

    private:
        using MainFunctionHelperBaseSharedPtr = std::shared_ptr<ImplType>;

    private:
        MainFunctionHelperBaseSharedPtr impl;
        MainFunctionSchedule mainFunctionSchedule;
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H