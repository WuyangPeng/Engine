// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_H

#include "InputManagerInterface.h" 

namespace Framework
{
	template <typename ApplicationTrait>
	class InputManager : public InputManagerInterface
	{
	public:
		using ClassType = InputManager<ApplicationTrait>;
		using ParentType = InputManagerInterface;

	public:
		explicit InputManager(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

