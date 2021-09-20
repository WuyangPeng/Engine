// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:09)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR2D_ORTHONORMAL_BASIS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR2D_ORTHONORMAL_BASIS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Vector2DOrthonormalBasisTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector2DOrthonormalBasisTesting);

    private:
        void MainTest();
        void OrthonormalBasisTest();

        virtual void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR2D_ORTHONORMAL_BASIS_TESTING_H