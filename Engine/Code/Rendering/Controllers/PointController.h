// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:37)

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
		// 所连接的对象必须是Polypoint或Polypoint派生的类。
		PointController();
		  ~PointController();
		PointController(PointController&&) = default;
		  PointController& operator=(PointController&&) = default;
		  
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PointController); 

		// 点运动，在该系统的模型空间。速度矢量应为单位的长度。
		// 其中点代表一个刚体在应用程序，
		// 你可以选择该系统的原点为点的质量中心和
		// 坐标轴对应于惯性张量的主方向。
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

		// 动画更新。应用程序时间以毫秒为单位。
		 bool Update(double applicationTime) override;
		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;

	protected:
		// 对于点运动数组的延迟分配。
		void Reallocate (int numPoints); 		

		// 该类从运动参数计算新的位置和方向。
		// 派生类应该更新运动参数，然后要么调用基类的更新方法或在自己的更新方法中提供位置和方向。
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
