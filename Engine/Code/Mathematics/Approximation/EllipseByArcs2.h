///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/02 17:07)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
namespace Mathematics
{
    // ��ԲΪ(x/a)^2 + (y/b)^2 = 1��
    // �����ڵ�һ�����еĲ���(x >= 0 and y >= 0)���ơ�
    // ����numArcs >= 2 �Ļ������Ӧ������������
    // ��Բ��(a,0) �� (0,b)�ļ�Ȩƽ��ֵ�С�
    // ���ص������������numArcs+1��Ԫ�غ�
    // ��������Բ�ĺͰ뾶ÿ��������numArcԪ�ء�
    // m_Points[i]��m_Points[i+1]������Ļ�
    // ��������m_Center[i]�Ͱ뾶��m_Radius[i]��

    template <typename Real>
    class EllipseByArcs2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<EllipseByArcs2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<EllipseByArcs2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<EllipseByArcs2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE EllipseByArcs2 final
    {
    public:
        using EllipseByArcs2Impl = EllipseByArcs2Impl<Real>;
        
        TYPE_DECLARE(EllipseByArcs2);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using Vector2D = Vector2D<Real>;
        using Arc2 = Arc2<Real>;
        using Circle2 = Circle2<Real>;
        using PointsType = std::vector<Vector2D>;
        using Circle2Container = std::vector<Circle2>;

    public:
        EllipseByArcs2(Real begin, Real end, size_t numArcs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const PointsType GetPoints() const;
        [[nodiscard]] const Circle2Container GetCircle2() const;

        [[nodiscard]] const Arc2 GetArc2(int index) const;
        [[nodiscard]] int getNumArcs() const;

    private:
        PackageType impl;
    };

    using FloatEllipseByArcs2 = EllipseByArcs2<float>;
    using DoubleEllipseByArcs2 = EllipseByArcs2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
