///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 17:33)

#ifndef RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ParticleControllerImpl
    {
    public:
        using ClassType = ParticleControllerImpl;

        using AVector = Mathematics::AVectorF;
        using BaseRendererWeakPtr = std::weak_ptr<BaseRenderer>;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;

    public:
        explicit ParticleControllerImpl(const BaseRendererSharedPtr& baseRenderer) noexcept;
        ParticleControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetSystemLinearSpeed() const noexcept;
        void SetSystemLinearSpeed(float aSystemLinearSpeed) noexcept;
        NODISCARD float GetSystemAngularSpeed() const noexcept;
        void SetSystemAngularSpeed(float aSystemAngularSpeed) noexcept;
        NODISCARD AVector GetSystemLinearAxis() const noexcept;
        void SetSystemLinearAxis(const AVector& aSystemLinearAxis) noexcept;
        NODISCARD AVector GetSystemAngularAxis() const noexcept;
        void SetSystemAngularAxis(const AVector& aSystemAngularAxis) noexcept;
        NODISCARD float GetSystemSizeChange() const noexcept;
        void SetSystemSizeChange(float aSystemSizeChange) noexcept;

        // 粒子运动，在该系统的模型空间。速度矢量应为单位的长度。
        // 其中点代表一个刚体在应用程序，
        // 你可以选择该系统的原点为粒子的质量中心和
        // 坐标轴对应于惯性张量的主方向。
        int GetNumParticles() const noexcept;
        NODISCARD float GetParticleLinearSpeed(int index) const;
        NODISCARD AVector GetParticleLinearAxis(int index) const;
        NODISCARD float GetParticleSizeChange(int index) const;

        void SetParticleLinearSpeed(int index, float particleLinearSpeed);
        void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
        void SetParticleSizeChange(int index, float particleSizeChange);

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

        void SetCamera(const std::shared_ptr<Camera>& aCamera) noexcept;
        NODISCARD std::shared_ptr<Camera> GetCamera() noexcept;

        void SetControllerObject(Visual& visual);

        void UpdateSystemMotion(Particles& particles, float ctrlTime);
        void UpdatePointMotion(Particles& particles, float ctrlTime);

    private:
        // 系统的运动，在局部坐标。速度矢量应为单位的长度。
        float systemLinearSpeed;
        float systemAngularSpeed;
        AVector systemLinearAxis;
        AVector systemAngularAxis;
        float systemSizeChange;

        int numParticles;
        std::vector<float> particleLinearSpeeds;
        std::vector<AVector> particleLinearAxes;
        std::vector<float> particleSizeChanges;

        std::shared_ptr<Camera> camera;
        BaseRendererWeakPtr baseRenderer;
    };
}

#endif  // RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H
