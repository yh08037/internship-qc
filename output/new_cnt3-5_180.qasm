OPENQASM 2.0;
include "qelib1.inc";
qreg[16];
creg[16];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[13];
u3(0.000000, 0.000000, 0.785398) q[14];
u3(1.570796, 0.000000, 3.141593) q[12];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, 0.785398) q[10];
u3(1.570796, 0.000000, 3.141593) q[9];
u3(1.570796, 0.000000, 3.141593) q[8];
u3(0.000000, 0.000000, 0.785398) q[7];
u3(1.570796, 0.000000, 3.141593) q[6];
u3(1.570796, 0.000000, 3.141593) q[5];
u3(0.000000, 0.000000, 0.785398) q[4];
u3(1.570796, 0.000000, 3.141593) q[3];
u3(1.570796, 0.000000, 3.141593) q[2];
u3(0.000000, 0.000000, 0.785398) q[1];
u3(1.570796, 0.000000, 3.141593) q[0];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[13],q[15];
cx q[15],q[13];
cx q[13],q[15];
cx q[13],q[11];
cx q[11],q[13];
cx q[13],q[11];
cx q[14],q[13];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, 0.785398) q[8];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, 0.785398) q[5];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, 0.785398) q[0];
cx q[14],q[13];
cx q[13],q[14];
cx q[14],q[13];
cx q[14],q[11];
cx q[11],q[14];
cx q[14],q[11];
cx q[15],q[14];
cx q[15],q[14];
cx q[14],q[15];
cx q[15],q[14];
cx q[15],q[11];
cx q[11],q[15];
cx q[15],q[11];
cx q[13],q[15];
u3(0.000000, 0.000000, -0.785398) q[14];
cx q[14],q[11];
cx q[11],q[14];
cx q[14],q[11];
cx q[14],q[15];
cx q[15],q[14];
cx q[14],q[15];
cx q[13],q[14];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[13];
u3(0.000000, 0.000000, -0.785398) q[14];
cx q[15],q[14];
cx q[15],q[14];
cx q[14],q[15];
cx q[15],q[14];
cx q[13],q[15];
cx q[13],q[15];
cx q[15],q[13];
cx q[13],q[15];
cx q[14],q[13];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[13];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[14];
cx q[13],q[14];
cx q[14],q[13];
cx q[13],q[14];
cx q[11],q[13];
cx q[14],q[15];
cx q[11],q[4];
cx q[4],q[11];
cx q[11],q[4];
cx q[11],q[9];
cx q[9],q[11];
cx q[11],q[9];
cx q[12],q[11];
cx q[12],q[3];
cx q[3],q[12];
cx q[12],q[3];
cx q[12],q[6];
cx q[6],q[12];
cx q[12],q[6];
cx q[13],q[12];
u3(0.000000, 0.000000, -0.785398) q[11];
cx q[11],q[1];
cx q[1],q[11];
cx q[11],q[1];
cx q[11],q[12];
cx q[12],q[11];
cx q[11],q[12];
cx q[13],q[11];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, -0.785398) q[13];
u3(0.000000, 0.000000, -0.785398) q[11];
cx q[12],q[11];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[13],q[12];
cx q[13],q[12];
cx q[12],q[13];
cx q[13],q[12];
cx q[11],q[13];
u3(1.570796, 0.000000, 3.141593) q[12];
u3(1.570796, 0.000000, 3.141593) q[11];
u3(1.570796, 0.000000, 3.141593) q[12];
u3(0.000000, 0.000000, 0.785398) q[13];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, 0.785398) q[12];
cx q[14],q[2];
cx q[2],q[14];
cx q[14],q[2];
cx q[14],q[0];
cx q[0],q[14];
cx q[14],q[0];
cx q[11],q[14];
cx q[11],q[13];
cx q[13],q[11];
cx q[11],q[13];
cx q[11],q[12];
cx q[12],q[11];
cx q[11],q[12];
cx q[11],q[2];
cx q[2],q[11];
cx q[11],q[2];
cx q[15],q[11];
u3(0.000000, 0.000000, -0.785398) q[14];
cx q[14],q[0];
cx q[0],q[14];
cx q[14],q[0];
cx q[14],q[11];
cx q[11],q[14];
cx q[14],q[11];
cx q[15],q[14];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, -0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[14];
cx q[11],q[14];
cx q[11],q[14];
cx q[14],q[11];
cx q[11],q[14];
cx q[15],q[11];
cx q[15],q[11];
cx q[11],q[15];
cx q[15],q[11];
cx q[14],q[15];
u3(1.570796, 0.000000, 3.141593) q[11];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[14];
cx q[13],q[0];
cx q[0],q[13];
cx q[13],q[0];
cx q[13],q[14];
cx q[14],q[13];
cx q[13],q[14];
cx q[13],q[15];
cx q[15],q[13];
cx q[13],q[15];
cx q[11],q[13];
cx q[14],q[15];
cx q[11],q[13];
cx q[13],q[11];
cx q[11],q[13];
cx q[11],q[2];
cx q[2],q[11];
cx q[11],q[2];
cx q[12],q[11];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[12],q[2];
cx q[2],q[12];
cx q[12],q[2];
cx q[13],q[12];
u3(0.000000, 0.000000, -0.785398) q[11];
cx q[11],q[2];
cx q[2],q[11];
cx q[11],q[2];
cx q[11],q[12];
cx q[12],q[11];
cx q[11],q[12];
cx q[13],q[11];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, -0.785398) q[13];
u3(0.000000, 0.000000, -0.785398) q[11];
cx q[12],q[11];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[13],q[12];
cx q[13],q[12];
cx q[12],q[13];
cx q[13],q[12];
cx q[11],q[13];
u3(1.570796, 0.000000, 3.141593) q[12];
u3(1.570796, 0.000000, 3.141593) q[11];
u3(0.000000, 0.000000, 0.785398) q[13];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, 0.785398) q[11];
cx q[12],q[13];
cx q[13],q[12];
cx q[12],q[13];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[12],q[4];
cx q[4],q[12];
cx q[12],q[4];
cx q[12],q[8];
cx q[8],q[12];
cx q[12],q[8];
cx q[10],q[12];
cx q[14],q[15];
cx q[15],q[14];
cx q[14],q[15];
cx q[11],q[14];
cx q[11],q[14];
cx q[14],q[11];
cx q[11],q[14];
cx q[15],q[11];
u3(0.000000, 0.000000, -0.785398) q[14];
cx q[14],q[11];
cx q[11],q[14];
cx q[14],q[11];
cx q[15],q[14];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, -0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[14];
cx q[11],q[14];
cx q[11],q[14];
cx q[14],q[11];
cx q[11],q[14];
cx q[15],q[11];
cx q[15],q[11];
cx q[11],q[15];
cx q[15],q[11];
cx q[14],q[15];
u3(1.570796, 0.000000, 3.141593) q[11];
u3(1.570796, 0.000000, 3.141593) q[14];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(1.570796, 0.000000, 3.141593) q[11];
u3(0.000000, 0.000000, 0.785398) q[14];
cx q[15],q[14];
cx q[14],q[15];
cx q[15],q[14];
cx q[13],q[15];
u3(0.000000, 0.000000, 0.785398) q[11];
cx q[13],q[15];
cx q[15],q[13];
cx q[13],q[15];
cx q[14],q[13];
cx q[10],q[12];
cx q[12],q[10];
cx q[10],q[12];
cx q[10],q[8];
cx q[8],q[10];
cx q[10],q[8];
cx q[10],q[2];
cx q[2],q[10];
cx q[10],q[2];
cx q[11],q[10];
cx q[14],q[13];
cx q[13],q[14];
cx q[14],q[13];
cx q[15],q[14];
u3(0.000000, 0.000000, -0.785398) q[13];
cx q[11],q[0];
cx q[0],q[11];
cx q[11],q[0];
cx q[11],q[9];
cx q[9],q[11];
cx q[11],q[9];
cx q[11],q[8];
cx q[8],q[11];
cx q[11],q[8];
cx q[12],q[11];
u3(0.000000, 0.000000, -0.785398) q[10];
cx q[13],q[14];
cx q[14],q[13];
cx q[13],q[14];
cx q[15],q[13];
u3(0.000000, 0.000000, 0.785398) q[14];
cx q[10],q[2];
cx q[2],q[10];
cx q[10],q[2];
cx q[10],q[11];
cx q[11],q[10];
cx q[10],q[11];
cx q[12],q[10];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, -0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[13];
u3(0.000000, 0.000000, -0.785398) q[12];
u3(0.000000, 0.000000, -0.785398) q[10];
cx q[14],q[13];
cx q[11],q[10];
cx q[14],q[13];
cx q[13],q[14];
cx q[14],q[13];
cx q[15],q[14];
cx q[11],q[10];
cx q[10],q[11];
cx q[11],q[10];
cx q[12],q[11];
cx q[15],q[14];
cx q[14],q[15];
cx q[15],q[14];
cx q[13],q[15];
u3(1.570796, 0.000000, 3.141593) q[14];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[10],q[12];
u3(1.570796, 0.000000, 3.141593) q[11];
cx q[13],q[15];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, 0.785398) q[10];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[11],q[12];
cx q[12],q[11];
cx q[11],q[12];
cx q[10],q[11];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[12],q[10];
cx q[10],q[12];
cx q[12],q[10];
cx q[12],q[4];
cx q[4],q[12];
cx q[12],q[4];
cx q[15],q[12];
cx q[15],q[12];
cx q[12],q[15];
cx q[15],q[12];
cx q[15],q[2];
cx q[2],q[15];
cx q[15],q[2];
cx q[9],q[15];
cx q[9],q[0];
cx q[0],q[9];
cx q[9],q[0];
cx q[9],q[13];
cx q[13],q[9];
cx q[9],q[13];
cx q[12],q[9];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[15],q[2];
cx q[2],q[15];
cx q[15],q[2];
cx q[12],q[15];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, -0.785398) q[12];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[9],q[15];
cx q[12],q[9];
cx q[15],q[12];
u3(1.570796, 0.000000, 3.141593) q[9];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(1.570796, 0.000000, 3.141593) q[9];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[9];
cx q[10],q[4];
cx q[4],q[10];
cx q[10],q[4];
cx q[15],q[10];
cx q[15],q[10];
cx q[10],q[15];
cx q[15],q[10];
cx q[15],q[4];
cx q[4],q[15];
cx q[15],q[4];
cx q[11],q[15];
u3(0.000000, 0.000000, -0.785398) q[10];
cx q[10],q[4];
cx q[4],q[10];
cx q[10],q[4];
cx q[10],q[15];
cx q[15],q[10];
cx q[10],q[15];
cx q[11],q[10];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[11];
u3(0.000000, 0.000000, -0.785398) q[10];
cx q[15],q[10];
cx q[15],q[10];
cx q[10],q[15];
cx q[15],q[10];
cx q[11],q[15];
cx q[11],q[15];
cx q[15],q[11];
cx q[11],q[15];
cx q[10],q[11];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, 0.785398) q[10];
cx q[12],q[4];
cx q[4],q[12];
cx q[12],q[4];
cx q[12],q[10];
cx q[10],q[12];
cx q[12],q[10];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[15],q[12];
cx q[10],q[11];
cx q[15],q[12];
cx q[12],q[15];
cx q[15],q[12];
cx q[15],q[11];
cx q[11],q[15];
cx q[15],q[11];
cx q[15],q[10];
cx q[10],q[15];
cx q[15],q[10];
cx q[9],q[15];
cx q[9],q[15];
cx q[15],q[9];
cx q[9],q[15];
cx q[9],q[10];
cx q[10],q[9];
cx q[9],q[10];
cx q[9],q[11];
cx q[11],q[9];
cx q[9],q[11];
cx q[12],q[9];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[15],q[10];
cx q[10],q[15];
cx q[15],q[10];
cx q[15],q[11];
cx q[11],q[15];
cx q[15],q[11];
cx q[15],q[9];
cx q[9],q[15];
cx q[15],q[9];
cx q[12],q[15];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, -0.785398) q[12];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[9],q[15];
cx q[9],q[15];
cx q[15],q[9];
cx q[9],q[15];
cx q[12],q[9];
cx q[12],q[9];
cx q[9],q[12];
cx q[12],q[9];
cx q[15],q[12];
u3(1.570796, 0.000000, 3.141593) q[9];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[12];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[9],q[12];
cx q[12],q[9];
cx q[9],q[12];
cx q[7],q[9];
cx q[10],q[11];
cx q[11],q[10];
cx q[10],q[11];
cx q[15],q[10];
cx q[8],q[7];
cx q[15],q[10];
cx q[10],q[15];
cx q[15],q[10];
cx q[11],q[15];
u3(0.000000, 0.000000, -0.785398) q[10];
cx q[9],q[8];
u3(0.000000, 0.000000, -0.785398) q[7];
cx q[10],q[15];
cx q[15],q[10];
cx q[10],q[15];
cx q[11],q[10];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[9],q[7];
u3(0.000000, 0.000000, 0.785398) q[8];
u3(0.000000, 0.000000, -0.785398) q[11];
u3(0.000000, 0.000000, -0.785398) q[10];
u3(0.000000, 0.000000, -0.785398) q[9];
u3(0.000000, 0.000000, -0.785398) q[7];
cx q[15],q[10];
cx q[8],q[7];
cx q[15],q[10];
cx q[10],q[15];
cx q[15],q[10];
cx q[11],q[15];
cx q[9],q[8];
cx q[11],q[15];
cx q[15],q[11];
cx q[11],q[15];
cx q[10],q[11];
u3(1.570796, 0.000000, 3.141593) q[15];
cx q[7],q[9];
u3(1.570796, 0.000000, 3.141593) q[8];
u3(1.570796, 0.000000, 3.141593) q[10];
u3(0.000000, 0.000000, 0.785398) q[11];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[8];
u3(0.000000, 0.000000, 0.785398) q[7];
u3(0.000000, 0.000000, 0.785398) q[10];
cx q[11],q[10];
cx q[10],q[11];
cx q[11],q[10];
cx q[11],q[9];
cx q[9],q[11];
cx q[11],q[9];
cx q[12],q[11];
cx q[9],q[10];
cx q[10],q[9];
cx q[9],q[10];
cx q[15],q[9];
cx q[7],q[8];
cx q[12],q[11];
cx q[11],q[12];
cx q[12],q[11];
cx q[10],q[12];
cx q[15],q[13];
cx q[13],q[15];
cx q[15],q[13];
cx q[6],q[15];
cx q[10],q[12];
cx q[12],q[10];
cx q[10],q[12];
cx q[11],q[10];
u3(0.000000, 0.000000, -0.785398) q[12];
cx q[6],q[2];
cx q[2],q[6];
cx q[6],q[2];
cx q[9],q[6];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[12],q[10];
cx q[10],q[12];
cx q[12],q[10];
cx q[11],q[12];
u3(0.000000, 0.000000, 0.785398) q[10];
cx q[15],q[6];
cx q[6],q[15];
cx q[15],q[6];
cx q[9],q[15];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, -0.785398) q[11];
u3(0.000000, 0.000000, -0.785398) q[12];
u3(0.000000, 0.000000, -0.785398) q[9];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[10],q[12];
cx q[6],q[15];
cx q[10],q[12];
cx q[12],q[10];
cx q[10],q[12];
cx q[11],q[10];
cx q[6],q[13];
cx q[13],q[6];
cx q[6],q[13];
cx q[9],q[6];
cx q[11],q[10];
cx q[10],q[11];
cx q[11],q[10];
cx q[12],q[11];
u3(1.570796, 0.000000, 3.141593) q[10];
cx q[15],q[9];
u3(1.570796, 0.000000, 3.141593) q[6];
cx q[12],q[11];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(1.570796, 0.000000, 3.141593) q[6];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[6];
cx q[7],q[12];
cx q[12],q[7];
cx q[7],q[12];
cx q[15],q[7];
cx q[15],q[0];
cx q[0],q[15];
cx q[15],q[0];
cx q[8],q[15];
u3(0.000000, 0.000000, -0.785398) q[7];
cx q[8],q[7];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[8];
u3(0.000000, 0.000000, -0.785398) q[7];
cx q[7],q[0];
cx q[0],q[7];
cx q[7],q[0];
cx q[15],q[7];
cx q[8],q[15];
cx q[8],q[0];
cx q[0],q[8];
cx q[8],q[0];
cx q[7],q[8];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[8];
u3(0.000000, 0.000000, 0.785398) q[7];
cx q[9],q[7];
cx q[7],q[9];
cx q[9],q[7];
cx q[15],q[9];
cx q[7],q[8];
cx q[15],q[13];
cx q[13],q[15];
cx q[15],q[13];
cx q[6],q[15];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[9],q[6];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[9],q[15];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, -0.785398) q[9];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[15],q[7];
cx q[7],q[15];
cx q[15],q[7];
cx q[6],q[15];
cx q[9],q[6];
cx q[9],q[6];
cx q[6],q[9];
cx q[9],q[6];
cx q[15],q[9];
u3(1.570796, 0.000000, 3.141593) q[6];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[9];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[6],q[9];
cx q[9],q[6];
cx q[6],q[9];
cx q[4],q[6];
cx q[15],q[7];
cx q[5],q[4];
cx q[15],q[6];
cx q[6],q[15];
cx q[15],q[6];
cx q[8],q[15];
u3(0.000000, 0.000000, -0.785398) q[7];
cx q[6],q[5];
u3(0.000000, 0.000000, -0.785398) q[4];
cx q[7],q[9];
cx q[9],q[7];
cx q[7],q[9];
cx q[8],q[7];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[6],q[4];
u3(0.000000, 0.000000, 0.785398) q[5];
u3(0.000000, 0.000000, -0.785398) q[8];
u3(0.000000, 0.000000, -0.785398) q[7];
u3(0.000000, 0.000000, -0.785398) q[6];
u3(0.000000, 0.000000, -0.785398) q[4];
cx q[15],q[7];
cx q[5],q[4];
cx q[8],q[15];
cx q[6],q[5];
cx q[7],q[8];
u3(1.570796, 0.000000, 3.141593) q[15];
cx q[4],q[6];
u3(1.570796, 0.000000, 3.141593) q[5];
u3(1.570796, 0.000000, 3.141593) q[7];
u3(0.000000, 0.000000, 0.785398) q[8];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[5];
u3(0.000000, 0.000000, 0.785398) q[4];
u3(0.000000, 0.000000, 0.785398) q[7];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[9],q[8];
cx q[15],q[6];
cx q[4],q[5];
cx q[9],q[8];
cx q[8],q[9];
cx q[9],q[8];
cx q[7],q[9];
cx q[15],q[9];
cx q[9],q[15];
cx q[15],q[9];
cx q[15],q[2];
cx q[2],q[15];
cx q[15],q[2];
cx q[3],q[15];
cx q[7],q[2];
cx q[2],q[7];
cx q[7],q[2];
cx q[8],q[7];
u3(0.000000, 0.000000, -0.785398) q[9];
cx q[3],q[15];
cx q[15],q[3];
cx q[3],q[15];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[6],q[3];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[9],q[7];
cx q[7],q[9];
cx q[9],q[7];
cx q[8],q[9];
u3(0.000000, 0.000000, 0.785398) q[7];
cx q[15],q[8];
cx q[8],q[15];
cx q[15],q[8];
cx q[15],q[3];
cx q[3],q[15];
cx q[15],q[3];
cx q[6],q[15];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, -0.785398) q[8];
u3(0.000000, 0.000000, -0.785398) q[9];
u3(0.000000, 0.000000, -0.785398) q[6];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[7],q[9];
cx q[3],q[15];
cx q[7],q[9];
cx q[9],q[7];
cx q[7],q[9];
cx q[7],q[3];
cx q[3],q[7];
cx q[7],q[3];
cx q[8],q[7];
cx q[3],q[9];
cx q[9],q[3];
cx q[3],q[9];
cx q[6],q[3];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[9],q[8];
u3(1.570796, 0.000000, 3.141593) q[7];
cx q[15],q[6];
u3(1.570796, 0.000000, 3.141593) q[3];
cx q[9],q[8];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(1.570796, 0.000000, 3.141593) q[3];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[3];
cx q[4],q[6];
cx q[6],q[4];
cx q[4],q[6];
cx q[15],q[4];
cx q[15],q[4];
cx q[4],q[15];
cx q[15],q[4];
cx q[5],q[15];
u3(0.000000, 0.000000, -0.785398) q[4];
cx q[4],q[15];
cx q[15],q[4];
cx q[4],q[15];
cx q[5],q[4];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[5];
u3(0.000000, 0.000000, -0.785398) q[4];
cx q[15],q[4];
cx q[15],q[4];
cx q[4],q[15];
cx q[15],q[4];
cx q[5],q[15];
cx q[5],q[15];
cx q[15],q[5];
cx q[5],q[15];
cx q[4],q[5];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[5];
u3(0.000000, 0.000000, 0.785398) q[4];
cx q[15],q[6];
cx q[4],q[5];
cx q[3],q[15];
cx q[6],q[3];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[6],q[15];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, -0.785398) q[6];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[3],q[15];
cx q[6],q[3];
cx q[15],q[6];
u3(1.570796, 0.000000, 3.141593) q[3];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[6];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[3],q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[3],q[0];
cx q[0],q[3];
cx q[3],q[0];
cx q[1],q[3];
cx q[4],q[5];
cx q[5],q[4];
cx q[4],q[5];
cx q[15],q[4];
cx q[1],q[3];
cx q[3],q[1];
cx q[1],q[3];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[2],q[1];
cx q[15],q[4];
cx q[4],q[15];
cx q[15],q[4];
cx q[5],q[15];
u3(0.000000, 0.000000, -0.785398) q[4];
cx q[2],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[2],q[0];
cx q[0],q[2];
cx q[2],q[0];
cx q[3],q[2];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[4],q[15];
cx q[15],q[4];
cx q[4],q[15];
cx q[5],q[4];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[3],q[1];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, -0.785398) q[5];
u3(0.000000, 0.000000, -0.785398) q[4];
u3(0.000000, 0.000000, -0.785398) q[3];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[15],q[4];
cx q[2],q[1];
cx q[15],q[4];
cx q[4],q[15];
cx q[15],q[4];
cx q[5],q[15];
cx q[2],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[3],q[2];
cx q[5],q[15];
cx q[15],q[5];
cx q[5],q[15];
cx q[4],q[5];
u3(1.570796, 0.000000, 3.141593) q[15];
cx q[3],q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[1],q[3];
u3(1.570796, 0.000000, 3.141593) q[2];
u3(1.570796, 0.000000, 3.141593) q[4];
u3(0.000000, 0.000000, 0.785398) q[5];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, 0.785398) q[1];
u3(0.000000, 0.000000, 0.785398) q[4];
cx q[6],q[5];
cx q[3],q[13];
cx q[13],q[3];
cx q[3],q[13];
cx q[15],q[3];
cx q[2],q[13];
cx q[13],q[2];
cx q[2],q[13];
cx q[1],q[2];
cx q[4],q[6];
cx q[15],q[5];
cx q[5],q[15];
cx q[15],q[5];
cx q[0],q[15];
cx q[4],q[15];
cx q[15],q[4];
cx q[4],q[15];
cx q[5],q[4];
u3(0.000000, 0.000000, -0.785398) q[6];
cx q[0],q[9];
cx q[9],q[0];
cx q[0],q[9];
cx q[3],q[0];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[6],q[4];
cx q[4],q[6];
cx q[6],q[4];
cx q[5],q[6];
u3(0.000000, 0.000000, 0.785398) q[4];
cx q[15],q[6];
cx q[6],q[15];
cx q[15],q[6];
cx q[15],q[5];
cx q[5],q[15];
cx q[15],q[5];
cx q[3],q[15];
u3(0.000000, 0.000000, 0.785398) q[0];
u3(0.000000, 0.000000, -0.785398) q[5];
u3(0.000000, 0.000000, -0.785398) q[6];
u3(0.000000, 0.000000, -0.785398) q[3];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[4],q[6];
cx q[0],q[15];
cx q[5],q[4];
cx q[3],q[0];
cx q[6],q[5];
u3(1.570796, 0.000000, 3.141593) q[4];
cx q[15],q[3];
u3(1.570796, 0.000000, 3.141593) q[0];
cx q[6],q[5];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(1.570796, 0.000000, 3.141593) q[0];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[0];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[15],q[1];
cx q[15],q[3];
cx q[3],q[15];
cx q[15],q[3];
cx q[2],q[15];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[2],q[1];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[2];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[15],q[1];
cx q[2],q[15];
cx q[2],q[0];
cx q[0],q[2];
cx q[2],q[0];
cx q[1],q[2];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, 0.785398) q[1];
cx q[15],q[3];
cx q[1],q[2];
cx q[0],q[15];
cx q[0],q[15];
cx q[15],q[0];
cx q[0],q[15];
cx q[3],q[0];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[15],q[0];
cx q[0],q[15];
cx q[15],q[0];
cx q[3],q[15];
u3(0.000000, 0.000000, 0.785398) q[0];
u3(0.000000, 0.000000, -0.785398) q[3];
u3(0.000000, 0.000000, -0.785398) q[15];
cx q[0],q[15];
cx q[0],q[15];
cx q[15],q[0];
cx q[0],q[15];
cx q[3],q[0];
cx q[3],q[0];
cx q[0],q[3];
cx q[3],q[0];
cx q[15],q[3];
u3(1.570796, 0.000000, 3.141593) q[0];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(0.000000, 0.000000, 0.785398) q[3];
u3(0.000000, 0.000000, 0.785398) q[15];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[15],q[1];
cx q[15],q[1];
cx q[1],q[15];
cx q[15],q[1];
cx q[2],q[15];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[1],q[3];
cx q[3],q[1];
cx q[1],q[3];
cx q[2],q[1];
u3(0.000000, 0.000000, 0.785398) q[15];
u3(0.000000, 0.000000, -0.785398) q[2];
u3(0.000000, 0.000000, -0.785398) q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[15],q[1];
cx q[15],q[1];
cx q[1],q[15];
cx q[15],q[1];
cx q[2],q[15];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
cx q[1],q[2];
u3(1.570796, 0.000000, 3.141593) q[15];
u3(1.570796, 0.000000, 3.141593) q[1];
u3(0.000000, 0.000000, 0.785398) q[2];
u3(0.000000, 0.000000, 0.785398) q[1];
cx q[3],q[2];
cx q[3],q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[1],q[3];
cx q[1],q[3];
cx q[3],q[1];
cx q[1],q[3];
cx q[2],q[1];
u3(0.000000, 0.000000, -0.785398) q[3];
cx q[3],q[1];
cx q[1],q[3];
cx q[3],q[1];
cx q[2],q[3];
u3(0.000000, 0.000000, 0.785398) q[1];
u3(0.000000, 0.000000, -0.785398) q[2];
u3(0.000000, 0.000000, -0.785398) q[3];
cx q[1],q[3];
cx q[1],q[3];
cx q[3],q[1];
cx q[1],q[3];
cx q[2],q[1];
cx q[2],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[3],q[2];
u3(1.570796, 0.000000, 3.141593) q[1];
cx q[3],q[2];
