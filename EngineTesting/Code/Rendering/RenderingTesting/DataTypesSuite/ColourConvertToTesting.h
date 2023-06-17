///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:56)

#ifndef RENDERING_DATA_TYPES_SUITE_COLOUR_CONVERT_TO_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_COLOUR_CONVERT_TO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ColourConvertToTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ColourConvertToTesting;
        using ParentType = UnitTest;

    public:
        explicit ColourConvertToTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void R5G6B5ConvertTest() noexcept;
        void A1R5G5B5ConvertTest() noexcept;
        void A4R4G4B4ConvertTest() noexcept;
        void A8ConvertTest() noexcept;
        void L8ConvertTest() noexcept;
        void A8L8ConvertTest() noexcept;
        void R8G8B8ConvertTest() noexcept;
        void A8R8G8B8ConvertTest() noexcept;
        void A8B8G8R8ConvertTest() noexcept;
        void L16ConvertTest() noexcept;
        void G16R16ConvertTest() noexcept;
        void A16B16G16R16ConvertTest() noexcept;
        void R16FConvertTest() noexcept;
        void G16R16FConvertTest() noexcept;
        void A16B16G16R16FConvertTest() noexcept;
        void R32FConvertTest() noexcept;
        void G32R32FConvertTest() noexcept;
        void A32B32G32R32FConvertTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_COLOUR_CONVERT_TO_TESTING_H