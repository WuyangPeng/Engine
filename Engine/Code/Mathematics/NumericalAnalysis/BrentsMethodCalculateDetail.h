// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/09 16:13)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_DETAIL_H

#include "BrentsMethodCalculate.h"
#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real,typename UserDataType>
Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::BrentsMethodCalculate (const BrentsMethod& brentsMethod, Real begin, Real end)
	:m_BrentsMethod{ brentsMethod },m_Begin{ begin },m_End{ end },
	 m_BeginFunction{ m_BrentsMethod.GetFunctionValue(m_Begin) }, m_EndFunction{ m_BrentsMethod.GetFunctionValue(m_End) }, m_Bisect2Root{},
	 m_SearchBegin{},m_SearchEnd{},m_SearchFunction{},m_PreviousBisected{ true },	 
	 m_BeginEndFunctionDifference{},m_BeginSearchFunctionDifference{},m_EndSearchFunctionDifference{},	 
	 m_Solution{}, m_SolutionFunction{}
{
    Calculate();
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::IsValid() const noexcept
{
    return true;    
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real,typename UserDataType>
typename const Mathematics::BrentsMethodCalculate<Real,UserDataType>::BrentsMethodRoot Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::GetRoot ()
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Bisect2Root;
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::Calculate()
{
    if(IsBeginSatisfyConditions())
	{
	    // �ö˵������㺯������Ľ��Ƹ���
		m_Bisect2Root = BrentsMethodRoot{ m_Begin,m_BeginFunction,BrentsMethodRootType::HaveSolution };
	}
	else if (IsEndSatisfyConditions())
	{
		// �ö˵������㺯������Ľ��Ƹ���
		m_Bisect2Root = BrentsMethodRoot{ m_End, m_EndFunction,BrentsMethodRootType::HaveSolution };
	}
	else if (m_BeginFunction * m_EndFunction < Real{})
	{
		Search();		
	}    
}
                       
// private
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::IsBeginSatisfyConditions() const
{    
    if (m_BrentsMethod.GetNegativeFTolerance() <= m_BeginFunction && m_BeginFunction <= m_BrentsMethod.GetPositiveFTolerance())
    {              
        return true;
    }
    else
    {
        return false;
    }
}

// private
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::IsEndSatisfyConditions() const
{
    if (m_BrentsMethod.GetNegativeFTolerance() <= m_EndFunction && m_EndFunction <= m_BrentsMethod.GetPositiveFTolerance())
    {        
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>
	::Search() 
{
	SwapBeginEnd();

	// ��ʼ����������ֵ��
	InitSearchValue();

	// ������
	auto maxIterations = m_BrentsMethod.GetMaxIterations();
	for (auto i = 0; i < maxIterations; ++i)
	{
		if (RootSearch())
			return;
	}	

	m_Bisect2Root = BrentsMethodRoot{ m_End, m_EndFunction, BrentsMethodRootType::Unknown };
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::SwapBeginEnd()
{
    if (Math<Real>::FAbs(m_BeginFunction) < Math<Real>::FAbs(m_EndFunction))
    {
        // ����m_Begin��m_End��ʹ��|f(m_End)| <= |f(m_Begin)|��
        // ��ֵm_End����Ϊ�Ǹ�����ѹ��ơ�
		std::swap(m_Begin, m_End);
		std::swap(m_BeginFunction, m_EndFunction);       
    }
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::InitSearchValue()
{
    m_SearchBegin = m_Begin;
    m_SearchEnd = m_Begin;
    m_SearchFunction = m_BeginFunction;
    m_PreviousBisected = true;
}

// private
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::RootSearch()
{
    UpdateFunctionDifference();
    
    if (Math<Real>::sm_ZeroTolerance < Math<Real>::FAbs(m_BeginSearchFunctionDifference) &&
        Math<Real>::sm_ZeroTolerance < Math<Real>::FAbs(m_EndSearchFunctionDifference))
    {
        // ʹ������β�ֵ��
        InverseQuadratic();
    }
    else
    {
        // ʹ�������Բ�ֵ�����߷�����
        InverseLinear();
    }
    
    // ����ֵ��Ҫ���н��ܻ�ܾ����ԡ�
    AcceptOrRejectTests();

	m_SolutionFunction = m_BrentsMethod.GetFunctionValue(m_Solution);
    
    // �����������µĹ��ƺ��������ԡ�
	if (IsSolutionSatisfyConditions())
	{
		m_Bisect2Root = BrentsMethodRoot{ m_Solution, m_SolutionFunction,BrentsMethodRootType::HaveSolution };
		return true;
	}
        
    // ���µ��Ӽ�����԰����µĹ�����Ϊ�յ㡣
    UpdateSubinterval();
    
    // ������㷨�Ӽ���㹻Сʱ��ֹ��
	if (IsConvXTolerance())
	{
		m_Bisect2Root = BrentsMethodRoot{ m_End, m_EndFunction, BrentsMethodRootType::HaveSolution };

		return true;
	}
    
    // һ��ѭ������ʽ�ǣ�x1�Ǹ����ƣ�
    // f(m_Begin) * f(m_End) < 0��|f(m_End)| <= |f(m_Begin)|��
    SwapBeginEnd();
    
    return false;
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::UpdateFunctionDifference()
{
    m_BeginEndFunctionDifference =  m_BeginFunction - m_EndFunction;    
    m_BeginSearchFunctionDifference = m_BeginFunction - m_SearchFunction;    
    m_EndSearchFunctionDifference = m_EndFunction - m_SearchFunction;
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::InverseQuadratic()
{
    m_Solution = m_Begin * m_EndFunction * m_SearchFunction / m_BeginEndFunctionDifference / m_BeginSearchFunctionDifference -
				 m_End * m_BeginFunction * m_SearchFunction / m_BeginEndFunctionDifference / m_EndSearchFunctionDifference +
				 m_SearchBegin * m_BeginFunction * m_SearchFunction / m_BeginSearchFunctionDifference / m_EndSearchFunctionDifference;
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::InverseLinear()
{
    m_Solution = (m_End * m_BeginFunction - m_Begin * m_EndFunction) / m_BeginEndFunctionDifference;    
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::AcceptOrRejectTests()
{
    auto solutionAvrDiff = m_Solution - static_cast<Real>(0.75) * m_Begin - static_cast<Real>(0.25) * m_End;
    
	auto solutionEndDiff = m_Solution - m_End;
    
	auto absSolutionEndDiff = Math<Real>::FAbs(solutionEndDiff);
    
	auto absEndSearchBeginDiff = Math<Real>::FAbs(m_End - m_SearchBegin);
    
	auto absSearchBeginSearchEndDiff = Math<Real>::FAbs(m_SearchBegin - m_SearchEnd);
    
	bool currentBisected{ false };
    if (Math<Real>::sm_ZeroTolerance  < solutionAvrDiff * solutionEndDiff)
    {
        // ֵs������0.75 * x0+0.25 * x1��x1֮�䡣
        // ע�����㷨��ʱ��x0 < x1����ʱx1 < x0��
        // ���Բ��Բ�û��ʹ�ü򵥵ıȽϡ�
        currentBisected = true;
    }
    else if (m_PreviousBisected)
    {
        // Brent�ĵ�һ���ԣ���ȷ���Ƿ���ܸò�ֵ ��
        currentBisected = (static_cast<Real>(0.5) *  absEndSearchBeginDiff) <= absSolutionEndDiff || (absEndSearchBeginDiff <= m_BrentsMethod.GetStepXTolerance());
    }
    else
    {
        // Brent�ĵڶ����ԣ���ȷ���Ƿ���ܸò�ֵ ��
        currentBisected = ((static_cast<Real>(0.5) * absSearchBeginSearchEndDiff) <= absSolutionEndDiff || (absSearchBeginSearchEndDiff <= m_BrentsMethod.GetStepXTolerance()));
    }
    
    if (currentBisected)
    {
        // ����һ������Ĳ���ʧ�ܣ�
        // ���Ծܾ���ֵ�����ö��ַ������档
        m_Solution = static_cast<Real>(0.5) * (m_Begin + m_End);
        m_PreviousBisected = true;
    }    
    else
    {
        m_PreviousBisected = false;
    }
}

// private
template <typename Real,typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real,UserDataType>
	:: UpdateSubinterval()
{
    m_SearchEnd = m_SearchBegin;
    m_SearchBegin = m_End;
    m_SearchFunction = m_EndFunction;
	if (m_BeginFunction * m_SolutionFunction < Real{})
    {
        m_End = m_Solution;
        m_EndFunction = m_SolutionFunction;
    }
    else
    {
        m_Begin = m_Solution;
        m_BeginFunction = m_SolutionFunction;
    }
}

// private
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::IsSolutionSatisfyConditions() const
{   
    if (m_BrentsMethod.GetNegativeFTolerance() <= m_SolutionFunction && m_SolutionFunction <= m_BrentsMethod.GetPositiveFTolerance())
    {       
        return true;
    }
    else
    {
        return false;
    }
}

// private
template <typename Real,typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real,UserDataType>
	::IsConvXTolerance() const
{
    if (Math<Real>::FAbs(m_End - m_Begin) <= m_BrentsMethod.GetConvXTolerance())
    {        
        return true;
    }
    else
    {
        return false;
    }
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H




