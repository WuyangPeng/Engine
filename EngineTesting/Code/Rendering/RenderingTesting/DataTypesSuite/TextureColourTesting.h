///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:56)

#ifndef RENDERING_DATA_TYPES_SUITE_TEXTURE_COLOUR_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_TEXTURE_COLOUR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class TextureColourTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TextureColourTesting;
        using ParentType = UnitTest;

    public:
        explicit TextureColourTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void R5G6B5Test();
        void A1R5G5B5Test();
        void A4R4G4B4Test();
        void A8Test();
        void L8Test();
        void A8L8Test();
        void R8G8B8Test();
        void A8R8G8B8Test();
        void A8B8G8R8Test();
        void L16Test();
        void G16R16Test();
        void A16B16G16R16Test();
        void R16FTest() noexcept;
        void G16R16FTest() noexcept;
        void A16B16G16R16FTest() noexcept;
        void R32FTest();
        void G32R32FTest();
        void A32B32G32R32FTest();
        void ConvertingTest() noexcept;
        void OperatorTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_TEXTURE_COLOUR_TESTING_H