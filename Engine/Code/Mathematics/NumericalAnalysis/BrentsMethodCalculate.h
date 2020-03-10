// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/08 15:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H

#include "Mathematics/MathematicsDll.h"

#include "BrentsMethodRoot.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
	template <typename Real,typename UserDataType>
	class BrentsMethod;

    template <typename Real,typename UserDataType>
    class BrentsMethodCalculate : boost::noncopyable
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethodCalculate<Real,UserDataType>;
        using BrentsMethod = BrentsMethod<Real,UserDataType>;
		using BrentsMethodRoot = BrentsMethodRoot<Real>;

    public:
        BrentsMethodCalculate (const BrentsMethod& brentsMethod, Real begin, Real end);
        
		CLASS_INVARIANT_DECLARE;
 
        const BrentsMethodRoot GetRoot ();
        
    private:
        void Calculate();
        bool IsBeginSatisfyConditions() const;
		bool IsEndSatisfyConditions() const;
		void Search();
        void SwapBeginEnd();
        void InitSearchValue();
        bool RootSearch();
		bool IsConvXTolerance() const;
        void UpdateFunctionDifference();
        void InverseQuadratic();
        void InverseLinear();
        void AcceptOrRejectTests();
        bool IsSolutionSatisfyConditions() const;
        void UpdateSubinterval();
        
    private:
        const BrentsMethod& m_BrentsMethod;
        Real m_Begin;
        Real m_End;
        Real m_BeginFunction;
        Real m_EndFunction;
        
        BrentsMethodRoot m_Bisect2Root;
                
        // ¸ùËÑË÷µÄÖµ¡£
        Real m_SearchBegin;
        Real m_SearchEnd;
        Real m_SearchFunction;
        bool m_PreviousBisected;
        
        Real m_BeginEndFunctionDifference;
        Real m_BeginSearchFunctionDifference;
        Real m_EndSearchFunctionDifference;
        
        Real m_Solution;
        Real m_SolutionFunction;
    };  
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H
