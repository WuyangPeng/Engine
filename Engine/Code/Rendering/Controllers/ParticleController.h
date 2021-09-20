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
EXPORT_SHARED_PTR(Rendering, ParticleControllerImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{	
	class Particles;

	class RENDERING_DEFAULT_DECLARE ParticleController : public Controller
	{
	public:
            void Swap(ParticleController& rhs) noexcept;
            
                public:
                    TYPE_DECLARE(ParticleController);
                    using ClassShareType = CoreTools::CopyUnsharedClasses;
                    ~ParticleController() noexcept= default;
                    ParticleController(const ParticleController& rhs);
                    ParticleController& operator=(const ParticleController& rhs);
                    ParticleController(ParticleController&& rhs) noexcept;
                    ParticleController& operator=(ParticleController&& rhs) noexcept;
		using ParentType = Controller;
		using AVector = Mathematics::FloatAVector;

	public:
		// �����ӵĶ��������Particles��
		ParticleController();
		  

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ParticleController); 
		
		float GetSystemLinearSpeed() const noexcept;
		void SetSystemLinearSpeed(float systemLinearSpeed) noexcept;
		float GetSystemAngularSpeed() const noexcept;
		void SetSystemAngularSpeed(float systemAngularSpeed) noexcept;
		const AVector GetSystemLinearAxis() const noexcept;
		void SetSystemLinearAxis(const AVector& systemLinearAxis) noexcept;
		const AVector GetSystemAngularAxis() const noexcept;
		void SetSystemAngularAxis(const AVector& systemAngularAxis) noexcept;
		float GetSystemSizeChange() const noexcept;
		void SetSystemSizeChange(float systemSizeChange) noexcept;

	    // �����˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
		// ���е����һ��������Ӧ�ó���
		// �����ѡ���ϵͳ��ԭ��Ϊ���ӵ��������ĺ�
		// �������Ӧ�ڹ���������������
		int GetNumParticles() const noexcept;
		float GetParticleLinearSpeed(int index) const; 
		const AVector GetParticleLinearAxis(int index) const;
		float GetParticleSizeChange(int index) const;

		void SetParticleLinearSpeed(int index, float particleLinearSpeed);
		void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
		void SetParticleSizeChange(int index, float particleSizeChange);		

		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		 bool Update(double applicationTime) override;
		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;
		
	protected:
		// ���������˶�������ӳٷ��䡣
		void Reallocate (int numParticles);   
		
		// ������˶����������µ�λ�úͷ���
		// ������Ӧ�ø����˶�������Ȼ��Ҫô���û���ĸ��·��������Լ��ĸ��·������ṩλ�úͷ���
		virtual void UpdateSystemMotion (float ctrlTime);
		virtual void UpdatePointMotion (float ctrlTime);

	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;

		Particles* m_Particles;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(ParticleController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( ParticleController); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H
