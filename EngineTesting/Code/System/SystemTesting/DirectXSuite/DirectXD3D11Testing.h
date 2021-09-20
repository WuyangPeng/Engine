///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/01 20:55)

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