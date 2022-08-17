///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 20:57)

#include "SkinControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/SkinController.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/VisualTest.h" 
#include "Rendering/SceneGraph/LoadVisual.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SkinControllerTesting)

void Rendering::SkinControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}