///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 20:06)

#include "CullerTesting.h"
#include "SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Culler.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CullerTesting)

void Rendering::CullerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CameraTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpatialPtrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VisibleTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::CullerTesting::CameraTest() noexcept
{
}

void Rendering::CullerTesting::PlaneTest() noexcept
{
}

void Rendering::CullerTesting::SpatialPtrTest() noexcept
{
}

void Rendering::CullerTesting::VisibleTest() noexcept
{
}
