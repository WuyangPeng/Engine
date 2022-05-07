///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/07 17:07)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TransformController, TransformControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TransformController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TransformController);
        using ParentType = Controller;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;

    public:
        explicit TransformController(const TransformF& localTransform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TransformController);

        void SetTransform(const TransformF& localTransform) noexcept;
        NODISCARD TransformF GetTransform() const noexcept;

        void SetTranslate(const APoint& translate) noexcept;
        void SetRotate(const Matrix& rotate) noexcept;
        void SetUniformScale(float scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        void SetScale(const APoint& scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        void SetMatrix(const Matrix& matrix) noexcept;

        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        // ���¼򵥵Ŀ���m_LocalTransform��Spatial m_Object��LocalTransform��
        // ����������ϣ�TransformController��ʾһ������ʱ��Ϊ������transform��
        bool Update(double applicationTime) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TransformController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TransformController);
}

#endif  // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
