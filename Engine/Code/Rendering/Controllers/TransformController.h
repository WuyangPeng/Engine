// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:38)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

RENDERING_EXPORT_SHARED_PTR(TransformControllerImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TransformController : public Controller
	{
	public:
            COPY_UNSHARE_CLASSES_TYPE_DECLARE(TransformController, = default);
		using ParentType = Controller;
		using APoint = Mathematics::FloatAPoint;
		using Matrix = Mathematics::FloatMatrix;

	public:
		explicit TransformController(const FloatTransform& localTransform); 
		  
		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TransformController); 
	 
		void SetTransform(const FloatTransform& localTransform) noexcept;
		const FloatTransform GetTransform() const noexcept;

		void SetTranslate(const APoint& translate);
		void SetRotate(const Matrix& rotate);
		void SetUniformScale(float scale);
		void SetScale(const APoint& scale);
		void SetMatrix(const Matrix& matrix);

		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;
		
		// 动画更新。应用程序时间以毫秒为单位。
		// 更新简单的拷贝m_LocalTransform到Spatial m_Object的LocalTransform。
		// 在这个意义上，TransformController表示一个所有时间为常数的transform。
		 bool Update(double applicationTime) override;

		 ControllerInterfaceSharedPtr Clone() const override;
                 ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		IMPL_TYPE_DECLARE(TransformController);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(TransformController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( TransformController); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
