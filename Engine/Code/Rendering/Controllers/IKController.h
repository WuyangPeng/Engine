///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:02)

#ifndef RENDERING_CONTROLLERS_IK_CONTROLLER_H
#define RENDERING_CONTROLLERS_IK_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "IKGoal.h"
#include "IKJoint.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(IKController, IKControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IKController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(IKController);
        using ParentType = Controller;
        using IKJointSharedPtrVector = std::vector<CoreTools::ObjectAssociated<IKJoint>>;

    public:
        explicit IKController(const IKJointSharedPtrVector& joints);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKController);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD int GetIterations() const noexcept;
        void SetIterations(int iterations) noexcept;
        NODISCARD bool IsOrderEndToRoot() const noexcept;
        void SetOrderEndToRoot(bool orderEndToRoot) noexcept;

        NODISCARD IKJointSharedPtr GetJointsSharedPtr(int index);
        NODISCARD int GetJointsNum() const;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(IKController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(IKController);

}

#endif  // RENDERING_CONTROLLERS_IK_CONTROLLER_H
