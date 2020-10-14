// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 10:21)

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
        // 设定'rotationScaleMatrices'为“真”时,输入控制器管理的形式为：
        // Y = R * S * X + T，其中R是旋转变换，S为一个正的对角线缩放矩阵，T是平移矩阵;
        // 也就是说，每一个变换具有IsRotationScaleMatrix等于“真”。
        // 在这种情况下，旋转和比例的混合可以是几何或算术，在其构造函数中指定输入。
        // 平移混合始终是算术。让{R0,S0,T0} 和{R1,S1,T1} 是转换通道，
        // 权重w在范围[0,1]。让{R,S,T}是混合的结果。
        // 让q0, q1和q对应于R0，R1和R2与Dot(q0,q1) >= 0 和
        // A = angle(q0,q1) = acos(Dot(q0,q1))。

        // 平移:  T = (1 - w) * T0 + w * T1

        // 算术旋转:  q = Normalize((1 - w) * q0 + w * q1)
        // 几何旋转:
        //   q = Slerp(w,q0,q1)
        //     = (sin((1 - w) * A) * q0 + sin(w * A) * q1) / sin(A)

        // 算术缩放:  s = (1 - w) * s0 + w * s1 对每个通道 s0, s1, s
        // 几何缩放:  s = sign(s0) * sign(s1) * pow(|s0|,1 - w) * pow(|s1|,w)
        //  如果其中s0或s1是零，则s是零。

        // 设置“rotationScaleMatrices'为'假'时，当mIsRotationMatrix是'假'对每个变换。
        // 在这种情况下，所有的变换使用加权平均值计算。这是不推荐的，因为视觉效果是难以预料的。
        BlendTransformController(const TransformControllerSharedPtr& firstController, const TransformControllerSharedPtr& secondController,
                                 bool rotationScaleMatrices, bool geometricRotation = false, bool geometricScale = false);



        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BlendTransformController);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 权重w是一个数字的量0 <= w <= 1。
        const ConstTransformControllerSharedPtr GetFirstController() const noexcept;
        const ConstTransformControllerSharedPtr GetSecondController() const noexcept;
        bool IsRotationScaleMatrices() const noexcept;
        void SetWeight(float weight) noexcept;
        float GetWeight() const noexcept;

        bool IsGeometricRotation() const noexcept;
        bool IsGeometricScale() const noexcept;

        // 动画更新。应用程序时间以毫秒为单位。
        bool Update(double applicationTime) override;

        ControllerInterfaceSharedPtr Clone() const override;
        
        ObjectInterfaceSharedPtr CloneObject() const override;

        // 对“this”设置对象，管理控制器。
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
