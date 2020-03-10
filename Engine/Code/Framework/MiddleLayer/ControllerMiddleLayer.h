// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:40)
// 控制层类的声明
#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

#include "ModelViewControllerMiddleLayer.h"

namespace Framework
{
	template <typename ApplicationTrait>
	class ControllerMiddleLayer : public ModelViewControllerMiddleLayer
	{
	public:
		typedef ControllerMiddleLayer<ApplicationTrait> ClassType;
		typedef ModelViewControllerMiddleLayer ParentType;

	public:
		ControllerMiddleLayer();
		virtual ~ControllerMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		virtual bool Move(const WindowPoint& point);
		virtual bool Resize(WindowDisplayFlags type,const WindowSize& size);
		virtual bool KeyDown(uint8_t key, const WindowPoint& point);
	    virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown(int key, const WindowPoint& point);
		virtual bool SpecialKeyUp(int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button,MouseStateTypes state, const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Create();
		virtual bool Destroy();	
		virtual bool Idle(int64_t timeDelta);
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_H

