///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:46)

#ifndef RENDERING_RENDERERS_SUITE_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H
#define RENDERING_RENDERERS_SUITE_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class TextureManagementLockEncapsulationTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TextureManagementLockEncapsulationTesting;
        using ParentType = UnitTest;

    public:
        explicit TextureManagementLockEncapsulationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void Texture1DTest() noexcept;
        void Texture2DTest() noexcept;
        void Texture3DTest() noexcept;
        void TextureCubeTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H