// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 10:15)

#ifndef RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/AVector.h"

#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ParticleControllerImpl
    {
    public:
        using ClassType = ParticleControllerImpl;
        using AVector = Mathematics::FloatAVector;

    public:
        explicit ParticleControllerImpl(int numParticles);
        ParticleControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

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

        // 粒子运动，在该系统的模型空间。速度矢量应为单位的长度。
        // 其中点代表一个刚体在应用程序，
        // 你可以选择该系统的原点为粒子的质量中心和
        // 坐标轴对应于惯性张量的主方向。
        int GetNumParticles() const noexcept;
        float GetParticleLinearSpeed(int index) const;
        const AVector GetParticleLinearAxis(int index) const;
        float GetParticleSizeChange(int index) const;

        void SetParticleLinearSpeed(int index, float particleLinearSpeed);
        void SetParticleLinearAxis(int index, const AVector& particleLinearAxis);
        void SetParticleSizeChange(int index, float particleSizeChange);

        int GetStreamingSize() const noexcept;
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        void Load(const CoreTools::BufferSourceSharedPtr& source);

    private:
        // 系统的运动，在局部坐标。速度矢量应为单位的长度。
        float m_SystemLinearSpeed;
        float m_SystemAngularSpeed;
        AVector m_SystemLinearAxis;
        AVector m_SystemAngularAxis;
        float m_SystemSizeChange;

        int m_NumParticles;
        std::vector<float> m_ParticleLinearSpeed;
        std::vector<AVector> m_ParticleLinearAxis;
        std::vector<float> m_ParticleSizeChange;
    };
}

#endif  // RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H
