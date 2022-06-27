///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/26 22:46)

#include "ModelViewControllerMiddleLayerTest.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ModelViewControllerMiddleLayerTest::ModelViewControllerMiddleLayerTest(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayerTest)

Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest::GetPublicModelMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return GetModelMiddleLayer();
}

Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest::GetPublicViewMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return GetViewMiddleLayer();
}

Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest::GetPublicControllerMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return GetControllerMiddleLayer();
}

Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest::GetConstPublicModelMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetConstModelMiddleLayer();
}

Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest::GetConstPublicViewMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetConstViewMiddleLayer();
}

Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest::GetConstPublicControllerMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GetConstControllerMiddleLayer();
}
