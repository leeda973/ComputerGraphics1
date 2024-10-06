#include <GL/freeglut.h>  // GLUT와 OpenGL 헤더 파일 포함
#include <stdio.h>        // printf 사용을 위한 헤더 파일

// 정점 좌표 배열 (8개의 정점)
GLfloat MyVertices[8][3] = {
    {-0.25, -0.25,  0.25},
    {-0.25,  0.25,  0.25},
    { 0.25,  0.25,  0.25},
    { 0.25, -0.25,  0.25},
    {-0.25, -0.25, -0.25},
    {-0.25,  0.25, -0.25},
    { 0.25,  0.25, -0.25},
    { 0.25, -0.25, -0.25}
};

// 정점 색상 배열
GLfloat MyColors[8][3] = {
    {0.2, 0.2, 0.2},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0}
};

// 디스플레이 콜백 함수
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);  // 화면 지우기

    // 정점 0, 3, 2, 1로 구성된 면을 그리기 (반시계 방향)
    glBegin(GL_POLYGON);
    glColor3fv(MyColors[0]); glVertex3fv(MyVertices[0]);  // 색상과 정점 지정
    glColor3fv(MyColors[3]); glVertex3fv(MyVertices[3]);
    glColor3fv(MyColors[2]); glVertex3fv(MyVertices[2]);
    glColor3fv(MyColors[1]); glVertex3fv(MyVertices[1]);
    glEnd();

    glFlush();  // 그리기 명령 실행
}

// 메인 함수
int main(int argc, char** argv) {
    // GLUT 초기화
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);  // 윈도우 크기 설정
    glutCreateWindow("OpenGL Drawing Example");  // 윈도우 생성

    // 화면 갱신 콜백 함수 등록
    glutDisplayFunc(MyDisplay);

    // 메인 이벤트 루프 실행
    glutMainLoop();

    return 0;
}
