///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 15:32)

#ifndef RENDERING_RENDERER_ENGINE_PICK_RAY_H
#define RENDERING_RENDERER_ENGINE_PICK_RAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(PickRayImpl);

/// ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ�
/// ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ����
/// ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRay
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(PickRay);

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;

    public:
        PickRay(bool result, const APoint& origin, const AVector& direction);
        NODISCARD static PickRay Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsResult() const noexcept;
        NODISCARD APoint GetOrigin() const noexcept;
        NODISCARD AVector GetDirection() const noexcept;

    private:
        enum class PickRayCreate
        {
            Init,
        };

    public:
        explicit PickRay(PickRayCreate pickRayCreate);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_PICK_RAY_H
