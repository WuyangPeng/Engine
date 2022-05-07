///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/07 16:35)

#ifndef RENDERING_CONTROLLERS_MORPH_CONTROLLER_H
#define RENDERING_CONTROLLERS_MORPH_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "ControllerKeyInfo.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(MorphController, MorphControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MorphController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MorphController);
        using ParentType = Controller;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        // �������Ŀ�����ε�Ŀ�꣬���̶�����������ڵļ���
        // ���캯����һЩ�����������Ĺ�����
        // ÿ��Ŀ�궥�㣬ʱ�䣬��Ȩ�ض���������Ӧ�ĳ�Ա���ʷ��䡣

        // numVertices: ÿ��Ŀ��Ķ�������������е�Ŀ�������ͬ�����Ķ��㡣

        // numTargets:  ���ε�Ŀ����

        // numKeys:  ������Ŀ��ÿ����������һ���ض���ʱ�䡣

        MorphController(int numVertices, int numTargets, int numKeys);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MorphController);

        // ���ù��캯����������ʹ����Щ�������ö������飬ʱ���Ȩ�ء�
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumTargets() const noexcept;
        NODISCARD int GetNumKeys() const noexcept;
        NODISCARD APoint GetVertices(int target, int vertices) const;
        NODISCARD float GetTimes(int key) const;
        NODISCARD float GetWeights(int key, int target) const;

        void SetVertices(int target, int vertices, const APoint& point);
        void SetTimes(int key, float times);
        void SetWeights(int key, int target, float weights);

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        // ���ұ߽��ϵļ���
        NODISCARD ControllerKeyInfo GetKeyInfo(float ctrlTime) noexcept;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(MorphController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(MorphController);
}

#endif  // RENDERING_CONTROLLERS_MORPH_CONTROLLER_H
