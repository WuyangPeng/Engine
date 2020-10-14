// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/23 10:21)

#ifndef RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_H
#define RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "TransformController.h"

RENDERING_EXPORT_SHARED_PTR(BlendTransformControllerImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BlendTransformController : public TransformController
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(BlendTransformController, = default);
        using ParentType = TransformController;
        using APoint = Mathematics::FloatAPoint;
        using Matrix = Mathematics::FloatMatrix;

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
        BlendTransformController(const TransformControllerSharedPtr& firstController, const TransformControllerSharedPtr& secondController,
                                 bool rotationScaleMatrices, bool geometricRotation = false, bool geometricScale = false);



        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BlendTransformController);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // Ȩ��w��һ�����ֵ���0 <= w <= 1��
        const ConstTransformControllerSharedPtr GetFirstController() const noexcept;
        const ConstTransformControllerSharedPtr GetSecondController() const noexcept;
        bool IsRotationScaleMatrices() const noexcept;
        void SetWeight(float weight) noexcept;
        float GetWeight() const noexcept;

        bool IsGeometricRotation() const noexcept;
        bool IsGeometricScale() const noexcept;

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        bool Update(double applicationTime) override;

        ControllerInterfaceSharedPtr Clone() const override;
        
        ObjectInterfaceSharedPtr CloneObject() const override;

        // �ԡ�this�����ö��󣬹����������
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

    private:
        IMPL_TYPE_DECLARE(BlendTransformController);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(BlendTransformController);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( BlendTransformController);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_H
