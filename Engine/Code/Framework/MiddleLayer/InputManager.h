// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:48)

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
		InputManager();
		virtual ~InputManager();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
 
		virtual bool Move(const WindowPoint& point);
		virtual bool Resize(WindowDisplayFlags type, const WindowSize& size);
		virtual bool KeyDown(uint8_t key, const WindowPoint& point);
		virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown(int key, const WindowPoint& point);
		virtual bool SpecialKeyUp(int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button, MouseStateTypes state,const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

