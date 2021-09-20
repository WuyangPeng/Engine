// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 18:59)

#ifndef RENDERING_SCENE_GRAPH_SUITE_STANDARD_MESH_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_STANDARD_MESH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class StandardMeshTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StandardMeshTesting); 

	private:
		void MainTest();	
		void BaseTest();
		void RectangleTest();
		void DiskTest();
		void BoxTest();
		void CylinderOmittedEndDisksTest();
		void CylinderIncludedEndDisksTest();
		void SphereTest();
		void TorusTest();
		void TetrahedronTest();
		void HexahedronTest();
		void OctahedronTest();
		void DodecahedronTest();
		void IcosahedronTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_STANDARD_MESH_TESTING_H