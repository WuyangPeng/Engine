/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:59)

#ifndef SYSTEM_DIRECT_X_SUITE_DIRECT_X_D3_D12_TESTING_H
#define SYSTEM_DIRECT_X_SUITE_DIRECT_X_D3_D12_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DirectXD3D12Testing final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DirectXD3D12Testing;
        using ParentType = UnitTest;

    public:
        explicit DirectXD3D12Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_DIRECT_X_SUITE_DIRECT_X_D3_D12_TESTING_H