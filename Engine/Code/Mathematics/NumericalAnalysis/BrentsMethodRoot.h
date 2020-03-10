// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 15:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class BrentsMethodRoot
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = BrentsMethodRoot<Real>;
        
    public:
        // 方程无解
        BrentsMethodRoot ();
        // 方程有解
        BrentsMethodRoot (Real root,Real function, BrentsMethodRootType type);
        
		CLASS_INVARIANT_DECLARE;  

        Real GetRoot() const;
        Real GetFunction() const;
        BrentsMethodRootType GetBrentsMethodRootType() const;
        
    private:
        Real m_Root;
        Real m_Function;
        BrentsMethodRootType m_BrentsMethodRootType;
    };

    using BrentsMethodRootf = BrentsMethodRoot<float>;
    using BrentsMethodRootd = BrentsMethodRoot<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H
