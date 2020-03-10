// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:22)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{ 
    // ����������ĵ㼸��������ģ�ʹ�������
    // �����ʽC'[0]+C'[1]*X+C'[2]*Y+C'[3]*Z+C'[4]*(X^2+Y^2+Z^2)��
    // ����Length(C') = 1
    // �ú�������C = (C'[0]/C'[4],C'[1]/C'[4],C'[2]/C'[4],C'[3]/C'[4])��
    // ����������� C[0]+C[1]*X+C[2]*Y+C[3]*Z+X^2+Y^2+Z^2��
    // ��������(xc,yc,zc) = -0.5*(C[1],C[2],C[3])��
    // �뾶Ϊrad = sqrt(xc*xc+yc*yc+zc*zc-C[0])��	 
    template <typename Real>
    class QuadraticSphereFit3
    {
    public:
		using ClassType = QuadraticSphereFit3<Real>;
        using Vector3D = Vector3D<Real>;
        
    public:
		explicit QuadraticSphereFit3(const std::vector<Vector3D>& points);
        
        CLASS_INVARIANT_DECLARE;
        
        const Vector3D GetCenter() const;
        Real GetRadius() const;
        Real GetEigenValue() const;
        
    private:
        void Calculate(const std::vector<Vector3D>& points);

	private:
		const static int sm_EigenSystemSize = 5;
        
    private:
        Vector3D m_Center;
        Real m_Radius;
        Real m_EigenValue;
    };

	using QuadraticSphereFit3d = QuadraticSphereFit3<double>;
	using QuadraticSphereFit3f = QuadraticSphereFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
