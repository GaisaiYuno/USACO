/**
 * Description: Delaunay triangulation with 3D hull
 * Source: KACTL
 * Time: O(N^2)
 * Verification: https://dmoj.ca/problem/cco08p6
 */

#include "../Primitives/Point.h"
#include "Hull3D.h"

V<AR<P,3>> triHull(vP p) {
	if (sz(p) == 3) { 
		int d = cross(p[0],p[1],p[2]) < 0;
		return {{p[0],p[1+d],p[2-d]}}; }
	V<P3> p3; V<AR<P,3>> res; trav(x,p) p3.pb({x.f,x.s,norm(x)});
	#define nor(x) P(p3[x][0],p3[x][1])
	trav(t,hull3d(p3)) 
		if (dot(cross(p3[t[0]],p3[t[1]],p3[t[2]]),{0,0,1}) < 0)
			res.pb({nor(t[0]),nor(t[2]),nor(t[1])});
	return res;
}