// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:33)

#ifndef RENDERING_CONTROLLERS_IK_CONTROLLER_H
#define RENDERING_CONTROLLERS_IK_CONTROLLER_H

#include "Rendering/RenderingDll.h" 

#include "Controller.h"
#include "IKGoal.h"
#include "IKJoint.h" 

RENDERING_EXPORT_SHARED_PTR(IKControllerImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE IKController : public Controller	
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(IKController);
		using ParentType = Controller;
		using IKJointSmartPointerVector = std::vector<IKJointSmartPointer>;

	public:
		explicit IKController(const IKJointSmartPointerVector& joints);
		virtual ~IKController();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKController);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		// 动画更新。应用程序时间以毫秒为单位。
		virtual bool Update(double applicationTime);

		virtual ControllerInterfaceSmartPointer Clone() const override;

		int GetIterations() const;
		void SetIterations(int iterations);
		bool IsOrderEndToRoot() const;
		void SetOrderEndToRoot(bool orderEndToRoot);

		const IKJointSmartPointer GetJointsSmartPointer(int index);
		int GetJointsNum() const;

    private:
		IMPL_TYPE_DECLARE(IKController);
	};
	
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(IKController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, IKController); 

}

#endif // RENDERING_CONTROLLERS_IK_CONTROLLER_H
