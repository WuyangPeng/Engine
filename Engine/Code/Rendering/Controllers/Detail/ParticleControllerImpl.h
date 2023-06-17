///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/AVector.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ParticleControllerImpl
    {
    public:
        using ClassType = ParticleControllerImpl;
        using AVector = Mathematics::AVectorF;

    public:
        explicit ParticleControllerImpl(int numParticles);
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

        // �����˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
        // ���е����һ��������Ӧ�ó���
        // �����ѡ���ϵͳ��ԭ��Ϊ���ӵ��������ĺ�
        // �������Ӧ�ڹ���������������
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

    private:
        // ϵͳ���˶����ھֲ����ꡣ�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
        float systemLinearSpeed;
        float systemAngularSpeed;
        AVector systemLinearAxis;
        AVector systemAngularAxis;
        float systemSizeChange;

        int numParticles;
        std::vector<float> particleLinearSpeeds;
        std::vector<AVector> particleLinearAxes;
        std::vector<float> particleSizeChanges;
    };
}

#endif  // RENDERING_CONTROLLERS_PARTICLE_CONTROLLER_IMPL_H
