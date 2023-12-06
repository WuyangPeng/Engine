///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/24 11:25)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Transform.h"

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
        explicit TransformController(const Mathematics::TransformF& localTransform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TransformController);

        void SetTransform(const Mathematics::TransformF& localTransform) noexcept;
        NODISCARD Mathematics::TransformF GetTransform() const noexcept;

        void SetTranslate(const APoint& translate) noexcept;
        void SetRotate(const Matrix& rotate) noexcept;
        void SetUniformScale(float scale);
        void SetScale(const APoint& scale);
        void SetMatrix(const Matrix& matrix) noexcept;

        void SetController(const ControllerSharedPtr& object) override;

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        // ���¼򵥵Ŀ���m_LocalTransform��Spatial m_Object��LocalTransform��
        // ����������ϣ�TransformController��ʾһ������ʱ��Ϊ������transform��
        bool Update(double applicationTime) override;

        NODISCARD ControllerSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TransformController);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TransformController);
}

#endif  // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_H
