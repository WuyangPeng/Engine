// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/09 17:21)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H

#include "MinimizeN.h"
#include "Minimize1Detail.h"
#include "MinimizeNDataDetail.h"
#include "MinimizeNGetMinimumDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real,typename UserDataType>
Mathematics::MinimizeN<Real,UserDataType>
	::MinimizeN (int dimensions, Function function,int maxLevel,int maxBracket,int maxIterations,const UserDataType* userData)
	:m_Dimensions{ dimensions }, m_Function{ function }, m_MaxLevel{ maxLevel }, m_MaxBracket{ maxBracket }, m_MaxIterations{ maxIterations }, m_UserData{ userData }
{    
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real,typename UserDataType>
bool Mathematics::MinimizeN<Real,UserDataType>
	::IsValid() const noexcept
{
    if(1 <= m_Dimensions && m_Function != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real,typename UserDataType>
typename const Mathematics::MinimizeN<Real, UserDataType>::MinimizeNData Mathematics::MinimizeN<Real,UserDataType>
	::GetMinimum (const RealVector& begin, const RealVector& end,const RealVector& initial) const
{
    MATHEMATICS_CLASS_IS_VALID_1; 

	// ��ʼ�²⡣
	MinimizeNGetMinimum minimizeNGetMinimum{ m_Dimensions, initial, m_Function, m_UserData, begin, end };
  
    for (auto iter = 0; iter < m_MaxIterations; ++iter)
    {
   		// ������ÿ��������Сֵ�����µ�ǰλ�á�
        for (auto index = 0; index < m_Dimensions; ++index)
        {
			minimizeNGetMinimum.FindEachDirection(index,m_MaxLevel,m_MaxBracket);
        }
        
     	// ����һ����λ���ȵĹ����
		auto length = minimizeNGetMinimum.EstimateUnitLengthConjugateDirection();
        if (length < Math<Real>::sm_Epsilon)
        {         
			// �µ�λ�ò�û�дӾɵ�λ���������ı䡣�������Ƿ��и��õ�����׼��
            break;
        }
        
		minimizeNGetMinimum.MinimizeConjugateDirection(length, m_MaxLevel, m_MaxBracket);
    }
    
	return minimizeNGetMinimum.GetMinimizeNData();
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H
