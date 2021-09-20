// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/26 18:03)

#include "ModelViewControllerMiddleLayerTest.h"  
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
 
Framework::ModelViewControllerMiddleLayerTest
	::ModelViewControllerMiddleLayerTest(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayerTest)

const Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest
	::GetPublicModelMiddleLayer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return GetModelMiddleLayer();
}

const Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest
	::GetPublicViewMiddleLayer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return GetViewMiddleLayer();
}

const Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest
	::GetPublicControllerMiddleLayer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return GetControllerMiddleLayer();
}

const Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest
	::GetConstPublicModelMiddleLayer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetConstModelMiddleLayer();
}

const Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest
	::GetConstPublicViewMiddleLayer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetConstViewMiddleLayer();
}

const Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerTest
	::GetConstPublicControllerMiddleLayer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return GetConstControllerMiddleLayer();
}
