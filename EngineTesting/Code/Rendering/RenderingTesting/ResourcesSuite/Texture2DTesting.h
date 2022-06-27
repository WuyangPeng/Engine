///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 15:54)

#ifndef RENDERING_RESOURCES_SUITE_TEXTURE_2D_TESTING_H
#define RENDERING_RESOURCES_SUITE_TEXTURE_2D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class Texture2DTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Texture2DTesting);

    private:
        void MainTest();
        void BaseTest();
        void MipmapsTest();
        void StreamTest();
        void FileTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_TEXTURE_2D_TESTING_H