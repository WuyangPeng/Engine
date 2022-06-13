///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:59)

#ifndef SYSTEM_DIRECTX_SUITE_DIRECTX_D3D11_TESTING_H
#define SYSTEM_DIRECTX_SUITE_DIRECTX_D3D11_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DirectXD3D11Testing final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DirectXD3D11Testing;
        using ParentType = UnitTest;

    public:
        explicit DirectXD3D11Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_DIRECTX_SUITE_DIRECTX_D3D11_TESTING_H