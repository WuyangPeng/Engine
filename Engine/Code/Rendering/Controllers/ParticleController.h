///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/24 19:02)

#ifndef RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H
#define RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/SceneGraph/Particles.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ParticleController, ParticleControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ParticleController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ParticleController);
        using ParentType = Controller;

        using AVector = Mathematics::AVectorF;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;

    public:
        // �����ӵĶ��������Particles��
        explicit ParticleController(const BaseRendererSharedPtr& baseRenderer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ParticleController);

        NODISCARD float GetSystemLinearSpeed() const noexcept;
        void SetSystemLinearSpeed(float systemLinearSpeed) noexcept;
        NODISCARD float GetSystemAngularSpeed() const noexcept;
        void SetSystemAngularSpeed(float systemAngularSpeed) noexcept;
        NODISCARD AVector GetSystemLinearAxis() const noexcept;
        void SetSystemLinearAxis(const AVector& systemLinearAxis) noexcept;
        NODISCARD AVector GetSystemAngularAxis() const noexcept;
        void SetSystemAngularAxis(const AVector& systemAngularAxis) noexcept;
        NODISCARD float GetSystemSizeChange() const noexcept;
        void SetSystemSizeChange(float systemSizeChange) noexcept;

        // �����˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
        // ���е����һ��������Ӧ�ó���
        // �����ѡ���ϵͳ��ԭ��Ϊ���ӵ��������ĺ�
        // �������Ӧ�ڹ���������������
        NODISCARD int GetNumParticles() const noexcept;
        NODISCARD float GetParticleLinearSpeed(int index) const;
        NODISCARD AVector GetParticleLinearAxis(int index) const;
        NODISCARD float GetParticleSizeChange(int index) const;

        void SetParticleLinearSpeed(int index, float particleLinearSpeed);
        void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
        void SetParticleSizeChange(int index, float particleSizeChange);

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;
        void SetController(const ControllerSharedPtr& object) override;

        void SetCamera(const std::shared_ptr<Camera>& aCamera) noexcept;
        NODISCARD std::shared_ptr<Camera> GetCamera() noexcept;

    protected:
        // ������˶����������µ�λ�úͷ���
        // ������Ӧ�ø����˶�������Ȼ��Ҫô���û���ĸ��·��������Լ��ĸ��·������ṩλ�úͷ���
        virtual void UpdateSystemMotion(float ctrlTime);
        virtual void UpdatePointMotion(float ctrlTime);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ParticleController);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ParticleController);
}

#endif  // RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_H
