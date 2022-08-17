///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 20:57)

#include "PointControllerTest.h"
#include "PointControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/Controller.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Polypoint.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PointControllerTesting)

void Rendering::PointControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}