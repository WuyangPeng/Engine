//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 18:27)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

#include <iosfwd>

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
        virtual CMainFunctionHelper& operator=(const CMainFunctionHelper& rhs) = delete;
        CMainFunctionHelper(CMainFunctionHelper&& rhs) noexcept;
        virtual CMainFunctionHelper& operator=(CMainFunctionHelper&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] int GetArgc() const noexcept;
        [[nodiscard]] char** GetArgv() noexcept;

        [[nodiscard]] int Run() noexcept;

    protected:
        void SystemPause() noexcept;
        [[nodiscard]] OStreamShared GetStreamShared() const noexcept;

    private:
        void InitSingleton();
        void InitUniqueIDManager();
        void InitLog();
        void InitMemory() noexcept(g_MemoryNoexcept); 
        void GenerateStream();
        void InitStreamLocale();

        void DestroySingleton() noexcept;
        void DestroyStream() noexcept; 
        void DestroyMemory() noexcept;
        void DestroyLog() noexcept;
        void DestroyUniqueIDManager() noexcept;

        [[nodiscard]] virtual int DoRun() = 0;

    private:
        enum class ScheduleType
        {
            Failure = 0,
            UniqueIDManager = 1,
            Log = 2,
            Memory = 3,
            Max = 4,
        };

    private:
        int m_Argc;
        char** m_Argv;
        OStreamShared m_Stream;
        ScheduleType m_Schedule;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H