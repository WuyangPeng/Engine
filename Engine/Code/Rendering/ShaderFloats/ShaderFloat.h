///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 16:41)

#ifndef RENDERING_SHADER_FLOATS_SHADER_FLOATS_H
#define RENDERING_SHADER_FLOATS_SHADER_FLOATS_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ShaderFloat, ShaderFloatImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderFloat : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ShaderFloat);
        using ParentType = Object;
        using FloatVector = std::vector<float>;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;
        using Colour = Colour<float>;
        using ShaderFloatSharedPtr = std::shared_ptr<ClassType>;
        using ConstShaderFloatSharedPtr = std::shared_ptr<const ClassType>;

    public:
        // 寄存器的数量必须为正数。每个寄存器相当于四个浮点数。
        explicit ShaderFloat(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        explicit ShaderFloat(int numRegisters);
        explicit ShaderFloat(const FloatVector& data);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderFloat);

        // 对于延迟构造。
        virtual void SetNumRegisters(int numRegisters);

        NODISCARD int GetNumRegisters() const;
        NODISCARD const float* GetData() const;
        NODISCARD float* GetData();

        // 由寄存器访问数据。SetRegister从data复制四个浮点值的副本到寄存器index。
        // SetRegisters从data复制mNumElements个浮点值到所有寄存器。
        // 类似的浮点值大小由Get*函数复制。
        void SetRegister(int index, const FloatVector& data);
        void SetRegister(int index, const AVector& vector);
        void SetRegister(int index, const APoint& point);
        void SetRegister(int index, const Colour& colour);
        void SetRegisters(const Matrix& matrix);
        void SetRegisters(const FloatVector& data);
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
        bool AllowUpdater() const noexcept;
        virtual void Update(const Visual* visual, const Camera* camera);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD virtual ShaderFloatSharedPtr Clone() const;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ShaderFloat);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ShaderFloat);
}

#endif  // RENDERING_SHADER_FLOATS_SHADER_FLOATS_H
