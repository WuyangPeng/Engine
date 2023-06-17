///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_PICKRAY_IMPL_H
#define RENDERING_RENDERERS_PICKRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
    // ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ�
    // ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ����
    // ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
    class RENDERING_HIDDEN_DECLARE PickRayImpl
    {
    public:
        using ClassType = PickRayImpl;

    public:
        PickRayImpl() noexcept;
        PickRayImpl(bool result, const Mathematics::APointF& origin, const Mathematics::AVectorF& direction) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsResult() const noexcept;
        NODISCARD Mathematics::APointF GetOrigin() const noexcept;
        NODISCARD Mathematics::AVectorF GetDirection() const noexcept;

    private:
        bool result;
        Mathematics::APointF origin;
        Mathematics::AVectorF direction;
    };
}

#endif  // RENDERING_RENDERERS_PICKRAY_IMPL_H
