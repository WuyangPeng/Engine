///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 16:00)

#ifndef RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H
#define RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "ControllerKeyInfo.h"
#include "TransformController.h"
#include "Mathematics/Algebra/AQuaternion.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(KeyframeController, KeyframeControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE KeyframeController : public TransformController
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(KeyframeController);
        using ParentType = TransformController;
        using Matrix = Mathematics::MatrixF;
        using AQuaternion = Mathematics::AQuaternionF;
        using APoint = Mathematics::APointF;

    public:
        // 如果平移，旋转和缩放都有着相同的关键帧时间，则numCommonTimes被设置为正数。
        // 每个剩余数量为numCommonTimes，当通道存在，或为零时。
        // 如果关键帧时间不共享，则numCommonTimes必须设置为零，而其余的数字设定为适当的值
        // 当信道存在时为正值和其他方式为零。

        // 变换输入初始化控制对象的局部变换。
        // 这个类的以前的行为是为了填补只能由关键帧代表的通道变换，
        // 其中隐含依靠空间Spatial m_Object有它的应用程序适当地设置其他通道。
        // 现在KeyframeController设置*所有*的通道。
        KeyframeController(int numCommonTimes, int numTranslations, int numRotations, int numScales, const TransformF& localTransform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(KeyframeController);

        // 调用构造函数后，您必须设置数据使用这些函数。
        NODISCARD int GetNumCommonTimes() const noexcept;
        NODISCARD float GetCommonTimes(int index) const;
        void SetCommonTimes(int index, float commonTimes);

        NODISCARD int GetNumTranslations() const noexcept;
        NODISCARD float GetTranslationTimes(int index) const;
        NODISCARD APoint GetTranslations(int index) const;

        void SetTranslationTimes(int index, float translationTimes);
        void SetTranslations(int index, const APoint& translations);

        NODISCARD int GetNumRotations() const noexcept;
        NODISCARD float GetRotationTimes(int index) const;
        NODISCARD AQuaternion GetRotations(int index) const;

        void SetRotationTimes(int index, float rotationTimes);
        void SetRotations(int index, const AQuaternion& rotations);

        NODISCARD int GetNumScales() const noexcept;
        NODISCARD float GetScaleTimes(int index) const;
        NODISCARD float GetScales(int index) const;

        void SetScaleTimes(int index, float scaleTimes);
        void SetScales(int index, float scales);

        // 动画更新。应用程序时间以毫秒为单位。
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        // 支持查找给出指定时间的关键帧。
        NODISCARD ControllerKeyInfo GetTranslateKeyInfo(float ctrlTime);
        NODISCARD ControllerKeyInfo GetRotateKeyInfo(float ctrlTime);
        NODISCARD ControllerKeyInfo GetScaleKeyInfo(float ctrlTime);
        NODISCARD ControllerKeyInfo GetCommonKeyInfo(float ctrlTime);

        NODISCARD APoint GetTranslate(const ControllerKeyInfo& keyInfo) const;
        NODISCARD Matrix GetRotate(const ControllerKeyInfo& keyInfo) const noexcept;
        NODISCARD float GetScale(const ControllerKeyInfo& keyInfo) const noexcept;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(KeyframeController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(KeyframeController);
}

#endif  // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_H
