///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:33)

#include "PickerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Rendering/Detail/SwitchNode.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/Picker.h"
#include "Rendering/SceneGraph/Triangles.h"

#include <random>

Rendering::PickerTesting::PickerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PickerTesting)

void Rendering::PickerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::PickerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::PickerTesting::BaseTest() noexcept
{
}
