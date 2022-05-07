///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:15)

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
        // 寄存器的数量必须为正数。每个寄存器相当于四个浮点数。
        ShaderFloatImpl() noexcept;
        explicit ShaderFloatImpl(int numRegisters);
        explicit ShaderFloatImpl(const FloatVector& data);

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        // 对于延迟构造。
        void SetNumRegisters(int numRegisters);

        NODISCARD int GetNumRegisters() const;
        NODISCARD const float* GetData() const;
        NODISCARD float* GetData();

        // 由寄存器访问数据。SetRegister从data复制四个浮点值的副本到寄存器index。
        // SetRegisters从data复制mNumElements个浮点值到所有寄存器。
        // 类似的浮点值大小由Get*函数复制。
        void SetRegister(int index, const FloatVector& aData);
        void SetRegister(int index, const AVector& vector);
        void SetRegister(int index, const APoint& point);
        void SetRegister(int index, const Colour& colour);
        void SetRegisters(const FloatVector& aData);
        void SetRegisters(const Matrix& matrix);
        NODISCARD FloatVector GetRegister(int index) const;
        NODISCARD FloatVector GetRegisters() const;

        // 按索引访问数据。
        NODISCARD const float& operator[](int index) const;
        NODISCARD float& operator[](int index);

        // 该函数允许着色器常量的动态更新在渲染器调用VisualEffectInput::Enable函数。
        // 因此，数据传送到着色器程序尽可能晚在渲染通道发生。
        // 这是在绘图调用修改摄像机设置全局效果时非常有用。
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
