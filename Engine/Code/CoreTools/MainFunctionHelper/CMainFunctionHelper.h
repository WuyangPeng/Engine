/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:45)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/UnitTestSuite/OStreamShared.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CMainFunctionHelper
    {
    public:
        using ClassType = CMainFunctionHelper;

    public:
        CMainFunctionHelper(int argc, char** argv);
        virtual ~CMainFunctionHelper() noexcept;

        CMainFunctionHelper(const CMainFunctionHelper& rhs) = delete;
        CMainFunctionHelper& operator=(const CMainFunctionHelper& rhs) = delete;
        CMainFunctionHelper(CMainFunctionHelper&& rhs) noexcept;
        CMainFunctionHelper& operator=(CMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetArgc() const noexcept;
        NODISCARD char** GetArgv() noexcept;
        NODISCARD char* GetArgv(int index) noexcept;

        NODISCARD int Run() noexcept;

    protected:
        void SystemPause() noexcept;
        NODISCARD OStreamShared GetStreamShared() const noexcept;

    private:
        void InitSingleton();
        void InitUniqueIdManager();
        void InitLog();
        void GenerateStream();
        void InitStreamLocale();

        void DestroySingleton() noexcept;
        void DestroyStream() noexcept;
        void DestroyLog() noexcept;
        void DestroyUniqueIdManager() noexcept;

        NODISCARD virtual int DoRun() = 0;

    private:
        enum class ScheduleType
        {
            Failure = 0,
            UniqueIdManager = 1,
            Log = 2,
            Max = 3,
        };

    private:
        int argc;
        char** argv;
        OStreamShared stream;
        ScheduleType schedule;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H