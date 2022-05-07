///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 16:55)

#ifndef RENDERING_CONTROLLERS_POINT_CONTROLLER_H
#define RENDERING_CONTROLLERS_POINT_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(PointController, PointControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PointController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(PointController);
        using ParentType = Controller;
        using AVector = Mathematics::AVectorF;

    public:
        // 所连接的对象必须是Polypoint或Polypoint派生的类。
        explicit PointController(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PointController);

        // 点运动，在该系统的模型空间。速度矢量应为单位的长度。
        // 其中点代表一个刚体在应用程序，
        // 你可以选择该系统的原点为点的质量中心和
        // 坐标轴对应于惯性张量的主方向。
        NODISCARD int GetNumPoints() const noexcept;
        NODISCARD float GetPointLinearSpeed(int index) const;
        NODISCARD float GetPointAngularSpeed(int index) const;
        NODISCARD AVector GetPointLinearAxis(int index) const;
        NODISCARD AVector GetPointAngularAxis(int index) const;

        void SetPointLinearSpeed(int index, float pointLinearSpeed);
        void SetPointAngularSpeed(int index, float pointAngularSpeed);
        void SetPointLinearAxis(int index, const AVector& pointLinearAxis);
        void SetPointAngularAxis(int index, const AVector& pointAngularAxis);

        NODISCARD float GetSystemLinearSpeed() const noexcept;
        void SetSystemLinearSpeed(float systemLinearSpeed) noexcept;
        NODISCARD float GetSystemAngularSpeed() const noexcept;
        void SetSystemAngularSpeed(float systemAngularSpeed) noexcept;
        NODISCARD AVector GetSystemLinearAxis() const noexcept;
        void SetSystemLinearAxis(const AVector& systemLinearAxis) noexcept;
        NODISCARD AVector GetSystemAngularAxis() const noexcept;
        void SetSystemAngularAxis(const AVector& systemAngularAxis) noexcept;

        // 动画更新。应用程序时间以毫秒为单位。
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

    protected:
        // 对于点运动数组的延迟分配。
        void Reallocate(int numPoints);

        // 该类从运动参数计算新的位置和方向。
        // 派生类应该更新运动参数，然后要么调用基类的更新方法或在自己的更新方法中提供位置和方向。
        virtual void UpdateSystemMotion(float ctrlTime);
        virtual void UpdatePointMotion(float ctrlTime);

    private:
        PackageType impl;

        Polypoint* points;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(PointController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(PointController);
}

#endif  // RENDERING_CONTROLLERS_POINT_CONTROLLER_H
