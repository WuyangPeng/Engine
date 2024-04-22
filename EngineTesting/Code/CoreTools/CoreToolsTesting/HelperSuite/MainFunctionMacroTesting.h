/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 20:28)

#ifndef CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    /// ��MAIN_FUNCTION��CORE_TOOLS_MUTEX_INIT��CORE_TOOLS_MUTEX_EXTERNʹ��Toolset�е�MainFunction���ԡ�
    /// ��DLL_MAIN_FUNCTIONʹ��Toolset�е�DllMainFunction���ԡ�
    /// ����Ϊ�ղ��ԡ�
    class MainFunctionMacroTesting final : public UnitTest
    {
    public:
        using ClassType = MainFunctionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MainFunctionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H