///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:04)

#include "ModelViewControllerMiddleLayerTest.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ModelViewControllerMiddleLayerTest::ModelViewControllerMiddleLayerTest(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
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
