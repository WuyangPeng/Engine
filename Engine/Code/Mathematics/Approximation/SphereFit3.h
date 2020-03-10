// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:22)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
	// ��һ������С���������
	// ��������Ĵ����ѳ���maxIterations������һ�����ԡ��������ӵ��������������
	// ���initialCenterIsAverage����Ϊ���桱��
	// �����������ĵĳ�ʼ�²������ݵ��ƽ��ֵ��
	// ������ݵ���һ������ǵ�Ⱥ����SphereFit3�������ٶȺ�����
	// ���initialCenterIsAverage����Ϊ���١���
	// �������ĵĳ�ʼֵ�²�ʹ��һ��������η��̣�
	// ��ʾһ�������ϵ������С���˷������㡣
	// ��������������Ѹ�������� 
	template <typename Real>
	class SphereFit3
    {
    public:
		using ClassType = SphereFit3<Real>;
        using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
        
    public:
		SphereFit3(const std::vector<Vector3D>& points,int maxIterations,bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;
        
		const Sphere3 GetSphere() const;
        
    private:
        void Calculate(const std::vector<Vector3D>& points,int maxIterations,bool initialCenterIsAverage);
		const Vector3D GetAveragePoint(const std::vector<Vector3D>& points);
		void Iteration(const std::vector<Vector3D>& points, const Vector3D& average);

    private:
		Sphere3 m_Sphere;
    };

	using SphereFit3d = SphereFit3<double>;
	using SphereFit3f = SphereFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
