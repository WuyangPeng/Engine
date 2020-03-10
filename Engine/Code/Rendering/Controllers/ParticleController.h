// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:36)

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
		// �����ӵĶ��������Particles��
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

	    // �����˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
		// ���е����һ��������Ӧ�ó���
		// �����ѡ���ϵͳ��ԭ��Ϊ���ӵ��������ĺ�
		// �������Ӧ�ڹ���������������
		int GetNumParticles() const;
		float GetParticleLinearSpeed(int index) const; 
		const AVector GetParticleLinearAxis(int index) const;
		float GetParticleSizeChange(int index) const;

		void SetParticleLinearSpeed(int index, float particleLinearSpeed);
		void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
		void SetParticleSizeChange(int index, float particleSizeChange);		

		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		virtual bool Update(double applicationTime) override;
		virtual void SetObject(ControllerInterface* object) override;
		virtual void SetObjectInCopy(ControllerInterface* object) override;
		
	protected:
		// ���������˶�������ӳٷ��䡣
		void Reallocate (int numParticles);   
		
		// ������˶����������µ�λ�úͷ���
		// ������Ӧ�ø����˶�������Ȼ��Ҫô���û���ĸ��·��������Լ��ĸ��·������ṩλ�úͷ���
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
