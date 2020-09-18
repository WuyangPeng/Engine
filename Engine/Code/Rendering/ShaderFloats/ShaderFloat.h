// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/23 17:18)

#ifndef RENDERING_SHADER_FLOATS_SHADER_FLOATS_H
#define RENDERING_SHADER_FLOATS_SHADER_FLOATS_H

#include "Rendering/RenderingDll.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Colour.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(ShaderFloatImpl);

namespace Rendering
{
    class Camera;
    class Visual;

    class RENDERING_DEFAULT_DECLARE ShaderFloat : public CoreTools::Object
    {
    public:
        OLD_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ShaderFloat);
        using ParentType = Object;
        using FloatVector = std::vector<float>;
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;
        using Matrix = Mathematics::FloatMatrix;
        using Colour = Colour<float>;
        using ShaderFloatSmartPointer = std::shared_ptr<ClassType>;
        using ConstShaderFloatSmartPointer = std::shared_ptr<const ClassType>;

    public:
        // �Ĵ�������������Ϊ������ÿ���Ĵ����൱���ĸ���������
        ShaderFloat();
        explicit ShaderFloat(int numRegisters);
        explicit ShaderFloat(const FloatVector& data);
        ~ShaderFloat();

        #include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
        ShaderFloat(ShaderFloat&&) noexcept = default;
        ShaderFloat& operator=(ShaderFloat&&) noexcept = default;
        		   #include STSTEM_WARNING_POP

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderFloat);

        // �����ӳٹ��졣
        virtual void SetNumRegisters(int numRegisters);

        int GetNumRegisters() const;
        const float* GetData() const;
        float* GetData();

        // �ɼĴ����������ݡ�SetRegister��data�����ĸ�����ֵ�ĸ������Ĵ���index��
        // SetRegisters��data����mNumElements������ֵ�����мĴ�����
        // ���Ƶĸ���ֵ��С��Get*�������ơ�
        void SetRegister(int index, const FloatVector& data);
        void SetRegister(int index, const AVector& vector);
        void SetRegister(int index, const APoint& point);
        void SetRegister(int index, const Colour& colour);
        void SetRegisters(const Matrix& matrix);
        void SetRegisters(const FloatVector& data);
        const FloatVector GetRegister(int index) const;
        const FloatVector GetRegisters() const;

        // �������������ݡ�
        const float& operator[](int index) const;
        float& operator[](int index);

        // �ú���������ɫ�������Ķ�̬��������Ⱦ������VisualEffectInput::Enable������
        // ��ˣ����ݴ��͵���ɫ�����򾡿���������Ⱦͨ��������
        // �����ڻ�ͼ�����޸����������ȫ��Ч��ʱ�ǳ����á�
        void EnableUpdater();
        void DisableUpdater();
        bool AllowUpdater() const;
        virtual void Update(const Visual* visual, const Camera* camera);
        ObjectInterfaceSharedPtr CloneObject() const override;
        virtual ShaderFloatSmartPointer Clone() const;

    private:
        IMPL_TYPE_DECLARE(ShaderFloat);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ShaderFloat);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ShaderFloat);
}

#endif  // RENDERING_SHADER_FLOATS_SHADER_FLOATS_H
