OPENQASM 2.0;
include "qelib1.inc";
qreg[16];
creg[16];
cx q[4],q[5];
cx q[5],q[4];
cx q[4],q[5];
cx q[3],q[4];
cx q[2],q[1];
u3(1.570796, 0.000000, 3.141593) q[2];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, 0.785398) q[1];
u3(0.000000, 0.000000, 0.785398) q[4];
u3(0.000000, 0.000000, 0.785398) q[2];
cx q[3],q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[1],q[3];
cx q[1],q[3];
cx q[3],q[1];
cx q[1],q[3];
cx q[2],q[1];
cx q[2],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[3],q[2];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[3],q[1];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, -0.785398) q[3];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[2],q[1];
cx q[2],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[3],q[2];
cx q[3],q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[1],q[3];
u3(1.570796, 0.000000, 3.141593) q[2];
cx q[2],q[0];
u3(3.141593, 0.000000, 3.141593) q[2];
u3(0.000000, 0.000000, 0.785398) q[0];
u3(1.570796, 0.000000, 3.141593) q[2];
cx q[0],q[4];
u3(0.000000, 0.000000, 0.785398) q[2];
cx q[2],q[0];
cx q[2],q[0];
cx q[0],q[2];
cx q[2],q[0];
cx q[4],q[2];
u3(0.000000, 0.000000, -0.785398) q[0];
cx q[0],q[2];
cx q[2],q[0];
cx q[0],q[2];
cx q[4],q[0];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, -0.785398) q[4];
u3(0.000000, 0.000000, -0.785398) q[0];
cx q[2],q[0];
cx q[2],q[0];
cx q[0],q[2];
cx q[2],q[0];
cx q[4],q[2];
cx q[4],q[2];
cx q[2],q[4];
cx q[4],q[2];
cx q[0],q[4];
u3(1.570796, 0.000000, 3.141593) q[2];
