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
EXPORT_SHARED_PTR(Rendering, PointControllerImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class Polypoint;

	class RENDERING_DEFAULT_DECLARE PointController : public Controller
	{
	public:

            void Swap(PointController& rhs) noexcept;
      
          public:
              TYPE_DECLARE(PointController);
              using ClassShareType = CoreTools::CopyUnsharedClasses;
              ~PointController() noexcept= default;
              PointController(const PointController& rhs);
              PointController& operator=(const PointController& rhs);
              PointController(PointController&& rhs) noexcept;
              PointController& operator=(PointController&& rhs) noexcept;
		using ParentType = Controller;
		using AVector = Mathematics::AVectorF;

	public:
		// �����ӵĶ��������Polypoint��Polypoint�������ࡣ
		PointController();
		 
		  
		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
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
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;

		Polypoint* m_Points;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(PointController);
#include STSTEM_WARNING_POP
        CORE_TOOLS_SHARED_PTR_DECLARE(PointController);
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_POINT_CONTROLLER_H
