// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 16:25)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class  RombergIntegral
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = RombergIntegral<Real,UserDataType>;

		// 最后一个参数是用户定义的数据。
		using Function = Real(*)(Real, const UserDataType*);
        
    public:
        RombergIntegral (int order, Real begin, Real end,Function function,const UserDataType* userData);
        ~RombergIntegral();
		RombergIntegral(const RombergIntegral& rhs);
		RombergIntegral& operator=(const RombergIntegral& rhs);
        
        CLASS_INVARIANT_DECLARE;
    
        Real GetValue () const;
        
    private:
        void Calculate();
        
    private:
        int m_Order;
        Real m_Begin;
        Real m_End;
        Function m_Function;
        const UserDataType* m_UserData;
        Real m_Value;
        Real** m_Rom;
    };    
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
