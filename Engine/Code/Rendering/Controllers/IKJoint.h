// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 10:34)

#ifndef RENDERING_CONTROLLERS_IKJOINT_H
#define RENDERING_CONTROLLERS_IKJOINT_H

#include "Rendering/RenderingDll.h" 

#include "IKGoal.h"
#include "Rendering/SceneGraph/Spatial.h"

RENDERING_EXPORT_SHARED_PTR(IKJointImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE IKJoint : public CoreTools::Object 
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(IKJoint);
		using ParentType = Object;
		using APoint = Mathematics::APointf;
		using AVector = Mathematics::AVectorf;
		using IKGoalSmartPointerVector = std::vector<IKGoalSmartPointer>;
		using MatrixRotationAxis = Mathematics::MatrixRotationAxis;

	public:		
		IKJoint(const SpatialSmartPointer& object,const IKGoalSmartPointerVector& goals);
		  ~IKJoint();
                IKJoint(IKJoint&&) = default;
                IKJoint& operator=(IKJoint&&) = default;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKJoint);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		// Joint¸üÐÂ¡£
		const AVector GetAxis(MatrixRotationAxis axisIndex) const;
		void UpdateWorldTransform();
		void UpdateWorldRotateAndTranslate();
		bool UpdateLocalTranslate(MatrixRotationAxis axisIndex);
		bool UpdateLocalRotate(MatrixRotationAxis axisIndex);	

		const ConstSpatialSmartPointer GetObjectSmartPointer() const noexcept;
		const ConstIKGoalSmartPointer GetGoalsSmartPointer(int index) const;
		int GetGoalsNum() const;

		void SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation);
		void SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation);

		bool IsAllowTranslation(MatrixRotationAxis axisIndex) const;
		bool IsAllowRotation(MatrixRotationAxis axisIndex) const;

	private:
		IMPL_TYPE_DECLARE(IKJoint);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(IKJoint);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, IKJoint); 
}

#endif // RENDERING_CONTROLLERS_IKJOINT_H
