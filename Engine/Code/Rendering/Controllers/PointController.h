// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:37)

#ifndef RENDERING_CONTROLLERS_POINT_CONTROLLER_H
#define RENDERING_CONTROLLERS_POINT_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/AVector.h"
#include "Controller.h" 

RENDERING_EXPORT_SHARED_PTR(PointControllerImpl);

namespace Rendering
{
	class Polypoint;

	class RENDERING_DEFAULT_DECLARE PointController : public Controller
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(PointController);
		using ParentType = Controller;
		using AVector = Mathematics::AVectorf;

	public:
		// �����ӵĶ��������Polypoint��Polypoint�������ࡣ
		PointController();
		  ~PointController();
		PointController(PointController&&) = default;
		  PointController& operator=(PointController&&) = default;
		  
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PointController); 

		// ���˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
		// ���е����һ��������Ӧ�ó���
		// �����ѡ���ϵͳ��ԭ��Ϊ����������ĺ�
		// �������Ӧ�ڹ���������������
		int GetNumPoints() const noexcept;
		float GetPointLinearSpeed(int index) const;
		float GetPointAngularSpeed(int index) const;
		const AVector GetPointLinearAxis(int index) const;
		const AVector GetPointAngularAxis(int index) const;

		void SetPointLinearSpeed(int index, float pointLinearSpeed);
		void SetPointAngularSpeed(int index, float pointAngularSpeed);
		void SetPointLinearAxis(int index, const AVector& pointLinearAxis);
		void SetPointAngularAxis(int index, const AVector& pointAngularAxis);

		float GetSystemLinearSpeed() const noexcept;
		void SetSystemLinearSpeed(float systemLinearSpeed) noexcept;
		float GetSystemAngularSpeed() const noexcept;
		void SetSystemAngularSpeed(float systemAngularSpeed) noexcept;
		const AVector GetSystemLinearAxis() const noexcept;
		void SetSystemLinearAxis(const AVector& systemLinearAxis) noexcept;
		const AVector GetSystemAngularAxis() const noexcept;
		void SetSystemAngularAxis(const AVector& systemAngularAxis) noexcept;

		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		 bool Update(double applicationTime) override;
		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;

	protected:
		// ���ڵ��˶�������ӳٷ��䡣
		void Reallocate (int numPoints); 		

		// ������˶����������µ�λ�úͷ���
		// ������Ӧ�ø����˶�������Ȼ��Ҫô���û���ĸ��·��������Լ��ĸ��·������ṩλ�úͷ���
		virtual void UpdateSystemMotion (float ctrlTime);
		virtual void UpdatePointMotion (float ctrlTime);

	private:
		IMPL_TYPE_DECLARE(SkinController);

		Polypoint* m_Points;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(PointController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, PointController); 
}

#endif // RENDERING_CONTROLLERS_POINT_CONTROLLER_H
