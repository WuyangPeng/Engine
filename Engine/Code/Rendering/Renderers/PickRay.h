///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:36)

#ifndef RENDERING_RENDERERS_PICKRAY_H
#define RENDERING_RENDERERS_PICKRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(PickRayImpl);

namespace Rendering
{
    // ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ�
    // ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ����
    // ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
    class RENDERING_DEFAULT_DECLARE PickRay
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(PickRay);
        using ClassType = PickRay;

    public:
        explicit PickRay(CoreTools::DisableNotThrow disableNotThrow);
        PickRay(bool result, const Mathematics::APointF& origin, const Mathematics::AVectorF& direction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsResult() const noexcept;
        NODISCARD Mathematics::APointF GetOrigin() const noexcept;
        NODISCARD Mathematics::AVectorF GetDirection() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PICKRAY_H
