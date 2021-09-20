// Threading Core Render Engine
// ���ߣ������������ʶ���������
// Copyright (c) 2011-2018
//
// ������԰汾��1.0.0.0 (2018/01/26 14:05)

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

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RESOURCES_SUITE_TEXTURE_2D_TESTING_H