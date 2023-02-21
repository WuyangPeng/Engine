///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/06 21:15)

#ifndef RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_H
#define RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "TransformController.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(BlendTransformController, BlendTransformControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BlendTransformController : public TransformController
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(BlendTransformController);
        using ParentType = TransformController;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;

    public:
        // �趨'rotationScaleMatrices'Ϊ���桱ʱ,����������������ʽΪ��
        // Y = R * S * X + T������R����ת�任��SΪһ�����ĶԽ������ž���T��ƽ�ƾ���;
        // Ҳ����˵��ÿһ���任����IsRotationScaleMatrix���ڡ��桱��
        // ����������£���ת�ͱ����Ļ�Ͽ����Ǽ��λ����������乹�캯����ָ�����롣
        // ƽ�ƻ��ʼ������������{R0,S0,T0} ��{R1,S1,T1} ��ת��ͨ����
        // Ȩ��w�ڷ�Χ[0,1]����{R,S,T}�ǻ�ϵĽ����
        // ��q0, q1��q��Ӧ��R0��R1��R2��Dot(q0,q1) >= 0 ��
        // A = angle(q0,q1) = acos(Dot(q0,q1))��

        // ƽ��:  T = (1 - w) * T0 + w * T1

        // ������ת:  q = Normalize((1 - w) * q0 + w * q1)
        // ������ת:
        //   q = Slerp(w,q0,q1)
        //     = (sin((1 - w) * A) * q0 + sin(w * A) * q1) / sin(A)

        // ��������:  s = (1 - w) * s0 + w * s1 ��ÿ��ͨ�� s0, s1, s
        // ��������:  s = sign(s0) * sign(s1) * pow(|s0|,1 - w) * pow(|s1|,w)
        //  �������s0��s1���㣬��s���㡣

        // ���á�rotationScaleMatrices'Ϊ'��'ʱ����mIsRotationMatrix��'��'��ÿ���任��
        // ����������£����еı任ʹ�ü�Ȩƽ��ֵ���㡣���ǲ��Ƽ��ģ���Ϊ�Ӿ�Ч��������Ԥ�ϵġ�
        BlendTransformController(const TransformControllerSharedPtr& firstController,
                                 const TransformControllerSharedPtr& secondController,
                                 bool rotationScaleMatrices,
                                 bool geometricRotation = false,
                                 bool geometricScale = false);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BlendTransformController);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // Ȩ��w��һ�����ֵ���0 <= w <= 1��
        NODISCARD ConstTransformControllerSharedPtr GetFirstController() const noexcept;
        NODISCARD ConstTransformControllerSharedPtr GetSecondController() const noexcept;
        NODISCARD bool IsRotationScaleMatrices() const noexcept;
        void SetWeight(float weight) noexcept;
        NODISCARD float GetWeight() const noexcept;

        NODISCARD bool IsGeometricRotation() const noexcept;
        NODISCARD bool IsGeometricScale() const noexcept;

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        // �ԡ�this�����ö��󣬹����������
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(BlendTransformController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BlendTransformController);
}

#endif  // RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_H
