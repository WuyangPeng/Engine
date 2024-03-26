/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 17:33)

#ifndef SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ���Ա���������
    /// ����SelectCompilerConfig.h
    /// TCRE_COMPILER_VERSION��TCRE_SYSTEM_COMPILER��SYSTEM_CPP_STANDARD�������ڡ�
    /// ����VisualC.h
    /// MSVC_VERSION��TCRE_USE_MSVC��MSVC_FULL_VERSION��TCRE_COMPILER_VERSION�������ڡ�
    class CompilerConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CompilerConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit CompilerConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CompilerTest();
        void VisualCTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H
