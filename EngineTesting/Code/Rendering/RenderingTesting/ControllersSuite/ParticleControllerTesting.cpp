///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:05)

#include "ParticleControllerTest.h"
#include "ParticleControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/Controller.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Particles.h"

#include <random>
#include <vector>

Rendering::ParticleControllerTesting::ParticleControllerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ParticleControllerTesting)

void Rendering::ParticleControllerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ParticleControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    CameraManager::Create();
    RendererManager::Create();

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}