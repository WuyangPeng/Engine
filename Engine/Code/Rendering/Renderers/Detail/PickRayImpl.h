// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.3.0 (2020/03/27 10:01)

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
        PickRayImpl(bool result, const Mathematics::FloatAPoint& origin, const Mathematics::FloatAVector& direction) noexcept;

        CLASS_INVARIANT_DECLARE;

        bool IsResult() const noexcept;
        Mathematics::FloatAPoint GetOrigin() const noexcept;
        Mathematics::FloatAVector GetDirection() const noexcept;

    private:
        bool m_Result;
        Mathematics::FloatAPoint m_Origin;
        Mathematics::FloatAVector m_Direction; 
    };
}

#endif  // RENDERING_RENDERERS_PICKRAY_IMPL_H