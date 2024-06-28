#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
#define ll long long
#define INF 1e9
using namespace std;

int T;
int n;
char r[3];
char cube[7][4][4];

void showFace(int i) {
	for(int j=1;j<=3;++j) {
		for(int k=1;k<=3;++k) {
			printf("%c", cube[i][j][k]);
		}
		printf("\n");
	}
	return;
}

void matRotation(int face, int d) {
	char phase[4][4];
	memset(phase, 0, sizeof(phase));
	for(int j=1;j<=3;++j) {
		for(int k=1;k<=3;++k) {
			phase[j][k] = cube[face][j][k];
		}
	}
	if(d > 0) {  // clockwise
		for(int i=0;i<4;++i) {
			if(i == 0) {
				for(int j=1;j<=3;++j) {
					cube[face][j][3] = phase[1][j];
				}
			} else if(i==1) {
				for(int j=1;j<=3;++j) {
					cube[face][3][4-j] = phase[j][3];
				}
			} else if(i==2) {
				for(int j=1;j<=3;++j) {
					cube[face][4-j][1] = phase[3][4-j];
				}
			} else {
				for(int j=1;j<=3;++j) {
					cube[face][1][j] = phase[4-j][1];
				}
			}
		}
	} else if(d == 0) {  // counter-clockwise
		for(int i=0;i<4;++i) {
			if(i==0) {
				for(int j=1;j<=3;++j) {
					cube[face][j][1] = phase[1][4-j];
				}
			} else if(i==1) {
				for(int j=1;j<=3;++j) {
					cube[face][3][j] = phase[j][1];
				}
			} else if(i==2) {
				for(int j=1;j<=3;++j) {
					cube[face][4-j][3] = phase[3][j];
				}
			} else {
				for(int j=1;j<=3;++j) {
					cube[face][1][4-j] = phase[4-j][3];
				}
			}
		}
	}
	return;
}

void color(int i, char c) {
	for(int j=1;j<=3;++j) {
		for(int k=1;k<=3;++k) {
			cube[i][j][k] = c;
		}
	}
	return;
}

void initCube() {
	memset(cube, 0, sizeof(cube));

	for(int i=1;i<=6;++i) {
		switch(i) {
			case 1:
				color(1,'w');
				break;
			case 2:
				color(2,'r');
				break;
			case 3:
				color(3,'y');
				break;
			case 4:
				color(4,'o');
				break;
			case 5:
				color(5,'g');
				break;
			case 6:
				color(6,'b');
				break;
		}

	}
	return;
}

void moveL() {  // L+
	char var[13];
	memset(var, 0, sizeof(var));

	int idx = 1;
	int faces[] = {1,2,3,4};
	for(int i=0;i<4;++i) {
		int face = faces[i];
		for(int j=1;j<=3;++j) {
			var[idx++] = cube[face][j][1];
		}
	}

	rotate(var+1,var+10,var+13);
	idx = 1;
	for(int i=0;i<4;++i) {
		int face = faces[i];
		for(int j=1;j<=3;++j) {
			cube[face][j][1] = var[idx++];
		}
	}

	return;
}

void moveR() {  // R-
	char var[13];
	memset(var, 0, sizeof(var));

	int idx = 1;
	int faces[] = {1,2,3,4};
	for(int i=0;i<4;++i) {
		int face = faces[i];
		for(int j=1;j<=3;++j) {
			var[idx++] = cube[face][j][3];
		}
	}

	rotate(var+1,var+10,var+13);
	idx = 1;
	for(int i=0;i<4;++i) {
		int face = faces[i];
		for(int j=1;j<=3;++j) {
			cube[face][j][3] = var[idx++];
		}
	}

	return;
}

void moveU() {  // U+
	int var[13];
	memset(var,0,sizeof(var));

	int idx = 1;
	int faces[] = {4,6,2,5};
	for(int i=0;i<4;++i) {
		int face = faces[i];

		for(int j=1;j<=3;++j) {
			if(face == 4) {
				var[idx++] = cube[face][3][j];
			} else {
				var[idx++] = cube[face][1][4-j];
			}
		}
	}

	rotate(var+1,var+10,var+13);
	idx = 1;
	for(int i=0;i<4;++i) {
		int face = faces[i];
		for(int j=1;j<=3;++j) {
			if(face == 4) {
				cube[face][3][j] = var[idx++];
			} else {
				cube[face][1][4-j] = var[idx++];
			}
		}
	}

	return;
}

void moveD() {  // D-
	int var[13];
	memset(var,0,sizeof(var));

	int idx = 1;
	int faces[] = {4,6,2,5};
	for(int i=0;i<4;++i) {
		int face = faces[i];

		for(int j=1;j<=3;++j) {
			if(face == 4) {
				var[idx++] = cube[face][1][j];
			} else {
				var[idx++] = cube[face][3][4-j];
			}
		}
	}

	rotate(var+1,var+10,var+13);
	idx = 1;
	for(int i=0;i<4;++i) {
		int face = faces[i];
		for(int j=1;j<=3;++j) {
			if(face == 4) {
				cube[face][1][j] = var[idx++];
			} else {
				cube[face][3][4-j] = var[idx++];
			}
		}
	}

	return;
}

void moveF() {  // F+
	int var[13];
	memset(var,0,sizeof(var));

	int idx = 1;
	int faces[] = {1,6,3,5};
	for(int i=0;i<4;++i) {
		int face = faces[i];

		for(int j=1;j<=3;++j) {
			if(face==1) {
				var[idx++] = cube[face][3][j];
			} else if(face==6) {
				var[idx++] = cube[face][j][1];
			} else if(face==3) {
				var[idx++] = cube[face][1][4-j];
			} else if(face==5) {
				var[idx++] = cube[face][4-j][3];
			}
		}
	}

	rotate(var+1,var+10,var+13);
	idx = 1;
	for(int i=0;i<4;++i) {
		int face = faces[i];

		for(int j=1;j<=3;++j) {
			if(face==1) {
				cube[face][3][j] = var[idx++];
			} else if(face==6) {
				cube[face][j][1] = var[idx++];
			} else if(face==3) {
				cube[face][1][4-j] = var[idx++];
			} else if(face==5) {
				cube[face][4-j][3] = var[idx++];
			}
		}
	}

	return;
}

void moveB() {  // B-
	int var[13];
	memset(var,0,sizeof(var));

	int idx = 1;
	int faces[] = {1,6,3,5};
	for(int i=0;i<4;++i) {
		int face = faces[i];

		for(int j=1;j<=3;++j) {
			if(face==1) {
				var[idx++] = cube[face][1][j];
			} else if(face==6) {
				var[idx++] = cube[face][j][3];
			} else if(face==3) {
				var[idx++] = cube[face][3][4-j];
			} else if(face==5) {
				var[idx++] = cube[face][4-j][1];
			}
		}
	}

	rotate(var+1,var+10,var+13);
	idx = 1;
	for(int i=0;i<4;++i) {
		int face = faces[i];

		for(int j=1;j<=3;++j) {
			if(face==1) {
				cube[face][1][j] = var[idx++];
			} else if(face==6) {
				cube[face][j][3] = var[idx++];
			} else if(face==3) {
				cube[face][3][4-j] = var[idx++];
			} else if(face==5) {
				cube[face][4-j][1] = var[idx++];
			}
		}
	}

	return;
}

void move(char f, int d) {
	// L,R : 1,2,3,4 (U,F,D,B)
		// L+,R- : 1->2->3->4->1
		// L-,R+ : 1->4->3->2->1
	// U,D : 2,5,4,6 (F,L,B,R)
		// U+,D- : 4->6->2->5->4
		// U-,D+ : 4->5->2->6->4
	// F,B : 1,6,3,5 (U,R,D,L)
		// F+,B- : 1->6->3->5->1
		// F-,B+ : 1->5->3->6->1

	if(f=='L') {
		if(d > 0) {
			moveL();
			matRotation(5,d);
		} else if(d==0) {
			for(int i=0;i<3;++i)
				moveL();

			matRotation(5,d);
		}
	} else if(f=='R') {
		if(d > 0) {
			for(int i=0;i<3;++i)
				moveR();

			matRotation(6,d);
			
		} else if(d==0) {
			moveR();
			matRotation(6,d);
		}
	} else if(f=='U') {
		if(d > 0) {
			moveU();
			matRotation(1,d);
		} else if(d==0) {
			for(int i=0;i<3;++i)
				moveU();

			matRotation(1,d);
		}
	} else if(f=='D') {
		if(d > 0) {
			for(int i=0;i<3;++i)
				moveD();

			matRotation(3,d);
			
		} else if(d==0) {
			moveD();
			matRotation(3,d);
		}
	} else if(f=='F') {
		if(d > 0) {
			moveF();
			matRotation(2,d);
		} else if(d==0) {
			for(int i=0;i<3;++i)
				moveF();

			matRotation(2,d);
		}
	} else if(f=='B') {
		if(d > 0) {
			for(int i=0;i<3;++i)
				moveB();

			matRotation(4,d);
		} else if(d==0) {
			moveB();
			matRotation(4,d);
		}
	}
}

int main(void) {
	// ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	scanf("%d", &T);

	while(T--) {
		scanf("%d", &n);
		initCube();
		for(int i=0;i<n;++i) {
			scanf("%s", r);
			char face = r[0];
			int d = '-' - r[1];  // 2: '+', 0: '-'

			move(face, d);
		}
		showFace(1);  // show the top face
	}
	
	return 0;
}