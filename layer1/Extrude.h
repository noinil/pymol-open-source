/* 
A* -------------------------------------------------------------------
B* This file contains source code for the PyMOL computer program
C* copyright 1998-2000 by Warren Lyford Delano of DeLano Scientific. 
D* -------------------------------------------------------------------
E* It is unlawful to modify or remove this copyright notice.
F* -------------------------------------------------------------------
G* Please see the accompanying LICENSE file for further information. 
H* -------------------------------------------------------------------
I* Additional authors of this source file include:
-* 
-* 
-*
Z* -------------------------------------------------------------------
*/
#ifndef _H_Extrude
#define _H_Extrude

#include"Ray.h"
#include"CGO.h"

typedef struct {
  PyMOLGlobals *G;
  int N;

  float *p; /* points */
  float *n; /* normals (3x3f) at each point*/
  float *c; /* colors */
  int   *i; /* indices */

  float *sv,*tv;
  float *sn,*tn;
  int Ns;

} CExtrude;

CExtrude *ExtrudeNew(PyMOLGlobals *G);

CExtrude *ExtrudeCopyPointsNormalsColors(CExtrude *orig);

void ExtrudeAllocPointsNormalsColors(CExtrude *I,int n);
void ExtrudeTruncate(CExtrude *I,int n);
void ExtrudeFree(CExtrude *I);

void ExtrudeCircle(CExtrude *I, int n, float size);
void ExtrudeRectangle(CExtrude *I,float width,float length,int mode);
void ExtrudeOval(CExtrude *I,int n,float width,float length);


void ExtrudeBuildNormals1f(CExtrude *I);
void ExtrudeBuildNormals2f(CExtrude *I);
void ExtrudeComputeTangents(CExtrude *I);
void ExtrudeCGOSurfaceTube(CExtrude *I,CGO *cgo,int cap,float *color_override);
void ExtrudeCGOSurfacePolygon(CExtrude *I,CGO *cgo,int cap,float *color_override);
void ExtrudeCGOSurfacePolygonTaper(CExtrude *I,CGO *cgo,
                                   int sampling,float *color_override);
void ExtrudeCGOSurfaceStrand(CExtrude *I,CGO *cgo,int sampling,float *color_override);
void ExtrudeCGOTraceFrame(CExtrude *I,CGO *cgo);
void ExtrudeCGOTrace(CExtrude *I,CGO *cgo);
void ExtrudeCGOTraceAxes(CExtrude *I,CGO *cgo);
void ExtrudeDumbbell1(CExtrude *I,float width,float length,int mode);
void ExtrudeDumbbell2(CExtrude *I, int n,int sign,float length,float size);
void ExtrudeDumbbellEdge(CExtrude *I,int samp,int sign,float length);

#endif
