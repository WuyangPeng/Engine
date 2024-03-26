/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 16:07)

#ifndef SYSTEM_TESTING_HELPER_SUITE_WGL_EXTENSIONS_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_WGL_EXTENSIONS_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ��������ڲ���WglExtensionsMacroͷ�ļ���
    /// ͨ������System/Helper/WglExtensionsMacro.h�ļ���ʵ�ֲ��ԣ�
    /// �౾���ǿղ��ԡ�
    class WglExtensionsMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WglExtensionsMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit WglExtensionsMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_WGL_EXTENSIONS_MACRO_TESTING_H
