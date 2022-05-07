///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/07 16:55)

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
        // �����ӵĶ��������Polypoint��Polypoint�������ࡣ
        explicit PointController(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PointController);

        // ���˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
        // ���е����һ��������Ӧ�ó���
        // �����ѡ���ϵͳ��ԭ��Ϊ����������ĺ�
        // �������Ӧ�ڹ���������������
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

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

    protected:
        // ���ڵ��˶�������ӳٷ��䡣
        void Reallocate(int numPoints);

        // ������˶����������µ�λ�úͷ���
        // ������Ӧ�ø����˶�������Ȼ��Ҫô���û���ĸ��·��������Լ��ĸ��·������ṩλ�úͷ���
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
