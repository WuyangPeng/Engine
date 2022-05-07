///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/08 11:10)

#ifndef SYSTEM_TESTING_TESTING_HELPER_H
#define SYSTEM_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace System
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;
        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();

        NODISCARD Suite GetConfigMacroSuite();
        NODISCARD Suite GetWindowsMacroSuite();
        NODISCARD Suite GetEnumMacroSuite();
        NODISCARD Suite GetOpenGLMacroSuite();
        NODISCARD Suite GetGlUtilityMacroSuite();

        void AddSystemOutputSuite();

        NODISCARD Suite GetMessageBoxSelectionSuite();

        void AddDynamicLinkSuite();

        NODISCARD Suite GetLoadLibrarySuite();
        NODISCARD Suite GetLibraryToolsSuite();
        NODISCARD Suite GetLoadResourceToolsSuite();
        NODISCARD Suite GetEnumResourceToolsSuite();

        void AddCharacterStringSuite();

        NODISCARD Suite GetFormatErrorMessageSuite();
        NODISCARD Suite GetCodePageSuite();
        NODISCARD Suite GetStringConversionSuite();
        NODISCARD Suite GetFormatStringSuite();

        void AddConsoleSuite();

        NODISCARD Suite GetConsoleColoursSuite();
        NODISCARD Suite GetConsoleScreenBufferSuite();

        void AddMemoryToolsSuite();

        NODISCARD Suite GetHeapToolsSuite();
        NODISCARD Suite GetViewOfFileSuite();
        NODISCARD Suite GetMemoryHelperSuite();
        NODISCARD Suite GetVirtualToolsSuite();
        NODISCARD Suite GetLocalToolsSuite();

        void AddThreadingSuite();

        NODISCARD Suite GetCriticalSectionSuite();
        NODISCARD Suite GetSemaphoreSuite();
        NODISCARD Suite GetEventSuite();
        NODISCARD Suite GetMutexSuite();
        NODISCARD Suite GetSlimReaderWriterSuite();
        NODISCARD Suite GetConditionVariableSuite();
        NODISCARD Suite GetInitOnceSuite();
        NODISCARD Suite GetWaitableTimerSuite();
        NODISCARD Suite GetSyncToolsSuite();
        NODISCARD Suite GetInterlockedSuite();
        NODISCARD Suite GetThreadSuite();
        NODISCARD Suite GetThreadToolsSuite();
        NODISCARD Suite GetProcessSuite();
        NODISCARD Suite GetProcessToolsSuite();

        void AddTimeSuite();
        void AddFileManagerSuite();

        NODISCARD Suite GetCFileSuite();
        NODISCARD Suite GetFileSuite();
        NODISCARD Suite GetFileToolsSuite();
        NODISCARD Suite GetFileTimeSuite();

        void AddSecuritySuite();

        NODISCARD Suite GetCreateSecuritySuite();
        NODISCARD Suite GetSecurityDescriptorSuite();
        NODISCARD Suite GetAccessCheckSuite();
        NODISCARD Suite GetAddAccessSuite();
        NODISCARD Suite GetSecurityBaseSuite();
        NODISCARD Suite GetSecuritySidSuite();
        NODISCARD Suite GetSecurityAclSuite();
        NODISCARD Suite GetSecurityAceSuite();

        void AddNetworkSuite();

        NODISCARD Suite GetSocketPrototypesSuite();
        NODISCARD Suite GetDatabasePrototypesSuite();
        NODISCARD Suite GetWindowsSockExSuite();

        void AddOpenGLSuite();
        void AddDirectXSuite();

        void AddWindowsSuite();

        NODISCARD Suite GetWindowsSystemSuite();

        void AddLinuxSuite();
        void AddMacintoshSuite();
        void AddAndroidSuite();
    };
}

#endif  // SYSTEM_TESTING_TESTING_HELPER_H