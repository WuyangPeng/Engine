// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 15:51)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real,typename UserDataType>
    class  GaussianQuadrature
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = GaussianQuadrature<Real,UserDataType>;
   
        // 最后一个参数是用户定义的数据。
        typedef Real (*Function)(Real,const UserDataType*);
        
    public:
        GaussianQuadrature (Real begin, Real end,Function function,const UserDataType* userData);
           
        CLASS_INVARIANT_DECLARE;
    
        Real GetResult () const;
        
    private:
        void Calculate();
        
    private:
		Real m_Radius;
		Real m_Center;
        Function m_Function;
        const UserDataType* m_UserData;
        Real m_Result;
    };     
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
