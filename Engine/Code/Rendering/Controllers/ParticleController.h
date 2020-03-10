// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:36)

#ifndef RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H
#define RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Mathematics/Algebra/AVector.h" 

RENDERING_EXPORT_SHARED_PTR(ParticleControllerImpl);

namespace Rendering
{	
	class Particles;

	class RENDERING_DEFAULT_DECLARE ParticleController : public Controller
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(ParticleController);
		using ParentType = Controller;
		using AVector = Mathematics::AVectorf;

	public:
		// 所连接的对象必须是Particles。
		ParticleController();
		virtual ~ParticleController();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ParticleController); 
		
		float GetSystemLinearSpeed() const;
		void SetSystemLinearSpeed(float systemLinearSpeed);
		float GetSystemAngularSpeed() const;
		void SetSystemAngularSpeed(float systemAngularSpeed);
		const AVector GetSystemLinearAxis() const;
		void SetSystemLinearAxis(const AVector& systemLinearAxis);
		const AVector GetSystemAngularAxis() const;
		void SetSystemAngularAxis(const AVector& systemAngularAxis);
		float GetSystemSizeChange() const;
		void SetSystemSizeChange(float systemSizeChange);

	    // 粒子运动，在该系统的模型空间。速度矢量应为单位的长度。
		// 其中点代表一个刚体在应用程序，
		// 你可以选择该系统的原点为粒子的质量中心和
		// 坐标轴对应于惯性张量的主方向。
		int GetNumParticles() const;
		float GetParticleLinearSpeed(int index) const; 
		const AVector GetParticleLinearAxis(int index) const;
		float GetParticleSizeChange(int index) const;

		void SetParticleLinearSpeed(int index, float particleLinearSpeed);
		void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
		void SetParticleSizeChange(int index, float particleSizeChange);		

		// 动画更新。应用程序时间以毫秒为单位。
		virtual bool Update(double applicationTime) override;
		virtual void SetObject(ControllerInterface* object) override;
		virtual void SetObjectInCopy(ControllerInterface* object) override;
		
	protected:
		// 对于粒子运动数组的延迟分配。
		void Reallocate (int numParticles);   
		
		// 该类从运动参数计算新的位置和方向。
		// 派生类应该更新运动参数，然后要么调用基类的更新方法或在自己的更新方法中提供位置和方向。
		virtual void UpdateSystemMotion (float ctrlTime);
		virtual void UpdatePointMotion (float ctrlTime);

	private:
		IMPL_TYPE_DECLARE(ParticleController);

		Particles* m_Particles;
	};

	CORE_TOOLS_STREAM_REGISTER(ParticleController);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, ParticleController); 
}

#endif // RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H
