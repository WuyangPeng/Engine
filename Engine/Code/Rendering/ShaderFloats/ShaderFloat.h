// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 17:18)

#ifndef RENDERING_SHADER_FLOATS_SHADER_FLOATS_H
#define RENDERING_SHADER_FLOATS_SHADER_FLOATS_H

#include "Rendering/RenderingDll.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Colour.h"

#include <vector>
EXPORT_SHARED_PTR(Rendering, ShaderFloatImpl, RENDERING_DEFAULT_DECLARE); 
namespace Rendering
{
    class Camera;
    class Visual;

    class RENDERING_DEFAULT_DECLARE ShaderFloat : public CoreTools::Object
    {
    public:
    public:
        void Swap(ShaderFloat& rhs) noexcept;

    public:
        TYPE_DECLARE(ShaderFloat);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~ShaderFloat() noexcept;
        ShaderFloat(const ShaderFloat& rhs);
        ShaderFloat& operator=(const ShaderFloat& rhs);
        ShaderFloat(ShaderFloat&& rhs) noexcept;
        ShaderFloat& operator=(ShaderFloat&& rhs) noexcept;

        using ParentType = Object;
        using FloatVector = std::vector<float>;
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;
        using Matrix = Mathematics::FloatMatrix;
        using Colour = Colour<float>;
        using ShaderFloatSharedPtr = std::shared_ptr<ClassType>;
        using ConstShaderFloatSharedPtr = std::shared_ptr<const ClassType>;

    public:
        // 寄存器的数量必须为正数。每个寄存器相当于四个浮点数。
        ShaderFloat();
        explicit ShaderFloat(int numRegisters);
        explicit ShaderFloat(const FloatVector& data);
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderFloat);

        // 对于延迟构造。
        virtual void SetNumRegisters(int numRegisters);

        int GetNumRegisters() const;
        const float* GetData() const;
        float* GetData();

        // 由寄存器访问数据。SetRegister从data复制四个浮点值的副本到寄存器index。
        // SetRegisters从data复制mNumElements个浮点值到所有寄存器。
        // 类似的浮点值大小由Get*函数复制。
        void SetRegister(int index, const FloatVector& data);
        void SetRegister(int index, const AVector& vector);
        void SetRegister(int index, const APoint& point);
        void SetRegister(int index, const Colour& colour);
        void SetRegisters(const Matrix& matrix);
        void SetRegisters(const FloatVector& data);
        const FloatVector GetRegister(int index) const;
        const FloatVector GetRegisters() const;

        // 按索引访问数据。
        const float& operator[](int index) const;
        float& operator[](int index);

        // 该函数允许着色器常量的动态更新在渲染器调用VisualEffectInput::Enable函数。
        // 因此，数据传送到着色器程序尽可能晚在渲染通道发生。
        // 这是在绘图调用修改摄像机设置全局效果时非常有用。
        void EnableUpdater();
        void DisableUpdater();
        bool AllowUpdater() const;
        virtual void Update(const Visual* visual, const Camera* camera);
        ObjectInterfaceSharedPtr CloneObject() const override;
        virtual ShaderFloatSharedPtr Clone() const;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ShaderFloat);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( ShaderFloat);
}

#endif  // RENDERING_SHADER_FLOATS_SHADER_FLOATS_H
