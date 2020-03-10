// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 17:37)

#ifndef PHYSICS_LCP_SOLVER_LCP_SOLVER_MANAGER_H
#define PHYSICS_LCP_SOLVER_LCP_SOLVER_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Vector3D.h" 

#include <fstream>

namespace Physics
{
	class   LCPSolverManager
	{
	public:
		// A class for solving the Linear Complementarity Problem (LCP)
		// w = Mz + q, w o z = 0, w >= 0, z >= 0.
		//
		// Input:
		//   'numEquations' is the number of equations.
		//   'M' is a positive semidefinite matrix of size 'numEquations'.
		//   'Q' is a vector of reals.
		//
		// Output:
		//   'Z' and 'W' are the solutions.
		//   'status' of the output is one of the status codes below.

		enum // status codes
		{
			SC_FOUND_SOLUTION,               // solution
			SC_FOUND_TRIVIAL_SOLUTION,       // solution (z = 0, w = q)
			SC_CANNOT_REMOVE_COMPLEMENTARY,  // no solution (unbounded)
			SC_EXCEEDED_MAX_RETRIES,         // no solution (round-off problems?)
		};

		LCPSolverManager (int numEquations, double** M, double* Q, double* Z,
						  double* W, int& status, int maxRetries = 100,
						  double zeroTolerance = 0.0, double ratioError = 0.0);

		// MaxRetries:  In theory, one iteration of the LCP solver should work.
		// Floating point round-off errors can cause the solver to fail.  When
		// this does, the solver is allowed to retry the algorithm with a
		// different order of input equations.

		// ZeroTolerance:  The search for a pivot equation uses a comparison of a
		// certain term to zero.  To deal with floating point round-off errors,
		// the comparison is based on a small tolerance about zero.

		// RatioError:  The solver computes constant coefficients, z coefficients,
		// and w coefficients.  If any of these are nearly zero, their values are
		// set to zero.  The decision is made based on a relative comparison of a
		// ratio to zero.

	private:
		void AllocateEquations ();
		void DeallocateEquations ();
		bool InitializeEquations ();
		bool SelectEquation (int& equation);
		bool FindEquation (int& equation);
		bool EquationAlgorithm (int& equation);
		void Solve (char basicVariable, int basicVariableIndex);

		struct Equation
		{
			char Var;      // 'w' or 'z' are the only choices
			int VarIndex;  // index of the w or z variable
			double* C;     // constant coefficients
			double* W;     // coefficients of the w terms
			double* Z;     // coefficients of the z terms
		};

		int mNumEquations;
		double** mM;
		double* mQ;
		Equation* mEquations;
		char mNonBasicVariable;
		char mDepartingVariable;
		int mNonBasicVariableIndex;
		int mDepartingVariableIndex;
		double mFuzz;

		int mMaxRetries;
		double mZeroTolerance;
		double mRatioError;

#ifdef PHYSICS_LCPSOLVER_LOG
		void OpenLog ();
		void CloseLog ();
		void PrintImmediateSolution ();
		void PrintCannotRemoveComplementary ();
		void PrintNoBasicVariable (char basicVariable, int basicVariableIndex);
		void PrintEquations ();
		void PrintResults ();
		std::ofstream mLog;
		int mPrintEquationsCalls;
#endif // PHYSICS_LCPSOLVER_LOG
	};
}

#endif // PHYSICS_LCP_SOLVER_LCP_SOLVER_MANAGER_H
