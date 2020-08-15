// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:38)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

RENDERING_EXPORT_SHARED_PTR(TransformControllerImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TransformController : public Controller
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(TransformController);
		using ParentType = Controller;
		using APoint = Mathematics::APointf;
		using Matrix = Mathematics::Matrixf;

	public:
		explicit TransformController(const Transform& localTransform);
		  ~TransformController();
TransformController(TransformController&&) = default;
		  TransformController& operator=(TransformController&&) = default;
		  
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TransformController); 
	 
		void SetTransform(const Transform& localTransform) noexcept;
		const Transform GetTransform() const noexcept;

		void SetTranslate(const APoint& translate);
		void SetRotate(const Matrix& rotate);
		void SetUniformScale(float scale);
		void SetScale(const APoint& scale);
		void SetMatrix(const Matrix& matrix);

		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;
		
		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		// ���¼򵥵Ŀ���m_LocalTransform��Spatial m_Object��LocalTransform��
		// ����������ϣ�TransformController��ʾһ������ʱ��Ϊ������transform��
		 bool Update(double applicationTime) override;

		 ControllerInterfaceSmartPointer Clone() const override;
    
	private:
		IMPL_TYPE_DECLARE(TransformController);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(TransformController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, TransformController); 
}

#endif // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
