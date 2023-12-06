///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 19:02)

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
        // 所连接的对象必须是Particles。
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

        // 粒子运动，在该系统的模型空间。速度矢量应为单位的长度。
        // 其中点代表一个刚体在应用程序，
        // 你可以选择该系统的原点为粒子的质量中心和
        // 坐标轴对应于惯性张量的主方向。
        NODISCARD int GetNumParticles() const noexcept;
        NODISCARD float GetParticleLinearSpeed(int index) const;
        NODISCARD AVector GetParticleLinearAxis(int index) const;
        NODISCARD float GetParticleSizeChange(int index) const;

        void SetParticleLinearSpeed(int index, float particleLinearSpeed);
        void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
        void SetParticleSizeChange(int index, float particleSizeChange);

        // 动画更新。应用程序时间以毫秒为单位。
        NODISCARD bool Update(double applicationTime) override;
        void SetController(const ControllerSharedPtr& object) override;

        void SetCamera(const std::shared_ptr<Camera>& aCamera) noexcept;
        NODISCARD std::shared_ptr<Camera> GetCamera() noexcept;

    protected:
        // 该类从运动参数计算新的位置和方向。
        // 派生类应该更新运动参数，然后要么调用基类的更新方法或在自己的更新方法中提供位置和方向。
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
