///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 20:51)

#include "KeyframeControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/KeyframeController.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, KeyframeControllerTesting)

void Rendering::KeyframeControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CoreTools::InitTerm::ExecuteTerminators();
}
