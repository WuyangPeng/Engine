// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 15:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// ���ַ��ⷽ�̵ĸ�
namespace Mathematics
{
    template <typename Real>
    class Bisect3Root
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect3Root<Real>;
        
    public:
        // �����޽�
        Bisect3Root ();
        // �����н�
        Bisect3Root (Real xRoot,Real yRoot,Real zRoot,BisectRootType type);
        
		CLASS_INVARIANT_DECLARE;
       
        // ��m_BisectRootType == BisectRootType::HaveSolutionʱ��
        // m_XRoot��m_YRoot��m_ZRoot����Ч�ġ�
        // ��m_BisectRootType == BisectRootType::Unknownʱ��
        // m_XRoot��m_YRoot��m_ZRoot�ǽ���ֵ������֤�������ȷ�ġ�
        // ��m_BisectRootType == BisectRootType::NoSolutionʱ��
        // GetXRoot()��GetYRoot()��GetZRoot()�׳��쳣��
        Real GetXRoot() const;
        Real GetYRoot() const;
        Real GetZRoot() const;
        BisectRootType GetBisectRootType() const;
        
    private:
        Real m_XRoot;
        Real m_YRoot;
        Real m_ZRoot;
        BisectRootType m_BisectRootType;
    };

    using Bisect3Rootf = Bisect3Root<float>;
    using Bisect3Rootd = Bisect3Root<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
