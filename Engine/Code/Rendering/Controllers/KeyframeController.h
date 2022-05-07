///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/07 16:00)

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
        // ���ƽ�ƣ���ת�����Ŷ�������ͬ�Ĺؼ�֡ʱ�䣬��numCommonTimes������Ϊ������
        // ÿ��ʣ������ΪnumCommonTimes����ͨ�����ڣ���Ϊ��ʱ��
        // ����ؼ�֡ʱ�䲻������numCommonTimes��������Ϊ�㣬������������趨Ϊ�ʵ���ֵ
        // ���ŵ�����ʱΪ��ֵ��������ʽΪ�㡣

        // �任�����ʼ�����ƶ���ľֲ��任��
        // ��������ǰ����Ϊ��Ϊ���ֻ���ɹؼ�֡�����ͨ���任��
        // �������������ռ�Spatial m_Object������Ӧ�ó����ʵ�����������ͨ����
        // ����KeyframeController����*����*��ͨ����
        KeyframeController(int numCommonTimes, int numTranslations, int numRotations, int numScales, const TransformF& localTransform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(KeyframeController);

        // ���ù��캯������������������ʹ����Щ������
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

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        // ֧�ֲ��Ҹ���ָ��ʱ��Ĺؼ�֡��
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
