///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:42)

#ifndef SYSTEM_DIRECT_X_SUITE_DIRECT_X_D3D11_TESTING_H
#define SYSTEM_DIRECT_X_SUITE_DIRECT_X_D3D11_TESTING_H

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

#endif  // SYSTEM_DIRECT_X_SUITE_DIRECT_X_D3D11_TESTING_H