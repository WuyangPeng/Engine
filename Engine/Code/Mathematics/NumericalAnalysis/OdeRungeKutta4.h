// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 16:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

namespace Mathematics
{
    template <typename Real,typename UserDataType>
    class OdeRungeKutta4 : public OdeSolver<Real,UserDataType>
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = OdeRungeKutta4<Real,UserDataType>;
        using ParentType = OdeSolver<Real,UserDataType>;
		using typename ParentType::Function;
		using typename ParentType::RealVector;
		using ParentType::GetStepSize;
		using ParentType::GetFunctionValue;
		using ParentType::GetDimension;

    public:
        OdeRungeKutta4 (int dimension, Real step,Function function,const UserDataType* userData);
        virtual ~OdeRungeKutta4 ();

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
            
		virtual void Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut);
        virtual void SetStepSize (Real step);
        
    private:
        Real m_HalfStep;
        Real m_SixthStep;
		RealVector m_FirstStepFunctionValue;
		RealVector m_SecondStepFunctionValue;
		RealVector m_ThirdStepFunctionValue;
		RealVector m_FourthStepFunctionValue;
		RealVector m_SecondXIn;
    };  
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H
