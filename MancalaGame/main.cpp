#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

using namespace std;

struct coordinates{
    float x,y;
};

struct coordinates oyuk[12];
struct coordinates kasa[2];
int stone_num[14];
int turn=1;
int selection=1;
int playing = 1;

void setValues(){
    oyuk[0].x = -33.2;  oyuk[0].y = -11;
    oyuk[1].x = -20.8;  oyuk[1].y = -11;
    oyuk[2].x = -7.8;   oyuk[2].y = -11;
    oyuk[3].x = 7.8;    oyuk[3].y = -11;
    oyuk[4].x = 20.8;   oyuk[4].y = -11;
    oyuk[5].x = 33.2;   oyuk[5].y = -11;

    oyuk[11].x = -33.2; oyuk[11].y = 11;
    oyuk[10].x = -20.8; oyuk[10].y = 11;
    oyuk[9].x = -7.8;   oyuk[9].y = 11;
    oyuk[8].x = 7.8;    oyuk[8].y = 11;
    oyuk[7].x = 20.8;   oyuk[7].y = 11;
    oyuk[6].x = 33.2;   oyuk[6].y = 11;

    kasa[0].x = -49.75; kasa[0].y = 0;
    kasa[1].x = 49.75; kasa[1].y = 0;

    stone_num[0]=0; stone_num[7]=0;
    for(int i=1;i<14;i++){
        if(i==7)
            continue;
        stone_num[i]=4;
    }
}

void drawCircle(float r, float x, float y) {
        float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex2f(r*cos(M_PI * i / 180.0) + x, r*sin(M_PI * i / 180.0) + y);

        glEnd();
}

void drawhand(){
    glColor3f(0.945,0.76,0.49);
    float x,y;
    if(selection<7){
        if (selection==1){
            x=-33.2;
            y=-24;
        }
        else if(selection==2){
            x=-20.8;
            y=-24;
        }
        else if(selection==3){
            x=-7.8;
            y=-24;
        }
        else if(selection==4){
            x=7.8;
            y=-24;
        }
        else if(selection==5){
            x=20.8;
            y=-24;
        }
        else if(selection==6){
            x=33.2;
            y=-24;
        }

        drawCircle(1,x-2,y+5);
        drawCircle(1,x-2,y+4);
        drawCircle(1,x-2,y+3);
        drawCircle(1,x-2,y+2);
        drawCircle(1,x-2,y+1);

        drawCircle(3,x,y);

        glBegin(GL_POLYGON);
            glVertex3f(x-2, y-5, 0.0);
            glVertex3f(x+2, y-5, 0.0);
            glVertex3f(x+2, y-2, 0.0);
            glVertex3f(x-2, y-2, 0.0);
        glEnd();
    }
    else{
        if (selection==8){
            x=33.2;
            y=24;
        }
        else if(selection==9){
            x=20.8;
            y=24;
        }
        else if(selection==10){
            x=7.8;
            y=24;
        }
        else if(selection==11){
            x=-7.8;
            y=24;
        }
        else if(selection==12){
            x=-20.8;
            y=24;
        }
        else if(selection==13){
            x=-33.2;
            y=24;
        }
        drawCircle(1,x+2,y-5);
        drawCircle(1,x+2,y-4);
        drawCircle(1,x+2,y-3);
        drawCircle(1,x+2,y-2);
        drawCircle(1,x+2,y-1);

        drawCircle(3,x,y);

        glBegin(GL_POLYGON);
            glVertex3f(x-2, y+2, 0.0);
            glVertex3f(x+2, y+2, 0.0);
            glVertex3f(x+2, y+5, 0.0);
            glVertex3f(x-2, y+5, 0.0);
        glEnd();
    }


}

void drawGameBoard(){
    glBegin(GL_POLYGON);
        glVertex3f(-59.5, -33.5, 0.0);
        glVertex3f(59.5, -33.5, 0.0);
        glVertex3f(59.5, 33.5, 0.0);
        glVertex3f(-59.5, 33.5, 0.0);
    glEnd();

    glColor3f(0.44,0.212,0.134);
    glBegin(GL_POLYGON);
        glVertex3f(-59.5, 31.5, 0.0);
        glVertex3f(59.5, 31.5, 0.0);
        glVertex3f(59.5, 33.5, 0.0);
        glVertex3f(-59.5, 33.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-59.5, -33.5, 0.0);
        glVertex3f(-57.5, -33.5, 0.0);
        glVertex3f(-57.5, 33.5, 0.0);
        glVertex3f(-59.5, 33.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(57.5, -33.5, 0.0);
        glVertex3f(59.5, -33.5, 0.0);
        glVertex3f(59.5, 33.5, 0.0);
        glVertex3f(57.5, 33.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-59.5, -33.5, 0.0);
        glVertex3f(59.5, -33.5, 0.0);
        glVertex3f(59.5, -31.5, 0.0);
        glVertex3f(-59.5, -31.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-40.0, -1.0, 0.0);
        glVertex3f(40.0, -1.0, 0.0);
        glVertex3f(40.0, 1.0, 0.0);
        glVertex3f(-40.0, 1.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, -33.5, 0.0);
        glVertex3f(1.0, -33.5, 0.0);
        glVertex3f(1.0, 33.5, 0.0);
        glVertex3f(-1.0, 33.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-42.0, -33.5, 0.0);
        glVertex3f(-40.0, -33.5, 0.0);
        glVertex3f(-40.0, 33.5, 0.0);
        glVertex3f(-42.0, 33.5, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(40.0, -33.5, 0.0);
        glVertex3f(42.0, -33.5, 0.0);
        glVertex3f(42.0, 33.5, 0.0);
        glVertex3f(40.0, 33.5, 0.0);
    glEnd();

    glColor3f(0.145,0.07,0.04);

    glBegin(GL_POLYGON);
        glVertex3f(-55.0, -20.0, 0.0);
        glVertex3f(-44.5, -20.0, 0.0);
        glVertex3f(-44.5, 20.0, 0.0);
        glVertex3f(-55.0, 20.0, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(44.5, -20.0, 0.0);
        glVertex3f(55.0, -20.0, 0.0);
        glVertex3f(55.0, 20.0, 0.0);
        glVertex3f(44.5, 20.0, 0.0);
    glEnd();

    drawCircle(5.8,oyuk[0].x,oyuk[0].y);
    drawCircle(5.8,oyuk[1].x,oyuk[1].y);
    drawCircle(5.8,oyuk[2].x,oyuk[2].y);
    drawCircle(5.8,oyuk[3].x,oyuk[3].y);
    drawCircle(5.8,oyuk[4].x,oyuk[4].y);
    drawCircle(5.8,oyuk[5].x,oyuk[5].y);
    drawCircle(5.8,oyuk[6].x,oyuk[6].y);
    drawCircle(5.8,oyuk[7].x,oyuk[7].y);
    drawCircle(5.8,oyuk[8].x,oyuk[8].y);
    drawCircle(5.8,oyuk[9].x,oyuk[9].y);
    drawCircle(5.8,oyuk[10].x,oyuk[10].y);
    drawCircle(5.8,oyuk[11].x,oyuk[11].y);
}

void write_txt(float x, float y, char *string) {
  glRasterPos2f(x,y);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);  // Updates the position
  }
}

void write_txt_2(float x, float y, char *string) {
  glRasterPos2f(x,y);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  // Updates the position
  }
}
void write_txt_3(float x, float y, char *string) {
  glRasterPos2f(x,y);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);  // Updates the position
  }
}

void write_utilities(){
    glColor3f(1,1,1);
    char str[]="";
    sprintf(str,"%d\0",stone_num[1]);
    write_txt(oyuk[0].x-0.8,oyuk[0].y-0.5,str);
    sprintf(str,"%d\0",stone_num[2]);
    write_txt(oyuk[1].x-0.8,oyuk[1].y-0.5,str);
    sprintf(str,"%d\0",stone_num[3]);
    write_txt(oyuk[2].x-0.8,oyuk[2].y-0.5,str);
    sprintf(str,"%d\0",stone_num[4]);
    write_txt(oyuk[3].x-0.8,oyuk[3].y-0.5,str);
    sprintf(str,"%d\0",stone_num[5]);
    write_txt(oyuk[4].x-0.8,oyuk[4].y-0.5,str);
    sprintf(str,"%d\0",stone_num[6]);


    write_txt(oyuk[5].x-0.8,oyuk[5].y-0.5,str);
    sprintf(str,"%d\0",stone_num[8]);

    write_txt(oyuk[6].x-0.8,oyuk[6].y-0.5,str);
    sprintf(str,"%d\0",stone_num[9]);

    write_txt(oyuk[7].x-0.8,oyuk[7].y-0.5,str);
    sprintf(str,"%d\0",stone_num[10]);

    write_txt(oyuk[8].x-0.8,oyuk[8].y-0.5,str);
    sprintf(str,"%d\0",stone_num[11]);
    write_txt(oyuk[9].x-0.8,oyuk[9].y-0.5,str);
    sprintf(str,"%d\0",stone_num[12]);
    write_txt(oyuk[10].x-0.8,oyuk[10].y-0.5,str);
    sprintf(str,"%d\0",stone_num[13]);
    write_txt(oyuk[11].x-0.8,oyuk[11].y-0.5,str);

    sprintf(str,"%d\0",stone_num[0]);
    write_txt(kasa[0].x-0.8,kasa[0].y-0.5,str);
    sprintf(str,"%d\0",stone_num[7]);
    write_txt(kasa[1].x-0.8,kasa[1].y-0.5,str);

    char str2[12]="";
    sprintf(str2,"PLAYER  ==>  %d\0",turn);
    write_txt(-7.5,34,str2);

}


static void key(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            if(turn==1){
                if(selection==6)
                    selection=1;
                else
                    selection++;
            }
            else{
                if(selection==8)
                    selection=13;
                else
                    selection--;
            }
            break;
        case GLUT_KEY_LEFT:
            if(turn==1){
                if(selection==1)
                    selection=6;
                else
                    selection--;
            }
            else{
                if(selection==13)
                    selection=8;
                else
                    selection++;
            }
            break;
    }
    glutPostRedisplay();
}

void action(){
    int s_num=0;
    int i;
    int last_visited_num;
    if(stone_num[selection]==0){
        if(turn==2) turn=1;
        else turn=2;
        return;
    }
    if(stone_num[selection]==1){
        if(selection==13){
            stone_num[0] += 1;
            last_visited_num = 0;
        }
        else{
            stone_num[selection+1] +=1;
            last_visited_num = selection+1;
        }
        stone_num[selection] = 0;
    }
    else if(selection<7){
        i=0;
        s_num = stone_num[selection];
        stone_num[selection] = 0;
        while(s_num!=0){
            last_visited_num = selection +i;
            stone_num[selection+i] += 1;
            if (selection+i==13){
                i = -1*(selection);
            }
            i++;
            s_num--;
        }
    }
    else{
        i=0;
        s_num = stone_num[selection];
        stone_num[selection] = 0;
        while(s_num!=0){
            last_visited_num = selection +i;
            stone_num[selection+i] += 1;
            if (selection+i==13){
                i = -1*(selection);
                i--;
            }
            i++;
            s_num--;
        }
    }
    if(last_visited_num == 7) turn=2;
    else if(last_visited_num == 0) turn=1;
    else if(last_visited_num>7 && selection <7 && stone_num[last_visited_num]%2==0){
        stone_num[7] += stone_num[last_visited_num];
        stone_num[last_visited_num] = 0;
    }
    else if(last_visited_num<7 && selection >7 && stone_num[last_visited_num]%2==0){
        stone_num[0] += stone_num[last_visited_num];
        stone_num[last_visited_num] = 0;
    }
    else if(last_visited_num < 7 && selection < 7 && stone_num[last_visited_num]==1){
        stone_num[7] += stone_num[last_visited_num];
        stone_num[7] += stone_num[(-1*(last_visited_num-7))+7];
        stone_num[last_visited_num] = 0;
        stone_num[(-1*(last_visited_num-7))+7] = 0;
    }

    else if(last_visited_num > 7 && selection > 7 && stone_num[last_visited_num] == 1){
        stone_num[0] += stone_num[last_visited_num];
        stone_num[0] += stone_num[-1*((last_visited_num%7)-7)];
        stone_num[last_visited_num] = 0;
        stone_num[-1*((last_visited_num%7)-7)] = 0;
    }
}

void game_end(){
    int win_player=0;
    glColor3f(0.004,0.663,0.7);
    glBegin(GL_POLYGON);
        glVertex3f(-32, -18, 0.0);
        glVertex3f(32, -18, 0.0);
        glVertex3f(32, 18, 0.0);
        glVertex3f(-32, 18, 0.0);
    glEnd();
    glColor3f(0.145,0.07,0.04);
    glBegin(GL_POLYGON);
        glVertex3f(18, -15, 0.0);
        glVertex3f(28, -15, 0.0);
        glVertex3f(28, 15, 0.0);
        glVertex3f(18, 15, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-28, -15, 0.0);
        glVertex3f(-18, -15, 0.0);
        glVertex3f(-18, 15, 0.0);
        glVertex3f(-28, 15, 0.0);
    glEnd();
    glColor3f(1,1,1);
    char str[300]="";
    sprintf(str,"%d\0",stone_num[0]);
    write_txt(-23.5,0,str);
    sprintf(str,"%d\0",stone_num[7]);
    write_txt(22.5,0,str);
    if(stone_num[0]==stone_num[7]) win_player = 0;
    else if(stone_num[0] < stone_num[7]) win_player = 1;
    else win_player = 2;
    glColor3f(0,0,0);
    if(win_player > 0){
        sprintf(str,"Player %d is won the game !\0",win_player);
        write_txt_2(-12,0,str);
    }
    else{
        sprintf(str,"THE MATCH ENDED");
        write_txt_2(-11,4,str);
        sprintf(str,"IN A DRAW !!");
        write_txt_2(-6,0,str);

    }
    glColor3f(1,1,1);
    sprintf(str,"Press ESC to exit game\0",win_player);
    write_txt_3(-9.7,-10,str);
    sprintf(str,"Press ENTER to new game\0",win_player);
    write_txt_3(-10,-13,str);


}

void gameCheck(){
    int i;
    int flag1 = 0;
    int flag2 = 0;
    for(i=1;i<7;i++){
        if(stone_num[i]>0){
            flag1 = 0;
            break;
        }
        else flag1 = 1;
    }
    for(i=8;i<14;i++){
        if(stone_num[i]>0){
            flag2=0;
            break;
        }
        else flag2=0;
    }
    if(flag1 == 1 && flag2 ==0){
        for(i=8;i<14;i++){
            stone_num[7] += stone_num[i];
            stone_num[i] = 0;
        }
        playing=0;
    }
    else if(flag1 == 0 && flag2 == 1){
        for(i=1;i<7;i++){
            stone_num[0] += stone_num[i];
            stone_num[i] = 0;
        }
        playing=0;
    }
    else if(flag1 == 1 && flag2 == 1) playing=0;
}

void pause_menu(){
    int win_player=0;
    glColor3f(0.004,0.663,0.7);
    glBegin(GL_POLYGON);
        glVertex3f(-32, -18, 0.0);
        glVertex3f(32, -18, 0.0);
        glVertex3f(32, 18, 0.0);
        glVertex3f(-32, 18, 0.0);
    glEnd();
    glColor3f(0.145,0.07,0.04);
    glBegin(GL_POLYGON);
        glVertex3f(18, -15, 0.0);
        glVertex3f(28, -15, 0.0);
        glVertex3f(28, 15, 0.0);
        glVertex3f(18, 15, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-28, -15, 0.0);
        glVertex3f(-18, -15, 0.0);
        glVertex3f(-18, 15, 0.0);
        glVertex3f(-28, 15, 0.0);
    glEnd();
    glColor3f(1,1,1);
    char str[300]="";
    sprintf(str,"%d\0",stone_num[0]);
    write_txt(-23.5,0,str);
    sprintf(str,"%d\0",stone_num[7]);
    write_txt(22.5,0,str);
    if(stone_num[0]==stone_num[7]) win_player = 0;
    else if(stone_num[0] < stone_num[7]) win_player = 1;
    else win_player = 2;
    glColor3f(0,0,0);
    sprintf(str,"PAUSED   GAME\0",win_player);
    write_txt_2(-9,5,str);
    glColor3f(1,1,1);
    sprintf(str,"Press Q to quit game\0",win_player);
    write_txt_3(-9,-11,str);
    sprintf(str,"Press N to new game\0",win_player);
    write_txt_3(-8.7,-7,str);
    sprintf(str,"Press ENTER to continue\0",win_player);
    write_txt_3(-10,-3,str);

}

static void detect_key(unsigned char key, int x, int y)
{
    switch (key){
        case 13:
            if (playing == 1){
                action();
                gameCheck();
                if (turn==1){
                    selection=13;
                    turn=2;
                }
                else{
                    turn=1;
                    selection=1;
                }
            }
            else if (playing==0){
                setValues();
                playing =1;
            }
            else if (playing==2){
                playing = 1;
            }
            break;
        case 27:
            if(playing==0) exit(0);
            else if(playing==1){
                playing = 2;
            }
            break;
        case 81:
        case 113:
            if(playing==2) exit(0);
            break;
        case 78:
        case 110:
            if(playing == 2){
                setValues();
                playing =1;
            }
            break;
    }
    glutPostRedisplay();
}

static void display(void)
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.64,0.337,0.22);


    drawGameBoard();
    if(playing ==1) write_utilities();
    if(playing==0) game_end();
    if(playing==2) pause_menu();

    glutSpecialFunc(key);
    glutKeyboardFunc(detect_key);

    drawhand();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280,720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("MANCALA");

    setValues();

    glutDisplayFunc(display);

    glViewport(0,0,800,800);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glOrtho(-64,64,-36,36,-1,1);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);


    glutMainLoop();

    return 0;
}
