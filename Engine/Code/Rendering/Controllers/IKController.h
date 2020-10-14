// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 10:33)

#ifndef RENDERING_CONTROLLERS_IK_CONTROLLER_H
#define RENDERING_CONTROLLERS_IK_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "IKGoal.h"
#include "IKJoint.h"

RENDERING_EXPORT_SHARED_PTR(IKControllerImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IKController : public Controller
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(IKController, = default);
        using ParentType = Controller;
        using IKJointSharedPtrVector = std::vector<IKJointSharedPtr>;

    public:
        explicit IKController(const IKJointSharedPtrVector& joints);
     

            CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IKController);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 动画更新。应用程序时间以毫秒为单位。
        bool Update(double applicationTime) override;

        ControllerInterfaceSharedPtr Clone() const override;
        ObjectInterfaceSharedPtr CloneObject() const override;

        int GetIterations() const noexcept;
        void SetIterations(int iterations) noexcept;
        bool IsOrderEndToRoot() const noexcept;
        void SetOrderEndToRoot(bool orderEndToRoot) noexcept;

        const IKJointSharedPtr GetJointsSharedPtr(int index);
        int GetJointsNum() const;

    private:
        IMPL_TYPE_DECLARE(IKController);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(IKController);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( IKController);

}
#include STSTEM_WARNING_POP

#endif  // RENDERING_CONTROLLERS_IK_CONTROLLER_H
