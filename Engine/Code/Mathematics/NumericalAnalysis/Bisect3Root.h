// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 15:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// 二分法解方程的根
namespace Mathematics
{
    template <typename Real>
    class Bisect3Root
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect3Root<Real>;
        
    public:
        // 方程无解
        Bisect3Root ();
        // 方程有解
        Bisect3Root (Real xRoot,Real yRoot,Real zRoot,BisectRootType type);
        
		CLASS_INVARIANT_DECLARE;
       
        // 当m_BisectRootType == BisectRootType::HaveSolution时，
        // m_XRoot、m_YRoot、m_ZRoot是有效的。
        // 当m_BisectRootType == BisectRootType::Unknown时，
        // m_XRoot、m_YRoot、m_ZRoot是近似值，不保证结果是正确的。
        // 当m_BisectRootType == BisectRootType::NoSolution时，
        // GetXRoot()、GetYRoot()、GetZRoot()抛出异常。
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
