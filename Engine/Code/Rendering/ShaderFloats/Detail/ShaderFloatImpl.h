///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/07 18:15)

#ifndef RENDERING_SHADER_FLOATS_SHADER_FLOATS_IMPL_H
#define RENDERING_SHADER_FLOATS_SHADER_FLOATS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Colour.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderFloatImpl
    {
    public:
        using ClassType = ShaderFloatImpl;
        using FloatVector = std::vector<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;
        using Colour = Colour<float>;

    public:
        // �Ĵ�������������Ϊ������ÿ���Ĵ����൱���ĸ���������
        ShaderFloatImpl() noexcept;
        explicit ShaderFloatImpl(int numRegisters);
        explicit ShaderFloatImpl(const FloatVector& data);

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        // �����ӳٹ��졣
        void SetNumRegisters(int numRegisters);

        NODISCARD int GetNumRegisters() const;
        NODISCARD const float* GetData() const;
        NODISCARD float* GetData();

        // �ɼĴ����������ݡ�SetRegister��data�����ĸ�����ֵ�ĸ������Ĵ���index��
        // SetRegisters��data����mNumElements������ֵ�����мĴ�����
        // ���Ƶĸ���ֵ��С��Get*�������ơ�
        void SetRegister(int index, const FloatVector& aData);
        void SetRegister(int index, const AVector& vector);
        void SetRegister(int index, const APoint& point);
        void SetRegister(int index, const Colour& colour);
        void SetRegisters(const FloatVector& aData);
        void SetRegisters(const Matrix& matrix);
        NODISCARD FloatVector GetRegister(int index) const;
        NODISCARD FloatVector GetRegisters() const;

        // �������������ݡ�
        NODISCARD const float& operator[](int index) const;
        NODISCARD float& operator[](int index);

        // �ú���������ɫ�������Ķ�̬��������Ⱦ������VisualEffectInput::Enable������
        // ��ˣ����ݴ��͵���ɫ�����򾡿���������Ⱦͨ��������
        // �����ڻ�ͼ�����޸����������ȫ��Ч��ʱ�ǳ����á�
        void EnableUpdater() noexcept;
        void DisableUpdater() noexcept;
        NODISCARD bool AllowUpdater() const noexcept;

    private:
        static constexpr auto floatingPointSize = 4;

    private:
        FloatVector data;
        bool allowUpdater;
    };
}

#endif  // RENDERING_SHADER_FLOATS_SHADER_FLOATS_IMPL_H
