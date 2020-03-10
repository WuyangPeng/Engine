// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:36)

#ifndef PHYSICS_LCP_SOLVER_LCP_POLY_DIST_H
#define PHYSICS_LCP_SOLVER_LCP_POLY_DIST_H

#include "Physics/PhysicsDll.h"

#include "LCPSolverManager.h"
#include "Mathematics/Algebra/Vector3D.h" 
#include "Mathematics/Algebra/Vector2D.h" 
#include "CoreTools/DataTypes/Tuple.h"

namespace Physics
{
	template <int Dimension, typename FVector, typename DVector>
	class  LCPPolyDist
	{
	public:
		typedef CoreTools::Tuple<Dimension,int> ITuple;

		// A class for computing the distance between two convex polygons or two
		// convex polyhedra.  The distance algorithm is formulated as a linear
		// complementarity problem (LCP) for three-dimensional data.  For convex
		// polygons in two dimensions, the third component of the vertices must
		// be zero.

		// Status codes returned by the polyhedra distance calculation.
		enum
		{
			SC_FOUND_SOLUTION = LCPSolverManager::SC_FOUND_SOLUTION, // solution

			SC_FOUND_TRIVIAL_SOLUTION = LCPSolverManager::SC_FOUND_TRIVIAL_SOLUTION, // solution (z = 0, w = q)

			SC_CANNOT_REMOVE_COMPLEMENTARY = LCPSolverManager::SC_CANNOT_REMOVE_COMPLEMENTARY, // no solution

			SC_EXCEEDED_MAX_RETRIES	= LCPSolverManager::SC_EXCEEDED_MAX_RETRIES, 

			// no solution (round-off problems?)
			SC_VERIFY_FAILURE,  // VerifySolution failed
			SC_TEST_POINTS_TEST_FAILED, // VerifyWithTestPoints failed
		};

		// Polygons are represented by vertices and edges.  The vertices are
		// stored as vectors in 3D with the last component always zero.
		//   numPoints1  = number of vertices of first polygon
		//   points1     = array of vertices
		//   numFaces1   = number of edges (same as numPoints1)
		//   faces1      = array of edges, each edge a pair of indices into the
		//                  vertex array points1: <0,1>, <1,2>, ..., <n-2,n-1>,
		//                  <n-1,0>
		//   numPoints2  = number of vertices of second polygon
		//   points2     = array of vertices
		//   numFaces2   = number of edges (same as numPoints2)
		//   faces2      = array of edges, each edge a pair of indices into the
		//                  vertex array points2: <0,1>, <1,2>, ..., <n-2,n-1>,
		//                  <n-1,0>
		//   statusCode  = the status of the LCP numerical solver
		//   distance    = distance between the polygons
		//   closest     = array of two closest points, one on each polygon
		// 
		// Polyhedra are represented by vertices and faces.
		//   numPoints1  = number of vertices of first polyhedron
		//   points1     = array of vertices
		//   numFaces1   = number of triangular faces
		//   faces1      = array of faces, each face a triple of indices into
		//                  the vertex array points1
		//   numPoints2  = number of vertices of second polyhedron
		//   points2     = array of vertices
		//   numFaces2   = number of triangular faces
		//   faces2      = array of faces, each face a triple of indices into
		//                  the vertex array points2
		//   statusCode  = the status of the LCP numerical solver
		//   distance    = distance between the polyhedra
		//   closest     = array of two closest points, one on each polyhedron

		LCPPolyDist (int numPoints1, FVector* points1, int numFaces1,
					 ITuple* faces1, int numPoints2, FVector* points2, int numFaces2,
					 ITuple* faces2, int& statusCode, float& distance, FVector closest[2],
					 double verifyMinDifference = 0.00001, double randomWidth = 0.0);

		// Polygons and polyhedra represented by halfspaces.  The halfspaces are
		// all the points p such that p.Dot(An[i]) <= Bn[i], n = 1 or 2.  The
		// arrays An[] are the outer-pointing edge/face normals.  The arrays Bn[]
		// are the line/plane constants.
		//   numFaces1  = number of halfspaces of first polygon/polyhedron
		//   B1         = array of line/plane constants
		//   A1         = array of outer pointing edge/face normals
		//   numFaces2  = number of halfspaces of second polygon/polyhedron
		//   B2         = array of line/plane constants
		//   A2         = array of outer pointing edge/face normals
		//   statusCode = the status of the LCP numerical solver
		//   distance   = distance between the polygons/polyhedra
		//   closest    = array of two closest points, one on each
		//                  polygon/polyhedron

		LCPPolyDist (int numFaces1, FVector* A1, float* B1, int numFaces2,
					 FVector* A2, float* B2, int& statusCode, float& distance,
					 FVector closest[2], double verifyMinDifference = 0.00001,
					 double randomWidth = 0.0);

		// VerifyMinDifference:  Solution vectors are tested to determine if they
		// meet constraints imposed by the halfspace statement of the problem:
		// V o Z <= B. VerifyMinDifference is the amount that this dot product can
		// exceed B without reporting an error.

		// RandomWidth:  Used in GenerateHalfSpaceDescription to produce a random
		// array of vertices whose means are the input values to FuzzArray. Each
		// vertex is selected from a uniform distribution of width RandomWidth. 

	private:
		double ProcessLoop (bool halfspaceConstructor, int& statusCode, FVector closest[2]);
		bool BuildMatrices (double** M, double* Q);
		void ComputeHalfspaces (int numPoints, const DVector* points, int numFaces, const ITuple* faces, DVector* A, double* B);
		void GenerateHalfSpaceDescription (int numPoints, DVector* points, int numFaces, ITuple* faces, DVector* A, double* B);
		void ChangeFaceOrder (int numFaces, ITuple* faces);
		void MoveHalfspaces (int numFaces, DVector* A, double* B);
		void MovePoints ();
		int VerifySolution (const DVector closest[2]);

		int mDimension;
		int mNumEquations;
		int mNumPoints1;
		int mNumPoints2;
		int mNumFaces1;
		int mNumFaces2; 
		DVector* mPoints1;  // points
		DVector* mPoints2;
		ITuple* mFaces1;  // faces
		ITuple* mFaces2;
		DVector* mA1;  // halfspace vectors
		DVector* mA2;
		double* mB1;  // halfspace constants
		double* mB2;

		double mVerifyMinDifference;
		double mRandomWidth;

#ifdef PHYSICS_LCPPOLYDIST_LOG
		void OpenLog ();
		void CloseLog ();
		void PrintMatrices (double** M, double* Q);
		void LogRetries (int tryNumber);
		void LCPSolverLoopLimit ();
		void LogVertices (int numPoints, const DVector* points);
		void LogVerticesAndFaces (int numPoints, const FVector* points, int numFaces, const ITuple* faces);
		void LogHalfspaces (int numFaces, const DVector* A, const double* B);
		void SetupTestPoints (int index, int numFaces, int numPoints,
							  const DVector& closest, const DVector* A, const double* B,
							  const DVector* points, DVector* testPoints);
		void LogTestPoints (const DVector* testPoints);
		void LogSolutionWithTestPoints (int index, const DVector& closest,  const DVector* testPoints);
		void VerifyWithTestPoints (const DVector* closest, int& statusCode);
		void RandomizeArray (int numPoints, DVector* points);
		void RandomizeHalfspaces ();
		void LogVerifyFailure (int whichPoly, int i, double diff);
		std::ofstream mLog;
#endif // PHYSICS_LCPPOLYDIST_LOG
	};

	using LCPPolyDist2 = LCPPolyDist<2, Mathematics::Vector2D<float>, Mathematics::Vector2D<double> >;
	using LCPPolyDist3 = LCPPolyDist<3, Mathematics::Vector3D<float>, Mathematics::Vector3D<double> >;
}

#endif // PHYSICS_LCP_SOLVER_LCP_POLY_DIST_H
